/*********************************************************************************
*     File Name           :     21MergeTwoSortedList.cpp
*     Created By          :     edward
*     Creation Date       :     [2015-07-10 20:53]
*     Last Modified       :     [2015-07-10 21:10]
*     Description         :      
**********************************************************************************/
#include <iostream>
// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}

};
class Solution {
    public:
        ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
            if(!l1 && !l2)
                return NULL;
            if(!l1)
                return l2;
            if(!l2)
                return l1;
            ListNode *L,*p,*q;
            if(l1->val < l2->val)
            {
                L = l1;
                l1 = l1->next;
            }
            else
            {
                L = l2;
                l2 = l2->next;
            }
            p=L;
            while(l1 && l2)
            {
                if(l1->val < l2->val)
                {
                    q=l1;
                    l1 = l1->next;
                }
                else
                {
                    q=l2;
                    l2 = l2->next;
                }
                p->next = q;
                p=q;
            }
            while(l1)
            {
                p->next = l1;
                break;
            }
            while(l2)
            {
                p->next = l2;
                break;
            }
            return L;
        }

};
int main(int argc, char *argv[])
{
    ListNode l1(2);
    ListNode l2(1);
    Solution so;
    so.mergeTwoLists(&l1,&l2);
    return 0;
}
