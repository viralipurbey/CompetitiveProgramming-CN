#include<bits/stdc++.h>
using namespace std;
int findFrequency(vector<int> v, int x){
    
    // Your code here
    int count = 0;
    vector<int>::iterator it;
    for(it = v.begin(); it != v.end(); it++){
        if(*it == x){
            count++;
        }
    }
    
    return count;
}
int main(){
	int T;
	cin >> T;
	while(T--){

		vector<int> v;
		int n;
		cin >> n;
		int num;

		for(int i = 0; i < n ; i++){
			cin >> num;
			v.push_back(num);
		}
		int x;
		cin >> x;

		int ans = findFrequency(v,x);
		cout << ans << endl;
	}

	return 0;
}