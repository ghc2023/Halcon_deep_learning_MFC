// MY_CLASS_TRAIN_PARA.cpp : 实现文件
//

#include "stdafx.h"
#include "MFC_HALCON_DLL.h"
#include "MY_CLASS_TRAIN_PARA.h"
#include "afxdialogex.h"
#include "Halcon_public.h"
#include "Halconcpp.h"
#include "HDevThread.h"
using namespace HalconCpp;
// CMY_CLASS_TRAIN_PARA 对话框

//分类-训练参数;
extern CLASS_Train_S Class_Train;

// extern HTuple  hv_Class_Train_NumEpochs;
// extern HTuple  hv_Class_Train_BatchSize;
// extern HTuple  hv_Class_Train_Momentum;
// extern HTuple  hv_Class_Train_WeightPrior;
// 
// extern HTuple  hv_Class_Train_InitialLearningRate;
// extern HTuple  hv_Class_Train_Augmenttation_Percentage;
// 
// extern HTuple  hv_Class_Train_ChangeLearningRateEpochs;
// extern HTuple  hv_Class_Train_ChangeLearningRate;
// extern HTuple  hv_Class_Train_EnableDiasplay;
// extern HTuple  hv_Class_Train_RandomSeed;
// 
// extern HTuple  hv_Class_Train_SelectePercentaheTrainSamples;
// extern HTuple  hv_Class_Train_update_images_interval_epochs;
// extern HTuple  hv_Class_Train_change_plot_interval_seconds;
// extern HTuple  hv_Class_Train_update_interval_seconds;
// extern HTuple  hv_Class_Train_EvaluationIntervalEpochs;
// 
// extern HTuple  hv_Class_Train_BestModelBaseName;
// extern HTuple  hv_Class_Train_FinalModelBaseName;
// extern HTuple  hv_Class_Train_Augmentation_Method;
// extern HTuple  hv_Class_Train_Augmentation_Value;

IMPLEMENT_DYNAMIC(CMY_CLASS_TRAIN_PARA, CDialogEx)
CString g_strCBText_Method ;
CMY_CLASS_TRAIN_PARA::CMY_CLASS_TRAIN_PARA(CWnd* pParent /*=NULL*/)
	: CDialogEx(CMY_CLASS_TRAIN_PARA::IDD, pParent)
	, i_class_train_BatchSize(64)
	, f_class_train_Momentum(0.9)
	, i_class_train_NumEpochs(20)
	, f_class_train_InitialLearningRate(0.001)
	, cs_class_train_ChangeLearningRateEpochs(_T("4,8,12"))
	, f_class_train_WeightPrior(0.0005)
	, cs_ChangeLearningRateValues(_T("0.1,0.01,0.001"))
	, i_augmentation_percentage(50)
	, i_SelectedPercentageTrainSamples(20)
	, i_update_images_interval_epochs(4)//几个周期更新一次图像;
	, i_change_plot_interval_seconds(10)//改变画评估信息图更新 时间间隔10秒;
	, i_update_interval_seconds(2)//评估信息2秒钟更新一次
	, i_EvaluationIntervalEpochs(1)//几个周期评估一次;
	, cs_BestModelBaseName(_T("/best_dl_model_classification"))
	, cs_FinalModelBaseName(_T("/final_dl_model_classification"))
	, i_class_train_RandomSeed(42)
	, cs_Class_Train_Augmentation_Value(_T("rc"))
{


}

CMY_CLASS_TRAIN_PARA::~CMY_CLASS_TRAIN_PARA()
{
}

