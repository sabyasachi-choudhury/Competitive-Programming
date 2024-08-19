/*
Problem

Given an array of n numbers, calculate the continuous subarray with the maximum sum. Q on page 21
*/

#include <stdio.h>
#include <iostream>
#include <vector>

using namespace std;

typedef vector<int> v;

// Naive O(n^2) solution
int max_subarray_nsquare(v array, int length){
    int max = 0;
    int sum = 0;
    for (int i = 0; i < length; i++){
        sum = 0;
        for (int j = 0; j < length - i; j++){
            sum += array[i+j];
            if (sum > max){
                max = sum;
            };
        };
    };
    return max;
};

// O(n) solution
int max_subarray(v array, int length){
    int max = 0;
    int sum = 0;
    for (int i = 0; i < length; i++){
        if (sum + array[i] > sum){
            sum += array[i];
        }
        else {
            sum = 0;
        }
        if (sum > max){
            max = sum;
        };
    };
    return max;
};

int main(){

    int x, len;
    v arr;

    cin >> len;
    for (int i = 0; i < len; i++){
        cin >> x;
        arr.push_back(x);
    };

    cout << max_subarray(arr, len);

    return 0;

};