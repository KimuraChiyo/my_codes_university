/*
alter function notUsedProds ()
returns table
as
return
(
select distinct IdProd as 'Номера товаров, которые не заказывали', [Description] as 'Описание товаров', InStock as 'Остаток на складе'
		from Product
		where IdProd not in (select distinct IdProd from OrdItem)
)
*/
select * from notUsedProds()