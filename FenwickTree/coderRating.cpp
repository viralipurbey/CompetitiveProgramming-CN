#include<bits/stdc++.h>
using namespace std;

class coder{

public:
    int x;
    int y;
    int index;
};

bool compare(coder c1, coder c2){
    if(c1.x == c2.x){
        return c1.y < c2.y;
    }
    return c1.x < c2.x; 
}

void update(int y, int* BIT){
    for(; y <= 100000; y += y & (-y)){
        BIT[y]++;
    }
}

int query(int y, int* BIT){
    int count = 0;
    for(; y > 0; y -= y & (-y)){
        count += BIT[y];
    }
    return count;
}

int main(){

    int n;
    cin >> n;
    coder *arr = new coder[n];
    
    for(int i = 0; i < n; i++){
       cin >> arr[i].x >> arr[i].y;
       arr[i].index = i;
    }
    sort(arr, arr + n, compare);

    int *BIT = new int[100001]();
    int *ans = new int[n];

    for(int i = 0; i < n;){

        int endIndex = i;
        while(endIndex < n && arr[i].x == arr[endIndex].x && arr[i].y == arr[endIndex].y){
            endIndex++;
        }

        // query
        for(int j = i; j < endIndex; j++){
            
            ans[arr[j].index] = query(arr[j].y, BIT);

        }

        // update
        for(int j = i; j < endIndex; j++){
            
            update(arr[j].y, BIT);

        }
        i = endIndex;
        
    }

    for(int i = 0; i < n; i++){
        cout << ans[i] << endl;
    }

}