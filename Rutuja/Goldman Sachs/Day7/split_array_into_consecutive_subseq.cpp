/*
https://leetcode.com/problems/split-array-into-consecutive-subsequences/description/
*/

#include<bits/stdc++.h>
using namespace std;

/* 
Approach:

- Each point has two options:- 
                            -> It can be a part of existing grp
                            -> It can create a new grp
                            -> If not return false

*/

class Solution {
public:
    bool isPossible(vector<int>& nums) {
       unordered_map<int , int> avail, vac;
       int grp=0;
    
       for(int i=0; i<nums.size(); i++)
       {
           avail[nums[i]]++;
       }
       for(int i=0; i<nums.size(); i++)
       {
           int n = nums[i];
           if(avail[n]<=0)
           continue;
           else if(vac[n] > 0)
           {
               //first checking if the number can be accomodated in any existing grp -> reduce its freq from vac and avail-> as its consumed
               vac[n]--;
               avail[n]--;
               //create a vacancy for its next consecutive element
               vac[n+1]++; //imp
           }
           else if(avail[n]>0 && avail[n+1]>0 && avail[n+2]>0 )
           {
               //second checking if the number can create a new grp -> only if its 2 next consecutive ele are avail 

                grp++;  //new grp created

                //reduce the freq of these 3 elements as they are consumed
                avail[n]--;
                avail[n+1]--;
                avail[n+2]--;
                
                //create a vacancy for 4th consecutive element as it can be accomodated in future
                vac[n+3]++;
           }
           else
           return false; //each num in list has only above two options -> if not satisfying -> false

       }
       
       //At last check if any num is still remaining in the array
       for(int i=0; i<nums.size(); i++)
       {
           if(avail[i] > 0)
           return false;
       }

        return true;
    }
};