#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int n; // 보드의 크기
char board[51][51];  // 보드에 채워져있는 사탕 색상

void changePos(int x1, int y1, int x2, int y2) {
	char temp = board[x1][y1];
	board[x1][y1] = board[x2][y2];
	board[x2][y2] = temp;
}

int candy() {
	int ret = 1;

	for (int i = 0; i < n; i++) {
		int rcnt = 1;  // 행 검사
		int ccnt = 1;  // 열 검사
		char rprev = board[i][0];
		char cprev = board[0][i];
		for (int j = 1; j < n; j++) {
			if (board[i][j] == rprev) rcnt++;
			else {
				rprev = board[i][j];
				ret = max(ret, rcnt);
				rcnt = 1;
			}

			if (board[j][i] == cprev) ccnt++;
			else {
				cprev = board[j][i];
				ret = max(ret, ccnt);
				ccnt = 1;
			}
		}
		ret = max(ret, rcnt);
		ret = max(ret, ccnt);
	}

	return ret;
}

int main() {
	cin >> n;

	for (int i = 0; i < n; i++) {
		string input;
		cin >> input;

		for (int j = 0; j < n; j++) {
			board[i][j] = input[j];
		}
	}

	int res = 0;

	// 인접한 열 두칸 골라서 사탕 위치 바꿈(ㅇㅇ)
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n - 1; j++) {
			if (board[i][j] == board[i][j + 1]) continue;
			changePos(i, j, i, j + 1);

			// 현재 보드에서 연속된 같은 사탕개수 구함
			res = max(res, candy());

			// 바꾼 사탕 원상 복구
			changePos(i, j, i, j + 1);
		}
	}

	// 인접한 행 두칸 골라서 사탕 위치 바꿈(8)
	for (int j = 0; j < n; j++) {
		for (int i = 0; i < n - 1; i++) {
			if (board[i][j] == board[i + 1][j]) continue;
			changePos(i, j, i + 1, j);
			res = max(res, candy());
			changePos(i, j, i + 1, j);
		}
	}

	cout << res << "\n";
	return 0;
}