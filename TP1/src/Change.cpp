/*
 * Change.cpp
 */

#include "Change.h"
#include <algorithm>

// coinValues[] = {1, 2, 5}
// exite um stock ilimitado de moedas de cada valor
string calcChange(int m, int numCoins, int *coinValues)
{
	int minCoin[m + 1];
	int lastCoin[m + 1];
	for (int i = 0; i < m + 1; i++) {
		minCoin[i] = 100;
		lastCoin[i] = 0;
	}
	minCoin[0] = 0;

	for (int i = 0; i < numCoins; i++) {
		int possibleLastCoin = coinValues[i];
		for (int k = 1; k <= m; k++) {
			int remainingChange = k - possibleLastCoin;
			if (remainingChange >= 0) {
				int possibleMinCoin = minCoin[remainingChange] + 1;
				if (possibleMinCoin < minCoin[k]) {
					minCoin[k] = possibleMinCoin;
					lastCoin[k] = possibleLastCoin;
				}
			}
		}
	}

	// printing the result
	for (int k = 0; k <= m; k++)
		cout << k << "    \t";
	cout << endl;
	for (int k = 0; k <= m; k++)
		cout << minCoin[k] << " - " << lastCoin[k] << "\t";

	// getting the result
	int remainingChange = m;
	string answer = "";
	while (remainingChange != 0) {
		answer += to_string(lastCoin[remainingChange]) + ";";
		remainingChange -= lastCoin[remainingChange];
	}
	cout << answer << endl;
	return answer;

	/*
	 * Greedy Algorithm
	 *
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
    */
}


