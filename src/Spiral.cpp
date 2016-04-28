/*
Write a program to generate elements of a matrix in spiral order.
Store the generated elements in single dimensional array and return that array.

Directions for Spiral are : Go Right ,Go Down ,Go Left, Go Up
Ex:

Matrix:
1	2	3
4	5	6
7	8	9

Spiral order:
1	2	3	6	9	8	7	4	5

Given matrix is a two dimensional array(input_array) with dimensions rows, columns.
If rows, columns are invalid then return NULL.
If input_array is NULL then return NULL.

Example Input :
int board[2][3]={
				 {4,6,7},
				 {1,3,8}
				};
spiral(2,2,(int **)board); // Rows followed by columns followed by board

Example Output : Return an array consisting of {4,6,7,8,3,1};

Note : Check the function Parameters ,Its a double pointer .

*/


#include "stdafx.h"
#include<stdlib.h>

int *spiral(int rows, int columns, int **input_array)
{
	if (rows <= 0 || columns <= 0 || input_array == NULL)
		return NULL;
	else
	{
		int i, j = 0, k = 0, l = rows, m = 0, n = columns;
		int size = rows*columns;
		int *arr = (int *)malloc(size * sizeof(int));
		/*
		k - starting row index
		l - ending row index
		m - starting column index
		n - ending column index
		i - iterator
		j - index
		*/

		while (k < l && m < n)
		{
			/* Print the first row from the remaining rows */
			for (i = m; i < n; ++i)
			{
				arr[j++] = input_array[k][i];
			}
			k++;

			/* Print the last column from the remaining columns */
			for (i = k; i < l; ++i)
			{
				arr[j++] = input_array[i][n - 1];
			}
			n--;

			/* Print the last row from the remaining rows */
			if (k < l)
			{
				for (i = n - 1; i >= m; --i)
				{
					arr[j++] = input_array[l - 1][i];
				}
				l--;
			}

			/* Print the first column from the remaining columns */
			if (m < n)
			{
				for (i = l - 1; i >= k; --i)
				{
					arr[j++] = input_array[i][m];
				}
				m++;
			}
		}
		return(arr);
	}
}

