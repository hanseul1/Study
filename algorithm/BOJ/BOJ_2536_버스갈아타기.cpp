#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <map>

using namespace std;

struct bus {
	int x1, y1;
	int x2, y2;
	int dir;  // ��: 0, ��: 1
	bool finish;
};

int m, n;  // ���θ� ũ��
int k;  // ���� ��
int sx, sy, cx, cy;  // ������� ������
bus busList[5001];  // ���� ����Ʈ
vector<int> adjList[5001];  // �������� ��������Ʈ
queue<pair<int, int> > q;  // (���� ��ȣ, ���� ��)
bool visited[5001];  // �� ���� �뼱 �湮 ����

const int dx[4] = { -1,1,0,0 };
const int dy[4] = { 0,0,-1,1 };

void make_adjlist() {
	for (int i = 1; i < k; i++) {
		for (int j = i + 1; j <= k; j++) {
			bus bus1 = busList[i];
			bus bus2 = busList[j];

			// �� �� �� ������ ���
			if (bus1.dir == 0 && bus2.dir == 0) {
				// ������ �̾������� ����
				if (bus1.x1 == bus2.x1 && ((bus2.y1 <= bus1.y2 && bus1.y1 <= bus2.y2) || (bus1.y1 <= bus2.y2 && bus2.y1 <= bus1.y2))) {
					adjList[i].push_back(j);
					adjList[j].push_back(i);
				}
			}
			// �� �� �� ������ ���
			else if (bus1.dir == 1 && bus2.dir == 1) {
				if (bus1.y1 == bus2.y1 && ((bus2.x1 <= bus1.x2 && bus1.x1 <= bus2.x2) || (bus1.x1 <= bus2.x2 && bus2.x1 <= bus1.x2))) {
					adjList[i].push_back(j);
					adjList[j].push_back(i);
				}
			}
			// bus1�� �� ����, bus2�� �� ������ ���
			else if (bus1.dir == 0 && bus2.dir == 1) {
				if (bus2.x1 <= bus1.x1 && bus1.x1 <= bus2.x2 && bus1.y1 <= bus2.y1 && bus2.y1 <= bus1.y2) {
					adjList[i].push_back(j);
					adjList[j].push_back(i);
				}
			}
			// bus1�� �� ����, bus2�� �� ������ ���
			else {
				if (bus1.x1 <= bus2.x1 && bus2.x1 <= bus1.x2 && bus2.y1 <= bus1.y1 && bus1.y1 <= bus2.y2) {
					adjList[i].push_back(j);
					adjList[j].push_back(i);
				}
			}
		}
	}
}

void check_finish() {
	for (int i = 1; i <= k; i++) {
		bus b = busList[i];
		if (b.dir == 0) {
			if (b.x1 == cx && b.y1 <= cy && cy <= b.y2) busList[i].finish = true;
			if (b.x1 == sx && b.y1 <= sy && sy <= b.y2) {
				q.push(make_pair(i, 1));
				visited[i] = true;
			}
		}
		else {
			if (b.y1 == cy && b.x1 <= cx && cx <= b.x2) busList[i].finish = true;
			if (b.y1 == sy && b.x1 <= sx && sx <= b.x2) {
				q.push(make_pair(i, 1));
				visited[i] = true;
			}
		}
	}
}

int bfs() {
	while (!q.empty()) {
		int b = q.front().first;
		int cnt = q.front().second;
		q.pop();

		if (busList[b].finish) return cnt;

		// ����� ���� �뼱���� ȯ�� ����
		for (int i = 0; i < adjList[b].size(); i++) {
			int nb = adjList[b][i];

			if (!visited[nb]) {
				q.push(make_pair(nb, cnt + 1));
				visited[nb] = true;
			}
		}
	}
	return 0;
}

int main() {
	cin >> m >> n;
	cin >> k;

	for (int i = 0; i < k; i++) {
		int b;
		cin >> b;
		cin >> busList[b].x1 >> busList[b].y1 >> busList[b].x2 >> busList[b].y2;

		if (busList[b].x1 == busList[b].x2) {
			busList[b].dir = 0;
			if (busList[b].y1 > busList[b].y2) {
				int temp = busList[b].y1;
				busList[b].y1 = busList[b].y2;
				busList[b].y2 = temp;
			}
		}
			
		else {
			busList[b].dir = 1;
			if (busList[b].x1 > busList[b].x2) {
				int temp = busList[b].x1;
				busList[b].x1 = busList[b].x2;
				busList[b].x2 = temp;
			}
		}
			
	}

	cin >> sx >> sy >> cx >> cy;

	make_adjlist();
	check_finish();

	int res = bfs();
	cout << res << "\n";

	return 0;
}