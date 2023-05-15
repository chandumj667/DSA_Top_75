/*
    1. Two Sum

    LeetCode Problem Link : https://leetcode.com/problems/two-sum/

Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.

You may assume that each input would have exactly one solution, and you may not use the same element twice.
You can return the answer in any order.


Example 1:
Input: nums = [2,7,11,15], target = 9
Output: [0,1]
Explanation: Because nums[0] + nums[1] == 9, we return [0, 1].


Example 2:
Input: nums = [3,2,4], target = 6
Output: [1,2]


Example 3:
Input: nums = [3,3], target = 6
Output: [0,1]


Constraints:
2 <= nums.length <= 104
-109 <= nums[i] <= 109
-109 <= target <= 109
Only one valid answer exists.
*/



/*
    using brute force approach
    using nested loop for checking each element with every other element their sum up is equal to the given target then return those two indices
    for(i=0; i<n; i++){
        for(int j=0; j<n; j++){
            (i==j) continue;
            (vec[i]+vec[j] == target)return i, j;
        }
    }

    here we can start the inner loop from i+1 as the previous element already checks with the current element in its previous iteration
    for(i=0; i<n; i++){
        for(int j=i+1; j<n; j++){
            (i==j) continue;
            (vec[i]+vec[j] == target)return i, j;
        }
    }

    Time complexity : O(N^2) => Exponential
    Space complexity : O(1) => Constant
*/

/*
    using better approach
    using hashing as we have the target value with us and current index value then we need find the second value
    by storing the values in hashmap we can reduce the time complexity from O(N^2) to something O(N)

    store the element and it's corresponding index in the hashmap then traverse the vector/array
    if the value - target == second_value then check if the  second value whether it is present in hashmap or not if present then return the index
    if not present then push the value in to the hashmap with its index value
    repeat the process

    Time complexity :
    O(N) or O(N^2) in worst case as we take unordered map
    O(N logN) if we take ordered map / map;

    Space complexity : O(N); as we are using a data structure (Map / Unordered map)

*/

/*
    using better or optimal
    using two pointer approach
    it is also take O(N logN) but with out using map / unordered map

    sort the array ascending order place a left index at 0 and right index at last element and sum up the two elements
    if their sum == target  return the two values which are in left index and right index;
    if their sum > target reduce the right index by one and check the result again;
    if their sum < target increase the left index by one

    Time complexity : O(N logN)
    space complexity : O(1)
*/

#include<bits/stdc++.h>
using namespace std;


// void print(vector<int> vec, int n)
// {
//     cout << "from Better approach. The two indices are ";
//     for (int i = 0; i < n; i++)
//     {
//         cout << vec[i] << " ";
//     }
//     cout << endl;
// }

void brute_force(vector<int> vec, int n, int k)
{
    // n == size
    // k == target
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i == j)
                continue;
            if (vec[i] + vec[j] == k)
            {
                cout << endl<< "from Brute force approach. The two Values are " << vec[i] << " " <<vec[j] << endl;
                return;
            }
        }
    }
}


void better(vector<int>vec,int n, int k){
    unordered_map<int, int> ump;
    vector<int> ans;
    for (int i = 0; i < n; i++){
        // int val = vec[i];
        // int diff = k - val;
        if(ump.find(k-vec[i]) != ump.end()){
            cout << "from Better approach. The two values are " 
            << k-vec[i]<< " " << vec[i]<<endl;
            // ans.push_back(ump[diff]);
            // ans.push_back(vec[i]);
            // print(ans, 2);
            break;
        }
        ump[vec[i]] = i;
    }
}


void optimal(vector<int>vec, int n, int k){
    sort(vec.begin(), vec.end());
    int left = 0;
    int right = n - 1;
    while(left < right){
        if((vec[left] + vec[right]) == k){
            cout << "from optimal approach. The two values are " << vec[left] << " "<< vec[right] << endl;
            break;
        }
        else if((vec[left]+vec[right]) > k)
            right--;
        else if((vec[left]+vec[right]) < k)
            left++;
    }
}

int main(){
    int size;
    cout << "Enter the size of the array ";
    cin >> size;
    vector<int> vec(size);
    cout << "Enter " << size << " element in to the array" << endl;
    for (int i = 0; i < size; i++){
        cin >> vec[i];
        // cout << vec[i] << " ";
    }
    int target;
    cout << "Enter the target value ";
    cin >> target;
    brute_force(vec, size, target);
    better(vec, size, target);
    optimal(vec, size, target);
    return 0;
}