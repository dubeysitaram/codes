/*
leetcode  1201. Ugly Number III

An ugly number is a positive integer that is divisible by a, b, or c.

Given four integers n, a, b, and c, return the nth ugly number.

*/
class Solution {
public:
long long lcm(long long a, long long b) {
    return (a / __gcd(a, b)) * b;
}

bool is_possible(long long mid, long long n, long long a, long long b, long long c) {
    long long x = mid / a;
    long long y = mid / b;
    long long z = mid / c;
    long long ab = mid / lcm(a, b);
    long long ac = mid / lcm(a, c);
    long long bc = mid / lcm(b, c);
    long long abc = mid / lcm(lcm(a, b), c);
    long long tot = x + y + z - ab - ac - bc + abc;
    return tot >= n;
}

long long nthUglyNumber(long long n, long long a, long long b, long long c) {
    long long hi = 1e18, lo = 0;
    while (hi - lo > 1) {
        long long mid = (hi + lo) / 2;
        if (is_possible(mid, n, a, b, c)) {
            hi = mid;
        } else {
            lo = mid;
        }
    }
    return hi;
}

};
/*
264. Ugly Number II

An ugly number is a positive integer whose prime factors are limited to 2, 3, and 5.
Given an integer n, return the nth ugly number.

*/
class Solution {
public:
    int solve(int n) {
        
        long long a=0;
        set<long long> s2;
        s2.insert(1);
        for (long long i = 2; i <= n; i++) {
             long long a  =*s2.begin();
             s2.erase(s2.begin());
            long long x1 = 2 * a;
            long long x2 = 3 * a;
            long long x3 = 5 * a;
            s2.insert(x1);s2.insert(x2);s2.insert(x3);
            
        }
        

        return (int)*s2.begin();
    }

    int nthUglyNumber(int n) { return solve(n); }
};