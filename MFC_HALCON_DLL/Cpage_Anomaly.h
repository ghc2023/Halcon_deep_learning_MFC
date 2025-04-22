#pragma once


// Cpage_Anomaly 对话框

class Cpage_Anomaly : public CDialogEx
{
	DECLARE_DYNAMIC(Cpage_Anomaly)

public:
	Cpage_Anomaly(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~Cpage_Anomaly();

// 对话框数据
	enum { IDD = IDD_DIALOG_ANOMALY };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
};
