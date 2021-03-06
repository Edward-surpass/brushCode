/*********************************************************************************
*     File Name           :     19RemoveNthNodeFromEndOfList.cpp
*     Created By          :     edward
*     Creation Date       :     [2015-07-08 19:41]
*     Last Modified       :     [2015-07-09 10:27]
*     Description         :      
topic:Given a linked list, remove the nth node from the end of list and return its head.

For example,

   Given linked list: 1->2->3->4->5, and n = 2.

      After removing the second node from the end, the linked list becomes 1->2->3->5.
Note:
Given n will always be valid.
Try to do this in one pass.
**********************************************************************************/
#include <iostream>
//Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
class Solution {
    public:
        ListNode* removeNthFromEnd(ListNode* head, int n) {
            ListNode *p = head,*pn=head;
            int i =0;
            while(p->next)
            {
                ++i;
                if(i>n)
                {
                    pn=pn->next;
                }
                p = p->next;
            }
            if(i>=n)
            {
                p = pn->next;
                pn->next = p->next;
                delete(p);
            }
            else
            {
                p = head;
                head = head->next;
                delete(p);
            }
            return head;
        }
};

