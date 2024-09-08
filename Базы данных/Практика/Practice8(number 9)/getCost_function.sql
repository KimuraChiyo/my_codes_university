/*
alter function getCost (@IdOrd int)
returns varchar(20)
as
  begin
	declare @result varchar(40)
	select @result = ('Заказ №' + cast(@IdOrd as varchar(5)) + ': ' + cast(sum(Qty*Price) as varchar(5)))
	from OrdItem
	where IdOrd = @IdOrd
	group by IdOrd
	return @result
  end
*/

declare @need int
set @need = 2
select dbo.getCost(@need) as 'Cost'