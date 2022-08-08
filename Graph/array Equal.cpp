
#include <bits/stdc++.h>
using namespace std;


int arraySum(int arr[], int n)
{
	int sum = 0;
	for (int i = 0; i < n; i++)
		sum += arr[i];
	return sum;
}

int smallest(int arr[], int n)
{
	int small = INT_MAX;
	for (int i = 0; i < n; i++)
		if (arr[i] < small)
			small = arr[i];
	return small;
}

int minOp(int arr[], int n)
{
	int sum = arraySum(arr, n);
	int small = smallest(arr, n);
	int minOperation = sum - (n * small);
	
	return minOperation;
}


int main()
{
	return minOp(A, N); 
}


