/*alter procedure deleteCust
	@InputId int
as
begin
	if @InputId not in (select IdCust from [Customer])
		begin
		print '������� � ����� ������� �� ����������'
		return -100
		end
	if @InputId not in (select distinct IdCust from [Order])
		begin
		delete from Customer where IdCust = @InputId
		print '�������� ������ �������'
		end
	else
		begin
		if (select count(*) from [Order] where IdCust = @InputId) > 1
			begin
			print '���������� ������� ����� �������, ��� ��� �� ����� ������'
			return -100
			end
		else
			begin
			print '���������� ������� ����� �������, ��� ��� �� ����� �����'
			return -100
			end
		/*
		select IdOrd as '������, ������� ����� ������' 
		from [Order] 
		where IdCust = @InputId
		*/
		end
	return 0		
end
*/
--insert into Customer (FName, LName, IdCity, Address, Zip, Phone) values
--('�������', '���', 14, '��� ����, 10', '11120', '890032900')
--select * from [Customer]
--select * from [Order]
--exec deleteCust 24



