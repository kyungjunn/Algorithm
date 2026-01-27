#include <iostream>
#include <queue>
using namespace std;

int N, M; // N: 가로(열), M: 세로(행)
int map[310][310];
bool check[310][310];

// 아래(행+1), 오른쪽(열+1)
int dx[2] = { 1, 0 }; 
int dy[2] = { 0, 1 };

bool bfs() {
    queue<pair<int, int>> q;
    check[1][1] = true;
    q.push({ 1, 1 });

    while (!q.empty()) {
        int r = q.front().first;  // 현재 행 (1~M)
        int c = q.front().second; // 현재 열 (1~N)
        q.pop();

        // 도착지점: M행 N열
        if (r == M && c == N) return true;

        for (int i = 0; i < 2; i++) {
            int nr = r + dx[i];
            int nc = c + dy[i];

            // 경계 조건: 행은 M 이하, 열은 N 이하
            if (nr >= 1 && nr <= M && nc >= 1 && nc <= N) {
                if (map[nr][nc] == 1 && !check[nr][nc]) {
                    check[nr][nc] = true;
                    q.push({ nr, nc });
                }
            }
        }
    }
    return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> M; // 가로 N, 세로 M
    for (int i = 1; i <= M; i++) { // M개의 줄(행)
        for (int j = 1; j <= N; j++) { // 각 줄에 N개의 숫자(열)
            cin >> map[i][j];
        }
    }

    if (bfs()) cout << "Yes";
    else cout << "No";

    return 0;
}