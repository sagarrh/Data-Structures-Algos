#include<iostream>
#include<vector>


//breaking large problem into smaller ones and then solving them kindof like divide and conquer 

using namespace std;

//using recurive approach 

int solveRecursive(int n,int k){
    if(n==1) return 0;
    return ((solveRecursive(n-1,k)+k)%n);
}

int solveIterative(int n ,int k){
    int winner=0;
    for(int i=2;i<=n;i++){
        winner=(winner+k)%i;
    }
    return winner;


}
 

int main(){
    int n =5;
    int k=2;
    int answer= solveRecursive(n,k);
    //adding one to make it one-indexed
    cout<<answer+1;
    cout<<"  and  ";

    int answer2= solveIterative(n,k);
    cout<<answer2+1;
    return 0;


}