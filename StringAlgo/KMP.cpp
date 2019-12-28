#include<bits/stdc++.h>
using namespace std;

int* getlps(string pattern){
	int n = pattern.length();
	int* lps = new int[n];

	lps[0] = 0;
	int i = 1, j = 0;
	while(i < n){
		if(pattern[j] == pattern[i]){
			lps[i] = j + 1;
			i++;
			j++;
		}else{
			if(j != 0){
				j = lps[j-1];
			}
			else{
				lps[i] = 0;
				i++;
			}
			
		}
	}
	return lps;
}

int kmpSearch(string text, string pattern){
	int lentext = text.length();
	int lenPat = pattern.length();
	int *lps = getlps(pattern);
	int index = -1;

	int i = 0;
	int j = 0;
	while(i < lentext && j < lenPat){

		
		if(text[i] == text[j]){
			i++;
			j++;
		}
		else{
			if(j != 0){
				j = lps[j-1];
			}
			else{
				i++;
			}
		}
	}
	if(j == lenPat){
		index = i-lenPat;
	}
	return index;
	
}

int main(){

	string str = "abcxabcdabcdabcy";
	string substr = "abcdabcy";
	cout << kmpSearch(str, substr) << endl;
}