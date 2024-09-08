select * from [Order]

select IdCust, FName + ' ' + LName as 'Фамилия Имя' from Customer
where IdCust in 
(select IdCust from [Order]
where IdCust = some(select IdCust from [Customer])
and OrdDate < CAST('2023-11-01' as smalldatetime)
group by IdCust)