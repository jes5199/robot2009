#include <Servo.h>

Servo axis;

void setup(){
	axis.attach(7);
}

void loop(){
	static int axis_counter     = 0;
	static int axis_counter_max = 10;
	static int axis_angle       = 0;
	static int axis_direction   = 1;

	axis.write(axis_angle);
	Servo::refresh();

	axis_counter += 1;
	if(axis_counter >= axis_counter_max){
		axis_counter = 0;
		axis_angle += axis_direction;
		if(axis_angle >= 180){
			axis_direction = -1;
		}
		if(axis_angle <= 0){
			axis_direction = 1;
		}
	}
}
