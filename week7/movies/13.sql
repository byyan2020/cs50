SELECT name FROM people
JOIN stars ON movies.id = stars.movie_id
JOIN movie ON movie.id = stars.movie_id
