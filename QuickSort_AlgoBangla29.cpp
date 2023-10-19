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
/*
Best/Average Case Complexity O(n*logn)
Worst Case Time Complexity O(n^2)
Space Complexity O(log n)


Time Complexity of Quick Sort
T(n) = T(n-1) + n -----------------------------(1)

Substitute (n-1) in place of n in equ (1)
T(n-1) = T(n-2) + (n-1)

Put the value of T(n-1) in equ (1)
T(n) = T(n-2) + (n-1) + n --------------(2)

Substitute (n-2) in place of n in equ (1)
T(n-2) = T(n-3) + (n-2)

Put the value of T(n-2) in equ (2)
T(n) =  T(n-3) + (n-2)+ (n-1) + n
-----------------------------------------
-----------------------------------------
T(n) = T(1) + 2 + 3 + .....................................+ (n-2)+ (n-1) + n
T(n) = 1  + 2 + 3 + .....................................+ (n-2)+ (n-1) + n

T(n) = n(n+1)/2
T(n) = n^2 / 2 + n/2
T(n) = O(n^2) [Worst Case]

If the array is divided into two equal part
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

T(n) = O(n*log2 (n)) [Best/Average Case]
*/
