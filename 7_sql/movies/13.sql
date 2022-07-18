SELECT people.name
FROM people, stars, movies
WHERE movies.id = stars.movie_id
AND people.id = stars.person_id
AND NOT people.name = 'Kevin Bacon'
AND movies.title IN
    (SELECT movies.title
    FROM people, stars, movies
    WHERE movies.id = stars.movie_id
    AND people.id = stars.person_id
    AND (people.name = 'Kevin Bacon' AND people.birth = 1958));
