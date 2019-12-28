#include<bits/stdc++.h>
using namespace std;

struct Node{
    int maximum;
    int smaximum;
};

void buildTree(int* arr, Node* tree, int start, int end, int treeNode){
    
    if(start == end){
        tree[treeNode].maximum = arr[start];
        tree[treeNode].smaximum = INT_MIN;
        return;
    }
    
    int mid = (start + end)/2;
    buildTree(arr,tree,start,mid,2*treeNode);
    buildTree(arr,tree,mid+1,end,2*treeNode+1);

    tree[treeNode].maximum = max(tree[2*treeNode].maximum, tree[2*treeNode+1].maximum);
    tree[treeNode].smaximum = min(max(tree[2*treeNode].maximum, tree[2*treeNode +1].smaximum) , max(tree[2*treeNode + 1].maximum, tree[2*treeNode].smaximum));
}

void updateTree(int* arr, Node* tree, int start, int end, int treeNode, int idx, int value){


    if(start == end){
        arr[idx] = value;
        tree[treeNode].maximum = value;
        return;
    }
    int mid = (start + end)/2;
    if(mid < idx){

        updateTree(arr,tree,mid+1,end,2*treeNode+1,idx,value);
    }else{

        updateTree(arr,tree,start,mid,2*treeNode,idx,value);
    }

    tree[treeNode].maximum = max(tree[2*treeNode].maximum, tree[2*treeNode+1].maximum);
    tree[treeNode].smaximum = min(max(tree[2*treeNode].maximum, tree[2*treeNode +1].smaximum) , max(tree[2*treeNode + 1].maximum, tree[2*treeNode].smaximum));
}

Node query(Node* tree, int start, int end, int treeNode, int left, int right){

    if(start > right || end < left){
        Node ans;
        ans.maximum = INT_MIN;
        ans.smaximum = INT_MIN;
        return ans;
    }

    if(start >= left && end <= right){
        return tree[treeNode];
    }

    int mid = (start + end)/2;
    Node ans1 = query(tree,start,mid,2*treeNode,left,right);
    Node ans2 = query(tree,mid+1,end,2*treeNode+1,left,right);

    Node ans;
    ans.maximum = max(ans1.maximum,ans2.maximum);
    ans.smaximum = min(max(ans1.maximum,ans2.smaximum), max(ans1.smaximum, ans2.maximum));
    return ans;
}
int main() {

	// Write your code here
    int n, q;
    
    cin >> n;
    int *arr = new int[n];
    Node *tree = new Node[4*n];
    
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }

    cin >> q;

    buildTree(arr,tree,0,n-1,1);

    for(int i = 0; i < q; i++){
        char ch;
        int l, r;
        cin >> ch >> l >> r;
        if(ch == 'Q'){
            Node ans = query(tree,0,n-1,1,l-1,r-1);
            int res = ans.maximum + ans.smaximum;
            cout << res << endl;
        }else{
            updateTree(arr,tree,0,n-1,1,l-1,r);
        }
    }
    return 0;
    
}