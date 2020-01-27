#include <iostream>
#include <queue>
#include <string>

using namespace std;

int r, c;  // ������ ��� ���� ��
char field[251][251];  // ���� ����
bool visited[251][251];  // �� ���� ��ǥ �湮 ����

const int dx[4] = { -1,1,0,0 };
const int dy[4] = { 0,0,-1,1 };

int bfs(int sx, int sy) {
	queue<pair<int, int> > q;
	int o = 0, v = 0;  // ���� ������ ��, ���� ��

	q.push(make_pair(sx, sy));
	visited[sx][sy] = true;

	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		if (field[x][y] == 'o') o++;
		else if (field[x][y] == 'v') v++;

		// ��� Ž��
		for (int dir = 0; dir < 4; dir++) {
			int nx = x + dx[dir];
			int ny = y + dy[dir];

			// ���� üũ
			if (nx < 0 || nx >= r || ny < 0 || ny >= c 
					|| visited[nx][ny] || field[nx][ny] == '#')
				continue;

			visited[nx][ny] = true;
			q.push(make_pair(nx, ny));
		}
	}

	// ����̸� ����ִ� ���� ��
	// �����̸� ����ִ� ������ ��
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
	// ���� ��ü Ž���ϸ鼭 ���� �湮���� ���� ���� bfs ����
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