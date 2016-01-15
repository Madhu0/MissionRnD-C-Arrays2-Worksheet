/*
OVERVIEW: You are given 2 bank statements that are ordered by date. Write a function that returns dates common to both statements
(ie both statements have transactions in these dates).
E.g.: Input: A[3] = { { 10, "09-10-2003", "First" }, { 20, "19-10-2004", "Second" }, { 30, "03-03-2005", "Third" } };
B[3] = { { 10, "09-10-2003", "First" }, { 220, "18-01-2010", "Sixth" }, { 320, "27-08-2015", "Seventh" } };
Output: { { 10, "09-10-2003", "First" } }

INPUTS: Two bank statements (array of transactions).

OUTPUT: Transactions having same dates.

ERROR CASES: Return NULL for invalid inputs.

NOTES:
*/

#include <iostream>

int convert_num1(char str[]){
	int day = (str[0] - '0') * 10 + str[1] - '0';
	int month = (str[3] - '0') * 10 + str[4] - '0';
	int year = (str[6] - '0') * 1000 + (str[7] - '0') * 100 + (str[8] - '0') * 10 + str[9];
	return day + month * 30 + year * 365;
}

struct transaction {
	int amount;
	char date[11];
	char description[20];
};

struct transaction * sortedArraysCommonElements(struct transaction *A, int ALen, struct transaction *B, int BLen) {
	if (A == NULL || B == NULL || ALen < 1 || BLen < 1)
		return NULL;
	int i = 0, j = 0, k = 0,common_count=0;
	struct transaction *result;
	result = (struct transaction *)malloc((ALen + BLen)*sizeof(struct transaction));
	while (i < ALen&&j < BLen){
		if (convert_num1(A[i].date) < convert_num1(B[j].date))
			i++;
		else if (convert_num1(A[i].date) > convert_num1(B[j].date))
			j++;
		else{
			result[k] = A[i];
			common_count++;
			k++;
			i++;
			j++;
		}
	}
	if (common_count == 0)
		return NULL;
	return result;
}