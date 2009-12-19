# include <boost/numeric/ublas/matrix.hpp>
# include <mat2cpp.hpp>
bool matrix_div_ok(void)
{	bool   ok  = true;
	using namespace mat2cpp;

	size_t i, j, m(3), n(2);
	matrix<double> x = rand(m, m);
	matrix<double> y = rand(m, n);
	// ---------------------------------------
	size_t rank;
	matrix<double> z = matrix_div(x, y, rank);
	// ---------------------------------------
	ok &= (rank      == m);
	ok &= (z.size1() == m);
	ok &= (z.size2() == n);
	matrix<double> x_z = prod(x, z);
	for(i = 0; i < m; i++)
	{	for(j = 0; j < n; j++)
			ok &= std::fabs( x_z(i,j) - y(i,j) ) < 1e-10;
	}
	return ok;
}
