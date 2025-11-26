-- Last updated: 26/11/2025, 22:33:00
# Write your MySQL query statement below
SELECT DISTINCT
  l1.Num AS ConsecutiveNums
FROM (
  SELECT
    Num,
    LAG(Num, 1) OVER (ORDER BY Id) AS PrevNum,
    LEAD(Num, 1) OVER (ORDER BY Id) AS NextNum
  FROM
    Logs
) l1
WHERE
  l1.Num = l1.PrevNum AND l1.Num = l1.NextNum;