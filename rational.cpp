#include "rational.hpp"
#include <stdexcept>
#include <iostream>
#include<cmath>
using std::ostream;

// Default constructor
Rational::Rational()
{
	numerator = 0;
	denominator = 1;
}

// Value constructor
Rational::Rational(int n, int d)
{
	if (d < 0)
	{ 
		d = abs(d);
		n = -n;
	}

	numerator = n;
	denominator = d;
	reduce();

	try
	{
		numerator = n;
		denominator = d;
		if (denominator == 0)
		{
			throw std::domain_error{ "Invalid input. The denominator must be a non-zero number.\n" };
		}
			
	}
	catch (std::domain_error& e)
	{
		std::cout << e.what();
	}
}

//Binary operators
Rational Rational::operator + (Rational const &rhs) const
{

	Rational a, b;
	
	//Get common denominator
	a.numerator = numerator * rhs.denominator;
	a.denominator = denominator * rhs.denominator;
	b.numerator = rhs.numerator * denominator;
	b.denominator = rhs.denominator * denominator;

	//Add numerators after getting common denominator
	a.numerator += b.numerator;
	a.reduce();
	return a;
}

//Unary operators
Rational Rational::operator -() const
{
	Rational a;
	a.numerator = this->numerator;
	a.denominator = this->denominator;
	a.numerator = -a.numerator;
	
	return a;
}

Rational Rational::operator - (Rational const& rhs) const
{
	Rational a, b;

	//Get common denominator
	a.numerator = numerator * rhs.denominator;
	a.denominator = denominator * rhs.denominator;
	b.numerator = rhs.numerator * denominator;
	b.denominator = rhs.denominator * denominator;

	//subtract numerators after getting common denominator
	a.numerator -= b.numerator;
	a.reduce();
	return a;
}

Rational Rational::operator * (Rational const& rhs) const
{
	Rational a, b;

	//Set a and b to correct values
	a.numerator = numerator;
	a.denominator = denominator;
	b.numerator = rhs.numerator;
	b.denominator = rhs.denominator;

	//multiply numerators
	a.numerator *= b.numerator;
	a.denominator *= b.denominator;
	a.reduce();
	return a;
}

Rational Rational::operator / (Rational const& rhs) const
{
	Rational a, b, current;

	current.numerator = numerator;
	current.denominator = denominator;

	//Set a and b to correct values
	a.numerator = numerator;
	a.denominator = denominator;
	b.numerator = rhs.numerator;
	b.denominator = rhs.denominator;

	//multiply a's num by b's den and a's den by b's num
	a.numerator *= b.denominator;
	a.denominator *= b.numerator;

	try
	{
		if (a.denominator == 0)
		{
			throw std::domain_error{ "Invalid input. The denominator must be a non-zero number.\n" };
		}
	}
	catch (std::domain_error& e)
	{
		std::cout << e.what();
		a.denominator = current.denominator;
		a.numerator = current.numerator;
	}
	a.reduce();
	
	return a;
}

//Assignment operators
void Rational::operator += (Rational const& src)
{
	//Declare a temporary variable
	Rational b;

	//Set this and b to correct values
	b.numerator = src.numerator * this->denominator;
	b.denominator = src.denominator * this->denominator;
	this->numerator *= src.denominator;
	this->denominator *= src.denominator;

	// add b to this
	this->numerator += b.numerator;
	
	this->reduce();
}

void Rational::operator -= (Rational const& src)
{
	Rational b;

	//Set this and b to correct values
	b.numerator = src.numerator * this->denominator;
	b.denominator = src.denominator * this->denominator;
	this->numerator *= src.denominator;
	this->denominator *= src.denominator;

	// subract b from this
	this->numerator -= b.numerator;

	this->reduce();
}

void Rational::operator *= (Rational const& src)
{
	//multiply this by src
	this->numerator *= src.numerator;
	this->denominator *= src.denominator;
	this->reduce();
}

void Rational::operator /= (Rational const& src)
{
	Rational current;

	current.numerator = this->numerator;
	current.denominator = this->denominator;

	//multiply a's num by b's den and a's den by b's num
	this->numerator *= src.denominator;
	this->denominator *= src.numerator;

	try
	{
		if (this->denominator == 0)
		{
			throw std::domain_error{ "Invalid input. The denominator must be a non-zero number.\n" };
		}

	}
	catch (std::domain_error& e)
	{
		std::cout << e.what();
		this->denominator = current.denominator;
		this->numerator = current.numerator;
	}
	this->reduce();
}

//Prefix operators
Rational Rational::operator++()
{
	this->numerator += this->denominator;
	return *this;
}

Rational Rational::operator --()
{
	this->numerator -= this->denominator;
	return *this;
}

//Postfix operators
Rational Rational::operator ++(int)
{
	Rational a;
	a.numerator = this->numerator;
	a.denominator = this->denominator;
	a.numerator += a.denominator;
	return a;
}

