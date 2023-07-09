SELECT name FROM people WHERE id IN (SELECT person_id FROM directors WHERE movie_id IN (SELECT id FROM movies JOIN ratings on movies.id = ratings.movie_id WHERE rating = 9.0)) ORDER BY name DESC
