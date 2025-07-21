/*
850. Rectangle Area II

You are given a 2D array of axis-aligned rectangles. Each rectangle[i] = [xi1, yi1, xi2, yi2]
denotes the ith rectangle where (xi1, yi1) are the coordinates of the bottom-left corner,
and (xi2, yi2) are the coordinates of the top-right corner.

Calculate the total area covered by all rectangles in the plane.
Any area covered by two or more rectangles should only be counted once.

Return the total area. Since the answer may be too large, return it modulo 109 + 7.
*/

class Solution {
public:
	const int MOD = 1e9 + 7;

	int rectangleArea(vector<vector<int>>& rectangles) {
		vector<vector<int>> events;

		// Step 1: Convert each rectangle into two events: opening and closing
		for (int i = 0; i < rectangles.size(); i++) {
			// Event format: {x-coordinate, type(1 for open, -1 for close), y1, y2}
			events.push_back({rectangles[i][0], 1, rectangles[i][1], rectangles[i][3]});  // left edge
			events.push_back({rectangles[i][2], -1, rectangles[i][1], rectangles[i][3]}); // right edge
		}

		// Step 2: Sort events by x-coordinate
		sort(events.begin(), events.end());

		multiset<pair<int, int>> active; // Tracks currently open vertical segments (y-intervals)
		long ans = 0;
		int prevX = events[0][0]; // Previous x-position to compute width

		// Step 3: Sweep through all x-events
		for (int i = 0; i < events.size(); i++) {
			int x = events[i][0];
			int type = events[i][1];
			int y1 = events[i][2];
			int y2 = events[i][3];

			// Step 4: Calculate total vertical coverage from active intervals
			long y_covered = 0;
			int curr_start = -1, curr_end = -1;

			for (auto& [a, b] : active) {
				if (a > curr_end) {
					// No overlap, add previous segment length
					y_covered += curr_end - curr_start;
					curr_start = a;
					curr_end = b;
				} else {
					// Overlap exists, extend the end
					curr_end = max(curr_end, b);
				}
			}
			y_covered += curr_end - curr_start; // Add last segment

			// Step 5: Add area = width * height
			ans = (ans + (y_covered * (x - prevX)) % MOD) % MOD;

			// Step 6: Update active set with current event
			if (type == 1)
				active.insert({y1, y2});       // Add interval
			else
				active.erase(active.find({y1, y2})); // Remove interval

			prevX = x; // Move to next x
		}

		return ans % MOD;
	}
};



class Solution {
public:
	static const int MOD = 1e9 + 7;

	// Given a multiset of (y, delta) pairs where delta=+1 for entry, -1 for exit,
	// compute the total union-length over y.
	int getYUnionLength(const multiset<pair<int, int>>& yline) {
		// Build a small vector of events: (y, type), where
		// type = -1 for start, +1 for end.
		vector<pair<int, int>> ev;
		ev.reserve(yline.size());
		for (auto &p : yline) {
			// we stored +1 on entry, -1 on exit, so flip sign
			ev.emplace_back(p.first, -p.second);
		}
		sort(ev.begin(), ev.end());

		int covered = 0;
		int active = 0;
		int prevY = 0;
		bool havePrev = false;

		for (auto &e : ev) {
			int y = e.first;
			int type = e.second;
			if (active > 0 && havePrev) {
				covered += y - prevY;
			}
			active -= type;   // start: type=-1 → active++, end: type=+1 → active--
			prevY = y;
			havePrev = true;
		}
		return covered;
	}

	int rectangleArea(vector<vector<int>>& rectangles) {
		// 1) build x‑events: {x, open/close, y1, y2}
		//    open = 0, close = 1
		vector<array<int, 4>> events;
		events.reserve(rectangles.size() * 2);
		for (auto &r : rectangles) {
			events.push_back({r[0], 0, r[1], r[3]});
			events.push_back({r[2], 1, r[1], r[3]});
		}
		sort(events.begin(), events.end(),
		[&](auto & a, auto & b) {
			if (a[0] != b[0]) return a[0] < b[0];
			return a[1] < b[1];
		});

		// 2) sweep over x
		long long area = 0;
		int prevX = events[0][0];
		multiset<pair<int, int>> yline; // (y, +1 entry or -1 exit)

		for (auto &e : events) {
			int x = e[0];
			int type = e[1];
			int y1 = e[2];
			int y2 = e[3];

			// accumulate area for [prevX, x)
			if (x > prevX) {
				int ycov = getYUnionLength(yline);
				long long width = (long long)(x - prevX);
				area = (area + ycov * width % MOD) % MOD;
			}

			// add or remove this rectangle’s y‑interval
			if (type == 0) {
				yline.emplace(y1, +1);
				yline.emplace(y2, -1);
			} else {
				// safely erase exactly one (y1,+1) and one (y2,-1)
				auto it1 = yline.find(make_pair(y1, +1));
				if (it1 != yline.end()) yline.erase(it1);
				auto it2 = yline.find(make_pair(y2, -1));
				if (it2 != yline.end()) yline.erase(it2);
			}

			prevX = x;
		}

		return (int)area;
	}
};
