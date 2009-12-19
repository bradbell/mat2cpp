function [ok] = size_ok()
ok      = true;
x       = [ 1 2 3 ; 4 5 6 ];
% ----------------
[m, n]  = size(x);
% ----------------
ok      = ok & (m == 2);
ok      = ok & (n == 3);
return
