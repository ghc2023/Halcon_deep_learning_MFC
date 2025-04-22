// MY_CLASS_EVALUE_PARA.cpp : 实现文件
//

#include "stdafx.h"
#include "MFC_HALCON_DLL.h"
#include "MY_CLASS_EVALUE_PARA.h"
#include "afxdialogex.h"


#include "Halconcpp.h"
#include "HDevThread.h"
using namespace HalconCpp;

// CMY_CLASS_EVALUE_PARA 对话框

IMPLEMENT_DYNAMIC(CMY_CLASS_EVALUE_PARA, CDialogEx)

CMY_CLASS_EVALUE_PARA::CMY_CLASS_EVALUE_PARA(CWnd* pParent /*=NULL*/)
	: CDialogEx(CMY_CLASS_EVALUE_PARA::IDD, pParent)
	, cs_ClassificationMeasures(_T("top1_error,top3_error,precision,recall,f_score,absolute_confusion_matrix,relative_confusion_matrix"))
	, i_BatchSize(10)
	, CS_display_mode_value(_T("measures,pie_charts_precision,pie_charts_recall,absolute_confusion_matrix"))
	, d_class_evalue_waitsecond(0.1)
	, i_class_evalue_MaxNumberofRandomSamples(10)
{

}

CMY_CLASS_EVALUE_PARA::~CMY_CLASS_EVALUE_PARA()
{
}

void CMY_CLASS_EVALUE_PARA::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, cs_ClassificationMeasures);
	DDX_Text(pDX, IDC_EDIT2, i_BatchSize);
	DDV_MinMaxInt(pDX, i_BatchSize, 1, 10000);
	DDX_Control(pDX, IDC_COMBO1, c_combobox_UseGPU);
	DDX_Text(pDX, IDC_EDIT3, CS_display_mode_value);
	DDX_Control(pDX, IDC_COMBO3, c_combobox_calss_evalue_SelectedHeatmapInfClassName);
	DDX_Control(pDX, IDC_COMBO2, c_combobox_calss_evalue_SelectedHeatmapGTClassName);
	DDX_Control(pDX, IDC_COMBO4, c_combobox_class_evalue_HeatmapMethod);
	DDX_Text(pDX, IDC_EDIT4, d_class_evalue_waitsecond);
	DDX_Control(pDX, IDC_COMBO5, c_combobox_class_evalue_IsShowHeatMap);
	DDX_Text(pDX, IDC_EDIT5, i_class_evalue_MaxNumberofRandomSamples);

	// 为组合框控件的列表框添加列表项“none” ;  
	c_combobox_UseGPU.AddString(_T("true"));
	// 为组合框控件的列表框添加列表项“all_channels”;   
	c_combobox_UseGPU.AddString(_T("false"));
	// 默认选择第一项   ;
	c_combobox_UseGPU.SetCurSel(0);


	// 为组合框控件的列表框添加列表项“none” ;  
	c_combobox_class_evalue_IsShowHeatMap.AddString(("false"));
	// 为组合框控件的列表框添加列表项“all_channels”;   
	c_combobox_class_evalue_IsShowHeatMap.AddString(_T("true"));
	// 默认选择第一项   ;
	c_combobox_class_evalue_IsShowHeatMap.SetCurSel(0);


	// 为组合框控件的列表框添加列表项“none” ;  
	c_combobox_class_evalue_HeatmapMethod.AddString(_T("heatmap_grad_cam"));
	// 为组合框控件的列表框添加列表项“all_channels”;   
	c_combobox_class_evalue_HeatmapMethod.AddString(_T("heatmap_confidence_based"));
	// 默认选择第一项   ;
	c_combobox_class_evalue_HeatmapMethod.SetCurSel(0);


}


BEGIN_MESSAGE_MAP(CMY_CLASS_EVALUE_PARA, CDialogEx)
	ON_CBN_SELCHANGE(IDC_COMBO1, &CMY_CLASS_EVALUE_PARA::OnCbnSelchangeCombo1)
	ON_BN_CLICKED(IDC_BUTTON_SAVE_CLASS_EVALUE_PARA, &CMY_CLASS_EVALUE_PARA::OnBnClickedButtonSaveClassEvaluePara)
	ON_CBN_SELCHANGE(IDC_COMBO4, &CMY_CLASS_EVALUE_PARA::OnCbnSelchangeCombo4)
END_MESSAGE_MAP()


// CMY_CLASS_EVALUE_PARA 消息处理程序


void CMY_CLASS_EVALUE_PARA::OnCbnSelchangeCombo1()
{
	// TODO:  在此添加控件通知处理程序代码
}


void CMY_CLASS_EVALUE_PARA::OnBnClickedButtonSaveClassEvaluePara()
{
	// TODO:  在此添加控件通知处理程序代码


}


void CMY_CLASS_EVALUE_PARA::OnCbnSelchangeCombo4()
{
	// TODO:  在此添加控件通知处理程序代码
}
