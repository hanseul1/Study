#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <string>

using namespace std;

int w, h;  // 정사각형 크기
char map[101][101];  // 주어진 지도
vector<pair<int, int> > C;  // C의 위치
int visited[101][101][4];  // 각 좌표에 해당방향으로 레이저가 도달하는 최소 거울 수

const int dx[4] = { -1,1,0,0 };
const int dy[4] = { 0,0,-1,1 };

void laser(int sx, int sy) {
	queue<pair<pair<int, int>, int> > q;  // (좌표, 현재 이동 방향)

	// 현재 위치에서 동서남북 방향 이동 동선 큐에 넣음
	for (int dir = 0; dir < 4; dir++) {
		q.push(make_pair(make_pair(sx, sy), dir));
		visited[sx][sy][dir] = 0;
	}

	while (!q.empty()) {
		int x = q.front().first.first;
		int y = q.front().first.second;
		int d = q.front().second;
		q.pop();

		// 동서남북 방향 이동
		for (int dir = 0; dir < 4; dir++) {
			int nx = x + dx[dir];
			int ny = y + dy[dir];

			// 이동 가능한 곳인지 확인
			if (nx < 0 || nx >= h || ny < 0 || ny >= w || map[nx][ny] == '*')
				continue;

			// 같은 방향 이동이면 거울 개수 유지
			// 90도 회전 이동이면 거울 개수 +1
			int mirror = (dir == d) ? visited[x][y][d] : visited[x][y][d] + 1;

			// 아직 방문하지 않았거나 
			// 지금까지 구한 최소 거울 개수보다 작아지면 갱신
			if (visited[nx][ny][dir] == -1 || visited[nx][ny][dir] > mirror) {
				visited[nx][ny][dir] = mirror;
				q.push(make_pair(make_pair(nx, ny), dir));
			}
		}
	}
}

int main() {
	cin >> w >> h;

	string temp;
	getline(cin, temp);
	for (int i = 0; i < h; i++) {
		string input;
		getline(cin, input);

		for (int j = 0; j < w; j++) {
			map[i][j] = input[j];

			if (map[i][j] == 'C')
				C.push_back(make_pair(i, j));
		}
	}

	// visited 배열 초기화
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			for (int k = 0; k < 4; k++) {
				visited[i][j][k] = -1;
			}
		}
	}

	laser(C[0].first, C[0].second);
	int fx = C[1].first;
	int fy = C[1].second;
	int res = 987654321;
	for (int i = 0; i < 4; i++) {
		if(visited[fx][fy][i] != -1)
			res = min(res, visited[fx][fy][i]);
	}
	cout << res << "\n";
	return 0;
}