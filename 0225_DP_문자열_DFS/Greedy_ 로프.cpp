#include<iostream>
#include<algorithm>

using namespace std;

int arr[100001];
int N;

int main() {

	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> arr[i];

	}

	sort(arr, arr + N);
	int max = 0;

	for (int i = 0; i < N; i++) {
		if (max < (N - i) * arr[i])
			max = (N - i) * arr[i];
	}
	cout << max;
	return 0;

}
