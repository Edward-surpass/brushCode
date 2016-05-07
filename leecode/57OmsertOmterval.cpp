/*********************************************************************************
*     File Name           :     56MergeIntervals.cpp
*     Created By          :     edward
*     Creation Date       :     [et of non-overlapping intervals, insert a new interval into the intervals (merge if necessary).

You may assume that the intervals were initially sorted according to their start times.

Example 1:
Given intervals [1,3],[6,9], insert and merge [2,5] in as [1,5],[6,9].

Example 2:
Given [1,2],[3,5],[6,7],[8,10],[12,16], insert and merge [4,9] in as [1,2],[3,10],[12,16].

This is because the new interval [4,9] overlaps with [3,5],[6,7],[8,10].
**********************************************************************************/
#include <vector>
#include <queue>
#include <algorithm>
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
        vector<Interval> insert(vector<Interval>& intervals, Interval newInterval) {
            priority_queue<int> IntSta,IntEnd;
            vector<Interval> res;
            size_t i;
            bool isbreak = false;
            int maxnum,minnum,lefttop,righttop;
            for (i = 0; i < intervals.size(); ++i) {
                IntSta.push(intervals[i].start);
                IntEnd.push(intervals[i].end);
            }
            IntSta.push(newInterval.start);
            IntEnd.push(newInterval.end);
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
                    break;
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
                        isbreak = true;
                        break;
                    }
                }
                if(isbreak)
                    break;
                lefttop = minnum;
                IntSta.pop();
                res.push_back({lefttop,righttop});
            }
            int len = res.size();
            for (i = 0; i < len/2; ++i) {
                swap(res[i],res[len-i-1]);
            }
            return res;
        }

};

