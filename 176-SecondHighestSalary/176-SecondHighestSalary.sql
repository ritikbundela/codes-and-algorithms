-- Last updated: 26/11/2025, 22:33:03
# Write your MySQL query statement below
select
( 
    select distinct salary 
    from Employee
    order by salary DESC 
    Limit 1 Offset 1
)
as SecondHighestSalary;