select IdOrd, [Description], Price, Qty, Qty * Price as 'Cost' from OrdItem as a, Product as b 
where a.IdProd = b.IdProd

select IdOrd, [Description], Price, Qty, Qty * Price as 'Cost' from OrdItem as a, Product as b 
where a.IdProd = b.IdProd and IdOrd = 3