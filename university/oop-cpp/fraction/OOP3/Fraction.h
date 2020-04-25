#pragma once
#include <iostream>
using namespace std;

class Fraction
{
	friend Fraction operator+(const Fraction&, const Fraction&);
	friend Fraction operator+(const Fraction&, int);
	friend Fraction operator+(int, const Fraction&);
	friend Fraction operator+(const Fraction&, double);
	friend Fraction operator+(double, const Fraction&);

	friend Fraction operator-(const Fraction&, const Fraction&);
	friend Fraction operator-(const Fraction&, int);
	friend Fraction operator-(int, const Fraction&);
	friend Fraction operator-(const Fraction&, double);
	friend Fraction operator-(double, const Fraction&);

	friend Fraction operator*(const Fraction&, const Fraction&);
	friend Fraction operator*(const Fraction&, int);
	friend Fraction operator*(int, const Fraction&);
	friend Fraction operator*(const Fraction&, double);
	friend Fraction operator*(double, const Fraction&);

	friend Fraction operator/(const Fraction&, const Fraction&);
	friend Fraction operator/(const Fraction&, int);
	friend Fraction operator/(int, const Fraction&);
	friend Fraction operator/(const Fraction&, double);
	friend Fraction operator/(double, const Fraction&);

	friend bool operator==(const Fraction&, const Fraction&);
	friend bool operator!=(const Fraction&, const Fraction&);
	friend bool operator>(const Fraction&, const Fraction&);
	friend bool operator<(const Fraction&, const Fraction&);
	friend bool operator>=(const Fraction&, const Fraction&);
	friend bool operator<=(const Fraction&, const Fraction&);

	friend ostream& operator<<(ostream&, const Fraction&);
	friend istream& operator>>(istream&, Fraction&);

private:
	int numenator;
	unsigned int denominator;

public:
	Fraction(int numenator = 1, int denominator = 1);
	static Fraction FromInt(int);
	static Fraction FromDouble(double);

	// ���������� ���������.
	inline int GetNumenator();
	// ���������� �����������.
	inline int GetDenominator();

	// �������� �����.
	void Print();

	// ��������� �����.
	friend Fraction Reduce(const Fraction&);

	void operator=(const Fraction&);
	void operator=(int);
	void operator=(double);

	operator double();
	operator float();
};

// ���������� ���������� ����� ��������.
int NOD(unsigned int, unsigned int);
// ���������� ���������� ����� �������.
int NOK(unsigned int, unsigned int);