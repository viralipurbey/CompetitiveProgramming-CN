#include<bits/stdc++.h>
using namespace std;

void calc(int);
int main(){


	// freopen("taktakin.txt","r",stdin);
	// freopen("taktakout.txt","w",stdout);

	int f;
	cin >> f;
	calc(f);
	return 0;

}

void calc(int f){

	int count = 0;
	int nof = f;
	while(nof % 11 != 1){

		count++;
		nof = nof * 2;
	}
	cout << count <<" "<< nof<< endl;
}