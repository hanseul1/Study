#include <iostream>
#include <string>
#include <math.h>

using namespace std;

int n, m;  // �������� ũ��
char board[51][51];  // �������� ����
bool visited[51][51];  // �� ��ǥ�� �湮 ����
int sx, sy;  // dfs ������
bool res;

const int dx[4] = { -1,1,0,0 };
const int dy[4] = { 0,0,-1,1 };

void dfs(int x, int y, int cnt) {
	if (res) return;

	// ���������� ���ƿԴٸ� ����Ŭ ����
	if (x == sx && y == sy && visited[sx][sy]) {
		res = true;
		return;
	}

	// �����¿� �������� �̵� ����
	for (int dir = 0; dir < 4; dir++) {
		int nx = x + dx[dir];
		int ny = y + dy[dir];

		// ���� üũ
		if (nx < 0 || nx >= n || ny < 0 || ny >= m || visited[nx][ny]) continue;

		// ���� ���̸� �̵�
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

	// ����Ŭ�� ������ ����
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