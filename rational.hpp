#pragma once


	class Rational
	{
		
	public:
		//Constructors
		Rational();
		Rational(int n, int d);

		//Binary operators
		Rational operator + (Rational const& rhs) const;
		Rational operator - (Rational const& rhs) const;
		Rational operator * (Rational const& rhs) const;
		Rational operator / (Rational const& rhs) const;

		void operator += (Rational const& src);
		void operator -= (Rational const& src);
		void operator *= (Rational const& src);
		void operator /= (Rational const& src);

		Rational operator ++();
		Rational operator --();

		Rational operator ++(int);
		Rational operator --(int);

		//Unary operators
		Rational operator -() const;

		//Comparison operators
		bool operator > (Rational const& rhs) const;
		bool operator < (Rational const& rhs) const;
		bool operator >= (Rational const& rhs) const;
		bool operator <= (Rational const& rhs) const;
		bool operator != (Rational const& rhs) const;
		bool operator == (Rational const& rhs) const;

		//IO operators

		//std::ostream& operator <<(std::ostream& out, Rational const& r);
		//friend std::ostream& operator <<(std::ostream& out, Rational const& r);
		//friend std::istream& operator >> (std::istream& in, Rational& r);

		//Getters
		int den();
		int num();

		//Setters
		void den(int d);
		void num(int n);

		//Conversions
		static double doubleBase;
		operator double() const;
		operator int() const;
		Rational(double d);
		Rational(int i);

	private:
		int GCF(int first, int second);
		void reduce();
		int numerator, denominator;
		
	};
