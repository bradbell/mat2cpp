# include <mat2cpp.hpp>
bool max_ok(void)
{	bool   ok  = true;
	using namespace mat2cpp;

	size_t i, j, m(2), n(3);
	matrix<double> x = rand(m, n);
	// ---------------
	double y = max(x);
	// ---------------
	bool less = true;
	for(i = 0; i < m; i++)
	{	for(j = 0; j < n; j++)
		{	ok   &= x(i,j) <= y;
			less &= x(i,j) < y;
		}
	}
	ok &= ! less;
	return ok;
}
