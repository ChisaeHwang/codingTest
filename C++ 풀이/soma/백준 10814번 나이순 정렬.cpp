#include <iostream>
#include <algorithm>

using namespace std;

// 클래스를 이용해 나이와 이름 한번에 입력받기
class client {
public:
	int age;
	string name;
};

client *crr = new client[100000];

bool cmp(client a, client b) { // 오름차순 
	return a.age < b.age;
}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> crr[i].age >> crr[i].name;
	}

	// 안정정렬
	stable_sort(crr, crr + N, cmp);

	for (int i = 0; i < N; i++) {
		cout << crr[i].age << " " << crr[i].name << '\n';
	}
	
	return 0;
}
