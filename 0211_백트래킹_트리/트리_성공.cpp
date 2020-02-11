#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, i, p[50], c[50], k, target, cnt;

int main() {

	cin >> n;
	for (int i = 0; i < n; i++) {

		cin >> p[i];
		if (p[i] != -1) c[p[i]]++; //top노드 아닌것 child노드에 저장
	}
	
	cin >> k;
	c[p[k]]--;

	for (i = 0; i<n; i++) {
		target = i;
		while (target != -1 && target != k) target = p[target]; //탐색하면서 top노드까지 올라감. 올라가는 중에 k가 있게되면 죽은 노드.

		if (target == -1 && c[i] == 0) cnt++; //top노드까지 올라갈수있고 자식노드가 없다는 것은 leaf노드라는 뜻.
		
	}

	cout << cnt;

	return 0;
}
