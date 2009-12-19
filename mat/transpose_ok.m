function [ok] = transpose_ok()
ok  = true;
m   = 2;
n   = 3;
x   = rand(m, n);
% -------
y   = x';
% -------
[r, c] = size(y);
ok     = ok & (r == n);
ok     = ok & (c == m);
for i = 1 : m
	for j = 1 : n
		ok = ok & (y(j, i) == x(i, j));
	end
end
return
