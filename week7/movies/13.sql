SELECT name FROM people
JOIN stars ON movies.id = stars.movie_id
JOIN movie ON movie.id = stars.movie_id
WHERE id IN (
    SELECT person_id FROM stars WHERE movie_id IN (
        
    )
    )
