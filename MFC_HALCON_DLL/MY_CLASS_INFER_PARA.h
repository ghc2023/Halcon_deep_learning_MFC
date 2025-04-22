#pragma once
#include "afxwin.h"


// CMY_CLASS_INFER_PARA 对话框

class CMY_CLASS_INFER_PARA : public CDialogEx
{
	DECLARE_DYNAMIC(CMY_CLASS_INFER_PARA)

public:
	CMY_CLASS_INFER_PARA(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CMY_CLASS_INFER_PARA();

// 对话框数据
	enum { IDD = IDD_DIALOG_CLASS_INFER };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	CString cs_ImageDir;
	double d_class_infer_scalewindows;
	int i_class_infer_BatchSizeInference;
	CString cs_class_infer_KeysForDisplay;
	int i_class_infer_MaxNumberofRandomSamples;
	CComboBox c_combobox_class_infer_usegpu;
	afx_msg void OnEnChangeEdit3();
};
