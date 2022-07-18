SELECT DISTINCT people.name
FROM people
JOIN movies, directors, ratings
ON people.id = directors.person_id
AND movies.id = directors.movie_id
AND movies.id = ratings.movie_id
WHERE ratings.rating >= 9.0;
