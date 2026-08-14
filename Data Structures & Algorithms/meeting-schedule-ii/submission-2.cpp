/**
 * Definition of Interval:
 * class Interval {
 * public:
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */

class Solution {
public:
    int minMeetingRooms(vector<Interval>& intervals) {
        if(intervals.size() == 0) return 0;
        sort(intervals.begin(), intervals.end(), [](Interval a, Interval b){
           return a.start < b.start;
        });

        priority_queue<int, vector<int>, greater<int>> pq;
        pq.push(intervals[0].end);
        int cnt = 1;
        int ans = 1;
        for(int i = 1; i < intervals.size(); i++){
            if(pq.top() > intervals[i].start){
                cnt++;
            }
            else{
                while(!pq.empty() && pq.top() <= intervals[i].start){
                    pq.pop();
                    // cnt--;
                }
            }
            pq.push(intervals[i].end);
            cnt = pq.size();
            ans = max(ans, cnt);
            // cnt++;
        }
        return ans;
    }
};
