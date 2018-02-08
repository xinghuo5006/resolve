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
    ListNode *detectCycle(ListNode *head) {
          if(head==NULL)
              return NULL;
          if(head->next ==NULL)
              return NULL;
          if(head->next->next ==NULL)
              return NULL;
          ListNode *slow = head->next;
          ListNode *fast = head->next->next;
          while(fast!=NULL && fast->next !=NULL && slow !=fast)
          {
              slow = slow->next;
              fast = fast->next->next;
            //  if(slow == fast)
              //    break;
          }
        if(fast ==NULL || fast->next ==NULL)
        {
            return NULL;
        }
        else
        {
            //has cycle ,need print the cross point
            fast = head;
            while(fast!=slow)
            {
                fast = fast->next;
                slow= slow->next;
            }
            return fast;
        }
    }
};
