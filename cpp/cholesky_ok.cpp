# include <boost/numeric/ublas/matrix.hpp>
# include <mat2cpp.hpp>
bool cholesky_ok(void)
{	bool   ok  = true;
	using namespace mat2cpp;

	size_t i, j, m(3);
	matrix<double> a = rand(m, m);
	matrix<double> x = prod(trans(a), a);
	// ---------------------------------------
	size_t rank;
	matrix<double> y = cholesky(x, rank);
	// ---------------------------------------
	ok &= (rank      == m);
	ok &= (y.size1() == m);
	ok &= (y.size2() == m);
	matrix<double> check = prod(trans(y), y);
	for(i = 0; i < m; i++)
	{	for(j = 0; j < m; j++)
			ok &= std::fabs( check(i, j) - x(i,j) ) < 1e-10;
	}
	for(i = 0; i < m; i++)
	{	for(j = 0; j < i; j++)
			ok &= (y(i, j) == 0.); 
	}
	return ok;
}
