#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

void sort(char arr[], int len)
{
	int i, j, t;
	for (i = 1; i < len; i++)
	{
		j = i;
		while (arr[j] < arr[j - 1] && j>0)
		{
			t = arr[j];
			arr[j] = arr[j - 1];
			arr[j - 1] = t;
			j--;
		}
	}
}
int main()
{
	char arr[] = "CBA";
	int len = 3;
	sort(arr, len);
	int i, j;
	for (i = (int)pow(2, len)-1; i >=1 ; i--)
	{
		int sum = i;
		for (j = len - 1; j >= 0; j--)
		{
			if (sum >= pow(2, j))
			{
				printf("%c", arr[len-1-j]);
				sum -= (int)pow(2, j);
			}
		}
		printf("\n");
	}
	system("pause");
	return 0;
}
