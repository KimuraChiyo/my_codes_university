USE master;
GO
-- Удаление базы данных stroy, если она существует
IF EXISTS (SELECT name FROM sys.databases WHERE name = 'CarRental')
BEGIN
    ALTER DATABASE CarRental SET SINGLE_USER WITH ROLLBACK IMMEDIATE;
	DROP DATABASE CarRental
END

--Создание новой базы данных stroy
USE [master]
GO

/****** Object:  Database [CarRental]    Script Date: 10/13/2023 11:11:01 AM ******/
CREATE DATABASE [CarRental]
 CONTAINMENT = NONE
 ON  PRIMARY 
( NAME = N'CarRental', FILENAME = N'C:\my_codes_university\Databases\LabWorks\LabWork2\CarRental.mdf' , SIZE = 8192KB , MAXSIZE = UNLIMITED, FILEGROWTH = 65536KB )
 LOG ON 
( NAME = N'CarRental_log', FILENAME = N'C:\my_codes_university\Databases\LabWorks\LabWork2\CarRental_log.ldf' , SIZE = 8192KB , MAXSIZE = 2048GB , FILEGROWTH = 65536KB )
 WITH CATALOG_COLLATION = DATABASE_DEFAULT, LEDGER = OFF
GO

IF (1 = FULLTEXTSERVICEPROPERTY('IsFullTextInstalled'))
begin
EXEC [CarRental].[dbo].[sp_fulltext_database] @action = 'enable'
end
GO

ALTER DATABASE [CarRental] SET ANSI_NULL_DEFAULT OFF 
GO

ALTER DATABASE [CarRental] SET ANSI_NULLS OFF 
GO

ALTER DATABASE [CarRental] SET ANSI_PADDING OFF 
GO

ALTER DATABASE [CarRental] SET ANSI_WARNINGS OFF 
GO

ALTER DATABASE [CarRental] SET ARITHABORT OFF 
GO

ALTER DATABASE [CarRental] SET AUTO_CLOSE OFF 
GO

ALTER DATABASE [CarRental] SET AUTO_SHRINK OFF 
GO

ALTER DATABASE [CarRental] SET AUTO_UPDATE_STATISTICS ON 
GO

ALTER DATABASE [CarRental] SET CURSOR_CLOSE_ON_COMMIT OFF 
GO

ALTER DATABASE [CarRental] SET CURSOR_DEFAULT  GLOBAL 
GO

ALTER DATABASE [CarRental] SET CONCAT_NULL_YIELDS_NULL OFF 
GO

ALTER DATABASE [CarRental] SET NUMERIC_ROUNDABORT OFF 
GO

ALTER DATABASE [CarRental] SET QUOTED_IDENTIFIER OFF 
GO

ALTER DATABASE [CarRental] SET RECURSIVE_TRIGGERS OFF 
GO

ALTER DATABASE [CarRental] SET  DISABLE_BROKER 
GO

ALTER DATABASE [CarRental] SET AUTO_UPDATE_STATISTICS_ASYNC OFF 
GO

ALTER DATABASE [CarRental] SET DATE_CORRELATION_OPTIMIZATION OFF 
GO

ALTER DATABASE [CarRental] SET TRUSTWORTHY OFF 
GO

ALTER DATABASE [CarRental] SET ALLOW_SNAPSHOT_ISOLATION OFF 
GO

ALTER DATABASE [CarRental] SET PARAMETERIZATION SIMPLE 
GO

ALTER DATABASE [CarRental] SET READ_COMMITTED_SNAPSHOT OFF 
GO

ALTER DATABASE [CarRental] SET HONOR_BROKER_PRIORITY OFF 
GO

ALTER DATABASE [CarRental] SET RECOVERY FULL 
GO

ALTER DATABASE [CarRental] SET  MULTI_USER 
GO

ALTER DATABASE [CarRental] SET PAGE_VERIFY CHECKSUM  
GO

ALTER DATABASE [CarRental] SET DB_CHAINING OFF 
GO

ALTER DATABASE [CarRental] SET FILESTREAM( NON_TRANSACTED_ACCESS = OFF ) 
GO

ALTER DATABASE [CarRental] SET TARGET_RECOVERY_TIME = 60 SECONDS 
GO

ALTER DATABASE [CarRental] SET DELAYED_DURABILITY = DISABLED 
GO

ALTER DATABASE [CarRental] SET ACCELERATED_DATABASE_RECOVERY = OFF  
GO

ALTER DATABASE [CarRental] SET QUERY_STORE = ON
GO

