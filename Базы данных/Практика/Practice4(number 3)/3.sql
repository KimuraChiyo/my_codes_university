select *, Qty*Price as '��������� ��������� ����������� ������' from OrdItem

select Sum(c.[��������� ��������� ����������� ������]) as '��������� ��������� �������' from (select *, Qty*Price as '��������� ��������� ����������� ������' from OrdItem) c