/*********************************************************************************
*     File Name           :     2AddTwoNumbers.cpp
*     Created By          :     edward
*     Creation Date       :     [2015-07-01 12:05]
*     Last Modified       :     [2015-07-01 12:52]
*     Description         :      
topic:You are given two linked lists representing two non-negative numbers. The digits are stored in reverse order and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.

Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
Output: 7 -> 0 -> 8
**********************************************************************************/
//   * Definition for singly-linked list.
#include <iostream>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
class Solution {
    public:
        ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
            int r,temp;
            ListNode *p,*L;
            if(l1 && l2)
            {
                temp =l1->val + l2->val ;
                if(temp < 10)
                {
                    L = p = new ListNode(temp);
                    r=0;
                }
                else
                {
                    L = p = new ListNode(temp %10);
                    r=1;
                }
            }
            l1=l1->next;
            l2=l2->next;
            while(l1 && l2)
            {
                temp =l1->val + l2->val + r ;
                if(temp < 10)
                {
                    p->next = new ListNode(temp);
                    r=0;
                }
                else
                {
                    p->next = new ListNode(temp%10);
                    r=1;
                }
                p=p->next;
                l1=l1->next;
                l2=l2->next;
            }
            while(l1)
            {
                temp = l1->val +r;
                if(temp < 10)
                {
                    p->next = new ListNode(l1->val+r);
                    r=0;
                }
                else
                {
                    p->next = new ListNode(temp%10);
                    r=1;
                }
                p=p->next;
                l1=l1->next;
            }
            while(l2)
            {
                temp = l2->val +r;
                if(temp < 10)
                {
                    p->next = new ListNode(l2->val+r);
                    r=0;
                }
                else
                {
                    p->next = new ListNode(temp % 10);
                    r=1;
                }
                p=p->next;
                l2=l2->next;
            }
            if(r==1)
                p->next = new ListNode(r);
            return L;
        }
};

