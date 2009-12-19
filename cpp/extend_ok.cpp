# include <mat2cpp.hpp>
bool extend_ok(void)
{	using namespace mat2cpp;

	bool   ok  = true;
	size_t i, j, m(2), n(3);
	matrix<double> x(m, n);
	for(i = 0; i < m; i++)
	{	for(j = 0; j < n; j++)
			x(i, j) = double(i+j);
	}
	// -------------------------------
	x.resize(m, n + 1);
	for(i = 0; i < m; i++)
		x(i, n) = double(i + n);
	// -------------------------------
	ok &= (x.size1() == m);
	ok &= (x.size2() == n + 1);
	for(i = 0; i < m; i++)
	{	for(j = 0; j < n; j++)
			ok &= (x(i, j) == double(i+j));
	}
	return ok;
}
