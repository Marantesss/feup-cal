/*
 * Factorial.cpp
 */

#include "Factorial.h"

int factorialRecurs(int n)
{
	if (n < 0) {
		return 0;
	}
	else if (n == 1 || n == 0) {
		return 1;
	}
	else
		return n * factorialRecurs(n-1);

}

int factorialDinam(int n)
{
	if (n <= 0) {
		return 0;
	}

	long fact[100] = {0};
	fact[0] = 1;
	for (int i = 1; i <= n; ++i)
		fact[i] = i * fact[i - 1];
	return fact[n];

	return 0;
}
