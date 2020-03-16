/* Write a class RecentCounter to count recent requests.

   It has only one method: ping(int t), where t represents some 
   time in milliseconds.

   Return the number of pings that have been made from 
   3000 milliseconds ago until now.

   Any ping with time in [t - 3000, t] will count, including 
   the current ping.

   It is guaranteed that every call to ping uses a strictly 
   larger value of t than before.
*/
class RecentCounter {
public:
    // Our sole member attribute will keep track of all pings received "to-date".
    vector<int> pings;
    RecentCounter() {}
    
    int ping(int t) {
        // Our ping method will return the number of pings within the last 3,000 seconds.
        pings.push_back(t);
        // To accomplish this, we just check how many pings are in range.
        int ttl {};
        for (const auto& val : pings)
            if (t - val <= 3000) ttl++;
        return ttl;
    }
};
/**
 * Your RecentCounter object will be instantiated and called 
 * as such:
 * RecentCounter* obj = new RecentCounter();
 * int param_1 = obj->ping(t);
 */
