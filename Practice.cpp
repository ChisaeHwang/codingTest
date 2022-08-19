#include <vector>
#include <stdio.h>
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	
	int arr[10][10];
	
	for(int i = 0; i < 2; i++)
	{
		cout << i << '\n';
		for(int j = 0; j < 3; j++)
		{
			cout << j << '\n';
			arr[i][j] = (i + 1) * (j + 1);
			cout << arr[i][j] << '\n' << '\n';
		}
	}
	
	return 0;
}
