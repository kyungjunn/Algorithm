#include <iostream>
#include <queue>
#include <vector>

using namespace std;

const int VertexCount = 6;
int AdjacencyMatrix[VertexCount][VertexCount] =
{
	{ 0, 1, 0, 1, 0, 0 },
	{ 1, 0, 1, 1, 0, 0 },
	{ 0, 1, 0, 0, 0, 0 },
	{ 1, 1, 0, 0, 1, 0 },
	{ 0, 0, 0, 1, 0, 1 },
	{ 0, 0, 0, 0, 1, 0 }
};

bool Visited[VertexCount];
int Distance[VertexCount];
int Parent[VertexCount];

void PrintShortestPath(int Start, int Dest)
{
	if (Visited[Dest] == false)
	{
		cout << "목적지 이동 X";
		return;
	}

	// 0->3->4->5
	vector<int> Temp;

	int Current = Dest;

	while (Current != Start)
	{
		Temp.push_back(Current);
		Current = Parent[Current];
	}
	Temp.push_back(Start);


	// 역순
	for (int i = Temp.size() - 1; i >= 0; --i)
	{
		cout << Temp[i];
		if (i > 0)
		{
			cout << "->";
		}
	}
	cout << endl;

}
void BFS(int Start)
{
	// 예약 목록
	std::queue<int> VertexQueue;
	VertexQueue.push(Start); // 시작지점 예약
	Visited[Start] = true; // 방문 

	Parent[Start] = Start;
	Distance[Start] = 0;

	// 큐가 비어있지 않다면
	while (!VertexQueue.empty())
	{
		int Current = VertexQueue.front(); // 가장 오래 예약한 놈
		VertexQueue.pop();

		// 현재 정점과 연결 + 방문 안한놈 찾기
		for (int Next = 0; Next < VertexCount; ++Next)
		{
			if (AdjacencyMatrix[Current][Next] == 0)
			{
				continue;
			}
			if (Visited[Next] == true)
			{
				continue;
			}

			VertexQueue.push(Next); // 예약 걸기
			Visited[Next] = true;
			Parent[Next] = Current;
			Distance[Next] = Distance[Current] + 1;
		}
	}


}
int main()
{
	BFS(0);

	PrintShortestPath(0, 5);

	return 0;
}