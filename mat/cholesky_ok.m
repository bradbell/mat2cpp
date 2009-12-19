function [ok] = cholesky_ok()
ok  = true;
m   = 3;
a   = rand(m, m);
x   = a' * a; 
% -------------
[y, r]  = chol(x);
% -------------
[m, n] = size(y);
ok     = ok & (m == 3);
ok     = ok & (n == 3);
ok     = ok & all ( all( abs(y' * y - x) < 1e-10 ) );
for i = 1 : m
	for j = 1 : (i-1)
		ok = ok & (y(i,j) == 0);
	end
end
ok     = ok & (r == 0);
return 
