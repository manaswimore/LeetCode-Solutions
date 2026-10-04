class Solution {
public:
    vector<int> minInterval(vector<vector<int>>& intervals,
                         vector<int>& queries) {

    sort(intervals.begin(), intervals.end());

    vector<pair<int, int>> qs;

    for (int i = 0; i < queries.size(); i++) {
        qs.push_back({queries[i], i});
    }

    sort(qs.begin(), qs.end());

    priority_queue<
        pair<int, int>,
        vector<pair<int, int>>,
        greater<pair<int, int>>
    > pq;

    vector<int> ans(queries.size(), -1);

    int i = 0;

    for (auto [query, index] : qs) {

        // Add all intervals that start before or at query
        while (i < intervals.size() &&
               intervals[i][0] <= query) {

            int start = intervals[i][0];
            int end = intervals[i][1];

            int size = end - start + 1;

            pq.push({size, end});

            i++;
        }

        // Remove intervals that ended before query
        while (!pq.empty() && pq.top().second < query) {
            pq.pop();
        }

        // Smallest valid interval
        if (!pq.empty()) {
            ans[index] = pq.top().first;
        }
    }

    return ans;
}
};