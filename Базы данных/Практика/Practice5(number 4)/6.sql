select distinct a.IdCust as '����� ��������, ������� �� ������ ������' from Customer a left join [Order] b on a.IdCust = b.IdCust
where a.IdCust not in (select IdCust from [Order])

select distinct IdCust as '����� ��������, ������� ������ ������' from [Order]

select * from [Order]