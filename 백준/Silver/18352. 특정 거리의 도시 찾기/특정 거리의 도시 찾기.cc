#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int n, m, k, x;
vector<int> visited; // 몇 번째 방문한 곳인지 계산하는 벡터
vector<int> result; // 결과 출력 도시 벡터
vector<vector<int>> v; // 입력받은 도시 정보 벡터

void bfs(int city)
{
    queue<int> q;
    q.push(city);
    visited[city] = 0;

    while (!q.empty()) // 큐가 빌 때까지
    {
        int now = q.front();
        q.pop(); // 맨 앞 도시 저장 후 pop

        for (int i = 0; i < v[now].size(); i++) // 현재 방문한 도시와 연결 되어 있는 도시의 수 만큼
        {
            if (v[now][i] == city) continue;
            if (visited[v[now][i]] == 0)
            {
                q.push(v[now][i]);
                visited[v[now][i]] = visited[now] + 1;
              
                if (visited[v[now][i]] == k)
                {
                    result.push_back(v[now][i]);
                }
            }
        }
    }
}

int main(void)
{
    int n1, n2;
    cin >> n >> m >> k >> x;
    // 도시 개수에 따라 resize -> 0번 도시는 없기 때문
    v.resize(n + 1);
    visited.resize(n + 1);

    for (int i = 0; i < m; ++i)
    {
        cin >> n1 >> n2;
        v[n1].push_back(n2);
    }

    bfs(x);

    sort(result.begin(), result.end());

    if (result.empty())
        cout << -1;
    else
    {
        for (int var : result)
            cout << var << '\n';
    }

    return 0;
}