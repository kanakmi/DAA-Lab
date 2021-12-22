#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

int main(){
    int n, sum;
    cin >> n;
    int arr[n], i, j;
    for(i=0; i<n; i++){
        cin >> arr[i];
    }
    cin >> sum;
    int t[n+1][sum+1];
    memset(t, -1, sizeof(t));
    for(i=0; i<=n; i++){
        t[i][0] = 1;
    }
    for(i=1; i<=sum; ++i){
        t[0][i] = 0;
    }
    for(i=1; i<=n; ++i){
        for(j=1; j<=sum; ++j){
            if(j<arr[i-1]){
                t[i][j] = t[i-1][j];
            }
            else{
                t[i][j] = t[i-1][j] + t[i][j-arr[i-1]];
            }
        }
    }
    cout << t[n][sum];
    return 0;
}