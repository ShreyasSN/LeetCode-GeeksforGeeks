select user_id as buyer_id, join_date, 
    sum(if(year(order_date) = 2019, 1, 0)) as orders_in_2019
from users u right join orders o on user_id = buyer_id
group by buyer_id