#include <iostream>
#include <vector>

int Farm[50][50];
bool Visited[50][50];

const int DirectionY[4] = { -1, 1, 0, 0 };
const int DirectionX[4] = { 0, 0, -1, 1 };

using namespace std;

// 가로, 세로, 배추 갯수, 결과
int N, M, K, Result;

void DFS(int y, int x)
{
	Visited[y][x] = true;

	for (int dir = 0; dir < 4; ++dir)
	{
		int NextY = y + DirectionY[dir];
		int NextX = x + DirectionX[dir];

		if (NextY < 0 || NextY >= N ||
			NextX < 0 || NextX >= M)
		{
			continue;
		}

		if (Visited[NextY][NextX] || Farm[NextY][NextX] == 0)
		{
			continue;
		}

		DFS(NextY, NextX);
	}
}

int main()
{
	cin >> N >> M >> K;

	// 농장 초기화
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < M; ++j)
		{
			Farm[N][M] = 0;
		}
	}

	Result = 0;


	// 배추 심기
	for (int i = 0; i < K; ++i)
	{
		int X, Y;
		cin >> X >> Y;
		Farm[Y][X] = 1;
	}


	// DFS
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < M; ++j)
		{
			if (Farm[i][j] == 1 && !Visited[i][j])
			{
				DFS(i, j);
				Result++;
			}
		}
	}

	cout << "지렁이 : " << Result << endl;

	return 0;
}