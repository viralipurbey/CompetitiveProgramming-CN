#include<bits/stdc++.h>
using namespace std;

class trieNode{

public:
	trieNode** children;
	int weight;

	trieNode(){
		children = new trieNode*[26];
		for(int i = 0; i < 26;i++){
			children[i] = NULL;
		}
		weight = 0;
	}
};

void insert(string s, int weight, trieNode* head){

	if(s.empty()){
		return;
	}

	trieNode* child;
	int index = s[0] - 'a';
	if(head->children[index]){
		child = head->children[index];
	}else{
		child = new trieNode();
		head->children[index] = child;
	}

	if(head->weight < weight){
		head->weight = weight;
	}
	insert(s.substr(1),weight,child);
}

int searchBest(string s, trieNode* head){

	int bestWeight = -1;
	trieNode* curr = head;
	for(int i = 0; i < s.length(); i++){
		int index = s[i] - 'a';
		trieNode* child = curr->children[index];
		if(child){
			curr = child;
			bestWeight = child->weight;
		}
		else{
			return -1;
		}
	}

	return bestWeight;
}

int main(){

	int n, q;

	cin >> n >>q;
	trieNode* head = new trieNode();
	for(int i = 0; i < n; i++){
		string s;
		int w;
		cin >> s >> w;
		insert(s, w, head);
	}
	for(int i = 0; i < q; i++){
		string sub;
		cin >> sub;
		int ans = searchBest(sub, head);
		cout << ans << endl;
	}
} 