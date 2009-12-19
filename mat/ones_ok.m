function [ok] = ones_ok()
ok      = true;
m       = 2;
n       = 3;
% -------------------
x       = ones(2, 3);
% -------------------
[m, n]  = size(x);
ok      = ok & (m == 2);
ok      = ok & (n == 3);
ok      = ok & all( all( x == 1 ) );
return
