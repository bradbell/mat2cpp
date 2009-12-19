function [ok] = scalar_ok()
ok  = true;
m   = 2;
n   = 3;
u   = rand(m, n);
x   = 5;
% ----------
v   = u * x;
% ----------
[m, n] = size(v);
ok     = ok & (m == 2) & (n == 3); 
for i = 1 : m
	for j = 1 : n
		ok = ok & abs(v(i,j) - u(i,j) * x(1,1)) < 1e-10;
	end
end
return
