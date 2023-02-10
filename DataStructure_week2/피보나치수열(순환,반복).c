#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

//2.6_피보나치수열(순환)
//(입력)Enter a number: n
//(출력)fib(n) = 결과

int fib(int n)
{
	if (n == 0) return 0;
	if (n == 1) return 1;
	return fib(n - 2) + fib(n - 1);
}
int main(void)
{
	int n;
	print("Enter a number: ");
	scanf("%d", &n);

	printf("fib(%d) = %d\n", n, fib(n));
}

/*2.7_피보나치수열(반복)
//(입력)Enter a number: n
//(출력)fib(n) = 결과

int fib(int n)
{
	if (n == 0) return 0; //pp
	if (n == 1) return 1; //p

	int pp = 0, p = 1, result = 0;

	for (int i = 2; i <= n; i++) {
		result = p + pp;
		pp = p;
		p = result;
	}
	return result;
}
int main(void)
{
	int n;
	print("Enter a number: ");
	scanf("%d", &n);

	printf("fib(%d) = %d\n", n, fib(n));
}*/