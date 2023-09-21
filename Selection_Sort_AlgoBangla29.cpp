/*
			Selection Sort
In selsction sort,the first smallest element is selected
from the unsorted array and place at the first position.
After that second smallest element is selected and place
in the second position.The process continues until the
array is sorted.

Time Complexity O(n^2)
Space Complexity O(1)
*/
#include<bits/stdc++.h>
using namespace std;
void code(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif 
}
int main(){
	code();
	int n;	cin >> n;
	int arr[n];
	// vector<int>arr(n);
	for(int i=0;i<n;i++) cin >> arr[i];
	for(int i=0;i<n;i++){
		int mini = arr[i];
		int idx=i;
		for(int j=i+1;j<n;j++){
			if(mini>arr[j]){
				mini = arr[j];
				idx = j;
			}
		}
		swap(arr[i],arr[idx]);
	}
	for(int i=0;i<n;i++) cout << arr[i] << " ";
}

