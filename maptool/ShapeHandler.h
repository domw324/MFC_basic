#pragma once
#include <vector>
#include <iostream>
#include "Shape.h"

class CShapeHandler {
public:
	CShapeHandler();
	~CShapeHandler();

	void CreateShape(int nShapeType, int nStartX, int nStartY, int nEndX, int nEndY);
	void DeleteShape(int nIndex);

private:
	std::vector<CShape*> *m_ShapeArr;
};