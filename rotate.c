#include <Servo.h>

Servo axis;

void setup(){
	axis.attach(7);
}

void loop(){
	static int axis_angle = 0;

	Servo::refresh();

	axis_angle += 1;
	axis_angle %= 180;
	axis.write(axis_angle);
}
