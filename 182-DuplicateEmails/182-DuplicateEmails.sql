-- Last updated: 26/11/2025, 22:32:57
# Write your MySQL query statement below
select email
from person
group by email
having count(email)>1;