void CMY_CLASS_TRAIN_PARA::DoDataExchange(CDataExchange* pDX)
{
	//UpdateData(TRUE);
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT_BatchSize, i_class_train_BatchSize);
	DDX_Text(pDX, IDC_EDIT_Momentum, f_class_train_Momentum);
	DDX_Text(pDX, IDC_EDIT_NumEpochs, i_class_train_NumEpochs);
	DDX_Text(pDX, IDC_EDIT_InitialLearningRate, f_class_train_InitialLearningRate);
	DDX_Text(pDX, IDC_EDIT_InitialLearningRate2, cs_class_train_ChangeLearningRateEpochs);
	DDX_Text(pDX, IDC_EDIT_Momentum2, f_class_train_WeightPrior);
	DDX_Text(pDX, IDC_EDIT_ChangeLearningRateValues, cs_ChangeLearningRateValues);
	DDX_Text(pDX, IDC_EDIT_Augmentation_Percentage, i_augmentation_percentage);



	DDX_Control(pDX, IDC_COMBO_EnableDisplay, m_combobox_class_train_EnableDisplay);
	// 为组合框控件的列表框添加列表项“none” ;  
	m_combobox_class_train_EnableDisplay.AddString(_T("true"));
	// 为组合框控件的列表框添加列表项“all_channels”;   
	m_combobox_class_train_EnableDisplay.AddString(_T("false"));
	// 默认选择第一项   ;
	m_combobox_class_train_EnableDisplay.SetCurSel(0);

	DDX_Text(pDX, IDC_EDIT_SelectedPercentageTrainSamples, i_SelectedPercentageTrainSamples);
	DDX_Text(pDX, IDC_EDIT_update_images_interval_epochs, i_update_images_interval_epochs);
	DDX_Text(pDX, IDC_EDIT_change_plot_interval_seconds, i_change_plot_interval_seconds);
	DDX_Text(pDX, IDC_EDIT_update_images_interval_epochs2, i_update_interval_seconds);
	DDX_Text(pDX, IDC_EDIT_update_images_interval_epochs3, i_EvaluationIntervalEpochs);
	DDX_Text(pDX, IDC_EDIT_update_images_interval_epochs4, cs_BestModelBaseName);
	DDX_Text(pDX, IDC_EDIT_update_images_interval_epochs5, cs_FinalModelBaseName);
	DDX_Text(pDX, IDC_EDIT1, i_class_train_RandomSeed);
	DDX_Control(pDX, IDC_COMBO_Augmentation_Method, c_combocox_class_train_Augmentation_Method);
	//DDX_Control(pDX, IDC_COMBO5, c_combobox_class_train_Augmentation_Value);
	DDX_Text(pDX, IDC_EDIT_Augmentation_Value, cs_Class_Train_Augmentation_Value);


	// 默认选择第一项   ;
	if (g_strCBText_Method=="")
	{
		// 为组合框控件的列表框添加列表项“none” ;  
		c_combocox_class_train_Augmentation_Method.AddString(_T("mirror"));
		// 为组合框控件的列表框添加列表项“all_channels”;   
		c_combocox_class_train_Augmentation_Method.AddString(_T("rotate"));
		c_combocox_class_train_Augmentation_Method.AddString(_T("brightness_variation"));
		c_combocox_class_train_Augmentation_Method.AddString(_T("brightness_variation_spot"));
		c_combocox_class_train_Augmentation_Method.AddString(_T("crop_percentage"));
		c_combocox_class_train_Augmentation_Method.AddString(_T("crop_pixel"));
		c_combocox_class_train_Augmentation_Method.AddString(_T("rotate_range"));

		c_combocox_class_train_Augmentation_Method.SetCurSel(0);
		CString strCBText;
		int nIndex = c_combocox_class_train_Augmentation_Method.GetCurSel();
		c_combocox_class_train_Augmentation_Method.GetLBText(nIndex, g_strCBText_Method);
		if (g_strCBText_Method == "mirror")
		{
			GetDlgItem(IDC_EDIT_Augmentation_Value)->SetWindowText("rc");
			//cs_Class_Train_Augmentation_Value = "rc";
		}
		else if (g_strCBText_Method == "rotate")
		{
			GetDlgItem(IDC_EDIT_Augmentation_Value)->SetWindowText("90");
			//cs_Class_Train_Augmentation_Value = "90";
		}
		else if (g_strCBText_Method == "brightness_variation")
		{
			GetDlgItem(IDC_EDIT_Augmentation_Value)->SetWindowText("20");
			//cs_Class_Train_Augmentation_Value = "20";
		}
		else if (g_strCBText_Method == "brightness_variation_spot")
		{
			GetDlgItem(IDC_EDIT_Augmentation_Value)->SetWindowText("30");
			//cs_Class_Train_Augmentation_Value = "30";
		}
		else if (g_strCBText_Method == "crop_percentage")
		{
			GetDlgItem(IDC_EDIT_Augmentation_Value)->SetWindowText("50");
			//cs_Class_Train_Augmentation_Value = "50";
		}
		else if (g_strCBText_Method == "crop_pixel")
		{
			GetDlgItem(IDC_EDIT_Augmentation_Value)->SetWindowText("300");
			//cs_Class_Train_Augmentation_Value = "300";
		}
		else if (g_strCBText_Method == "rotate_range")
		{
			GetDlgItem(IDC_EDIT_Augmentation_Value)->SetWindowText("32");
			//cs_Class_Train_Augmentation_Value = "32";
		}
	}
	



	//UpdateData(FALSE);
}

BEGIN_MESSAGE_MAP(CMY_CLASS_TRAIN_PARA, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON_SAVE_CLASS_TRAIN_PARA, &CMY_CLASS_TRAIN_PARA::OnBnClickedButtonSaveClassTrainPara)
	ON_CBN_SELCHANGE(IDC_COMBO_Augmentation_Method, &CMY_CLASS_TRAIN_PARA::OnCbnSelchangeComboAugmentationMethod)
END_MESSAGE_MAP()

// CMY_CLASS_TRAIN_PARA 消息处理程序;

