/*********************************************************************************
*     File Name           :     61RotateList.cpp
*     Created By          :     edward
*     Creation Date       :     [2015-07-30 11:26]
*     Last Modified       :     [2015-07-30 11:50]
*     Description         :     Given a list, rotate the list to the right by k places, where k is non-negative.

For example:
Given 1->2->3->4->5->NULL and k = 2,
return 4->5->1->2->3->NULL.
**********************************************************************************/
#include <iostream>
using namespace std;
// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}

};
class Solution {
    public:
        ListNode* rotateRight(ListNode* head, int k) {
            if(!head || !k)
                return head;
            ListNode *p,*np;
            p = np = head;
            int n=0;
            while(np->next)
            {
                if(n<k)
                {
                    ++n;
                }
                else
                {
                    p = p->next;
                }
                np=np->next;
            }
            if(k==n)
            {
                np->next = head;
                head = p->next;
                p->next = NULL;
            }
            if(k<n)
            {
                return rotateRight(head,k%(n+1));
            }
            return head;
        }

};

