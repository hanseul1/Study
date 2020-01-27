#include <iostream>
#include <queue>
#include <string>

using namespace std;

int r, c;  // 마당의 행과 열의 수
char field[251][251];  // 마당 상태
bool visited[251][251];  // 각 마당 좌표 방문 여부

const int dx[4] = { -1,1,0,0 };
const int dy[4] = { 0,0,-1,1 };

int bfs(int sx, int sy) {
	queue<pair<int, int> > q;
	int o = 0, v = 0;  // 현재 영역의 양, 늑대 수

	q.push(make_pair(sx, sy));
	visited[sx][sy] = true;

	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		if (field[x][y] == 'o') o++;
		else if (field[x][y] == 'v') v++;

		// 사방 탐색
		for (int dir = 0; dir < 4; dir++) {
			int nx = x + dx[dir];
			int ny = y + dy[dir];

			// 범위 체크
			if (nx < 0 || nx >= r || ny < 0 || ny >= c 
					|| visited[nx][ny] || field[nx][ny] == '#')
				continue;

			visited[nx][ny] = true;
			q.push(make_pair(nx, ny));
		}
	}

	// 양수이면 살아있는 양의 수
	// 음수이면 살아있는 늑대의 수
	if (o > v) return o;
	else return -v;
}

int main() {
	cin >> r >> c;

	for (int i = 0; i < r; i++) {
		string input;
		cin >> input;

		for (int j = 0; j < c; j++) {
			field[i][j] = input[j];
		}
	}

	int ores = 0;
	int vres = 0;
	// 마당 전체 탐색하면서 아직 방문하지 않은 영역 bfs 수행
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			if (field[i][j] != '#' && !visited[i][j]) {
				int result = bfs(i, j);
				if (result > 0) ores += result;
				else vres += (-result);
			}
		}
	}

	cout << ores << " " << vres << "\n";
	return 0;
}