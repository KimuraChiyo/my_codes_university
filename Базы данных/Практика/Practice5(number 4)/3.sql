select * from 
(select IdOrd, sum(Qty * Price) as '���������' 
from OrdItem
group by IdOrd) r

select * from 
(select IdOrd, sum(Qty * Price) as '���������' 
from OrdItem
group by IdOrd) r
where ��������� > 50