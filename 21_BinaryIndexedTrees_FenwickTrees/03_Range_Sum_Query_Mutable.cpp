// 307. Range Sum Query - Mutable

/*

Given an integer array nums, handle multiple queries of the following types:

Update the value of an element in nums.
Calculate the sum of the elements of nums between indices left and right inclusive where left <= right.
Implement the NumArray class:

NumArray(int[] nums) Initializes the object with the integer array nums.
void update(int index, int val) Updates the value of nums[index] to be val.
int sumRange(int left, int right) Returns the sum of the elements of nums between
indices left and right inclusive (i.e. nums[left] + nums[left + 1] + ... + nums[right]).



*/

class NumArray {
public:
	int n;
	vector<int> bit;
	vector<int>a;
	void fn1_update(int i, int x) {
		for (; i <= n; i += (i & -i)) {
			bit[i] += x;
		}
	}
	int fn2_sum(int i) {
		int ans = 0;
		for (; i > 0; i -= (i & -i)) {
			ans += bit[i];
		}
		return ans;
	}
	NumArray(vector<int>& nums) {
		n = nums.size();
		bit.resize(n + 1, 0);
		a.resize(n + 1);
		for (int i = 0; i < n; i++) {
			a[i + 1] = nums[i];
			fn1_update(i + 1, nums[i]);
		}
	}

	void update(int i, int x) {
		fn1_update(i + 1, -a[i + 1]);
		fn1_update(i + 1, x);
		a[i + 1] = x;
	}

	int sumRange(int left, int right) {
		return fn2_sum(right + 1) - fn2_sum(left); // 1-based indexing
	}
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */