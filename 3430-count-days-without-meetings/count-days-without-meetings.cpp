class Solution {
public:
   int countDays(int days, vector<vector<int>>& meetings) {
    if (meetings.empty()) return days;  // If no meetings, all days are free
    
    sort(meetings.begin(), meetings.end()); // Sort by start date
    
    int count = 0;
    int lastEnd = 0; // Track the last meeting's end date
    
    for (const auto& m : meetings) {
        if (m[0] > lastEnd + 1) {
            count += (m[0] - lastEnd - 1); // Count free days before this meeting
        }
        lastEnd = max(lastEnd, m[1]); // Update last occupied day
    }
    
    // Count free days after the last meeting
    if (lastEnd < days) {
        count += (days - lastEnd);
    }

    return count;
}

};