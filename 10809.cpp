//���ڿ� �迭�� �ʱ�ȭ�������. �����Ⱚ�� ���� ���� �߻� ����.
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