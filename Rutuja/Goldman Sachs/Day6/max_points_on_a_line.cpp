/*
https://leetcode.com/problems/max-points-on-a-line/description/
*/

#include<bits/stdc++.h>
using namespace std;
/*
Approach: 
- Step1: For each point pair it with next remaining pts 
- Step2: For each pair check if the points are coincident or has a slope->infinity 
- Step3: If not in above two cases, cal the slope and incr the count if same slope is occurred
- Step4: For each unique slope, cal the slope with max count
- Step5: For each count -> add the coincident pts if exists
- Step6: Repeat the same for each new point and return the max ans 
*/

class Solution {
public:
    double findslope(vector<int> p1, vector<int> p2 )
    {
        double slope=0;
        if(abs(p2[1]-p1[1]) == 0)
        slope= 0;
        else
        slope =  (double (p1[1]-p2[1])/(p2[0]-p1[0] ) );
        return slope;
    }

    int maxPoints(vector<vector<int>>& points) {
        // vector<double> slope;
        // vector<int> point= points[0];
        int ans=0;
        for(int i=0; i<points.size(); i++)
        {
            unordered_map<double, int> mp;
            int coincident=1, maxcount=0;
            //considering next remaining pts to pair with curr point
            for(int j=i+1; j<points.size() ; j++)
            {
                if(points[i][0]==points[j][0] && points[i][1]==points[j][1])
                    coincident++; //if points -> coincident
                else if(points[i][0]==points[j][0])
                    mp[INT_MAX]++; //if slope-> infinity 
                else 
                {
                    double slope =(findslope(points[i], points[j]));
                    mp[slope]++;
                }

            }

        for(auto &it: mp)
        {
            maxcount= max(maxcount,it.second);
        }
        maxcount+= coincident; //add coincident pts if exist
        ans = max(ans, maxcount); //count max for

        }

        return ans;
    }
};