public class LinearSearch {

    static int ls(int[] arr, int key){
        for(int i=0; i<arr.length; i++){
            if(arr[i]==key){
                return i;
            }
        }
        return -1;
    }

    public static void main(String[] args){
        int[] arr = {1,6,8,4,3,5};
        System.out.println(ls(arr,5));
    }
}
