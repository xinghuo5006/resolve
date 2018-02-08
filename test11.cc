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
          ListNode *temp = head;
        unordered_map<void*,int> hash; 
        while(temp)
          {
              if(hash.find(temp)!= hash.end())
                  return temp;
              hash.insert(std::unordered_map<void*,int>::value_type(temp,1));
              temp = temp->next;
          }
        return NULL;
    }
};
