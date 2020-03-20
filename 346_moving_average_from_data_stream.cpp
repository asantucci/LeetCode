/* Given a stream of integers and a window size, calculate 
   the moving average of all integers in the sliding window.
*/
class MovingAverage {
    vector<int> data;
    int size_;
public:
    /** Initialize your data structure here. */
    MovingAverage(int size) : size_(size) {
    }
    
    double next(int val) {
        // If we've reached our sliding window size, we need
        // to remove an element from our queue.
        if (data.size() >= size_) data.erase(data.begin(), data.begin() + 1);
        data.push_back(val);
        double avg {};
        for (const auto& v : data)
            avg += v;
        avg /= data.size();
        return avg;
    }
};

/**
 * Your MovingAverage object will be instantiated and called as such:
 * MovingAverage* obj = new MovingAverage(size);
 * double param_1 = obj->next(val);
 */
