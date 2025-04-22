
// MFC_HALCON_DLLDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "MFC_HALCON_DLL.h"
#include "MFC_HALCON_DLLDlg.h"
#include "afxdialogex.h"



#include <tchar.h>   
#include <string.h>
#ifdef _DEBUG
#define new DEBUG_NEW
#endif
#include "Halcon_public.h"
#include "dl_dll_interface.h"
#include "Halconcpp.h"
#include "HDevThread.h"
#include <string>
using namespace std;
using namespace HalconCpp;

TCHAR szFilePathdata[MAX_PATH + 1];

TCHAR szFilePath[MAX_PATH + 1];

char g_datapath[256] = { 0 };
char g_savepath[256] = { 0 };

static CWinThread* m_pWinThreadImage;
int  i_split_number = 0;
int  Thread_Running_Type = 0;

//GPU
HTuple hv_UseGPU;
//窗口;
HTuple  hv_WindowHandleimage, hv_WindowHandlechild;
//读图;
HTuple hv_label;
HTuple hv_SubFile;
HTuple hv_ImageBaseFolder;//有选择性的类子文件;
HTuple hv_RawImageFolder;//完成路径，路径下所有文件为训练文件;
HTuple hv_ModelFileName;
HTuple hv_AllDataSaveDir;


//分类-预处理参数;
CLASS_PREPRO_S Class_Prepro;
//分类-训练参数;
CLASS_Train_S  Class_Train;


//HTuple hv_LabelSource;//类名标签不同方式//
// 	//* LabelSource用于读取数据集。;
// 	//'last_folder'最后文件夹名为类名标签;
// 	//'file_name'文件名最为类名标签;
// 	//'file_name_remove_index'文件名除去后面的序列之后最为类名标签;

// HTuple hv_Class_DLDataset;
// HTuple  hv_Class_Propre_TrainingValidationPercent;
// HTuple  hv_Class_Propre_ImagePreprocessFeatures;
// HTuple  hv_Class_Propre_ImageWidth;
// HTuple  hv_Class_Propre_ImageHeight;
// HTuple  hv_Class_Propre_ImageChannels;
// HTuple  hv_Class_Propre_Domainhandling;
// HTuple  hv_Class_Propre_NormalizationType;
// HTuple  hv_Class_Propre_DLDatasetFileName;//图像字典路径;
// HTuple  hv_Class_Propre_DataDirectory;//图像字典;
// HTuple  hv_Class_Propre_PreprocessParamFile;//预处理参数字典路径;
// HTuple  hv_Class_Propre_DLPreprocessParam;//预处理参数字典;
// HTuple  hv_Class_Propre_Is_overwrite_files;
// HTuple  hv_Class_Propre_LabelSource;
// HTuple  hv_Class_Propre_constant_values_mean_values_normalization;
// HTuple  hv_Class_Propre_constant_values_deviation_values_normalization;

// 分类-训练参数;
// HTuple  hv_Class_Train_NumEpochs;
// HTuple  hv_Class_Train_BatchSize;
// HTuple  hv_Class_Train_Momentum;
// HTuple  hv_Class_Train_WeightPrior;
// HTuple  hv_Class_Train_InitialLearningRate;
// HTuple  hv_Class_Train_Augmenttation_Percentage;
// HTuple  hv_Class_Train_ChangeLearningRateEpochs;
// HTuple  hv_Class_Train_ChangeLearningRate;
// HTuple  hv_Class_Train_EnableDiasplay;
// HTuple  hv_Class_Train_RandomSeed;
// HTuple  hv_Class_Train_SelectePercentaheTrainSamples;
// HTuple  hv_Class_Train_update_images_interval_epochs;
// HTuple  hv_Class_Train_change_plot_interval_seconds;
// HTuple  hv_Class_Train_update_interval_seconds;
// HTuple  hv_Class_Train_EvaluationIntervalEpochs;
// HTuple  hv_Class_Train_BestModelBaseName;
// HTuple  hv_Class_Train_FinalModelBaseName;
// HTuple  hv_Class_Train_Augmentation_Method;
// HTuple  hv_Class_Train_Augmentation_Value;

// 用于应用程序“关于”菜单项的 CAboutDlg 对话框;
class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 对话框数据;
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持;

// 实现;
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CMFC_HALCON_DLLDlg 对话框



CMFC_HALCON_DLLDlg::CMFC_HALCON_DLLDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CMFC_HALCON_DLLDlg::IDD, pParent)
	, CS_data_path(_T("C:\\Users\\Public\\Documents\\MVTec\\HALCON-19.11-Progress\\examples\\images\\food"))
	, CS_save_path(_T("E:/dl/dl-class/classify_fruits_data"))
	, CS_json_path(_T(""))
	, cs_class_pre_calssnamefile(_T(""))//apple_braeburn,apple_golden_delicious,apple_topaz,peach,pear;
	, cs_class_modelfilename(_T("C:/Program Files/MVTec/HALCON-19.11-Progress/dl/pretrained_dl_classifier_compact.hdl"))
	, cs_select_class_modelname(_T("所选模型：pretrained_dl_classifier_compact.hdl"))
	, cs_select_jsonname(_T("所选json文件："))
	, cs_class_prepro_DLDatasetFileName(_T("DLDatasetDirect:"))
	, cs_class_prepro_PreprocessDirect(_T("PreprocessDirect:"))
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMFC_HALCON_DLLDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT_DATA_PATH, CS_data_path);
	DDX_Text(pDX, IDC_EDIT_SAVE_PATH, CS_save_path);
	DDX_Control(pDX, IDC_TAB_CLASS, m_tab_class);
	DDX_Text(pDX, IDC_EDIT1, CS_json_path);
	HTuple  hv_CudaLoaded, hv_CuDNNLoaded, hv_CuBlasLoaded;

	GetSystem("cuda_loaded", &hv_CudaLoaded);
	GetSystem("cudnn_loaded", &hv_CuDNNLoaded);
	GetSystem("cublas_loaded", &hv_CuBlasLoaded);
	if (0 != (HTuple(HTuple(HTuple(int(hv_CudaLoaded == HTuple("true"))).TupleAnd(int(hv_CuDNNLoaded == HTuple("true")))).TupleAnd(int(hv_CuBlasLoaded == HTuple("true")))).TupleNot()))
	{
		hv_UseGPU = 0;
		GetDlgItem(IDC_STATIC_HALCON_GPU)->SetWindowText(_T("HALCON_GPU： 无法使用！"));
	}
	else
	{
		hv_UseGPU = 1;
		GetDlgItem(IDC_STATIC_HALCON_GPU)->SetWindowText(_T("HALCON_GPU： 可以使用！"));
	}
	// 	DDX_Control(pDX, IDC_CHECK_ALL_FILE, m_check_all_file);
	// 	DDX_Control(pDX, IDC_CHECK_SPECIFIED_FILE, m_check_spec_file);
	DDX_Control(pDX, IDC_RADIO_ALL_FILE, m_radio_all_file);
	DDX_Text(pDX, IDC_EDIT_CLASS_FILE, cs_class_pre_calssnamefile);

	// 	if (((CButton *)GetDlgItem(IDC_RADIO_SPECIFIED_FILE))->GetCheck())
	// 	{
	// 		cs_class_pre_calssnamefile = "apple_braeburn,apple_golden_delicious,apple_topaz,peach,pear";
	// 		UpdateData(FALSE);
	// 	}
	DDX_Text(pDX, IDC_EDIT_MODEL_SAVE, cs_class_modelfilename);
	DDX_Text(pDX, IDC_STATIC_SELECT_MODEL_NAME, cs_select_class_modelname);
	DDX_Text(pDX, IDC_STATIC_SELECT_JSON, cs_select_jsonname);
	DDX_Text(pDX, IDC_STATIC_DLDatasetFileName, cs_class_prepro_DLDatasetFileName);
	DDX_Text(pDX, IDC_STATIC_PreprocessDirect, cs_class_prepro_PreprocessDirect);


}

