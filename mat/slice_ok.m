function [ok] = slice_ok()
ok      = true;
m       = 3;
n       = 4;
x       = (1 : m)' * (1 : n);
y       = zeros(2, 2);
% --------------------
r       = 1 : 2 : 3;
c       = 1 : 2 : 3;
x(r, c) = y;
% --------------------
[p, q]  = size(x);
ok      = ok & (m == p);
ok      = ok & (n == q);
for i = 1 : m
	for j = 1 : n
		if any(i == r) & any( j == c) 
			ok = ok & x(i, j) == 0;
		else
			ok = ok & x(i, j) == i * j;
		end
	end
end
return
