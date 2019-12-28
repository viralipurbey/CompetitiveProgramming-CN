#include<bits/stdc++.h>
using namespace std;

struct node{
    int max_sum;
    int sum;
    int best_suffix_sum;
    int best_prefix_sum;
};

void buildTree(int* arr, node* tree, int start, int end, int treeNode){
    
    if(start == end){
        tree[treeNode].sum = arr[start];
        if(arr[start] < 0){
            tree[treeNode].max_sum = 0;
        }else{
            tree[treeNode].max_sum = arr[start];
        }

        tree[treeNode].best_prefix_sum = tree[treeNode].max_sum;
        tree[treeNode].best_suffix_sum = tree[treeNode].max_sum;
        return;
    }
    
    int mid = (start + end)/2;
    buildTree(arr,tree,start,mid,2*treeNode);
    buildTree(arr,tree,mid+1,end,2*treeNode+1);

    int l = 2*treeNode;
    int r = 2*treeNode+1;

    tree[treeNode].sum = tree[l].sum + tree[r].sum;
    tree[treeNode].best_suffix_sum = max(tree[r].best_suffix_sum, tree[l].best_suffix_sum + tree[r].sum);
    tree[treeNode].best_prefix_sum = max(tree[l].best_prefix_sum, tree[r].best_prefix_sum + tree[l].sum);

    int op1 = tree[l].max_sum;
    int op2 = tree[r].max_sum;
    int op3 = tree[l].sum + tree[r].best_prefix_sum;
    int op4 = tree[r].sum + tree[l].best_suffix_sum;
    int op5 = tree[l].best_suffix_sum + tree[r].best_prefix_sum;

    tree[treeNode].max_sum = max(op1,max(op2,max(op3,max(op4,op5))));

}

node query(node* tree, int start, int end, int treeNode, int left, int right){

    if(start > right || end < left){
        node ans;
        ans.sum = 0;
        ans.max_sum = 0;
        ans.best_prefix_sum = 0;
        ans.best_suffix_sum = 0;
        return ans;
    }

    if(start >= left && end <= right){
        return tree[treeNode];
    }

    int mid = (start + end)/2;
    node ans1 = query(tree,start,mid,2*treeNode,left,right);
    node ans2 = query(tree,mid+1,end,2*treeNode+1,left,right);

    node ans;

    ans.sum = ans1.sum + ans2.sum;
    ans.best_suffix_sum = max(ans2.best_suffix_sum, ans1.best_suffix_sum + ans2.sum);
    ans.best_prefix_sum = max(ans1.best_prefix_sum, ans2.best_prefix_sum + ans1.sum);

    int op1 = ans1.max_sum;
    int op2 = ans2.max_sum;
    int op3 = ans1.sum + ans2.best_prefix_sum;
    int op4 = ans2.sum + ans1.best_suffix_sum;
    int op5 = ans1.best_suffix_sum + ans2.best_prefix_sum;

    ans.max_sum = max(op1,max(op2,max(op3,max(op4,op5))));
    return ans;
}
int main() {

    // Write your code here
    int n, q;
    
    cin >> n;
    int *arr = new int[n];
    node *tree = new node[4*n];
    
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }

    cin >> q;

    buildTree(arr,tree,0,n-1,1);

    for(int i = 0; i < q; i++){
        int l, r;
        cin >>  l >> r;
        node ans = query(tree,0,n-1,1,l-1,r-1);
        int res = ans.max_sum;
        cout << res << endl;
    }
    return 0;
    
}