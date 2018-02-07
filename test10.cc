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
     void reorderList(ListNode *head) {
          int length = 0;
          ListNode* temp = head;
          ListNode* list1 = head;
          ListNode* list2 = head;
          if(temp!=NULL)
          {
              length++;
              temp=temp->next;
          }
         if(length<3)
             return ;
         for(int i =0; i<length/2;i++)
         {
             list2 = list2->next;
         }
         ListNode* last1=list2;
         list2 = last1->next;
         last1->next = NULL;
         //reserse the list2
         list2 = reverselist(list2);
         //combine two list
         while(list2!=NULL)
         {
             //insert
             ListNode *tmp = list2;
             list2 = list2->next;
             tmp->next = list1->next;
             list1->next = tmp;
             list1= tmp->next;
         }
     }
    ListNode*  reverselist(ListNode* m_head)
    {
        ListNode* ret = m_head;
        while(m_head->next != NULL)
        {
            ListNode* temp = m_head->next;
            m_head->next = temp->next;
            temp->next = ret;
            ret = temp;
        }
        return ret;
     }
};
