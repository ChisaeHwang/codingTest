#include <iostream>
#include <algorithm>

using namespace std;

int N, M, x;
long long cnt[1001];
long long sum, ans;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> M;

	for (int i = 0; i < N; i++)
	{
		cin >> x;
		sum += x;
		cnt[sum % M]++;
	}

	for (int i = 0; i <= 1000; i++)
	{
		ans += cnt[i] * (cnt[i] - 1) / 2; // nC2 ¸¸Å­ ´õÇØÁÜ 
	}
	
	cout << cnt[0] + ans;
	
	return 0; 
}

