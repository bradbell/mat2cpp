function [ok] = matrix_div_ok()
ok  = true;
m   = 3;
n   = 2;
x   = rand(m, m);
y   = rand(m, n);
% -------------
z      = x \ y;
% -------------
[m, n] = size(z);
ok     = ok & (m == 3);
ok     = ok & (n == 2);
ok     = ok & all ( all( abs(x * z - y) < 1e-10 ) );
return 
