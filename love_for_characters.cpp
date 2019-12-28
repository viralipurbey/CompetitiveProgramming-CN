#include<bits/stdc++.h>
using namespace std;

void countchar(char* s, int n){

	int *arr = new int[3];
	for(int i =0; i < n; i++){
		if(s[i] == 'a'){
			arr[0]++;
		}
		if(s[i] == 's'){
			arr[1]++;
		}
		if(s[i] == 'p'){
			arr[2]++;
		}
	}
	for(int i =0; i < 3; i++){
		cout << arr[i] <<" ";
	}
	
	cout << endl;
}

int main()
{
    int n;
    cin >> n;
    char* s = new char[n];
    int i;
    cin >> s;
	countchar(s, n);
	return 0;
}
