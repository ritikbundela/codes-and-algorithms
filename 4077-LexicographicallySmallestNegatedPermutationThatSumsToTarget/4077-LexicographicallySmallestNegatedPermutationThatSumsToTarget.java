// Last updated: 26/11/2025, 22:29:21
class Solution {
    public int[] lexSmallestNegatedPerm(int n, long target) {
        long total = (long) n * (n + 1) / 2;
        if (target < -total || target > total || 
            (total - target) % 2 != 0) {
            return new int[0];
        }

        long k = (total - target) / 2;

        boolean[] isNeg = new boolean[n + 1];
        for (int i = n; i >= 1; i--) {
            if (k >= i) {
                isNeg[i] = true;
                k -= i;
            }
        }

        int[] result = new int[n];
        int idx = 0;

        for (int i = n; i >= 1; i--) {
            if (isNeg[i]) {
                result[idx++] = -i;
            }
        }

        for (int i = 1; i <= n; i++) {
            if (!isNeg[i]) {
                result[idx++] = i;
            }
        }

        return result;
    }
}