-- Last updated: 26/11/2025, 22:32:58
SELECT e2.name as Employee
FROM employee e1
INNER JOIN employee e2 on e1.id = e2.managerID
WHERE
e1.salary < e2.salary;
