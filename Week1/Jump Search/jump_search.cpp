#include <iostream>
#include <fstream>
using namespace std;

int c=0;

bool jump_search(int *arr, int n, int k){
    for(int i=0; i<n; i+=2){
        ++c;
        if(arr[i]==k)
            return true;

        if(arr[i]>k){
            ++c;
            if(arr[i-1]==k)
                return true;
            else return false;
        }
    }
    return false;
}

int main(){
    fstream input;
    input.open("jump_search_input.txt", ios::in); // specifying the input file
    if (!input) {
        cout << "Unable to open file";
        exit(1); // terminate with error
    }
    int t, n, i, k;
    input >> t; // input number of testcases
    fstream output;
    output.open("jump_search_output.txt", ios::out);
    while(t>0){
        input >> n; // input number of values in array
        int* arr = new int[n];
        for(i=0; i<n; ++i){
            input >> arr[i]; // input array values
        }
        input >> k; // input element to search
        c=0;
        bool res = jump_search(arr, n, k);
        if(res){
            output << "Present " << c << '\n';
        }
        else{
            output << "Not Present " << c << '\n';
        }
        --t;
    }
    input.close();
    output.close();
    return 0;
}