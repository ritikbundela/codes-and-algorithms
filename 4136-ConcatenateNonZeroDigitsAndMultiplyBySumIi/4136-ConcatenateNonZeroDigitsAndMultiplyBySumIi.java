// Last updated: 26/11/2025, 22:29:10
class Solution {
    public int[] sumAndMultiply(String s, int[][] queries) {
    int mod = 1000_000007;
    int n = s.length();
    int q = queries.length;

    int[] res = new int[q];

    long[] prefNum = new long[n];
    long[] pow10 = new long[n + 1];
    int[] prefCnt = new int[n];
    long[] prefSum = new long[n];
    pow10[0] = 1;

    int cnt = 0;
    long num = 0;
    long sum = 0;

    for (int i = 0; i < n; i++) {
        char c = s.charAt(i);

        if (c != '0') {
            cnt++;
            num = (num * 10 + (c - '0')) % mod;
            sum += (c - '0');

            pow10[cnt] = (pow10[cnt - 1] * 10) % mod;
        }

        prefNum[i] = num;
        prefCnt[i] = cnt;
        prefSum[i] = sum;
    }

    for (int k = 0; k < q; k++) {
        int l = queries[k][0];
        int r = queries[k][1];

        int cntR = prefCnt[r];
        int cntL = l == 0 ? 0 : prefCnt[l - 1];
        int digits = cntR - cntL;

        long digitSum = prefSum[r] - (l == 0 ? 0 : prefSum[l - 1]);

        long x;
        if (l == 0) {
            x = prefNum[r];
        } else {
            long left = prefNum[l - 1];
            long shift = (left * pow10[digits]) % mod;
            x = (prefNum[r] - shift + mod) % mod;
        }

        res[k] = (int) ((x * digitSum) % mod);
    }

    return res;
}

}