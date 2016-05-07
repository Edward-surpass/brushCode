/*********************************************************************************
*     File Name           :     56MergeIntervals.cpp
*     Created By          :     edward
*     Creation Date       :     [2015-07-28 20:38]
*     Last Modified       :     [2015-07-28 21:09]
*     Description         :     Given a collection of intervals, merge all overlapping intervals.

For example,
Given [1,3],[2,6],[8,10],[15,18],
return [1,6],[8,10],[15,18].
**********************************************************************************/
#include <vector>
#include <queue>
//Definition for an interval.
using namespace std;
struct Interval {
    int start;
    int end;
    Interval() : start(0), end(0) {}
    Interval(int s, int e) : start(s), end(e) {}

};
class Solution {
    public:
        vector<Interval> merge(vector<Interval>& intervals) {
            priority_queue<int> IntSta,IntEnd;
            vector<Interval> res;
            size_t i;
            int maxnum,minnum,lefttop,righttop;
            for (i = 0; i < intervals.size(); ++i) {
                IntSta.push(intervals[i].start);
                IntEnd.push(intervals[i].end);
            }
            while(!IntSta.empty() && !IntEnd.empty())
            {
                righttop = IntEnd.top();
                IntEnd.pop();
                minnum = IntSta.top();
                if(!IntEnd.empty())
                    maxnum = IntEnd.top();
                else
                {
                    lefttop = minnum;
                    res.push_back({lefttop,righttop});
                    return res;
                }
                while(minnum<=maxnum)
                {
                    IntEnd.pop();
                    IntSta.pop();
                    minnum = IntSta.top();
                    if(!IntEnd.empty())
                    {
                        maxnum = IntEnd.top();
                    }
                    else
                    {
                        lefttop=minnum;
                        res.push_back({lefttop,righttop});
                        return res;
                    }
                }
                lefttop = minnum;
                IntSta.pop();
                res.push_back({lefttop,righttop});
            }
            return res;
        }

};

