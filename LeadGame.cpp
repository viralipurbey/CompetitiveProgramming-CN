#include<bits/stdc++.h>
using namespace std;

int main(){

	int n;
	cin >> n;   // no of matches

	int cs1 = 0, cs2 = 0;
	int max_lead = 0;
	int winner = 1;

	while(n--){
		int s1, s2;
		cin >> s1 >> s2;

		cs1 += s1;
		cs2 += s2;
		int lead = 0;
		int curr_win = 1;

		if(cs1 >= cs2){
			lead = cs1 - cs2;
		}
		else{
			lead = cs2 - cs1;
			curr_win = 2;
		}
		if(max_lead < lead){
			max_lead = lead;
			winner = curr_win;
		}
	}
	cout << winner <<" "<< max_lead<< endl;

	return 0;
}	