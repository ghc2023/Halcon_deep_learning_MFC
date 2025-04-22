#pragma once
#include "afxwin.h"


// CMY_CLASS_EVALUE_PARA 对话框

class CMY_CLASS_EVALUE_PARA : public CDialogEx
{
	DECLARE_DYNAMIC(CMY_CLASS_EVALUE_PARA)

public:
	CMY_CLASS_EVALUE_PARA(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CMY_CLASS_EVALUE_PARA();

// 对话框数据
	enum { IDD = IDD_DIALOG_CLASS_EVALUE };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	CString cs_ClassificationMeasures;
	int i_BatchSize;
	CComboBox c_combobox_UseGPU;
	CString CS_display_mode_value;
	CComboBox c_combobox_calss_evalue_SelectedHeatmapInfClassName;
	CComboBox c_combobox_calss_evalue_SelectedHeatmapGTClassName;
	CComboBox c_combobox_class_evalue_HeatmapMethod;
	double d_class_evalue_waitsecond;
	CComboBox c_combobox_class_evalue_IsShowHeatMap;
	int i_class_evalue_MaxNumberofRandomSamples;
	afx_msg void OnCbnSelchangeCombo1();
	afx_msg void OnBnClickedButtonSaveClassEvaluePara();
	afx_msg void OnCbnSelchangeCombo4();
};
