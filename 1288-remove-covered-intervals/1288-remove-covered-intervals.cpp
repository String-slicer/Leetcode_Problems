class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {

        // Step 1: Sort the intervals.
        //
        // Primary sorting:
        // - Sort by starting point in ascending order.
        //
        // Secondary sorting (important):
        // - If two intervals have the same start,
        //   place the interval with the larger ending point first.
        //
        // Why?
        // Example:
        // [1,4] and [1,5]
        //
        // If we sort by end ascending:
        // [1,4], [1,5]
        // The smaller interval comes first, so we cannot detect
        // that it is covered by [1,5].
        //
        // By sorting end in descending order:
        // [1,5], [1,4]
        // the larger interval always appears first, making it
        // possible to detect covered intervals in a single pass.
        sort(intervals.begin(), intervals.end(),
        [](vector<int>& a, vector<int>& b){
            if(a[0] == b[0])
                return a[1] > b[1];
            return a[0] < b[0];
        });

        // ans stores the number of intervals that are NOT covered.
        int ans = 0;

        // maxEnd keeps track of the farthest ending point
        // among all previously processed intervals.
        //
        // Initially no interval has been processed.
        int maxEnd = 0;

        // Traverse all intervals in sorted order.
        for(auto &it : intervals){

            // If the current interval ends after maxEnd,
            // it cannot be covered by any previous interval.
            //
            // Why?
            // Since starts are already sorted,
            // every previous interval starts before or at
            // the current interval.
            //
            // If its end is also >= current end,
            // then the current interval is covered.
            //
            // Therefore, only intervals with a larger end
            // than maxEnd are unique (not covered).
            if(it[1] > maxEnd){

                // Count this interval.
                ans++;

                // Update the farthest ending point seen so far.
                maxEnd = it[1];
            }

            // Else:
            // current end <= maxEnd
            //
            // Some previous interval started earlier (or same)
            // and ends later (or same),
            // therefore this interval is completely covered.
            // Ignore it.
        }

        return ans;
    }
};