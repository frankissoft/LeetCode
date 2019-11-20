#include <iostream>
#include <string>

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    std::stack<int> s;




    bool isPalindrome(ListNode* head) {
        int i = 0;
        ListNode rev_head(head.val);
        while (head.next != NULL) {
            ListNode newp(head.next);
            newp.next = rev.head;
            i++;
        }
        for (int j = 0; j <= (i / 2); j++) {
            if (head != newp) {
                return false;
            }
            else {
                head = head.next;
                newp = newp.next;
            }
        }

    }
};
