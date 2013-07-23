dnl     package,          version,  bugreport
AC_INIT(mat2cpp, 20130721, bradbell@apl.washington.edu)

dnl The directory corresponding to the installation of BOOST ------------
AC_MSG_CHECKING( [BOOST_DIR] )
AC_SUBST(BOOST_DIR)
if test "$BOOST_DIR" != "" ; then
	AC_MSG_RESULT( [ BOOST_DIR=$BOOST_DIR ] )
else
	AC_MSG_ERROR( [ BOOST_DIR=$BOOST_DIR ] )
fi

dnl The C++ error and warning flags for every compliation ---------------
AC_MSG_CHECKING( [COMPILE_FLAGS] )
AC_SUBST(COMPILE_FLAGS)
AM_CONDITIONAL(mat2cpp_COMPILE_FLAGS, test "$COMPILE_FLAGS" != "" )
if test "$COMPILE_FLAGS" != "" ; then
	AC_MSG_RESULT( [COMPILE_FLAGS=$COMPILE_FLAGS] ) 
else
	AC_MSG_RESULT( [no] )
fi 

dnl Run any macros required for proper operation of generated Makefiles
dnl nostdinc: Do not define standard include directories in generated Makefiles
AM_INIT_AUTOMAKE(nostdinc)

dnl Use config.h instead of make file command line arguments
AM_CONFIG_HEADER( config.h )

dnl AC_PROG_CXX([compiler-search-list]) outputs CXX as C++ compiler to use
AC_PROG_CXX

dnl No default setting for compiler flags
AC_SUBST(CXXFLAGS, "")

dnl AC_PROG_F77([compiler-search-list]) outputs F77 as Fortran compiler to use
AC_PROG_F77
dnl Macros for linking fortran to C
AC_F77_WRAPPERS

dnl Determine if ranlib is present and where it is if present (set RANLIB)
AC_PROG_RANLIB

dnl Have configure check distribution directory 
AC_CONFIG_SRCDIR([mat2cpp.omh])

dnl AC_CONFIG_FILES(file-list) for each file in the list, configure will 
dnl read file.in, do its substitutions, and create file
AC_CONFIG_FILES([ 
	Makefile
	lib/Makefile
	cpp/Makefile
])

dnl create all the requested output files
AC_OUTPUT
