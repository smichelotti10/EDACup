#ifndef _GAMEMODEL_H
#define _GAMEMODEL_H

#include "MQTTClient2.h"
#include <vector>
#include "Players.h"

using namespace std;

//class Players;

enum GameState
{
    START, PRE_KICKOFF, KICKOFF, IN_GAME, PRE_FREEKICK, FREEKICK, PRE_PENALTY, PENALTY, 
    PAUSE, CONTINUE, REMOVE_ROBOT, ADD_ROBOT, ENDED_GAME, GOAL
};

class GameModel
{
public:
    GameModel(MQTTClient2 &mqttClient);
    ~GameModel();

    void start(string teamID);
    void suscribeToGameTopics();
    void addPlayer(Players *bot);
    string getTeamID();

    GameState gameState; 
    void updateTime(float deltaTime);
private:
    MQTTClient2 *mqttClient;
    vector<Players *> team;

    string teamID;
    float deltaTime;

};

#endif //_GAMEMODEL_H