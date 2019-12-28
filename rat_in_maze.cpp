#include<bits/stdc++.h>
using namespace std;
int sol[20][20];
int maze[20][20];

bool isvalidpath(int maze[][20], int n, int row, int col){

	if(maze[row][col] == 0){
		return false;
	}

	if(sol[row][col] == 1){
		return false;
	}

	if(row == -1 || row == n || col == -1 || col == n){
		return false;
	} 

	return true;
}

void Helper(int maze[][20],int n,int row,int col){

	//base case
	if(row == (n-1) && col == (n-1)){

		sol[row][col] = 1;
		//print soln
		for(int i = 0; i < n;  i++){
			for(int j = 0; j < n; j++){
				cout << sol[i][j] <<" ";
			}
		}
		cout << endl;
		sol[row][col] = 0;
		return;

	}

	if(isvalidpath(maze,n,row,col + 1)){
		sol[row][col] = 1;
		Helper(maze,n,row,col + 1);
	}
	
	if(isvalidpath(maze,n,row + 1,col )){
		sol[row][col] = 1;
		Helper(maze,n,row + 1,col);
	}
	
	if(isvalidpath(maze,n,row ,col - 1)){
		sol[row][col] = 1;
		Helper(maze,n,row,col - 1);
	}
	
	if(isvalidpath(maze,n,row -1,col)){
		sol[row][col] = 1;
		Helper(maze,n,row - 1,col);
	}

	sol[row][col] = 0;
	return;
	
}

void ratInAMaze(int maze[][20], int n){
	
	memset(sol,0,20 * 20 * sizeof(int));

	Helper(maze,n,0,0);


}


int main(){

	int n;
	cin >> n;

	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			cin >> maze[i][j];
		}
	}

	ratInAMaze(maze,n);

	return 0;
}