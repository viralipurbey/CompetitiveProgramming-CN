#include<bits/stdc++.h>
using namespace std;

struct Node{
    int A;
    int B;
};

void buildtree(Node *arr, int *tree, int start, int end, int treeNode){

    // Base Case
    if(start == end){
        tree[treeNode] = start;
        return;
    }

    int mid = (start + end)/2;
    buildtree(arr, tree, start, mid, 2 * treeNode);
    buildtree(arr, tree, mid + 1, end, 2 * treeNode + 1);

    int one = tree[2 * treeNode];
    int second = tree[2 * treeNode + 1];
    if(arr[one].A != arr[second].A){
        if(arr[one].A > arr[second].A){
            tree[treeNode] = one;
        }else{
            tree[treeNode] = second;
        }
    }else if(arr[one].B != arr[second].B){
        if(arr[one].B < arr[second].B){
            tree[treeNode] = one;
        }else{
            tree[treeNode] = second;
        }
    }else{
        tree[treeNode] = min(one, second);
    }
}

int query(Node *arr, int *tree, int start, int end, int left, int right, int treeNode){

    // Completely outside
    if(right < start || end < left){
        return left;
    }
    // Completely inside
    if(start >= left && end <= right){
        return tree[treeNode];
    }

    // Partially inside and partially outside
    int mid = (start + end)/2;
    int ans1 = query(arr, tree, start, mid, left, right, 2 * treeNode);
    int ans2 = query(arr, tree, mid + 1, end, left, right, 2 * treeNode + 1);
    int ans;
    if(arr[ans1].A != arr[ans2].A){
        if(arr[ans1].A > arr[ans2].A){
            ans = ans1;
        }else{
            ans = ans2;
        }
    }else if(arr[ans1].B != arr[ans2].B){
        if(arr[ans1].B < arr[ans2].B){
            ans = ans1;
        }else{
            ans = ans2;
        }
    }else{
        ans = min(ans1 , ans2);
    }
    return ans;
}

int main(){

    int n;
    cin >> n;
    Node *arr = new Node[n];
    for(int i = 0; i < n; i++){
        cin >> arr[i].A;
    }
    for(int i = 0; i < n; i++){
        cin >> arr[i].B;
    }

    int *tree = new int[4 * n];
    buildtree(arr, tree, 0, n-1, 1);

    //Print tree
    // for(int i = 1; i <= 4 * n; i++){
    //     cout << tree[i] << endl;
    // }

    int q;
    cin >> q;

    for(int i = 0; i < q; i++){
        int x, y;
        cin >> x >> y;
        int ans = query(arr, tree, 0, n-1, x-1, y-1, 1);
        cout << ans + 1 << endl;
    }
}