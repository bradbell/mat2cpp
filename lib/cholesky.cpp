/*
$begin cholesky.cpp$$
$spell
	cholesky
	uplo
	dpotrf
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

$section Cholesky Factor a Matrix Source Code$$

$codep */
# include <cassert>
# include <mat2cpp.hpp>
# include <config.h>

# define C2DPOTRF_F77 F77_FUNC_(c2dpotrf, C2DPOTRF)

namespace mat2cpp {
	// Linkage for Fortran version of the Lapack routine dpotrf
	extern "C" fortran_subroutine C2DPOTRF_F77(
		fortran_integer   *c_uplo, 
		fortran_integer   *n, 
		fortran_double    *a, 
		fortran_integer   *lda, 
		fortran_integer   *info
	);
	matrix<double> cholesky
	(const matrix<double> &x, size_t &rank)
	{	assert( x.size1() == x.size2() );
		size_t i, j;

		size_t m = x.size1(); 
		fortran_integer c_uplo = fortran_integer('U'); 
		fortran_double  *a     = new fortran_double  [m * m];
		for(i = 0; i < m; i++)
		{	for(j = 0; j < m; j++)
				a[ i + j * m ] = x(i, j);
		}
		fortran_integer lda  = fortran_integer(m);
		fortran_integer fm   = fortran_integer(m);
		fortran_integer info;
		C2DPOTRF_F77 (&c_uplo, &fm, a, &lda, &info);
	
		assert( info >= 0 );
		if( info == 0 )
			rank = m;
		else	rank = size_t(info - 1);
	
		matrix<double> z(m, m);
		for(i = 0; i < m; i++)
		{	for(j = i; j < m; j++)
				z(i, j) = a[ i + j * m ];
			for(j = 0; j < i; j++)
				z(i, j) = 0.;
		}
		delete [] a;
		return z;
	}

}
/* $$
$end
*/
