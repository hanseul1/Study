#include <iostream>
#include <queue>
#include <map>

using namespace std;

// 1 2 3
// 4 5 6
// 7 8 9  => 숫자 123456789로 나타냄

int board[3][3];  // 현재 표에 채워져있는 상태
// 표 상태를 숫자로 만들기 위해 각 좌표의 숫자에 곱해줄 값
int mul[3][3] = { {100000000, 10000000, 1000000},
				  {100000, 10000, 1000},
				  {100,10,1} };
map<int, int> visited;  // 각 표의 상태 방문 순서

const int dx[4] = { -1,1,0,0 };
const int dy[4] = { 0,0,-1,1 };

int bfs(int start, int sx, int sy) {
	queue<pair<int, pair<int, int> > > q;  // (표 상태, 빈칸 좌표)
	q.push(make_pair(start, make_pair(sx, sy)));
	visited[start] = 0;

	while (!q.empty()) {
		int here = q.front().first;
		int x = q.front().second.first;
		int y = q.front().second.second;
		int move = visited[here];
		q.pop();

		// 빈칸의 상하좌우 칸의 숫자 이동
		for (int dir = 0; dir < 4; dir++) {
			int nx = x + dx[dir];
			int ny = y + dy[dir];

			// 범위 체크
			if (nx < 0 || nx >= 3 || ny < 0 || ny >= 3) continue;

			// 이동했을 때 표의 상태 계산
			int nextNum = (here / mul[nx][ny]) % 10;
			int next = here - nextNum * mul[nx][ny] - 9 * mul[x][y]
							+ nextNum * mul[x][y] + 9 * mul[nx][ny];

			// 아직 방문하지 않았으면 이동
			if (visited.count(next) == 0) {
				if (next == 123456789) return move + 1;
				visited[next] = move + 1;
				q.push(make_pair(next, make_pair(nx, ny)));
			}
		}
	}
	return -1;
}

int main() {
	int init = 0;
	int sx = 0, sy = 0;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			cin >> board[i][j];
			if (board[i][j] == 0) {
				sx = i;
				sy = j;
				board[i][j] = 9;
			}
			init += board[i][j] * mul[i][j];
		}
	}

	int res = 0;
	if (init != 123456789) res = bfs(init, sx, sy);

	cout << res << endl;
	return 0;
}