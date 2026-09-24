// 0 ms | 18.5 MB
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
    struct compare{
        bool operator()(ListNode*a , ListNode* b){
            return a->val>b->val;
        }
    };
    
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode* , vector<ListNode*> , compare> minHeap;
        for(ListNode* head: lists){
            if(head!=nullptr){
                minHeap.push(head);
            }
        }
        ListNode dummy(0);
        ListNode* tail = &dummy;
        while(!minHeap.empty()){
            ListNode* node= minHeap.top();
            minHeap.pop();
            tail->next=node;
            tail=tail->next;
            if(node->next!=nullptr) minHeap.push(node->next);
        }
        return dummy.next;
    }
};