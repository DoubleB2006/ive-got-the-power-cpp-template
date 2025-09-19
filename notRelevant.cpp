#include <bits/stdc++.h>
using namespace std;

struct Node {
    int val;
    Node* next;
    Node(int v): val(v), next(nullptr) {}
};

/* ---------- basic construction / utilities ---------- */
void push_front(Node*& head, int v) {
    Node* n = new Node(v);
    n->next = head;
    head = n;
}

void push_back(Node*& head, int v) {
    Node* n = new Node(v);
    if (!head) { head = n; return; }
    Node* cur = head;
    while (cur->next) cur = cur->next;
    cur->next = n;
}

Node* search(Node* head, int target) {
    for (Node* cur = head; cur; cur = cur->next)
        if (cur->val == target) return cur;
    return nullptr;
}

bool delete_first(Node*& head, int target) {
    Node dummy(0); dummy.next = head;
    Node* prev = &dummy;
    while (prev->next && prev->next->val != target) prev = prev->next;
    if (!prev->next) return false;
    Node* dead = prev->next;
    prev->next = dead->next;
    if (dead == head) head = dummy.next;
    delete dead;
    return true;
}

void free_list(Node*& head) {
    while (head) {
        Node* nxt = head->next;
        delete head;
        head = nxt;
    }
}

/* ---------- algorithms on linked lists ---------- */
// 1) Reverse a list (iterative, O(n), O(1) space)
void reverse_list(Node*& head) {
    Node *prev = nullptr, *cur = head;
    while (cur) {
        Node* nxt = cur->next;
        cur->next = prev;
        prev = cur;
        cur = nxt;
    }
    head = prev;
}

// 2) Find middle (slow/fast pointers)
Node* middle(Node* head) {
    Node *slow = head, *fast = head;
    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow; // for even length: the 2nd middle
}

// 3) Detect cycle (Floyd) and return entry if present
Node* cycle_entry(Node* head) {
    Node *slow = head, *fast = head;
    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast) {              // meet
            slow = head;
            while (slow != fast) { slow = slow->next; fast = fast->next; }
            return slow;                 // entry
        }
    }
    return nullptr;
}

// 4) Merge two sorted lists (stable)
Node* merge_sorted(Node* a, Node* b) {
    Node dummy(0);
    Node* tail = &dummy;
    while (a && b) {
        if (a->val <= b->val) { tail->next = a; a = a->next; }
        else { tail->next = b; b = b->next; }
        tail = tail->next;
    }
    tail->next = a ? a : b;
    return dummy.next;
}

// 5) Remove N-th node from end (one pass)
bool remove_nth_from_end(Node*& head, int n) {
    Node dummy(0); dummy.next = head;
    Node *fast = &dummy, *slow = &dummy;
    for (int i = 0; i < n+1; ++i) {
        if (!fast) return false; // n > length
        fast = fast->next;
    }
    while (fast) { fast = fast->next; slow = slow->next; }
    Node* dead = slow->next;
    if (!dead) return false;
    slow->next = dead->next;
    if (dead == head) head = dummy.next;
    delete dead;
    return true;
}

// 6) In-place merge sort (O(n log n), stable, linked-list friendly)
void split_in_half(Node* head, Node*& a, Node*& b) {
    Node *slow = head, *fast = head->next;
    while (fast && fast->next) { slow = slow->next; fast = fast->next->next; }
    a = head;
    b = slow->next;
    slow->next = nullptr;
}

void mergesort(Node*& head) {
    if (!head || !head->next) return;
    Node *a=nullptr, *b=nullptr;
    split_in_half(head, a, b);
    mergesort(a);
    mergesort(b);
    head = merge_sorted(a, b);
}

// 7) Palindrome check: O(n) time, O(1) space
bool is_palindrome(Node* head) {
    if (!head || !head->next) return true;
    // find middle
    Node *slow=head, *fast=head;
    while (fast && fast->next) { slow=slow->next; fast=fast->next->next; }
    // reverse second half
    Node *prev=nullptr, *cur=slow;
    while (cur) { Node* nxt=cur->next; cur->next=prev; prev=cur; cur=nxt; }
    // compare halves
    Node *p1=head, *p2=prev;
    bool ok = true;
    while (p2) { if (p1->val!=p2->val) { ok=false; break; } p1=p1->next; p2=p2->next; }
    // (optional) restore list by reversing back
    return ok;
}

/* ---------- quick demo ---------- */
int main() {
    Node* head = nullptr;
    for (int x: {5,1,4,2,3}) push_front(head, x);  // list: 3->2->4->1->5
    mergesort(head);                                // list: 1->2->3->4->5
    Node* mid = middle(head);                       // 3
    reverse_list(head);                             // 5->4->3->2->1
    remove_nth_from_end(head, 2);                   // remove '2': 5->4->3->1
    cout << "Middle was: " << mid->val << "\n";
    cout << "Final list: ";
    for (Node* c=head; c; c=c->next) cout << c->val << " ";
    cout << "\nPalindrome? " << (is_palindrome(head) ? "yes":"no") << "\n";
    free_list(head);
}






















