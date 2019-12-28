#include<bits/stdc++.h>
using namespace std;
int power[100001];

void buildPower(){
    power[0] = 1;
    for(int i = 1; i <= 100000; i++){
        power[i] = (power[i-1]*2)%3;
    }
}

void buildTree(int* tree, int* input, int start, int end, int treeNode){

    if(start == end){
        tree[treeNode] = input[start];
        return;
    }

    int mid = (start + end)/2;
    buildTree(tree, input, start, mid, 2 * treeNode);
    buildTree(tree, input, mid + 1, end, 2 * treeNode + 1);
    tree[treeNode] = (tree[2 * treeNode] * power[end-mid]+ tree[2 * treeNode + 1])%3;
}

void update(int *input, int *tree, int start, int end, int treeNode, int idx){

    // Base Case
    if(start == end){
        tree[treeNode] = 1;
        input[idx] = 1;
        return;
    }

    int mid = (start + end)/2;
    if(idx > mid){
        update(input, tree, mid + 1, end, 2 * treeNode + 1, idx);
    }else{
        update(input, tree, start, mid, 2 * treeNode, idx);
    }

    tree[treeNode] = (tree[2 * treeNode] * power[end-mid] + tree[2 * treeNode + 1])%3;
}

int query(int *tree, int start, int end, int left, int right, int treeNode){

    // Completely outside
    if(right < start || end < left){
        return 0;
    }
    // Completely inside
    if(start >= left && end <= right){
        return tree[treeNode];
    }

    // Partially inside and partially outside
    int mid = (start + end)/2;
    int ans1 = query(tree, start, mid, left, right, 2 * treeNode);
    int ans2 = query(tree, mid + 1, end, left, right, 2 * treeNode + 1);
    int ans;
    ans = (ans1 * power[right-mid]+ ans2)%3;
    return ans;
}

int main(){
    buildPower();
    int n;
    cin >> n;
    string bin;
    cin >> bin;
    int *input = new int[n];
    for(int i = 0; i < n; i++) 
        input[i] = bin[i]-'0';
    int *tree = new int[4*n];
    buildTree(tree, input, 0, n-1, 1);
    int q;
    cin >> q;
    for(int i = 0; i < q; i++){
        int type, left, right, idx;
        cin >> type;
        if(type == 0){
            cin >> left >> right;
            cout << query(tree, 0, n-1, left, right, 1) << endl;
        }else{
            cin >> idx;
            if(input[idx] == 0){
                update(input,tree, 0, n-1, 1, idx);
            }
        }
    }

}