//Edited by Ian Martin Ajzenszmidt of Melbourne Australia to include chrono and date and time
#include <boost/numeric/ublas/matrix.hpp>
#include <iomanip>
#include <iostream>
#include <algorithm>
#include <ctime>
#include <chrono>
using namespace boost::numeric::ublas;
using namespace std;

// A custom, more pretty way to print matrices
std::ostream &operator<<(std::ostream &Str, matrix<double> const &v)
{
	for (int i = 0; i < v.size1(); i++)
	{
		Str << ((i == 0) ? "[[" : " [");
		for (int j = 0; j < v.size2(); j++)
		{
			Str << setw(4);
			Str << v(i, j);
			Str << setw(0);
		}
		Str << ((i == v.size1() - 1) ? "]]" : "]");
		if (i != v.size1() - 1)
			Str << endl;
	}
	return Str;
}

int main()
{
        auto start = std::chrono::system_clock::now();
	matrix<double> A(2, 2);
	A(0, 0) = 1;
	A(0, 1) = 2;
	A(1, 0) = 3;
	A(1, 1) = 4;

	matrix<double> B(2, 2);
	B(0, 0) = -1;
	B(0, 1) = 0;
	B(1, 0) = 0;
	B(1, 1) = -1;

	matrix<double> C = prod(A, B);

	cout << "Multiplication of " << endl
		<< A << endl;
	cout << "and " << endl
		<< B << endl;
	cout << "is" << endl;
	cout << C << endl;
   
    // Some computation here
    auto end = std::chrono::system_clock::now();
 
    std::chrono::duration<double> elapsed_seconds = end-start;
    std::time_t end_time = std::chrono::system_clock::to_time_t(end);
 
    std::cout << "finished computation at " << std::ctime(&end_time)
              << "elapsed time: " << elapsed_seconds.count() << "s"
              << std::endl;


	return 0;
}