BEGIN_MESSAGE_MAP(CMFC_HALCON_DLLDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, &CMFC_HALCON_DLLDlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON_OPEN_SAVE_PATH, &CMFC_HALCON_DLLDlg::OnBnClickedButtonOpenSavePath)
	ON_BN_CLICKED(IDC_BUTTON_Preprocess, &CMFC_HALCON_DLLDlg::OnBnClickedButtonPreprocess)
	ON_NOTIFY(TCN_SELCHANGE, IDC_TAB_CLASS, &CMFC_HALCON_DLLDlg::OnTcnSelchangeTabClass)
	ON_BN_CLICKED(IDC_BUTTON_SHOW_PREPROCESS, &CMFC_HALCON_DLLDlg::OnBnClickedButtonShowPreprocess)
	ON_BN_CLICKED(IDC_RADIO_SPECIFIED_FILE, &CMFC_HALCON_DLLDlg::OnBnClickedRadioSpecifiedFile)
	ON_BN_CLICKED(IDC_BUTTON_MODEL_SAVE, &CMFC_HALCON_DLLDlg::OnBnClickedButtonModelSave)
	ON_BN_CLICKED(IDC_RADIO2, &CMFC_HALCON_DLLDlg::OnBnClickedRadio2)
	
	ON_BN_CLICKED(IDC_BUTTON_OPEN_JSON, &CMFC_HALCON_DLLDlg::OnBnClickedButtonOpenJson)
	ON_EN_CHANGE(IDC_EDIT1, &CMFC_HALCON_DLLDlg::OnEnChangeEdit1)
	ON_EN_CHANGE(IDC_EDIT_MODEL_SAVE, &CMFC_HALCON_DLLDlg::OnEnChangeEditModelSave)
	ON_EN_CHANGE(IDC_EDIT_CLASS_FILE, &CMFC_HALCON_DLLDlg::OnEnChangeEditClassFile)
	ON_BN_CLICKED(IDC_BUTTON_TRAIN, &CMFC_HALCON_DLLDlg::OnBnClickedButtonTrain)
END_MESSAGE_MAP()

//ON_EN_CHANGE(IDC_EDIT_SAVE_PATH, &CMFC_HALCON_DLLDlg::OnEnChangeEditSavePath)
// CMFC_HALCON_DLLDlg 消息处理程序

BOOL CMFC_HALCON_DLLDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 将“关于...”菜单项添加到系统菜单中。

	// IDM_ABOUTBOX 必须在系统命令范围内。
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// 设置此对话框的图标。  当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	m_tab_class.InsertItem(0, "  分类  ");
	m_tab_class.InsertItem(1, "  检测  ");
	m_tab_class.InsertItem(2, "  检测带方向  ");
	m_tab_class.InsertItem(3, " 语义分割 ");
	m_tab_class.InsertItem(4, " 异常检测 ");

	m_page_class.Create(MAKEINTRESOURCE(IDD_DIALOG_CLASS),&m_tab_class);

	m_page_detect.Create(MAKEINTRESOURCE(IDD_DIALOG_DETECT), &m_tab_class);

	m_page_detect_orienta.Create(MAKEINTRESOURCE(IDD_DIALOG_DETECT_ORIENTA), &m_tab_class);

	m_page_segment.Create(MAKEINTRESOURCE(IDD_DIALOG_SEGMENT), &m_tab_class);

	m_page_anomaly.Create(MAKEINTRESOURCE(IDD_DIALOG_ANOMALY), &m_tab_class);

	CRect cr;
	m_tab_class.GetClientRect(cr);
	cr.top += 24;
	cr.left += 4;
	cr.right -= 4;
	cr.bottom -= 4;

	m_page_class.MoveWindow(cr);
	m_page_detect.MoveWindow(cr);
	m_page_segment.MoveWindow(cr);
	m_page_anomaly.MoveWindow(cr);

	m_page_detect_orienta.MoveWindow(cr);

	m_page_class.ShowWindow(SW_SHOW);

// 	m_check_all_file.SetCheck(1);
// 	m_check_spec_file.SetCheck(0);
	((CButton*)GetDlgItem(IDC_RADIO_SPECIFIED_FILE))->SetCheck(BST_CHECKED);
	if (((CButton *)GetDlgItem(IDC_RADIO_SPECIFIED_FILE))->GetCheck() && cs_class_pre_calssnamefile == "")//
	{
		cs_class_pre_calssnamefile = "apple_braeburn,apple_golden_delicious,apple_topaz,peach,pear";

	}
	((CButton*)GetDlgItem(IDC_RADIO1))->SetCheck(BST_CHECKED);

	ShowWindow(SW_NORMAL);

	//hv_Class_Propre_LabelSource = "last_folder";
	// TODO:  在此添加额外的初始化代码
	UpdateData(FALSE);



	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}


void MyHalconExceptionHandler(const HException& except)
{
	throw except;
}


void CMFC_HALCON_DLLDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// 如果向对话框添加最小化按钮，则需要下面的代码;
//  来绘制该图标。  对于使用文档/视图模型的 MFC 应用程序，;
//  这将由框架自动完成。;

void CMFC_HALCON_DLLDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作区矩形中居中
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 绘制图标
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标;
//显示。;

HCURSOR CMFC_HALCON_DLLDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

//打开训练数据路径;
void CMFC_HALCON_DLLDlg::OnBnClickedButton1()//打开训练数据路径
{
	// TODO:  在此添加控件通知处理程序代码;

	UpdateData(TRUE);
// 	TCHAR szFilePath_t[MAX_PATH + 1];
// 
// 	if (szFilePathdata[0] == 0)
// 	{
// 		GetModuleFileName(NULL, szFilePathdata, MAX_PATH);
// 		(_tcsrchr(szFilePathdata, _T('\\')))[1] = 0;//删除文件名，只获得路径
// 	}
// 
// 	CString defaultDir = szFilePathdata;   //默认打开的文件路径;  
// 	CString fileName = _T("");         //默认打开的文件名  ;
// 	CString filter = _T("图像(*.jpg;*.bmp;*.hobj)|*.jpg;*.bmp;*.hobj||");   //文件过虑的类型 ; 视频(*.mp4;)|*.mp4|
// 	CFileDialog openFileDlg(TRUE, defaultDir, fileName, OFN_HIDEREADONLY | OFN_READONLY, filter, NULL);//  
// 	openFileDlg.GetOFN().lpstrInitialDir = defaultDir;
// 	INT_PTR result = openFileDlg.DoModal();
// 	CS_data_path = defaultDir;
// 	if (result == IDOK)
// 	{
// 		CS_data_path = openFileDlg.GetPathName();
// 		for (int i = 0; i < CS_data_path.GetLength(); i++)
// 		{
// 			szFilePath_t[i] = CS_data_path[i];
// 		}
// 		(_tcsrchr(szFilePath_t, _T('\\')))[1] = 0;//删除文件名，只获得路径；
// 
// 		for (int i = 0; i < MAX_PATH + 1; i++)
// 		{
// 			if (szFilePath_t[i] != 0)
// 			{
// 				szFilePathdata[i] = szFilePath_t[i];
// 			}
// 		}
// 
// 		(_tcsrchr(szFilePathdata, _T('\\')))[1] = 0;//删除文件名，只获得路径;
// 		strcpy(g_datapath, szFilePathdata);
// 		CS_data_path = g_datapath;
// 	}
// 	else
// 	{
// 		strcpy(g_datapath, CS_data_path.GetBuffer());
// 		//DWORD le0 = CS_data_path.GetLength() * sizeof(TCHAR);
// 	}



	//打开路径
	BROWSEINFO bi;
	char Buffer[MAX_PATH] = { 0 };
	//初始化入口参数bi开始
	bi.hwndOwner = NULL;
	bi.pidlRoot = NULL;
	bi.pszDisplayName = Buffer;//此参数如为NULL则不能显示对话框
	bi.lpszTitle = "打开路径";
	bi.ulFlags = BIF_EDITBOX;//包括文件
	bi.lpfn = NULL;
	bi.iImage = IDR_MAINFRAME;

	LPITEMIDLIST pIDList = SHBrowseForFolder(&bi);//调用显示选择对话框
	if (pIDList)
	{
		SHGetPathFromIDList(pIDList, Buffer);//取得文件夹路径到Buffer里
		//SetDlgItemText(IDC_EDIT1, Buffer);
	}
	//hv_ImageBaseFolder = Buffer;// 训练图像数据路径
	CS_data_path = Buffer;
	UpdateData(FALSE);



}

