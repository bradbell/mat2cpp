/*
$begin element_unary.cpp$$
$spell
	elementwise
	fabs
	undef
	cmath
	hpp
	namespace
	const
	std
	mat2cpp
$$

$section Elementwise Unary Functions Source Code$$

$codep */
# include <cmath>
# include <mat2cpp.hpp>

# define MAT2CPP_ELEMENT_UNARY(mat_f, std_f) \
matrix<double> mat_f \
(const matrix<double> &x) \
{	size_t i, j, m(x.size1()), n(x.size2()); \
	matrix<double> y(m, n); \
	for(i = 0; i < m; i++) \
	{	for(j = 0; j < n; j++) \
			y(i, j) = std::std_f(x(i, j)); \
	} \
	return y; \
}

namespace mat2cpp {
	MAT2CPP_ELEMENT_UNARY(abs, fabs)
	MAT2CPP_ELEMENT_UNARY(log, log)
}

# undef MAT2CPP_ELEMENT_UNARY
/* $$
$end
*/
