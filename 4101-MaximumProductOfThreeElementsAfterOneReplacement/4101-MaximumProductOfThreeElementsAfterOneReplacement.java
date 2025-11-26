// Last updated: 26/11/2025, 22:29:17
class Solution {
    public long maxProduct(int[] nums) {
        int[] clone = nums.clone(); 
 
        Arrays.sort(clone);
        int n = clone.length;

        long smallest = clone[0];
        long secondSmallest = clone[1];
        
        long largest = clone[n - 1];
        long secondLargest = clone[n - 2];
        long thirdLargest = clone[n - 3];

        long POSITIVE_LIMIT = 100000;
        long NEGATIVE_LIMIT = -100000; 

        long maxProduct = Math.max(
            largest * secondLargest * thirdLargest,  
            smallest * secondSmallest * largest       
        );

        long productWithPositiveLimit = POSITIVE_LIMIT * Math.max(
            largest * secondLargest,    
            smallest * secondSmallest   
        );
        maxProduct = Math.max(maxProduct, productWithPositiveLimit);

        long productWithNegativeLimit = NEGATIVE_LIMIT * smallest * largest; 
        maxProduct = Math.max(maxProduct, productWithNegativeLimit);

        return maxProduct;
    }
}