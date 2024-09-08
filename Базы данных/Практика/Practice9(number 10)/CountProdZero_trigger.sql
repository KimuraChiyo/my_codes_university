/*
alter trigger CountProdZero on [OrdItem]
after INSERT 
as
begin
	declare @count_InStock int
	set @count_InStock = (select InStock from INSERTED ins
	left join  Product prod
	on ins.IdProd = prod.IdProd)
	if @count_InStock = 0
		rollback tran
		Print 'Not Enough.'
end
*/
insert into OrdItem (IdOrd, IdProd, Qty, Price) values (1, 4, 10, 1000)