#ifndef _H_
#define _H_

#include <iostream>
class drib
{
private:
	//fields of integer, numerator, denumerator
	int c, n, dn;
public:
	_declspec(dllexport) drib(); // default constructor
	_declspec(dllexport) drib(int, int); // constructor with numerator and denumerator
	_declspec(dllexport) drib(int, int, int); // constructor with integer, numerator and denumerator
	_declspec(dllexport) drib(double); // constructor (converts double to drib)

	//operation with two dribs
	_declspec(dllexport) drib operator+(const drib&) const;
	_declspec(dllexport) drib operator-(const drib&) const;
	_declspec(dllexport) drib operator*(const drib&) const;
	_declspec(dllexport) drib operator/(const drib&) const;

	//operations with integer and dribs
	_declspec(dllexport) friend drib operator+(int, const drib&);
	_declspec(dllexport) friend drib operator-(int, const drib&);
	_declspec(dllexport) friend drib operator*(int, const drib&);
	_declspec(dllexport) friend drib operator/(int, const drib&);

	//operations for dribs and integer
	_declspec(dllexport) friend drib operator+(const drib&, int);
	_declspec(dllexport) friend drib operator-(const drib&, int);
	_declspec(dllexport) friend drib operator*(const drib&, int);
	_declspec(dllexport) friend drib operator/(const drib&, int);

	//operations for double and dribs
	_declspec(dllexport) friend drib operator+(double, const drib&);
	_declspec(dllexport) friend drib operator-(double, const drib&);
	_declspec(dllexport) friend drib operator*(double, const drib&);
	_declspec(dllexport) friend drib operator/(double, const drib&);

	//operations for dribs and double
	_declspec(dllexport) friend drib operator+(const drib&, double);
	_declspec(dllexport) friend drib operator-(const drib&, double);
	_declspec(dllexport) friend drib operator*(const drib&, double);
	_declspec(dllexport) friend drib operator/(const drib&, double);

	//shorting drib
	_declspec(dllexport) void shorting();
	//divide numerator in denumerator
	_declspec(dllexport) double Result();

	//making drib right
	_declspec(dllexport) void toRight();
	//making drib unright
	_declspec(dllexport) void toUnright();

	//for getting fields
	_declspec(dllexport) int getC();
	_declspec(dllexport) void setC(int);
	_declspec(dllexport) int getN();
	_declspec(dllexport) void setN(int);
	_declspec(dllexport) int getDn();
	_declspec(dllexport) void setDn(int);

	//display in stream
	_declspec(dllexport) friend std::ostream& operator<<(std::ostream&, const drib &);

	//default destructor
	_declspec(dllexport) ~drib();
};

#endif
