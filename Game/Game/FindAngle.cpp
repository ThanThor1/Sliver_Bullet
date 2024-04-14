#include "FindAngle.h"
#include "SomeConst.h"
#include "Library.h"
double FindAngle(int x1, int y1, int x2, int y2) {
    double denta_x=x2-x1;
	double denta_y=y2-y1;
	double angle = 0;
	double slope = denta_x / denta_y;
	if (denta_x > 0 && denta_y > 0) {
		angle = 360 - atan(slope) / PI * 180;
	}
	else if (denta_x < 0 && denta_y > 0) {
		angle = -atan(slope) / PI * 180;
	}
	else if (denta_x < 0 && denta_y < 0) {
		angle = 180 - atan(slope) / PI * 180;
	}
	else if (denta_x > 0 && denta_y < 0) {
		angle = 180 - atan(slope) / PI * 180;
	}
	
	if (denta_x == 0 && denta_y > 0) {
		angle = 0;
	}
	if (denta_x == 0 && denta_y < 0) {
		angle = 180;
	}
	if (denta_y == 0 && denta_x < 0) {
		angle = 90;
	}
	if (denta_y == 0 && denta_x > 0) {
		angle = 270;
	}
	return angle;
}