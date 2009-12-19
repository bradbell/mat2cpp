# include <mat2cpp.hpp>
bool size_ok(void)
{	bool   ok  = true;
	using namespace mat2cpp;

	size_t m(2), n(3);
	matrix<double> x(m, n);
	// --------------------
	ok &= (x.size1() == m);
	ok &= (x.size2() == n);
	// --------------------
	return ok;
}
