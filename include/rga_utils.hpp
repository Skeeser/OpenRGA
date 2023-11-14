#pragma once
#include <iostream>
#include <chrono>

namespace RGA
{

    class Timer
    {
    public:
        Timer() : start_time_(std::chrono::high_resolution_clock::now()) {}

        void Reset()
        {
            start_time_ = std::chrono::high_resolution_clock::now();
        }

        double ElapsedSeconds() const
        {
            auto end_time = std::chrono::high_resolution_clock::now();
            std::chrono::duration<double> elapsed = end_time - start_time_;
            return elapsed.count();
        }

        void PrintElapsedSeconds(const std::string &message = "") const
        {
            std::cout << message << ElapsedSeconds() << " seconds" << std::endl;
        }

    private:
        std::chrono::time_point<std::chrono::high_resolution_clock> start_time_;
        };

    // int main()
    // {
    //     Timer timer;

    //     // 模拟一些耗时的操作
    //     for (int i = 0; i < 1000000; ++i)
    //     {
    //         // Do something...
    //     }

    //     timer.PrintElapsedSeconds("Time taken: ");

    //     // 重新计时
    //     timer.Reset();

    //     // 模拟另一些耗时的操作
    //     for (int i = 0; i < 5000000; ++i)
    //     {
    //         // Do something else...
    //     }

    //     timer.PrintElapsedSeconds("Time taken: ");

    //     return 0;
    // }
}
