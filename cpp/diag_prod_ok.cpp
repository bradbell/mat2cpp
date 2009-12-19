# include <mat2cpp.hpp>
bool diag_prod_ok(void)
{	bool   ok  = true;
	using namespace mat2cpp;

	size_t i, j, m(3), n(2);
	matrix<double> u = rand(m, 1);
	matrix<double> x = rand(1, m);
	matrix<double> y = rand(m, n);
	// --------------------------------
	matrix<double> w = diag_prod(u, y);
	matrix<double> z = diag_prod(x, y);
	// --------------------------------
	ok &= (z.size1() == m);
	ok &= (z.size2() == n);
	for(i = 0; i < m; i++)
	{	for(j = 0; j < n; j++)
		{	double wij = u(i,0) * y(i,j);
			double zij = x(0,i) * y(i,j);
			ok &= std::fabs(w(i, j) - wij) < 1e-10;
			ok &= std::fabs(z(i, j) - zij) < 1e-10;
		}
	}
	return ok;
}
