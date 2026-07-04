
public class MergeSort {

    static void mergesort(int[] arr){
        int length = arr.length;

        while(length <= 1) return;

        int mid = length / 2;
        
        int[] leftarray = new int[mid];
        int[] rightarray = new int[length - mid];

        int i = 0; //left array
        int j = 0; //right array
        
        for(; i<length; i++){
            if(i<mid){
                leftarray[i] = arr[i];
            }else{
                rightarray[j] = arr[i];
                j++;
            }
        }

        mergesort(leftarray);
        mergesort(rightarray);
        merge(leftarray, rightarray, arr);

    }

    static void merge(int[] leftarray, int[] rightarray, int[] arr){
        int leftsize = leftarray.length;
        int rightsize = rightarray.length;

        int l =0, r=0, i=0;

        while(l<leftsize && r<rightsize ){
            if(leftarray[l] < rightarray[r]){
                arr[i] = leftarray[l];
                l++;
                i++;
            }else{
                arr[i] = rightarray[r];
                r++;
                i++;
            }
        }

        while(l<leftsize){
            arr[i] = leftarray[l];
            l++;
            i++;
        }
        while(r<rightsize){
            arr[i] = rightarray[r];
            r++;
            i++;
        }
    }

    public static void main(String[] args){
        int[] arr = {9,6,7,2,3,8};
        mergesort(arr);

        for(int i : arr){
            System.out.print(i + " ");
        }
    }
    
}
