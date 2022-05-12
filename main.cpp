#include "MQTTClient2.h"
#include "Players.h"

void subscribeTopics (MQTTClient2 &client);

int main ()
{
    MQTTClient2 client;


    return 0;
}

void subscribeTopics (MQTTClient2 &client)
{

    for(int i = 1; i <5 ;)
    {

    }


    client->subscribe("robot1.1/motion/state");
    client->subscribe("robot1.1/power/powerConsumption");
    client->subscribe("robot1.1/power/batteryLevel");

    client->subscribe("robot1.1/motor1/voltage");
    client->subscribe("robot1.1/motor1/rpm");
    client->subscribe("robot1.1/motor1/temperature");
    client->subscribe("robot1.1/motor1/voltage/set");
    client->subscribe("robot1.1/motor1/current/set");

    client->subscribe("robot1.1/motor2/voltage");
    client->subscribe("robot1.1/motor2/rpm");
    client->subscribe("robot1.1/motor2/temperature");
    client->subscribe("robot1.1/motor2/voltage/set");
    client->subscribe("robot1.1/motor2/current/set");

    client->subscribe("robot1.1/motor3/voltage");
    client->subscribe("robot1.1/motor3/rpm");
    client->subscribe("robot1.1/motor3/temperature");
    client->subscribe("robot1.1/motor3/voltage/set");
    client->subscribe("robot1.1/motor3/current/set");

    client->subscribe("robot1.1/motor4/voltage");
    client->subscribe("robot1.1/motor4/rpm");
    client->subscribe("robot1.1/motor4/temperature");
    client->subscribe("robot1.1/motor4/voltage/set");
    client->subscribe("robot1.1/motor4/current/set");

    client->subscribe("robot1.1/dribbler/voltage");
    client->subscribe("robot1.1/dribbler/rpm");
    client->subscribe("robot1.1/dribbler/temperature");
    client->subscribe("robot1.1/dribbler/voltage/set");
    client->subscribe("robot1.1/dribbler/current/set");
}