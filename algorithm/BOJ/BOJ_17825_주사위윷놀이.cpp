#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int dice[10];  // 주사위 던져서 나온 수 
vector<pair<int, int> > horse;  // 게임판에 올라온 말 리스트(점수, 빨간경로:0 / 파란경로: 해당 경로 인덱스)
int res;

const int blueRoad[3][8] = { {10,13,16,19,25,30,35,40},
					  {20,22,24,25,30,35,40},
					  {30,28,27,26,25,30,35,40} };

// pt번째 말을 step칸 만큼 이동
// return 이동한 칸의 점수 (해당 칸에 다른 말이 있으면 -1)
int moveHorse(int pt, int step) {
	int ret = 0;
	pair<int, int> temp = horse[pt];  // 원래 위치 저장

	if (horse[pt].second == 0) {  // 빨간 경로 : 2씩 증가
		ret = horse[pt].first + 2 * step;
		horse[pt].first = ret;

		// 10 , 20, 30 점 칸에 도달한 경우 => 파란 경로로 이동
		if (ret % 10 == 0 && ret < 40) {
			horse[pt].second = ret;
		}
	}
	else {  // 파란 경로 : 각 경로의 배열에 따라 이동
		int road = horse[pt].second / 10 - 1;
		int index = horse[pt].second % 10;
		if (index + step > 7 || (road == 1 && index + step > 6)) ret = 41;  // 도착한 경우
		else {
			ret = blueRoad[road][index + step];
			horse[pt].second = (road + 1) * 10 + (index + step);
		}
		horse[pt].first = ret;
	}

	// 다른 말이 있는지 확인
	if (horse[pt].first <= 40) {
		for (int i = 0; i < horse.size(); i++) {
			if (i != pt) {
				if (horse[i] == horse[pt]) ret = -1;
				// 점수가 같은 경우
				else if (horse[i].first == horse[pt].first) {
					// 둘 중 하나가 빨간 경로에 있거나 
					// 둘 중 하나가 30에 있는 경우 제외하고 같은 위치에 있음
					if (!(horse[i].second == 0 || horse[pt].second == 0 ||
						horse[i].second == 30 || horse[pt].second == 30))
						ret = -1;
					else if (horse[i].first == 40) ret = -1;
				}
			}
		}
	}

	if (ret == -1) horse[pt] = temp;  // 다른 말 있는 경우 이동 취소
	return ret;
}

void dfs(int pt, int score) {
	// 주사위 턴 10번 끝나면 점수 최댓값 갱신
	if (pt == 10) {
		res = max(res, score);
		return;
	}

	// 현재 게임판에 있는 말 이동
	for (int i = 0; i < horse.size(); i++) {
		if (horse[i].first > 40) continue;

		pair<int, int> prev = horse[i];
		int next = moveHorse(i, dice[pt]);
		if (next > 0) {  // 이동 성공한 경우
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