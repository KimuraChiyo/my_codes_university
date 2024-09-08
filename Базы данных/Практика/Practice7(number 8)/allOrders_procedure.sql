/*ALTER PROC [allOrders]
	@NeedProd int
as
	declare @count_orders int

	set @count_orders = (select count(*) from OrdItem where IdProd = @NeedProd)

	if @count_orders = 0
		begin
			print 'Количество заказов с этим товаров равно нулю'
		end
	else
		begin

			/*
			-- всё наполнение всех заказов
			select * 
			from OrdItem
			*/

			/*
			-- всё наполнение заказов с нужным товаром
			select * 
			from OrdItem
			where IdOrd in (select IdOrd as 'Заказы с этим товаром'  
							from OrdItem
							where IdProd = @NeedProd)
			*/

			-- все заказы
			select IdOrd as 'Заказы с этим товаром' 
			from OrdItem 
			where IdProd = @NeedProd
		end
return 0
*/

exec allOrders 1