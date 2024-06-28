#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;



vector<int> twoSum(vector<int> arr,int target){
    vector<int> sorted;
    sorted = arr;
    sort(sorted.begin(),sorted.end());
    int left=0;
    int right=sorted.size()-1;
    vector<int> result;


    while(left<right){
        int sum = sorted[left]+sorted[right];
        if(sum==target){

            int index1= find(arr.begin(),arr.end(),sorted[left])-arr.begin();
            int index2=find(arr.begin(),arr.end(),sorted[right])-arr.begin();
            if(index1!=index2){
                result.push_back(index1);
                result.push_back(index2);
                return result;
            }
        }else if(target<sum){
            right--;
        }
        else{
            left++;
        }
    }
}


int main() {
    vector<int> nums = {2, 7, 11, 15};
    int target = 9;

    vector<int> indices = twoSum(nums, target);
    if (indices.size() == 2) {
        cout << "Indices are: " << indices[0] << " and " << indices[1] << endl;
    } else {
        cout << "No valid indices found." << endl;
    }

    return 0;
}

//int index1 = find(arr.begin(),arr.end(),sorted[left]-arr.begin());
