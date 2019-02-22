#pragma once
#include "Point.h"
#include <atltypes.h>

class CShape
{
public:
	CShape();
	~CShape();

	virtual int GetType();
	virtual void SetShapeInfo(int nId, CPoint pntStart, CPoint pntEnd);
	virtual CShape* GetInstance();
	virtual int GetId();
	virtual CPoint GetStartPoint();
	virtual CPoint GetEndPoint();

protected:
	CPoint pntStart;
	CPoint pntEnd;
	int nShapeType;

private:
	int nId;
};