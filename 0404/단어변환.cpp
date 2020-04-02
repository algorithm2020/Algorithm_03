#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(string begin, string target, vector<string> words) {
    int answer = 0;
    bool visit[50] = {false,};
    bool check = false;
	int cnt;
	queue<pair<string,int>> q;
    
	for (int i = 0; i<words.size();i++) {
		if (target == words[i]) {
			check = true;
			break;
		}
	} 
	if (check == false) return 0;

    q.push(make_pair(begin, 0));

	while (!q.empty()) {
		string cmp = q.front().first;
		int dist = q.front().second;
		q.pop();

		if (cmp == target) {
			answer = dist;
            break;
		}
		for (int i = 0; i < words.size(); i++) {
            cnt = 0;
			if ( visit[i] == false) {
				for (int j = 0;j < cmp.size();j++) {
					if ( cmp[j] != words[i][j]) cnt++;
					}
                if (cnt == 1) {
						q.push(make_pair(words[i],dist+1));
						visit[i] = true;
				}
			}
		} 
    }
    return answer;
}
