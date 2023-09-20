/*
				Insertion Sort
Insertion sort is a comparison-based algorithm.Insertion sort 
works similar to the sorting of playing cards
in hands.It assumed that the first card is already sorted in
the card game.And then we select an unsorted card.If the selected
unsorted card is greater then the first card it will be place at
right side.Otherwise it will be placed at the left side.Similarly
all unsorted cards are taken and put their exact place.


Average/Worst case time Complexity O(n^2)
Best case time complexity O(n)
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
	vector<int>vec(n);
	//int vec[n];
	for(int i=0;i<n;i++)	cin >> vec[i];
	for(int i=1;i<n;i++){// 5 4 1 3 2
		int key = vec[i];
		int j=i-1;
		while(vec[j]>key && j>=0){
			vec[j+1] = vec[j];
			j--;
		}
		vec[j+1] =key;
	}
	// for(int i=0;i<n;i++)	cout << vec[i] << " ";
	for(auto it:vec) cout << it << " ";
}


