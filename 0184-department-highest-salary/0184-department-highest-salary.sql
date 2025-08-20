select d.name as Department,
       e.name as Employee,
       Salary
from employee e left join department d on e.departmentid = d.id
where (e.departmentid, e.salary) in (
    select e1.departmentid, max(e1.salary) from employee e1
    group by e1.departmentid
) 