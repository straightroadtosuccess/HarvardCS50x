SELECT AVG(r.rating)
FROM movies AS m
JOIN ratings AS r ON m.id = r.movie_id
WHERE m.year = 2012;
