#include <bits/stdc++.h>
using namespace std;

int n, k; //수열의 길이 n, 지울 숫자의 개수 k
vector<int> arr, srt; //원본 수열 arr, 정렬한 수열 srt

int main() {
	scanf("%d%d", &n, &k);
	for (int i = 1,a; i <= n; i++) { //arr과 srt 입력
		scanf("%1d", &a); 
		arr.push_back(a);
		srt.push_back(a);
	}
	sort(srt.begin(), srt.end(), [](int a, int b) {return a > b; }); //srt를 내림차순으로 정렬
	//출력할 수열의 길이는 n-k이고 n-k번째로 큰 수가 수열에 들어감
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n - k; j++)	
			//n-k번째로 큰 수까지 수열에 들어갈 수 있기 때문에 
			//arr[i]가 srt[0]부터 srt[n-k-1] 사이에있다면 수열에 포함
			if (arr[i] == srt[j]) {		
				printf("%d", arr[i]);
				break;
			}
	}

	return 0;
}