ALTER DATABASE [CarRental] SET QUERY_STORE (OPERATION_MODE = READ_WRITE, CLEANUP_POLICY = (STALE_QUERY_THRESHOLD_DAYS = 30), DATA_FLUSH_INTERVAL_SECONDS = 900, INTERVAL_LENGTH_MINUTES = 60, MAX_STORAGE_SIZE_MB = 1000, QUERY_CAPTURE_MODE = AUTO, SIZE_BASED_CLEANUP_MODE = AUTO, MAX_PLANS_PER_QUERY = 200, WAIT_STATS_CAPTURE_MODE = ON)
GO

ALTER DATABASE [CarRental] SET  READ_WRITE 
GO

use CarRental;

CREATE TABLE Positions (
  PosId INT PRIMARY KEY IDENTITY,
  PosName varchar(40) NOT NULL unique, 
  PosSalary numeric(10, 3),
  PosResponsibilities VARCHAR(100),
  PosRequirements VARCHAR(100)
)
CREATE TABLE Employees (
  EmpId INT PRIMARY KEY IDENTITY,
  EmpFullName VARCHAR(100) NOT NULL,
  EmpAge INT not null
    CONSTRAINT CK_Emp_EmpAge CHECK(EmpAge > 17 AND EmpAge < 100),
  EmpSex VARCHAR(6) not null
    CONSTRAINT CK_Emp_EmpSex CHECK(EmpSex = 'Male' OR EmpSex = 'Female'),
  EmpPlace VARCHAR(100),
  EmpPhone VARCHAR(11) NOT NULL unique,
  EmpPassData NUMERIC(10, 0) unique,
  EmpPositionId INT REFERENCES Positions (PosId)
)
create table CarBrands (
  BrandId INT PRIMARY KEY IDENTITY,
  BrandName VARCHAR(20) NOT NULL,
  BrandCharacteristic VARCHAR(200),
  BrandDescription VARCHAR(100)
)
create table Cars (
  CarId int primary key identity,
  CarRegNumber varchar(9) unique,
  CarBody int
    constraint CH_Car_CarBody check(CarBody >= 0),
  CarEngine int
    constraint CH_Car_CarEngine check(CarEngine >= 0),
  CarIssueYear date
    constraint CH_Car_CarIssueYear check(datediff(year, '1990-01-01', CarIssueYear) > 0),
  CarMileAge numeric(10, 3)
    constraint CH_Car_CarMileage check(CarMileAge >= 0 and CarMileAge <= 9999999),
  CarCost numeric(12, 3)
    constraint CH_Car_CarCost check(CarCost >= 0 and CarCost <= 999999999.999),
  CarCostPerDay numeric(9, 2) not null
    constraint CH_Car_CarCostPerDay check(CarCostPerDay > 0 and CarCostPerDay <= 9999999.999),
  CarLastTechView date,
  CarSpecMarks varchar(100),
  CarReturnMark varchar(3),
  CarBrandId int references CarBrands (BrandId),
  CarEmployeeId int references Employees (EmpId)
)
create table Clients (
  ClientId int primary key identity,
  ClientFullName VARCHAR(100) NOT NULL,
  ClientSex VARCHAR(6) not null
    CONSTRAINT CK_Client_Sex CHECK(ClientSex = 'Male' OR ClientSex = 'Female'),
  ClientBirthDate date NOT NULL
    constraint CK_Client_BirthDate check(datediff(year, ClientBirthDate, getdate()) > 17)
)
create table AdditServices (
  ServId int primary key identity,
  ServName varchar(100) not null, 
  ServDescription varchar(100),
  ServCost numeric(10, 3)
    constraint CH_Car_Mileage check(ServCost > 0 and ServCost < 9999999)
)
create table CarRent (
  CarRentId int primary key identity,
  CarRentIssueDate date not null,
  CarRentCountDays int not null
    constraint CH_CarRent_CarRentCountDays check(CarRentCountDays > 0),
  CarRentReturnDate date,
  CarRentCost numeric(10, 3) not null
    constraint CH_Car_CarRentCost check(CarRentCost > 0 and CarRentCost < 9999999),
  CarRentPayMark varchar(3) not null,
  CarRentServ1 int references AdditServices (ServId),
  CarRentServ2 int references AdditServices (ServId),
  CarRentServ3 int references AdditServices (ServId),
  EmployeeId int references Employees (EmpId),
  ClientId int references Clients (ClientId),
  CarId int references Cars (CarId)
)

insert into CarBrands (BrandName, BrandCharacteristic, BrandDescription) values ('Toyota', 'Приятные машинки', 'Это что? Супра? Супра классная'),
																				('BMW', 'Машинки для любителей', 'Часто ездят в ТО'),
																				('Bugatti', 'Дорогущие машинки', 'Легкая встреча со столбом'),
																				('Mercedes', 'Премиум машинки', 'Элита'),
																				('Volvo', 'Безопасные машинки', 'Полубоги') 
