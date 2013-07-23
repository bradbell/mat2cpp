# ifndef MAT2CPP_INCLUDED
# define MAT2CPP_INCLUDED
/*
$begin mat2cpp.hpp$$
$spell
	randn
	cpp
	Ublas
	Matlab or Octave
	C++
	hpp
	namespace
	const
	div
	typedef
$$

$index include, mat2cpp.hpp$$

$section The Matlab or Octave to C++ Using Ublas Include File$$

$head Syntax$$
$code # include <mat2cpp.hpp>$$

$head Purpose$$

$head Ublas Linkage$$
The $code mat2cpp.hpp$$ contains 
the following include commands:
$codep
	# include <boost/numeric/ublas/matrix.hpp>
	# include <boost/numeric/ublas/matrix_proxy.hpp>
$$
In addition, it links the following 
$code ublas$$ identifiers to the $code mat2cpp$$ namespace:
$code matrix$$, $code zero_matrix$$, $code scalar_matrix$$,
$code slice$$, $code matrix_slice$$.
It also defines $code matrix_slice_double$$ using
$codep
	typedef matrix_slice< matrix<double> >  matrix_slice_double;
$$

$head mat2cpp Functions$$
The $code mat2cpp.hpp$$ include also
defines linkage for the following 
$code mat2cpp$$ namespace functions:

$table
$code abs$$         $cnext $tref element_unary$$ $rnext
$code log$$         $cnext $tref element_unary$$ $rnext
$code diag_prod$$   $cnext $tref diag_prod$$     $rnext
$code matrix_div$$  $cnext $tref matrix_div$$    $rnext
$code max$$         $cnext $tref max$$           $rnext
$code min$$         $cnext $tref min$$           $rnext
$code scalar$$      $cnext $tref scalar$$        $rnext
$code sum$$         $cnext $tref sum$$           $rnext
$code rand$$        $cnext $tref rand$$          $rnext
$code randn$$       $cnext $tref randn$$         $rnext
$tend

$subhead Fortran Linkage$$
The $code mat2cpp.hpp$$ include also
defines the following types:
$table
$code fortran_integer$$ $cnext 
	the type in C++ corresponding to Fortran integer $rnext
$code fortran_double$$ $cnext 
	the type in C++ corresponding to Fortran double precision $rnext
$code fortran_subroutine$$ $cnext 
	the return type in C++ corresponding to Fortran subroutine 
$tend


$end
*/

# include <boost/numeric/ublas/matrix.hpp>
# include <boost/numeric/ublas/matrix_proxy.hpp>
namespace mat2cpp 
{	// linking certain identifiers from ublas ----------
	using boost::numeric::ublas::matrix;
	using boost::numeric::ublas::scalar_matrix;
	using boost::numeric::ublas::zero_matrix;
	using boost::numeric::ublas::slice;
	using boost::numeric::ublas::matrix_slice;

	// define the matrix_slice_double type
	typedef matrix_slice< matrix<double> >  matrix_slice_double;
	// -------------------------------------------------

	// element_unary functions -------------------------
	extern matrix<double> abs (const matrix<double> &x);
	extern matrix<double> log (const matrix<double> &x);
	// -------------------------------------------------

	extern matrix<double> cholesky
	(const matrix<double> &x, size_t &rank);

	extern matrix<double> diag_prod
	(const matrix<double> &x, const matrix<double> &y);

	extern matrix<double> matrix_div
	(const matrix<double> &x, const matrix<double> &y, size_t &rank);

	extern double max
	(const matrix<double> &x);

	extern double min
	(const matrix<double> &x);

	extern double scalar
	(const matrix<double> &x);

	extern double sum
	(const matrix<double> &x);

	extern matrix<double> rand
	(size_t m, size_t n);

	extern matrix<double> randn
	(size_t m, size_t n);

	// fortran linkage types -------------
	typedef int       fortran_integer;
	typedef double    fortran_double;
	typedef void      fortran_subroutine;
	// -----------------------------------
}

# endif
