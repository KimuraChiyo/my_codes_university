﻿--ЧЕТВЕРТАЯ ЛАБА
--1. Процедура добавления в AdditServices
--create proc AddInAdditServices
--	@Name varchar(100),
--	@Desc varchar(100),
--	@Cost numeric(10, 3)
--as
--insert into AdditServices (ServName, ServDescription, ServCost) values
--(@Name, @Desc, @Cost)

--exec AddInAdditServices @Name='Электрика', @Desc='Прошивка системы', @Cost=20000

--2. Процедура добавления в CarBrands
--alter proc AddInCarBrands
--	@Name varchar(20),
--	@Characteristics varchar(200),
--	@Desc varchar(100)
--as
--insert into CarBrands (BrandName, BrandCharacteristic, BrandDescription) values
--(@Name, @Characteristics, @Desc)

--exec AddInCarBrands @Name='Lada', @Characteristics='Ведра', @Desc='Ведра'

--3. Процедура добавления в Positions
--create proc AddInPositions
--	@Name varchar(40),
--	@Salary numeric(10, 3),
--	@Responses varchar(100),
--	@Requires varchar(100)
--as
--insert into Positions (PosName, PosSalary, PosResponsibilities, PosRequirements) values
--(@Name, @Salary, @Responses, @Requires)

--exec AddInPositions @Name='Me2', @Salary=16000, @Responses=NULL, @Requires=NULL

--4. Процедура добавления в Employees
--create proc AddInEmployees
--	@FullName varchar(100),
--	@Age int,
--	@Sex varchar(6),
--	@Place varchar(100),
--	@Phone varchar(11),
--	@PassData numeric(10, 0),
--	@PosId int
--as
--insert into Employees (EmpFullName, EmpAge, EmpSex, EmpPlace, EmpPhone, EmpPassData, EmpPositionId) values
--(@FullName, @Age, @Sex, @Place, @Phone, @PassData, @PosId)

--exec AddInEmployees @FullName='Приветов Привет Приветович', 
--					@Age=18, 
--					@Sex='Male', 
--					@Place=null, 
--					@Phone='11111111112', 
--					@PassData='1000000001', 
--					@PosId=6

--5. Процедура добавления в Clients
--create proc AddInClients
--	@FullName varchar(100),
--	@Sex varchar(6),
--	@BirthDate date
--as
--insert into Clients (ClientFullName, ClientSex, ClientBirthDate) values
--(@FullName, @Sex, @BirthDate)

--exec AddInClients @FullName='Покпокаев Покапока Покапокаич', @Sex='Male', @BirthDate='2000-01-01'

--6. Процедура добавления в Cars
--create proc AddInCars
--	@RegName varchar(9),
--	@Body int,
--	@Engine int,
--	@IssueYear date,
--	@MileAge numeric(10, 3),
--	@Cost numeric(12, 3),
--	@CostPerDay numeric(9,2),
--	@LastTechView date,
--	@SpecMarks varchar(100),
--	@ReturnMark varchar(3),
--	@BrandId int,
--	@EmployeeId int
--as
--insert into Cars (CarRegNumber, CarBody, CarEngine, CarIssueYear, CarMileAge, CarCost, CarCostPerDay, CarLastTechView, CarSpecMarks, CarReturnMark, CarBrandId, CarEmployeeId) values
--(@RegName, @Body, @Engine, @IssueYear, @MileAge, @Cost, @CostPerDay, @LastTechView, @SpecMarks, @ReturnMark, @BrandId, @EmployeeId)

--exec AddInCars @RegName='А001БУ16',
--			   @Body=null, 
--			   @Engine=null, 
--			   @IssueYear=null, 
--			   @MileAge=122321.82, 
--			   @Cost=null, 
--			   @CostPerDay=1, 
--			   @LastTechView=null, 
--			   @SpecMarks=null, 
--			   @ReturnMark='NO', 
--			   @BrandId=6, 
--			   @EmployeeId=null

