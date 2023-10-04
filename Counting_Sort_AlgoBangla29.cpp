/*
    Counting Sort
Time Complexity O(n+Range)
Space Complexity O(mx element)
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
    int n;  cin >> n;
    int arr[n],mx=INT_MIN;
    for(int i=0;i<n;i++){
        cin >> arr[i];
        mx = max(mx,arr[i]);
    }
    int cunt[mx+1];// 0 0 0 0 0 0
    for(int i=0;i<=mx;i++)  cunt[i]=0;
    for(int i=0;i<n;i++) cunt[arr[i]]++;
    for(int i=0;i<=mx;i++){
        cout << cunt[i] <<' ';
    }
    cout << endl;

    for(int i=1;i<=mx;i++){
        cunt[i] = cunt[i]+cunt[i-1];
    }
    for(int i=0;i<=mx;i++){
        cout << cunt[i] <<' ';
    }
    cout << endl;

    int output[n];
    for(int i=0;i<n;i++){
        output[--cunt[arr[i]]] = arr[i];
    }
    for(int i=0;i<n;i++) arr[i] = output[i];
        
    for(int i=0;i<n;i++){
        cout << arr[i] <<' ';
    }
    cout << endl;
}
