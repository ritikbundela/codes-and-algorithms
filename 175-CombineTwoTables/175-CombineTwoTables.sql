-- Last updated: 26/11/2025, 22:33:04
# Write your MySQL query statement below
SELECT p.firstName , p.lastName, A.city, A.state
FROM Person P LEFT JOIN Address A
on P.PersonId = A.PersonId