void CMFC_HALCON_DLLDlg::OnBnClickedButtonOpenSavePath()
{
	// TODO:  在此添加控件通知处理程序代码;


	UpdateData(TRUE);
	TCHAR szFilePath_t[MAX_PATH + 1];
	
	if (szFilePath[0] == 0)
	{
		GetModuleFileName(NULL, szFilePath, MAX_PATH);
		(_tcsrchr(szFilePath, _T('\\')))[1] = 0;//删除文件名，只获得路径
	}

	CString defaultDir = szFilePath;   //默认打开的文件路径;  
	CString fileName = _T("");         //默认打开的文件名  ;
	CString filter = _T("图像(*.jpg;*.bmp;*.hobj)|*.jpg;*.bmp;*.hobj||");   //文件过虑的类型 ; 视频(*.mp4;)|*.mp4|
	CFileDialog openFileDlg(TRUE, defaultDir, fileName, OFN_HIDEREADONLY | OFN_READONLY, filter, NULL);//  
	openFileDlg.GetOFN().lpstrInitialDir = defaultDir;
	INT_PTR result = openFileDlg.DoModal();
	CS_save_path = defaultDir;
	if (result == IDOK)
	{
		CS_save_path = openFileDlg.GetPathName();
		for (int i = 0; i < CS_save_path.GetLength(); i++)
		{
			szFilePath_t[i] = CS_save_path[i];
		}
		(_tcsrchr(szFilePath_t, _T('\\')))[1] = 0;//删除文件名，只获得路径；

		for (int i = 0; i < MAX_PATH + 1; i++)
		{
			if (szFilePath_t[i] != 0)
			{
				szFilePath[i] = szFilePath_t[i];
			}
		}

		(_tcsrchr(szFilePath, _T('\\')))[1] = 0;//删除文件名，只获得路径;
		strcpy(g_savepath, szFilePath);
		CS_save_path = g_savepath;
	}
	else
	{
		strcpy(g_savepath, CS_save_path.GetBuffer());
		//DWORD le0 = CS_data_path.GetLength() * sizeof(TCHAR);
	}
	
	//(_tcsrchr(g_datapath, _T('\\')))[1] = 0;//删除文件名，只获得路径
	UpdateData(FALSE);

}

void disp_message(HTuple hv_WindowHandle, HTuple hv_String, HTuple hv_CoordSystem,
	HTuple hv_Row, HTuple hv_Column, HTuple hv_Color, HTuple hv_Box)
{

	// Local iconic variables

	// Local control variables
	HTuple  hv_GenParamName, hv_GenParamValue;

	//This procedure displays text in a graphics window.
	//
	//Input parameters:
	//WindowHandle: The WindowHandle of the graphics window, where
	//   the message should be displayed
	//String: A tuple of strings containing the text message to be displayed
	//CoordSystem: If set to 'window', the text position is given
	//   with respect to the window coordinate system.
	//   If set to 'image', image coordinates are used.
	//   (This may be useful in zoomed images.)
	//Row: The row coordinate of the desired text position
	//   A tuple of values is allowed to display text at different
	//   positions.
	//Column: The column coordinate of the desired text position
	//   A tuple of values is allowed to display text at different
	//   positions.
	//Color: defines the color of the text as string.
	//   If set to [], '' or 'auto' the currently set color is used.
	//   If a tuple of strings is passed, the colors are used cyclically...
	//   - if |Row| == |Column| == 1: for each new textline
	//   = else for each text position.
	//Box: If Box[0] is set to 'true', the text is written within an orange box.
	//     If set to' false', no box is displayed.
	//     If set to a color string (e.g. 'white', '#FF00CC', etc.),
	//       the text is written in a box of that color.
	//     An optional second value for Box (Box[1]) controls if a shadow is displayed:
	//       'true' -> display a shadow in a default color
	//       'false' -> display no shadow
	//       otherwise -> use given string as color string for the shadow color
	//
	//It is possible to display multiple text strings in a single call.
	//In this case, some restrictions apply:
	//- Multiple text positions can be defined by specifying a tuple
	//  with multiple Row and/or Column coordinates, i.e.:
	//  - |Row| == n, |Column| == n
	//  - |Row| == n, |Column| == 1
	//  - |Row| == 1, |Column| == n
	//- If |Row| == |Column| == 1,
	//  each element of String is display in a new textline.
	//- If multiple positions or specified, the number of Strings
	//  must match the number of positions, i.e.:
	//  - Either |String| == n (each string is displayed at the
	//                          corresponding position),
	//  - or     |String| == 1 (The string is displayed n times).
	//
	//
	//Convert the parameters for disp_text.
	if (0 != (HTuple(int(hv_Row == HTuple())).TupleOr(int(hv_Column == HTuple()))))
	{
		return;
	}
	if (0 != (int(hv_Row == -1)))
	{
		hv_Row = 12;
	}
	if (0 != (int(hv_Column == -1)))
	{
		hv_Column = 12;
	}
	//
	//Convert the parameter Box to generic parameters.
	hv_GenParamName = HTuple();
	hv_GenParamValue = HTuple();
	if (0 != (int((hv_Box.TupleLength()) > 0)))
	{
		if (0 != (int(HTuple(hv_Box[0]) == HTuple("false"))))
		{
			//Display no box
			hv_GenParamName = hv_GenParamName.TupleConcat("box");
			hv_GenParamValue = hv_GenParamValue.TupleConcat("false");
		}
		else if (0 != (int(HTuple(hv_Box[0]) != HTuple("true"))))
		{
			//Set a color other than the default.
			hv_GenParamName = hv_GenParamName.TupleConcat("box_color");
			hv_GenParamValue = hv_GenParamValue.TupleConcat(HTuple(hv_Box[0]));
		}
	}
	if (0 != (int((hv_Box.TupleLength()) > 1)))
	{
		if (0 != (int(HTuple(hv_Box[1]) == HTuple("false"))))
		{
			//Display no shadow.
			hv_GenParamName = hv_GenParamName.TupleConcat("shadow");
			hv_GenParamValue = hv_GenParamValue.TupleConcat("false");
		}
		else if (0 != (int(HTuple(hv_Box[1]) != HTuple("true"))))
		{
			//Set a shadow color other than the default.
			hv_GenParamName = hv_GenParamName.TupleConcat("shadow_color");
			hv_GenParamValue = hv_GenParamValue.TupleConcat(HTuple(hv_Box[1]));
		}
	}
	//Restore default CoordSystem behavior.
	if (0 != (int(hv_CoordSystem != HTuple("window"))))
	{
		hv_CoordSystem = "image";
	}
	//
	if (0 != (int(hv_Color == HTuple(""))))
	{
		//disp_text does not accept an empty string for Color.
		hv_Color = HTuple();
	}
	//
	DispText(hv_WindowHandle, hv_String, hv_CoordSystem, hv_Row, hv_Column, hv_Color,
		hv_GenParamName, hv_GenParamValue);
	return;
}

CStringArray* DivString(CString test,CString cs_split,int  &i_split_number)
{
	CStringArray* m_result = new CStringArray;
	i_split_number = 0;
	if (test=="")
	{
		i_split_number=0;
		m_result->Add(_T(""));
		return m_result;
	}
	while (TRUE)
	{
		int index = test.Find(cs_split);
		int i_lenght = test.GetLength();
		if (index == -1)
		{
			m_result->Add(test);
			i_split_number++;
			return m_result;
		}
		i_split_number++;
		CString test1 = test.Left(index);
		m_result->Add(test1);
		test = test.Right(test.GetLength() - index - 1);
	}

}

//hv_AllDataSaveDir, hv_ModelFileName ,hv_RawImageFolder;

//自定义函数;
//获得-根目录文件名称函数;
void Get_Path_Root_Name(CString &File_Path)
{
	int i_sx = File_Path.ReverseFind('\\');
	int i_dx = File_Path.ReverseFind('/');
	if (i_dx > i_sx)
	{
		File_Path = File_Path.Right(File_Path.GetLength() - File_Path.ReverseFind('/') - 1);
	}
	else
	{
		File_Path = File_Path.Right(File_Path.GetLength() - File_Path.ReverseFind('\\') - 1);
	}
}

//自定义函数;
void Get_ReadSaveDir(void* param)
{
	CMFC_HALCON_DLLDlg *Dlg = (CMFC_HALCON_DLLDlg*)param;
	//子文件分类名;
	hv_label.Clear();
	if (((CButton *)(Dlg->GetDlgItem(IDC_RADIO_SPECIFIED_FILE)))->GetCheck())
	{
		hv_SubFile = 1;
		CStringArray* result = DivString(Dlg->cs_class_pre_calssnamefile, ",", i_split_number);
		for (int i = 0; i < i_split_number; i++)
		{
			CString cs_label = "/" + result->GetAt(i);
			hv_label[i] = cs_label.GetBuffer(cs_label.GetLength());
		}
		if (i_split_number == 0)
		{
			AfxMessageBox("子文件名为空！");
		}
	}
	else
	{
		hv_SubFile = 0;
	}

	if (Dlg->CS_data_path.GetLength() > 1)
	{
		hv_ImageBaseFolder = Dlg->CS_data_path.GetBuffer(Dlg->CS_data_path.GetLength());
	}
	if (hv_SubFile[0] > 0)
	{
		HTuple hv_label_all;
		//((((hv_label1.TupleConcat(hv_label2)).TupleConcat(hv_label3)).TupleConcat(hv_label4)).TupleConcat(hv_label5));
		if (i_split_number > 0)
		{
			hv_label_all.TupleConcat(hv_label[0]);
		}
		for (int i = 1; i < i_split_number; i++)
		{
			hv_label_all.TupleConcat(hv_label[i]);
		}
		hv_RawImageFolder = hv_ImageBaseFolder + hv_label;
	}
	else
	{
		hv_RawImageFolder = hv_ImageBaseFolder;
	}
	hv_AllDataSaveDir = Dlg->CS_save_path.GetBuffer(Dlg->CS_save_path.GetLength());
	hv_ModelFileName = Dlg->cs_class_modelfilename.GetBuffer(Dlg->cs_class_modelfilename.GetLength());

}

