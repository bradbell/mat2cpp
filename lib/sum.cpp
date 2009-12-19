/*
$begin sum.cpp$$
$spell
	Matlab
	cassert
	hpp
	namespace
	const
	std
	mat2cpp
$$

$section Sum The Elements of a Matlab Source Code$$

$codep */
# include <mat2cpp.hpp>
# include <cassert>
namespace mat2cpp {
	double sum 
	(const matrix<double> &x)
	{	double y = 0.;
		size_t m = x.size1();
		size_t n = x.size2();
		size_t i, j;
		for(i = 0; i < m; i++)
		{	for(j = 0; j < n; j++)
				y += x(i, j);
		}
		return y;
	}
}
/* $$
$end
*/
