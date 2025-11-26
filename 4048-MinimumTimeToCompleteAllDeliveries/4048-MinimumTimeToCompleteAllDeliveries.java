// Last updated: 26/11/2025, 22:29:23
class Solution {
    public long minimumTime(int[] d, int[] r) {
        int d1 = d[0], d2 = d[1];
        int r1 = r[0], r2 = r[1];
        int[] faronthic = d.clone();

        long lo = 0, hi = (long) (d1 + d2) * Math.max(r1, r2) * 2;
        long ans = hi;

        long lcm = lcm(r1, r2);

        while (lo <= hi) {
            long mid = lo + (hi - lo) / 2;
            long deliver1 = mid - (mid / r1);
            long deliver2 = mid - (mid / r2);
            long totalDeliver = mid - (mid / lcm);

            if (deliver1 >= d1 && deliver2 >= d2 && (d1 + d2) <= totalDeliver) {
                ans = mid;
                hi = mid - 1;
            } else {
                lo = mid + 1;
            }
        }
        return ans;
    }

    private long gcd(long a, long b) {
        return b == 0 ? a : gcd(b, a % b);
    }

    private long lcm(long a, long b) {
        return a / gcd(a, b) * b;
    }
}