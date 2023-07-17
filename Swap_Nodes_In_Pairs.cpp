#include <iostream>
#include <vector>
#include <climits>

using namespace std;


 struct ListNode {
     int val;
     ListNode *next;
     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
 };
 
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {

         // if head is NULL OR just having a single node, then no need to change anything 
        if(head == NULL || head -> next == NULL) 
        {
            return head;
        }
            
        ListNode* temp; // temporary pointer to store head -> next
        temp = head->next; // give temp what he want
        
        head->next = swapPairs(head->next->next); // changing links
        temp->next = head; // put temp -> next to head
        
        return temp; // now after changing links, temp act as our head
    }
    
};
void append(ListNode* head, int val)
{
    // 1. allocate node
    ListNode* new_node = new ListNode();
 
    // Used in step 5
    ListNode* last = head;
 
    // 2. Put in the data
    new_node->val = val;
 
    // 3. This new node is going to be
    // the last node, so make next of
    // it as NULL
    new_node->next = NULL;
 
    // 4. If the Linked List is empty,
    // then make the new node as head
    if (head == NULL) {
        head = new_node;
        return;
    }
 
    // 5. Else traverse till the last node
    while (last->next != NULL) {
        last = last->next;
    }
 
    // 6. Change the next of last node
    last->next = new_node;
    return;
}

void display (ListNode *head)
{
    ListNode *temp=head;
    int i=0;
    while(temp)
    {
        cout<<"the "<<((i)+1)<<" val ="<<temp->val<<endl;
        temp=temp->next;
        i++;
    }
    temp=nullptr;
}
int main(){
    
    Solution s1;
    ListNode *head=nullptr;
    ListNode *node=new ListNode();

    node->val=1;
    node->next=nullptr;
    head=node;
    append(head,2);
    append(head,3);
    append(head,4);
    append(head,5);
    display(head);
    head=s1.swapPairs(head);
    cout<<"----------------------"<<endl;
    display(head);


}