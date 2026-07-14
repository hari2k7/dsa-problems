public class Solution {
    static int MaxConsecutiveOnes(int[] arr){
        int counter = 0;
        int max = 0;
        for(int i=0; i<arr.length; i++){
            if(arr[i]==1){
                counter++;
                if(max < counter){
                    max = counter;
                }
            }else{
                counter = 0;
            }
        }
        return max;
    }

    public static void main(String[] args){
        int[] arr = {1,1,0,1,1,1,0,1,1};
        System.out.println(MaxConsecutiveOnes(arr));
    }
}
