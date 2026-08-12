
public class Solution {
    static int KSmallElement(int[] arr, int k){
        for(int i=1; i<=k; i++){
            int mini = 0;
            
            for(int j=0; j<arr.length; j++){
                if(arr[j]<arr[mini]){
                    mini = j;
                }
            }

            if(i==k) return arr[mini];

            arr[mini] = Integer.MAX_VALUE;

        }

        return -1;
    }    

     public static void main(String[] args) {

        int[] arr = {2, 0, 1, 3, 5};
        int k = 2;

        System.out.println("Kth smallest element: " + KSmallElement(arr, k));
    }
}
