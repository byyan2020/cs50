SELECT title FROM movies
JOIN stars ON movies.id = stars.movie_id
JOIN people ON stars.person_id = people.id
WHERE name = "Johnny Depp"
WHERE name = "
ORDER BY rating DESC
LIMIT 5;
