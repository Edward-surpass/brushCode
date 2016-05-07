/*********************************************************************************
*     File Name           :     23SwapNodesinPairs.cpp
*     Created By          :     edward
*     Creation Date       :     [2015-07-11 18:01]
*     Last Modified       :     [2015-07-11 18:28]
*     Description         :      
topic:Given a linked list, swap every two adjacent nodes and return its head.

For example,
Given 1->2->3->4, you should return the list as 2->1->4->3.

Your algorithm should use only constant space. You may not modify the values in the list, only nodes itself can be changed.
**********************************************************************************/
#include <iostream>
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}

};
class Solution {
    public:
        ListNode* swapPairs(ListNode* head) {
            if(!head||!head->next)
                return head;
            ListNode *p = head->next,*pre = head,*q,*pn;
            head = new ListNode(0);
            q = head;
            while(pre && p)
            {
                pn = p->next;
                q->next = p;
                p->next = pre;
                q = pre;
                pre = pn;
                if(pre)
                    p = pre->next;
            }
            q->next = pre;
            p = head;
            head = head->next;
            delete(p);
            return head;
        }
};

