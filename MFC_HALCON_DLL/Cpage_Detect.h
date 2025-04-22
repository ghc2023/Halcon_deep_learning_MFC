#pragma once


// Cpage_Detect 对话框

class Cpage_Detect : public CDialogEx
{
	DECLARE_DYNAMIC(Cpage_Detect)

public:
	Cpage_Detect(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~Cpage_Detect();

// 对话框数据
	enum { IDD = IDD_DIALOG_DETECT };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
};
