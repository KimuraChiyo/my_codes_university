select *, Qty*Price as 'Суммарная стоимость конкретного товара' from OrdItem

select IdOrd, Sum(Qty*Price) as 'Суммарная стоимость' from OrdItem group by IdOrd