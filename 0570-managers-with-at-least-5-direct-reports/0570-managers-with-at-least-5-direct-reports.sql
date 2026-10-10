# Write your MySQL query statement below
select e.name from employee e join employee r on e.id=r.managerid group by e.id,e.name having count(r.managerid)>=5