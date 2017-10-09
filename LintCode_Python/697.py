class Solution:
    """
    @param: : the given number
    @return: whether whether there're two integers
    """

    def checkSumOfSquareNumbers(self, num):
        # write your code here
        if num < 0:
            return False
        else:
            max = int(math.sqrt(num / 2))
            for a in range(0,max + 1):
                b = math.sqrt((num - a * a))
                if b == int(b):
                    return True
            return False