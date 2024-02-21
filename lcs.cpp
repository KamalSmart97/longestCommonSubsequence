#include<iostream>
using namespace std;

static int current_value = 0, maximum_subsequence = 0;

int longest_common_subsequence(int **numPos, int row, int currentValue, int totalRow, int totalColumn, int intialTerm)
{

	for (int jj = row; jj < totalRow; jj++)
	{
		int ii = 0;

		while (numPos[jj][ii] != -1)
		{
			int temp = intialTerm;

			if (numPos[jj][ii] > currentValue)
			{
				temp++;
				if ((row + 1) < totalRow)
					longest_common_subsequence(numPos, row + 1, numPos[jj][ii], totalRow, totalColumn, temp);

				if (temp > maximum_subsequence)
					maximum_subsequence = temp;


				return 0;

			}
			else
				ii++;

			if (ii >= totalColumn)
				break;
		}
	}
	return 0;
}


int main()
{
	char string1[][100] = { "","" };
	int ii = 0, jj = 0, kk = 0, nStatus = 0;
	bool bFound = false;

	int strle1n[2] = { 0 };
	int len1 = 0, len2 = 0;

	cout << "enter the first string";
	cin >> string1[0];
	cout << "enter the second string";
	cin >> string1[1];

	strle1n[0] = strlen(string1[0]);
	strle1n[1] = strlen(string1[1]);

	//eliminating the un-common sting
	int n = 0;
	strle1n[0] < strle1n[1] ? n = 0 : n = 1;

	len1 = strle1n[n];
	len2 = strle1n[!n];


	//Allocating the row space in heap dynamically

	int** LCS_string = new int* [len1];

	//Allocating the column space in heap dynamically

	for (ii = 0; ii < len1; ii++)
	{
		kk = 0;
		LCS_string[ii] = new int[len2];
		for (jj = 0; jj < len2; jj++)
		{
			LCS_string[ii][jj] = -1;
			if (string1[n][ii] == string1[!n][jj])
			{
				bFound = true;
				LCS_string[ii][kk] = jj;
				kk++;
			}
		}

	}

	if (!bFound)
	{
		cout << " no common sequence found";
		nStatus = -1;
		goto cleanup;
	}
	for (ii = 0; ii < len1; ii++)
	{
		current_value = 0;
		longest_common_subsequence(LCS_string, ii, 0, len1, len2,0);
	}
	cout << " the longest common sequence is :\t"<< maximum_subsequence;

cleanup:
	//Free the memory after the use of array
	for (ii = 0; ii < strle1n[n]; ii++) {
		delete[] LCS_string[ii];
	}

	delete[] LCS_string;

	return nStatus;

}

