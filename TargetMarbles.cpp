#include<bits/stdc++.h>
using namespace std;

int main(){

	int n , target;
	cin >> n >> target;

	int marbles[n];

	for(int i = 0; i < n; i++){
		cin >> marbles[i];
	}

	int sum ;
    bool flag = false;
	for(int i = 0 ; i < n; i++){
        sum = 0;
		for(int j = i; j < n; j++){
			sum += marbles[j];
			if(sum == target){
                flag = true;
				cout <<"true"<< endl;
				for(int k = i; k <= j; k++)
					cout << marbles[k] <<" ";
			}
			else if(sum > target)
				break;
		}
		if(flag == true)
			break;
	}
    if(flag == false)
        cout << "false";
	cout << endl;
	return 0;

}