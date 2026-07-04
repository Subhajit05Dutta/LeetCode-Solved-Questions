# Write your MySQL query statement below
select  distinct name,IFNULL(sum(distance),0) as travelled_distance
from Users left join Rides 
on Users.id=Rides.User_id
group by users.name,users.id
order by travelled_distance  desc,name asc