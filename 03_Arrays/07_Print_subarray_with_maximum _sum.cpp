


// kadane mai breakcondition pe answer store karana hai vhi dekh le

vector<int> findSubarray(vector<int>& arr) {
	inyt n = arr.size();
	int temp = 0, currmax = INT_MIN;
	int lo = 0, flo = 0, fhi = 0;
	for (int i = 0; i < n; ++i) {
		temp += arr[i];
		if (temp > currmax) {
			currmax = temp;
			flo = lo;
			fhi = i + 1;
		}
		if (temp < 0) {
			temp = 0;
			lo = i + 1;
		}
	}
	return vector<int>(arr.begin() + flo, arr.begin() + fhi);
}





// if subarray should only have the positive element
// https://www.geeksforgeeks.org/problems/maximum-sub-array5443/1


vector<int> findSubarray(vector<int>& arr) {
	int n = arr.size();
	int temp = 0, currmax = 0;
	int lo = 0, flo = -1, fhi = -1;
	for (int i = 0; i < arr.size(); ++i) {

		if (arr[i] >= 0) {
			temp += arr[i];

			if (temp > currmax) {
				currmax = temp;
				while (i < n - 1 && arr[i + 1] == 0)i++; // so that the length of the array will be longest
				flo = lo;
				fhi = i + 1;
			}
		} else {
			temp = 0;
			lo = i + 1;
		}
	}
	if (flo == -1) return { -1};
	return vector<int>(arr.begin() + flo, arr.begin() + fhi);
}