#include <Servo.h>

Servo axis;

void setup(){
	axis.attach(7);
}

void loop(){
	static int axis_angle_times_ten = 0;

	Servo::refresh();

	axis_angle_times_ten += 1;
	axis_angle_times_ten %= 1800;
	axis.write(axis_angle_times_ten / 10);
}
