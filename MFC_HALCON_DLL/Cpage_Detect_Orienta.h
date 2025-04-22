#pragma once


// Cpage_Detect_Orienta 对话框

class Cpage_Detect_Orienta : public CDialogEx
{
	DECLARE_DYNAMIC(Cpage_Detect_Orienta)

public:
	Cpage_Detect_Orienta(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~Cpage_Detect_Orienta();

// 对话框数据
	enum { IDD = IDD_DIALOG_DETECT_ORIENTA };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
};
