class Solution {
public:
    string frequencySort(string s) {
        // Step 1: Count character frequencies
        unordered_map<char, int> freqMap;
        for (char c : s) {
            freqMap[c]++;
        }

        // Step 2: Use a max heap to store characters by frequency
        priority_queue<pair<int, char>> maxHeap;
        for (const auto& entry : freqMap) {
            maxHeap.emplace(entry.second, entry.first);
        }

        // Step 3: Build result string
        string result;
        while (!maxHeap.empty()) {
            auto [freq, ch] = maxHeap.top(); maxHeap.pop();
            result.append(freq, ch);
        }

        return result;
    }
};
