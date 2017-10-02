public class Solution {
    /*
     * @param : the given number
     * @return: whether whether there're two integers
     */
    public boolean checkSumOfSquareNumbers(int num) {
        // write your code here
        if (num < 0) {
            return false;
        } else {
            int max = (int)Math.sqrt(num / 2);
            for (int a = 0; a <= max; a++) {
                double b = Math.sqrt((num - a * a));
                if (b == (int) b) {
                    return true;
                }
            }
            return false;
        }
    }
};