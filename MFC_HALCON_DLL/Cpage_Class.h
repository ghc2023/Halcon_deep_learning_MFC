#pragma once


// Cpage_Class 对话框

class Cpage_Class : public CDialogEx
{
	DECLARE_DYNAMIC(Cpage_Class)

public:
	Cpage_Class(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~Cpage_Class();

// 对话框数据
	enum { IDD = IDD_DIALOG_CLASS };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButtonPreproParaClass();
	afx_msg void OnBnClickedButtonTrainParaClass();
	afx_msg void OnBnClickedButtonEvaluaParaClass();
	afx_msg void OnBnClickedButtonInferParaClass();
};
