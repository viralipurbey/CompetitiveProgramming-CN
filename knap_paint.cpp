#include<bits/stdc++.h>
using namespace std;

struct worker{
    int start;
    int cost;
    int speed;
};

bool comp(worker w1, worker w2){
    
    if(w1.start == w2.start){
        if(w1.speed != w2.speed){
            return w1.speed > w2.speed;
        }
        else{
            return w1.cost < w2.cost;
        }
    }
    else{
        return w1.start < w2.start;
    }
   
}
long long knapsack(worker W[], int n, int D){
    
    sort(W,W + n,comp);
    long long cost = W[0].cost;
    long long rem = D;
    int prev = 0;
    for(int i = 1; i < n; i++){
        rem = rem - W[prev].speed *(W[i].start - W[prev].start);
        if(rem == 0){
            break;
        }
        if(W[i].speed > W[prev].speed){
            cost += W[i].cost;
            prev = i;
        }
    }
    return cost;
}
int main()
{
    //Write your code here
       
    int n;
    long long D;
    cin >> n >> D;
    worker W[n];
    for(int i = 0; i < n; i++){
        cin >> W[i].start >> W[i].cost >> W[i].speed;
    }
    
    int cost = knapsack(W,n,D);
    cout << cost << endl;
    
    return 0;
}