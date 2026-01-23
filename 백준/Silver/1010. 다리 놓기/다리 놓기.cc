#include <iostream>

using namespace std;

int T, N, M;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> T;
    for (int i = 0; i < T; i++)
    {
        cin >> N >> M;

        long result = 1;
        int k = 1;

        for (int j = M; j > M - N; j--) // j는 M부터 (M-N+1)까지 반복 (총 N번)
        {
            result *= j; // 분자 값을 하나씩 곱함
            result /= k; // 분모 값을 하나씩 나눔
            k++;
        }

        cout << result << "\n";
    }
    return 0;
}