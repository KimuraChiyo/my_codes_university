select *, Qty*Price as '��������� ��������� ����������� ������' from OrdItem

select IdOrd, Sum(Qty*Price) as '��������� ���������' from OrdItem group by IdOrd