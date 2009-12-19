function [ok] = element_div_ok()
ok  = true;
m   = 3;
n   = 2;
x   = rand(m, n);
y   = rand(m, n);
% --------------
z      = x ./ y;
% --------------
[m, n] = size(z);
ok     = ok & (m == 3);
ok     = ok & (n == 2);
for i = [1 : m]
	for j = [1 : n]
		zij = x(i, j) / y(i, j);
		ok  = ok & abs(z(i, j) - zij) < 1e-10;
	end
end
return 
