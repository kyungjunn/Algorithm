#include <iostream>
using namespace std;

int main()
{
    int n, m;
    int min = 0;
    cin >> n >> m;
    
    if(n > 0)
    {
        if (m < 10)
        {
            min = n - m;
        }
    }
    else
    {
        cout << "잘못된 연산입니다.";
    }
    cout << min;
    return 0;
}