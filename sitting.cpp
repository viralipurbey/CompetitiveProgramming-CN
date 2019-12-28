#include<bits/stdc++.h>
using namespace std;

int main(){


	// freopen("sitin.txt","r",stdin);
	// freopen("sitout.txt","w",stdout);

	int r,s;
	cin >> r >> s;
	int nos = r * s;
	int tickets;
	cin >> tickets;

	int nosit , nostd;
	if(tickets <= nos){
		cout << tickets <<" "<< 0 << endl;
	}
	else{
		cout << nos <<" "<< (tickets - nos) << endl;
	}

	return 0;
}