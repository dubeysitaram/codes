#include<bits/stdc++.h>
using namespace std;
#define fastio() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define MOD 1000000007
typedef long long ll;
int ans = 0;
int countpairs(vector<pair<int, int>>& arrindex, int lo, int mid, int hi) {
	int i = lo; int j = mid + 1;
	while (i <= mid) {
		while (j <= hi && arrindex[i].first > 2 * arr[j].first) {
			j++;
		}
		ans += j - mid + 1;

	}
	return ans;
}


void merge(vector<pair<int, int>>& arrindex, int lo, int mid, int hi) {
	int n = hi - lo + 1;
	vector<pair<int, int>> sortedarray(n);
	int i = lo; // 0 se start nhi kr skte as on each level lo is not zero,
	int j = mid + 1;
	int k = 0;
	while (i <= mid && j <= hi) {
		if (arrindex[i].first <=arrindex[j].first) {
			sortedarray[k] = arrindex[i];
			i++;
			k++;
		} else {
			sortedarray[k] = arrindex[j];
			j++;
			k++;
		}
	}
	while (i <= mid) {
		sortedarray[k] = arrindex[i];
		i++;
		k++;
	}
	while (j <= hi) {
		sortedarray[k] = arrindex[j];
		j++;
		k++;
	}
	i = lo; // 0 se start nhi kr skte as on each level lo is not zero,
	k = 0;
	while (i <= hi) {
		arrindex[i] = sortedarray[k];
		i++;
		k++;
	}
}

void mergesort(vector<pair<int, int>>& arrindex, int lo, int hi) {
	if (lo >= hi)
		return;
	int mid = lo + (hi - lo) / 2;
	mergesort(arrindex, lo, mid);
	mergesort(arrindex, mid + 1, hi);
    countpairs(arrindex,lo,mid,hi);
	merge(arrindex, lo, mid, hi);
}

int reversePairs(vector<int>& nums) {
	int n = nums.size();
	vector<pair<int, int>> numindex(n);
	for (int i = 0; i < n; i++) {
		numindex[i] = {nums[i], i};
	}
	mergesort(numindex, 0, n - 1);
	return ans;
}

void solve() {


}


int main() {
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
#ifndef ONLINE_JUDGE
	freopen("Error.txt", "w", stderr);
#endif

	int t = 1;
	cin >> t;
	while (t--) {
		solve();
	}

}



#!/usr/bin/env bash

# ─── CONFIGURATION ─────────────────────────────────────────────────────────────
# List of IPs to monitor:
HOSTS=( "8.8.8.8" "1.1.1.1" "192.168.1.1" "10.0.0.1" "172.16.0.1" "203.0.113.5" )

# Threshold in milliseconds:
THRESHOLD_MS=100

# Ping count per sample:
COUNT=4

# Pause between full cycles (in seconds):
SLEEP_INTERVAL=60

# Twilio SMS settings – you must export these in your environment:
#   export TWILIO_ACCOUNT_SID="ACXXXX..."
#   export TWILIO_AUTH_TOKEN="your_auth_token"
#   export TWILIO_FROM="+15551234567"
#   export ALERT_TO="+919876543210"
TWILIO_API="https://api.twilio.com/2010-04-01/Accounts/${TWILIO_ACCOUNT_SID}/Messages.json"

# ─── FUNCTION TO SEND SMS ALERT ────────────────────────────────────────────────
send_alert() {
  local host=$1
  local avg_ms=$2
  local body="ALERT: ${host} avg ping = ${avg_ms} ms exceeds threshold of ${THRESHOLD_MS} ms"
  curl -s -X POST "${TWILIO_API}" \
    --data-urlencode "From=${TWILIO_FROM}" \
    --data-urlencode "To=${ALERT_TO}" \
    --data-urlencode "Body=${body}" \
    -u "${TWILIO_ACCOUNT_SID}:${TWILIO_AUTH_TOKEN}" \
    >/dev/null
}

# ─── MAIN LOOP ────────────────────────────────────────────────────────────────
while true; do
  for host in "${HOSTS[@]}"; do
    # Ping and grab the 'avg' field from the rtt line
    # Format: rtt min/avg/max/mdev = 10.123/20.456/30.789/1.234 ms
    avg_ms=$(ping -c "$COUNT" -q "$host" 2>/dev/null \
      | awk -F'/' '/rtt/ { print $5 }')

    # If we got a numeric value back…
    if [[ $avg_ms =~ ^[0-9]+(\.[0-9]+)?$ ]]; then
      # Compare as integers (round up)
      avg_int=${avg_ms%.*}
      (( avg_int < 0 )) && avg_int=0

      if (( avg_int > THRESHOLD_MS )); then
        echo "$(date '+%F %T')  [WARNING] $host avg=${avg_ms}ms" 
        send_alert "$host" "$avg_ms"
      else
        echo "$(date '+%F %T')  [OK]      $host avg=${avg_ms}ms"
      fi
    else
      # No response at all? Treat it as down.
      echo "$(date '+%F %T')  [DOWN]    $host no response"
      send_alert "$host" "no response"
    fi
  done

  sleep "$SLEEP_INTERVAL"
done
