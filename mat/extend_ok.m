function [ok] = extend_ok()
ok       = true;
m        = 2;
n        = 3;
for i = 1 : m
	for j = 1 : n
		x(i, j) = i + j;
	end
end
% -----------------------
for i = 1 : m
	x(i, n + 1) = i + (n + 1);
end
% -----------------------
[m, n]   = size(x);
ok       = ok & (m == 2);
ok       = ok & (n == 4);
for i = 1 : m
	for j = 1 : n
		ok = ok & (x(i, j) == i + j);
	end
end
return
