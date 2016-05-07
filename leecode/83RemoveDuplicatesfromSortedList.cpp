/*********************************************************************************
*     File Name           :     83RemoveDuplicatesfromSortedList.cpp
*     Created By          :     edward
*     Creation Date       :     [2016-04-18 20:55]
*     Last Modified       :     [2016-04-18 21:08]
*     Description         :      
**********************************************************************************/
   // Definition for singly-linked list.
#include <istream>
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}

};
class Solution {
    public:
        ListNode* deleteDuplicates(ListNode* head) {
            if(!head)
                return head;
            ListNode *p = head;
            ListNode *q;
            while(p)
            {
                q = p;
                while(q && q->next && q->val == q->next->val)
                    q->next = q->next->next;
                p = p->next;
            }
            return head;
        }

};

