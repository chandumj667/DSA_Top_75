/*
    287. Find the Duplicate Number

    LeetCode Problem Link : https://leetcode.com/problems/find-the-duplicate-number/

    Given an array of integers nums containing n + 1 integers where each integer is in the range [1, n] inclusive.

There is only one repeated number in nums, return this repeated number.

You must solve the problem without modifying the array nums and uses only constant extra space.


Example 1:

Input: nums = [1,3,4,2,2]
Output: 2
Example 2:

Input: nums = [3,1,3,4,2]
Output: 3


Constraints:

1 <= n <= 105
nums.length == n + 1
1 <= nums[i] <= n
All the integers in nums appear only once except for precisely one integer which appears two or more times.


Follow up:

How can we prove that at least one duplicate number must exist in nums?
Can you solve the problem in linear runtime complexity?
*/


#include<bits/stdc++.h>
using namespace std;


/*
    using brute force approach 
    sort the array and check the adjacent elements if arr[i] == arr[i+1] then the duplicate element is arr[i]

    Time complexity = O(N logN)
    Space complexity = O(1)
*/

/*
    using optimal approach 
    LinkedList cycle detection method
    using two pointers slow  and fast. slow pointer moves one step where as fast pointer moves two steps until they are at same index
    if they collide at same index then change the fast pointer to index 0 and move it by one step
    if they collide again then the value at their collision is the duplicate one

    Time complexity : O(N)
    space complexity : O(1)
*/

void brute_force(vector<int>vec, int n){
    sort(vec.begin(), vec.end());
    for (int i = 0; i<n-1; i++){
        if(vec[i] == vec[i+1]){
            cout << endl;
            cout << "from Brute force approach. The duplicate value is " << vec[i]<<endl;
            return;
        }
    }
}


void optimal(vector<int>vec, int n){
    int slow = vec[0];
    int fast = vec[0];
    do{
        slow = vec[slow];
        fast = vec[vec[fast]];
    } while (slow != fast);
    fast = vec[0];
    while(slow != fast){
        slow = vec[slow];
        fast = vec[fast];
    }
    cout << "from Optimal approach. The duplicate value is " << slow;
}


int main(){
    int n;
    cout << "Enter the size of the array ";
    cin >> n;
    vector<int> vec(n);
    cout << "Enter " << n << " elements in to the array" << endl;
    for (int i = 0; i < n; i++){
        cin >> vec[i];
    }
    brute_force(vec, n);
    optimal(vec, n);
    return 0;
}