#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

//2.6_�Ǻ���ġ����(��ȯ)
//(�Է�)Enter a number: n
//(���)fib(n) = ���

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

/*2.7_�Ǻ���ġ����(�ݺ�)
//(�Է�)Enter a number: n
//(���)fib(n) = ���

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