/*********************************************************************************
*     File Name           :     22MergeKSortedLists.cpp
*     Created By          :     edward
*     Creation Date       :     [2015-07-11 16:32]
*     Last Modified       :     [2015-07-11 18:00]
*     Descrioption         :      
topic:Merge k sorted linked lists and return it as one sorted list. Analyze and describe its complexity.
**********************************************************************************/
#include <queue>
#include <iostream>
#include <map>
#include <vector>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
class cmp{
    public:
        bool operator()(const ListNode *lh,const ListNode *rh)
        {
            return lh->val > rh->val;
        }
};
class Solution {
    public:
        ListNode* mergeKLists(vector<ListNode*>& lists) {
            if(lists.empty() )
                return NULL;
            ListNode *L,*p,*q;
            size_t i,j;
            priority_queue<ListNode*,vector<ListNode *>,cmp> nowheap;
            for (i = 0; i < lists.size(); ++i) {
                if(lists[i])
                {
                    nowheap.push(lists[i]);
                    lists[i]=NULL;
                }
            }
            L =p = new ListNode(0);
            while(!nowheap.empty())
            {
                q=nowheap.top();
                if(q->next)
                    nowheap.push(q->next);
                q->next = p->next;
                p->next = q;
                p=p->next;
                nowheap.pop();
            }
            p=L;
            L=L->next;
            delete(p);
            return L;
        }

};
