#include<bits/stdc++.h>
#include<iostream>
using namespace std;

int num_way(int n)
{
    if(n==0||n==1){
    return 1;
    }else{
    return num_way(n-1)+num_way(n-2);
    }
}

int main()
{
    int n;
    
    cout<<"enter value of n";
    cin>>n;
    cout << num_way(n) << endl;
}


