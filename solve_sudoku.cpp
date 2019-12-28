#include<bits/stdc++.h>
using namespace std;
#define N 9

bool findEmptyLoc(int grid[N][N], int &row, int &col){

	for(int i = 0; i < N; i++){
		for(int j = 0; j < N; j++){
			if(grid[i][j] == 0){
				row = i;
				col = j;
				return true;
			}
		}
	}
	return false;
}

bool isSafe(int grid[N][N], int row, int col, int num){

	//for row
	for(int j = 0; j < N; j++){
		if(grid[row][j] == num){
			return false;
		}
	}

	// for col
	for(int i = 0; i < N; i++){
		if(grid[i][col] == num){
			return false;
		}
	}

	// for grid
	int rowfactor = row - (row%3);
	int colfactor = col -(col%3);
	for(int i = rowfactor; i <rowfactor+3; i++){
		for(int j = colfactor; j <colfactor + 3; j++){
			if(grid[i][j] == num){
				return false;
			}
		}
	}

	return true;
}

bool solve_sudoku(int grid[N][N]){

	int row, col;
	if(!findEmptyLoc(grid,row,col)){
		return true;
	}

	for(int i = 1; i <= N; i++){
		if(isSafe(grid,row,col,i)){
			grid[row][col] = i;
			if(solve_sudoku(grid)){
				return true;
			}
			grid[row][col] = 0;
		}
	}

	return false;
}

int main(){

	int grid[9][9];

	for(int i = 0; i < N; i++){
		string s;
		cin >> s;
		for(int j = 0; j < s.length(); j++){
			grid[i][j] = s[j] - '0';
		}
	}
	
	solve_sudoku(grid);

	for(int i = 0; i < N; i++){
		for(int j= 0; j < N; j++){
			cout << grid[i][j];
		}
		cout << endl;
	}
}