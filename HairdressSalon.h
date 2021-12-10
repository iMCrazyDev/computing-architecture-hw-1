#pragma once
#include <condition_variable>
#include <mutex>
#include <thread>

class HairDresser {
public:
    std::condition_variable CV;
    std::mutex Mutex;
    int CurrentIndex;

    HairDresser();

    void DoWork();

};
