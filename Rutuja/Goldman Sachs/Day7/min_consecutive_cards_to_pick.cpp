/*
https://leetcode.com/problems/minimum-consecutive-cards-to-pick-up/description/
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minimumCardPickup(vector<int>& cards) {
        unordered_map<int , int> visited, mp;
        // vector<int> diff;
        
        int count=INT_MAX, endpoint=0, flag=0;
        for(int i=0; i<cards.size(); i++)
        {
              mp[cards[i]]++;
        }
        for(auto it: mp)
        {
            if( it.second >1)
            {
                flag=1;
                break;
            }
        }
        if(flag==0)
        return -1;

        for(int i=0; i<cards.size(); i++)
        {
          int n = cards[i]; 
          if(visited.count(n))
          {
            
            endpoint = i;
            count = min(count, endpoint - visited[n]);
            visited[n] = i;
          }
          else
          {
            visited[n] = i;   
          }
        }
        
        return count + 1;
    }
};