function [ok] = sum_ok()
ok  = true;
m   = 2;
n   = 3;
x   = rand(m, n);
% ------------------
y   = sum( sum(x) );
% ------------------
[p, q] = size(y);
ok     = ok & (p == 1) & (q == 1); 
ok     = ok & abs( y - ones(1, m) * x * ones(n, 1) ) < 1e-10;
return
