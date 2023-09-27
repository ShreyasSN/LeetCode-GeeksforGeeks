# Write your MySQL query statement below

SELECT firstname, lastname, city, state from Person P
LEFT JOIN Address A ON
P.personId = A.personId