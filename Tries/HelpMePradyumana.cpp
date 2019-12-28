#include<bits/stdc++.h>
using namespace std;

class trieNode{

public: 
    bool isTerminal = false;
    trieNode **children;
    trieNode(){
        children = new trieNode*[26];
        for(int i = 0; i < 26; i++){
            children[i] = NULL;
        }
    }
};

void insert(string s, trieNode *head){

    if(s.empty()){
        head->isTerminal = true;
        return;
    }

    trieNode *child;
    int index = s[0] - 'a';
    if(head -> children[index]){
        child = head -> children[index];
    }else{
        child = new trieNode();
        head -> children[index] = child;
    }

    insert(s.substr(1),child);

}

void DFS(trieNode *head, string s){
    
    if(head -> isTerminal){
        cout << s << endl;
    }

    for(int i= 0; i < 26; i++){
        if(head -> children[i]){
            char ch = 'a' + i;
            string s1(1, ch);
            DFS(head -> children[i], s + s1);
        }
    }
    
}

int query(trieNode *head, string s){

    trieNode *curr = head;
    for(int i = 0; i < s.length(); i++){
        int index = s[i] - 'a';
        trieNode *child = curr -> children[index];
        if(!child){
            cout << "No suggestions" << endl;
            return 1;
        }
        curr = child;
    }
    
    DFS(curr, s);
    return 0;
}

int main(){
    int n;
    cin >> n;
    string s;
    trieNode *head = new trieNode();
    for(int i = 0; i < n; i++){
        cin >> s;
        insert(s,head);
    }
    int q;
    cin >> q;
    for(int i = 0; i < q; i++){
        cin >> s;
        int ans = query(head, s);
        if(ans){
            insert(s, head);
        }
    }
}