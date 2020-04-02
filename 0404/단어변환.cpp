#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(string begin, string target, vector<string> words) {
    	int answer = 0;
    	bool visit[50] = {false,};
    	bool check = false;
	int cnt;
	queue<pair<string,int>> q; //현재 비교할 단어와 몇단계인지 저장
    
	for (int i = 0; i<words.size();i++) {
		if (target == words[i]) {
			check = true;
			break;
		}
	} 
	if (check == false) return 0; //words목록 중에 target이 없으면 0을 return;

   	q.push(make_pair(begin, 0));

	while (!q.empty()) {
		string cmp = q.front().first;
		int dist = q.front().second;
		q.pop();

		if (cmp == target) {
			answer = dist;
            		break;
		}
		for (int i = 0; i < words.size(); i++) { //각 단어비교
            		cnt = 0; //각 단어마다 초기화 해줘야함.
			if ( visit[i] == false) {
				for (int j = 0;j < cmp.size();j++) { //단어의 각 스펠링 비교
					if ( cmp[j] != words[i][j]) cnt++;
				}
               			if (cnt == 1) { //스펠링이 다른게 하나있는 경우
					q.push(make_pair(words[i],dist+1));
					visit[i] = true;
				}
			}
		} 
    	}
    return answer;
}
