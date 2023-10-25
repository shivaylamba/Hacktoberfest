public class SlidingWindow {
    public static void main(String[] args) {
     int[] a={ 2,9,31,-4,21,7};
     int k=3;
        System.out.println(maxSubArray(a,k));
    }
    static int maxSubArray(int[] a, int k){
      int wSum=0;
      int mSum=Integer.MIN_VALUE;

        for (int i = 0; i < k; i++) {
            wSum+=a[i];
        }
        for (int i = k; i <a.length ; i++) {
            wSum=wSum-a[i-k]+a[i];
            mSum=Math.max(wSum,mSum);

        }
        return mSum;
    }

}
