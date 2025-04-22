// MY_CLASS_PROPRE_PARA.cpp : 实现文件
//

#include "stdafx.h"
#include "MFC_HALCON_DLL.h"
#include "MY_CLASS_PROPRE_PARA.h"
#include "afxdialogex.h"
#include "Halcon_public.h"
#include "Halconcpp.h"
#include "HDevThread.h"
using namespace HalconCpp;

extern CLASS_PREPRO_S  Class_Prepro;
//extern CLASS_PREPRO_S  Class_Prepros;
// extern HTuple  hv_Class_Propre_TrainingValidationPercent;
// extern HTuple  hv_Class_Propre_ImagePreprocessFeatures;
// 
// extern HTuple  hv_Class_Propre_ImageWidth;
// extern HTuple  hv_Class_Propre_ImageHeight;
// extern HTuple  hv_Class_Propre_ImageChannels;
// 
// extern HTuple  hv_Class_Propre_Domainhandling;
// extern HTuple  hv_Class_Propre_NormalizationType;
// 
// // extern HTuple  hv_Class_Propre_SeedRand;
// // extern HTuple  hv_Class_Propre_ImageRangeMin;
// // extern HTuple  hv_Class_Propre_ImageRangeMax;
// 
// extern HTuple  hv_Class_Propre_Is_overwrite_files;
// extern HTuple  hv_Class_Propre_LabelSource;
// 
// extern HTuple  hv_Class_Propre_constant_values_mean_values_normalization;
// extern HTuple  hv_Class_Propre_constant_values_deviation_values_normalization;
// CMY_CLASS_PROPRE_PARA 对话框

IMPLEMENT_DYNAMIC(CMY_CLASS_PROPRE_PARA, CDialogEx)

CMY_CLASS_PROPRE_PARA::CMY_CLASS_PROPRE_PARA(CWnd* pParent /*=NULL*/)
	: CDialogEx(CMY_CLASS_PROPRE_PARA::IDD, pParent)
	, i_TrainingPercent(70)
	, i_ValidationPercent(15)
	, i_ImageWidth(300)
	, i_ImageHeight(300)
	, i_ImageNumChannels(3)
	, f_class_pre_meanvalues1(123.675)
	, f_class_pre_meanvalues2(116.28)
	, f_class_pre_meanvalues3(103.53)
	, f_class_pre_deviationvalues1(58.395)
	, f_class_pre_deviationvalues2(57.12 )
	, f_class_pre_deviationvalues3(57.375)
	, i_class_prepro_seedrand(42)
	, i_class_perpro_image_range_min(-127)
	, i_class_perpro_image_range_max(128)
{

}

CMY_CLASS_PROPRE_PARA::~CMY_CLASS_PROPRE_PARA()
{
}

void CMY_CLASS_PROPRE_PARA::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_COMBO_CLASS_LABELSOURCE, m_combo_class_LabelSource);

	// 为组合框控件的列表框添加列表项“last_folder” ;  
	m_combo_class_LabelSource.AddString(_T("last_folder"));
	// 为组合框控件的列表框添加列表项“file_name”;   
	m_combo_class_LabelSource.AddString(_T("file_name"));
	// 在组合框控件的列表框中索引为1的位置插入列表项“file_name_remove_index”;   
	m_combo_class_LabelSource.InsertString(2, _T("file_name_remove_index"));
	// 默认选择第一项   ;
	m_combo_class_LabelSource.SetCurSel(0);
	// 编辑框中默认显示第一项的文字“last_folder”   
	//SetDlgItemText(IDC_SEL_WEB_EDIT, _T("last_folder"));
	DDX_Text(pDX, IDC_EDIT_TrainingPercent, i_TrainingPercent);
	DDX_Text(pDX, IDC_EDIT_ValidationPercent, i_ValidationPercent);
	DDX_Text(pDX, IDC_EDIT_ImageWidth, i_ImageWidth);
	DDX_Text(pDX, IDC_EDIT_ImageHeight, i_ImageHeight);
	DDX_Text(pDX, IDC_EDIT_ImageNumChannels, i_ImageNumChannels);
	DDX_Control(pDX, IDC_COMBO_normalization, m_combo_class_normalization);

	// 为组合框控件的列表框添加列表项“none” ;  
	m_combo_class_normalization.AddString(_T("none"));
	// 为组合框控件的列表框添加列表项“all_channels”;   
	m_combo_class_normalization.AddString(_T("all_channels"));
	// 在组合框控件的列表框中索引为1的位置插入列表项“first_channel”;   
	m_combo_class_normalization.AddString(_T("first_channel"));
	// 在组合框控件的列表框中索引为1的位置插入列表项“constant_values”;   
	m_combo_class_normalization.InsertString(3, _T("constant_values"));
	// 默认选择第一项   ;
	m_combo_class_normalization.SetCurSel(1);

	DDX_Control(pDX, IDC_COMBO_DOMAINHANDING, m_combo_class_domainhandling);
	// 为组合框控件的列表框添加列表项“none” ;  
	m_combo_class_domainhandling.AddString(_T("full_domain"));
	// 为组合框控件的列表框添加列表项“all_channels”;   
	m_combo_class_domainhandling.AddString(_T("crop_domain"));
	// 在组合框控件的列表框中索引为1的位置插入列表项“first_channel”;   
	m_combo_class_domainhandling.InsertString(2, _T("keep_domain"));

	// 默认选择第一项   ;
	m_combo_class_domainhandling.SetCurSel(0);

	DDX_Text(pDX, IDC_EDIT_MeanValues1, f_class_pre_meanvalues1);
	DDX_Text(pDX, IDC_EDIT_MeanValues2, f_class_pre_meanvalues2);
	DDX_Text(pDX, IDC_EDIT_MeanValues3, f_class_pre_meanvalues3);

	DDX_Text(pDX, IDC_EDIT_DeviationValues1, f_class_pre_deviationvalues1);
	DDX_Text(pDX, IDC_EDIT_DeviationValues2, f_class_pre_deviationvalues2);
	DDX_Text(pDX, IDC_EDIT_DeviationValues3, f_class_pre_deviationvalues3);

	DDX_Control(pDX, IDC_COMBO3, m_combo_is_overwrite_files);

	// 为组合框控件的列表框添加列表项“none” ;  
	m_combo_is_overwrite_files.AddString(_T("true"));
	// 为组合框控件的列表框添加列表项“all_channels”;   
	m_combo_is_overwrite_files.AddString(_T("false"));
	// 默认选择第一项   ;
	m_combo_is_overwrite_files.SetCurSel(0);
	DDX_Text(pDX, IDC_EDIT2, i_class_prepro_seedrand);


	DDX_Text(pDX, IDC_EDIT1, i_class_perpro_image_range_min);
	DDX_Text(pDX, IDC_EDIT6, i_class_perpro_image_range_max);

}


