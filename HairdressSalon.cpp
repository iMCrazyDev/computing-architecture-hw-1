#include "HairdressSalon.h"
#include <iostream>
#define msThreadSleepTime 3000

HairDresser::HairDresser() {
}

void HairDresser::DoWork() {
    std::unique_lock<std::mutex> locker(Mutex);
    while (true) {
        std::cout << "Hairdresser is sleepin'..." << std::endl;
        CV.wait(locker);
        std::cout << "Hairdresser is workin' with client id " << CurrentIndex << " ... " << std::endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(msThreadSleepTime));
        CV.notify_one();
    }
}
