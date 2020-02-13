#include <iostream>
#include <queue>
#include <string>

using namespace std;

int n, m;  // 미로 크기
char map[51][51];  // 미로 모양
int visited[51][51][65];  // 각 좌표 방문한 순서(열쇠 정보에 따라 저장)

const int INF = 987654321;
const int dx[4] = { -1,1,0,0 };
const int dy[4] = { 0,0,-1,1 };

int escape(int sx, int sy) {
	queue<pair<pair<int, int>, int> > q;  // (위치 좌표, 가지고 있는 열쇠 정보)
	q.push(make_pair(make_pair(sx, sy), 0));
	visited[sx][sy][0] = 0;

	while (!q.empty()) {
		int x = q.front().first.first;
		int y = q.front().first.second;
		int key = q.front().second;
		q.pop();

		// 인접한 4방향으로 이동
		for (int dir = 0; dir < 4; dir++) {
			int nx = x + dx[dir];
			int ny = y + dy[dir];

			// 범위 체크 및 벽 체크
			if (nx < 0 || nx >= n || ny < 0 || ny >= m || map[nx][ny] == '#') continue;

			// 다음 위치가 출구라면 탈출 가능
			if (map[nx][ny] == '1') return visited[x][y][key] + 1;

			// 다음 위치가 문이라면 열쇠있는지 확인
			else if (map[nx][ny] >= 'A' && map[nx][ny] <= 'F') {
				int door = map[nx][ny] - 'A';
				int result = ((key >> door) & 1);
				if (result != 1) continue;

				if (visited[nx][ny][key] > visited[x][y][key] + 1) {
					visited[nx][ny][key] = visited[x][y][key] + 1;
					q.push(make_pair(make_pair(nx, ny), key));
				}
			}

			// 다음 위치가 빈 곳 또는 열쇠이기 때문에 이동 가능
			else {
				// 열쇠 있을 때
				if (map[nx][ny] >= 'a' && map[nx][ny] <= 'f') {
					int k = map[nx][ny] - 'a';
					int nkey = key | (1 << k);

					if (visited[nx][ny][nkey] > visited[x][y][key] + 1) {
						visited[nx][ny][nkey] = visited[x][y][key] + 1;
						q.push(make_pair(make_pair(nx, ny), nkey));
					}
				}
				else {
					if (visited[nx][ny][key] > visited[x][y][key] + 1) {
						visited[nx][ny][key] = visited[x][y][key] + 1;
						q.push(make_pair(make_pair(nx, ny), key));
					}
				}
			}
		}
	}

	return -1;
}

int main() {
	int sx, sy;  // 시작 위치

	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		string input;
		cin >> input;
		for (int j = 0; j < m; j++) {
			map[i][j] = input[j];

			// 시작 위치 저장
			if (map[i][j] == '0') {
				sx = i, sy = j;
				map[i][j] = '.';
			}
		}
	}

	// visited 배열 초기화
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			for (int k = 0; k < 65; k++) {
				visited[i][j][k] = INF;
			}
		}
	}

	int res = escape(sx, sy);
	cout << res << "\n";
	return 0;
}