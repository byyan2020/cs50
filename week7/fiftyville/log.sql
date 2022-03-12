-- Keep a log of any SQL queries you execute as you solve the mystery.

-- GET description from crime scene reports
SELECT description FROM crime_scene_reports
WHERE year = 2021
AND month = 7
AND day = 28
And street = "Humphrey Street";

--Theft of the CS50 duck took place at 10:15am at the Humphrey Street bakery. Interviews were conducted today with three witnesses who were present at the time – each of their interview transcripts mentions the bakery.


-- Get transcrip from interviews
SELECT name, transcript FROM interviews
WHERE year = 2021
AND month = 7
AND day = 28
AND transcript LIKE "%bakery%";

-- Ruth    | Sometime within ten minutes of the theft, I saw the thief get into a car in the bakery parking lot and drive away. If you have security footage from the bakery parking lot, you might want to look for cars that left the parking lot in that time frame.                                                          |
-- Eugene  | I don't know the thief's name, but it was someone I recognized. Earlier this morning, before I arrived at Emma's bakery, I was walking by the ATM on Leggett Street and saw the thief there withdrawing some money.                                                                                                 |
-- Raymond | As the thief was leaving the bakery, they called someone who talked to them for less than a minute. In the call, I heard the thief say that they were planning to take the earliest flight out of Fiftyville tomorrow. The thief then asked the person on the other end of the phone to purchase the flight ticket. |
-- Emma    | I'm the bakery owner, and someone came in, suspiciously whispering into a phone for about half an hour. They never bought anything.


SELECT id FROM people
WHERE license_plate IN (
    -- check the cars that left the parking lot in that time frame
    SELECT license_plate FROM bakery_security_logs
    WHERE year = 2021
    AND month = 7
    AND day = 28
    AND hour = 10
    AND minute BETWEEN 15 AND 25
)
AND id IN (
    -- ATM on Leggett street, withdrawing money
    SELECT person_id FROM bank_accounts
    JOIN people ON people.id = bank_accounts.person_id
    WHERE account_number IN (
        SELECT account_number FROM atm_transactions
        WHERE year = 2021
        AND month = 7
        AND day = 28
        AND atm_location = "Leggett Street"
        AND transaction_type = "withdraw"
    )
)

AND phone_number IN (
    -- phone call less than 1 minite
    SELECT caller FROM phone_calls
    WHERE year = 2021
    AND month = 7
    AND day = 28
    AND duration < 60
);

--purchase the earliest flight out of Fiftyville tomorrow
SELECT id FROM flights
WHERE year = 2021
AND month = 7
AND day = 29
AND origin_airport_id = (
    SELECT id FROM airports
    WHERE city like "fiftyville"
)
ORDER BY hour, minute
LIMIT 1;
