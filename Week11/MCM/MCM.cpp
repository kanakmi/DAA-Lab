#include <bits/stdc++.h>
using namespace std;

int MatrixChainMultiplication(int arr[], int i, int j, vector<vector<int>> &mem)
{
    if (i == j)
        return 0;
    if(mem[i][j] != -1)
        return mem[i][j];
    int k;
    int min = INT_MAX;
    int temp;
    for (k = i; k < j; k++)
    {
        temp = MatrixChainMultiplication(arr, i, k, mem) + MatrixChainMultiplication(arr, k + 1, j, mem) 
                + arr[i - 1] * arr[k] * arr[j];
 
        if (temp < min)
            min = temp;
    }
    return mem[i][j]=min;
}

int main(){
    int n;
    cin >> n;
    int arr[n];
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    vector<vector<int>> mem(n+1, vector<int>(n+1, -1));
    cout << MatrixChainMultiplication(arr, 1, n-1, mem);
    return 0;
}