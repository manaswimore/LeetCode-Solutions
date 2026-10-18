class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size();
        int n2=nums2.size();
        int ans[n1+n2];
        int i= 0;
        int j=0;
        int k=0;
        while(i< n1 && j<n2)
        {
            if(nums1[i] < nums2[j])
            {
                ans[k]=nums1[i];
                k++;
                i++;
                
            }
            else
            {
                ans[k]=nums2[j];
                k++;
                j++;
            }
        }
        while(i<n1)
        {
            ans[k]=nums1[i];
            k++;
            i++;
        }
        while(j<n2)
        {
            ans[k]=nums2[j];
            k++;
            j++;
        }
        int a=n1+n2;
        if(a %2 == 0)
        {
            double median = (ans[a/2-1]+ans[a/2])/2.0;
            return median;
        }
        else
        {
            double median =ans[a/2];
            return median;
        }
    }
};