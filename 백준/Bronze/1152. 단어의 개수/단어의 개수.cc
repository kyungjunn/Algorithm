#include <iostream>
#include <string> // getline()

using namespace std;

int main() {

	string s;
	int cnt = 1;

	getline(cin, s); // getline을 통해 공백이 포함된 문자열을 입력받을 수 있음.

	if (s.length() == 1 && s[0] == ' ') {
		cout << 0;
		return 0;
	}

	for (int i = 1; i < s.length() - 1; i++) {
		if (s[i] == ' ') 
        {
            cnt++;
        }
	}

	cout << cnt;

	return 0;
}