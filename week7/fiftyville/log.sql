-- Keep a log of any SQL queries you execute as you solve the mystery.

SELECT description
FROM crime_scene_reports
WHERE year = 2021
AND month = 7
AND day = 28
And street = "Humphrey Street";

--Theft of the CS50 duck took place at 10:15am at the Humphrey Street bakery. Interviews were conducted today with three witnesses who were present at the time – each of their interview transcripts mentions the bakery.

SELECT id, activity, license_plate
FROM bakery_security_logs
WHERE year = 2021
AND month = 7
AND day = 28;