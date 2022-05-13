//#include "MQTTClient2.h"
//#include "MQTTListenChild.h"
#include "GameModel.h"
#include "Players.h"
#include <iostream>

int fail ()
{
    cout << "FAIL" <<endl;
    return 0;
}

int pass ()
{
    cout << "PASS" <<endl;
    return 1;
}

int main ()
{
    Players jugador;

    // TESTS FOR CALCULATE ROTATION
    cout << "TESTING FUNCTION CALCULATE ROTATION:: " << endl;

    float angle = jugador.calculateRotation({0,0},{1,1});
    cout << "testing 45°...";
    if(angle < 46 && angle > 44)
        pass();
    else
        fail();

    float angle = jugador.calculateRotation({0,0},{0,0});
    cout << "testing same position...";
    if(angle == 0)
        pass();
    else
        fail();

    float angle = jugador.calculateRotation({-1,-1},{1,1});
    cout << "testing 45° diff places...";
    if(angle < 46 && angle > 44)
        pass();
    else
        fail();

    float angle = jugador.calculateRotation({-1,0},{1,0});
    cout << "testing 0°...";
    if(angle == 0)
        pass();
    else
        fail();

    float angle = jugador.calculateRotation({0,-4},{0,12});
    cout << "testing 90°...";
    if(angle == 90)
        pass();
    else
        fail();

    float angle = jugador.calculateRotation({-1,-1},{2,0});
    cout << "testing 30°...";
    if(angle < 32 && angle > 28) 
        pass();
    else
        fail();

    // TESTS FOR PROPORTIONAL POSITION

    cout << "TESTING FUNCTION POPORTIONAL POSITION:: " << endl;
    coordinate_t coord = jugador.proportionalPosition({0,0},{1,1},0);
    cout << "testing 0 proportion...";
    if(coord.x==0 && coord.z==0) 
        pass();
    else
        fail();

    coordinate_t coord = jugador.proportionalPosition({-1,-1},{1,1},0.5);
    cout << "testing half proportion...";
    if(coord.x==0 && coord.z==0) 
        pass();
    else
        fail();    

    coordinate_t coord = jugador.proportionalPosition({1,1},{1,1},1);
    cout << "testing 1 proportion...";
    if(coord.x==1 && coord.z==1) 
        pass();
    else
        fail();

    coordinate_t coord = jugador.proportionalPosition({0,0},{1,1},2);
    cout << "testing double proportion...";
    if(coord.x==-2 && coord.z==-2) 
        pass();
    else
        fail();

    return 0;
}