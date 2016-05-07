/*********************************************************************************
*     File Name           :     82RemoveDuplicateSortedListII.cpp
*     Created By          :     edward
*     Creation Date       :     [2016-04-18 20:14]
*     Last Modified       :     [2016-04-18 20:54]
*     Description         :      
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
        ListNode* deleteDuplicates(ListNode* head) {

            while(head && head->next && head->val == head->next->val)
            {
                while(head->next && head->val == head->next->val)
                {
                    head = head->next;

                }
                head = head->next;

            }
            if(!head)
                return head;
            ListNode *q, *p = head;

            int temp_val;
            while( p -> next )
            {

                q = p->next;
                temp_val = q->val;
                if(q->next && q->next->val == temp_val)
                {
                    while (q->next && q->next->val == temp_val)
                    {
                        q = q->next;

                    }

                    p->next = q->next;

                }
                else
                {
                    p = p->next;

                }

            }
            return head;

        }


};
