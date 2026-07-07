public class LargestNum {
    static int largestN(int[] arr){
        int largest = arr[0];
        for(int i=1; i<arr.length; i++){
            if(arr[i]>largest){
                largest = arr[i];
            }
        }
        return largest;
    }    

    public static void main(String[] args){
        int[] arr = {9,3,8,6,8,6,5};
        System.out.println(largestN(arr));
    }
}
