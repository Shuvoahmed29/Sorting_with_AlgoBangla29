/*
				Bucket Sort
It's divides an array elements into several buckets.The
bucket are then sorted one at a time,using different
sorting algorithm.
Bucket sort working on floating point numbers
between range 0.0 to 1.0

Best/Average case time complexity O(n)
worst case time complexity O(n^2)
Space Complexity O(n+k)
*/
#include<bits/stdc++.h>
using namespace std;
void code(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif 
}
void bucketSort(float *arr,int n){
	vector<float>bucket[n];
	for(int i=0;i<n;i++){
		int idx=n*arr[i];
		bucket[idx].push_back(arr[i]);
	}
	for(int i=0;i<n;i++){
		sort(bucket[i].begin(),bucket[i].end());
	}
	int idx=0;
	for(int i=0;i<n;i++){
		for(int j=0;j<bucket[i].size();j++){
			arr[idx]=bucket[i][j];
			idx++;
		}
	}
}
int main(){
	code();
	int n;	cin >> n;
	float arr[n];//0 to 1
	for(int i=0;i<n;i++) cin >> arr[i];
	bucketSort(arr,n);
	for(int i=0;i<n;i++) cout << arr[i] <<' ';
}


