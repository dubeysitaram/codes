/*The frequency of an element is the number of times it occurs in an array.

You are given an integer array nums and an integer k.
In one operation, you can choose an index of nums and increment the element at that index by 1.

Return the maximum possible frequency of an element after performing at most k operations.

Constraints:

1 <= nums.length <= 105
1 <= nums[i] <= 105
1 <= k <= 105
*/



/*
sol.)
Here our key idea is we will sort the array
now at each index we will calculate required diffrence to be filled
like for ex 1 1 2 6 7
at position 4 there is 6, to make the all the element before the 6 equal to 6

req value of k = (6+6+6+6) - (1+1+2+6) = 24 - 10 = 14
if this req value of the k is greater than the given value of the k then move the j pointer ahead else
move the i pointer ahead modifying the currsum value and length

*/




int maxFrequency(vector<int>& nums, int k) {
	long long n = nums.size();
	sort(nums.begin(), nums.end());
	long long i = 0;
	long long j = 0;
	long long sumpres = 0;
	long long reqsum = 0;
	long long ans = 1;
	while (j < n) {
		long long len = j - i + 1;
		reqsum = len * nums[j];
		sumpres += nums[j];
		long long diff = reqsum - sumpres;
		if (diff <= k) {
			ans = max(ans, j - i + 1);
		} else {
			while ((j - i + 1) * nums[j] - sumpres > k) {
				sumpres = sumpres - nums[i];
				i++;
			}
		}
		j++;
	}
	return (int)ans;
}

