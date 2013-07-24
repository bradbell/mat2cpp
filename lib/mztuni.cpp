/*
-----------------------------------------------------------------------------
$begin mztuni.cpp$$
$spell
	ctime
	std
	hpp
	ptr
	seedm1
	stmp
	Marsaglia
	Zaman
	Tsang
	cstddef
	cassert
	cm
	ip
	jp
	jj
	uni
	mztuni
$$

$section C++ Marsaglia Zaman Tsang Uniform Random Number Source Code$$

$codep
*/
# include <cstddef>    // for size_t
# include <cassert>    // for assert
# include <ctime>      // for std::time and std::time_t
# include <mztuni.hpp> // routines implemented here
//
size_t mztuni_seed(size_t seed)
{	static size_t previous_seed = 0;
	if( seed == 0 )
		return previous_seed;
	//
	if( seed == 1 )
	{	// initialize the random number generator using the clock for a seed
		std::time_t* null_ptr = 0;
		std::time_t seconds   = std::time(null_ptr);
		seed                  = static_cast<size_t>( seconds );
		seed                  = seed % 796594175 + 3;
	}
	mztuni(seed - 1);
	previous_seed = seed;
	//
	return previous_seed;
}
double mztuni(size_t seedm1)
{	assert( seedm1 <= 796594176 );

	// define local mod function
	class mod_class {
	public:
		size_t operator()(size_t i, size_t j)
		{	return i % j; }
	};
	mod_class mod;
	//
	// static data that persists between function calls
	static double u[98], c, cd, cm;
	static size_t ip, jp;
	//
	if( seedm1 > 0 )
	{	size_t i, j, k, l, m;
		size_t stmp = seedm1;
		i    = mod(stmp, 168);
		stmp = stmp / 168;
		j    = mod(stmp, 168) + 1;
		stmp = stmp / 168;
		k    = mod(stmp, 168) + 1;
		stmp = stmp / 168;
		l    = mod(stmp, 168) + 1;
		assert( i != 1 || j != 1 || k != 1 || l != 1 );
		for(size_t ii = 1; ii <=97; ii++)
		{	double s = 0.0;
			double t = 0.5;
			for(size_t jj = 1; jj <= 24; jj++)
			{	m = mod( mod(i * j, 179) * k, 179 );
				i = j;
				j = k;
				k = m;
				l = mod(53 * l + 1, 169);
				if( mod(l * m, 64) >= 32) 
					s = s + t;
				t = 0.5 * t;
			}
		     u[ii] = s;
		}
		// There is a typo in the paper, where the fortran version has
		// CD =  7654321. / 167777216.;
		c  =   362436. / 16777216.;
		cd =  7654321. / 16777216.;
		cm = 16777213. / 16777216.;
		ip = 97;
		jp = 33;
		//
		return 0.0;
	}
	double uni = u[ip] - u[jp];
	if(uni < 0.0)
		uni = uni +  1.0;
	u[ip] = uni;
	//
	ip = ip - 1;
	if(ip == 0)
		ip = 97;
	//
	jp = jp - 1;
	if(jp == 0)
		jp = 97;
	//
	c = c - cd;
	if(c < 0.0)
		c = c + cm;
	//
	uni = uni - c;
	if(uni < 0.0)
		uni = uni + 1.0;
	return uni;
}
/* $$
$end
*/
