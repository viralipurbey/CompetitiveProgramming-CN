#include<bits/stdc++.h>
using namespace std;

void replaceCharacter(char input[], char c1, char c2) {
    
    if(input[0] == '\0'){
        return;
    }
    
    if(input[0] != c1){
        replaceCharacter(input + 1,c1,c2);
    }
    else{
        input[0] = c2;
        replaceCharacter(input + 1, c1 ,c2);
    }
}
void removeConsecutiveDuplicates(char *input) {

    if(input[0] == '\0'){
        return;
    }
    
    if(input[0] != input[1]){
        removeConsecutiveDuplicates(input + 1);
    }
    else{
        int i = 1;
        for(; input[i] != '\0'; i++){
            input[i-1] = input[i];
        }
        input[i-1] = input[i];
        removeConsecutiveDuplicates(input);
    }

}

void removeX(char s[]){
	if(s[0] == '\0'){
		return;
	}

	if(s[0] != 'x'){
		removeX(s+1);
	}
	else{
		int i = 1;
		for(; s[i] != '\0'; i++){
			s[i-1] = s[i];
		}
		s[i-1] = s[i];
		removeX(s);
	}
}
int length(char s[]){
	if(s[0] == '\0'){
		return 0;
	}
	int smalloutput = length(s+1);
	return 1 + smalloutput;
}
int main(){

	char str[100];
	cin >> str;

	int len = length(str);
	cout << len << endl;

	// removeX(str);
	// cout << str << endl;

	// removeConsecutiveDuplicates(str);
	// cout << str << endl;
	char c1,c2;
	cin >> c1, c2;

	replaceCharacter(str,c1,c2);
	cout << str << endl;
}