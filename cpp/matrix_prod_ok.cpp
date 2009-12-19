# include <boost/numeric/ublas/matrix.hpp>
# include <mat2cpp.hpp>
bool matrix_prod_ok(void)
{	bool   ok  = true;
	using namespace mat2cpp;

	size_t i, j, k, m(3), n(2), p(4);
	matrix<double> x = rand(m, n);
	matrix<double> y = rand(n, p);
	// ---------------------------
	matrix<double> z = prod(x, y);
	// ---------------------------
	ok &= (z.size1() == m);
	ok &= (z.size2() == p);
	for(i = 0; i < m; i++)
	{	for(j = 0; j < p; j++)
		{	double zij = 0.;
			for(k = 0; k < n; k++)
				zij += x(i,k) * y(k,j);
			ok &= std::fabs(z(i, j) - zij) < 1e-10;
		}
	}
	return ok;
}
