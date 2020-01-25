#include <iostream>
#include <string>
#include <math.h>

using namespace std;

int n, m;  // 게임판의 크기
char board[51][51];  // 게임판의 상태
bool visited[51][51];  // 각 좌표의 방문 여부
int sx, sy;  // dfs 시작점
bool res;

const int dx[4] = { -1,1,0,0 };
const int dy[4] = { 0,0,-1,1 };

void dfs(int x, int y, int cnt) {
	if (res) return;

	// 시작점으로 돌아왔다면 사이클 존재
	if (x == sx && y == sy && visited[sx][sy]) {
		res = true;
		return;
	}

	// 상하좌우 방향으로 이동 가능
	for (int dir = 0; dir < 4; dir++) {
		int nx = x + dx[dir];
		int ny = y + dy[dir];

		// 범위 체크
		if (nx < 0 || nx >= n || ny < 0 || ny >= m || visited[nx][ny]) continue;

		// 같은 색이면 이동
		if (board[nx][ny] == board[x][y] && (nx != sx || ny != sy || cnt >= 2)) {
			visited[nx][ny] = true;
			dfs(nx, ny, cnt + 1);
			visited[nx][ny] = false;
		}
	}
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

	// 사이클의 시작점 선택
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			sx = i;
			sy = j;
			dfs(i, j, 0);
			if (res) break;
		}
		if (res) break;
	}

	if (res) cout << "Yes\n";
	else cout << "No\n";
	return 0;
}