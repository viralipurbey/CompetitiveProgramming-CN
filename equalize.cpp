#include<bits/stdc++.h>
using namespace std;

void swap(int & a, int & b){
	int temp = a;
	a = b;
	b = temp;
}

// void flip_a(char *a){
// 	int temp = ((int)(*a));
// 	temp = ~temp;
// 	*a = ((char)temp);
// }


int main(){

	int n;
	cin >> n;
	string a, b;
	cin >> a;
	cin >> b;
	int cost = 0;

	for(int i = 0; i < n; ){

		if(a[i] == b[i]){
			i++;
		}
		else{
			if((a[i+1] != b[i+1]) && (a[i+1] != a[i]) && ((i+1) < n)){
				swap(a[i] ,a[i+1]);
				cost++;
				i+=2;
			}
			else{
				a[i] = ~(a[i]);
				cost++;
				i++;
			}
		}
	}

	cout << cost << endl;
	return 0;

}