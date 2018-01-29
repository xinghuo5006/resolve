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
        static bool carrierFreqLessThan(const int &a, const int &b)
    {
        return a > b;
    }
        ListNode *sortList(ListNode *head) {
            ListNode* itr = head;
            vector<int> unsortnum;
            while(itr!=NULL)
            {
                unsortnum.push_back(itr->val);
                itr = itr->next;
            }
             std::sort(unsortnum.begin(), unsortnum.end(), carrierFreqLessThan);
              ListNode* head2 = NULL; //new a list,or initiailze head to null
              //head  = NULL;
             for(int i=0;i<unsortnum.size();i++)
             {
               ListNode* itr2 = new ListNode(unsortnum.at(i));
               itr2->next = head2;
               head2 = itr2;
             }

            return head2;
        }
    };
