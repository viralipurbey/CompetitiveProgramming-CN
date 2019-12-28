#include<bits/stdc++.h>
using namespace std;

struct Node{
    int no_evens;
    int no_odds;
};

void buildtree(int *arr, Node *tree, int start, int end, int treeNode){

    // Base Case
    if(start == end){
        if(arr[start] % 2 == 0){
            tree[treeNode].no_evens = 1;
            tree[treeNode].no_odds = 0;
        }else{
            tree[treeNode].no_evens = 0;
            tree[treeNode].no_odds = 1;
        }
        return;
    }

    int mid = (start + end)/2;
    buildtree(arr, tree, start, mid, 2 * treeNode);
    buildtree(arr, tree, mid + 1, end, 2 * treeNode + 1);

    tree[treeNode].no_evens = tree[2 * treeNode].no_evens + tree[2 * treeNode + 1].no_evens;
    tree[treeNode].no_odds = tree[2 * treeNode].no_odds + tree[2 * treeNode + 1].no_odds;
}

Node query(Node *tree, int start, int end, int left, int right, int treeNode){

    // Completely outside
    if(right < start || end < left){
        Node ans;
        ans.no_odds = 0;
        ans.no_evens = 0;
        return ans;
    }
    // Completely inside
    if(start >= left && end <= right){
        return tree[treeNode];
    }

    // Partially inside and partially outside
    int mid = (start + end)/2;
    Node ans1 = query(tree, start, mid, left, right, 2 * treeNode);
    Node ans2 = query(tree, mid + 1, end, left, right, 2 * treeNode + 1);
    Node ans;
    ans.no_evens = ans1.no_evens + ans2.no_evens;
    ans.no_odds = ans1.no_odds + ans2.no_odds;
    return ans;
}

void update(int *arr, Node *tree, int start, int end, int treeNode, int idx, int value){

    // Base Case
    if(start == end){
        arr[idx] = value;
        if(value % 2 == 0){
            tree[treeNode].no_evens = 1;
            tree[treeNode].no_odds = 0;
        }else{
            tree[treeNode].no_evens = 0;
            tree[treeNode].no_odds = 1;
        }
        return;
    }

    int mid = (start + end)/2;
    if(idx > mid){
        update(arr, tree, mid + 1, end, 2 * treeNode + 1, idx, value);
    }else{
        update(arr, tree, start, mid, 2 * treeNode, idx, value);
    }

    tree[treeNode].no_evens = tree[2 * treeNode].no_evens + tree[2 * treeNode + 1].no_evens;
    tree[treeNode].no_odds = tree[2 * treeNode].no_odds + tree[2 * treeNode + 1].no_odds;
}

int main(){

    int n;
    cin >> n;
    int *arr = new int[n];
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }

    Node *tree = new Node[4 * n];
    buildtree(arr, tree, 0, n-1, 1);

    //Print tree
    // for(int i = 1; i <= 4 * n; i++){
    //     cout << tree[i].no_evens <<" , "<< tree[i].no_odds << endl;
    // }

    int q;
    cin >> q;

    for(int i = 0; i < q; i++){
        int type, x, y;
        cin >> type >> x >> y;
        if(type == 0){
            update(arr, tree, 0, n-1, 1, x-1, y);
        }else if(type == 1){
            Node ans = query(tree, 0, n-1, x-1, y-1, 1);
            cout << ans.no_evens << endl;
        }else{
            Node ans = query(tree, 0, n-1, x-1, y-1, 1);
            cout << ans.no_odds << endl;
        }
    }
}