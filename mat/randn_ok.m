function [ok] = randn_ok()
ok      = true;
m       = 100;
n       = 11;
% -------------------
x       = randn(m, n);
% -------------------
[m_, n_]= size(x);
ok      = ok & (m == m_);
ok      = ok & (n == n_);
N       = m * n;
sum_    = sum( sum(x) );
sumsq   = sum( sum( x .* x ) );
avg     = sum_ / N;
var     = sumsq / N -  avg * avg;
ok      = ok & abs( avg ) < 2 / sqrt(N);
% The variance of N independent chi-squares is 2 / N
ok      = ok & abs(var - 1.) < 2 * sqrt( 2. / N );
return
