SELECT movies.title
FROM movies
JOIN stars, people, ratings
ON movies.id = stars.movie_id
AND people.id = stars.person_id
AND ratings.movie_id = movies.id
WHERE people.name = 'Chadwick Boseman'
ORDER BY ratings.rating DESC
LIMIT 5;
