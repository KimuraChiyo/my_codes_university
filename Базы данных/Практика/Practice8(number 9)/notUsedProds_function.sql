/*
alter function notUsedProds ()
returns table
as
return
(
select distinct IdProd as '������ �������, ������� �� ����������', [Description] as '�������� �������', InStock as '������� �� ������'
		from Product
		where IdProd not in (select distinct IdProd from OrdItem)
)
*/
select * from notUsedProds()