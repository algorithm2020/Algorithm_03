//실패

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n,k, root,p_size,num;
int leaf_num = 0;
vector<vector<int>> child;
vector<int> parent;

int main()
{
	cin >> n; //노드 갯수
	child.resize(n);

	for (int i = 0;i < n;i++)
	{
		cin >> num; //부모노드 숫자
		if (num == -1) root = i;
		else {
			child[num].push_back(i);
			parent.push_back(num);
		}
	}
	sort(parent.begin(), parent.end());
	parent.erase(unique(parent.begin(), parent.end()), parent.end());//parent 중복원소 제거

	p_size = parent.size();
	leaf_num = n - p_size;
	cout << p_size << '\n';

	cin >> k; // 제거할 노드 숫자

	for (int i = 0;i < p_size;i++)
	{
		if (k == root) {
			leaf_num = 0;
		}
		else if (k == parent[i]) {
			while (child[i][0] == parent[i]) {
				leaf_num--;
			}
			leaf_num -= 
		}

	}

	cout << leaf_num - 1<<'\n';


	return 0;

}
