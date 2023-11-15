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
	int vec[n];
	for(int i=0;i<n;i++)	cin >> vec[i];
	int key = vec[n-1];
	int idx = n-1;
	for(int i=n-2;i>=0;i--){
		int j=i;
		if(vec[j]>key){
			vec[j+1] = vec[j];
			for(auto it:vec) cout << it << " ";
			cout << endl;
		 	idx = j;
		}
	}
	vec[idx] = key;
	if(vec[idx-1]>vec[idx] && idx>0)swap(vec[idx-1],vec[idx]);
	for(auto it:vec) cout << it << " ";
	cout << endl;
}