SELECT
    firstName, 
    lastName, 
    city,
    state
FROM 
    Person p left join Address using(PersonId)