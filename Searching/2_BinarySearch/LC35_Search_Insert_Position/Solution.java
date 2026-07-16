class Solution {
    public int searchInsert(int[] nums, int target) {
        int low = 0;
        int high = nums.length - 1;
        while(low<=high){
            int mid = (low+high)/2;
            if(nums[mid]==target){
                return mid;
            }else if(target<nums[mid]){
                high = mid - 1;
            }else{
                low = mid +1;
            }
        }
        return low;
    }

    public static void main(String[] args) {
        Solution sol = new Solution();

        int[] nums = {1, 3, 5, 6};

        System.out.println(sol.searchInsert(nums, 5));
    }
}