-- Last updated: 26/11/2025, 22:32:56

select name as Customers
from Customers c
LEFT JOIN Orders o 
ON c.id= o.customerId
where o.customerId is null;
