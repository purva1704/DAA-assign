#include <iostream>
using namespace std;

int main() {
    int n, D;

    cout << "Enter the number of tasks: ";
    cin >> n;

    int task[n];

    cout << "Enter the amount of work for each task:" << endl;
    for (int i = 0; i < n; i++) 
        {
        cin >> task[i];
    }

    cout << "Enter the number of days: ";
    cin >> D;

    // Setting boundaries for binary search
    int left = 1;         // Minimum possible work per day
    int right = task[0];   // Maximum work (largest single task)

    // Find the largest task to set the initial right boundary
    for (int i = 1; i < n; i++) {
        if (task[i] > right) {
            right = task[i];
        }
    }

    int result = right;  // Variable to store the minimum work per day

    // Start binary search to find the minimum work per day
    while (left <= right) {
        int mid = left + (right - left) / 2;

        // Check if we can complete the tasks with 'mid' units of work per day
        int curDay = 0;  // Variable to track the number of days used

        for (int i = 0; i < n; i++) {
            // Calculate how many days the current task will take with 'mid' work per day
            int daysNeeded = (task[i] + mid - 1) / mid;  // Equivalent to ceil(task[i] / mid)

            curDay += daysNeeded;

            // If more days are required than allowed, break early
            if (curDay > D) {
                break;
            }
        }

        // If tasks can be completed within 'D' days, search for smaller value
        if (curDay <= D) {
            result = mid;  // Store this as a potential answer
            right = mid - 1;  // Try to find a smaller valid value
        } else {
            left = mid + 1;  // Otherwise, increase the value
        }
    }

    // Output the minimum amount of work per day
    cout << "Minimum amount of work to be done per day: " << result << endl;

    return 0;
}
