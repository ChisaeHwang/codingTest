#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main() {
	
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
    priority_queue<int> maxHeap; // �ִ� ��, ������ ���� 
    priority_queue<int, vector<int>, greater<int>> minHeap; // �ּ� ��, ū�� ���� 

    int n;
    cin >> n;

    for (int i = 0; i < n; ++i) {
    	int num;
        cin >> num;
        if(maxHeap.empty() || num < maxHeap.top()){
        	maxHeap.push(num);
		} else {
			minHeap.push(num);
		}
		
		if(maxHeap.size() > minHeap.size() + 1) {
			minHeap.push(maxHeap.top());
			maxHeap.pop();
		} else if (minHeap.size() > maxHeap.size() + 1) {
			maxHeap.push(minHeap.top());
			minHeap.pop();
		}
		
		if(maxHeap.size() == minHeap.size()) {
			cout << maxHeap.top() << '\n';
		} else if (maxHeap.size() > minHeap.size()) {
			cout << maxHeap.top() << '\n';
		} else if (maxHeap.size() < minHeap.size()) {
			cout << minHeap.top() << '\n';
		}
    }

    return 0;
}

