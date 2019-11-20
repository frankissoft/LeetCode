bool isPalindrome(ListNode* head) {
    if(head == nullptr) return true;
    ListNode* speed2 = head;
    ListNode* speed1 = head;
    ListNode* prev = nullptr;
    while(speed2&&speed2->next){
        speed2 = speed2->next->next;
        prev = speed1;
        speed1 = speed1->next;
    }
    // If the length is odd, do not reverese the middle element
    if(speed2 != nullptr) {
        prev = speed1;
        speed1 = speed1->next;
    }

    // Reverse the second half of the list
    prev->next = reverse_l(prev->next);

    // Move both the pointers and see if values matches
    speed2 = head; speed1 = prev->next;
    bool isPalin = compare(speed2, speed1);

    prev->next = reverse_l(prev->next);
    return isPalin;
}

ListNode* reverse_l(ListNode* head){
    if(head == nullptr || head->next == nullptr) return head;
    ListNode* cur = head;
    ListNode* prev = nullptr;
    ListNode* nex = nullptr;
    while(cur){
        nex = cur->next;
        cur->next = prev;
        prev = cur;
        cur = nex;
    }

    return prev;
}

bool compare(ListNode* speed2, ListNode* speed1){
    while(speed1){
        if(speed2->val != speed1->val) return false;
        speed2 = speed2->next;
        speed1 = speed1->next;
    }
    return true;
}
