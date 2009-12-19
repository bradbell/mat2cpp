/*
$begin mat2cpp_ok.cpp$$ 
$spell
	const
	randn
	cholesky
	cstdlib
	srand
	div
	bool
	cout
	endl
	iostream
	std
	C++
$$

$section Run C++ Version of Examples$$

$codep */
# include <iostream>
# include <cstdlib>

extern bool add_ok(void);
extern bool cholesky_ok(void);
extern bool diag_prod_ok(void);
extern bool element_div_ok(void);
extern bool element_prod_ok(void);
extern bool element_unary_ok(void);
extern bool extend_ok(void);
extern bool matrix_div_ok(void);
extern bool matrix_prod_ok(void);
extern bool max_ok(void);
extern bool min_ok(void);
extern bool ones_ok(void);
extern bool rand_ok(void);
extern bool randn_ok(void);
extern bool scalar_ok(void);
extern bool scalar_div_ok(void);
extern bool scalar_prod_ok(void);
extern bool size_ok(void);
extern bool slice_ok(void);
extern bool sub_ok(void);
extern bool sum_ok(void);
extern bool transpose_ok(void);
extern bool zeros_ok(void);

bool run_test(bool test(void), const char *name)
{	bool ok = test();
	if( ok )
		std::cout << "ok:    " << name << std::endl;
	else	std::cout << "error: " << name << std::endl;
	return ok;
}
int main()
{	bool ok   = true;
	
	// initialize the random number generator
	unsigned seed = 5;
	std::srand(seed);

	// run all the tests
	ok   = ok & run_test(add_ok, "add_ok");
	ok   = ok & run_test(cholesky_ok, "cholesky_ok");
	ok   = ok & run_test(diag_prod_ok, "diag_prod_ok");
	ok   = ok & run_test(element_div_ok, "element_div_ok");
	ok   = ok & run_test(element_prod_ok, "element_prod_ok");
	ok   = ok & run_test(element_unary_ok, "element_unary_ok");
	ok   = ok & run_test(extend_ok, "extend_ok");
	ok   = ok & run_test(matrix_div_ok, "matrix_div_ok");
	ok   = ok & run_test(matrix_prod_ok, "matrix_prod_ok");
	ok   = ok & run_test(max_ok, "max_ok");
	ok   = ok & run_test(min_ok, "min_ok");
	ok   = ok & run_test(ones_ok, "ones_ok");
	ok   = ok & run_test(rand_ok, "rand_ok");
	ok   = ok & run_test(randn_ok,"randn_ok");
	ok   = ok & run_test(scalar_ok, "scalar_ok");
	ok   = ok & run_test(scalar_div_ok, "scalar_div_ok");
	ok   = ok & run_test(scalar_prod_ok, "scalar_prod_ok");
	ok   = ok & run_test(size_ok, "size_ok");
	ok   = ok & run_test(slice_ok, "slice_ok");
	ok   = ok & run_test(sub_ok, "sub_ok");
	ok   = ok & run_test(sum_ok, "sum_ok");
	ok   = ok & run_test(transpose_ok, "transpose_ok");
	ok   = ok & run_test(zeros_ok, "zeros_ok");
	std::cout << std::endl;
	if( ok )
		std::cout << "All tests passed" << std::endl;
	else	std::cout << "At least one test failed" << std::endl;
	int error = ! ok;
	return error;
}
/*  $$

$end
*/
