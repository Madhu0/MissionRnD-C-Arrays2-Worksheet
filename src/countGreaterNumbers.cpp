/*
OVERVIEW: You are given a bank statement where transactions are ordered by date. Write a function that finds the number of transactions in that statement after a given date.
-- find the count of numbers greater than a given number in a sorted array.
E.g.: Input: A[3] = { { 10, "09-10-2003", "First" }, { 20, "19-10-2004", "Second" }, { 30, "03-03-2005", "Third" } };
date = "19-10-2004"
Output: 1 (as there is only one transaction { 30, "03-03-2005", "Third" })

INPUTS: One bank statement (array of transactions) and date.

OUTPUT: Return the number of transactions in that statement after a given date.

ERROR CASES: Return NULL for invalid inputs.

NOTES:
*/

struct transaction {
	int amount;
	char date[11];
	char description[20];
};

int compare(char *string1,char *ptr){
	int i;
	for (i = 0; string1[i] != '\0'&&ptr[i] != '\0'; i++){
		if (string1[i] != ptr[i])
			return 0;
	}
	if (string1[i] == ptr[i])
		return 1;
}

int countGreaterNumbers(struct transaction *Arr, int len, char *date) {
	int i;
	if (Arr==nullptr)
		return -1;
	else{
		for (i = 0; i < len; i++){
			if (compare(Arr[i].date, date))
				break;
		}
		if (i < len - 1 && !compare(Arr[i+1].date, date))
			return len - i - 1;
		else
			return 0;
	}

}
