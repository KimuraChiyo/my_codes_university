select * from [OrdItem] as a left join Product as b on a.IdProd = b.IdProd

select IdOrd from [OrdItem]
where IdProd = (Select IdProd from Product where [Description] = 'Монитор1')