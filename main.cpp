#include <iostream>
#include "Client.h"
#define MaxClients 10
#define msThreadSleepStartTime 1000

int main() {

    auto startWork = [](HairDresser* dresser) { dresser->DoWork(); };
    auto startClient = [](Client *client) { client->DoWork(); };
    std::cout << "Enter number of clients in salon" << std::endl;
    int numberOfClients;
    std::cin >> numberOfClients;
    HairDresser dresser;
    std::thread thMain(startWork, &dresser);
    std::this_thread::sleep_for(std::chrono::milliseconds(msThreadSleepStartTime));

    Client clients[MaxClients];
    std::thread threads[MaxClients];

    for (int i = 0; i < numberOfClients; ++i) {
        clients[i] = Client(i, &dresser);
        std::thread th(startClient, &clients[i]);
        threads[i] = std::move(th);
    }

    for (int i = 0; i < numberOfClients; ++i) {
        threads[i].join();
    }
    
    thMain.join();
    return 0;
}
