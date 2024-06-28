#include<iostream>
#include<vector>
#include<conio.h>
#include<unordered_map>

using namespace std;

//approach 2 using hashmaps

vector<int> twosum(vector<int> arr,int target){

    unordered_map<int,int> maps;
    vector<int> result;

    for(int i=0;i<arr.size();i++){
        int complement = target-arr[i];
        if(maps.find(complement)!=maps.end()){
            result.push_back(i);
            result.push_back(maps[complement]);
            break;

        }
        maps[arr[i]]=i;
    }
    return result;
}
int main(){

    vector<int> arr={3,6,1,9,2};
    int target=9;
    vector<int> result = twosum(arr,target);
    cout<<"the two numbers are "<<result[0]<<" and "<<result[1];
    return 0;
}