insert into Clients (ClientFullName, ClientSex, ClientBirthDate) values ('Соловьёв Леонид Александрович', 'Male', '2004-12-27'),
																		('Иванова Ирина Александровна', 'Female', '2000-01-01'),
																		('Иванов Иван Иванович', 'Male', '1990-12-01'),
																		('Иванов Иван Петрович', 'Male', '1990-12-02'),
																		('Иванов Иван Денисович', 'Male', '1990-12-03')
insert into Positions (PosName, PosSalary, PosResponsibilities, PosRequirements) values ('Директор', 3000000.00, 'Существовать, решать дела', 'Быть предприимчивым')
insert into Positions (PosName, PosSalary) values ('Механик-инженер', 75000.00),
												  ('Менеджер', 125000.00),
												  ('Механик-электрик', 125000.00),
												  ('Разработчик сайтов', 0.00)
insert into Employees (EmpFullName, EmpAge, EmpSex, EmpPhone, EmpPassData, EmpPositionId) values ('Иванов Иван Иванович', 30, 'Male', '11111111111', '1111111111', 1),
																								 ('Петров Петр Петрович', 19, 'Male', '22222222222', '2222222222', 3),
																								 ('Дмитриев Дмитрий Дмитриевич', 20, 'Male', '33333333333', '3333333333', 2),
																								 ('Маликов Дмитрий Анатольевич', 40, 'Male', '44444444444', '4444444444', 2),
																								 ('Андреева Мива Андреевна', 24, 'Female', '55555555555', '5555555555', 3),
																								 ('Асгардов Локи Лафейсон', 27, 'Male', '66666666666', '6666666666', 2),
																								 ('Асгардов Тор Одинсон', 28, 'Male', '77777777777', '7777777777', 4),
																								 ('Мидгардов Тони Старкович', 45, 'Male', '88888888888', '8888888888', 4),
																								 ('Терентьев Михаил Павлович', 29, 'Male', '99999999999', '9999999999', 4),
																								 ('Соловьёв Леонид Александрович', 18, 'Male', '79003289471', '1000000000', 5)
insert into Cars (CarRegNumber, CarMileAge, CarCostPerDay, CarReturnMark, CarBrandId, CarEmployeeId) values ('A111БУ16', 27123.82, 2500, 'YES', 1, 3),
																											('A222БУ16', 127123.82, 4000, 'YES', 2, 4),
																											('A333БУ16', 0, 2500, 'YES', 1, 3),
																											('A444БУ16', 100000, 10000, 'YES', 3, 6),
																											('A555БУ16', 120000, 10000, 'YES', 4, 4),
																											('A666БУ16', 15000, 6000, 'YES', 4, 4),
																											('A777БУ16', 10000, 50000, 'YES', 5, 4) 
insert into Cars (CarRegNumber, CarMileAge, CarCostPerDay, CarReturnMark, CarBrandId) values ('A888БУ16', 23002, 2500, 'NO', 1),
																							 ('A999БУ16', 17000, 5000, 'NO', 4),
																							 ('A000БУ16', 15000, 5000, 'NO', 4) 
insert into AdditServices (ServName, ServDescription, ServCost) values ('Электрика', 'Починка коробки', 15000),
																	   ('Внешний вид', 'Вправление вмятин', 16100),
																	   ('Внешний вид', 'Замена фар', 10000),
																	   ('Внешний вид', 'Подкачка шин', 1000),
																	   ('Внешний вид', 'Покраска кузова', 20000)
insert into CarRent (CarRentIssueDate, CarRentCountDays, CarId, CarRentCost, CarRentPayMark, CarRentServ1, ClientId) values ('2023-10-11', 1, 1, 2500, 'YES', 1, 1),
																															('2023-10-12', 1, 2, 4000, 'YES', 1, 1),
																															('2023-10-13', 1, 3, 2500, 'YES', 1, 1),
																															('2023-10-11', 1, 4, 10000, 'YES', 2, 1),
																															('2023-10-12', 1, 5, 10000, 'YES', 2, 1),
																															('2023-10-13', 1, 6, 6000, 'YES', 2, 1)
insert into CarRent (CarRentIssueDate, CarRentCountDays, CarId, CarRentCost, CarRentPayMark, CarRentServ1, CarRentServ2, ClientId) values ('2023-10-13', 1, 10, 5000, 'NO', 3, 2, 1)
insert into CarRent (CarRentIssueDate, CarRentCountDays, CarId, CarRentCost, CarRentPayMark, ClientId) values ('2023-10-10', 1, 7, 50000, 'NO', 1),
																											  ('2023-10-11', 1, 8, 2500, 'NO', 1),
																											  ('2023-10-12', 1, 9, 5000, 'NO', 1)

select * from AdditServices;
select * from CarBrands;
select * from CarRent;
select * from Cars;
select * from Clients;
select * from Employees;
select * from Positions;
