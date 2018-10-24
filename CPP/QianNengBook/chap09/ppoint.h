#ifndef HEADER_PPOINT
#define HEADER_PPOINT
class PPoint{
	double x, y;   // 直角坐标抑或极坐标
public:
	PPoint(double ix, double iy);  // 设置坐标
	double xOffset();   // 直角坐标x分量
	double yOffset();   // 直角坐标y分量
	double angle();     // 极坐标弧角
	double radius();    // 极坐标半径
};
#endif
