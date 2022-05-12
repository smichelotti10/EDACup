#include "Players.h"
#include <raylib.h>

using namespace std;

Players::Players(string path)
{
    displayImage = LoadImage(path.c_str());
}

Players::~Players()
{
    UnloadImage(displayImage);
}

void Players::start(MQTTClient2 *mqttClient, string playerNumber)
{
    //depende de la entrega
    this->mqttClient = mqttClient;
    playerId = "robot" + teamID + "." + playerNumber.c_str();
}

void Players::setDisplay(string path)
{
    Rectangle selectRectangle = {0, 0, 16, 16};
    Image selectedImage = ImageFromImage(displayImage, selectRectangle);

    const int dataSize = 16 * 16 * 3;
    vector<char> payload(dataSize);
    memcpy(payload.data(), selectedImage.data, dataSize);

    UnloadImage(selectedImage);

    mqttClient->publish(playerId + "/display/lcd/set", payload);
}

// Funcion para trasnformar un float a vector de char.
std::vector<char> Players::getArrayFromFloat(float payload)
{
	std::vector<char> data(sizeof(float));

	// Extraído de: https://www.cplusplus.com/reference/cstring/memcpy/
	memcpy(data.data(), &payload, sizeof(float));

	return data;
}

/*Función de movimiento del robot, a traves de los 4 motores
 *
 * Esta función envia los valores de corriente a cada motor,
 * para obtenerlos se utiliza una transformación lineal
 * sobre la dirección deseada.
 * Ademas utiliza un coeficiente de rotación que permite
 * modificar la matriz de transformación y asi lograr rotar al robot.
 *
 * Normalizando el vector resultante y luego escalandolo
 * por el valor limite permite mantener limitado a los motores
 * y evitar que se quemen
 */
/*void Players::moveMotors()
{
	// Calculo de corriente sobre los motores
	Vector2 direction((int) IsKeyDown(KEY_RIGHT) - IsKeyDown(KEY_LEFT),
							  (int)IsKeyDown(KEY_UP) - IsKeyDown(KEY_DOWN)); //Esto hay que cambiarlo mas adelante

	int rotationCoef = IsKeyDown(KEY_SPACE);

	raylib::Vector4 motor(direction.DotProduct(VECTOR_MOV_1),
						  direction.DotProduct(VECTOR_MOV_2) * (1 - rotationCoef),
						  direction.DotProduct(VECTOR_MOV_3),
						  direction.DotProduct(VECTOR_MOV_4) * (1 + rotationCoef));

	//Creación y Publicación de los mensajes

	MQTTListener msj1, msj2, msj3, msj4;
	msj1.topic = "robot1/motor1/current/set";
	msj2.topic = "robot1/motor2/current/set";
	msj3.topic = "robot1/motor3/current/set";
	msj4.topic = "robot1/motor4/current/set";

	msj1.payload = getArrayFromFloat(LIMIT_CURRENT * motor.Normalize().x);
	msj2.payload = getArrayFromFloat(LIMIT_CURRENT * motor.Normalize().y);
	msj3.payload = getArrayFromFloat(LIMIT_CURRENT * motor.Normalize().z);
	msj4.payload = getArrayFromFloat(LIMIT_CURRENT * motor.Normalize().w);

	mqttClient->publish(msj1.topic, msj1.payload);
	mqttClient->publish(msj2.topic, msj2.payload);
	mqttClient->publish(msj3.topic, msj3.payload);
	mqttClient->publish(msj4.topic, msj4.payload);
}*/

// Función para hacer funcionar el Kricker y el Chipper.
// Estos se activan con la tecla ENTER
/*void Players::setKickerChipper()
{
	class MQTTMessage msj1, msj2, msj3;
	if (IsKeyDown(KEY_ENTER))
	{
		msj1.topic = "robot1/kicker/chargeVoltage/set";
		msj1.payload = getArrayFromFloat(KICKER_CHARGEVOLTAGE);
		publish(msj1.topic, msj1.payload);
		msj2.topic = "robot1/kicker/kick/cmd";
		msj2.payload = getArrayFromFloat(KICKER_KICK);
		publish(msj2.topic, msj2.payload);
		msj3.topic = "robot1/kicker/chip/cmd";
		msj3.payload = getArrayFromFloat(KICKER_CHIP);
		publish(msj3.topic, msj3.payload);
	}
}*/

// Función para encender el Dribbler. Se enciende con la tecla
// Blockspace y se apaga con la tecla M
/*void Players::setDribbler()
{
	class MQTTMessage msj1;
	if (IsKeyDown(KEY_BACKSPACE))
	{
		msj1.topic = "robot1/dribbler/current/set";
		msj1.payload = getArrayFromFloat(DRIBBLER_CURRECT);
		publish(msj1.topic, msj1.payload);
	}
	if (IsKeyDown(KEY_M))
	{
		msj1.topic = "robot1/dribbler/voltage/set";
		msj1.payload = getArrayFromFloat(0.0F);
		publish(msj1.topic, msj1.payload);
	}
}*/