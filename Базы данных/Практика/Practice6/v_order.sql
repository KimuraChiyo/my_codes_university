/*
create view v_Order
as
select a.IdOrd, OrdDate, a.IdCust, FName, LName, c.[Count] as 'Количество видов товаров в заказе'
from 
[Order] a, 
Customer b, 
(select IdOrd, count(distinct IdProd) as 'Count'
 from OrdItem
 group by IdOrd) c
where a.IdCust = b.IdCust and a.IdOrd = c.IdOrd
*/
select * from [v_Order]
--drop view v_Order
select OrdDate, a.IdCust, FName, LName from Customer a, [Order] b
where a.IdCust = b.IdCust

select IdOrd, count(distinct IdProd) as 'Количество видов товаров в заказе' 
from OrdItem
group by IdOrd