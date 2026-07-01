public class BinarySearch {
    static int bs(int[] arr, int key){
        int low = 0;
        int high = arr.length - 1;
        while(low <= high){
            int mid = (low + high)/2;
            if(key == arr[mid]){
                return mid;
            }else if(key < arr[mid]){
                high = mid - 1;
            }else{
                low = mid + 1;
            }
        }
        return -1;
    }

    public static void main(String[] args){
        int[] arr = {2,4,6,8,9};
        System.out.println(bs(arr,9));
    }
}
