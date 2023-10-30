#include <iostream>
#include <vector>
#include <queue>
#include <climits>
#include <stack>

using namespace std;

// �׷����� ������ ��Ÿ���� ����ü
struct Edge {
    int to;
    int weight;
};


int result; // �̰� �ִ� ��� ����, 1ȸ�� �����ϸ� �ִܰ�� �Է����°� �� ���ķδ� ���� ū �� ����?

// ���ͽ�Ʈ�� �˰��� �Լ�
void dijkstra(vector<vector<Edge>>& graph, int start) {
    int n = graph.size();
    vector<int> distance(n, INT_MAX);  // �׷��� ������ ��ŭ�� �迭, �� �ʱⰪ MAX�� ����
    distance[start] = 0; // 1������ 0���� ����


    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq; // �켱���� ť
    pq.push({ 0, start });  // {(��� �� ����)�ִܰŸ�, ��� ��ȣ} -> �ٴ� �� distance�� ������ ������?, �� ����

    while (!pq.empty()) {
        int u = pq.top().second;     // ����ȣ
        int dist = pq.top().first; // �ִܰŸ�
        pq.pop();

        if (dist > distance[u]) continue; // pq�� �ִܰŸ� > distance�� ��ϵ� �Ÿ�(?) ��  continue

        for (const Edge& edge : graph[u]) { // �ش� ��忡 �پ��ִ� ��� ��带 ��ȸ�� 
            int v = edge.to; // �� �� �ִ� ���� 
            int weight = edge.weight;

            if (distance[u] + weight < distance[v]) {  // ���� �Ÿ�+ ���⼭ �߰��Ÿ�  <  �̰Ŷ� ������ ��ϵ� �ִܰŸ�
                // �����̸� �� ��ΰ� �� ������ ������Ʈ �ؾ�����~
                distance[v] = distance[u] + weight;
                pq.push({ distance[v], v });
            }
        }
    }

    if (result <= distance[n - 1]) { // ���� ���� ���� �Ÿ��� �� �����ɸ��ٸ� ������Ʈ
        result = distance[n - 1];
    }

    return;
}

vector<int> firstDijkstra(vector<vector<Edge>>& graph, int start) {
    int n = graph.size();
    vector<int> distance(n, INT_MAX);  // �׷��� ������ ��ŭ�� �迭, �� �ʱⰪ MAX�� ����
    distance[start] = 0; // 1������ 0���� ����

    vector<int> previous(n, -1); // ���� ��� �迭 �߰�
    previous[start] = start;

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq; // �켱���� ť
    pq.push({ 0, start });  // {(��� �� ����)�ִܰŸ�, ��� ��ȣ} -> �ٴ� �� distance�� ������ ������?, �� ����

    while (!pq.empty()) {
        int u = pq.top().second;     // ����ȣ
        int dist = pq.top().first; // �ִܰŸ�
        pq.pop();

        if (dist > distance[u]) continue; // pq�� �ִܰŸ� > distance�� ��ϵ� �Ÿ�(?) ��  continue

        for (const Edge& edge : graph[u]) { // �ش� ��忡 �پ��ִ� ��� ��带 ��ȸ�� 
            int v = edge.to; // �� �� �ִ� ���� 
            int weight = edge.weight;

            if (distance[u] + weight < distance[v]) {  // ���� �Ÿ�+ ���⼭ �߰��Ÿ�  <  �̰Ŷ� ������ ��ϵ� �ִܰŸ�
                // �����̸� �� ��ΰ� �� ������ ������Ʈ �ؾ�����~
                distance[v] = distance[u] + weight;
                previous[v] = u; // ���� ��� ����
                pq.push({ distance[v], v });

           //     cout << "������Ʈ!! distance[" << v << "] = " << distance[v] << "!!\n";
            }
        }
    }
    result = distance[n - 1];

    return previous; // ���� ��� �迭 ��ȯ, �̰� ���� ����ϸ� �ִܰ����
    // return distance[���������] �ϸ� �ִܰ�� "��"�� ��ȯ��
}

