/*
$begin diag_prod.cpp$$
$spell
	ublas
	cpp
	cassert
	hpp
	namespace
	const
	Matlab or Octave
	C++
$$

$section Diagonal Matrix Product with General Matrix Source Code$$

$codep */
# include <cassert>
# include <mat2cpp.hpp>
namespace mat2cpp {
	matrix<double> diag_prod 
	(const matrix<double> &x, const matrix<double> &y)
	{	size_t i, j, m(y.size1()), n(y.size2());
		matrix<double> z(m, n);
		if( x.size1() == 1 )
		{	// check that dimensions match
			assert( x.size2() == m );
			for(i = 0; i < m; i++)
			{	for(j = 0; j < n; j++)
					z(i, j) = x(0, i) * y(i, j);
			}
		}
		else if( x.size2() == 1 )
		{	// check that dimensions match
			assert( x.size1() == m );
			for(i = 0; i < m; i++)
			{	for(j = 0; j < n; j++)
					z(i, j) = x(i, 0) * y(i, j);
			}
		}
		else
		{	// this is a diag_prod usage error
			assert(0);
		}
		return z;
	}
}
/* $$
$end
*/
