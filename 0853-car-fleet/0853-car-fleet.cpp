class Solution {
public:
    int carFleet(int target, vector<int>& position,
                 vector<int>& speed) {

        vector<pair<int, double>> cars;

        // Store position and time
        for (int i = 0; i < position.size(); i++) {
            double time = (double)(target - position[i]) / speed[i];

            cars.push_back({position[i], time});
        }

        // Sort by position: closest to target first
        sort(cars.rbegin(), cars.rend());

        stack<double> st;

        for (auto car : cars) {

            double time = car.second;

            // If this car takes longer,
            // it forms a new fleet.
            if (st.empty() || time > st.top()) {
                st.push(time);
            }

            // Otherwise it catches the fleet ahead,
            // so no new fleet is created.
        }

        return st.size();
    }
};