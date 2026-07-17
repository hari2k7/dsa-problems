import java.util.Arrays;

class Solution {
    public int majorityElement(int[] nums) {
        int element = 0;
        int count = 0;

        for (int i = 0; i < nums.length; i++) {
            if (count == 0) {
                count = 1;
                element = nums[i];
            } else if (nums[i] == element) {
                count++;
            } else {
                count--;
            }
        }

        int cnt = 0;
        for (int j = 0; j < nums.length; j++) {
            if (nums[j] == element)
                cnt++;
        }

        if (cnt > nums.length / 2) {
            return element;
        }
        return -1;
    }

    public static void main(String[] args) {
        Solution sol = new Solution();

        int[] nums1 = {3, 2, 3};

        System.out.println("Array: " + Arrays.toString(nums1));
        System.out.println("Majority Element: " + sol.majorityElement(nums1));

    }
}