/*
$begin matrix_div.cpp$$
$spell
	config.h
	cpp
	C++
	Lapack
	dgesv
	nrhs
	lda
	ipv
	ldb
	fm
	fn
	cassert
	div
	hpp
	namespace
	const
	Elementwise
	Matlab or Octave
	C++
$$

$section Matrix Division Source Code$$

$codep */
# include <cassert>
# include <mat2cpp.hpp>
# include <config.h>

# define DGESV_F77 F77_FUNC_(dgesv, DGESV)

namespace mat2cpp {
	// Linkage for Fortran version of the Lapack routine dgesv
	extern "C" fortran_subroutine DGESV_F77(
		fortran_integer   *n, 
		fortran_integer   *nrhs, 
		fortran_double    *a, 
		fortran_integer   *lda, 
		fortran_integer   *ipv, 
		fortran_double    *b, 
		fortran_integer   *ldb, 
		fortran_integer   *info
	);
	matrix<double> matrix_div
	(const matrix<double> &x, const matrix<double> &y, size_t &rank)
	{	assert( x.size1() == x.size2() );
		assert( x.size2() == y.size1() );
	
		size_t i, j;
		size_t m               = y.size1();
		size_t n               = y.size2();
		fortran_double  *a     = new fortran_double  [m * m];
		fortran_double  *b     = new fortran_double  [m * n];
		fortran_integer *ipv   = new fortran_integer [m];
		for(i = 0; i < m; i++)
		{	for(j = 0; j < m; j++)
				a[ i + j * m ] = x(i, j);
			for(j = 0; j < n; j++)
				b[ i + j * m ] = y(i, j);
		}
		fortran_integer lda  = fortran_integer(m);
		fortran_integer ldb  = fortran_integer(m);
		fortran_integer fm   = fortran_integer(m);
		fortran_integer fn   = fortran_integer(n);
		fortran_integer info;
		DGESV_F77(&fm, &fn, a, &lda, ipv, b, &ldb, &info);
	
		assert( info >= 0 );
		if( info == 0 )
			rank = m;
		else	rank = size_t(info - 1);
	
		matrix<double> z(m, n);
		for(i = 0; i < m; i++)
		{	for(j = 0; j < n; j++)
				z(i, j) = b[ i + j * m ];
		}
		delete [] ipv;
		delete [] b;
		delete [] a;
		return z;
	}

}
/* $$
$end
*/
