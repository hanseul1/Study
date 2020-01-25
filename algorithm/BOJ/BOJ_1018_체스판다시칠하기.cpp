#include <iostream>
#include <algorithm>
#include <string>
#include <queue>

using namespace std;

int n, m;  // 보드의 크기
char board[51][51];  // 초기 보드의 상태

const int INF = 987654321;
const int dx[4] = { -1,1,0,0 };
const int dy[4] = { 0,0,-1,1 };

// (sx,sy)에서 시작하는 8*8 체스판을 다시 색칠한다.
// 첫 좌표의 색은 color
int painting(int sx, int sy, char color) {
	char temp[51][51];  // 다시 칠한 체스판 상태
	for (int i = sx; i < sx + 8; i++) {
		for (int j = sy; j < sy + 8; j++) {
			temp[i][j] = '.';
		}
	}
	
	queue<pair<int, int> > q;
	int ret = (board[sx][sy] == color) ? 0 : 1;
	temp[sx][sy] = color;
	q.push(make_pair(sx, sy));
	char other = (color == 'W') ? 'B' : 'W';

	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		// 상하좌우 칸 탐색
		for (int dir = 0; dir < 4; dir++) {
			int nx = x + dx[dir];
			int ny = y + dy[dir];

			// 범위 및 방문 체크
			if (nx < sx || nx >= sx + 8 || ny < sy || ny >= sy + 8 || temp[nx][ny] != '.')
				continue;

			// 현재 칠해진 체스판의 (x,y)칸과 원래 보드의 (nx,ny)칸이 같은색이면 다시칠함
			if (temp[x][y] == board[nx][ny]) ret++;

			temp[nx][ny] = (temp[x][y] == color) ? other : color;
			q.push(make_pair(nx, ny));
		}
	}

	return ret;
}

int main() {
	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		string input;
		cin >> input;
		for (int j = 0; j < m; j++) {
			board[i][j] = input[j];
		}
	}

	int res = INF;
	for (int i = 0; i <= n - 8; i++) {
		for (int j = 0; j <= m - 8; j++) {
			int cand = min(painting(i, j, 'W'), painting(i, j, 'B'));
			res = min(res, cand);
		}
	}

	cout << res << "\n";
	return 0;
}