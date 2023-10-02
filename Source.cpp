#include "rational.hpp"
#include <iostream>


int main()
{
	// Initialize test cases
	Rational a(1, 2);
	Rational b;
	b.num(1);
	b.den(4);
	Rational c;

	// Perform operations and output the results
	a += b;
	std::cout << a.num() << " " << a.den() << std::endl;

	a -= b;
	std::cout << a.num() << " " << a.den() << std::endl;

	a /= (b - b);
	std::cout << a.num() << " " << a.den() << std::endl;

	a++;
	std::cout << a.num() << " " << a.den() << std::endl;

	a--;
	std::cout << a.num() << " " << a.den() << std::endl;	

	a = -a;
	std::cout << a.num() << " " << a.den() << std::endl;

	double d = b;	
	std::cout << d << std::endl;

	b = d;
	std::cout << a.num() << " " << a.den() << std::endl;
}