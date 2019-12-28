#include<bits/stdc++.h>
using namespace std;

struct Node{
	int sum;
	int max_sum;
	int best_prefix_sum;
	int best_suffix_sum;
};

void buildTree(int *arr, Node* tree, int start, int end, int treeNode){

	if(start == end){

		tree[treeNode].sum = arr[start];
		tree[treeNode].max_sum = arr[start];
		tree[treeNode].best_prefix_sum = arr[start];
		tree[treeNode].best_suffix_sum = arr[start];

		return;

	}

	int mid = (start + end)/2;
	buildTree(arr, tree, start, mid, 2 * treeNode);
	buildTree(arr, tree, mid + 1, end, 2 * treeNode + 1);

	Node left = tree[2 * treeNode];
	Node right = tree[2 * treeNode + 1];

	tree[treeNode].sum = left.sum + right.sum;
	tree[treeNode].best_prefix_sum = max(left.best_prefix_sum, left.sum + right.best_prefix_sum);
	tree[treeNode].best_suffix_sum = max(right.best_suffix_sum, right.sum + left.best_suffix_sum);

	int one = left.sum + right.best_prefix_sum;
	int two = right.sum + left.best_suffix_sum;
	int three = left.best_suffix_sum + right.best_prefix_sum;

	tree[treeNode].max_sum = max(one, max(two, max(three, max(left.max_sum, right.max_sum)))); 
}

// void updateTree(int *arr, Node* tree, int start, int end, int treeNode, int idx, int value){



// }

Node query(Node *tree, int start, int end, int treeNode, int left, int right){


	if(start > right || end < left){
		Node ans;
		ans.max_sum = INT_MIN;
		ans.sum = INT_MIN;
		ans.best_suffix_sum = INT_MIN;
		ans.best_prefix_sum = INT_MIN;
		return ans;
	}

	if(start >= left && end <= right){
		Node ans = tree[treeNode];
		return ans;
	}

	int mid = (start + end)/2;
	Node ans1 = query(tree, start, mid, 2 * treeNode, left, right);
	Node ans2 = query(tree, mid + 1, end , 2 * treeNode + 1, left, right);
	Node ans;
	ans.sum = ans1.sum + ans2.sum;
	ans.best_prefix_sum = max(ans1.best_prefix_sum, ans1.sum + ans2.best_prefix_sum);
	ans.best_suffix_sum = max(ans2.best_suffix_sum, ans2.sum + ans1.best_suffix_sum);

	int one = ans1.sum + ans2.best_prefix_sum;
	int two = ans2.sum + ans1.best_suffix_sum;
	int three = ans1.best_suffix_sum + ans2.best_prefix_sum;

	ans.max_sum = max(one, max(two, max(three, max(ans1.max_sum, ans2.max_sum))));
	return ans; 
}

int main(){

	int n, q;
	cin >> n;
	int *arr = new int[n];
	for(int i = 0; i < n; i++){
		cin >> arr[i];
	}

	Node *tree = new Node[4*n];
	cin >> q;

	buildTree(arr, tree, 0, n-1, 1);
	for(int i = 0; i < q; i++){
		int left, right;
		cin >> left>> right;
		Node ans = query(tree, 0, n-1, 1, left-1, right-1);
		cout << ans.max_sum << endl;
	}
}

