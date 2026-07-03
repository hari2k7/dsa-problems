import java.util.Arrays;

public class InsertionSort {
    static int[] ins(int[] arr){
        for(int i=1; i<arr.length; i++){
            int temp = arr[i];
            int j = i-1;
            while(j >= 0 && arr[j] > temp){
                arr[j+1] = arr[j];
                j--;
            }
            arr[j+1] = temp;
        }
        return arr;
    }

    public static void main(String[] args){
        int[] arr = {8,6,4,7,5,1,3};
        System.out.println(Arrays.toString(ins(arr)));
    }
}
