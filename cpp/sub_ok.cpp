# include <cmath>
# include <mat2cpp.hpp>
bool sub_ok(void)
{	bool   ok  = true;
	using namespace mat2cpp;

	size_t i, j, m(3), n(2);
	matrix<double> x = rand(m, n);
	matrix<double> y = rand(m, n);
	// ----------------------
	matrix<double> z = x - y;
	// ----------------------
	ok &= (z.size1() == m);
	ok &= (z.size2() == n);
	for(i = 0; i < m; i++)
	{	for(j = 0; j < n; j++)
		{	double zij = x(i,j) - y(i,j);
			ok &= std::fabs(z(i, j) - zij) < 1e-10;
		}
	}
	return ok;
}
