import java.util.Arrays;

class Solution {
    public int[] searchRange(int[] nums, int target) {
        int first = firstOcc(nums,target);
        int last = lastOcc(nums,target);

        return new int[]{first, last};
    }

    int firstOcc(int[] nums, int target){
        int low=0;
        int high = nums.length -1;
        int f = -1;

        while(low<=high){
            int mid = (low+high)/2;

            if(target==nums[mid]){
                f = mid;
                high = mid-1;
            }else if(target>nums[mid]){
                low = mid+1;
            }else{
                high= mid-1;
            }
        }
        return f;
    }

    int lastOcc(int[] nums, int target){
        int low=0;
        int high=nums.length-1;
        int l=-1;
        
        while(low<=high){
            int mid=(low+high)/2;
            
            if(nums[mid]==target){
                l=mid;
                low=mid+1;
            }else if(nums[mid]<target){
                low = mid +1;
            }else{
                high = mid-1;
            }
        }
        return l;
    }

    public static void main(String[] args) {

        Solution sol = new Solution();

        int[] nums = {5, 7, 7, 8, 8, 10};
        int target = 8;

        int[] result = sol.searchRange(nums, target);

        System.out.println(Arrays.toString(result));
    }
}