//自定义函数;//分类-训练函数;
void Class_Train_Process(CMFC_HALCON_DLLDlg *dlg)
{

	//×××××××设置训练参数××××××××××;
	CreateDict(&(Class_Train.hv_TrainSetParam));
	SetDictTuple(Class_Train.hv_TrainSetParam, "BatchSize", Class_Train.hv_BatchSize);
	SetDictTuple(Class_Train.hv_TrainSetParam, "InitialLearningRate", Class_Train.hv_InitialLearningRate);
	SetDictTuple(Class_Train.hv_TrainSetParam, "Momentum", Class_Train.hv_Momentum);
	SetDictTuple(Class_Train.hv_TrainSetParam, "NumEpochs", Class_Train.hv_NumEpochs);
	SetDictTuple(Class_Train.hv_TrainSetParam, "WeightPrior", Class_Train.hv_WeightPrior);
	SetDictTuple(Class_Train.hv_TrainSetParam, "Augmentation_Percentage", Class_Train.hv_Augmenttation_Percentage);
	SetDictTuple(Class_Train.hv_TrainSetParam, "ChangeLearningRateEpochs", Class_Train.hv_ChangeLearningRateEpochs);
	SetDictTuple(Class_Train.hv_TrainSetParam, "ChangeLearningRateValues", Class_Train.hv_ChangeLearningRate);
	SetDictTuple(Class_Train.hv_TrainSetParam, "RandomSeed", Class_Train.hv_RandomSeed);
	SetDictTuple(Class_Train.hv_TrainSetParam, "Augmentation_Method", Class_Train.hv_Augmentation_Method);
	SetDictTuple(Class_Train.hv_TrainSetParam, "Augmentation_Value", Class_Train.hv_Augmentation_Value);

	//×××××××设置显示参数××××××××××;
	CreateDict(&(Class_Train.hv_DispaySetParam));
	SetDictTuple(Class_Train.hv_DispaySetParam, "EnableDisplay", Class_Train.hv_EnableDiasplay);// .hv_EnableDisplay
	SetDictTuple(Class_Train.hv_DispaySetParam, "SelectedPercentageTrainSamples", Class_Train.hv_SelectePercentaheTrainSamples);// .hv_SelectedPercentageTrainSamples
	SetDictTuple(Class_Train.hv_DispaySetParam, "update_images_interval_epochs", Class_Train.hv_update_images_interval_epochs);
	SetDictTuple(Class_Train.hv_DispaySetParam, "change_plot_interval_seconds", Class_Train.hv_change_plot_interval_seconds);
	SetDictTuple(Class_Train.hv_DispaySetParam, "update_interval_seconds", Class_Train.hv_update_interval_seconds);
	SetDictTuple(Class_Train.hv_DispaySetParam, "EvaluationIntervalEpochs", Class_Train.hv_EvaluationIntervalEpochs);


	//
	(Class_Train.hv_ClassBestFinaModelBaseNameSavePath).Clear();
	(Class_Train.hv_ClassBestFinaModelBaseNameSavePath).Append(hv_AllDataSaveDir);
	(Class_Train.hv_ClassBestFinaModelBaseNameSavePath).Append(Class_Train.hv_BestModelBaseName);
	(Class_Train.hv_ClassBestFinaModelBaseNameSavePath).Append(Class_Train.hv_FinalModelBaseName);
	
	//读入在预处理过程中预训练的轻量型的深度分类模型。;
	ReadDlModel(hv_ModelFileName, &(Class_Train.hv_DLModelHandle));

	HTuple hv_WindowHandles;
	hv_WindowHandles.Clear();
	hv_WindowHandles.Append(hv_WindowHandleimage);
	hv_WindowHandles.Append(hv_WindowHandlechild);

	//Class_Prepro.hv_Class_DLDataset;

// 	Class_Train_DL_Model(Class_Prepro.hv_Class_DLDataset, Class_Train.hv_DLModelHandle, Class_Train.hv_TrainSetParam, Class_Train.hv_DispaySetParam,
// 			Class_Prepro.hv_DLPreprocessParam, hv_WindowHandles, Class_Train.hv_ClassBestFinaModelBaseNameSavePath,
// 			&(Class_Train.hv_TrainResults), &(Class_Train.hv_TrainInfos), &(Class_Train.hv_EvaluationInfos));

// 	HTuple hv_DLDataset, hv_DLModelHandle, hv_TrainSetParam, hv_DispaySetParam,
// 		hv_DLPreprocessParam, hv_ClassBestFinaModelBaseNameSavePath;

// 	HTuple hv_TrainResults, hv_TrainInfos, hv_EvaluationInfos;
// 	CreateDict(&hv_DLDataset);

// 	CreateDict(&hv_TrainSetParam);

// 	CreateDict(&hv_DispaySetParam);

// 	CreateDict(&hv_DLPreprocessParam);

// 	Class_Train_DL_Model_000(hv_DLDataset, hv_DLModelHandle, hv_TrainSetParam, hv_DispaySetParam,
// 		hv_DLPreprocessParam, hv_WindowHandles, hv_ClassBestFinaModelBaseNameSavePath,
// 		&hv_TrainResults, &hv_TrainInfos, &hv_EvaluationInfos);

// 	DL_DLL_API	void Class_Train_DL_Model(HTuple hv_DLDataset, HTuple hv_DLModelHandle, HTuple hv_TrainSetParam,
// 		HTuple hv_DispaySetParam, HTuple hv_DLPreprocessParam, HTuple hv_WindowHandles,
// 		HTuple hv_ClassBestFinaModelBaseNameSavePath, HTuple *hv_TrainResults, HTuple *hv_TrainInfos,
// 		HTuple *hv_EvaluationInfos);


// 	Class_Train_DL_Model_000(HTuple hv_DLDataset, HTuple hv_DLModelHandle, HTuple hv_TrainSetParam,
// 		HTuple hv_DispaySetParam, HTuple hv_DLPreprocessParam, HTuple hv_WindowHandles,
// 		HTuple hv_ClassBestFinaModelBaseNameSavePath, HTuple *hv_TrainResults, HTuple *hv_TrainInfos,
// 		HTuple *hv_EvaluationInfos)

	HDevWindowStack::Push(hv_WindowHandleimage);
	HDevWindowStack::SetActive(hv_WindowHandleimage);
	if (HDevWindowStack::IsOpen())
		SetPart(HDevWindowStack::GetActive(), 1, 1, -1, -1);

	HDevWindowStack::Push(hv_WindowHandlechild);
	HDevWindowStack::SetActive(hv_WindowHandlechild);
	if (HDevWindowStack::IsOpen())
		SetPart(HDevWindowStack::GetActive(), 1, 1, -1, -1);

	if (hv_UseGPU == 1)
	{
		try
		{
			Class_Train_DL_Model((Class_Prepro.hv_Class_DLDataset), (Class_Train.hv_DLModelHandle), (Class_Train.hv_TrainSetParam), (Class_Train.hv_DispaySetParam), \
				(Class_Prepro.hv_DLPreprocessParam), hv_WindowHandles, (Class_Train.hv_ClassBestFinaModelBaseNameSavePath), \
				&(Class_Train.hv_TrainResults), &(Class_Train.hv_TrainInfos), &(Class_Train.hv_EvaluationInfos));

		}
		catch (HException &HDevExpDefaultException)
		{
			// 		HString hs = HDevExpDefaultException.ProcName();
			// 		HString hs1 = HDevExpDefaultException.ErrorMessage(); //错误文本
			// 		Herror hs2 = HDevExpDefaultException.ErrorCode(); //错误代码
			HTuple hv_Exception;
			HDevExpDefaultException.ToHTuple(&hv_Exception);
			CString  s_line = hv_Exception[3].S();
			CString  s_ErrorMessage = hv_Exception[4].S();
			AfxMessageBox(" Error：" + s_ErrorMessage + " Line：" + s_line);
			//int iiii = 0;
			return;
		}
		catch (HTuple &HDevExpDefaultException)
		{
			int i_line = HDevExpDefaultException.I();
			CString  s_ErrorMessage = HDevExpDefaultException[1].S();
			CString s_line;
			s_line.Format(_T("%d"), i_line);
			AfxMessageBox(" Error：" + s_ErrorMessage + " Line：" + s_line);
			return;
		}
	}
	else
	{
		AfxMessageBox("HALCON_GPU 不可用！");
	}
}

