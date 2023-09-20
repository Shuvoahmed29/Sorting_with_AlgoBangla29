/*
					Bubble Sort
Bubble sort is the simple sorting algorithm that works by repeatdly 
swapping the adjacent elements if the are in the wrong order.This
algorithm is not suitable for large data sets its average and worst-case time
Complexity is quite high.

Average/Worst-case time Complexity O(n^2)
Best case time complexity O(n); 1 2 3 4 5
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
// 1 2 3 4 5
int main(){
	code();
	int n;	cin >> n;
	// vector<int>vec(n);
	int vec[n];
	for(int i=0;i<n;i++) cin >> vec[i];
	for(int i=0;i<n;i++){
		for(int j=i+1;j<n;j++){
			// vec[i]=fast;
			// vec[j]=2nd;
			if(vec[i]>vec[j]) swap(vec[i],vec[j]);
			// if(vec[i]<vec[j]) swap(vec[i],vec[j]);
		}
	}
	for(int i=0;i<n;i++) cout << vec[i] << " ";

}


