#pragma once


// Cpage_Segment 对话框

class Cpage_Segment : public CDialogEx
{
	DECLARE_DYNAMIC(Cpage_Segment)

public:
	Cpage_Segment(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~Cpage_Segment();

// 对话框数据
	enum { IDD = IDD_DIALOG_SEGMENT };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
};
