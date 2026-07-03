import java.util.Arrays;

public class BubbleSort {
    static int[] bs(int[] arr){
        for(int i=arr.length; i>0; i--){
            for(int j=0; j<i-1; j++){
                if(arr[j]>arr[j+1]){
                    int temp = arr[j];
                    arr[j] = arr[j+1];
                    arr[j+1] = temp;
                }
            }
        }
        return arr;
    }

    public static void main(String[] args){
        int[] arr = {6,8,1,3,5};
        System.out.println(Arrays.toString(bs(arr)));
    }
}
