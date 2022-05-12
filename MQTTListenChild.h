#ifndef _MQTTLISTENCHILD_H
#define _MQTTLISTENCHILD_H

#include "MQTTClient2.h"

class MQTTListenChild : public MQTTListener
{
public: 
	void onMessage(std::string topic, std::vector<char> payload);
};

#endif   //_MQTTLISTENCHILD_H un experto programador en C, puede tener problemas en la logica. Un experto programador en c++ puede tener problemas entendiendo c++