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
/*
    Worst/Best/Average Case time Complexity O(n*log n)
    Space Complexity O(n)
    
    T(n) = T(n/2) + T(n/2)  + n
           (Left)     (Right)   (Marge)

T(n) = 2T(n/2) + n -------------(1)

Substitutes n/2 in place of n in equ. (1)
T(n/2) = 2T(n/4) + n/2

Put the value of T(n/2) in equ (1)
T(n) = 2{ 2T(n/4) + n/2 } + n
T(n) = 4 T(n/4) + 2n -------------------------------(2)

Substitutes n/4 in place of n in equ. (1)
T(n/4) = 2T(n/8) + n/4

Put the value of T(n/2) in equ (2)
T(n) = 4{2T(n/8) + n/4} + 2n
T(n) = 8T(n/8) + 3n
T(n) = 2^3 T(n/2^3) + 3n
Hence,
T(n) = 2^i T(n/2^i) + i*n ------------------------(3)

Let,
n/2^i = 1 
n = 2^i
log2 (n) = log2 (2^i)
log2 (n) = i log2 (2)
i = log2 (n)
From equ (3),
T(n) = n T(1) + n*log2 (n)
T(n) = n + n*log2 (n)

T(n) = O(n*log2 (n))
*/
