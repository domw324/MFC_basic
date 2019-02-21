
// maptoolView.h: CmaptoolView 클래스의 인터페이스
//

#pragma once
#include "maptoolDoc.h"
#include "Shape.h"
#include <vector>
#include <iostream>
#include <WinUser.h>

class CmaptoolView : public CView
{
protected: // serialization에서만 만들어집니다.
	CmaptoolView() noexcept;
	DECLARE_DYNCREATE(CmaptoolView)

// 특성입니다.
public:
	CmaptoolDoc* GetDocument() const;

// 작업입니다.
public:

// 재정의입니다.
public:
	virtual void OnDraw(CDC* pDC);  // 이 뷰를 그리기 위해 재정의되었습니다.
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// 구현입니다.
public:
	virtual ~CmaptoolView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 생성된 메시지 맵 함수
protected:
	afx_msg void OnFilePrintPreview();
	afx_msg void OnRButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnContextMenu(CWnd* pWnd, CPoint point);
	DECLARE_MESSAGE_MAP()

// 넣고 싶은 기능
public: 
	/// 이제 마우스 클릭 이벤트를 생성하자.
	/// 마우스 클릭하면 모드에 해당되는 객체가 생성되고
	/// 생성된 객체에는 시작점과 끝점의 정보가 담긴다.
	/// 암튼 저 Draw를 활용해서 그리는 걸로 하자
	/// 그리고 사각형 내부 색칠을 없에는 함수도 만들자. 얍!
	
	virtual void SetDrawMode(int nDrawMode);

	virtual void DrawLine(CPoint &pntStart, CPoint &pntEnd); /// 라인 생성
	virtual void DrawRect(CPoint &pntStart, CPoint &pntEnd); /// 사각형 생성

	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);

	void PointCheck(CPoint &point);
private:
	int m_nDrawMode;
	bool m_bDragFlag;
	CPoint m_CurrentMouse;
	CPoint m_StartMouse;
};

#ifndef _DEBUG  // maptoolView.cpp의 디버그 버전
inline CmaptoolDoc* CmaptoolView::GetDocument() const
   { return reinterpret_cast<CmaptoolDoc*>(m_pDocument); }
#endif