# Write your MySQL query statement below
select u.name as name,sum(t.amount) as balance from
users as u left join transactions  as t
on u.account=t.account
group by u.account
having sum(t.amount)>10000
