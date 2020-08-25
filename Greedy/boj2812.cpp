#include <bits/stdc++.h>
using namespace std;

int n, k; 
vector<int> arr, srt; 

int main() {
	scanf("%d%d", &n, &k);
	for (int i = 1,a; i <= n; i++) {
		scanf("%1d", &a); 
		arr.push_back(a);
		srt.push_back(a);
	}
	sort(srt.begin(), srt.end(), [](int a, int b) {return a > b; }); 
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n - k; j++)	
			if (arr[i] == srt[j]) {		
				printf("%d", arr[i]);
				break;
			}
	}

	return 0;
}