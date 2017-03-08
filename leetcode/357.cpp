class Solution {
    public:
    int count[11] = {1, 10, 91, 739, 5275, 32491, 168571, 712891, 2345851, 5611771, 8877691};
    int countNumbersWithUniqueDigits(int n) {
            if(n > 10) return count[10];
            else return count[n];
        }
};
