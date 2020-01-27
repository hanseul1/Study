#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

int n, m;  // 성의 크기
int map[101][101];  // 성의 구조
int t;  // 제한 시간
int visited[101][101][2];  // 각 위치에 도착하는 최소 시간

const int INF = 987654321;
const int dx[4] = { -1,1,0,0 };
const int dy[4] = { 0,0,-1,1 };

int bfs(int sx, int sy) {
	priority_queue<pair<pair<int, int>, pair<int, int> > > q;  // ((도달 시간, 그람 유무), 좌표)
	q.push(make_pair(make_pair(0, 0), make_pair(sx, sy)));
	visited[sx][sy][0] = 0;

	while (!q.empty()) {
		int x = q.top().second.first;
		int y = q.top().second.second;
		int time = -q.top().first.first;
		int g = q.top().first.second;
		q.pop();

		if (visited[x][y][g] < time) continue;

		// 상하좌우 탐색
		for (int dir = 0; dir < 4; dir++) {
			int nx = x + dx[dir];
			int ny = y + dy[dir];

			// 범위 체크
			if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;

			// 현재 위치가 벽인데 그람이 없는 경우 이동 불가
			if (map[nx][ny] == 1 && !g) continue;

			// 현재 위치에 그람이 있는 경우
			if (map[nx][ny] == 2 && visited[nx][ny][1] == INF) {
				visited[nx][ny][1] = time + 1;
				q.push(make_pair(make_pair(-time - 1, 1), make_pair(nx, ny)));
			}

			// 다음 위치로 도달하는 시간이
			// 지금까지 구한 최소 시간보다 작으면 이동
			if (visited[nx][ny][g] > time + 1) {
				visited[nx][ny][g] = time + 1;
				q.push(make_pair(make_pair(-time - 1, g), make_pair(nx, ny)));
			}
		}
	}

	return min(visited[n - 1][m - 1][0], visited[n - 1][m - 1][1]);
}

int main() {
	cin >> n >> m >> t;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> map[i][j];
		}
	}

	// visited 배열 초기화
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			for (int k = 0; k < 2; k++) {
				visited[i][j][k] = INF;
			}
		}
	}

	int res = bfs(0, 0);
	if (res <= t) cout << res << "\n";
	else cout << "Fail\n";

	return 0;
}