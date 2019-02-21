#pragma once
#include "Point.h"
#include <atltypes.h>

class CShape
{
public:
	CShape();
	~CShape();

	int GetType();
	void SetPoint(int nStartX, int nStartY, int nEndX, int nEndY);
	CPoint* GetStartPoint();
	CPoint* GetEndPoint();

protected:
	CPoint* pntStart;
	CPoint* pntEnd;
	int nShapeType;

private:
};