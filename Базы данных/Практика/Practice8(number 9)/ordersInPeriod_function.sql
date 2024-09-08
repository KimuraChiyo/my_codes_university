/*
alter function ordersInPeriod 
(
	@startdate smalldatetime = NULL,
	@enddate smalldatetime = NULL
)
returns 
@result table
(
IdOrd int,
OrdDate smalldatetime
)
as
begin
	declare @startstr varchar(11)
	declare @endstr varchar(11)
	set @startstr = '2020-01-01'
	set @endstr = '2030-12-31'

	if (@startdate is null) and (@enddate is null)
		begin
		insert @result 
		select IdOrd, OrdDate 
		from [Order]
		where OrdDate > cast(@startstr as smalldatetime)
		and OrdDate < cast(@endstr as smalldatetime)
		end
	if  (@startdate is null) and not (@enddate is null)
		begin
		insert @result 
		select IdOrd, OrdDate 
		from [Order]
		where OrdDate > cast(@startstr as smalldatetime)
		and OrdDate < @enddate
		end
	if not (@startdate is null) and (@enddate is null) 
		begin
		insert @result 
		select IdOrd, OrdDate 
		from [Order]
		where OrdDate > @startdate
		and OrdDate < cast(@endstr as smalldatetime)
		end
	if not (@startdate is null) and not (@enddate is null)
		begin
		insert @result 
		select IdOrd, OrdDate 
		from [Order]
		where OrdDate > @startdate
		and OrdDate < @enddate
		end
	return
end
*/

declare @startdate smalldatetime
declare @enddate smalldatetime

set @startdate = cast('2023-10-08' as smalldatetime)
set @enddate = cast('2023-10-10' as smalldatetime)

select * from ordersInPeriod(@startdate, @enddate)