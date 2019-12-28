#include<bits/stdc++.h>
using namespace std;

int main(){

	int n , x, y;
	cin >>n >> x >> y;
	string s;
	cin >> s;

	int num = 0;

	if(s[0] == '0'){
		num++;
	}
	for(int i = 0; i < n; i++){

		if(s[i] == '1' && s[i+1] == '0'){
			num++;
		}
	}

	long long cost;
    if(num == 0){
        cost = 0;
    }
    else{
        cost = (num - 1) *(min(x,y)) + y;
    }
	cout << cost << endl;
	return 0;
}