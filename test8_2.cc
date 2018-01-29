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
ListNode* findtheposition(ListNode * m_head,ListNode * m_target)
{
        ListNode * pos =m_head;
         while(m_head!=NULL && m_head->val < m_target->val)
         {
             pos = m_head;
            m_head = m_head->next;
          }
        return pos;
}
ListNode *insertionSortList(ListNode *head) {
       ListNode * temp = head;
       if(head ==NULL || head->next ==NULL)
           return head;
       while(temp->next != NULL)
       {
         ListNode * cur = temp->next;
         if(temp->val <= cur->val)
           {
              temp = temp->next; 
              continue;
           }
         //delete the node
           temp->next = cur->next;
           if(cur->val <= head->val)
           {
                //new head
             cur->next = head;
             head = cur;
             continue;
           }
         ListNode * pos = findtheposition(head , cur);
         //insert
         cur->next = pos->next;
         pos->next = cur;
       }
     return  head;
    }
};
