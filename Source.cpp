#include <math.h>
#include <stdio.h>

struct pt {
	float x, y;
};

struct line {
	float a, b, c;
};

//���������� ������������ ������� 2�2
double det(double a, double b, double c, double d) {
	return a * d - b * c;
}

//���������� ����� �����������
bool intersect(line m, line n, pt &res) {
	double zn = det(m.a, m.b, n.a, n.b);
	if (abs(zn) <= 0)
		return false;
	res.x = -det(m.c, m.b, n.c, n.b) / zn;
	res.y = -det(m.a, m.c, n.a, n.c) / zn;
	return true;
}
//�������� �� ������������� ������
bool parallel(line m, line n) {
	return abs(det(m.a, m.b, n.a, n.b)) <= 0;
}
//�������� �� ���������� ������
bool equivalent(line m, line n) {
	return abs(det(m.a, m.b, n.a, n.b)) <= 0
		&& abs(det(m.a, m.c, n.a, n.c)) <= 0
		&& abs(det(m.b, m.c, n.b, n.c)) <= 0;
}
//���������� ���� ����� �������
float angle(line m, line n) {
	return acos(fabs(m.a * n.a + m.b * n.b)
		(sqrt(m.a * m.a + m.b * m.b) * sqrt(n.a * n.a + n.b * n.b)));
};

