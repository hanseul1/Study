#include <iostream>
#include <algorithm>

using namespace std;

int n;  // �̷� ����
int maze[1001];  // �̷� ����
int cache[1001];
const int INF = 987654321;

int jump(int pt) {
	// base case : �̷� ���� ������ ���� �����ϸ� ����
	if (pt >= n - 1) return 0;

	// �޸������̼�
	int& ret = cache[pt];
	if (ret != -1) return ret;

	ret = INF;
	// ���� ĭ���� 1 ~ (���� ĭ�� ���� ����)ĭ ��ŭ ���� ����
	for (int i = 1; i <= maze[pt]; i++) {
		ret = min(ret, jump(pt + i) + 1);
	}

	return ret;
}

int main() {
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> maze[i];
		cache[i] = -1;  // ĳ�� �޸� �ʱ�ȭ
	}

	int res = jump(0);
	if (res == INF) res = -1;

	cout << res << endl;
	return 0;
}