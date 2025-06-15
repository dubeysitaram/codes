// number at (r,c) is simple as ncr for 0 based indexing and n-1Cr-1 in case of
// here it is 1 based so we will,
// First, we will consider r-1 as n and c-1 as r.

// calculation of nCr
// nCr = (n*(n-1)*(n-2)*.....*(n-r+1)) / (r*(r-1)*(r-2)*....1) = (n / 1)*((n-1) / 2)*.....*((n-r+1) / r).




#include <bits/stdc++.h>
using namespace std;

int nCr(int n, int r) {
	long long res = 1;
	// calculating nCr:
	for (int i = 0; i < r; i++) {
		res = res * (n - i);
		res = res / (i + 1);
	}
	return res;
}

// variation 1
// given the row number r and the column number c,find out the element at position (r,c).
int pascalTriangle_element_at_r_c(int r, int c) {
	int element = nCr(r - 1, c - 1);
	return element;
}



// variation 2
// Given the row number n. Print the n-th row of Pascal’s triangle.

// simply call the nCr for every postion of that row
void pascalTriangle_print_entire_row(int n) {
	// printing the entire row n:
	for (int c = 1; c <= n; c++) {
		cout << nCr(n - 1, c - 1) << " ";
	}
	cout << "n";
}



// variation 3
// print entire tree of height n

vector<vector<int>> pascalTriangle(int n) {
	vector<vector<int>> ans;

	//store the entire pascal's triangle:
	for (int row = 1; row <= n; row++) {
		ans.push_back(pascalTriangle_print_entire_row(row));
	}
	return ans;
}

int main()
{
	int r = 5; // row number
	int c = 3; // col number
	int element = pascalTriangle(r, c);
	cout << "The element at position (r,c) is: "
	     << element << "n";
	return 0;
}


// now to find the
