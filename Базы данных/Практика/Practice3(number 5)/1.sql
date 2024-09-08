use Sales;
delete from [Order] 
where IdOrd not in (select IdOrd from OrdItem)