#include <bits/stdc++.h>
using namespace std;

int num_codes(string s){
	
	long long *arr = new long long[s.length() + 1]();
    long long m = pow(10,9) + 7;
	arr[0] = 1;
	arr[1] = 1;
	for(int i = 2; i <= s.length(); i++){
        if(s[i-1]!='0')
		    arr[i] = arr[i-1];
		int i1 = s[i-1] -'0';
		int i2 = s[i-2] - '0';
        int x = i2 * 10 + i1;
		if(x <= 26 && x>=10){
			long long temp = (arr[i] + arr[i-2])%m;
            arr[i] = temp;
		}
	}

	long long output = arr[s.length()];
	delete[] arr;
	return output;
}

int main()
{   
    string s;
    cin >> s;
    while(s != "0"){
    	int n = num_codes(s);
    	cout << n << endl;
        cin >> s;
    }
    return 0;
}
