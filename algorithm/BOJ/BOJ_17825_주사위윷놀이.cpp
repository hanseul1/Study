#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int dice[10];  // �ֻ��� ������ ���� �� 
vector<pair<int, int> > horse;  // �����ǿ� �ö�� �� ����Ʈ(����, �������:0 / �Ķ����: �ش� ��� �ε���)
int res;

const int blueRoad[3][8] = { {10,13,16,19,25,30,35,40},
					  {20,22,24,25,30,35,40},
					  {30,28,27,26,25,30,35,40} };

// pt��° ���� stepĭ ��ŭ �̵�
// return �̵��� ĭ�� ���� (�ش� ĭ�� �ٸ� ���� ������ -1)
int moveHorse(int pt, int step) {
	int ret = 0;
	pair<int, int> temp = horse[pt];  // ���� ��ġ ����

	if (horse[pt].second == 0) {  // ���� ��� : 2�� ����
		ret = horse[pt].first + 2 * step;
		horse[pt].first = ret;

		// 10 , 20, 30 �� ĭ�� ������ ��� => �Ķ� ��η� �̵�
		if (ret % 10 == 0 && ret < 40) {
			horse[pt].second = ret;
		}
	}
	else {  // �Ķ� ��� : �� ����� �迭�� ���� �̵�
		int road = horse[pt].second / 10 - 1;
		int index = horse[pt].second % 10;
		if (index + step > 7 || (road == 1 && index + step > 6)) ret = 41;  // ������ ���
		else {
			ret = blueRoad[road][index + step];
			horse[pt].second = (road + 1) * 10 + (index + step);
		}
		horse[pt].first = ret;
	}

	// �ٸ� ���� �ִ��� Ȯ��
	if (horse[pt].first <= 40) {
		for (int i = 0; i < horse.size(); i++) {
			if (i != pt) {
				if (horse[i] == horse[pt]) ret = -1;
				// ������ ���� ���
				else if (horse[i].first == horse[pt].first) {
					// �� �� �ϳ��� ���� ��ο� �ְų� 
					// �� �� �ϳ��� 30�� �ִ� ��� �����ϰ� ���� ��ġ�� ����
					if (!(horse[i].second == 0 || horse[pt].second == 0 ||
						horse[i].second == 30 || horse[pt].second == 30))
						ret = -1;
					else if (horse[i].first == 40) ret = -1;
				}
			}
		}
	}

	if (ret == -1) horse[pt] = temp;  // �ٸ� �� �ִ� ��� �̵� ���
	return ret;
}

void dfs(int pt, int score) {
	// �ֻ��� �� 10�� ������ ���� �ִ� ����
	if (pt == 10) {
		res = max(res, score);
		return;
	}

	// ���� �����ǿ� �ִ� �� �̵�
	for (int i = 0; i < horse.size(); i++) {
		if (horse[i].first > 40) continue;

		pair<int, int> prev = horse[i];
		int next = moveHorse(i, dice[pt]);
		if (next > 0) {  // �̵� ������ ���
			int nextScore = next <= 40 ? score + next : score;
			dfs(pt + 1, nextScore);
		}
		horse[i] = prev;
	}
}

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(0);

	for (int i = 0; i < 10; i++) {
		cin >> dice[i];
	}

	for (int i = 0; i < 4; i++) {
		horse.push_back(pair<int, int>{0, 0});
	}

	dfs(0, 0);
	cout << res << endl;
	return 0;
}