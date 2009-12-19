# include <mat2cpp.hpp>
bool transpose_ok(void)
{	bool   ok  = true;
	using namespace mat2cpp;

	size_t i, j, m(2), n(3);
	matrix<double> x = rand(m, n);
	// -------------------------
	matrix<double> y = trans(x);
	// -------------------------
	ok &= (y.size1() == n);
	ok &= (y.size2() == m);
	for(i = 0; i < m; i++)
	{	for(j = 0; j < n; j++)
			ok &= y(j,i) == x(i,j);
	}
	return ok;
}