Rational Rational::operator --(int)
{
	Rational a;
	a.numerator = this->numerator;
	a.denominator = this->denominator;
	a.numerator -= a.denominator;
	return a;
}

//Comparison operators
bool Rational::operator > (Rational const& rhs) const
{
	Rational a;
	Rational b;

	//Set this and b to correct values
	b.numerator = rhs.numerator * this->denominator;
	b.denominator = rhs.denominator * this->denominator;
	a.numerator = this->numerator * rhs.denominator;
	a.denominator = this->denominator * rhs.denominator;

	//Compare a and b and return true or false
	return (a.numerator > b.numerator);
}

bool Rational::operator < (Rational const& rhs) const
{
	Rational a;
	Rational b;

	//Set this and b to correct values
	b.numerator = rhs.numerator * this->denominator;
	b.denominator = rhs.denominator * this->denominator;
	a.numerator = this->numerator * rhs.denominator;
	a.denominator = this->denominator * rhs.denominator;

	//Compare a and b and return true or false
	return (a.numerator < b.numerator);
}

bool Rational::operator <= (Rational const& rhs) const
{
	Rational a;
	Rational b;

	//Set this and b to correct values
	b.numerator = rhs.numerator * this->denominator;
	b.denominator = rhs.denominator * this->denominator;
	a.numerator = this->numerator * rhs.denominator;
	a.denominator = this->denominator * rhs.denominator;

	//Compare a and b and return true or false
	return (a.numerator <= b.numerator);
}

bool Rational::operator >= (Rational const& rhs) const
{
	Rational a;
	Rational b;

	//Set this and b to correct values
	b.numerator = rhs.numerator * this->denominator;
	b.denominator = rhs.denominator * this->denominator;
	a.numerator = this->numerator * rhs.denominator;
	a.denominator = this->denominator * rhs.denominator;

	//Compare a and b and return true or false
	return (a.numerator >= b.numerator);
}

bool Rational::operator != (Rational const& rhs) const
{
	Rational a;
	Rational b;

	//Set this and b to correct values
	b.numerator = rhs.numerator * this->denominator;
	b.denominator = rhs.denominator * this->denominator;
	a.numerator = this->numerator * rhs.denominator;
	a.denominator = this->denominator * rhs.denominator;

	//Compare a and b and return true or false
	return (a.numerator != b.numerator);
}

bool Rational::operator == (Rational const& rhs) const
{
	Rational a;
	Rational b;

	//Set this and b to correct values
	b.numerator = rhs.numerator * this->denominator;
	b.denominator = rhs.denominator * this->denominator;
	a.numerator = this->numerator * rhs.denominator;
	a.denominator = this->denominator * rhs.denominator;

	//Compare a and b and return true or false
	return (a.numerator == b.numerator);
}

//Find the greatest common factor and return
int Rational::GCF(int a, int b)
{
	if (a % b == 0)
		return b;

	else
	{
		GCF(b, a % b);
	}
}

//Reduce the rational
void Rational::reduce()
{
	int gcf = GCF(this->numerator, this->denominator);
	this->numerator /= gcf;
	this->denominator /= gcf;

	if (denominator < 0)
	{
		denominator = abs(denominator);
		numerator = -numerator;
	}
}

//Getters
int Rational::den()
{
	return denominator;
}

int Rational::num()
{
	return numerator;
}

//Setters
void Rational::den(int d)
{
	if (d < 0)
	{
		denominator = abs(d);
		numerator = -numerator;
	}
	else
	{
		numerator = abs(numerator);
	}

	int current = denominator;
	try
	{		
		
		
		denominator = d;
		if (denominator == 0)
		{
			throw std::domain_error{ "Invalid input. The denominator must be a non-zero number.\n" };			
		}
	}
	catch (std::domain_error& e)
	{
		std::cout << e.what();
		denominator = current;
	}

	reduce();
}


void Rational::num(int n)
{
	numerator = n;
	if (numerator == 0)
		denominator = 1;
	reduce();
}

//Conversions
double Rational::doubleBase = 1000000;

Rational::Rational(double d)
{
	numerator = doubleBase * d;
	denominator = doubleBase;
	reduce();
}

Rational::Rational(int i)
{
	numerator = i;
	denominator = 1;
}

Rational::operator double() const
{
	double d = this->denominator;
	double n = this->numerator;
	double ret = n / d;

	return ret;
}

Rational::operator int() const
{
	int i;
	i = (this->numerator / this->denominator);

	return i;
}

//IO operators

std::ostream& operator <<(std::ostream& out, Rational const& r) 
{
	Rational a = r;
	int n = a.num();
	int d = a.den();
	
	return out << n << '/' << d;
}

std::istream& operator >> (std::istream& in, Rational& r)
{
	int n, d;
	in >> n >> d;
	Rational{ n, d };

	return in;
}

