#include <iostream>


struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode* deleteDuplicates(ListNode* head) {
    auto pos = head;
    auto ptr = head;
    while (head -> next != nullptr) {
        if (head -> val = ptr -> val) {
            if (ptr->next != nullprt) {
                ptr = ptr -> next;
            }
        }
        head -> next = ptr;
        head = ptr;
    }
    return pos;
}

int main() {

    return 0;
}
