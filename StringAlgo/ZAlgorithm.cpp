#include<bits/stdc++.h>
using namespace std;

void buildZ(int *Z, string str){
    int l = 0;
    int r = 0;
    int n = str.length();

    for(int i = 0; i < n; i++){

        if(i > r){
            // i does not lie between l and r
            // Z for this doesn't exist
            l = i;
            r = i;
            while((r < n) && (str[r-l] == str[r])){
                r++;
            }
            Z[i] = r-l;
            r--;
        }else{
            int k = i - l;
            if(Z[k] <= r-i){
                // it lies between l and r
                // Z will exist previously
                Z[i] = Z[k];
            }else{
                // some part of z is already included
                // you have to start matching further
                l = i;
                while((r < n) && (str[r-l] == str[r])){
                    r++;
                }
                Z[i] = r-l;
                r--;
            }
        }

    }
}

void searchString(string text, string pattern){
    string str = pattern + "$" + text;
    int n = str.length();
    int *Z = new int[n]();
    buildZ(Z, str);
    for(int i = 0; i < n; i++){
        if(Z[i] == pattern.length()){
            cout << i - pattern.length() - 1 << endl;
        }
    }
}
int main(){
    string text = "abcdsafbcdfasbcda";
    string pattern = "bcd";
    searchString(text, pattern);
    return 0;
}