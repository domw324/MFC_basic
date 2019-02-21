#pragma once


// CDlgTab2 대화 상자

class CDlgTab2 : public CDialog
{
	DECLARE_DYNAMIC(CDlgTab2)

public:
	CDlgTab2(CWnd* pParent = nullptr);   // 표준 생성자입니다.
	virtual ~CDlgTab2();

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG2 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX)
	{
		CDialog::DoDataExchange(pDX);
	}    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()

 	
public:
	virtual afx_msg void OnBnClickedButtonLine();
	virtual afx_msg void OnBnClickedButtonRect();
	afx_msg void OnBnClickedButtonBack();
	afx_msg void OnBnClickedButtonDeleteAll();

private:
};
