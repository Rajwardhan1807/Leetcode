class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {

        // Get size of both arrays
        int m = nums1.size();
        int n = nums2.size();


        // Always do binary search on the smaller array
        // because it is faster
        if (m > n)
            return findMedianSortedArrays(nums2, nums1);


        // Binary search range for nums1
        int low = 0;
        int high = m;


        while (low <= high) {

            // cut1 tells where we divide nums1
            int cut1 = (low + high) / 2;


            // cut2 tells where we divide nums2
            // so that left side has half of the total elements
            int cut2 = (m + n + 1) / 2 - cut1;


            // Left side value of nums1
            // If there is nothing on left, take -infinity
            int l1 = (cut1 == 0) ? INT_MIN : nums1[cut1 - 1];


            // Left side value of nums2
            // If there is nothing on left, take -infinity
            int l2 = (cut2 == 0) ? INT_MIN : nums2[cut2 - 1];


            // Right side value of nums1
            // If there is nothing on right, take +infinity
            int r1 = (cut1 == m) ? INT_MAX : nums1[cut1];


            // Right side value of nums2
            // If there is nothing on right, take +infinity
            int r2 = (cut2 == n) ? INT_MAX : nums2[cut2];


            // Check if we found the correct division
            // All left values should be smaller than right values
            if (l1 <= r2 && l2 <= r1) {


                // If total elements are even
                // Median is average of middle two numbers
                if ((m + n) % 2 == 0) {
                    return (max(l1, l2) + min(r1, r2)) / 2.0;
                }


                // If total elements are odd
                // Median is the biggest value from left side
                return max(l1, l2);
            }


            // If nums1 left value is too big
            // Move the cut towards left
            else if (l1 > r2) {
                high = cut1 - 1;
            }


            // Otherwise move the cut towards right
            else {
                low = cut1 + 1;
            }
        }


        // This will never happen for valid input
        return 0.0;
    }
};