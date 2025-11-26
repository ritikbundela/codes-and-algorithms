// Last updated: 26/11/2025, 22:33:37
class Solution {
    public int minimumTotal(List<List<Integer>> triangle) {
        int size = triangle.size();
        if (size == 1) 
            return triangle.get(0).get(0);

        for (int i = size - 2; i >= 0; i--) {
            for (int j = 0; j < triangle.get(i).size(); j++) {
                int updatedValue = triangle.get(i).get(j) +
                Math.min(triangle.get(i+1).get(j), triangle.get(i+1).get(j+1));
                triangle.get(i).set(j, updatedValue);
            }
        }

        return triangle.get(0).get(0);
    }
}