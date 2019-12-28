#include <string>
using namespace std;

string input[10] ={ "", "","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
int keypad(int num, string output[]){
    /* Insert all the possible combinations of the integer number into the output string array. You do not need to
    print anything, just return the number of strings inserted into the array.
    */
    if(num == 0 || num == 1){
        output[0] = "";
        return 1;
    }
    int smallnum = num / 10;
    int rem = num % 10;
    
    int small_ans = keypad(smallnum,output);
    
    if(rem <2){
        
        return small_ans;
    }
    else{
        string *temp = new string[small_ans];
        for(int i = 0; i < small_ans; i++){
            temp[i] = output[i];
        }
        for(int i = 0; i < input[rem].size(); i++){
            for(int j = 0; j < small_ans; j++){
                output[small_ans * i + j] = temp[j] + input[rem][i];
            }
        }
        
        return small_ans * input[rem].size();
    }

    
}