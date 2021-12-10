#include "Client.h"
#include <iostream>
#include "colormod.h"

Client::Client() {
}

Client::Client(int id, HairDresser *hairDresserPtr) : clientId(id), hairDresser(hairDresserPtr) {
}

int Client::GetId() const {
    return clientId;
}

void Client::DoWork() {
    Color::Modifier color(1 + clientId);
    Color::Modifier def(0);
    while (true) {
        std::this_thread::sleep_for(std::chrono::milliseconds(msThreadBeforeIterate));
        std::cout << color << "Client " << clientId << " is waiting for a new haircut" << std::endl << def;
        std::unique_lock<std::mutex> locker(hairDresser->ClientMutex);
        hairDresser->CurrentIndex = GetId();
        hairDresser->PrivateCV.notify_one();
        hairDresser->ClientsCV.wait(locker);
        std::cout << color << "Client " << clientId << " is done" << std::endl << def;
    }
}
