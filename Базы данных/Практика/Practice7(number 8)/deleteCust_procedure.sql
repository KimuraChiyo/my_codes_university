/*alter procedure deleteCust
	@InputId int
as
begin
	if @InputId not in (select IdCust from [Customer])
		begin
		print 'Клиента с таким номером не существует'
		return -100
		end
	if @InputId not in (select distinct IdCust from [Order])
		begin
		delete from Customer where IdCust = @InputId
		print 'Удаление прошло успешно'
		end
	else
		begin
		if (select count(*) from [Order] where IdCust = @InputId) > 1
			begin
			print 'Невозможно удалять этого клиента, так как он делал заказы'
			return -100
			end
		else
			begin
			print 'Невозможно удалять этого клиента, так как он делал заказ'
			return -100
			end
		/*
		select IdOrd as 'Заказы, которые делал клиент' 
		from [Order] 
		where IdCust = @InputId
		*/
		end
	return 0		
end
*/
--insert into Customer (FName, LName, IdCity, Address, Zip, Phone) values
--('Фамилия', 'Имя', 14, 'Кул Гали, 10', '11120', '890032900')
--select * from [Customer]
--select * from [Order]
--exec deleteCust 24



