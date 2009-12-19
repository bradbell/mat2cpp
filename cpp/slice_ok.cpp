# include <mat2cpp.hpp>
bool slice_ok(void)
{	bool   ok  = true;
	using namespace mat2cpp;

	size_t i, j, k, m(3), n(4);
	matrix<double> x(m, n);
	for(i = 0; i < m; i++)
	{	for(j = 0; j < n; j++)
			x(i, j) = i * j;
	}
	zero_matrix<double> y(2, 2);
	// -------------------------
	slice r = slice(0, 2, 2);
	slice c = slice(0, 2, 2);
	matrix_slice_double (x, r, c) = y;
	// -------------------------
	ok &= (x.size1() == m);
	ok &= (x.size2() == n);
	for(i = 0; i < m; i++)
	{	for(j = 0; j < n; j++)
		{ 	bool row_match = false;
			for(k = 0; k < r.size(); k++)
				row_match |= (i == r.start() + r.stride() * k);
			bool col_match = false;
			for(k = 0; k < c.size(); k++)
				col_match |= (j == c.start() + c.stride() * k);
			if( row_match & col_match )
				ok &= (x(i,j) == 0.);
			else	ok &= (x(i,j) == double(i * j));
		}
	}
	return ok;
}
