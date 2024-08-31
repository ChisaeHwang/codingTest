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
//	while (end > start) // end가 start보다 같거나 작아지면, 그 값이 Lower Bound이므로 반복을 종료한다.
//	{
//		mid = (start + end) / 2; 
//		if (arr[mid] >= target) // 중간값이 원하는 값보다 크거나 같을 경우, 끝값을 중간값으로 설정하여 다시 탐색한다.
//			end = mid;
//		else start = mid + 1; // 중간값이 원하는 값보다 작을 경우, 시작값을 중간값+1로 설정하여 다시 탐색한다.
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
	  // 첫번째 인덱스를 빼주면 주소값이 아닌 인덱스 값을 반환 가능하다. 
      v[idx] = a;
    }
  }
  
  cout << v.size();
}
