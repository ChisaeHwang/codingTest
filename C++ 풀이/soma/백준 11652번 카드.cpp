#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	//freopen("test.txt", "r", stdin);
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	cin >> N;

	long long temp;
	vector<long long> v;

	for (int i = 0; i < N; i++)
	{
		cin >> temp;
		v.push_back(temp);
	}

	sort(v.begin(), v.end()); // sort로 크기만큼 정렬
	
	// 5, 3, 4, 3, 1 -> 1, 3, 3, 4, 5 

	int max = 0;
	int cnt = 0;
	long long result = v[0];

	for (int i = 1; i < N; i++)
	{
		if (v[i] == v[i - 1])
		{
			cnt++; // 같은게 있으면 count 
			if (cnt > max)
			{ // max count 갱신 
				max = cnt;
				result = v[i];
			}
		}
		else // 없으면 count 초기화 
			cnt = 0;
	}

	cout << result;
	
	return 0;
}
