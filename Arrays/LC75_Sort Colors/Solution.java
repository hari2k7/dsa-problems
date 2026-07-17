import java.util.Arrays;

class Solution {
    public void sortColors(int[] nums) {
        int low=0, mid=0, high=nums.length-1;

        while(mid<=high){
            if(nums[mid]==0){
                int temp = nums[low];
                nums[low] = nums[mid];
                nums[mid] = temp;

                mid++;
                low++;
            }else if(nums[mid]==1){
                mid++;
            }else{
                int temp = nums[high];
                nums[high] = nums[mid];
                nums[mid] = temp;

                high--;
            }
        }
    }

    public static void main(String[] args) {
        Solution sol = new Solution();

        int[] nums = {2, 0, 2, 1, 1, 0};

        System.out.println("Before sorting: " + Arrays.toString(nums));

        sol.sortColors(nums);

        System.out.println("After sorting:  " + Arrays.toString(nums));
    }
}