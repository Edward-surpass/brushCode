/*********************************************************************************
*     File Name           :     24ReverseNodesink-Group.cpp
*     Created By          :     edward
*     Creation Date       :     [2015-07-11 18:31]
*     Last Modified       :     [2015-07-11 18:51]
*     Description         :      
topic:Given a linked list, reverse the nodes of a linked list k at a time and return its modified list.

If the number of nodes is not a multiple of k then left-out nodes in the end should remain as it is.

You may not alter the values in the nodes, only nodes itself may be changed.

Only constant memory is allowed.

For example,
Given this linked list: 1->2->3->4->5

For k = 2, you should return: 2->1->4->3->5

For k = 3, you should return: 3->2->1->4->5
**********************************************************************************/
#include <iostream>
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}

};
class Solution {
    public:
        ListNode* reverseKGroup(ListNode* head, int k) {
            if(!head)
                return NULL;
            ListNode *p,*pn,*q,*pt;
            int num=0;
            p = head;
            head = new ListNode(0);
            q = head;
            while(p)
            {
                ++num;
                if(num == 1)
                    pt = p;
                pn = p->next;
                p->next = q->next;
                q->next = p;
                if(num == k)
                {
                    q = pt;
                    num = 0;
                }
                p = pn;
            }
            if(num != 0)
            {
                p=q->next;
                q->next = NULL;
                while(p)
                {
                    pn = p->next;
                    p->next = q->next;
                    q->next = p;
                    p = pn;
                }
            }
            p = head;
            head = head->next;
            delete(p);
            return head;
        }

};

