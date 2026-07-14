public class RotateByK {
    static void Rotate(int[] arr, int k){
        int[] temp = new int[k+1];
        for(int i=0; i<k+1; i++){
            temp[i] = arr[i];
        }
        int j=0;
        for(int i=k+1; i<arr.length; i++){
            arr[j] = arr[i];
            j++;
        }
        int x=0;
        for(int i=(arr.length - (k+1)); i<arr.length; i++){
            arr[i] = temp[x];
            x++;
        }
        
    }

    public static void main(String[] args){
        int[] arr = {1,2,3,4,5,6,7};
        Rotate(arr,3);
        for(int x : arr){
            System.out.print(x);
            System.out.print(" ");
        }
    }
}
