class Solution {
public:
    int minPenalty(int period, vector<int>& lights, vector<int>& arrivalTime) {
        int g = ranges::max(lights);
        return ranges::fold_left(
            arrivalTime | views::transform([&](int t) { 
                int r = t % period; return r >= g ? period - r : 0; 
            }),
            0, 
            ranges::max
        );
    }
};