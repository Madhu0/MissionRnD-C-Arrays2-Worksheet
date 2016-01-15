/*
OVERVIEW: Given an array where every element occurs three times, except one element which occurs only
once. Find the element that occurs once.
E.g.: Input: arr = 12, 1, 12, 3, 12, 1, 1, 2, 3, 3
ouput: 2

INPUTS: Integer array and length of the array.

OUTPUT: Element that occurs only once.

ERROR CASES: Return -1 for invalid inputs.

NOTES:
*/
#include <stdlib.h>

void update(int **array1, int element, int *pos, int *sum){
	int i, flag = 1;
	for (i = 0; i < *pos; i++){
		if (array1[i][0] == element){
			if (array1[i][1] == 1){
				*sum -= element;
				array1[i][1]++;
			}
			flag = 0;
			break;
		}
	}
	if (flag){
		array1[*pos][0] = element;
		*sum += element;
		array1[*pos][1] = 1;
		*pos += 1;
	}
}

int findSingleOccurenceNumber(int *A, int len) {
	if (A == NULL || len < 1)
		return -1;
	int **numbers, size, i, sum = 0, j = 0;
	size = (len / 3) + 2;
	numbers = (int **)malloc(size * sizeof(int *));
	for (i = 0; i < size; i++)
		numbers[i] = (int *)malloc(2 * sizeof(int));
	for (i = 0; i < 2; i++){
		for (j = 0; j < size; j++){
			numbers[j][i] = -1;
		}
	}
	j = 0;
	for (i = 0; i < len; i++){
		update(numbers, A[i], &j, &sum);
	}
	return sum;
}