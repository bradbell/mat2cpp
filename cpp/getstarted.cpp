# include <mat2cpp.hpp>
# include <boost/numeric/ublas/io.hpp>
int main(void)
{	using namespace mat2cpp;

	double a_data[] = {1., 2., 3., 4.};
	double b_data[] = {1., 2.};
	matrix<double> a(2, 2);
	matrix<double> b(2, 1);
	size_t i, j;
	for(i = 0; i < 2; i++)
	{	b(i, 0) = b_data[i];
		for(j = 0; j < 2; j++)
			a(i, j) = a_data[i * 2 + j];
	}	
	size_t rank;
	matrix<double> x = matrix_div(a, b, rank);
	std::cout << "x =" << x << std::endl;

	return 0;
}


