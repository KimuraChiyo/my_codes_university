/*ALTER PROC [allOrders]
	@NeedProd int
as
	declare @count_orders int

	set @count_orders = (select count(*) from OrdItem where IdProd = @NeedProd)

	if @count_orders = 0
		begin
			print '���������� ������� � ���� ������� ����� ����'
		end
	else
		begin

			/*
			-- �� ���������� ���� �������
			select * 
			from OrdItem
			*/

			/*
			-- �� ���������� ������� � ������ �������
			select * 
			from OrdItem
			where IdOrd in (select IdOrd as '������ � ���� �������'  
							from OrdItem
							where IdProd = @NeedProd)
			*/

			-- ��� ������
			select IdOrd as '������ � ���� �������' 
			from OrdItem 
			where IdProd = @NeedProd
		end
return 0
*/

exec allOrders 1