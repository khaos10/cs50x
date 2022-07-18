SELECT DISTINCT people.name
FROM people
JOIN movies, stars
ON people.id = stars.person_id
AND movies.id = stars.movie_id
WHERE movies.year = 2004
ORDER BY people.birth;
