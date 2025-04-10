/*
Library for controlling MaterialGworls ENES 100 OTV Project
ENES100 0401 Material Identification Group University of Maryland
Written by Avi Rosenberg
*/

#ifndef Material_h
#define Material_h

#include "Arduino.h"
#include "stdint.h"

class Move {
public:
	Move(uint8_t left13, uint8_t left24, uint8_t right13, uint8_t right24, uint8_t pwm);
	void forward(uint8_t speed);
	void backward(uint8_t, speed);
	void off();
private:
	uint8_t _left13;
	uint8_t _left24;
	uint8_t _right13;
	uint8_t _right24;
	uint8_t _speed;
};

class Turn {
public:
	Turn(uint8_t left13, uint8_t left24, uint8_t right13, uint8_t right24, uint8_t pwm);
	void left(uint8_t seconds);
	void right(uint8_t seconds);
	void left90();
	void right90();
	void off();
private:
	uint8_t _left13;
	uint8_t _left24;
	uint8_t _right13;
	uint8_t _right24;
	uint8_t _sec;
};

class Dis {
public:
	Dis(uint8_t trig, uint8_t echo);
	float pulse();
	float avg(uint8_t readings, uint8_t seconds);
private:
	uint8_t _trig;
	uint8_t _echo;
	uint8_t _sec;
	uint8_t _read;
	float _secPRead;
	float _total;
	float _distance;
	float _duration;
};

class Mission {
public:
	Mission(uint8_t servo, uint8_t screw, uint8_t fsrP);
	int fsr();
	int avgFsr(uint8_t seconds);
	void screwOn();
	void screwOff();
	void servoUp();
	void servoDown();
private:
	uint8_t _servo;
	uint8_t _screw;
	uint8_t _fsr;
	uint8_t _sec;
	int _total;
};
#endif
