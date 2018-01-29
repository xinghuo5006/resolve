/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {  ///////////Here is a block to traverse the list when use prevoious List,so correct way is to create a new list to place the node member.
                  /////////// the first way is right, the point just is a address,the assignment between two point is just a transport of value.
public:
    ListNode *insertionSortList(ListNode *head) {
       ListNode * temp = head;
       ListNode * previous1 =NULL;
       while(temp != NULL)
       {
         ListNode * previous2 =NULL;
         int refval= temp->val;
         ListNode * temp2=head;
         while(temp2!=temp)
         {
           if(temp2->val > refval)
              {
                if(temp2 = head)
                {
                   previous1->next = temp->next;  //delete the temp node
                   temp->next = head;
                   head = temp;
                   break;
                     //insert before the head , new head
                }
                previous1->next = temp->next;  //delete the temp node
                temp->next = previous2->next;
                previous2->next = temp;
                break;
               }       //insert into the correct position
            previous2 = temp2;
            temp2 = previous2->next;
                
          }
         previous1 = temp;
         temp = temp->next; 
       }
     return  head;
    }
};
