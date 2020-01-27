#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

int n, m;  // ���� ũ��
int map[101][101];  // ���� ����
int t;  // ���� �ð�
int visited[101][101][2];  // �� ��ġ�� �����ϴ� �ּ� �ð�

const int INF = 987654321;
const int dx[4] = { -1,1,0,0 };
const int dy[4] = { 0,0,-1,1 };

int bfs(int sx, int sy) {
	priority_queue<pair<pair<int, int>, pair<int, int> > > q;  // ((���� �ð�, �׶� ����), ��ǥ)
	q.push(make_pair(make_pair(0, 0), make_pair(sx, sy)));
	visited[sx][sy][0] = 0;

	while (!q.empty()) {
		int x = q.top().second.first;
		int y = q.top().second.second;
		int time = -q.top().first.first;
		int g = q.top().first.second;
		q.pop();

		if (visited[x][y][g] < time) continue;

		// �����¿� Ž��
		for (int dir = 0; dir < 4; dir++) {
			int nx = x + dx[dir];
			int ny = y + dy[dir];

			// ���� üũ
			if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;

			// ���� ��ġ�� ���ε� �׶��� ���� ��� �̵� �Ұ�
			if (map[nx][ny] == 1 && !g) continue;

			// ���� ��ġ�� �׶��� �ִ� ���
			if (map[nx][ny] == 2 && visited[nx][ny][1] == INF) {
				visited[nx][ny][1] = time + 1;
				q.push(make_pair(make_pair(-time - 1, 1), make_pair(nx, ny)));
			}

			// ���� ��ġ�� �����ϴ� �ð���
			// ���ݱ��� ���� �ּ� �ð����� ������ �̵�
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

	// visited �迭 �ʱ�ȭ
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