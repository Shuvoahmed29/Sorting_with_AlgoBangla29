#include<bits/stdc++.h>
using namespace std;
void code(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif 
}
int pivot(int low,int high,int *arr){
    int last=arr[high];
    int l=low;
    for(int i=low;i<high;i++){
        if(arr[i]<=last){
            swap(arr[l],arr[i]);
            l++;
        }
    }
    swap(arr[l],arr[high]);
    return l;
}
void quickSort(int low,int high,int *arr){
    if(low<high){
        int p = pivot(low,high,arr);
        quickSort(low,p-1,arr);
        quickSort(p+1,high,arr);
    }
}
int main(){
    code();
    int n;  cin >> n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin >> arr[i];
    }
    quickSort(0,n-1,arr);
    for(int i=0;i<n;i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}
