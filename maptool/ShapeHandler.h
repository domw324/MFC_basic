#pragma once
#include <vector>

class CShape;

class CShapeHandler {
public:
	static CShapeHandler* GetInstance();
	void CreateShape(int nShapeType, CPoint pntStart, CPoint pntEnd);
	void DeleteShape(int nIndex);
	void DeleteBack();
	void DeleteAll();
	CShape* GetObject(int nIndex);
	int GetSize();
	// void SetShape(int nIndex, CPoint pntStart, CPoint pntEnd); /// 필요 시 구현

private:
	CShapeHandler();
	~CShapeHandler();
	static CShapeHandler* pShapeHandler;
	std::vector<CShape*> m_ShapeArr;

	int nLineNum;
	int nRectNum;
};