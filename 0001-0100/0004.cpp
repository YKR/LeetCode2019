class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        /// --- MergeSort begins ---
        // vector<int> nums(nums1.size() + nums2.size());
        // int i, j, k;
        // for (i = 0, j = 0, k = 0; i < nums1.size() && j < nums2.size();)
        // {
        //     if (nums1[i] < nums2[j]) nums[k++] = nums1[i++];
        //     else nums[k++] = nums2[j++];
        // }
        // while (i < nums1.size())
        // {
        //     nums[k++] = nums1[i++];
        // }
        // while (j < nums2.size())
        // {
        //     nums[k++] = nums2[j++];
        // }
        // if (nums.size() & 1) return nums[nums.size()>>1];
        // return 0.5 * (nums[nums.size()>>1] + nums[(nums.size()>>1)-1]);
        /// --- MergeSort ends ---
        vector<int> * n1 = &nums1;
        vector<int> * n2 = &nums2;
        if (nums1.size() > nums2.size())
            n1 = &nums2, n2 = &nums1;
        int l = 0, r = n1->size();
        int halfsize = (n1->size() + n2->size()) >> 1;
        while (l <= r)
        {
            int mid = (l + r) >> 1;
            // take (mid) numbers from n1, (halfsize - mid) numbers from n2
            if (mid > 0 && (*n1)[mid - 1] > (*n2)[halfsize - mid])
            {
                // take too much from n1, shrink mid
                r = mid;
            }
            else if (mid < n1->size() && (*n1)[mid] < (*n2)[halfsize - mid - 1])
            {
                // take too much from n2, expand mid
                l = mid + 1;
            }
            else
            {
                // ok
                int lmax, rmin;
                if (mid == 0)
                {
                    if (n1->size() == 0)
                    {
                        lmax = (*n2)[halfsize - mid - 1];
                        rmin = (*n2)[halfsize - mid];
                    }
                    else
                    {
                        lmax = (*n2)[halfsize - mid - 1];
                        if (halfsize - mid < n2->size())
                            rmin = min((*n1)[mid], (*n2)[halfsize - mid]);
                        else
                            rmin = (*n1)[mid];
                    }
                }
                else if (mid == n1->size())
                {
                    rmin = (*n2)[halfsize - mid];
                    if (halfsize - mid > 0)
                        lmax = max((*n1)[mid - 1], (*n2)[halfsize - mid - 1]);
                    else
                        lmax = (*n1)[mid - 1];
                }
                else
                {
                    lmax = max((*n1)[mid - 1], (*n2)[halfsize - mid - 1]);
                    rmin = min((*n1)[mid], (*n2)[halfsize - mid]);
                }

                if ((n1->size() + n2->size()) & 1)
                    return rmin;
                else
                    return 0.5 * (lmax + rmin);
            }
        }
    }
};