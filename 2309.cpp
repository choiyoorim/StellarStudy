#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define N 9

int find_who(vector<int> &height, int sum) {
	for (int i = 0; i < N - 1; i++) {
		for (int j = 1; j < N; j++) {
			int choose = height[i] + height[j];
			if (sum - choose == 100) {
				height[i] = -1;
				height[j] = -1;
				return 0;
			}
		}
	}
	return 1;
}


int main() {
	vector<int> height;
	int sum = 0;
	for (int i = 0; i < N; i++) {
		int num;
		cin >> num;
		sum += num;
		height.push_back(num);
	}
	if (!find_who(height, sum)) {
		sort(height.begin(), height.end());
	}

	for (int i = 2; i < height.size(); i++) {
		cout << height[i] << endl;
	}
}