--7. Процедура добавления в CarRent
--create proc AddInCarRent
--	@IssueDate date,
--	@CountDays int,
--	@ReturnDate date,
--	@Cost numeric(10, 3),
--	@PayMark varchar(3), 
--	@Serv1 int,
--	@Serv2 int,
--	@Serv3 int,
--	@IdEmployee int,
--	@IdClient int,
--	@IdCar int
--as
--insert into CarRent (CarRentIssueDate, CarRentCountDays, CarRentReturnDate, CarRentCost, CarRentPayMark, CarRentServ1, CarRentServ2, CarRentServ3, EmployeeId, ClientId, CarId) values
--(@IssueDate, @CountDays, @ReturnDate, @Cost, @PayMark, @Serv1, @Serv2, @Serv3, @IdEmployee, @IdClient, @IdCar)

--exec AddInCarRent  @IssueDate='2023-10-14',
--				   @CountDays=2,
--				   @ReturnDate='2023-10-16',
--				   @Cost=2500,
--				   @PayMark='YES', 
--				   @Serv1=3,
--				   @Serv2=1,
--				   @Serv3=2,
--				   @IdEmployee=1,
--				   @IdClient=3,
--				   @IdCar=1

--функции под фильтры

--1. Фильтры для отображения сотрудников отдельных должностей (На основе запроса "Отдел кадров").
--ФИЛЬТР
--select * from OtdelKadrov
--where PosName like '%Директор%'
--ФУНКЦИЯ
--alter function get_employee(@position varchar(20))
--returns table
--as 
--return (select * from OtdelKadrov where PosName like @position);
--ИСПОЛЬЗОВАНИЕ
--select * from get_employee('Механик%');

--2. Фильтры отображения автомобилей отдельных марок (На основе запроса "Автопарк").
--ФИЛЬТР
--select * from Autopark
--where BrandName like '%Mercedes%'
--ФУНКЦИЯ
--create function get_brand_car(@brand varchar(20))
--returns table
--as 
--return (select * from Autopark where BrandName like @brand);
--ИСПОЛЬЗОВАНИЕ
--select * from get_brand_car('%Merc%')

--3. Фильтры отображения автомобилей находящихся и не находящихся в прокате (На основе запроса "Автопарк").
--ФИЛЬТР
--select * from Autopark
--where CarReturnMark = 'YES'
--ФУНКЦИЯ
--create function returned_car(@retmark varchar(4))
--returns table
--as
--return (select * from Autopark where CarReturnMark = @retmark)
--ИСПОЛЬЗОВАНИЕ
--select * from returned_car('YES')
--select * from returned_car('NO')

--4. Фильтры для отображения автомобилей выданных и возвращённых в определённую дату (На основе запроса "Автопарк").
--ФИЛЬТР
--Выданных в определенную дату
--select * from CarsInRent
--where CarRentIssueDate = CAST('2023-10-11' as smalldatetime)
--ФУНКЦИЯ
--create function get_issue_date(@date varchar(10))
--returns table
--as
--return (select * from CarsInRent where CarRentIssueDate = CAST(@date as smalldatetime))
--ИСПОЛЬЗОВАНИЕ
--select * from get_issue_date('2023-10-11')

--ФИЛЬТР
--Возвращенных в определенную дату
--select * from CarsInRent
--where CarRentReturnDate = CAST('2023-10-14' as smalldatetime)
--ФУНКЦИЯ
--create function get_return_date(@date varchar(10))
--returns table
--as
--return (select * from CarsInRent where CarRentReturnDate = CAST(@date as smalldatetime))
--ИСПОЛЬЗОВАНИЕ
--select * from get_return_date('2023-10-14')

--5. Фильтры оплаченных и не оплаченных автомобилей в прокате (На основе запроса "Автопарк").
--ФИЛЬТР
--select * from CarsInRent
--where CarRentPayMark = 'NO'
--ФУНКЦИЯ
--create function payed_car(@retmark varchar(4))
--returns table
--as
--return (select * from CarsInRent where CarRentPayMark = @retmark)
--ИСПОЛЬЗОВАНИЕ
--select * from payed_car('NO')
--select * from payed_car('YES')