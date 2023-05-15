/*
    238. Product of Array Except Self
    LeetCode Problem Link : https://leetcode.com/problems/product-of-array-except-self/

    Given an integer array nums, return an array answer such that answer[i] is equal to the product of all the elements of nums except nums[i].

The product of any prefix or suffix of nums is guaranteed to fit in a 32-bit integer.

You must write an algorithm that runs in O(n) time and without using the division operation.


Example 1:

Input: nums = [1,2,3,4]
Output: [24,12,8,6]


Example 2:

Input: nums = [-1,1,0,-3,3]
Output: [0,0,9,0,0]

Constraints:

2 <= nums.length <= 105
-30 <= nums[i] <= 30
The product of any prefix or suffix of nums is guaranteed to fit in a 32-bit integer.


Follow up: Can you solve the problem in O(1) extra space complexity? (The output array does not count as extra space for space complexity analysis.)
*/


#include<bits/stdc++.h>
using namespace std;

/*
    brute force approach
    in this approach we use an extra vector or array to store the result array
    traverse the array and multiply all the values in the array and store the result as total_mul
    then traverse the array. ans[i]  = total_mul / arr[i]
    we get the resultant array return it.

    Time Complexity : O(N) + O(N) = O(2N) => O(N)
    Space complexity : O(N)

*/


/*
    optimal approach
    index ith value is the product of all the elements left of ith index and product of all the elements right of ith index and product of them 
    
    Time complexity : O(N)
    space complexity : O(1)
*/
void print(vector<int>vec, int n){
    cout << endl;
    for (int i = 0; i<n; i++){
        cout << vec[i] << " ";
    }
}

void brute_force(vector<int>vec, int n){
    long mul = 1;
    for (int i = 0; i<n; i++){
        mul *= vec[i];
    }
    vector<int> ans(n);
    for (int i = 0; i < n; i++){
        ans[i] = mul / vec[i];
    }
    cout << "form brute force approach ";
    print(ans, n);
}


void optimal(vector<int>vec, int n){
    int right_product;
    vector<int> out(n);
    out[0] = 1;
    right_product = 1;
    
    for(int i = 1; i < n; i++)
        out[i] = out[i-1]*vec[i-1];//calculate left elements product for each index i
    

    for(int i = n-2; i >= 0; i--){  //from right to left compute right elements product and multiply to leftProduct at index i
        right_product = right_product * vec[i+1];
        out[i] =  out[i] * right_product;
    }
    print(out, n);
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