clear; 
clc; 
a=-34;
b=-93;
c=66;
d=47;
mprintf('Исходные переменные: a=%d b=%d c=%d d=%d\n', a, b, c, d)
if a<0 then
 a=-2*a;
end
if b<0 then
 b=-2*b;
end
if c<0 then
 c=-2*c;
end
if d<0 then
 d=-2*d;
end
mprintf('Измененные переменные: a=%d b=%d c=%d d=%d\n', a, b, c, d)
x=2.7;
mprintf('\n  x=%g\n',x)
n=1; H=1; S=H;
 mprintf('%5s%15s%15s\n','n: ','H: ','S: ');
 mprintf('%5d%15.10f%15.10f\n',n,H,S);
 while abs(H)>10^(-5)
 n=n+1;
 H=-H * ((x^2) / (4*n^2 - 2*n));
 S=S+H;
 mprintf('%5d%15.10f%15.10f\n',n,H,S);
 end
 mprintf(' Сумма ряда S(x) = %.10f\n',S);
