
public class Solution {
    static int SmallestMissingPositiveNum(int[] arr){
        int r = 1;
        for(int i=0; i<arr.length-1; i++){
            if(arr[i]==r) r++;
        }
        return r;
    }

    public static void main(String[] args) {
        int[] arr = {-1, 1, 3, 4};
        System.out.println(SmallestMissingPositiveNum(arr));
    }
}
