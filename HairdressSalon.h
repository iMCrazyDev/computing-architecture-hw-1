#pragma once
#include <condition_variable>
#include <mutex>
#include <thread>

class HairDresser {
public:
    std::condition_variable PrivateCV;
    std::condition_variable ClientsCV;
    std::mutex ClientMutex;
    int CurrentIndex;

    HairDresser();

    void DoWork();

};
