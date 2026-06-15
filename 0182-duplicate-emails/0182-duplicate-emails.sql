# Write your MySQL query statement below

select  distinct e.email as Email from Person e , Person f where e.email = f.email AND e.id <> f.id