//自定义函数;//分类-预处理函数;
void Class_Preprocess(CMFC_HALCON_DLLDlg *dlg)
{

	//CMFC_HALCON_DLLDlg *dlg
	HTuple hv_Exception;

	//----->读取图像数据到图像字典<-----
	//AfxMessageBox("马上进行--》预处理图像生成字典！");
	try
	{	
		read_dl_dataset_classification_ht(hv_RawImageFolder, Class_Prepro.hv_LabelSource, &(Class_Prepro.hv_Class_DLDataset), \
			&(Class_Prepro.hv_ClassNames), &(Class_Prepro.hv_ClassIDs));
	}
	catch (HException &HDevExpDefaultException)
	{
// 		HString hs = HDevExpDefaultException.ProcName();
// 		HString hs1 = HDevExpDefaultException.ErrorMessage(); //错误文本
// 		Herror hs2 = HDevExpDefaultException.ErrorCode(); //错误代码
		HDevExpDefaultException.ToHTuple(&hv_Exception);
		CString  s_line = hv_Exception[3].S();
		CString  s_ErrorMessage = hv_Exception[4].S();
		AfxMessageBox(" Error：" + s_ErrorMessage + " Line：" + s_line);
		//int iiii = 0;
		return;
	}
	catch (HTuple &HDevExpDefaultException)
	{	
		int i_line = HDevExpDefaultException.I();
		CString  s_ErrorMessage = HDevExpDefaultException[1].S();
		CString s_line;
		s_line.Format(_T("%d"), i_line);
		AfxMessageBox(" Error：" + s_ErrorMessage + " Line：" + s_line);
		return;
	}
	//AfxMessageBox("预处理图像生成字典完成！");

// 	Class_Prepro.hv_ImagePreprocessFeatures.Clear();
// 	Class_Prepro.hv_ImagePreprocessFeatures.Append(Class_Prepro.hv_ImageWidth);
// 	Class_Prepro.hv_ImagePreprocessFeatures.Append(Class_Prepro.hv_ImageHeight);
// 	Class_Prepro.hv_ImagePreprocessFeatures.Append(Class_Prepro.hv_ImageChannels);
// 	Class_Prepro.hv_ImagePreprocessFeatures.Append(Class_Prepro.hv_NormalizationType);
// 	Class_Prepro.hv_ImagePreprocessFeatures.Append(Class_Prepro.hv_Domainhandling);

// 	HTuple hv_ImagePreprocessFeatures = Class_Prepro.hv_ImagePreprocessFeatures;
// 	HTuple hv_sub = Class_Prepro.hv_LabelSource;
// 	HTuple hv_calssname = Class_Prepro.hv_ClassNames;
// 	HTuple hv_1 = Class_Prepro.hv_TrainingValidationPercent;
//  HTuple hv_ImageWidth = Class_Prepro.hv_ImageWidth;
	
	//AfxMessageBox("预处理图像关键函数开始！");
	try
	{
		Classify_Preprocess(Class_Prepro.hv_Class_DLDataset, Class_Prepro.hv_TrainingValidationPercent, Class_Prepro.hv_ImagePreprocessFeatures,
			Class_Prepro.hv_Is_overwrite_files, hv_AllDataSaveDir, hv_WindowHandleimage, &(Class_Prepro.hv_DLDatasetFileName),
			&(Class_Prepro.hv_DataDirectory), &(Class_Prepro.hv_PreprocessParamFile), &(Class_Prepro.hv_DLPreprocessParam));

	}
	catch (HException &HDevExpDefaultException)
	{
		// 		HString hs = HDevExpDefaultException.ProcName();
		// 		HString hs1 = HDevExpDefaultException.ErrorMessage(); //错误文本
		// 		Herror hs2 = HDevExpDefaultException.ErrorCode(); //错误代码
		HDevExpDefaultException.ToHTuple(&hv_Exception);
		CString  s_line = hv_Exception[3].S();
		CString  s_ErrorMessage = hv_Exception[4].S();
		AfxMessageBox(" Error：" + s_ErrorMessage + " Line：" + s_line);
		//int iiii = 0;
		return;
	}
	catch (HTuple &HDevExpDefaultException)
	{
		int i_line = HDevExpDefaultException.I();
		CString  s_ErrorMessage = HDevExpDefaultException[1].S();
		CString s_line;
		s_line.Format(_T("%d"), i_line);
		AfxMessageBox(" Error：" + s_ErrorMessage + " Line：" + s_line);
		return;
	}

	CString DLDatasetFileName = Class_Prepro.hv_DLDatasetFileName.S();

	CString PreprocessParamFile = Class_Prepro.hv_PreprocessParamFile.S();

	Get_Path_Root_Name(DLDatasetFileName);

	Get_Path_Root_Name(PreprocessParamFile);

	DLDatasetFileName = "DLDatasetFileName:" + DLDatasetFileName;

	PreprocessParamFile = "PreprocessParamFile:" + PreprocessParamFile;

	dlg->GetDlgItem(IDC_STATIC_DLDatasetFileName)->SetWindowText(DLDatasetFileName);

	dlg->GetDlgItem(IDC_STATIC_PreprocessDirect)->SetWindowText(PreprocessParamFile);

	AfxMessageBox("预处理关键函数完成!");
}

//自定义函数;//分类-显示函数;
void Show_Class_Preprocess()
{
	HTuple hv_WindowHandles;

	hv_WindowHandles.Clear();
	hv_WindowHandles.Append(hv_WindowHandleimage);
	hv_WindowHandles.Append(hv_WindowHandlechild);
	// 
	//AfxMessageBox("随机显示10个预处理训练集标签图像！");

	HTuple hv_SplitSamplesName = "train";
	HTuple hv_SamplesNums = 10;
	HTuple hv_KeysForDisplay = "classification_ground_truth";

	Dev_Display_Class_PreprocesSamples(Class_Prepro.hv_Class_DLDataset, hv_WindowHandles, hv_SplitSamplesName,
		hv_SamplesNums, hv_KeysForDisplay, 1);
}

