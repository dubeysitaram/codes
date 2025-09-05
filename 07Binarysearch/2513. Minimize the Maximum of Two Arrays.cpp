/*2513. Minimize the Maximum of Two Arrays.cpp

We have two arrays arr1 and arr2 which are initially empty.
You need to add positive integers to them such that they satisfy all the following conditions:
arr1 contains uniqueCnt1 distinct positive integers, each of which is not divisible by divisor1.
arr2 contains uniqueCnt2 distinct positive integers, each of which is not divisible by divisor2.
No integer is present in both arr1 and arr2.
Given divisor1, divisor2, uniqueCnt1, and uniqueCnt2,
return the minimum possible maximum integer that can be present in either array.
*/


class Solution {
public:
	long long lcm(long long a, long long b) {
		return (a / __gcd(a, b)) * b;
	}

	bool ispossible(long long mid, long long uniqueCnt1, long long uniqueCnt2, long long divisor1, long long divisor2) {
		long long cnt1 = mid - (mid / divisor1); // not divisible by divisor1
		long long cnt2 = mid - (mid / divisor2); // not divisible by divisor2
		long long common = mid - (mid / lcm(divisor1, divisor2)); // not divisible by both divisor1 && divisor2
		// here the we cannot apply single condition (common >= (uniqueCnt1 + uniqueCnt2)) and return true
		// check example 2 and 4 because if we take number not divisible by 4
		//  it also include the number divisible by 2 but we want not divisble by 2
		return (cnt1 >= uniqueCnt1) && (cnt2 >= uniqueCnt2) && (common >= (uniqueCnt1 + uniqueCnt2));
	}

	long long minimizeSet(long long divisor1, long long divisor2, long long uniqueCnt1, long long uniqueCnt2) {
		long long lo = 0, hi = 1e15;
		while (hi - lo > 1) {
			long long mid = (hi + lo) / 2;
			if (ispossible(mid, uniqueCnt1, uniqueCnt2, divisor1, divisor2)) {
				hi = mid;
			} else {
				lo = mid;
			}
		}
		return hi;
	}
};