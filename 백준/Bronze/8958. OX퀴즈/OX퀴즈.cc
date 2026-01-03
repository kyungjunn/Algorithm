#include <iostream>
#include <string>
using namespace std;

int main() {
	int T;
	string s;

	cin >> T;
	for (int i = 0; i < T; i++) 
    {
		cin >> s;
		int sum, cnt;
		sum = cnt = 0;
		for (int j = 0; j < s.length(); j++) 
        {
			if (s[j] == 'O') 
            {
                cnt++;
            }
			else
            {
                cnt = 0;
            } 
			sum += cnt;
		}
		cout << sum << "\n";
  	}
}