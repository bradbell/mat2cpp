# include <cstdlib>
# include <mat2cpp.hpp>
bool scalar_prod_ok(void)
{	bool   ok  = true;
	using namespace mat2cpp;

	size_t i, j, m(3), n(2);
	matrix<double> x = rand(m, n);
	double         y = std::rand() / double(RAND_MAX);
	// ----------------------
	matrix<double> z = x * y;
	z *= y;
	// ----------------------
	ok &= (z.size1() == m);
	ok &= (z.size2() == n);
	for(i = 0; i < m; i++)
	{	for(j = 0; j < n; j++)
		{	double zij = (x(i,j) * y) * y;
			ok &= std::fabs(z(i, j) - zij) < 1e-10;
		}
	}
	return ok;
}
