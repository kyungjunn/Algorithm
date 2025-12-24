#include <iostream>
using namespace std;
#define Max 9

int N, M;
int arr[Max];
bool visited[Max];

void dfs(int depth)
{
    if (depth == M) 
    {
        for(int i = 0; i < M; i++)
        {
            cout << arr[i] << " ";
        }
        cout << "\n";
        return;
    }

    for (int i = 1; i <= N; i++)
    {
        if (!visited[i]) // 이 숫자를 쓴 적 없다면
        {
            visited[i] = true;
            arr[depth] = i;
            dfs(depth + 1); // 재귀호출
            visited[i] = false; // 백트래킹 -> 되돌리기
        } 
    }
}
int main()
{
    cin >> N >> M;
    dfs(0); // 0부터 dfs 시작
    return 0;
}