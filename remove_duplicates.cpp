#include <bits/stdc++.h>
#include <vector>
#include <set>
using namespace std;

vector<int> remove_duplicates(vector<int> input){

	set<int> s;
	vector<int> result;
	for(int i = 0; i < input.size(); i++){
		if(s.find(input[i])== s.end()){
			s.insert(input[i]);
			result.push_back(input[i]);
		}
	}
	return result;
}

int remove_duplicate(int A[],int N)
{
//Your code here
    
    set<int> s;
    int size = 0;
    for(int i = 0; i < N; i++){
        if(s.find(A[i]) == s.end()){
            s.insert(A[i]);
            size++;
        }
    }
    
    set<int>::iterator it;
    int i = 0;
    for(it = s.begin(); it != s.end(); it++,i++){
        A[i] = *it;
    }
    
    return size;
}


int main(){

	vector<int> v(6);
	int arr[6];
	for(int i = 0; i < v.size(); i++){
		cin >> v[i];
		arr[i] = v[i];
	}
	vector<int> res = remove_duplicates(v);
	vector<int>::iterator it;

	for(it = res.begin(); it != res.end(); it++){
		cout <<*it << endl;
	}

	cout <<"********************" << endl;
	int size = remove_duplicate(arr,v.size());
	
	return 0;
}