int main() {
    int numVertices, numEdges;
    cin >> numVertices >> numEdges;

    vector<vector<Edge>> graph(numVertices);

    for (int i = 0; i < numEdges; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        // ����� �׷����̹Ƿ� u���� v�� ���� ������ v���� u�� ���� ������ �߰�

        graph[u-1].push_back({ v-1, w }); // �� �̰� �Ÿ��� ����� �����ϰ� �������� -1
        graph[v-1].push_back({ u-1, w });
    }

    // ���� ������ 1�� ����  -> �ٵ� �̰� 0���� �ٲ�ߵɵ�?
    int startVertex = 0;

    vector<int> previous = firstDijkstra(graph, startVertex);

    int lastVertex = numVertices - 1;

   // cout << "Shortest path from vertex " << startVertex << " to vertex " << lastVertex << ": " << endl;
   // cout << "\n�ִܰŸ���" << result<<"\n"; // �ִܰŸ� �׽�Ʈ ����
    
   
   // �ϴ� ���⼭ �߰��Ұ�
    //1. previous �� �ϳ� �ϳ������� �� ��� �������� �����ϰ� �����ϰ� �������ϰ� �ϸ��
    //2. �׸��� �ִ� ��� �̹� ������ ������ �����ϵ� ��ī�� ��� ��(���� �� ��, ������ ����ؼ� �� ¥���ô�)
    

    stack<int> path;
    int currentVertex = lastVertex;

    while (currentVertex != startVertex) {
        path.push(currentVertex);
        currentVertex = previous[currentVertex];
    }

    path.push(startVertex);

    // �� ���� ���ÿ��� ��ΰ� ����ִ� ^^�ӹ�

    int end = path.size() - 1;
    for (int i = 0; i <end; i++) {
        // �� ���� ũ��-1 ��ŭ ���ư���, top�̶� pop���� �̾ƾ���ǰ�

        int first = path.top();  // ù��° ��� (���� ����)
        path.pop();
        int second = path.top(); // �ι�° ���

        // �������� ���� ������ �ι�°�� �������� ��ߵ� ����?
       // cout << first << " ��  " << second << "����(0���� ����)\n";

        Edge forFirst;

        forFirst.to = -1;    // 'to' ��� ������ 10 ����
        forFirst.weight = -1; // 'weight' ��� ������ 20 ����

        Edge forSecond;
        forSecond.to = -1;    // 'to' ��� ������ 10 ����
        forSecond.weight = -1; // 'weight' ��� ������ 20 ����


        for (int k = 0; k < graph[first].size(); k++) {

            if (graph[first][k].to == second) {
                // 'to' ���� 10�� ��� �ش� ����ü ����
                forFirst = graph[first][k];
                graph[first].erase(graph[first].begin() + k);
            }
        }


        for (int k = 0; k < graph[second].size(); k++) {

            if (graph[second][k].to == first) {
                // 'to' ���� 10�� ��� �ش� ����ü ����
                forSecond = graph[second][k];
                graph[second].erase(graph[second].begin() + k);
            }
        }

        //���� ������ �� ��, �ش� �������� ���� ������
        // ���� ���ͽ�Ʈ�� ȣ���ؼ� �� �Լ� ���ο� �������� �� ������ (ū�� �ְ�)
       // �ٽ� ���󺹱� ��Ű���


        //���� ���ͽ�Ʈ��
  
        dijkstra(graph, startVertex);

    //    cout << "�̰� �ΰ� ������ ������" << forSecond.to << "  " << forFirst.to << "\n";


        graph[first].push_back(forFirst);
        graph[second].push_back(forSecond);
        
    }

  //  cout << "���� ������, �������? (�ᱹ �����Ÿ�)  " << result<<"\n";
    cout << result;


    //�̰� ���� ��ǥ ������ �̾ƺ��� ����



    /*
    while (!path.empty()) {
        cout << path.top() << " ";
        path.pop();
    }

    cout << endl;
    */
    return 0;
}
