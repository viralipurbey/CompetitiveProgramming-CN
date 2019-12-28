#include<bits/stdc++.h>
using namespace std;

struct Tree{
	int ss;
	int s;
};

struct Lazy{
	int value;
	int type = 0;
};

void buildTree(int *arr, Tree* tree, int start, int end, int treeNode){

	if(start == end){
		tree[treeNode].ss = arr[start] * arr[start];
		tree[treeNode].s = arr[start];
		return;
	}

	int mid = (start + end)/2;
	buildTree(arr,tree,start,mid,2*treeNode);
	buildTree(arr,tree,mid+1,end,2*treeNode+1);

	tree[treeNode].ss = tree[2*treeNode].ss + tree[2*treeNode+1].ss;
	tree[treeNode].s = tree[2*treeNode].s + tree[2*treeNode+1].s;
}

void updateSegmentTreeLazyInc(Tree* tree, Lazy* lazy, int low, int high, int startR, int endR, int currPos, int val){

	if(low > high){
		return;
	}

	if(lazy[currPos].value != 0){
		tree[currPos] += lazy[currPos];

		if(low != high){
			lazy[2*currPos] += lazy[currPos];
			lazy[2*currPos+1] += lazy[currPos];

		}

		lazy[currPos] = 0;
	}

	//No overlap
	if(startR > high || endR < low){
		return;
	}

	//Complete overlap
	if(startR <= low && endR >= high){

		tree[currPos] += inc;

		if(low != high){
			lazy[2*currPos] += inc;
			lazy[2*currPos+1] += inc;
		}

		return;
	}

	//Partial Overlap

	int mid = (low + high)/2;

	updateSegmentTreeLazy(tree, lazy, low, mid, startR, endR, 2*currPos , inc);
	updateSegmentTreeLazy(tree, lazy, mid+1, high, startR, endR, 2*currPos+1 , inc);
	tree[currPos] = min(tree[2*currPos], tree[2*currPos+1]);
}


int main(){

	int T;
	cin >> T;
	while(T--){

		int N, Q;
		cin >> N >> Q;

		int* arr = new int[N];
		for(int i = 0; i < N; i++){
			cin >> arr[i];
		}

		int* tree = new Tree[4*N];
		int* lazy = new Lazy[4*N];

		buildTree(arr,tree,0,N-1,1);


	}

}