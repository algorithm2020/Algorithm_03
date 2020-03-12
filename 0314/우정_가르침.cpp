#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;
int N, K, mx;
vector<string> word;
bool alpha[26];

void TeachAlpha(int idx, int cnt)
{
 //조합 이용하여 K개 뽑은 후 읽을 수 있는 단어 최대값 계산 
	if (cnt == K)
	{
		int num = 0;
		for (int i = 0;i < N;i++)
		{
			bool res = true;
			for (int j = 0; j < word[i].length();j++)
			{
				if (alpha[word[i][j] - 'a'] == false)
				{ 
					res = false;
					break;
				}
			}
			if (res) num++;
		}
		mx = max(mx, num);
		return;
	}

	for (int k = idx;k < 26;k++)
	{
		if (alpha[k] == false)
		{
			alpha[k] = true;
			TeachAlpha(k,cnt+1);
			alpha[k] = false;
		}
	}

}

int main()
{
	cin >> N >> K;
	word.resize(N);
	for (int i = 0;i < N;i++)
	{
		cin >> word[i];
		//anta 제거
		word[i] = word[i].substr(4, word[i].length());
		//tica 제거
		for (int j = 0; j < 4; j++)
			word[i].pop_back();
	}

	if (K < 5)
	{
		cout << 0 << '\n';
		return 0;
	}

	alpha['a' - 'a'] = true;
	alpha['n' - 'a'] = true;
	alpha['t' - 'a'] = true;
	alpha['i' - 'a'] = true;
	alpha['c' - 'a'] = true;
	
	K -= 5;

	TeachAlpha(0, 0);
	cout << mx << '\n';

	return 0;
}
