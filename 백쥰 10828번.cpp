#include <iostream>
#define mod 1000000000

using namespace std;

int s; // stackÀÇ size
int a[10001];
void push(int x) {
	a[s] = x;
	s++;
}
int pop() {
	if (s == 0) return -1;
	int t = a[s - 1];
	s--;
	return t;
}
int size() {
	return s;
}
int top() {
	if (s == 0) return -1;
	return a[s - 1];
}
int empty() {
	if (s == 0) return 1;
	else return 0;
}

int main(){
	
    ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	string str;
	int n;
	cin >> n;
	while(n--){
		cin >> str;
		if (str == "push") {
			int n;
			cin >> n;
			push(n);
		}
		if (str == "pop") {
			cout << pop() << '\n';
		}
		if (str == "top") {
			cout << top() << '\n';
		}
		if (str == "size") {
			cout << size() << '\n';
		}
		if (str == "empty") {
			cout << empty() << '\n';
		}
	}

	
    return 0;
}
