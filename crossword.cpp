#include<bits/stdc++.h>
using namespace std;
#define N 10

bool isvalidvertical(char cross[N][N] , int row, int col, string word){

	int count = 0;
	for(int i = 0; i < word.length(); i++){
		if((cross[row + i][col] == '-' ) || (cross[row + i][col] == word[i])){
			count++;
		}
		if(cross[row + i][col] == '+'){
			return false;
		}
	}

	if(count != word.size()){
		return false;
	}

	return true;

}

void setvertical(char cross[N][N],int row, int col, string word, bool helper[]){

	for(int i = 0; i < word.length(); i++){
		if(cross[row + i][col] == '-'){
			cross[row + i][col] = word[i];
			helper[i] = true;
		}
		else{
			helper[i] = false;
		}
	}
}

void resetvertical(char cross[N][N], int row, int col, bool helper[], int size){

	for(int i = 0; i < size; i++){
		if(helper[i]){
			cross[row + i][col] = '-';
		}
	}
}

bool isvalidhorizontal(char cross[N][N] , int row, int col, string word){

	int count = 0;
	for(int i = 0; i < word.length(); i++){
		if((cross[row][col + i] == '-' ) || (cross[row ][col + i] == word[i])){
			count++;
		}
		if(cross[row][col + i] == '+'){
			return false;
		}
	}

	if(count != word.size()){
		return false;
	}

	return true;
}

void sethorizontal(char cross[N][N],int row, int col, string word, bool helper[]){


	for(int i = 0; i < word.length(); i++){
		if(cross[row][col + i] == '-'){
			cross[row][col + i] = word[i];
			helper[i] = true;
		}
		else{
			helper[i] = false;
		}
	}
}

void resethorizontal(char cross[N][N], int row, int col, bool helper[], int size){

	for(int i = 0; i < size; i++){
		if(helper[i]){
			cross[row][col + i] = '-';
		}
	}
}

bool crossword(char cross[N][N], vector<string> words, int index){

	if(index == words.size()){
		//print the crossword

		for(int i = 0; i < N; i++){
			for(int j = 0; j < N; j++){
				cout << cross[i][j];
			}

			cout << endl;
		}

		return true;

	}

	for(int i = 0; i < N; i++){
		for(int j = 0; j < N; j++){
			if(cross[i][j] == '-' || cross[i][j] == words[index][0]){

				if(isvalidvertical(cross,i,j,words[index])){
					bool *helper = new bool[words[index].size()];

					setvertical(cross,i,j,words[index],helper);
					bool flag = crossword(cross,words,index + 1);
					if(flag){
						return true;
					}
					else{
						resetvertical(cross,i,j,helper,words[index].size());
					}
				}

				if(isvalidhorizontal(cross,i,j,words[index])){
					bool *helper = new bool[words[index].size()];

					sethorizontal(cross,i,j,words[index],helper);
					bool flag = crossword(cross,words,index + 1);
					if(flag){
						return true;
					}
					else{
						resethorizontal(cross,i,j,helper,words[index].size());
					}
				}

			}
		}

	}

	return false;
}

int main(){

	char cross[N][N];

	for(int i = 0; i < N; i++){
		for(int j = 0; j < N; j++){
			cin >> cross[i][j];
		}
	}

	vector<string> words;
	string input;
	cin >> input;
	int j = 0;

	for(int i = 0; i <= input.size(); i++){
		if((input[i] == ';') || i == input.size()){
			words.push_back(input.substr(j,(i-j)));
			j = i + 1;

		}
	}

	crossword(cross,words,0);

	for(int i = 0; i < N; i++){
			for(int j = 0; j < N; j++){
				cout << cross[i][j];
			}

			cout << endl;
		}

	return 0;
}