select c.name as Customers from customers c
left join orders o on c.id=o.customerid
where o.id is NULL;