#pragma once
#include "HairdressSalon.h"
#define msThreadBeforeIterate 300
class Client {
public:
    Client();

    Client(int id, HairDresser *hairDresserPtr);

    int GetId() const;

    void DoWork();

private:
    HairDresser *hairDresser;
    int clientId;
};
