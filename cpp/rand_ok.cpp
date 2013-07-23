# include <mat2cpp.hpp>
# include <cstdlib>

bool rand_ok(void)
{	bool   ok  = true;
	using namespace mat2cpp;

	size_t i, j, m(2), n(3);
	// ---------------------------
	matrix<double> x = rand(m, n);
	// ---------------------------
	ok &= (x.size1() == m);
	ok &= (x.size2() == n);
	for(i = 0; i < m; i++)
	{	for(j = 0; j < n; j++)
		{	ok &= (0. < x(i, j) ); // probability of limit is zero
			ok &= (x(i, j) < 1.);
		}
	}
	for(j = 0; j < n; j++)
		ok &= (x(0, j) != x(1, j));    // probability zero
	return ok;
}
