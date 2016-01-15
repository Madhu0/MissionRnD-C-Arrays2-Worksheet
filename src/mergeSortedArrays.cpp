/*
OVERVIEW: You are given 2 bank statements that are ordered by date - Write a function that produces a single merged statement ordered by dates.
E.g.: Input: A[3] = { { 10, "09-10-2003", "First" }, { 20, "19-10-2004", "Second" }, { 30, "03-03-2005", "Third" } };
B[2] = { { 10, "09-10-2003", "First" }, { 220, "18-01-2010", "Sixth" } };
Output: { { 10, "09-10-2003", "First" }, { 10, "09-10-2003", "First" }, { 20, "19-10-2004", "Second" },  30, "03-03-2005", "Third" }, { 220, "18-01-2010", "Sixth" } }

INPUTS: Two bank statements (array of transactions).

OUTPUT: Combined statement ordered by transaction date.

ERROR CASES: Return NULL for invalid inputs.

NOTES:
*/

#include <iostream>

struct transaction {
	int amount;
	char date[11];
	char description[20];
};

int convert_num(char str[]){
	int day = (str[0]-'0') * 10 + str[1]-'0';
	int month = (str[3]-'0') * 10 + str[4]-'0';
	int year = (str[6]-'0') * 1000 + (str[7]-'0') * 100 + (str[8]-'0') * 10 + str[9];
	return day + month*30 + year*365;
}
struct transaction * mergeSortedArrays(struct transaction *A, int ALen, struct transaction *B, int BLen) {
	if (A == NULL || B == NULL || ALen < 1 || BLen < 1)
		return NULL;
	int i = 0, j = 0, k = 0;
	struct transaction *result;
	result = (struct transaction *)malloc((ALen + BLen)*sizeof(struct transaction));
	while (i < ALen&&j < BLen){
		if (convert_num(A[i].date) < convert_num(B[j].date)){
			result[k] = A[i];
			k++;
			i++;
		}
		else if (convert_num(A[i].date) > convert_num(B[j].date)){
			result[k] = B[j];
			k++;
			j++;
		}
		else{
			result[k] = A[i];
			k++;
			result[k] = B[j];
			k++;
			i++;
			j++;
		}
	}
	if (i < (ALen)){
		for (; i < ALen; i++){
			result[k] = A[i];
			k++;
		}
	}
	else if (j < (BLen)){
		for (; j < BLen; j++){
			result[k] = B[j];
			k++;
		}
	}
	return result;
}