/*
    121. Best Time to Buy and Sell Stock
    LeetCode Problem link: https://leetcode.com/problems/best-time-to-buy-and-sell-stock/

    You are given an array prices where prices[i] is the price of a given stock on the ith day.

    You want to maximize your profit by choosing a single day to buy one stock and choosing a different day in the future to sell that stock.

    Return the maximum profit you can achieve from this transaction. If you cannot achieve any profit, return 0.



    Example 1:

    Input: prices = [7,1,5,3,6,4]
    Output: 5
    Explanation: Buy on day 2 (price = 1) and sell on day 5 (price = 6), profit = 6-1 = 5.
    Note that buying on day 2 and selling on day 1 is not allowed because you must buy before you sell.
    Example 2:

    Input: prices = [7,6,4,3,1]
    Output: 0
    Explanation: In this case, no transactions are done and the max profit = 0.


    Constraints:

    1 <= prices.length <= 105
    0 <= prices[i] <= 104
*/


#include<bits/stdc++.h>
using namespace std;

/*
    Using brute force approach 
    Keeping ith index at an element and check the right side array of the element which is greater one and sell it 
    do this for each and every element  
    and get the maximum diff as max-diff of every element and return maximum from the max-diff of all the elements that is the profit 

    time complexity : O(N^2)
    space complexity : O(1)
*/

/*
    using better approach
    using a minimal variable to store the minimum values on the right part of the array and profit variable to check the mak=x profit of all the difference of minimal values

    Time complexity : O(N)
    space complexity : O(1)
*/

void brute_force(vector<int>vec, int n){
    int profit = INT_MIN;
    for (int i = 0; i < n; i++){
        int diff_each = INT_MIN;
        for (int j = i + 1; j < n; j++){
            diff_each = max(diff_each, vec[j] - vec[i]);
        }
        profit = max(profit, diff_each);
    }
    cout << endl;
    cout << "From Brute force approach we get the profit " << profit << endl;
    return;
}

void optimal(vector<int> vec, int n){
    int minimal = INT_MAX;
    int profit = 0;
    for (int i = 0; i < n; i++){
        minimal = min(minimal, vec[i]);
        profit = max(profit, vec[i] - minimal);
    }
    cout << "From Optimal approach we get the profit " << profit << endl;
    return;
}

int main(){
    int n;
    cout << "Enter the size of the array ";
    cin >> n;
    // n == size
    vector<int> vec(n);
    cout<<"Enter "<<n<<" elements in to the array "<<endl;
    for (int i = 0; i < n; i++){
        cin >> vec[i];
    }
    brute_force(vec, n);
    optimal(vec, n);
    return 0;
}