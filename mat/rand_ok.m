function [ok] = rand_ok()
ok      = true;
m       = 2;
n       = 3;
% -------------------
x       = rand(2, 3);
% -------------------
[m, n]  = size(x);
ok      = ok & (m == 2);
ok      = ok & (n == 3);
ok      = ok & all( all( 0 < x ) );      % probability of limit case is zero
ok      = ok & all( all( x < 1 ) );
ok      = ok & all( x(1,:) ~= x(2,:) );  % probability of equality is zero
return
