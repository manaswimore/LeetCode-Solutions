/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
 

class Solution {
public:
    void reorderList(ListNode* head) {
        if (head == nullptr || head->next == nullptr)
            return;

        // Step 1: Find length
        int n = 0;
        ListNode* curr = head;

        while (curr != nullptr) {
            n++;
            curr = curr->next;
        }

        // Step 2: Find the end of the first half
        curr = head;
        for (int i = 1; i < (n + 1) / 2; i++) {
            curr = curr->next;
        }

        // Step 3: Reverse the second half
        ListNode* prev = nullptr;
        ListNode* second = curr->next;
        curr->next = nullptr;

        while (second != nullptr) {
            ListNode* nextNode = second->next;
            second->next = prev;
            prev = second;
            second = nextNode;
        }

        // Step 4: Merge both halves
        ListNode* first = head;
        second = prev;

        while (second != nullptr) {
            ListNode* nextFirst = first->next;
            ListNode* nextSecond = second->next;

            first->next = second;
            second->next = nextFirst;

            first = nextFirst;
            second = nextSecond;
        }
    }
};
