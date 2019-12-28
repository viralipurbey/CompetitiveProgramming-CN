#include<bits/stdc++.h>
using namespace std;

long calc_energy(long n, long energy[]){

	long ans = 0;
	long i = 0;
	for(long j = 1; j < (n-1); j++){
		if(abs(energy[i]) > abs(energy[j])){
			ans += (j-i)*energy[i] + ((pow(j,2) - pow(i,2))*(pow(energy[i],2))); 
			cout << i << j << endl;
			i = j;

		}
		else if(abs(energy[i]) == abs(energy[j])){
			if(energy[i] > 0){
				ans += (j-i)*energy[i] + ((pow(j,2) - pow(i,2))*(pow(energy[i],2))); 
				cout << i << j << endl;
				i = j;
			}
		}
	}

	// while(i < (n-1)){
	// 	long j = i + 1;
	// 	while(j <(n-1)){
	// 		if((abs(energy[i]) > abs(energy[j])) || (abs(energy[i]) == abs(energy[j]) && energy[i] > 0)){
	// 			break;
	// 		}
	// 		else{
	// 			j++;
	// 		}
	// 	}
	// 	ans += (j-i)*energy[i] + (j*j - i*i)*energy[i]*energy[i];
	// 	i = j;
	// }

	return ans;
}
int main(){
	long n;
	cin >> n;
	long energy[n];
	for(int i = 0; i <n ; i++){
		cin >> energy[i];
	}

	long ans = calc_energy(n,energy);
	cout << ans << endl;
	return 0;
}