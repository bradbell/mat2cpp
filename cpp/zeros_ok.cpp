# include <mat2cpp.hpp>
bool zeros_ok(void)
{	bool   ok  = true;
	using namespace mat2cpp;

	size_t i, j, m(2), n(3);
	// -------------------------
	zero_matrix<double> x(m, n);
	// -------------------------
	ok &= (x.size1() == m);
	ok &= (x.size2() == n);
	for(i = 0; i < m; i++)
	{	for(j = 0; j < n; j++)
			ok &= (x(i,j) == 0.);
	}
	return ok;
}
