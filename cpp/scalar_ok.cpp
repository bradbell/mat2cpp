# include <mat2cpp.hpp>
# include <cstdlib>
bool scalar_ok(void)
{	bool   ok  = true;
	using namespace mat2cpp;

	size_t i, j, m(2), n(3);
	matrix<double> u = rand(m, n);
	matrix<double> v = u;
	matrix<double> x(1, 1);
	x(0, 0) = 5.;
	// ------------
	v *= scalar(x);
	// ------------
	for(i = 0; i < m; i++)
	{	for(j = 0; j < n; j++)
			ok   &= std::fabs( v(i,j) - u(i,j) * x(0,0)) <= 1e-10;
	}
	return ok;
}
