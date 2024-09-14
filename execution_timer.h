/**
* Execution Timer
 * A high-performance C++ class for execution time calculations using arithmetic optimizations.
 *
 * Author: Chester Abrahams
 * GitHub: https://github.com/ChesterOfTheSemester/Execution-Timer
 */

#ifndef H_EXEC_TIMER
#define H_EXEC_TIMER

#include <unordered_map>
#include <chrono>

class ExecutionTimer {
private:
    struct TimerData { int64_t start_time = 0; };
    std::unordered_map<int, TimerData> timers;

public:
    // Starts or stops the timer associated with the uuid.
    // If the timer is not running, starts it and returns 0.
    // If the timer is running, stops it and returns elapsed time in nanoseconds.
    inline int64_t time(int uuid = 0)
    {
        // Get current time in milliseconds since epoch
        int64_t now = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now().time_since_epoch()).count();
        TimerData &timer = timers[uuid]; // Access the timer data directly
        int64_t is_running = timer.start_time != 0; // Determine if the timer is running
        int64_t elapsed_ms = now - timer.start_time; // Calculate elapsed time in milliseconds

        timer.start_time = now * (1 - is_running); // Toggle the timer state using arithmetic
        elapsed_ms *= is_running; // Multiply elapsed time by is_running to zero it if the timer was not running
        return elapsed_ms;
    }
};

static ExecutionTimer execution_timer;

#endif
