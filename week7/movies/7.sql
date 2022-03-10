SELECT title, rating FROM movies, ratings
WHERE movies.id = ratings.movie_id
AND 