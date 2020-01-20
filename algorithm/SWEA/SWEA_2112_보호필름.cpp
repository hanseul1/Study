#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int d, w;  // ��ȣ�ʸ� �β�, ����ũ��
int film[14][21];  // ��ȣ�ʸ� �ܸ� ����
int k;  // �հ� ����
int res;

bool checking() {
	// �� ������ �˻�
	for (int j = 0; j < w; j++) {
		bool isValid = false;
		int cnt = 1;  // ���ӵ� ���� ����
		int prev = film[0][j];  // ù��° ���� Ư��
		for (int i = 1; i < d; i++) {
			if (prev == film[i][j]) cnt++;
			else {
				prev = film[i][j];
				cnt = 1;
			}

			// ���� k�� ���ӵǸ� ���� �� �˻� ���
			if (cnt == k) {
				isValid = true;
				break;
			}
		}

		// ���� ���� k�� �̻� ���� ���ӵ��� �ʾ����� false ����
		if (!isValid) return false;
	}

	// ��� ���� �˻� ��������� true ����
	return true;
}

void injecting(int pt, int cnt) {
	// ������� ���� �ּڰ����� ũ�ų� ������ ���̻� ������� �ʰ� ����
	if (cnt >= res) return;

	// ��ǰ ������ �������� ���� �˻�
	if (pt == d) {
		if (checking()) res = min(res, cnt);
		return;
	}

	// ��ǰ�� �������� �ʴ� ���
	injecting(pt + 1, cnt);

	int temp[21];
	// ���� ���� ��ǰ A ����
	for (int i = 0; i < w; i++) {
		temp[i] = film[pt][i];  // ���� �ʸ� ���� ����
		film[pt][i] = 0;
	}
	injecting(pt + 1, cnt + 1);

	// ���� ���� ��ǰ B ����
	for (int i = 0; i < w; i++) {
		film[pt][i] = 1;
	}
	injecting(pt + 1, cnt + 1);

	// ���� �ʸ� ������ ����
	for (int i = 0; i < w; i++) {
		film[pt][i] = temp[i];
	}
}

int main() {
	int t;
	cin >> t;

	for (int test = 1; test <= t; test++) {
		cin >> d >> w >> k;

		for (int i = 0; i < d; i++) {
			for (int j = 0; j < w; j++) {
				cin >> film[i][j];
			}
		}

		res = d;  // ��ǰ�� �ִ� d�� ������ �� �ִ�.
		injecting(0, 0);

		cout << "#" << test << " " << res << "\n";
	}
	return 0;
}
