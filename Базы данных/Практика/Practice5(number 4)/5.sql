select distinct b.IdCust as '����� �������', IdProd as '����� ��������' from OrdItem a left join [Order] b on a.IdOrd = b.IdOrd
where b.IdCust = 12

select IdCust as '����� �������', IdProd as '����� ��������' from [Order] a, OrdItem b where a.IdOrd = b.IdOrd