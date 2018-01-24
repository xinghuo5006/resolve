class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int j=0;
        if(nums2.empty()&& nums1.empty())
        {
            return 0;
        }
        if(nums1.empty()&& !nums2.empty())
        {
            if(nums2.size()==1)
                return nums2[0];
             if(nums2.size()%2==0)
        {
            return (nums2[nums2.size()/2-1]+nums2[nums2.size()/2])/2.0;
        }
        else
        {
            return nums2[nums2.size()/2];
        }
        }
        if(nums2.empty()&& !nums1.empty())
        {
            if(nums1.size()==1)
                return nums1[0];
             if(nums1.size()%2==0)
        {
            return (nums1[nums1.size()/2-1]+nums1[nums1.size()/2])/2.0;
        }
        else
        {
            return nums1[nums1.size()/2];
        }
        }
        for(int i=0;i<nums1.size()+1 && j<nums2.size();)
        {
            if(i==nums1.size())
            {
                 nums1.push_back(nums2[j]);
                j++;
                continue;
            }
            if(nums2[j]>=nums1[i])
            {
                i++;
            }
            else
            {
                //insert into nums vector
                nums1.insert(nums1.begin()+i,nums2[j]);
                j++;
            }
        }
        if(nums1.size()%2==0)
        {
            return (nums1[nums1.size()/2-1]+nums1[nums1.size()/2])/2.0;
        }
        else
        {
            return nums1[nums1.size()/2];
        }
    }
};
