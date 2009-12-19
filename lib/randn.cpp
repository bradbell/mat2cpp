/*
$begin randn.cpp$$
$spell
	randn
	cmath
	ed
	Merran Evans, Nicholas Hastings, and Brian Peacock
	atan
	sqrt
	cos
	Matlab
	srand
	cstdlib
	hpp
	stdlib
	namespace
	std
	mat2cpp
$$

$section Normal Random Matrix Source Code$$

$codep */
# include <cstdlib>
# include <mat2cpp.hpp>
# include <cmath>

namespace mat2cpp {
	matrix<double> randn(size_t m, size_t n) 
	{	// use formula 30.3 of Statistical Distributions (3rd ed)
		// Merran Evans, Nicholas Hastings, and Brian Peacock
		matrix<double> u = rand(m * n + 1 , 1);
		matrix<double> x(m, n);
		size_t i, j, k;
		double pi  = 4. * std::atan(1.);
		double square, amp, angle;
		k = 0;
		for(i = 0; i < m; i++)
		{	for(j = 0; j < n; j++)
			{	if( k % 2 == 0 )
				{	square = - 2. * std::log( u(k, 0) );
					if( square < 0. )
						square = 0.;
					amp = sqrt(square);
					angle = 2. * pi * u(k+1, 0);
					x(i, j) = amp * std::sin( angle );
				}
				else	x(i, j) = amp * std::cos( angle );
				k++;
			}
		}
		return x;
	}
}
/* $$
$end
*/
