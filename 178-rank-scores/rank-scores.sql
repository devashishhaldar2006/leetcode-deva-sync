# Write your MySQL query statement below
SELECT s1.score,(SELECT COUNT(DISTINCT score) FROM scores s2 WHERE s2.score>=s1.score)
AS "rank" 
FROM scores s1 
ORDER BY s1.score DESC