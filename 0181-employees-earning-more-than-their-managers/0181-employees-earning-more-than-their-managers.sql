select e1.name as Employee from employee e1, employee e2 
where e2.id=e1.managerid and e1.salary>e2.salary;