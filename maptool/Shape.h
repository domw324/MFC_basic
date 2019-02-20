#pragma once
#include "Point.h"

class CShape
{
public:
	CShape();
	~CShape();

	int GetType();
	void SetPoint(int nStartX, int nStartY, int nEndX, int nEndY);
	void SetStartPoint(int nStartX, int nStartY);
	void SetEndPoint(int nEndX, int nEndY);

protected:
	Point* pntStart;
	Point* pntEnd;
	int nShapeType;

private:
};