BEGIN_MESSAGE_MAP(CMY_CLASS_PROPRE_PARA, CDialogEx)
	ON_CBN_SELCHANGE(IDC_COMBO_CLASS_LABELSOURCE, &CMY_CLASS_PROPRE_PARA::OnCbnSelchangeComboClassLabelsource)
	ON_BN_CLICKED(IDC_BUTTON_CLASS_PREPRO_SAVE_PARA, &CMY_CLASS_PROPRE_PARA::OnBnClickedButtonClassPreproSavePara)
END_MESSAGE_MAP()


// CMY_CLASS_PROPRE_PARA 消息处理程序


void CMY_CLASS_PROPRE_PARA::OnCbnSelchangeComboClassLabelsource()
{
	// TODO:  在此添加控件通知处理程序代码
}


void CMY_CLASS_PROPRE_PARA::OnBnClickedButtonClassPreproSavePara()
{
	// TODO:  在此添加控件通知处理程序代码
	UpdateData(TRUE);
	int nIndex = 0;
	CString strCBText;

	Class_Prepro.hv_TrainingValidationPercent[0] = i_TrainingPercent;
	Class_Prepro.hv_TrainingValidationPercent[1] = i_ValidationPercent;

	Class_Prepro.hv_ImagePreprocessFeatures[0] = i_ImageWidth;
	Class_Prepro.hv_ImagePreprocessFeatures[1] = i_ImageHeight;
	Class_Prepro.hv_ImagePreprocessFeatures[2] = i_ImageNumChannels;

	nIndex = m_combo_class_normalization.GetCurSel();
	m_combo_class_normalization.GetLBText(nIndex, strCBText);
	Class_Prepro.hv_ImagePreprocessFeatures[3] = strCBText.GetBuffer(strCBText.GetLength());

	nIndex = m_combo_class_domainhandling.GetCurSel();
	m_combo_class_domainhandling.GetLBText(nIndex, strCBText);
	Class_Prepro.hv_ImagePreprocessFeatures[4] = strCBText.GetBuffer(strCBText.GetLength());

	nIndex = m_combo_is_overwrite_files.GetCurSel();
	m_combo_is_overwrite_files.GetLBText(nIndex, strCBText);
	if (strCBText=="true")
	{
		Class_Prepro.hv_Is_overwrite_files = true;
	}
	else
	{
		Class_Prepro.hv_Is_overwrite_files = false;
	}

	nIndex = m_combo_class_LabelSource.GetCurSel();
	m_combo_class_LabelSource.GetLBText(nIndex, strCBText);
	Class_Prepro.hv_LabelSource = strCBText.GetBuffer(strCBText.GetLength());

// 	hv_Class_Propre_SeedRand = i_class_prepro_seedrand;
// 
// 	hv_Class_Propre_ImageRangeMin = i_class_perpro_image_range_min;
// 	hv_Class_Propre_ImageRangeMax = i_class_perpro_image_range_max;
	
	Class_Prepro.hv_ImagePreprocessFeatures[5] = i_class_perpro_image_range_min;
	Class_Prepro.hv_ImagePreprocessFeatures[6] = i_class_perpro_image_range_max;
	Class_Prepro.hv_ImagePreprocessFeatures[7] = i_class_prepro_seedrand;

	Class_Prepro.hv_constant_values_mean_values_normalization[0] = f_class_pre_meanvalues1;
	Class_Prepro.hv_constant_values_mean_values_normalization[1] = f_class_pre_meanvalues2;
	Class_Prepro.hv_constant_values_mean_values_normalization[2] = f_class_pre_meanvalues3;

	Class_Prepro.hv_constant_values_deviation_values_normalization[0] = f_class_pre_deviationvalues1;
	Class_Prepro.hv_constant_values_deviation_values_normalization[1] = f_class_pre_deviationvalues2;
	Class_Prepro.hv_constant_values_deviation_values_normalization[2] = f_class_pre_deviationvalues3;

	this->SendMessage(WM_CLOSE);
}
