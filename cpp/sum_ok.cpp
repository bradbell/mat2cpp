# include <mat2cpp.hpp>
bool sum_ok(void)
{	bool   ok  = true;
	using namespace mat2cpp;

	size_t i, j, m(2), n(3);
	matrix<double> x = rand(m, n);
	// ---------------
	double y = sum(x);
	// ---------------
	double check = 0.;
	for(i = 0; i < m; i++)
	{	for(j = 0; j < n; j++)
			check += x(i,j);
	}
	ok &= std::fabs(check - y) < 1e-10;
	return ok;
}
