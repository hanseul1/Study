#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int d, w;  // 보호필름 두께, 가로크기
int film[14][21];  // 보호필름 단면 정보
int k;  // 합격 기준
int res;

bool checking() {
	// 각 열별로 검사
	for (int j = 0; j < w; j++) {
		bool isValid = false;
		int cnt = 1;  // 연속된 셀의 개수
		int prev = film[0][j];  // 첫번째 셀의 특성
		for (int i = 1; i < d; i++) {
			if (prev == film[i][j]) cnt++;
			else {
				prev = film[i][j];
				cnt = 1;
			}

			// 셀이 k개 연속되면 현재 열 검사 통과
			if (cnt == k) {
				isValid = true;
				break;
			}
		}

		// 현재 열이 k개 이상 셀이 연속되지 않았으면 false 리턴
		if (!isValid) return false;
	}

	// 모든 열이 검사 통과했으면 true 리턴
	return true;
}

void injecting(int pt, int cnt) {
	// 현재까지 구한 최솟값보다 크거나 같으면 더이상 계산하지 않고 종료
	if (cnt >= res) return;

	// 약품 투입이 끝났으면 성능 검사
	if (pt == d) {
		if (checking()) res = min(res, cnt);
		return;
	}

	// 약품을 투입하지 않는 경우
	injecting(pt + 1, cnt);

	int temp[21];
	// 현재 막에 약품 A 투입
	for (int i = 0; i < w; i++) {
		temp[i] = film[pt][i];  // 기존 필름 정보 저장
		film[pt][i] = 0;
	}
	injecting(pt + 1, cnt + 1);

	// 현재 막에 약품 B 투입
	for (int i = 0; i < w; i++) {
		film[pt][i] = 1;
	}
	injecting(pt + 1, cnt + 1);

	// 원래 필름 정보로 복구
	for (int i = 0; i < w; i++) {
		film[pt][i] = temp[i];
	}
}

int main() {
	int t;
	cin >> t;

	for (int test = 1; test <= t; test++) {
		cin >> d >> w >> k;

		for (int i = 0; i < d; i++) {
			for (int j = 0; j < w; j++) {
				cin >> film[i][j];
			}
		}

		res = d;  // 약품은 최대 d번 투입할 수 있다.
		injecting(0, 0);

		cout << "#" << test << " " << res << "\n";
	}
	return 0;
}
