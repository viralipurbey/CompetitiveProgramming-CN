#include<bits/stdc++.h>
using namespace std;

void update(int *BIT, int n, int index, int value){

    for(; index <= n; index += index & (-index)){
        BIT[index] += value;
    }
}

int query(int *BIT, int index){
    int sum = 0;
    for(; index >0; index -= index & (-index)){
        sum += BIT[index];
    }
    return sum;
}

int main(){

    int n;
    cin >> n;
    int *arr = new int[n+1];
    int *BIT = new int[n+1]();

    for(int i = 1; i <= n; i++){
        cin >> arr[i];
        update(BIT, n, i, arr[i]);
    }

    cout <<"Sum of first 5 elements " << query(BIT, 5) << endl;
    cout <<"Sum of elements from 2 index to 6 index " << query(BIT, 6) - query(BIT, 1) << endl;
}