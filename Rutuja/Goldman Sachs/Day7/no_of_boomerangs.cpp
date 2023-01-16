/*
https://leetcode.com/problems/number-of-boomerangs/description/
*/

#include<bits/stdc++.h>
using namespace std;

/* 
Approach:
T.C: O(n^2)
S.C : O(n) -> map 
- For a boomerange to form condition-> for each single point: 
step1: cal its dist with all other points and store them in map
step2: for x equal distances -> no. of tuples possible are x(x-1); (since order also matters)
step3: add on the no . of tuples formed in case of each point to res-> return res 
*/

class Solution {
public:
    int numberOfBoomerangs(vector<vector<int>>& points) {
        int n= points.size(), ans=0;
        for(int i=0; i<n; i++)
        {
            map<double, int> mp;

            for(int j=0 ; j<n ; j++)
            {
                if(i==j)
                continue;

                double dist = sqrt( pow((points[i][0] - points[j][0] ), 2)  + pow((points[i][1]- points[j][1]), 2 )  ) ;
                mp[dist]++; 
            }

            for(auto it: mp)
            {
                if(it.second)
                ans += it.second * ( it.second -1)   ;
            }

        }
        
        return ans;
    }
};
