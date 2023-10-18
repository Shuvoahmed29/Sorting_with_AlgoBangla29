#include<bits/stdc++.h>
using namespace std;
void code(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif 
}
const int N = 1e6+10;
int arr[N];
void marge(int low,int high,int mid){
    int left = mid-low+1;
    int leftArray[left+1];
    int right = high-mid;
    int rightArray[right+1];
    for(int i=0;i<left;i++){
        leftArray[i] = arr[i+low];
    }
    for(int i=0;i<right;i++){
        rightArray[i] = arr[i+mid+1];
    }
    leftArray[left] = rightArray[right] = INT_MAX;
    int l=0,r=0;
    for(int i=low;i<=high;i++){
        if(leftArray[l]<=rightArray[r]){
            arr[i] = leftArray[l];
            l++;
        }
        else{
            arr[i] = rightArray[r];
            r++;
        }
    }
}
void margeSort(int left, int right){
    if(left==right) return;
    int mid = (left+right)/2;
    margeSort(left,mid);
    margeSort(mid+1,right);
    marge(left,right,mid);
}
int main(){
   code();
   int n;   cin >> n;
   for(int i=0;i<n;i++){
        cin >> arr[i];
   }
   margeSort(0,n-1);
   for(int i=0;i<n;i++){
    cout << arr[i] << " ";
   }
}
