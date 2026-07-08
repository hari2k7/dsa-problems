import java.util.LinkedHashSet;
import java.util.Set;

public class RemoveDuplicates {

    // Using LinkedHashSet (O(n) extra space)
    public static int removeDuplicatesUsingSet(int[] nums) {
        Set<Integer> set = new LinkedHashSet<>();

        for (int num : nums) {
            set.add(num);
        }

        int i = 0;
        for (int n : set) {
            nums[i++] = n;
        }

        return set.size();
    }

    // Using Two Pointers (O(1) extra space)
    public static int removeDuplicates(int[] nums) {
        if (nums.length == 0) {
            return 0;
        }

        int i = 0;

        for (int j = 1; j < nums.length; j++) {
            if (nums[j] != nums[i]) {
                nums[i + 1] = nums[j];
                i++;
            }
        }

        return i + 1;
    }

    public static void main(String[] args) {
        int[] nums = {1, 1, 2, 2, 3, 3, 4};

        int k = removeDuplicates(nums);

        System.out.println("Unique elements: " + k);

        for (int i = 0; i < k; i++) {
            System.out.print(nums[i] + " ");
        }
    }
}