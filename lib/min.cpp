/*
$begin min.cpp$$
$spell
	cassert
	hpp
	namespace
	const
	std
	mat2cpp
$$

$section Minimum Element of a Matrix Source Code$$

$codep */
# include <mat2cpp.hpp>
# include <cassert>
namespace mat2cpp {
	double min 
	(const matrix<double> &x)
	{	assert( x.size1() * x.size2() > 0 );
		double y = x(0, 0);
		size_t m = x.size1();
		size_t n = x.size2();
		size_t i, j;
		for(i = 0; i < m; i++)
		{	for(j = 0; j < n; j++)
				y = std::min(y, x(i, j));
		}
		return y;
	}
}
/* $$
$end
*/
