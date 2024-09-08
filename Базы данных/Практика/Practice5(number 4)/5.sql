select distinct b.IdCust as 'Номер клиента', IdProd as 'Номер продукта' from OrdItem a left join [Order] b on a.IdOrd = b.IdOrd
where b.IdCust = 12

select IdCust as 'Номер клиента', IdProd as 'Номер продукта' from [Order] a, OrdItem b where a.IdOrd = b.IdOrd