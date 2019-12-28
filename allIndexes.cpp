#include<bits/stdc++.h>
using namespace std;
static int num = 0;
static int pos = 0;

int allIndexes(int input[], int size, int x, int output[]) {
  /* Don't write main().
     Don't read input, it is passed as function argument.
     Save all the indexes in the output array passed and return the size of output array.
     Taking input and printing output is handled automatically.
  */
    if(size == 1){
        if(input[0] == x){
            output[pos] = num;
            pos++;
            return pos;
        }
        else
          return pos;
    }
    if(input[0] == x){
        output[pos] = num;
        pos++;
        num++;
    
    }
    else{
        num++;
    }
    allIndexes(input+1,size-1,x,output);
    return pos;
    
    

}
int main(){
  int n;
  cin >> n;
  int *input = new int[n];
  int *output = new int[n];

  for(int i = 0; i<n; i++){
    cin >> input[i];
  }
  int x;
  cin >> x;
  int size = allIndexes(input, n, x, output);
  for(int i = 0; i < size; i++){
    cout << output[i] <<" ";
  }
  cout << endl;
  return 0;

}