/*
 * Change.cpp
 */

#include "Change.h"

// coinValues[] = {1, 2, 5}
// exite um stock ilimitado de moedas de cada valor
string calcChange(int m, int numCoins, int *coinValues)
{
	int missingChange;
	string change[100] = {""};
	if (m - coinValues[0] < 0 && m != 0)
		return "-";
	for (int i = 1; i <=m; i++) {
		missingChange = i;
		int j = numCoins - 1;
		while (j >= 0) {
			if (missingChange - coinValues[j] >= 0) {
				missingChange -= coinValues[j];
				cout << missingChange << " - " << coinValues[j] << " - ";
				change[i] = to_string(coinValues[j])+";" + change[missingChange];
				break;
			}
			else {
				j--;
			}
		}
		cout << change[i] << endl;
	}
    return change[m];
}


