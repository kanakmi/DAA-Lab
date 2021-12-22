#include <iostream>
#include <vector>
using namespace std;

bool subset_sum(int arr[], int n, int sum, vector<vector<int>> &mem){
    if(sum == 0)
        return true;
    if(n == 0)
        return false;
    if(mem[n][sum] != -1) return mem[n][sum];
    if(arr[n-1] > sum)
        return mem[n][sum] = subset_sum(arr, n-1, sum, mem);
    else
        return mem[n][sum] = subset_sum(arr, n-1, sum, mem) || subset_sum(arr, n-1, sum-arr[n-1], mem);
}

int main(){
    int n, sum;
    cin >> n;
    int arr[n];
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    cin >> sum;
    vector<vector<int>> mem(n+1, vector<int>(sum+1, -1));
    cout << (subset_sum(arr, n, sum, mem)?"True":"False");
    return 0;
}