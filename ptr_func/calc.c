#include "../head.h"

double Add(double a, double b);
double Sub(double a, double b);
double Mul(double a, double b);
double Div(double a, double b);

double (*func[])(double, double) = {Add, Sub, Mul, Div};

enum op{
	ADD = 0,
	SUB,
	MUL,
	DIV
};

double Add(double a, double b)
{
	return a+b;
}

double Sub(double a, double b)
{
	return a-b;
}

double Mul(double a, double b)
{
	return a*b;
}

double Div(double a, double b)
{
	if (b == 0)
		return 0;
	return a/b;
}

double main()
{
	double a = 9;
	double b = 3;
	printf("add=%ld\n", func[SUB](a, b));
	return 0;
}
