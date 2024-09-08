select distinct a.IdCust as 'Ќомер клиентов, которые не делали заказы' from Customer a left join [Order] b on a.IdCust = b.IdCust
where a.IdCust not in (select IdCust from [Order])

select distinct IdCust as 'Ќомер клиентов, которые делали заказы' from [Order]

select * from [Order]