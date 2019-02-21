#pragma once
#include <vector>

class CShape;

class CShapeHandler {
public:
	CShapeHandler();
	~CShapeHandler();

	void CreateShape(int nShapeType, CPoint pntStart, CPoint pntEnd);
	void DeleteShape(int nIndex);
	void DeleteAll();
	CShape* GetObject(int nIndex);
	int GetSize();
	// void SetShape(int nIndex, CPoint pntStart, CPoint pntEnd); /// �ʿ� �� ����

	std::vector<CShape*> m_ShapeArr;
};