#include <iostream>
#include <vector>
#include <cstring>
#include <fstream>
#include <algorithm>

using namespace std;

//int lower_bound(int arr[], int target, int size)
//{
//	int mid, start, end;
//	start = 0, end = size-1;
//
//	while (end > start) // end�� start���� ���ų� �۾�����, �� ���� Lower Bound�̹Ƿ� �ݺ��� �����Ѵ�.
//	{
//		mid = (start + end) / 2; 
//		if (arr[mid] >= target) // �߰����� ���ϴ� ������ ũ�ų� ���� ���, ������ �߰������� �����Ͽ� �ٽ� Ž���Ѵ�.
//			end = mid;
//		else start = mid + 1; // �߰����� ���ϴ� ������ ���� ���, ���۰��� �߰���+1�� �����Ͽ� �ٽ� Ž���Ѵ�.
//	}
//	return end;
//}

int n;

int main(){
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> n;

  vector<int> v = {1000000};

  for (int i=0; i<n; i++){
    int a;
    cin >> a;
    if (a > v.back()) 
	{
		v.push_back(a);	
	}
    else
	{
      int idx = lower_bound(v.begin(), v.end(), a) - v.begin();
	  // ù��° �ε����� ���ָ� �ּҰ��� �ƴ� �ε��� ���� ��ȯ �����ϴ�. 
      v[idx] = a;
    }
  }
  
  cout << v.size();
}
