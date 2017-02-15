class Solution {
public:
    int poorPigs(int buckets, int minutesToDie, int minutesToTest) {
        int pigs = 0;
        int tests = minutesToTest / minutesToDie;
        for(int i = 1; i < buckets; i *= (tests + 1)) {
            pigs ++;
        }
        return pigs;
    }
};