//预处理线程函数;
UINT CMFC_HALCON_DLLDlg::thread_preprocess(void* param)
{
	
	CMFC_HALCON_DLLDlg *dlg = (CMFC_HALCON_DLLDlg*)param;

	if (Thread_Running_Type == 1)//分类-预处理方面;
	{
		Class_Preprocess(dlg);
	}
	else if (Thread_Running_Type == 1001)//随机显示预处理图像;
	{
		Show_Class_Preprocess();
	}
	else if (Thread_Running_Type == 2)//分类-训练;
	{
		Class_Train_Process(dlg);
	}
	else if (Thread_Running_Type == 3)//分类-评估;
	{
		;
	}
	else if (Thread_Running_Type == 4)//分类-推断;
	{
		;
	}
	Thread_Running_Type = 0;

	return 0;
	




// hv_Class_ImagePreprocessFeatures;
// 	HTuple hv_OutDir, hv_AllDataSaveDir;
// 
// 	HTuple hv_RawImageBaseFolder, hv_LabelSource, hv_PathExample;
// 
// 	HTuple hv_TrainingValidationPercent;
// 
// 	hv_PathExample = "C:\\Users\\Public\\Documents\\MVTec\\HALCON-19.11-Progress\\examples";
// 
// 	//具有真实标签分类图像数据的文件夹。;
// 	hv_RawImageBaseFolder = hv_PathExample + "/images/pill/";
// 	//LabelSource用于读取数据集。 'last_folder'最后文件夹名为类名标签,'file_name'文件名最为类名标签,'file_name_remove_index'文件名除去后面的序列之后最为类名标签;
// 	hv_LabelSource = "last_folder";
// 	HTuple  hv_DLDataset;
// 
// 	HTuple hv_Exception, hv_ErrorCode, hv_CocoFileName, hv_DictCocoJson;
// 	
//	AfxMessageBox("马上进行--》预处理图像生成字典！");

// 	try
// 	{
// 		ReadDict(hv_CocoFileName, HTuple(), HTuple(), &hv_DictCocoJson);
// 	}
// 	catch (HException &HDevExpDefaultException)
// 	{
// 		HString hs = HDevExpDefaultException.ProcName();
// 		HString hs1 = HDevExpDefaultException.ErrorMessage(); //错误文本
// 		Herror hs2 = HDevExpDefaultException.ErrorCode(); //错误代码
// 		HDevExpDefaultException.ToHTuple(&hv_Exception);
// 		//const char*  c_hs = hv_Exception[0].S();
// 		const char *pStr = NULL;
// 		const char *pStr1 = NULL;
// 		pStr = hs.Text();
// 		pStr1 = hs1.Text();
// 		int iiii = 0;
// 	}


	//hv_RawImageBaseFolder = 0;

// 	catch (HException &except)
// 	{
// 
// 		HException  exx("Parameter \"LabelSource\" has to be of length 1.");
// 		const HTuple exception, name;
// 		HTuple  value;
// 		except.GetExceptionData( exception, name,  &value);
// 		exx.GetExceptionData(exception, name, &value);
// 		HString hs = except.ProcName(); //实际的HALCON算子的名字
// 		HString hs1 = except.ErrorMessage(); //错误文本
// 		Herror hs2 = except.ErrorCode(); //错误代码
// 
// 		const char*  c_hs = hs.TextA();
// 		const char*  c_hs1 = hs1.TextA();
// 
// 		int  iioop = 0;
// 		except.ToHTuple(&hv_Exception);
// 
// 
// 		exx.ToHTuple(&hv_Exception);
// 		hv_ErrorCode = ((const HTuple&)hv_Exception)[0];
// 	}

// 	
// 	AfxMessageBox("预处理图像生成字典完成！");
// 
// 
// 	HTuple hv_OutDir = "E:/dl/dl-class/";
// 	hv_AllDataSaveDir = hv_OutDir + "classify_pill_defects_data";
// 
// 	HTuple hv_TrainingValidationPercent;
// 	hv_TrainingValidationPercent.Clear();
// 	hv_TrainingValidationPercent[0] = 70;
// 	hv_TrainingValidationPercent[1] = 15;
// 
// 	HTuple hv_ImageWidth = 300;
// 	HTuple hv_ImageHeight = 300;
// 	HTuple hv_ImageNumChannels = 3;
// 
// 	//用于图像预处理的其他参数 正则化 处理对象全域 。;
// 	HTuple hv_NormalizationType = "none";
// 	HTuple hv_DomainHandling = "full_domain";
// 	HTuple hv_ImagePreprocessFeatures;
// 	hv_ImagePreprocessFeatures.Clear();
// 	hv_ImagePreprocessFeatures.Append(hv_ImageWidth);
// 	hv_ImagePreprocessFeatures.Append(hv_ImageHeight);
// 	hv_ImagePreprocessFeatures.Append(hv_ImageNumChannels);
// 	hv_ImagePreprocessFeatures.Append(hv_NormalizationType);
// 	hv_ImagePreprocessFeatures.Append(hv_DomainHandling);
// 
// 	//样本字典字典是不是覆盖重新保存;
// 	HTuple hv_is_overwrite_files = 1;
// 
// 
// 	HTuple  hv_PreprocessParamFile, hv_DLPreprocessParam, hv_DLDatasetFileName, hv_DataDirectory;
// 
// // 	HWND hwndiamge = dlg->GetDlgItem(IDC_STATIC_PICTURE1)->GetSafeHwnd();
// // 	HWND hwndchild = dlg->GetDlgItem(IDC_STATIC_PICTURE2)->GetSafeHwnd();
// 
// 	HDevWindowStack::SetActive(hv_WindowHandlechild);
// 	HObject  ho_Frame;

// 	ReadImage(&ho_Frame, "E:/24.bmp");
// 	HTuple m_ImageWidth, m_ImageHeight;
// 	GetImageSize(ho_Frame, &m_ImageWidth, &m_ImageHeight);
// 	SetPart(hv_WindowHandlechild, 0, 0, m_ImageHeight - 1, m_ImageWidth - 1);
// 	if (HDevWindowStack::IsOpen())
// 	{
// 		DispObj(ho_Frame, HDevWindowStack::GetActive());
// 	}
		


//	AfxMessageBox("开始预处理关键函数！");



// 	HTuple hv_Progress;
// 	hv_Progress.Clear();
// 	hv_Progress[0] = "Procedure: preprocess_dl_dataset";
// 	hv_Progress[1] = "";
// 	hv_Progress[2] = "";
// 	hv_Progress[3] = "";
// 	
//     //set_display_font(hv_WindowHandleimage, 15, "mono", "true", "false");
//     //dev_inspect_ctrl (Progress)
// 	HDevWindowStack::SetActive(hv_WindowHandleimage);
// 	disp_message(hv_WindowHandleimage, hv_Progress, "window", 8, 8, "blue", "false");
// 
// // 
// 
// 	if (HDevWindowStack::IsOpen())
// 		ClearWindow(HDevWindowStack::GetActive());
// 
// 	hv_Progress[0] = "P-------------------";
// 
// 	disp_message(hv_WindowHandleimage, hv_Progress, "window", 8, 8, "blue", "false");
// 
// 	if (HDevWindowStack::IsOpen())
// 		ClearWindow(HDevWindowStack::GetActive());
// 
// 	hv_Progress[0] = "222222222222222222222222222";
// 
// 	disp_message(hv_WindowHandleimage, hv_Progress, "window", 8, 8, "blue", "false");
// 
// 	if (HDevWindowStack::IsOpen())
// 		ClearWindow(HDevWindowStack::GetActive());
// 
// 
// 
// 	hv_Progress[0] = "33333333333333333333333333333333333";
// HTuple hv_Class_Propre_TrainingValidationPercent
// 	disp_message(hv_WindowHandleimage, hv_Progress, "window", 8, 8, "blue", "false");
// 
// 	if (HDevWindowStack::IsOpen())
// 		ClearWindow(HDevWindowStack::GetActive());
// 
// 
// 	hv_Progress[0] = "4444444444444444444444444444444444";
// 
// 	disp_message(hv_WindowHandleimage, hv_Progress, "window", 8, 8, "blue", "false");

// 	if (HDevWindowStack::IsOpen())
// 		ClearWindow(HDevWindowStack::GetActive());
// 
// 	Classify_Preprocess(Class_Prepro.hv_Class_DLDataset, hv_TrainingValidationPercent, hv_ImagePreprocessFeatures,
// 		hv_is_overwrite_files, hv_AllDataSaveDir, hv_WindowHandleimage, &hv_DLDatasetFileName, &hv_DataDirectory,
// 		&hv_PreprocessParamFile, &hv_DLPreprocessParam);
//	AfxMessageBox("预处理关键函数完成!");
// 
// 

// 

//	Thread_Running_Type = 0;

//	return 1;
}


