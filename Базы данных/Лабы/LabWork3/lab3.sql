-- ТРЕТЬЯ ЛАБА

--ПРЕДСТАВЛЕНИЯ
-- Представление Отдел Кадров
--create view OtdelKadrov
--as
--select EmpId, EmpFullName, EmpAge,EmpSex, EmpPlace, EmpPhone, EmpPassData, EmpPositionId, PosName, PosSalary, PosResponsibilities, PosRequirements from Employees 
--inner join Positions 
--on EmpPositionId = PosId

-- Представление Автопарк
--alter view Autopark
--as
--select CarId, CarRegNumber, CarBody, CarEngine, CarIssueYear, CarMileAge, CarCost, CarCostPerDay, CarLastTechView, CarSpecMarks, CarReturnMark, 
--	   CarBrandId, BrandName, BrandCharacteristic, BrandDescription,
--	   CarEmployeeId, EmpFullName, EmpAge, EmpSex, EmpPlace, EmpPhone, EmpPassData, EmpPositionId
--from Cars
--left join Employees on CarEmployeeId = EmpId
--inner join CarBrands on CarBrandId = BrandId

-- Представление Автомобили в прокате
--create view CarsInRent
--as (
--select CarRentId, CarRentIssueDate, CarRentCountDays, CarRentReturnDate, CarRentCost, CarRentPayMark, 
--	   a.CarId, CarRegNumber, CarBody, CarEngine, CarIssueYear, CarMileAge, CarCost, CarCostPerDay, CarLastTechView, CarSpecMarks, CarReturnMark, CarBrandId, CarEmployeeId,
--	   a.ClientId, ClientFullName, ClientSex, ClientBirthDate,
--	   CarRentServ1, d.ServName as ServName1, d.ServDescription as ServDescription1, d.ServCost as ServCost1,
--	   CarRentServ2, e.ServName as ServName2, e.ServDescription as ServDescription2, e.ServCost as ServCost2,
--	   CarRentServ3, f.ServName as ServName3, f.ServDescription as ServDescription3, f.ServCost as ServCost3,
--	   EmployeeId, EmpFullName, EmpAge, EmpSex, EmpPlace, EmpPhone, EmpPassData, EmpPositionId
--from CarRent as a
--inner join Cars as b
--on a.CarId = b.CarId
--inner join Clients as c
--on a.ClientId = c.ClientId
--left join AdditServices as d
--on CarRentServ1 = d.ServId
--left join AdditServices as e
--on CarRentServ2 = e.ServId
--left join AdditServices as f
--on CarRentServ3 = f.ServId
--left join Employees
--on EmployeeId = EmpId
--)

--ФИЛЬТРЫ
--Фильтр для отображение сотрудников отдельных должностей на основе запроса Отдел кадров
--select * from OtdelKadrov
--where PosName like '%Директор%'

--Фильтр отображения автомобилей отдельных марок
--select CarRegNumber, BrandName from Autopark
--where BrandName like '%Mercedes%'

--Фильтры отображения автомобилей находящихся и не находящихся в прокате
--Не находящиеся
--select CarRegNumber, BrandName, CarReturnMark from Autopark
--where CarReturnMark = 'YES'
--Находящиеся
--select CarRegNumber, BrandName, CarReturnMark from Autopark
--where CarReturnMark = 'NO'

--Фильтры для отображения автомобилей выданных и возвращеннх в определнную дату
--Выданных в определенную дату
--select CarRentIssueDate, CarRegNumber from CarsInRent
--where CarRentIssueDate = CAST('2023-10-11' as smalldatetime)
--Возвращенных в определенную дату
--select CarRentReturnDate, CarRegNumber from CarsInRent
--where CarRentReturnDate = CAST('2023-10-14' as smalldatetime)

--Фильтры оплаченных и не оплаченных автомобилей в прокате
--Оплаченные
--select CarRegNumber, CarRentPayMark from CarsInRent
--where CarRentPayMark = 'YES'
--Неоплаченные
--select CarRegNumber, CarRentPayMark from CarsInRent
--where CarRentPayMark = 'NO'

--РАЗЛИЧНЫЕ ЗАПРОСЫ
--Вывести сотрудника с наименьшей ЗП
select EmpFullName, EmpAge, EmpSex, PosName, PosSalary from OtdelKadrov
where PosSalary = (select min(PosSalary) from Positions)

--Вывести информацию о машине с наименьшим пробегом
select CarRegNumber, BrandName, BrandDescription, CarMileAge, CarReturnMark from Autopark
where CarMileAge = (select min(CarMileAge) from Cars)

--Количество свободных машин
select count(*) as 'Количество свободных машин' from Autopark
where CarReturnMark = 'YES'

--Количество свободных машин определенной марки
select COUNT(*) as 'Количество свободных машин Toyota' from Autopark 
where CarReturnMark = 'YES' and BrandName='Toyota'