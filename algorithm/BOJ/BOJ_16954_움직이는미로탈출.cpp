#include <iostream>
#include <string>
#include <queue>

using namespace std;

int n = 8;  // 체스판 크기
char map[8][8];  // 체스판 상태

const int dx[9] = { -1,-1,-1,0,0,1,1,1,0 };
const int dy[9] = { -1,0,1,-1,1,-1,0,1,0 };

bool bfs(int sx, int sy) {
	queue<pair<pair<int, int>, int> > q;  // (좌표, 도착한 시간)
	q.push(make_pair(make_pair(sx, sy), 0));

	while (!q.empty()) {
		int x = q.front().first.first;
		int y = q.front().first.second;
		int t = q.front().second;
		q.pop();

		// 좌상, 상, 우상, 우 방향으로 이동하거나
		// 현재 위치에 그대로 있는다
		for (int dir = 0; dir < 9; dir++) {
			int nx = x + dx[dir];
			int ny = y + dy[dir];

			// 범위 체크
			if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;

			// 다음위치에 벽이 있거나 그 위에 벽이 있으면 이동 불가
			if ((nx - t - 1 >= 0 && map[nx - t - 1][ny] == '#') ||
				(nx - t >= 0 && map[nx - t][ny] == '#'))
				continue;

			// 다음 위치가 마지막 위치이면 탈출 성공
			if (nx == 0 && ny == n - 1) return true;

			// 다음 위치로 이동
			q.push(make_pair(make_pair(nx, ny), t + 1));
		}
	}
	return false;
}

int main() {
	for (int i = 0; i < n; i++) {
		string input;
		cin >> input;
		for (int j = 0; j < n; j++) {
			map[i][j] = input[j];
		}
	}

	bool res = bfs(n - 1, 0);

	if (res) cout << "1\n";
	else cout << "0\n";
	return 0;
}