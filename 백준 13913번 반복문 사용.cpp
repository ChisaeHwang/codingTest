#include <iostream>>
#include <queue>
#include <stack>
using namespace std;

const int MAX = 200000;
bool check[MAX + 1];
int dist[MAX + 1];
int from[MAX + 1]; // 어디에서 왔는지 

int main()
{

    int n, m;
    cin >> n >> m;

    check[n] = true;
    dist[n] = 0;
    queue<int> q;
    q.push(n);
    while (!q.empty())
    {
        int now = q.front();
        q.pop();
        if (now - 1 >= 0) 
        {
            if (check[now - 1] == false)
            {
                q.push(now - 1);
                check[now - 1] = true;
                from[now -1] = now;
                dist[now - 1] = dist[now] + 1;
            }
        }
        if (now + 1 < MAX)
        {
            if (check[now + 1] == false)
            {
                q.push(now + 1);
                check[now + 1] = true;
                from[now + 1] = now;
                dist[now + 1] = dist[now] + 1;
            }
        }
        if (now * 2 < MAX)
        {
            if (check[now * 2] == false)
            {
                q.push(now * 2);
                check[now * 2] = true;
                from[now * 2] = now;
                dist[now * 2] = dist[now] + 1;
            }
        }
    }

    cout << dist[m] << '\n';
    
    stack<int> ans;
    for(int i=m; i!=n; i=from[i]){ // 역순으로 구하기 
    	ans.push(i);
	}
	ans.push(n);
	while(!ans.empty()){
		cout << ans.top() << ' ';
		ans.pop();
	}
	
	cout << '\n';

    return 0;
}
