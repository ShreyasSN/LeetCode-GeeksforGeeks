select distinct num as ConsecutiveNums from (
    select num, lag(num, 1) over (order by id asc) as lg, 
                lead(num, 1) over (order by id asc) as ld
                from logs
) as sub
where num = lg and num = ld