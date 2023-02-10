#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

//2.5_°ÅµìÁ¦°ö(¼øÈ¯)
//(ÀÔ·Â)Enter a number: x n
//(Ãâ·Â)x^n = °ÅµìÁ¦°ö°ª

double power(double x, int n)
{
	if (n == 0) //x^0 = 1
		return 1;
	else if ((n % 2) == 0) //nÀÌ Â¦¼ö
		return power(x * x, n / 2);
	else return x * power(x * x, (n - 1) / 2); //nÀÌ È¦¼ö
}
int main(void)
{
	double x;
	int n;

	print("Enter a number: ");
	scanf("%lf %d", &x, &n);

	printf("%.f^%d = %.f", x, n, power(x, n));
}

/*2.4_°ÅµìÁ¦°ö(¹İº¹)
//(ÀÔ·Â)Enter a number: x n
//(Ãâ·Â)x^n = °ÅµìÁ¦°ö°ª

double power(double x, int n)
{
	double result = 1.0;

	for (int i = 0; i < n; i++)
		result *= x;

	return result;
}
int main(void)
{
	double x;
	int n;

	print("Enter a number: ");
	scanf("%lf %d", &x, &n);

	print("%.f^%d = %.f", x, n, power(x, n));
}*/