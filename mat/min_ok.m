function [ok] = min_ok()
ok  = true;
m   = 2;
n   = 3;
x   = rand(m, n);
% ------------------
y   = min( min(x) );
% ------------------
[m, n] = size(y);
ok     = ok & (m == 1) & (n == 1); 
ok     = ok & all( all ( x >= y ) );
ok     = ok & ~ all( all ( x > y ) );
return
