/*create proc countCustWithoutOrders
	@returning_value int out
as
set @returning_value = (
select count(IdCust)
from [Customer]
where IdCust not in (select distinct IdCust 
					 from [Order])
)
return 0
*/

declare @returning_value int

exec countCustWithoutOrders @returning_value = @returning_value OUTPUT

select @returning_value as ' оличество посетителей без заказов' 