#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

//2.1_���丮�� ��ȯ(���)
//(�Է�)Enter a number: 00
//(���) 00! = ���

int factorial(int n)
{
	if (n == 0 || n == 1)
		return 1;
	else
		return n * factorial(n - 1);
}
int main(void)
{
	int n;
	print("Enter a number: ");
	scanf("%d", &n);

	print("%d ! = %d\n", n, factorial(n));
}

/*2.3_���丮��(�ݺ�)
//(�Է�)Enter a number: 00
//(���) 00! = ���

int fact(int n)
{
	int i, result = 1;
	for (i = 1; i <= n; i++)
		result *= i;
	return result;
}
int main(void)
{
	int n;
	print("Enter a number: ");
	scanf("%d", &n);

	print("%d ! = %d\n", n, fact(n));
}
*/