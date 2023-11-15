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
	vector<int>vec(n);
	//int vec[n];
	for(int i=0;i<n;i++)	cin >> vec[i];
	int last = vec[n-1];
	int idx = n-1;
	for(int i=n-2;i>=0;i--){
		int j=i;
		if(vec[j]>last && j>=0){
			vec[j+1] = vec[j];
			for(auto it:vec) cout << it << " ";
			cout << endl;
			idx = j;
		}
	}
	vec[idx] = last;
	for(auto it:vec) cout << it << " ";
}
