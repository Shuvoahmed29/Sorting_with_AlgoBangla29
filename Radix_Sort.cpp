#include<bits/stdc++.h>
using namespace std;
void code(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif 
}
void radixSort(int *arr, int n, int mx) {
   int m, p = 1, index, temp;
   list<int> pocket[10];
   for(int i = 0; i< mx; i++) {
      m = pow(10, i+1);
      p = pow(10, i);
      for(int j = 0; j<n; j++) {
         temp = arr[j]%m;
         index = temp/p;
         pocket[index].push_back(arr[j]);
    }

    // for (int i = 0; i < 10; i++) {
    //     cout << "List " << i << ": ";
    //     for (int num : pocket[i]) cout << num << " ";
    //     cout << endl;
    // }
    // cout << endl;

    int count = 0;
      for(int j = 0; j<10; j++) {
         while(!pocket[j].empty()) {
            arr[count] = *(pocket[j].begin());
            pocket[j].erase(pocket[j].begin());
            count++;
         }
      }

      // for(int i=0;i<n;i++) cout << arr[i]<<" ";
   	  // cout << endl;
   }


}
int main() {
	code();
   int n, mx = INT_MIN;   cin >> n;
   int arr[n];
   for(int i = 0; i<n; i++) {
      cin >> arr[i];
      mx = max(mx,arr[i]);
   }
   int digit = 0;
   while(mx!=0){
   	  mx = mx/10;
   	  digit++;
   }

   cout << "Data before Sorting: \n";
   for(int i=0;i<n;i++) cout << arr[i]<<" ";
   cout << endl;

   radixSort(arr, n, digit);

   cout << "\nData after Sorting: \n";
   for(int i=0;i<n;i++) cout << arr[i]<<" ";
   cout << endl;

}
/*
	Best/Worst/Average Case Time Complexity O(n+size of max element)
	Space Complexity O(Max element)
*/