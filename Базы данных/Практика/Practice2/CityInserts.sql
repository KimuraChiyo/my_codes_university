INSERT INTO City (CityName) values 
('Kazan1'),
('Kazan2'),
('Kazan3'),
('Kazan4'),
('Kazan5'),
('Kazan6'),
('Kazan7'),
('Kazan8'),
('Kazan9'),
('Kazan10'),
('Kazan11'),
('Kazan12'),
('Kazan13'),
('Kazan14')

SELECT TOP (1000) [IdCity]
      ,[CityName]
  FROM [Sales].[dbo].[City]
