select *, Qty*Price as 'Суммарная стоимость конкретного товара' from OrdItem

select Sum(c.[Суммарная стоимость конкретного товара]) as 'Суммарная стоимость заказов' from (select *, Qty*Price as 'Суммарная стоимость конкретного товара' from OrdItem) c