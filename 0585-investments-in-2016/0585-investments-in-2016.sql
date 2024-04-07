SELECT ROUND(SUM(IF(TIV_2015<>TIV_2016, TIV_2016, 0)), 2) AS tiv_2016 FROM INSURANCE A
WHERE (LAT, LON) NOT IN (
    SELECT LAT, LON FROM INSURANCE B
    WHERE A.PID <> B.PID
)