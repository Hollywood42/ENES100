**ENES 100 0401 Material Identification Library** 

**Version 1.0**

**Written by Avi Rosenberg**

Classes: 

In the library we currently have three main classes: move, turn, and dis. Each is explained in more detail below. 

**Move:** 

This class controls the direction of the robot (speed will likely be added later based on the final operating characteristics of the robot). 

**Declaration:** 

    Move(uint8_t left13, uint8_t left24, uint8_t right13, uint8_t right24, uint8_t pwm);

Each of these variables are the pins that the motor drivers are using, for example left13 is the pin that is going to inputs 1 and 3 on the left motor driver. 

**Functions:**

********`void off();`

Shuts the motors off

`void forward(); `

Drives the vehicle forward until an off command is given

`void backward();`

Drives the vehicle backward until an off command is given

**Turn:**

This class turns the vehicle. 

**Declaration:**

    	Turn(uint8_t left13, uint8_t left24, uint8_t right13, uint8_t right24, uint8_t pwm);

Same inputs as the move class. 

**Functions:** 

    void off();

Same as in move class. 

`void left();`

Turns the vehicle left until an off() command is given. Can be combined with camera information in a while loop. 

`void right();` 

Turns the vehicle rights until an off() command is given. Can be combined with camera information in a while loop. 

`void left90(); `

Turns the vehicle 90 degrees to the left. 

    void right90();

Turns the vehicle 90 degrees to the right. 

**Dis:**

This class controls the ultrasonic sensor. 

**Declaration:** 

`Dis(uint8_t trig, uint8_t echo);`

Trig is the pin for the trigger pins, echo is the pin for the echo of the ultrasonic sensor. For each ultrasonic sensor make a new declaration ( ex. Dis disLeft(uint8\_t trig, uint8\_t echo)). 

**Functions:**

`float pulse();`

This sends out one pulse from the ultrasonic sensor and returns a distance value. 

    	float avg(uint8_t readings, uint8_t seconds);

This will send out multiple pulses and return an average distance during the run. The readings variable is how many pulses it will send out over a total measuring time of the seconds variable. _Note: Seconds is stored as an uint8\_t so do not pass decimals._ 
