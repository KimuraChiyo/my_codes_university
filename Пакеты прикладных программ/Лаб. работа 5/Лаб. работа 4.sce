clear 
clc 
clf
x=[-2.5:0.5:2.5]
y1=(1 + x) ./ (1 + x.^2);
disp(y1);
plot(x,y1,'LineStyle','--','Color','r','Thickness',5,...
'Marker','s','MarkerEdgeColor','b','MarkerFaceColor','y',...
'MarkerSize',10)
y2=-1 + (1 + (cos(x) ./ (3 + x)));
plot(x,y2,'LineStyle','-','Color','g','Thickness',3,...
'Marker','o','MarkerEdgeColor','r','MarkerFaceColor','k',...
'MarkerSize',10)
xtitle('Графики функций y1(x),y2(x)','X','Y')
legend('y1(x)','y2(x)',1)
xgrid