//预处理按钮;
void CMFC_HALCON_DLLDlg::OnBnClickedButtonPreprocess()
{
	// TODO:  在此添加控件通知处理程序代码

	//HTuple  HV_name = Class_Prepros.hv_ClassNames;
// 	CString SSS = "NIHAO";
// 	HTuple  HV_CS = SSS;
// 	HV_CS[1] = "123";
// 	CString SSS1 = HV_CS.S();
// 	CString SSS2 = HV_CS[1].S();
	UpdateData(TRUE);
	if (Thread_Running_Type >0)
	{
		AfxMessageBox("进程正在运行中！");
		return;
	}
	//thread_running = 1;

	CRect rect, rect2;
	CWnd *pWnd = this->GetDlgItem(IDC_STATIC_PICTURE1);//IDC_picture为picture控件ID;
	pWnd->GetClientRect(&rect);//rc为控件的大小。;
	// 	int x = rect.Height();
	// 	int y = rect.Width
	CWnd *pWnd0 = this->GetDlgItem(IDC_STATIC_PICTURE2);//IDC_picture为picture控件ID;
	pWnd0->GetClientRect(&rect2);//rc为控件的大小。;

	HTuple m_HWindowID1, m_HWindowID2;
	m_HWindowID1 = (Hlong)pWnd->m_hWnd;
	m_HWindowID2 = (Hlong)pWnd0->m_hWnd;
	SetWindowAttr("background_color", "black");
	OpenWindow(0, 0, rect2.Width(), rect2.Height(), m_HWindowID1, "visible", "", &hv_WindowHandlechild);
	HDevWindowStack::Push(hv_WindowHandlechild);

	SetWindowAttr("background_color", "black");
	OpenWindow(0, 0, rect.Width(), rect.Height(), m_HWindowID2, "visible", "", &hv_WindowHandleimage);
	HDevWindowStack::Push(hv_WindowHandleimage);

	Get_ReadSaveDir(this);

	if (Thread_Running_Type == 0)
	{
		Thread_Running_Type = 1;
		m_pWinThreadImage = AfxBeginThread(thread_preprocess, this, THREAD_PRIORITY_NORMAL);
	}
	//hv_LabelSource = ;

// 
// 	HTuple hv_OutDir, hv_AllDataSaveDir;
// 
// 	HTuple hv_RawImageBaseFolder, hv_LabelSource, hv_PathExample;
// 
// 	HTuple hv_TrainingValidationPercent;
// 
// 	hv_PathExample = "C:\\Users\\Public\\Documents\\MVTec\\HALCON-19.11-Progress\\examples";
// 
// 	//具有真实标签分类图像数据的文件夹。
// 	hv_RawImageBaseFolder = hv_PathExample + "/images/pill/";
// 	//LabelSource用于读取数据集。 'last_folder'最后文件夹名为类名标签,'file_name'文件名最为类名标签,'file_name_remove_index'文件名除去后面的序列之后最为类名标签;
// 	hv_LabelSource = "last_folder";
// 	HTuple  hv_DLDataset;
// 
// 	//AfxMessageBox("预处理图像生成字典！");
// 	//read_dl_dataset_classification_ht(hv_RawImageBaseFolder, hv_LabelSource, &hv_DLDataset);
// 	//AfxMessageBox("预处理图像生成字典完成！");
// 
// 
// 	hv_OutDir = "E:/dl/dl-class/";
// 	hv_AllDataSaveDir = hv_OutDir + "classify_pill_defects_data";
// 
// 
// 	hv_TrainingValidationPercent.Clear();
// 	hv_TrainingValidationPercent[0] = 70;
// 	hv_TrainingValidationPercent[1] = 15;
// 
// 	HTuple hv_ImageWidth = 300;
// 	HTuple hv_ImageHeight = 300;
// 	HTuple hv_ImageNumChannels = 3;
// 
// 	//用于图像预处理的其他参数 正则化 处理对象全域 。;
// 	HTuple hv_NormalizationType = "none";
// 	HTuple hv_DomainHandling = "full_domain";
// 	HTuple hv_ImagePreprocessFeatures;
// 	hv_ImagePreprocessFeatures.Clear();
// 	hv_ImagePreprocessFeatures.Append(hv_ImageWidth);
// 	hv_ImagePreprocessFeatures.Append(hv_ImageHeight);
// 	hv_ImagePreprocessFeatures.Append(hv_ImageNumChannels);
// 	hv_ImagePreprocessFeatures.Append(hv_NormalizationType);
// 	hv_ImagePreprocessFeatures.Append(hv_DomainHandling);
// 
// 	//样本字典字典是不是覆盖重新保存
// 	HTuple hv_is_overwrite_files = 1;
// 
// 
// 	HTuple  hv_PreprocessParamFile, hv_DLPreprocessParam, hv_DLDatasetFileName, hv_DataDirectory;
// 
// 	// 	HWND hwndiamge = dlg->GetDlgItem(IDC_STATIC_PICTURE1)->GetSafeHwnd();
// 	// 	HWND hwndchild = dlg->GetDlgItem(IDC_STATIC_PICTURE2)->GetSafeHwnd();
// 	HTuple hv_WindowHandles, hv_WindowHandleimage, hv_WindowHandlechild;
// 
// 	CRect rect, rect2;
// 	CWnd *pWnd = this->GetDlgItem(IDC_STATIC_PICTURE1);//IDC_picture为picture控件ID;
// 	pWnd->GetClientRect(&rect);//rc为控件的大小。;
// 	// 	int x = rect.Height();
// 	// 	int y = rect.Width
// 	CWnd *pWnd0 = this->GetDlgItem(IDC_STATIC_PICTURE2);//IDC_picture为picture控件ID;
// 	pWnd0->GetClientRect(&rect2);//rc为控件的大小。;
// 
// 	HTuple m_HWindowID1, m_HWindowID2;
// 	m_HWindowID1 = (Hlong)pWnd->m_hWnd;
// 	m_HWindowID2 = (Hlong)pWnd0->m_hWnd;
// 	SetWindowAttr("background_color", "black");
// 	OpenWindow(0, 0, rect2.Width(), rect2.Height(), m_HWindowID1, "visible", "", &hv_WindowHandlechild);
// 	HDevWindowStack::Push(hv_WindowHandlechild);
// 
// 	SetWindowAttr("background_color", "black");
// 	OpenWindow(0, 0, rect.Width(), rect.Height(), m_HWindowID2, "visible", "", &hv_WindowHandleimage);
// 	HDevWindowStack::Push(hv_WindowHandleimage);
// 
// 
// 	HDevWindowStack::SetActive(hv_WindowHandleimage);
// 	HObject  ho_Frame;
// 	ReadImage(&ho_Frame, "E:/24.bmp");
// 	HTuple m_ImageWidth, m_ImageHeight;
// 	GetImageSize(ho_Frame, &m_ImageWidth, &m_ImageHeight);
// 	SetPart(hv_WindowHandleimage, 0, 0, m_ImageHeight - 1, m_ImageWidth - 1);
// 	if (HDevWindowStack::IsOpen())
// 	{
// 		DispObj(ho_Frame, HDevWindowStack::GetActive());
// 	}

// 	HWND hwndiamge = GetDlgItem(IDC_STATIC_PICTURE1)->GetSafeHwnd();
// 	CRect rect, rect2;
// 	CWnd *pWnd0 = GetDlgItem(IDC_STATIC_PICTURE1);//IDC_picture为picture控件ID;
// 	pWnd0->GetClientRect(&rect);//rc为控件的大小。;
// 	HTuple m_HWindowID;
// 	m_HWindowID = (Hlong)pWnd0->m_hWnd;
// 	HTuple hv_WindowHandles, hv_WindowHandleimage, hv_WindowHandlechild, m_ImageWidth, m_ImageHeight;
// 	SetWindowAttr("background_color", "black");
// 	OpenWindow(0, 0, rect.Width(), rect.Height(), m_HWindowID, "visible", "", &hv_WindowHandleimage);
// 	HDevWindowStack::Push(hv_WindowHandleimage);

// 
// 
// 	AfxMessageBox("显示开始");
// 	HDevWindowStack::SetActive(hv_WindowHandleimage);
// 	HObject  ho_Frame;
// 	ReadImage(&ho_Frame, "E:/24.bmp");
// 
// 	GetImageSize(ho_Frame, &m_ImageWidth, &m_ImageHeight);
// 	SetPart(hv_WindowHandleimage, 0, 0, m_ImageHeight - 1, m_ImageWidth - 1);
// 
// 	if (HDevWindowStack::IsOpen())
// 	{
// 		DispObj(ho_Frame, HDevWindowStack::GetActive());
// 	}
// 		
// 
// 	AfxMessageBox("结束！");

}

//选项卡
void CMFC_HALCON_DLLDlg::OnTcnSelchangeTabClass(NMHDR *pNMHDR, LRESULT *pResult)
{
	// TODO:  在此添加控件通知处理程序代码
	//当前选中的选项卡第几个;

	switch (m_tab_class.GetCurSel())
	{
	case 0:
		m_page_class.ShowWindow(SW_SHOW);
		m_page_detect.ShowWindow(SW_HIDE);
		m_page_detect_orienta.ShowWindow(SW_HIDE);
		m_page_segment.ShowWindow(SW_HIDE);
		m_page_anomaly.ShowWindow(SW_HIDE);
		break;
	case  1:
		m_page_class.ShowWindow(SW_HIDE);
		m_page_detect.ShowWindow(SW_SHOW);
		m_page_detect_orienta.ShowWindow(SW_HIDE);
		m_page_segment.ShowWindow(SW_HIDE);
		m_page_anomaly.ShowWindow(SW_HIDE);
		break;
	case  2:
		m_page_class.ShowWindow(SW_HIDE);
		m_page_detect.ShowWindow(SW_HIDE);
		m_page_detect_orienta.ShowWindow(SW_SHOW);
		m_page_segment.ShowWindow(SW_HIDE);
		m_page_anomaly.ShowWindow(SW_HIDE);
		break;
	case  3:
		m_page_class.ShowWindow(SW_HIDE);
		m_page_detect.ShowWindow(SW_HIDE);
		m_page_detect_orienta.ShowWindow(SW_HIDE);
		m_page_segment.ShowWindow(SW_SHOW);
		m_page_anomaly.ShowWindow(SW_HIDE);
		break;
	case  4:
		m_page_class.ShowWindow(SW_HIDE);
		m_page_detect.ShowWindow(SW_HIDE);
		m_page_detect_orienta.ShowWindow(SW_HIDE);
		m_page_segment.ShowWindow(SW_HIDE);
		m_page_anomaly.ShowWindow(SW_SHOW);
		break;
	default:
		break;

	}

	*pResult = 0;
}


