# include <mat2cpp.hpp>
bool min_ok(void)
{	bool   ok  = true;
	using namespace mat2cpp;

	size_t i, j, m(2), n(3);
	matrix<double> x = rand(m, n);
	// ---------------
	double y = min(x);
	// ---------------
	bool greater = true;
	for(i = 0; i < m; i++)
	{	for(j = 0; j < n; j++)
		{	ok      &= x(i,j) >= y;
			greater &= x(i,j) > y;
		}
	}
	ok &= ! greater;
	return ok;
}
