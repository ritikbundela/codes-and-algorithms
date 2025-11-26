-- Last updated: 26/11/2025, 22:33:01
# Write your MySQL query statement below
SELECT
  score,
  DENSE_RANK() OVER (ORDER BY score DESC) AS 'rank'
FROM
  Scores;