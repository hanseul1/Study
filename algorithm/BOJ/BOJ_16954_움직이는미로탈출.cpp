#include <iostream>
#include <string>
#include <queue>

using namespace std;

int n = 8;  // ü���� ũ��
char map[8][8];  // ü���� ����

const int dx[9] = { -1,-1,-1,0,0,1,1,1,0 };
const int dy[9] = { -1,0,1,-1,1,-1,0,1,0 };

bool bfs(int sx, int sy) {
	queue<pair<pair<int, int>, int> > q;  // (��ǥ, ������ �ð�)
	q.push(make_pair(make_pair(sx, sy), 0));

	while (!q.empty()) {
		int x = q.front().first.first;
		int y = q.front().first.second;
		int t = q.front().second;
		q.pop();

		// �»�, ��, ���, �� �������� �̵��ϰų�
		// ���� ��ġ�� �״�� �ִ´�
		for (int dir = 0; dir < 9; dir++) {
			int nx = x + dx[dir];
			int ny = y + dy[dir];

			// ���� üũ
			if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;

			// ������ġ�� ���� �ְų� �� ���� ���� ������ �̵� �Ұ�
			if ((nx - t - 1 >= 0 && map[nx - t - 1][ny] == '#') ||
				(nx - t >= 0 && map[nx - t][ny] == '#'))
				continue;

			// ���� ��ġ�� ������ ��ġ�̸� Ż�� ����
			if (nx == 0 && ny == n - 1) return true;

			// ���� ��ġ�� �̵�
			q.push(make_pair(make_pair(nx, ny), t + 1));
		}
	}
	return false;
}

int main() {
	for (int i = 0; i < n; i++) {
		string input;
		cin >> input;
		for (int j = 0; j < n; j++) {
			map[i][j] = input[j];
		}
	}

	bool res = bfs(n - 1, 0);

	if (res) cout << "1\n";
	else cout << "0\n";
	return 0;
}