#include <iostream>
using namespace std;
#define Max 1000000

int arr[Max+1];
int main()
{
  // 소수 구하기
  for(int i = 2; i<Max; i++)
    {
      arr[i] = i;
    }
  for(int i = 2; i < Max; i++)
    {
      for(int j = 2; i * j < Max; j++)
        {
          arr[i*j] = 0;
        }
    }

  // 테스트 케이스 입력
  int n; 
  cin >> n;

  while(n--)
    {
      // 숫자 입력
      int N;
      cin >> N;

      int count = 0;
      for(int i = 2; i <= N/2; i++)
        {
          if(arr[i] && arr[N - i])
          {
            count++;
          }
        }
      cout << count << endl;
    }
  return 0;
}