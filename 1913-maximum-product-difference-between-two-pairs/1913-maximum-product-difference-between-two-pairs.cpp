class Solution {
public:
    int maxProductDifference(vector<int>& nums) {
        if (nums.size() < 4) {
            return -1;
        }
        int largest = INT_MIN;
        int second_largest = INT_MIN;
        int smallest = INT_MAX;
        int second_smallest = INT_MAX;

        for (int x : nums) {
            if (x >= largest) {
                second_largest = largest;
                largest = x;
            } else if (x > second_largest ) {
                second_largest = x;
            }
        }

        for (int x : nums) {
            if (x <= smallest) {
                second_smallest = smallest;
                smallest = x;
            } else if (x < second_smallest ) {
                second_smallest = x;
            }
        }

        return (largest * second_largest - smallest * second_smallest);
    }
};