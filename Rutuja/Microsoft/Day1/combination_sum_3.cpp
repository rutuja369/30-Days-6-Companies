/*Combination Sum 3: https://leetcode.com/problems/combination-sum-iii/description/  */

#include<bits/stdc++.h>
using namespace std;

/*
Approach: Recursion used 
T.C=O(2^n)
S.C: x*k ( x-> combinations, k-> length of subsequence)

*/

class Solution {
public:

    void rec(int index, int sum, vector<vector<int>> &ans, vector<int> &ds, vector<int> a, int target, int k )
    {
        //base case
        if(index== a.size())
        {
            if(target == sum)
            {
                if(ds.size()== k)
                {
                    ans.push_back(ds);
                }
            }
                return ;
        }

        //Case1: pick

        if(a[index] < target && ds.size()<k )
        {
            sum+=a[index];
            ds.push_back(a[index]);
            rec(index+1, sum, ans, ds, a, target, k );
            ds.pop_back();
            sum-= a[index];
        }

        //Case2: notpick
        rec(index+1, sum, ans, ds, a, target, k);

    }

    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> ans;
        vector<int> ds;
        vector<int> a{1, 2, 3, 4, 5, 6, 7, 8, 9};
        int target=n, len=k;

        rec(0, 0, ans, ds, a, target, len);

        return ans;
    }
};