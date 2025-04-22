#pragma once
#include "afxwin.h"


// CMY_CLASS_TRAIN_PARA 对话框

class CMY_CLASS_TRAIN_PARA : public CDialogEx
{
	DECLARE_DYNAMIC(CMY_CLASS_TRAIN_PARA)

public:
	CMY_CLASS_TRAIN_PARA(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CMY_CLASS_TRAIN_PARA();

// 对话框数据
	enum { IDD = IDD_DIALOG_CLASS_TRAIN };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	int i_class_train_BatchSize;
	float f_class_train_Momentum;
	int i_class_train_NumEpochs;
	float f_class_train_InitialLearningRate;
	CString cs_class_train_ChangeLearningRateEpochs;
	afx_msg void OnBnClickedButtonSaveClassTrainPara();
	float f_class_train_WeightPrior;
	CString cs_ChangeLearningRateValues;
	int i_augmentation_percentage;
	CComboBox m_combobox_class_train_EnableDisplay;
	int i_SelectedPercentageTrainSamples;
	int i_update_images_interval_epochs;
	int i_change_plot_interval_seconds;
	int i_update_interval_seconds;
	int i_EvaluationIntervalEpochs;
	CString cs_BestModelBaseName;
	CString cs_FinalModelBaseName;
	int i_class_train_RandomSeed;
	CComboBox c_combocox_class_train_Augmentation_Method;
	CComboBox c_combobox_class_train_Augmentation_Value;
	CString cs_Class_Train_Augmentation_Value;
	afx_msg void OnCbnSelchangeComboAugmentationMethod();
};
