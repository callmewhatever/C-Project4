#define _CRT_SECURE_NO_WARNINGS
#include<iostream>

class Complex
{
public:
	Complex(float = 0, float = 0);
	//A default constructor that uses default arguments 
	//in case no initializers are included in the main.

	//>>   <<   +   -   *   ==   !=  overloaded
	friend std::ostream& operator<<(std::ostream&, const Complex&);
	friend std::istream& operator>>(std::istream&, Complex&);
	Complex operator+(Complex&);
	Complex operator-(Complex&);
	Complex operator*(Complex&);
	Complex& operator*=(Complex&);
	const Complex& operator=(const Complex&);
	bool operator==(Complex&);
	bool operator!=(Complex&);
	Complex& operator++();
	Complex operator++(int);
	//overload the preincrement and postincrement operators ++ 
	//which will change the value of the complex number to its cube.
private:
	float real;
	float img;
};

std::ostream& operator<<(std::ostream& os, const Complex& obj)
{
	if (obj.img >= 0)
		os << obj.real << '+' << obj.img << "i.\n";
	else
		os << obj.real << obj.img << "i.\n";
	return os;
}

std::istream& operator>>(std::istream& is, Complex& obj)
{
	is >> obj.real >> obj.img;
	return is;
}

Complex Complex::operator+(Complex& x)
{
	return Complex(real + x.real, img + x.img);
}

Complex Complex::operator-(Complex& x)
{
	return Complex(real - x.real, img - x.img);
}

Complex Complex::operator*(Complex& x)
{
	return Complex((real * x.real - img * x.img), (real * x.img + img * x.real));
}

Complex& Complex::operator*=(Complex& rhs)
{
	*this = *this * rhs;
	return *this;
}

bool Complex::operator==(Complex& x)
{
	return (real == x.real) && (img == x.img);
}

bool Complex::operator!=(Complex& x)
{
	return (real != x.real) || (img != x.img);
}

const Complex& Complex::operator=(const Complex& x)
{
	real = x.real;
	img = x.img;
	return *this;
}

Complex::Complex(float n, float d)
{
	real = n;
	img = d;
}

Complex& Complex::operator++()
{
	Complex temp = *this;
	*this *= temp;
	*this *= temp;
	return *this;
}
Complex Complex::operator++(int)
{
	Complex temp = *this;
	*this *= temp;
	*this *= temp;
	return temp;
}

int main()
{
	Complex x(3.62, 1.25);
	Complex y(0.32, 4.15);
	std::cout << "\nTwo complex number created. The two complex numbers are:\n";
	std::cout << x << y;
	//test overloaded operator +
	Complex z = x + y;
	std::cout << "\nThe sum of those two complex numbers is:\n";
	std::cout << z;
	std::cout << "\nThe difference of those two complex numbers is:\n";
	//test overloaded operator -
	z = x - y;
	std::cout << z;
	std::cout << "\nThe product of those two complex numbers is:\n";
	//test overloaded operator *
	z = x * y;
	std::cout << z;
	//test overloaded operator preincrement ++
	std::cout << "\nAfter preincrement. Those two complex numbers are:\n";
	std::cout << ++x << ++y;
	//test overloaded operator ==
	if (x == y)
	{
		std::cout << "\n+++++those two complex numbers are equal.\n";
	}
	else
	{
		std::cout << "\n+++++those two complex numbers are different.\n";
	}
	Complex a(2.5, 1.5), b;
	b = a;
	std::cout << "\nTwo new complex number created. The two new complex numbers are:\n";
	std::cout << b << a;
	//test overloaded operator !=
	if (a != b)
	{
		std::cout << "\n+++++those two complex numbers are not the same.\n";
	}
	else
	{
		std::cout << "\n+++++those two complex numbers are the same.\n";
	}
	//test overloaded operator postincrement ++
	std::cout << "\nTwo complex numbers before postincrement are:\n" << a++ << b++;
	std::cout << "After postincrement are:\n" << a << b;
	return 0;
}
/*Two complex number created. The two complex numbers are:
3.62+1.25i.
0.32+4.15i.

The sum of those two complex numbers is:
3.94+5.4i.

The difference of those two complex numbers is:
3.3-2.9i.

The product of those two complex numbers is:
-4.0291+15.423i.

After preincrement. Those two complex numbers are:
30.4692+47.1884i.
-16.5008-70.1985i.

+++++those two complex numbers are different.

Two new complex number created. The two new complex numbers are:
2.5+1.5i.
2.5+1.5i.

+++++those two complex numbers are the same.

Two complex numbers before postincrement are:
2.5+1.5i.
2.5+1.5i.
After postincrement are:
-1.25+24.75i.
-1.25+24.75i.

C:\Users\rafon\source\repos\hw4\x64\Debug\hw4.exe (process 9528) exited with code 0.
To automatically close the console when debugging stops, enable Tools->Options->Debugging->Automatically close the console when debugging stops.
Press any key to close this window . . .
*/