/*
alter function getRemainder (@IdProd int)
returns varchar(25)
as
  begin
	declare @result varchar(25)
	set @result = 0
	SELECT @result = 'Остаток ' + (select [Description] from Product where IdProd = @IdProd) + ': ' +  cast(InStock as varchar(5))
	FROM Product
	where IdProd = @IdProd
	return @result
  end
*/

declare @need int
set @need = 1

select InStock from Product where IdProd = @need

select dbo.getRemainder(@need) as 'Склад'