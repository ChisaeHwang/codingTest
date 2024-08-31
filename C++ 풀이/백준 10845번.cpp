#include<iostream>
#include<string>

using namespace std;

struct Queue {
	
	int data[10000];
	int begin, end;
	
	Queue() {
		begin = 0;
		end = 0;	
	}

	void push(int num) {
		data[end] = num;
		end += 1;
	}
	
	int pop() {
		if (empty()) {
			return -1;
		}
		begin += 1;
		return data[begin-1];
	}
	
	int size() {
		return end - begin;
	}
	
	int front() {
		return data[begin];
	}
	
	int back() {
		return data[end-1];
	}
	
	bool empty() {
		if (begin == end) return true;
		else return false;
	}
};

	int main(){
		
		ios_base::sync_with_stdio(false);
		cin.tie();
		
		int t;
		cin >> t;
	
		Queue q;
		
		while(t--){
			string n;
			cin >> n;
			if (n == "push"){
				int num;
				cin >> num;
				q.push(num);
			} else if (n == "pop"){
				if (q.empty()){
					cout << -1 << '\n';
				} else {
					cout << q.front() << '\n';
					q.pop();
				}
			} else if (n == "size"){
				cout << q.size() << '\n';
			} else if (n == "empty"){
				cout << q.empty() << '\n';
			} else if (n == "front"){
				if (q.empty()){
					cout << -1 << '\n';
				} else {
					cout << q.front() << '\n';
				}
			} else if (n == "back"){
				if (q.empty()){
					cout << -1 << '\n';
				} else {
					cout << q.back() << '\n';
			}
			
		}
	}
	
		
	    return 0;    
	}


