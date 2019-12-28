#include<bits/stdc++.h>
using namespace std;
#define MAXN 100

int visited[MAXN][MAXN];
int cx[]={1,-1,0,0,1,-1,1,-1};
int cy[]={0,0,1,-1,1,1,-1,-1};
char pattern[11]={'C','O','D','I','N','G','N','I','N','J','A'};

bool validpath(int i, int j, int N, int M){
    if(i >= 0 && i < N && j >= 0 && j < M){
        return true;
    }
    return false;
}

int DFS(char Graph[][MAXN], int x, int y, int index, int N, int M){

    if(index == 11){
        return 1;
    }

    visited[x][y] = 1;
    int found = 0;
    for(int i = 0; i < 8; i++){
        int dx = x + cx[i];
        int dy = y + cy[i];
        if(validpath(dx,dy, N, M) && Graph[dx][dy] == pattern[index] && !visited[dx][dy]){
            found = found | DFS(Graph, dx, dy, index + 1, N, M);
        }
    }
    visited[x][y] = 0;
    return found;
}

int solve(char Graph[][MAXN],int N, int M)
{
	int found = 0;
    memset(visited, 0, sizeof(visited));

    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            if(Graph[i][j] == 'C'){
                found = DFS(Graph, i, j, 1, N, M);
                if(found){
                    break;
                }
            }
        }
        if(found){
            break;
        }
    }
    return found;
}

int main(){
    int N, M;
    cin >> N >> M;
    char Graph[MAXN][MAXN];
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            cin >> Graph[i][j];
        }
    }

    cout << solve(Graph, N, M) << endl;
}