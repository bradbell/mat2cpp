/*
$begin scalar.cpp$$
$spell
	Matlab
	cassert
	xj
	iterator
	hpp
	namespace
	const
	std
	vj
	mat2cpp
$$

$section Convert Matrix to Scalar Source Code$$

$codep */
# include <mat2cpp.hpp>
# include <cassert>
namespace mat2cpp {
	double scalar 
	(const matrix<double> &x)
	{	assert( x.size1() * x.size2() == 1 );
		double y = x(0, 0);
		return y;
	}
}
/* $$
$end
*/
