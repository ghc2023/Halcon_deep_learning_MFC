// MY_CLASS_EVALUE_PARA.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "MFC_HALCON_DLL.h"
#include "MY_CLASS_EVALUE_PARA.h"
#include "afxdialogex.h"


#include "Halconcpp.h"
#include "HDevThread.h"
using namespace HalconCpp;

// CMY_CLASS_EVALUE_PARA �Ի���

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

	// Ϊ��Ͽ�ؼ����б������б��none�� ;  
	c_combobox_UseGPU.AddString(_T("true"));
	// Ϊ��Ͽ�ؼ����б������б��all_channels��;   
	c_combobox_UseGPU.AddString(_T("false"));
	// Ĭ��ѡ���һ��   ;
	c_combobox_UseGPU.SetCurSel(0);


	// Ϊ��Ͽ�ؼ����б������б��none�� ;  
	c_combobox_class_evalue_IsShowHeatMap.AddString(("false"));
	// Ϊ��Ͽ�ؼ����б������б��all_channels��;   
	c_combobox_class_evalue_IsShowHeatMap.AddString(_T("true"));
	// Ĭ��ѡ���һ��   ;
	c_combobox_class_evalue_IsShowHeatMap.SetCurSel(0);


	// Ϊ��Ͽ�ؼ����б������б��none�� ;  
	c_combobox_class_evalue_HeatmapMethod.AddString(_T("heatmap_grad_cam"));
	// Ϊ��Ͽ�ؼ����б������б��all_channels��;   
	c_combobox_class_evalue_HeatmapMethod.AddString(_T("heatmap_confidence_based"));
	// Ĭ��ѡ���һ��   ;
	c_combobox_class_evalue_HeatmapMethod.SetCurSel(0);


}


BEGIN_MESSAGE_MAP(CMY_CLASS_EVALUE_PARA, CDialogEx)
	ON_CBN_SELCHANGE(IDC_COMBO1, &CMY_CLASS_EVALUE_PARA::OnCbnSelchangeCombo1)
	ON_BN_CLICKED(IDC_BUTTON_SAVE_CLASS_EVALUE_PARA, &CMY_CLASS_EVALUE_PARA::OnBnClickedButtonSaveClassEvaluePara)
	ON_CBN_SELCHANGE(IDC_COMBO4, &CMY_CLASS_EVALUE_PARA::OnCbnSelchangeCombo4)
END_MESSAGE_MAP()


// CMY_CLASS_EVALUE_PARA ��Ϣ�������


void CMY_CLASS_EVALUE_PARA::OnCbnSelchangeCombo1()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
}


void CMY_CLASS_EVALUE_PARA::OnBnClickedButtonSaveClassEvaluePara()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������


}


void CMY_CLASS_EVALUE_PARA::OnCbnSelchangeCombo4()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
}
