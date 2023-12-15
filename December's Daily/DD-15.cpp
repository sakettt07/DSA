#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

string destCity(vector<vector<string>>& paths) {
    int n = paths.size();
    unordered_map<string, vector<string>> indegree;

    // Populate the indegree map with incoming cities
    for (auto ele : paths) {
        indegree[ele[0]].push_back(ele[1]);
    }

    // Display the contents of the indegree map
    cout << "Contents of the indegree map:\n";
    for (const auto& entry : indegree) {
        cout << entry.first << ": ";
        for (const auto& city : entry.second) {
            cout << city << " ";
        }
        cout << endl;
    }

    // Iterate through the paths to find the destination city
    for (auto ele : paths) {
        // Print the current iteration
        cout << "Checking path: [" << ele[0] << ", " << ele[1] << "]\n";

        // Check if the current outgoing city has no incoming cities
        if (indegree[ele[0]].size() == 0) {
            cout << ele[0] << " has no incoming cities, so it is the destination city.\n";
            return ele[0];
            
        }

        // Check if the current incoming city has no outgoing cities
        if (indegree[ele[1]].size() == 0) {
            cout << ele[1] << " has no outgoing cities, so it is the destination city.\n";
            return ele[1];
            cout << "Size of indegree[" << ele[1] << "]: " << indegree[ele[1]].size() << endl;
        }
    }

    // If no destination city is found, return "null"
    return "null";
}

int main() {
    vector<vector<string>> paths = {{"L", "NY"}, {"NY", "Li"}, {"Li", "SP"}};
    string result = destCity(paths);
    cout << "Destination city: " << result << endl;

    return 0;
}

