//realizations
#include "drib.h"

drib::drib()
{
	n = dn = 1;
	c = 0;
}
drib::drib(int a, int b)
{
	n = a; dn = b; c = 0;
}
drib::drib(int z, int a, int b) : drib(a, b)
{
	c = z;
}
drib::drib(double b)
{
	int zn = 1;
	while (int(b) != b)
	{
		zn *= 10;
		b *= 10;
	}
	c = 0; n = b; dn = zn;
}

drib drib::operator+(const drib &d) const
{
	drib *b1 = new drib(c, n, dn);
	drib *b2 = new drib(d.c, d.n, d.dn);
	drib result;
	if (b1->c == 0 && b2->c == 0)
	{
		result.n = b1->n * b2->dn + b2->n*b1->dn;
		result.dn = b1->dn * b2->dn;
	}
	else
	{
		b1->toUnright();
		b2->toUnright();
		result.n = b1->n * b2->dn + b2->n*b1->dn;
		result.dn = b1->dn * b2->dn;
	}
	delete b1;
	delete b2;
	return result;
}
drib drib::operator-(const drib &d) const
{
	drib *b1 = new drib(c, n, dn);
	drib *b2 = new drib(d.c, d.n, d.dn);
	drib result;
	if (b1->c == 0 && b2->c == 0)
	{
		result.n = b1->n * b2->dn - b2->n*b1->dn;
		result.dn = b1->dn * b2->dn;
	}
	else
	{
		b1->toUnright();
		b2->toUnright();
		result.n = b1->n * b2->dn - b2->n*b1->dn;
		result.dn = b1->dn * b2->dn;
	}
	delete b1;
	delete b2;
	return result;
}
drib drib::operator*(const drib &d) const
{
	drib *b1 = new drib(c, n, dn);
	drib *b2 = new drib(d.c, d.n, d.dn);
	drib result;
	if (b1->c == 0 && b2->c == 0)
	{
		result.n = b1->n * b2->n;
		result.dn = b1->dn * b2->dn;
	}
	else
	{
		b1->toUnright();
		b2->toUnright();
		result.n = b1->n * b2->n;
		result.dn = b1->dn * b2->dn;
	}
	delete b1;
	delete b2;
	return result;
}
drib drib::operator/(const drib &d) const
{
	drib *b1 = new drib(c, n, dn);
	drib *b2 = new drib(d.c, d.n, d.dn);
	drib result;
	if (b1->c == 0 && b2->c == 0)
	{
		result.n = b1->n * b2->dn;
		result.dn = b1->dn * b2->n;
	}
	else
	{
		b1->toUnright();
		b2->toUnright();
		result.n = b1->n * b2->dn;
		result.dn = b1->dn * b2->n;
	}
	delete b1;
	delete b2;
	return result;
}

void drib::shorting()
{
	for (int i = 1; i <= n; i++)
	{
		if (n%i == 0 && dn%i == 0) 
		{
			n /= i;
			dn /= i;
			i = 1;
		}
	}
}
void drib::toRight()
{
	if (n < dn) return;
	else
	{
		/*c += n / dn;
		n = n - c * dn;*/
		int tmp = 0;
		tmp += n / dn;
		n = n - tmp * dn;
		c += tmp;
	}
}
void drib::toUnright()
{
	if (n > dn) return;
	else
	{
		n += c * dn;
		c = 0;
	}
}

//get - set for variables in drib
int drib::getC(){return c;}
void drib::setC(int q){c = q;}
int drib::getN() { return n; }
void drib::setN(int q) { n = q; }
int drib::getDn() { return dn; }
void drib::setDn(int q) { dn = q; }

double drib::Result()
{
	drib *b = this;
	return double(b->n) / double(b->dn);
	delete b;
}

drib operator+(int i, const drib &d)
{
	return drib(d.c + i, d.n, d.dn);
}
drib operator-(int i, const drib &d)
{
	if (d.c >= i) return drib(d.c - i, d.n, d.dn);
	else
	{
		return drib(i, 1) - d;
	}
}
drib operator*(int i, const drib &d)
{
	return drib(d.c*i, d.n*i, d.dn);
}
drib operator/(int i, const drib &d)
{
	return drib(1, i)*d;
}

drib operator+(const drib &d, int i)
{
	return i + d;
}
drib operator-(const drib &d, int i)
{
	return d - drib(i, 1);
}
drib operator*(const drib &d, int i)
{
	return i*d;
}
drib operator/(const drib &d, int i)
{
	return d / drib(i, 1);
}

drib operator+(double i, const drib &d)
{
	return drib(i) + d;
}
drib operator-(double i, const drib &d)
{
	return drib(i) - d;
}
drib operator*(double i, const drib &d)
{
	return drib(i) * d;
}
drib operator/(double i, const drib &d)
{
	return drib(i) / d;
}

drib operator+(const drib& d, double i)
{
	return d + drib(i);
}
drib operator-(const drib& d, double i)
{
	return d - drib(i);
}
drib operator*(const drib& d, double i)
{
	return d * drib(i);
}
drib operator/(const drib& d, double i)
{
	return d / drib(i);
}

std::ostream & operator<<(std::ostream &os, const drib &d)
{
	if (d.dn == 1 && d.c == 0) os << d.n; 
	else if (d.c != 0) os << d.c << " " << d.n << "/" << d.dn;
	else if (d.n == 0) os << 0;
	else os << d.n << "/" << d.dn;
	return os;
}

drib::~drib()
{
}