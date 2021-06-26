//문자열 배열을 초기화해줘야함. 쓰레기값이 들어가면 문제 발생 가능.
#include <iostream>
using namespace std;

int main() {
	char s[101] = { 0 };
	int num[26];
	cin >> s;
	for (int i = 0; i < 26; i++) {
		int j;
		for (j = 0; j < 101; j++) {
			if (s[j] == (i+97)) {
				num[i] = j;
				break;
			}
		}
		if (j == 101) {
			num[i] = -1;
		}
	}

	for (int i = 0; i < 26; i++) {
		cout << num[i] << " ";
	}

	return 0;
}