/*
$begin mztuni_ok.cpp$$
$spell
	mztuni
$$

$section mztuni: Example and Test$$

$code
$verbatim%cpp/mztuni_ok.cpp%0%// BEGIN C++%// END C++%1%$$
$$

$end
*/
// BEGIN C++
# include <cstddef>
# include <mztuni.hpp>

bool mztuni_ok(void)
{	bool   ok  = true;
	//
	// seed used to create Table 4 in the article 
	size_t i = 12;
	size_t j = 34;
	size_t k = 56;
	size_t l = 78;
	//
	// seed in format expected by mztuni
	size_t seed = 0;
	seed        = 168 * seed + l - 1;
	seed        = 168 * seed + k - 1;
	seed        = 168 * seed + j - 1;
	seed        = 168 * seed + i + 1; // note + 1 (not - 1)
	//
	// seed the random number generator
	mztuni_seed(seed);
	//
	// skip first 20,000 simulations
	for(size_t ii = 1; ii <= 20000; ii++)
		mztuni();
	//
	// check the next 5 simulations using values in Table 4 of reference
	size_t table_4[] = {
	 6,  3, 11,  3,  0,  4,  0,
	13,  8, 15, 11, 11, 14,  0,
	 6, 15,  0,  2,  3, 11,  0,
	 5, 14,  2, 14,  4,  8,  0,
	 7, 15,  7, 10, 12,  2,  0
	};
	for(size_t ii = 0; ii < 5; ii++)
	{	double x      = mztuni(0);
		size_t factor = 1;
		for(size_t m = 0; m < 7; m++)
		{	factor *= 16;
			size_t value = static_cast<size_t>( x * factor ) % 16;
			size_t check = table_4[ii * 7 + m];
			ok  &= value == check;
		}
	}
	// check seed value
	ok &= mztuni_seed(0) == seed;
	//
	return ok;
}
// END C++
