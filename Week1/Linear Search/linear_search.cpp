#include <iostream>
#include <fstream>
using namespace std;

int linear_search(int *arr, int n, int k){
    int i;
    for(i=0; i<n; ++i){
        if(arr[i]==k){
            return i;
        }
    }
    return i;
}

int main(){
    fstream input;
    input.open("linear_search_input.txt", ios::in); // specifying the input file
    if (!input) {
        cout << "Unable to open file";
        exit(1); // terminate with error
    }
    int t, n, i, k;
    input >> t; // input number of testcases
    fstream output;
    output.open("linear_search_output.txt", ios::out);
    while(t>0){
        input >> n; // input number of values in array
        int* arr = new int[n];
        for(i=0; i<n; ++i){
            input >> arr[i]; // input array values
        }
        input >> k; // input element to search
        int res = linear_search(arr, n, k);
        if(res==n){
            output << "Not Present " << res << '\n';
        }
        else{
            output << "Present " << res+1 << '\n';
        }
        --t;
    }
    input.close();
    output.close();
    return 0;
}