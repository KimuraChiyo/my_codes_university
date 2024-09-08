select * from 
(select IdOrd, sum(Qty * Price) as 'Стоимость' 
from OrdItem
group by IdOrd) r

select * from 
(select IdOrd, sum(Qty * Price) as 'Стоимость' 
from OrdItem
group by IdOrd) r
where Стоимость > 50