//ppoint.h
#ifndef HEADER_PPOINT
#define HEADER_PPOINT
class PPoint{
	double x, y;   // ֱ�����������
public:
	void set(double ix, double iy);  // ��������
	double xOffset();  // ֱ������x����
	double yOffset();  // ֱ������y����
	double angle();    // �����껡��
	double radius();   // ������뾶
};
#endif