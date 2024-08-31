#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int DP[1001];

int main() {
	
	int N;
	cin >> N;

	DP[1] = 1;
	DP[2] = 0;
	DP[3] = 1;
	DP[4] = 1;
	
	for (int i = 5; i <= N; i++) 
		{
		if (min({DP[i - 1], DP[i - 3], DP[i - 4]})) 
		{
	      DP[i] = 0;
	    } 
		else 
		{
	      DP[i] = 1;
	    }
	  }
	
	  if (DP[N])
	  {
	    cout << "SK";
	  } else 
	  {
	    cout << "CY";
	  }
	
	return 0;
} 
