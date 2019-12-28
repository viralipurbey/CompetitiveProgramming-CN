#include<bits/stdc++.h>
using namespace std;
/*
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
*/

bool canDistributeEqually(int fruits){
	if((fruits % 11 )== 1)
		return true;
	else 
		return false;
}

int main(){

	// freopen("taktakin.txt","r",stdin);
	// freopen("taktakout.txt","w",stdout);

	int fruits;
	cin >> fruits;

	int fullMoons = 0;
	while(!canDistributeEqually(fruits)){
		fullMoons+=1;
		fruits *= 2;
	}
	cout << fullMoons <<" "<<fruits<<endl;
	return 0;
}