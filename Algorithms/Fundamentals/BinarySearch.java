import java.util.Arrays;

public class BinarySearch {
    public static int rank(int key, int [] a) {
        int lo = 0;
        int hi = a.length - 1;
        //lo represent low, hi represent high
        while (lo <= hi) {
            int mid = lo + (hi - lo) / 2;
            //use this form instead of (hi + lo)/2 because it can prevent overflow
            if(key < a[mid]) hi = mid - 1;
            else if(key > a[mid]) lo = mid + 1;
            else return mid;
        }
        return -1;
    }

    public static void main(String[] args) {
        int [] whitelist = In.readInts(args[0]);
        Arrays.sort(whitelist);
        while(!StdIn.isEmpty()) {
            int key = StdIn.readInt();
            //think why returning -1 instead of returning 1 or something else
            if(rank(key,whitelist) < 0)
                StdOut.println(key);
        }
    }
}

