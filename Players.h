#ifndef PLAYERS_H
#define PLAYERS_H

#include <string>
#include <cstring>
#include <vector>
#include <raylib.h>
#include "MQTTClient2.h"
//#include "GameModel.h"

using namespace std;

class Players
{
public:
    Players(string path);
    ~Players();

    void start(MQTTClient2 *mqttClient, string playerNumber);
    void setDribbler();
    void setKickerChipper();
    void moveMotors();
    vector<char> getArrayFromFloat(float payload);

private:
    MQTTClient2 *mqttClient;

    string teamID;
    string playerId; //robot
    Image displayImage;

    void setDisplay(string path);
};

#endif // PLAYERS_H