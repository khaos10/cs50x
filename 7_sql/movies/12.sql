SELECT movies.title
FROM movies
JOIN stars, people
ON movies.id = stars.movie_id
AND people.id = stars.person_id
WHERE people.name = 'Helena Bonham Carter'
AND movies.title IN
    (SELECT movies.title
    FROM movies
    JOIN stars, people
    ON movies.id = stars.movie_id
    AND people.id = stars.person_id
    WHERE people.name = 'Johnny Depp');
