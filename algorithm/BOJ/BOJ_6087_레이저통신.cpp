#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <string>

using namespace std;

int w, h;  // ���簢�� ũ��
char map[101][101];  // �־��� ����
vector<pair<int, int> > C;  // C�� ��ġ
int visited[101][101][4];  // �� ��ǥ�� �ش�������� �������� �����ϴ� �ּ� �ſ� ��

const int dx[4] = { -1,1,0,0 };
const int dy[4] = { 0,0,-1,1 };

void laser(int sx, int sy) {
	queue<pair<pair<int, int>, int> > q;  // (��ǥ, ���� �̵� ����)

	// ���� ��ġ���� �������� ���� �̵� ���� ť�� ����
	for (int dir = 0; dir < 4; dir++) {
		q.push(make_pair(make_pair(sx, sy), dir));
		visited[sx][sy][dir] = 0;
	}

	while (!q.empty()) {
		int x = q.front().first.first;
		int y = q.front().first.second;
		int d = q.front().second;
		q.pop();

		// �������� ���� �̵�
		for (int dir = 0; dir < 4; dir++) {
			int nx = x + dx[dir];
			int ny = y + dy[dir];

			// �̵� ������ ������ Ȯ��
			if (nx < 0 || nx >= h || ny < 0 || ny >= w || map[nx][ny] == '*')
				continue;

			// ���� ���� �̵��̸� �ſ� ���� ����
			// 90�� ȸ�� �̵��̸� �ſ� ���� +1
			int mirror = (dir == d) ? visited[x][y][d] : visited[x][y][d] + 1;

			// ���� �湮���� �ʾҰų� 
			// ���ݱ��� ���� �ּ� �ſ� �������� �۾����� ����
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

	// visited �迭 �ʱ�ȭ
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