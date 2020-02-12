#include <iostream>
#include <algorithm>

using namespace std;

int n;  // 미로 길이
int maze[1001];  // 미로 상태
int cache[1001];
const int INF = 987654321;

int jump(int pt) {
	// base case : 미로 가장 오른쪽 끝에 도달하면 종료
	if (pt >= n - 1) return 0;

	// 메모이제이션
	int& ret = cache[pt];
	if (ret != -1) return ret;

	ret = INF;
	// 현재 칸에서 1 ~ (현재 칸에 적힌 정수)칸 만큼 점프 가능
	for (int i = 1; i <= maze[pt]; i++) {
		ret = min(ret, jump(pt + i) + 1);
	}

	return ret;
}

int main() {
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> maze[i];
		cache[i] = -1;  // 캐시 메모리 초기화
	}

	int res = jump(0);
	if (res == INF) res = -1;

	cout << res << endl;
	return 0;
}