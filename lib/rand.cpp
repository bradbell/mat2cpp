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
$$

$section Uniform Random Matrix Source Code$$

$codep */
# include <cstdlib>
# include <mat2cpp.hpp>
namespace mat2cpp {
	matrix<double> rand(size_t m, size_t n) 
	{	matrix<double> x(m, n);
		size_t i, j;
		double rand_max = double(RAND_MAX);
		for(i = 0; i < m; i++)
		{	for(j = 0; j < n; j++)
				x(i, j) = double(std::rand()) / rand_max;
		} 
		return x;
	}
}
/* $$
$end
*/
