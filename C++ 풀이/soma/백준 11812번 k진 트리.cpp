#include <bits/stdc++.h>
using namespace std;

long long n, k, t;

long long getDepth(long long node) {
	
	long long depth = 0;
	long long left = 1;
	long long right = k;
	
	if(k == 1) {
		return node;
	} else {
		if(node != 0) { 
			depth = 1;
			while (!(left <= node && node <= right)) {
				++depth;
				left = left * k + 1;
				right = right * k + k;	
			} 
		}
	}
	
	return depth;
}

long long getParent(long long node) {

	long long parent = (node - 1) / k;
	
	return parent;
}

long long solve(long long u, long long v) {
	
	long long ret = 0;
	
	if(getDepth(u) < getDepth(v)) {
		swap(u, v);
	}
	
	
	if(k == 1) {
		ret = getDepth(u) - getDepth(v);
	} else {
		
		long long diff = getDepth(u) - getDepth(v);
		ret += diff;
		while(diff--) {
			u = getParent(u);
		}
		
		while(u != v) {
			u = getParent(u);
			v = getParent(v);
			ret += 2;
		}
	}
	
	
	return ret;
}


int main() {
    ios_base::sync_with_stdio(0); 
	cin.tie(0);
	
    cin >> n >> k >> t;
    
    while(t--) {
        long long u, v;
        cin >> u >> v;
        cout << solve(u - 1, v - 1) << '\n';
    }
    
    return 0;
}
