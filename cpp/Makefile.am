#
AM_CPPFLAGS         = \
	-I$(top_srcdir) \
	-I$(BOOST_DIR) \
	$(COMPILE_FLAGS)
#
AM_CXXFLAGS         = \
	$(COMPILE_FLAGS)
LDADD               = ../lib/libmat2cpp.a -llapack 
#
noinst_PROGRAMS     = mat2cpp_ok getstarted
getstarted_SOURCES  = getstarted.cpp
mat2cpp_ok_SOURCES  = \
	add_ok.cpp \
	cholesky_ok.cpp \
	diag_prod_ok.cpp \
	element_div_ok.cpp \
	element_prod_ok.cpp \
	element_unary_ok.cpp \
	extend_ok.cpp \
	mat2cpp_ok.cpp \
	matrix_div_ok.cpp \
	matrix_prod_ok.cpp \
	max_ok.cpp \
	min_ok.cpp \
	ones_ok.cpp \
	rand_ok.cpp \
	randn_ok.cpp \
	scalar_ok.cpp \
	scalar_div_ok.cpp \
	scalar_prod_ok.cpp \
	size_ok.cpp \
	slice_ok.cpp \
	sub_ok.cpp \
	sum_ok.cpp \
	transpose_ok.cpp \
	zeros_ok.cpp 
#
noinst_DATA = getstarted.out
getstarted.out : getstarted$(EXEEXT)
	./getstarted > getstarted.out
