#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int MAX_N = 500000;

int N;
int arrA[MAX_N + 1], arrB[MAX_N * 2];
long long tree[4 * (MAX_N + 1)];

long long sum(int node, int start, int end, int left, int right){
    if(left > end || right < start) return 0;
    if(left <= start && end <= right) {
    	return tree[node];
	}
    int mid = (start + end)/2;
    return sum(node*2, start, mid, left, right) + sum(node*2 + 1, mid + 1, end, left, right);
}

void update(int node, int start, int end, int idx) {
	if (idx < start || end < idx) return;
    if (start == end) { // 5번 같은 경우 idx가 5고 end가 이이상 작아지면 어차피 return 그러므로 
        tree[node]++; // idx 5에 맞지 않는 다른 node가 ++ 될 일 없음  
        return; // 예시 : 4-4, 2-2 같은 경우 end : 4, end : 2 이므로 return 그냥 
    }
    
	int mid = (start + end)/2; 
	update(node * 2, start, mid, idx); // 왼쪽 자식 노드로 
	update(node * 2 + 1, mid + 1, end, idx); // 오른쪽 자식 노드로
	tree[node] = tree[node * 2] + tree[node * 2 + 1];
	 
}

int main() {
	
	ios_base::sync_with_stdio(false); 
	cin.tie(NULL); cout.tie(NULL);
	
	
    cin >> N;
    for (int i = 1; i <= N; i++) {
        cin >> arrA[i];
    }
    for (int i = 1; i <= N; i++) {
        int num;
        cin >> num;
        arrB[num] = i;
    }
    
    long long ans = 0;
    for (int i = 1; i <= N; i++) {
        ans += sum(1, 1, N, arrB[arrA[i]] + 1, N); // node, start, end, left, right
        update(1, 1, N, arrB[arrA[i]]); // node, start, end, idx
    }
    cout << ans;
    return 0;
}

