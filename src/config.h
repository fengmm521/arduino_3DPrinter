//Command
#define MYSERIAL Serial
#define SPEED_SERIAL 250000
#define GCODE_BUFF_SIZE 3
//XYMG

#define SPEED_SPI 50000000
#define BASE_VOLTAGE 4.8//
#define LASER_OFF_POWER 10//0-255  correspond 0-5W (when the laser max power is 5W)
#define LASER_ON_POWER 255
#define PIN_XY 16
#define PIN_LASER 32
//Stepper
#define STEPPER_A_STEP_PER_UNIT 13.3333
#define STEPPER_A_ACCELERATION 300
#define STEPPER_A_TIMER Timer4
#define STEPPER_A_SPEED 250
#define STEPPER_A_PIN_EN 24
#define STEPPER_A_PIN_STEP 47
#define STEPPER_A_PIN_DIR 45
#define STEPPER_A_NEGATE false

#define STEPPER_B_STEP_PER_UNIT 200
#define STEPPER_B_ACCELERATION 100
#define STEPPER_B_TIMER Timer4
#define STEPPER_B_SPEED 50
#define STEPPER_B_PIN_EN 0
#define STEPPER_B_PIN_STEP 43
#define STEPPER_B_PIN_DIR 41
#define STEPPER_B_NEGATE true


#define STEPPER_C_STEP_PER_UNIT 200
#define STEPPER_C_ACCELERATION 100
#define STEPPER_C_TIMER Timer4
#define STEPPER_C_SPEED 50
#define STEPPER_C_PIN_EN 0
#define STEPPER_C_PIN_STEP 39
#define STEPPER_C_PIN_DIR 37
#define STEPPER_C_NEGATE true

#define Stepper_A_DISTANCE_MAX 400

//Planner
#define DA_VAL_BUFF_SIZE 3
#define DA_VAL_ARRY_SIZE 6000
#define SPEED_XY 3000 //  mm per seconds
#define DIS_F_THETA 260//distance between F-Theta and plane
#define DIS_XYMOTOR 8
#define RAD_MG_MAX 0.349065 //the Mirror galvanometer max rad  (20/180*pi)
#define CYCLE_LNTERPOLARION 3000// per seconds

//heating
#define HEATING_PIN 35
#define HEATING_CYCLE 4000000 //mirosecond
#define HEATING_PROPORTION 0.43
#define HEATING_TIMER Timer6
