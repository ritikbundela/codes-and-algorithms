// Last updated: 26/11/2025, 22:33:08
class Solution {
    public String fractionToDecimal(int numerator, int denominator) {
        if (numerator == 0) return "0";

        StringBuilder sb = new StringBuilder();

    
        boolean negative = (numerator < 0) ^ (denominator < 0);
        if (negative) sb.append('-');

        long lnum = Math.abs((long) numerator);
        long lden = Math.abs((long) denominator);

        long integerPart = lnum / lden;
        sb.append(integerPart);

        long rem = lnum % lden;
        if (rem == 0) {
            return sb.toString(); 
        }

        sb.append('.');

        Map<Long, Integer> remIndexMap = new HashMap<>();

        while (rem != 0) {
            if (remIndexMap.containsKey(rem)) {
                int insertPos = remIndexMap.get(rem);
                sb.insert(insertPos, '(');
                sb.append(')');
                break;
            }

            remIndexMap.put(rem, sb.length());

            rem *= 10;
            long digit = rem / lden;
            sb.append(digit);
            rem = rem % lden;
        }

        return sb.toString();
    }
}