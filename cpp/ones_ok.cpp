# include <mat2cpp.hpp>
bool ones_ok(void)
{	bool   ok  = true;
	using namespace mat2cpp;

	size_t i, j, m(2), n(3);
	// -------------------------------
	scalar_matrix<double> x(m, n, 1.);
	// -------------------------------
	ok &= (x.size1() == m);
	ok &= (x.size2() == n);
	for(i = 0; i < m; i++)
	{	for(j = 0; j < n; j++)
			ok &= (x(i,j) == 1.);
	}
	return ok;
}
