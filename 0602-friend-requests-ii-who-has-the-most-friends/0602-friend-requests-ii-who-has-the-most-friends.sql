with base as (
    select requester_id id from requestaccepted
    union all
    select accepter_id id from requestaccepted
)

select id, count(id) as num from base
group by id
order by num desc
limit 1