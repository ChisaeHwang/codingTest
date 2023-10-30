#include <iostream>
#include <vector>
#include <queue>
#include <climits>
#include <stack>

using namespace std;

// 그래프의 간선을 나타내는 구조체
struct Edge {
    int to;
    int weight;
};


int result; // 이게 최단 경로 값임, 1회차 실행하면 최단경로 입력할태고 그 이후로는 가장 큰 값 대입?

// 다익스트라 알고리즘 함수
void dijkstra(vector<vector<Edge>>& graph, int start) {
    int n = graph.size();
    vector<int> distance(n, INT_MAX);  // 그래프 사이즈 만큼의 배열, 각 초기값 MAX로 저장
    distance[start] = 0; // 1빠따는 0으로 설정


    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq; // 우선순위 큐
    pq.push({ 0, start });  // {(출발 점 부터)최단거리, 노드 번호} -> 근대 왜 distance랑 별개로 만들지?, 함 보자

    while (!pq.empty()) {
        int u = pq.top().second;     // 노드번호
        int dist = pq.top().first; // 최단거리
        pq.pop();

        if (dist > distance[u]) continue; // pq의 최단거리 > distance에 기록된 거리(?) 면  continue

        for (const Edge& edge : graph[u]) { // 해당 노드에 붙어있는 모든 노드를 순회함 
            int v = edge.to; // 갈 수 있는 방향 
            int weight = edge.weight;

            if (distance[u] + weight < distance[v]) {  // 지금 거리+ 여기서 추가거리  <  이거랑 별도로 기록된 최단거리
                // 성립이면 이 경로가 더 나으니 업데이트 해야줘잉~
                distance[v] = distance[u] + weight;
                pq.push({ distance[v], v });
            }
        }
    }

    if (result <= distance[n - 1]) { // 빼고 나서 구한 거리가 더 오래걸린다면 업데이트
        result = distance[n - 1];
    }

    return;
}

vector<int> firstDijkstra(vector<vector<Edge>>& graph, int start) {
    int n = graph.size();
    vector<int> distance(n, INT_MAX);  // 그래프 사이즈 만큼의 배열, 각 초기값 MAX로 저장
    distance[start] = 0; // 1빠따는 0으로 설정

    vector<int> previous(n, -1); // 이전 노드 배열 추가
    previous[start] = start;

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq; // 우선순위 큐
    pq.push({ 0, start });  // {(출발 점 부터)최단거리, 노드 번호} -> 근대 왜 distance랑 별개로 만들지?, 함 보자

    while (!pq.empty()) {
        int u = pq.top().second;     // 노드번호
        int dist = pq.top().first; // 최단거리
        pq.pop();

        if (dist > distance[u]) continue; // pq의 최단거리 > distance에 기록된 거리(?) 면  continue

        for (const Edge& edge : graph[u]) { // 해당 노드에 붙어있는 모든 노드를 순회함 
            int v = edge.to; // 갈 수 있는 방향 
            int weight = edge.weight;

            if (distance[u] + weight < distance[v]) {  // 지금 거리+ 여기서 추가거리  <  이거랑 별도로 기록된 최단거리
                // 성립이면 이 경로가 더 나으니 업데이트 해야줘잉~
                distance[v] = distance[u] + weight;
                previous[v] = u; // 이전 노드 갱신
                pq.push({ distance[v], v });

           //     cout << "업데이트!! distance[" << v << "] = " << distance[v] << "!!\n";
            }
        }
    }
    result = distance[n - 1];

    return previous; // 이전 노드 배열 반환, 이거 역순 출력하면 최단경로임
    // return distance[마지막노드] 하면 최단경로 "값"이 반환됨
}

int main() {
    int numVertices, numEdges;
    cin >> numVertices >> numEdges;

    vector<vector<Edge>> graph(numVertices);

    for (int i = 0; i < numEdges; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        // 양방향 그래프이므로 u에서 v로 가는 간선과 v에서 u로 가는 간선을 추가

        graph[u-1].push_back({ v-1, w }); // 아 이거 거리는 제대로 저장하고 나머지만 -1
        graph[v-1].push_back({ u-1, w });
    }

    // 시작 정점을 1로 설정  -> 근데 이거 0으로 바꿔야될듯?
    int startVertex = 0;

    vector<int> previous = firstDijkstra(graph, startVertex);

    int lastVertex = numVertices - 1;

   // cout << "Shortest path from vertex " << startVertex << " to vertex " << lastVertex << ": " << endl;
   // cout << "\n최단거리는" << result<<"\n"; // 최단거리 테스트 성공
    
   
   // 일단 여기서 추가할거
    //1. previous 값 하나 하나뽑으며 그 경로 지워보고 실행하고 복구하고 다음값하고 하면됨
    //2. 그리고 최단 경로 이미 뽑힌건 별도로 저장하든 어카든 고민 ㄲ(빼기 전 값, 빼고나서 고려해서 판 짜봅시다)
    

    stack<int> path;
    int currentVertex = lastVertex;

    while (currentVertex != startVertex) {
        path.push(currentVertex);
        currentVertex = previous[currentVertex];
    }

    path.push(startVertex);

    // 자 이제 스택에는 경로가 담겨있다 ^^ㅣ발

    int end = path.size() - 1;
    for (int i = 0; i <end; i++) {
        // 자 스택 크기-1 만큼 돌아가고, top이랑 pop으로 뽑아쓰면되고

        int first = path.top();  // 첫번째 노드 (역순 노상관)
        path.pop();
        int second = path.top(); // 두번째 노드

        // 시작점은 쓰고 버리고 두번째는 다음에도 써야됨 ㅇㅋ?
       // cout << first << " 랑  " << second << "차례(0부터 기준)\n";

        Edge forFirst;

        forFirst.to = -1;    // 'to' 멤버 변수에 10 대입
        forFirst.weight = -1; // 'weight' 멤버 변수에 20 대입

        Edge forSecond;
        forSecond.to = -1;    // 'to' 멤버 변수에 10 대입
        forSecond.weight = -1; // 'weight' 멤버 변수에 20 대입


        for (int k = 0; k < graph[first].size(); k++) {

            if (graph[first][k].to == second) {
                // 'to' 값이 10인 경우 해당 구조체 삭제
                forFirst = graph[first][k];
                graph[first].erase(graph[first].begin() + k);
            }
        }


        for (int k = 0; k < graph[second].size(); k++) {

            if (graph[second][k].to == first) {
                // 'to' 값이 10인 경우 해당 구조체 삭제
                forSecond = graph[second][k];
                graph[second].erase(graph[second].begin() + k);
            }
        }

        //이제 프리비어스 두 값, 해당 값끼리의 연결 지웠음
        // 이제 다익스트라 호출해서 그 함수 내부에 전역변수 비교 조지고 (큰값 넣고)
       // 다시 원상복구 시키면됨


        //여기 다익스트라
  
        dijkstra(graph, startVertex);

    //    cout << "이거 두개 지웠다 생성함" << forSecond.to << "  " << forFirst.to << "\n";


        graph[first].push_back(forFirst);
        graph[second].push_back(forSecond);
        
    }

  //  cout << "이제 본게임, 결과값은? (결국 최종거리)  " << result<<"\n";
    cout << result;


    //이건 역순 좌표 역으로 뽑아보는 역할



    /*
    while (!path.empty()) {
        cout << path.top() << " ";
        path.pop();
    }

    cout << endl;
    */
    return 0;
}
