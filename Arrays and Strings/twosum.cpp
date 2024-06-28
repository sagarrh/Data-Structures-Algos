#include<iostream>
#include<vector>

using namespace std;

//using brute force

vector<int> twosum(vector<int> arr,int target){
    vector<int> result;

    for(int i=0;i<arr.size();i++){
        for(int j=0;j<arr.size();j++){
            if(i!=j && arr[i]+arr[j]==target){
                result.push_back(arr[i]);
                result.push_back(arr[j]);
                break;
            }
        }
    }

    return result;
}
int main(){
    vector<int> arr={1,2,3,4,5,7};
    int target=8;

    vector<int> result = twosum(arr,target);

    cout<<"the two numbers are "<<result[0]<<" and "<<result[1];
    return 0;
}