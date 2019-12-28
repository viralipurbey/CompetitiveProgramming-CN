#include<bits/stdc++.h>
using namespace std;

class trieNode{

public:
	int lvalue = 0;
	int rvalue = 0;
	trieNode* left;
	trieNode* right;
};

void insert(int n, trieNode* head){

	trieNode* curr = head;

	for(int i = 31; i >= 0; i--){
		int b = (n>>i)&1;

		if(b == 0){

			if(!curr->left){
				curr->left = new trieNode();
			}
			curr->lvalue++;
			curr = curr->left;

		}else{

			if(!curr->right){
				curr->right = new trieNode();
			}
			curr->rvalue++;
			curr = curr->right;
		}
	}
}

int query(trieNode* head, int value, int K){

	trieNode* curr = head;
	int count = 0;
	for(int j = 31; j >= 0; j--){
		int b = (value >> j)&1;
		int k = (K >> j)&1;

		if(b==1 && k== 1){
			count += curr->rvalue;
			if(curr->left)
				curr = curr->left;
			else{
				break;
			}
		}
		else if(b==1 && k == 0){
			if(curr->right)
				curr = curr->right;
			else
				break;
		}
		else if(b==0 && k == 1){
			count += curr->lvalue;
			if(curr->right)
				curr = curr->right;
			else
				break;
		}
		else{
			if(curr->left)
				curr = curr->left;
			else
				break;
		}
	}
	return count;
}



int SubXOR(trieNode* head, int* arr, int n, int k){

	int count = 0;
	int curr = 0;

	for(int i = 0; i < n; i++){
		curr = curr ^ arr[i];
		insert(curr, head);
		int curr_ans = query(head, curr, k);
		count += curr_ans;

	}
	
	return count;
}

int main(){

	int t;
	cin  >>t;
	while(t--){
		int n, k;
		cin >> n >> k;
		int arr[n];
		for(int i = 0; i < n; i++){
			cin >> arr[i];
		}
		trieNode* head = new trieNode();

		cout << SubXOR(head, arr, n, k) << endl;
	}
}


// import java.util.Scanner;

// class trieNodes{
//     trieNodes left;
//     trieNodes right;
//     int lvalue;
//     int rvalue;
//     trieNodes(){
//         int lvalue=0;
//         int rvalue=0;
//     }
// }

// public class Main {
    
//       private static void insert(int n, trieNodes head) {
//         trieNodes curr = head;
//         for (int i = 31; i >= 0; i--) {
//             int b = (n >> i) & 1;

//             if (b == 0) {
//                 if (curr.left == null) {
//                     curr.left = new trieNodes();

//                 }
//                 curr.lvalue++;
//                 curr = curr.left;
//             } else {
//                 if (curr.right == null) {
//                     curr.right = new trieNodes();

//                 }
//                 curr.rvalue++;
//                 curr = curr.right;
//             }
//         }
//     }

//     private static long countXor(trieNodes head, int value, int k) {
//         trieNodes curr = head;
//         long count = 0;
//         // System.out.println(value+" "+k);//
//         for (int i = 31; i >= 0; i--) {
//             int a = (value >> i) & 1;
//             int b = (k >> i) & 1;
//             // System.out.println((i)+" "+a+" "+b);//
//             if (a == 1 && b == 1) {
//                 count += curr.rvalue;
//                 if (curr.left != null) {
//                     curr = curr.left;
//                 } else {
//                     break;
//                 }
//             } else if (a == 1 && b == 0) {
//                 if (curr.right != null) {
//                     curr = curr.right;
//                 } else {
//                     break;
//                 }

//             } else if (a == 0 && b == 1) {
//                 count += curr.lvalue;
//                 if (curr.right != null) {
//                     curr = curr.right;

//                 } else {
//                     break;
//                 }

//             } else if (a == 0 && b == 0) {
//                 if (curr.left != null) {
//                     curr = curr.left;
//                 } else {
//                     break;
//                 }
//             }

//         }
//         return count;
//     }


	
// 	public static void main(String[] args) {
// 		// Write your code here
        
//            Scanner sc = new Scanner(System.in);
//         int t = sc.nextInt();
//         while (t > 0) {
//             t--;
//             int n = sc.nextInt();
//             int k = sc.nextInt();
//             int arr[] = new int[n];
//             for (int i = 0; i < n; i++) {
//                 arr[i] = sc.nextInt();
//             }

//             trieNodes head = new trieNodes();
//             insert(0, head);
//             int currXor = 0;
//             int count = 0;
//             for (int i = 0; i < n; i++) {
//                 currXor = currXor ^ arr[i];
//                 long ans = countXor(head, currXor, k);
//                 // System.out.println(ans);//
//                 insert(currXor, head);
//                 count += ans;

//             }
//             System.out.println(count);

//         }

//     }



// 	}
