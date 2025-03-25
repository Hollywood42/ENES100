/*
Library for controlling MaterialGworls ENES 100 OTV Project
ENES100 0401 Material Identification Group University of Maryland
Written by Avi Rosenberg
*/

#include "Arduino.h"
#include "Material.h"
#include "stdint.h"


Move::Move(uint8_t left13, uint8_t left24, uint8_t right13, uint8_t right24, uint8_t pwm) {
	_left13 = left13;
	_left24 = left24;
	_right13 = right13;
	_right24 = right24;
	pinMode(left13, OUTPUT);
	pinMode(left24, OUTPUT);
	pinMode(right13, OUTPUT);
	pinMode(right24, OUTPUT);
}
void Move::forward() {
	digitalWrite(_left13, HIGH);
	digitalWrite(_left24, LOW);
	digitalWrite(_right13, HIGH);
	digitalWrite(_right24, LOW);
}

void Move::backward() {
	digitalWrite(_left13, LOW);
	digitalWrite(_left24, LOW);
	digitalWrite(_right13, LOW);
	digitalWrite(_right24, LOW);
}

void Move::off() {
	digitalWrite(_left13, LOW);
	digitalWrite(_left24, LOW);
	digitalWrite(_right13, LOW);
	digitalWrite(_right24, LOW);
}

Turn::Turn(uint8_t left13, uint8_t left24, uint8_t right13, uint8_t right24, uint8_t pwm) {
	_left13 = left13;
	_left24 = left24;
	_right13 = right13;
	_right24 = right24;
	pinMode(left13, OUTPUT);
	pinMode(left24, OUTPUT);
	pinMode(right13, OUTPUT);
	pinMode(right24, OUTPUT);
}
void Turn::left(uint8_t seconds) {
	_sec = seconds;
	digitalWrite(_left13, LOW);
	digitalWrite(_left24, HIGH);
	digitalWrite(_right13, HIGH);
	digitalWrite(_right24, LOW);
	delay(_sec);
	digitalWrite(_left13, LOW);
	digitalWrite(_left24, LOW);
	digitalWrite(_right13, LOW);
	digitalWrite(_right24, LOW);
}

void Turn::right(uint8_t seconds) {
	_sec = seconds;
	digitalWrite(_left13, HIGH);
	digitalWrite(_left24, LOW);
	digitalWrite(_right13, LOW);
	digitalWrite(_right24, HIGH);
	delay(_sec);
	digitalWrite(_left13, LOW);
	digitalWrite(_left24, LOW);
	digitalWrite(_right13, LOW);
	digitalWrite(_right24, LOW);
}

void Turn::left90() {
	_sec = 3;
	digitalWrite(_left13, LOW);
	digitalWrite(_left24, HIGH);
	digitalWrite(_right13, HIGH);
	digitalWrite(_right24, LOW);
	delay(_sec);
	digitalWrite(_left13, LOW);
	digitalWrite(_left24, LOW);
	digitalWrite(_right13, LOW);
	digitalWrite(_right24, LOW);
}

void Turn::right90() {
	_sec = 3;
	digitalWrite(_left13, HIGH);
	digitalWrite(_left24, LOW);
	digitalWrite(_right13, LOW);
	digitalWrite(_right24, HIGH);
	delay(_sec);
	digitalWrite(_left13, LOW);
	digitalWrite(_left24, LOW);
	digitalWrite(_right13, LOW);
	digitalWrite(_right24, LOW);
}

void Turn::off() {
	digitalWrite(_left13, LOW);
	digitalWrite(_left24, LOW);
	digitalWrite(_right13, LOW);
	digitalWrite(_right24, LOW);
}

Dis::Dis(uint8_t trig, uint8_t echo) {
	_trig = trig;
	_echo = echo;
	pinMode(trig, OUTPUT);
	pinMode(echo, INPUT);
}

float Dis::pulse() {
	digitalWrite(_trig, LOW);
	delayMicroseconds(2);
	digitalWrite(_trig, HIGH);
	delayMicroseconds(10);
	digitalWrite(_trig, LOW);

	_duration = pulseIn(_echo, HIGH);
	_distance = (_duration * .0343) / 2;

	return _distance;
	
}

float Dis::avg(uint8_t readings, uint8_t seconds) {
	_read = readings;
	_sec = seconds;
	_secPRead = seconds / readings;

	for (int i = 0; i < _read; i++) {
		digitalWrite(_trig, LOW);
		delayMicroseconds(2);
		digitalWrite(_trig, HIGH);
		delayMicroseconds(10);
		digitalWrite(_trig, LOW);

		_duration = pulseIn(_echo, HIGH);
		_distance = (_duration * .0343) / 2;

		_total = _total + _distance;

		delay(_secPRead);
	}
	return _total / _read;
}

