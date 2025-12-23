#include <iostream>
using namespace std;

int main()
{
    int A, B;
    cin >> A >> B;
    if (A < 0)
      cout << "잘못된 A를 입력하였습니다.";
    else if (B > 10)
      cout << "잘못된 B를 입력하였습니다.";
    else 
      cout << A + B;
}
