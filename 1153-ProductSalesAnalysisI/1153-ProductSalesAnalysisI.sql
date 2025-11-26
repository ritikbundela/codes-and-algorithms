-- Last updated: 26/11/2025, 22:31:09
# Write your MySQL query statement below
select Product.Product_name , sales.year , sales.price
from product
right join sales
on sales.product_id = product.product_id;