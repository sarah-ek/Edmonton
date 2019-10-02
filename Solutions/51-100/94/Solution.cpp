#include <boost/multiprecision/cpp_int.hpp>
#include <iostream>

using namespace std;
using boost::multiprecision::cpp_int;

int main(int argc, char *argv[]) {
	cpp_int zero, side, sum, perimeter, m;
	zero = 1;
	side = 1;
	perimeter = 0;
	sum = 0;
	m = 1;
	while(perimeter <= 1'000'000'000) {
		zero = side;
		side = ((4 * side) - zero + (2 * m));
		m = (-1) * m;
		sum += perimeter;
		perimeter = (3 * side) - m;
	}
	cout << sum << endl;
	return 0;
}