//随机显示图像数据;
void CMFC_HALCON_DLLDlg::OnBnClickedButtonShowPreprocess()
{
	// TODO:  在此添加控件通知处理程序代码;

	if (Thread_Running_Type == 0)
	{
		Thread_Running_Type = 1001;
		m_pWinThreadImage = AfxBeginThread(thread_preprocess, this, THREAD_PRIORITY_NORMAL);
	}
	else
	{
		AfxMessageBox("有进程在处理中！稍等！");
	}
}

//指定类文件名 单选框 -响应事件-;
void CMFC_HALCON_DLLDlg::OnBnClickedRadioSpecifiedFile()
{
	// TODO:  在此添加控件通知处理程序代码

	if (((CButton *)GetDlgItem(IDC_RADIO_SPECIFIED_FILE))->GetCheck() && cs_class_pre_calssnamefile == "")//
	{
		cs_class_pre_calssnamefile = "apple_braeburn,apple_golden_delicious,apple_topaz,peach,pear";
		
	}
	UpdateData(FALSE);
}

//指定类文件名 编辑框 -响应事件-;
void CMFC_HALCON_DLLDlg::OnEnChangeEditClassFile()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码
}

//初始化模型路径-按钮事件;
void CMFC_HALCON_DLLDlg::OnBnClickedButtonModelSave()
{
	// TODO:  在此添加控件通知处理程序代码
	TCHAR szFilePath_t[MAX_PATH + 1];

	if (szFilePathdata[0] == 0)
	{
		GetModuleFileName(NULL, szFilePathdata, MAX_PATH);
		(_tcsrchr(szFilePathdata, _T('\\')))[1] = 0;//删除文件名，只获得路径
	}

	CString defaultDir = szFilePathdata;   //默认打开的文件路径;  
	CString fileName = _T("所选模型：pretrained_dl_classifier_compact.hdl");         //默认打开的文件名  ;
	CString filter = _T("模型(*.hdl)|*.hdl||");   //文件过虑的类型 ; 视频(*.mp4;)|*.mp4|
	CFileDialog openFileDlg(TRUE, defaultDir, fileName, OFN_HIDEREADONLY | OFN_READONLY, filter, NULL);//  
	openFileDlg.GetOFN().lpstrInitialDir = defaultDir;
	INT_PTR result = openFileDlg.DoModal();
	cs_class_modelfilename = defaultDir;
	char c_modelfilename[360] = { 0 };
	if (result == IDOK)
	{
		cs_class_modelfilename = openFileDlg.GetPathName();
// 		for (int i = 0; i < cs_class_modelfilename.GetLength(); i++)
// 		{
// 			szFilePath_t[i] = cs_class_modelfilename[i];
// 		}
// 		(_tcsrchr(szFilePath_t, _T('\\')))[1] = 0;//删除文件名，只获得路径；
// 
// 		for (int i = 0; i < MAX_PATH + 1; i++)
// 		{
// 			if (szFilePath_t[i] != 0)
// 			{
// 				szFilePathdata[i] = szFilePath_t[i];
// 			}
// 		}
// 
// 		(_tcsrchr(szFilePathdata, _T('\\')))[1] = 0;//删除文件名，只获得路径;
// 		strcpy(c_modelfilename, szFilePathdata);
		//cs_class_modelfilename = c_modelfilename;
	}
	else
	{
		//strcpy(g_datapath, cs_class_modelfilename.GetBuffer());
		//DWORD le0 = CS_data_path.GetLength() * sizeof(TCHAR);
	}

	CString firstFileName = "";
	firstFileName = cs_class_modelfilename.Right(cs_class_modelfilename.GetLength() - cs_class_modelfilename.ReverseFind('\\') - 1);

	cs_select_class_modelname = _T("所选模型：") + firstFileName;


	UpdateData(FALSE);

}

//单选框-所选json文件-事件相应函数-;
void CMFC_HALCON_DLLDlg::OnBnClickedRadio2()
{
	// TODO:  在此添加控件通知处理程序代码;
	UpdateData(TRUE);
	if (((CButton *)GetDlgItem(IDC_RADIO2))->GetCheck() && CS_json_path == "")//
	{
		CS_json_path = "C:\\Users\\Public\\Documents\\MVTec\\HALCON-19.11-Progress\\examples\\hdevelop\\Deep-Learning\\Detection\\pill_bag.json";
		cs_select_jsonname = _T("所选json文件：") + CS_json_path.Right(CS_json_path.GetLength() - CS_json_path.ReverseFind('\\') - 1);
	}
	else if (CS_json_path != "")
	{
		cs_select_jsonname = _T("所选json文件：") + CS_json_path.Right(CS_json_path.GetLength() - CS_json_path.ReverseFind('\\') - 1);
	}

	UpdateData(FALSE);
}

//选择json文件;
void CMFC_HALCON_DLLDlg::OnBnClickedButtonOpenJson()
{
	// TODO:  在此添加控件通知处理程序代码


	TCHAR szFilePath_t[MAX_PATH + 1];

	if (szFilePathdata[0] == 0)
	{
		GetModuleFileName(NULL, szFilePathdata, MAX_PATH);
		(_tcsrchr(szFilePathdata, _T('\\')))[1] = 0;//删除文件名，只获得路径
	}

	CString defaultDir = szFilePathdata;   //默认打开的文件路径;  
	CString fileName = _T("所选json文件：pill_bag.json");         //默认打开的文件名  ;
	CString filter = _T("json文件(*.json)|*.json||");   //文件过虑的类型 ; 视频(*.mp4;)|*.mp4|
	CFileDialog openFileDlg(TRUE, defaultDir, fileName, OFN_HIDEREADONLY | OFN_READONLY, filter, NULL);//  
	openFileDlg.GetOFN().lpstrInitialDir = defaultDir;
	INT_PTR result = openFileDlg.DoModal();
	CS_json_path = defaultDir;
	//char c_modelfilename[360] = { 0 };
	if (result == IDOK)
	{
		CS_json_path = openFileDlg.GetPathName();
	}
	else
	{
		//strcpy(g_datapath, cs_class_modelfilename.GetBuffer());
		//DWORD le0 = CS_data_path.GetLength() * sizeof(TCHAR);
	}

	cs_select_jsonname = _T("所选json文件：") + CS_json_path.Right(CS_json_path.GetLength() - CS_json_path.ReverseFind('\\') - 1);

	UpdateData(FALSE);
}

//所选json文件编辑框事件相应函数;
void CMFC_HALCON_DLLDlg::OnEnChangeEdit1()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码

	UpdateData(TRUE);
	if (CS_json_path != "")
	{
		int i_sx = CS_json_path.ReverseFind('\\');
		int i_dx = CS_json_path.ReverseFind('/');
		if (i_dx > i_sx)
		{
			cs_select_jsonname = _T("所选json文件：") + CS_json_path.Right(CS_json_path.GetLength() - CS_json_path.ReverseFind('/') - 1);
		}
		else
		{
			cs_select_jsonname = _T("所选json文件：") + CS_json_path.Right(CS_json_path.GetLength() - CS_json_path.ReverseFind('\\') - 1);
		}
		
	}
	UpdateData(FALSE);

}

//所选模型文本框事件相应函数;
void CMFC_HALCON_DLLDlg::OnEnChangeEditModelSave()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog();
	// 函数并调用 CRichEditCtrl().SetEventMask();
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中;

	// TODO:  在此添加控件通知处理程序代码;
	UpdateData(TRUE);
	if (cs_class_modelfilename != "")
	{
		int i_sx = cs_class_modelfilename.ReverseFind('\\');
		int i_dx = cs_class_modelfilename.ReverseFind('/');

		if (i_dx>i_sx)
		{
			cs_select_class_modelname = _T("所选模型：") + cs_class_modelfilename.Right(cs_class_modelfilename.GetLength() - cs_class_modelfilename.ReverseFind('/') - 1);
		}
		else
		{
			cs_select_class_modelname = _T("所选模型：") + cs_class_modelfilename.Right(cs_class_modelfilename.GetLength() - cs_class_modelfilename.ReverseFind('\\') - 1);
		} 
	}
	UpdateData(FALSE);
}

//训练按钮;
void CMFC_HALCON_DLLDlg::OnBnClickedButtonTrain()
{
	// TODO:  在此添加控件通知处理程序代码;

	if (Thread_Running_Type == 0)
	{
		Thread_Running_Type = 2;
		m_pWinThreadImage = AfxBeginThread(thread_preprocess, this, THREAD_PRIORITY_NORMAL);
	}
	else
	{
		AfxMessageBox("有进程在处理中！稍等！");
	}

}
