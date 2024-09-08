R = 5.0;
H = 3;
V = (4 * %pi * R^3) / 3;
S = 4 * %pi * R^2;
Vc = (1/3) * %pi*H^2 * (3*R - H);
mprintf('\n');
mprintf('\tИСХОДНЫЕ ДАННЫЕ:\n\n'); 
mprintf('R= %.2f мм \n', R);
mprintf('H= %.2f мм \n\n', H);
mprintf('------------------------------------------\n') ;
mprintf('\n\tОТВЕТ:\n\n'); 
mprintf('V=%.2f куб.см\tS=%.2f кв.см\tVc=%.2f куб.см\n', V, S, Vc);

