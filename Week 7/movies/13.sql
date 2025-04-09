SELECT DISTINCT p.name
FROM people AS p
JOIN stars AS s ON p.id = s.person_id
JOIN movies AS m ON s.movie_id = m.id
JOIN stars AS s_kb ON m.id = s_kb.movie_id
JOIN people AS p_kb ON s_kb.person_id = p_kb.id
WHERE p_kb.name = 'Kevin Bacon'
  AND p_kb.birth = 1958
  AND p.id != p_kb.id;
