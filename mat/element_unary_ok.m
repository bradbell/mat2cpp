function [ok] = element_unary_ok()
ok  = true;
m   = 2;
n   = 3;
x   = rand(m, n);
% ---------------
abs_x   = abs(x);
log_x   = log(x);
% ---------------
for i = 1 : m
	for j = 1 : n
		ok = ok & ( abs_x(i, j) == abs(x(i, j)) );
		ok = ok & ( log_x(i, j) == log(x(i, j)) );
	end
end
return
