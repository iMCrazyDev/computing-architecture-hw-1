#include "HairdressSalon.h"
#include <iostream>
#define msThreadSleepTime 300

HairDresser::HairDresser() {
}

void HairDresser::DoWork() {
    std::unique_lock<std::mutex> locker(ClientMutex);
    while (true) {
        std::cout << "Hairdresser is sleepin'..." << std::endl;
        PrivateCV.wait(locker);
        std::cout << "Hairdresser is workin' with client id " << CurrentIndex << " ... " << std::endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(msThreadSleepTime));
        ClientsCV.notify_one();
    }
}
