class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        
        ListNode *count, *start, *current, *prev, *next, *p;
        int i;   // Iterator
        start = head;
        prev = NULL;
        count = head;
        
        while(start){
            
            i = 0;
            while(count and i < k){
                i++;
                count = count->next;
            }
            
            if(i == k){
                current = start;
                
                // Code to reverse the linked list
                while(i > 0){
                    next = current->next;
                    current->next = prev;
                    prev = current;
                    current = next;
                    i--;
                }
                start->next = count;  // Making the last node of the reversed list points to the first node(count) of left linked list. 
                
                
                // previous pointer points to the start of the reveresed linked list.
                if(start == head) head = prev;
                else p->next = prev;
                
                p = start;
                start = count;
                
            }
            else break;
            
        }
        
        return head;
        
    }
};