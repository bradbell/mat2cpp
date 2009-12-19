function [ok] = zeros_ok()
ok      = true;
m       = 2;
n       = 3;
% --------------------
x       = zeros(2, 3);
% --------------------
[m, n]  = size(x);
ok      = ok & (m == 2);
ok      = ok & (n == 3);
ok      = ok & all( all( x == 0 ) );
return
