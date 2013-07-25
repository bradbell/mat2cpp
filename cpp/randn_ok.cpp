# include <mat2cpp.hpp>
# include <cstdlib>
# include <cmath>

bool randn_ok(void)
{	bool   ok  = true;
	using namespace mat2cpp;

	size_t i, j, m(20), n(21);
	// ---------------------------
	matrix<double> x = randn(m, n);
	// ---------------------------
	ok &= (x.size1() == m);
	ok &= (x.size2() == n);
	double sum   = 0.;
	double sumsq = 0.;
	for(i = 0; i < m; i++)
	{	for(j = 0; j < n; j++)
		{	sum   += x(i, j);
			sumsq += x(i, j) * x(i, j);
		}
	}
	double N   = double( m * n );
	double avg = sum / N;
	double var = sumsq / N - avg * avg;

	// The variance of N independent standard normals is N
	// and variance of avg in 1/N.
	ok &= std::fabs(avg) < 3. / std::sqrt(N);

	//  The variance of N independent chi-squares is 2 * N
	// and variance of sumsq is 2/N
	ok &= std::fabs(var - 1.) < 3. * std::sqrt( 2. / N );
	return ok;
}
