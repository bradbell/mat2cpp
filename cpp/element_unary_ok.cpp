# include <mat2cpp.hpp>
# include <limits>

bool element_unary_ok(void)
{	bool   ok  = true;
	using namespace mat2cpp;
	double eps = 10. * std::numeric_limits<double>::epsilon();

	size_t i, j, m(2), n(3);
	matrix<double> x = rand(m, n);
	// ---------------------------
	matrix<double> abs_x = abs(x);
	matrix<double> log_x = log(x);
	// ---------------------------
	for(j = 0; j < n; j++)
	{	for(i = 0; i < m; i++)
		{	ok &= std::fabs( abs_x(i, j) - std::fabs(x(i, j)) ) < eps;
			ok &= std::fabs( log_x(i, j) - std::log(x(i, j))  ) < eps;
		}
	}
	return ok;
}
