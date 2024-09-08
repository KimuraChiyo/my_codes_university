select * from [Order] 

select * from [Order] 
where 
OrdDate > CAST('2023-10-01' as smalldatetime) and
OrdDate < CAST('2023-11-01' as smalldatetime)

select IdCust, COUNT(IdOrd) as 'Count' from [Order] 
where 
OrdDate > CAST('2023-10-01' as smalldatetime) and
OrdDate < CAST('2023-11-01' as smalldatetime)
group by IdCust

select IdCust, COUNT(IdOrd) as 'Count' from [Order] 
where 
OrdDate > CAST('2023-10-01' as smalldatetime) and
OrdDate < CAST('2023-11-01' as smalldatetime)
group by IdCust
having Count(IdOrd) > 3