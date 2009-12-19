function [ok] = matrix_prod_ok()
ok  = true;
m   = 3;
n   = 2;
p   = 4;
x   = rand(m, n);
y   = rand(n, p);
% --------------
z      = x * y;
% --------------
[m, p] = size(z);
ok     = ok & (m == 3);
ok     = ok & (p == 4);
for i = [1 : m]
	for j = [1 : p]
		zij = 0;
		for k = [1 : n]
			zij = zij + x(i, k) * y(k, j);
		end
		ok  = ok & abs(z(i, j) - zij) < 1e-10;
	end
end
return 
