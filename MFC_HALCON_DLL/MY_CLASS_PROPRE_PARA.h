#pragma once
#include "afxwin.h"


// CMY_CLASS_PROPRE_PARA 对话框

class CMY_CLASS_PROPRE_PARA : public CDialogEx
{
	DECLARE_DYNAMIC(CMY_CLASS_PROPRE_PARA)

public:
	CMY_CLASS_PROPRE_PARA(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CMY_CLASS_PROPRE_PARA();

// 对话框数据
	enum { IDD = IDD_DIALOG_CLASS_PREPRO };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	CComboBox m_combo_class_LabelSource;
	afx_msg void OnCbnSelchangeComboClassLabelsource();
	int i_TrainingPercent;
	int i_ValidationPercent;
	int i_ImageWidth;
	int i_ImageHeight;
	int i_ImageNumChannels;
	CComboBox m_combo_class_normalization;
	CComboBox m_combo_class_domainhandling;
	float f_class_pre_meanvalues1;
	float f_class_pre_meanvalues2;
	float f_class_pre_meanvalues3;
	float f_class_pre_deviationvalues1;
	float f_class_pre_deviationvalues2;
	float f_class_pre_deviationvalues3;
	CComboBox m_combo_is_overwrite_files;
	afx_msg void OnBnClickedButtonClassPreproSavePara();
	int i_class_prepro_seedrand;
	int i_class_perpro_image_range_min;
	int i_class_perpro_image_range_max;
};
