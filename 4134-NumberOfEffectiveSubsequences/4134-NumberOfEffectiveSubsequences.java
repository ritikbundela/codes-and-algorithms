// Last updated: 26/11/2025, 22:29:07
class Solution {
    private static final int MOD = 1000000007;

    public int countEffective(int[] nums) {
        int total = 0;
        for (int num : nums) {
            total |= num;
        }
        if (total == 0) {
            return 0;
        }
        List<Integer> bits = new ArrayList<>();
        for (int i = 0; i < 31; i++) {
            if (((total >> i) & 1) == 1) {
                bits.add(i);
            }
        }

        int m = bits.size();
        int range = 1 << m;

        int[] freq = new int[range];

        for (int num : nums) {
            int mask = 0;
            for (int i = 0; i < m; i++) {
                if (((num >> bits.get(i)) & 1) == 1) {
                    mask |= (1 << i);
                }
            }
            freq[mask]++;
        }

        for (int i = 0; i < m; i++) {
            for (int mask = 0; mask < range; mask++) {
                if ((mask & (1 << i)) != 0) {
                    freq[mask] += freq[mask ^ (1 << i)];
                }
            }
        }
        long K = 0;

        for (int mask = 0; mask < range; mask++) {
            int count = freq[mask];
            long ways = power(2, count);
            if ((m - Integer.bitCount(mask)) % 2 == 1) {
                K = (K - ways + MOD) % MOD;
            } else {
                K = (K + ways) % MOD;
            }
        }
        long totalSubsequences = power(2, nums.length);

        return (int) ((totalSubsequences - K + MOD) % MOD);
    }

    private long power(long base, long exp) {
        long res = 1;
        base %= MOD;
        while (exp > 0) {
            if ((exp & 1) == 1)
                res = (res * base) % MOD;
            base = (base * base) % MOD;
            exp >>= 1;
        }
        return res;
    }
}