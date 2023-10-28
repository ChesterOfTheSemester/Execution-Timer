/**
 * Execution Timer
 * A C++ script that allows you to do multiple execution time calculations.
 *
 * Author: Chester Abrahams
 * GitHub: https://github.com/ChesterOfTheSemester/Execution-Timer
 */

#ifndef H_EXEC_TIMER
#define H_EXEC_TIMER

#include <iostream>
#include <vector>
#include <unordered_map>

class {
private:
    std::unordered_map <int, long long> stack;

    long long currentTimestamp() {
        struct timespec te;
        clock_gettime(CLOCK_REALTIME, &te);
        return (long long) te.tv_sec * 1000 + te.tv_nsec / 1000000; // Convert to milliseconds
    }

public:
    long long time(int uuid = 0) {
        long long rtn = 0;

        // Add if timer does not exist yet
        if (stack.find(uuid) == stack.end())
            stack[uuid] = static_cast<long long> (0);

        // Calculate time difference or store current time
        if (stack[uuid] > 0) {
            rtn = currentTimestamp() - stack[uuid];
            stack[uuid] = static_cast<long long> (0);
        }
        else stack[uuid] = static_cast<long long> (currentTimestamp());

        return rtn;
    }
} execution_timer;

#endif