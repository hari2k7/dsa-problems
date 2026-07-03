import java.util.Arrays;

public class SelectionSort {
    static int[] ss(int[] arr){
        for(int i=0; i<arr.length -1; i++){
            int min = i;
            for(int j=i+1; j<arr.length; j++){
                if(arr[j]<arr[min]){
                    min = j;
                }
            }
            int temp = arr[min];
            arr[min] = arr[i];
            arr[i] = temp;
        }
        return arr;
    }

    public static void main(String[] args){
        int[] arr = {4,9,1,8,3,6};
        System.out.println(Arrays.toString(ss(arr)));
    }
}

