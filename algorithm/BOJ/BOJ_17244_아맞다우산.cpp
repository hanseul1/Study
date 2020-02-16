#include <iostream>
#include <queue>
#include <string>
#include <math.h>

using namespace std;

int n, m;  // 집의 크기
char home[51][51];  // 집의 구조
int sx, sy;  // 출발 위치
int visited[51][51][33];  // 각 위치에 방문한 시간(물건 챙긴 상태에 따라 저장)

const int INF = 987654321;
const int dx[4] = { -1,1,0,0 };
const int dy[4] = { 0,0,-1,1 };

int bfs(int stuff) {
	queue<pair<pair<int, int>, int> > q;  // (좌표, 물건 챙긴 상태)
	int complete = pow(2, stuff) - 1;  // 모든 물건 챙겼을 때 상태

	visited[sx][sy][0] = 0;
	q.push(make_pair(make_pair(sx, sy), 0));
	
	while (!q.empty()) {
		int x = q.front().first.first;
		int y = q.front().first.second;
		int s = q.front().second;
		q.pop();
		
		// 상하좌우 인접한 칸으로 이동
		for (int dir = 0; dir < 4; dir++) {
			int nx = x + dx[dir];
			int ny = y + dy[dir];
			int ns = s;

			// 범위 및 벽 체크
			if (nx < 0 || nx >= m || ny < 0 || ny >= n || home[nx][ny] == '#') continue;

			// 다음 칸이 나가는 문이고, 모든 물건을 챙겼다면 외출 가능
			if (home[nx][ny] == 'E' && s == complete) return visited[x][y][s] + 1;

			// 다음 칸이 물건이면 물건 챙기기
			if (home[nx][ny] >= '0' && home[nx][ny] < '0' + stuff) {
				int stuffNum = home[nx][ny] - '0';
				ns = s | (1 << stuffNum);
			}

			if (visited[nx][ny][ns] > visited[x][y][s] + 1) {
				visited[nx][ny][ns] = visited[x][y][s] + 1;
				q.push(make_pair(make_pair(nx, ny), ns));
			}
		}
	}
	return 0;
}

int main() {
	cin >> n >> m;

	char stuff = '0';
	for (int i = 0; i < m; i++) {
		string input;
		cin >> input;

		for (int j = 0; j < n; j++) {
			home[i][j] = input[j];

			if (home[i][j] == 'X') {
				home[i][j] = stuff;
				stuff++;
			}
			else if (home[i][j] == 'S') {
				sx = i, sy = j;
				home[i][j] = '.';
			}
		}
	}

	// visited 배열 초기화
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			for (int k = 0; k < 33; k++) {
				visited[i][j][k] = INF;
			}
		}
	}

	int res = bfs(stuff - '0');
	cout << res << "\n";
	return 0;
}