//字符串（中间逗号隔开，如“4，8，12”）转 数字 [4,8,12];
int class_csstring_to_int(CString cs_class_train_ChangeLearningRateEpochs,int i_CLREpochs[],int &i_num)
{
	if (cs_class_train_ChangeLearningRateEpochs.GetLength()>0)
	{
		char* strChangeLearningRateEpochs = NULL;
		char c_1 = 0;
		int  cs_lenght = cs_class_train_ChangeLearningRateEpochs.GetLength();
		strChangeLearningRateEpochs = cs_class_train_ChangeLearningRateEpochs.GetBuffer(cs_class_train_ChangeLearningRateEpochs.GetLength());

		int i_sing_num[100] = { 0 };
		int sing_index = 0;
		int i_doudian = 0; 
		int i_other = 0;
		int i_resultnum = 0;
		for (int i = 0; i < cs_lenght;i++)
		{
			char c_1 = strChangeLearningRateEpochs[i];
			if (c_1 >= 48 && c_1 <= 57)
			{
				i_sing_num[sing_index] = int(c_1) - 48;
				sing_index++;
				i_other = 0;
			}
			else
			{
				i_other = 1;
				if (sing_index>0)
				{
					i_resultnum = 0;
					
					for (int j = 0; j <sing_index; j++)
					{
						i_resultnum += i_sing_num[j] * pow(10, sing_index - j-1);
						i_sing_num[j] = 0;
					}
					i_CLREpochs[i_doudian] = i_resultnum;
					i_doudian++;
					sing_index = 0;
				}
				
			}
		}
		if (sing_index >0 && i_other==0)
		{
			if (sing_index > 0)
			{
				i_resultnum = 0;
				
				for (int j = 0; j < sing_index; j++)
				{
					i_resultnum += i_sing_num[j] * pow(10, sing_index - j - 1);
					i_sing_num[j] = 0;
				}
				i_CLREpochs[i_doudian] = i_resultnum;
				i_doudian++;
				sing_index = 0;
			}
		}
		i_num = i_doudian;
	}
	else
	{
		//i_CLREpochs = NULL; 
		i_num = 0;
	}
	return 1;
}

//字符串（中间逗号隔开，如“4，8，12”）转 数字 [4,8,12];
int class_csstring_to_double(CString cs_class_train_ChangeLearningRateEpochs, double i_CLREpochs[], int &i_num)
{


	if (cs_class_train_ChangeLearningRateEpochs.GetLength() > 0)
	{
		char* strChangeLearningRateEpochs = NULL;
		char c_1 = 0;
		int  cs_lenght = cs_class_train_ChangeLearningRateEpochs.GetLength();
		strChangeLearningRateEpochs = cs_class_train_ChangeLearningRateEpochs.GetBuffer(cs_class_train_ChangeLearningRateEpochs.GetLength());

		int i_sing_num[100] = { 0 };
		int sing_index = 0;
		int i_doudian = 0;
		int i_other = 0;
		double i_resultnum = 0;
		for (int i = 0; i < cs_lenght; i++)
		{
			char c_1 = strChangeLearningRateEpochs[i];

			if ((c_1 >= 48 && c_1 <= 57) || c_1 == '.')
			{
				i_sing_num[sing_index] = int(c_1) - 48;
				sing_index++;
				i_other = 0;
			}
			else
			{
				i_other = 1;
				if (sing_index > 0 && i_sing_num[0] == 0 && i_sing_num[1]== int('.')- 48)
				{
					i_resultnum = 0;

					for (int j = sing_index-1; j >=2; j--)
					{
						i_resultnum += (double)i_sing_num[j] / pow(10,(j-1));
						i_sing_num[j] = 0;
					}
					i_CLREpochs[i_doudian] = i_resultnum;
					i_doudian++;
					sing_index = 0;
				}

			}
		}
		if (sing_index > 0 && i_other == 0)
		{
			if (sing_index > 0 && i_sing_num[0] == 0 && i_sing_num[1] == int('.') - 48)
			{
				i_resultnum = 0;
				for (int j = sing_index - 1; j >= 2; j--)
				{
					i_resultnum += (double)i_sing_num[j] / pow(10, (j - 1));
					i_sing_num[j] = 0;
				}
				i_CLREpochs[i_doudian] = i_resultnum;
				i_doudian++;
				sing_index = 0;
			}
		}
		i_num = i_doudian;
	}
	else
	{
		//i_CLREpochs = NULL; 
		i_num = 0;
	}
	return 1;
}

