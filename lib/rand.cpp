/*
$begin rand.cpp$$
$spell
	Matlab
	srand
	cstdlib
	hpp
	stdlib
	namespace
	std
	mat2cpp
	bool
	mztuni
$$

$section Uniform Random Matrix Source Code$$

$codep */
# include <cstdlib>
# include <mat2cpp.hpp>
# include <mztuni.hpp>

namespace mat2cpp {
	matrix<double> rand(size_t m, size_t n) 
	{	matrix<double> x(m, n);
		size_t i, j;
		double rand_max   = double(RAND_MAX);
		bool   use_mztuni = mztuni_seed(0) != 0;
		// 
		for(i = 0; i < m; i++)
		{	for(j = 0; j < n; j++)
				if( use_mztuni )
					x(i, j) = mztuni();
				else
					x(i, j) = double(std::rand()) / rand_max;
		} 
		return x;
	}
}
/* $$
$end
*/