//保存训练参数;
void CMY_CLASS_TRAIN_PARA::OnBnClickedButtonSaveClassTrainPara()
{

	// TODO:  在此添加控件通知处理程序代码;
	UpdateData(TRUE);
	int i_CLREpochs[20] = {0};
	int i_num = 0;
	class_csstring_to_int(cs_class_train_ChangeLearningRateEpochs, i_CLREpochs, i_num);
	double ChangeLearningRate[20] = { 0 };
	int i_c_num = 0;
	class_csstring_to_double(cs_ChangeLearningRateValues, ChangeLearningRate, i_c_num);
	int  nIndex = 0;
	//分类-训练参数;
	Class_Train.hv_NumEpochs = i_class_train_NumEpochs;
	Class_Train.hv_BatchSize = i_class_train_BatchSize;
	Class_Train.hv_Momentum = f_class_train_Momentum;
	Class_Train.hv_WeightPrior = f_class_train_WeightPrior;
	Class_Train.hv_InitialLearningRate = f_class_train_InitialLearningRate;
	Class_Train.hv_Augmenttation_Percentage = i_augmentation_percentage;
	if (i_num == i_c_num&&i_c_num>0)
	{
		for (int i = 0; i <i_c_num; i++)
		{
			Class_Train.hv_ChangeLearningRateEpochs[i] = i_CLREpochs[i];
			Class_Train.hv_ChangeLearningRate[i] = ChangeLearningRate[i];
		}
	}
	
	CString strCBText;

	nIndex = m_combobox_class_train_EnableDisplay.GetCurSel();

	m_combobox_class_train_EnableDisplay.GetLBText(nIndex, strCBText);

	Class_Train.hv_EnableDiasplay = strCBText.GetBuffer(strCBText.GetLength());

	Class_Train.hv_RandomSeed = i_class_train_RandomSeed;

	Class_Train.hv_SelectePercentaheTrainSamples = i_SelectedPercentageTrainSamples;

	Class_Train.hv_update_images_interval_epochs = i_update_images_interval_epochs;

	Class_Train.hv_change_plot_interval_seconds = i_change_plot_interval_seconds;

	Class_Train.hv_update_interval_seconds = i_update_interval_seconds;

	Class_Train.hv_EvaluationIntervalEpochs = i_EvaluationIntervalEpochs;


	Class_Train.hv_BestModelBaseName = cs_BestModelBaseName.GetBuffer(cs_BestModelBaseName.GetLength());
	Class_Train.hv_FinalModelBaseName = cs_FinalModelBaseName.GetBuffer(cs_FinalModelBaseName.GetLength());
	Class_Train.hv_Augmentation_Method = g_strCBText_Method.GetBuffer(g_strCBText_Method.GetLength());

	CString g_strCBText_Value;
	GetDlgItem(IDC_EDIT_Augmentation_Value)->GetWindowText(g_strCBText_Value);
	Class_Train.hv_Augmentation_Value = g_strCBText_Value.GetBuffer(g_strCBText_Value.GetLength());
	this->SendMessage(WM_CLOSE);


}


void CMY_CLASS_TRAIN_PARA::OnCbnSelchangeComboAugmentationMethod()
{
	// TODO:  在此添加控件通知处理程序代码;

	//UpdateData(TRUE);
	int nIndex = c_combocox_class_train_Augmentation_Method.GetCurSel();
	c_combocox_class_train_Augmentation_Method.GetLBText(nIndex, g_strCBText_Method);
	if (g_strCBText_Method == "mirror")
	{
		GetDlgItem(IDC_EDIT_Augmentation_Value)->SetWindowText("rc");
		cs_Class_Train_Augmentation_Value = "rc";
	}
	else if (g_strCBText_Method == "rotate")
	{
		GetDlgItem(IDC_EDIT_Augmentation_Value)->SetWindowText("90");
		cs_Class_Train_Augmentation_Value = "90";
	}
	else if (g_strCBText_Method == "brightness_variation")
	{
		GetDlgItem(IDC_EDIT_Augmentation_Value)->SetWindowText("20");
		cs_Class_Train_Augmentation_Value = "20";
	}
	else if (g_strCBText_Method == "brightness_variation_spot")
	{
		GetDlgItem(IDC_EDIT_Augmentation_Value)->SetWindowText("30");
		cs_Class_Train_Augmentation_Value = "30";
	}
	else if (g_strCBText_Method == "crop_percentage")
	{
		GetDlgItem(IDC_EDIT_Augmentation_Value)->SetWindowText("50");
		cs_Class_Train_Augmentation_Value = "50";
	}
	else if (g_strCBText_Method == "crop_pixel")
	{
		GetDlgItem(IDC_EDIT_Augmentation_Value)->SetWindowText("300");
		cs_Class_Train_Augmentation_Value = "300";
	}
	else if (g_strCBText_Method == "rotate_range")
	{
		GetDlgItem(IDC_EDIT_Augmentation_Value)->SetWindowText("32");
		cs_Class_Train_Augmentation_Value = "32";
	}
	//UpdateData(FALSE);
}

