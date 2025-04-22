
// MFC_HALCON_DLLDlg.cpp : ʵ���ļ�
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
//����;
HTuple  hv_WindowHandleimage, hv_WindowHandlechild;
//��ͼ;
HTuple hv_label;
HTuple hv_SubFile;
HTuple hv_ImageBaseFolder;//��ѡ���Ե������ļ�;
HTuple hv_RawImageFolder;//���·����·���������ļ�Ϊѵ���ļ�;
HTuple hv_ModelFileName;
HTuple hv_AllDataSaveDir;


//����-Ԥ�������;
CLASS_PREPRO_S Class_Prepro;
//����-ѵ������;
CLASS_Train_S  Class_Train;


//HTuple hv_LabelSource;//������ǩ��ͬ��ʽ//
// 	//* LabelSource���ڶ�ȡ���ݼ���;
// 	//'last_folder'����ļ�����Ϊ������ǩ;
// 	//'file_name'�ļ�����Ϊ������ǩ;
// 	//'file_name_remove_index'�ļ�����ȥ���������֮����Ϊ������ǩ;

// HTuple hv_Class_DLDataset;
// HTuple  hv_Class_Propre_TrainingValidationPercent;
// HTuple  hv_Class_Propre_ImagePreprocessFeatures;
// HTuple  hv_Class_Propre_ImageWidth;
// HTuple  hv_Class_Propre_ImageHeight;
// HTuple  hv_Class_Propre_ImageChannels;
// HTuple  hv_Class_Propre_Domainhandling;
// HTuple  hv_Class_Propre_NormalizationType;
// HTuple  hv_Class_Propre_DLDatasetFileName;//ͼ���ֵ�·��;
// HTuple  hv_Class_Propre_DataDirectory;//ͼ���ֵ�;
// HTuple  hv_Class_Propre_PreprocessParamFile;//Ԥ��������ֵ�·��;
// HTuple  hv_Class_Propre_DLPreprocessParam;//Ԥ��������ֵ�;
// HTuple  hv_Class_Propre_Is_overwrite_files;
// HTuple  hv_Class_Propre_LabelSource;
// HTuple  hv_Class_Propre_constant_values_mean_values_normalization;
// HTuple  hv_Class_Propre_constant_values_deviation_values_normalization;

// ����-ѵ������;
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

// ����Ӧ�ó��򡰹��ڡ��˵���� CAboutDlg �Ի���;
class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// �Ի�������;
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��;

// ʵ��;
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


// CMFC_HALCON_DLLDlg �Ի���



CMFC_HALCON_DLLDlg::CMFC_HALCON_DLLDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CMFC_HALCON_DLLDlg::IDD, pParent)
	, CS_data_path(_T("C:\\Users\\Public\\Documents\\MVTec\\HALCON-19.11-Progress\\examples\\images\\food"))
	, CS_save_path(_T("E:/dl/dl-class/classify_fruits_data"))
	, CS_json_path(_T(""))
	, cs_class_pre_calssnamefile(_T(""))//apple_braeburn,apple_golden_delicious,apple_topaz,peach,pear;
	, cs_class_modelfilename(_T("C:/Program Files/MVTec/HALCON-19.11-Progress/dl/pretrained_dl_classifier_compact.hdl"))
	, cs_select_class_modelname(_T("��ѡģ�ͣ�pretrained_dl_classifier_compact.hdl"))
	, cs_select_jsonname(_T("��ѡjson�ļ���"))
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
		GetDlgItem(IDC_STATIC_HALCON_GPU)->SetWindowText(_T("HALCON_GPU�� �޷�ʹ�ã�"));
	}
	else
	{
		hv_UseGPU = 1;
		GetDlgItem(IDC_STATIC_HALCON_GPU)->SetWindowText(_T("HALCON_GPU�� ����ʹ�ã�"));
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
// CMFC_HALCON_DLLDlg ��Ϣ�������

BOOL CMFC_HALCON_DLLDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// ��������...���˵�����ӵ�ϵͳ�˵��С�

	// IDM_ABOUTBOX ������ϵͳ���Χ�ڡ�
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

	// ���ô˶Ի����ͼ�ꡣ  ��Ӧ�ó��������ڲ��ǶԻ���ʱ����ܽ��Զ�
	//  ִ�д˲���
	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		// ����Сͼ��

	m_tab_class.InsertItem(0, "  ����  ");
	m_tab_class.InsertItem(1, "  ���  ");
	m_tab_class.InsertItem(2, "  ��������  ");
	m_tab_class.InsertItem(3, " ����ָ� ");
	m_tab_class.InsertItem(4, " �쳣��� ");

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
	// TODO:  �ڴ���Ӷ���ĳ�ʼ������
	UpdateData(FALSE);



	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
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

// �����Ի��������С����ť������Ҫ����Ĵ���;
//  �����Ƹ�ͼ�ꡣ  ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���;
//  �⽫�ɿ���Զ���ɡ�;

void CMFC_HALCON_DLLDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // ���ڻ��Ƶ��豸������

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// ʹͼ���ڹ����������о���
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// ����ͼ��
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//���û��϶���С������ʱϵͳ���ô˺���ȡ�ù��;
//��ʾ��;

HCURSOR CMFC_HALCON_DLLDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

//��ѵ������·��;
void CMFC_HALCON_DLLDlg::OnBnClickedButton1()//��ѵ������·��
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������;

	UpdateData(TRUE);
// 	TCHAR szFilePath_t[MAX_PATH + 1];
// 
// 	if (szFilePathdata[0] == 0)
// 	{
// 		GetModuleFileName(NULL, szFilePathdata, MAX_PATH);
// 		(_tcsrchr(szFilePathdata, _T('\\')))[1] = 0;//ɾ���ļ�����ֻ���·��
// 	}
// 
// 	CString defaultDir = szFilePathdata;   //Ĭ�ϴ򿪵��ļ�·��;  
// 	CString fileName = _T("");         //Ĭ�ϴ򿪵��ļ���  ;
// 	CString filter = _T("ͼ��(*.jpg;*.bmp;*.hobj)|*.jpg;*.bmp;*.hobj||");   //�ļ����ǵ����� ; ��Ƶ(*.mp4;)|*.mp4|
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
// 		(_tcsrchr(szFilePath_t, _T('\\')))[1] = 0;//ɾ���ļ�����ֻ���·����
// 
// 		for (int i = 0; i < MAX_PATH + 1; i++)
// 		{
// 			if (szFilePath_t[i] != 0)
// 			{
// 				szFilePathdata[i] = szFilePath_t[i];
// 			}
// 		}
// 
// 		(_tcsrchr(szFilePathdata, _T('\\')))[1] = 0;//ɾ���ļ�����ֻ���·��;
// 		strcpy(g_datapath, szFilePathdata);
// 		CS_data_path = g_datapath;
// 	}
// 	else
// 	{
// 		strcpy(g_datapath, CS_data_path.GetBuffer());
// 		//DWORD le0 = CS_data_path.GetLength() * sizeof(TCHAR);
// 	}



	//��·��
	BROWSEINFO bi;
	char Buffer[MAX_PATH] = { 0 };
	//��ʼ����ڲ���bi��ʼ
	bi.hwndOwner = NULL;
	bi.pidlRoot = NULL;
	bi.pszDisplayName = Buffer;//�˲�����ΪNULL������ʾ�Ի���
	bi.lpszTitle = "��·��";
	bi.ulFlags = BIF_EDITBOX;//�����ļ�
	bi.lpfn = NULL;
	bi.iImage = IDR_MAINFRAME;

	LPITEMIDLIST pIDList = SHBrowseForFolder(&bi);//������ʾѡ��Ի���
	if (pIDList)
	{
		SHGetPathFromIDList(pIDList, Buffer);//ȡ���ļ���·����Buffer��
		//SetDlgItemText(IDC_EDIT1, Buffer);
	}
	//hv_ImageBaseFolder = Buffer;// ѵ��ͼ������·��
	CS_data_path = Buffer;
	UpdateData(FALSE);



}

void CMFC_HALCON_DLLDlg::OnBnClickedButtonOpenSavePath()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������;


	UpdateData(TRUE);
	TCHAR szFilePath_t[MAX_PATH + 1];
	
	if (szFilePath[0] == 0)
	{
		GetModuleFileName(NULL, szFilePath, MAX_PATH);
		(_tcsrchr(szFilePath, _T('\\')))[1] = 0;//ɾ���ļ�����ֻ���·��
	}

	CString defaultDir = szFilePath;   //Ĭ�ϴ򿪵��ļ�·��;  
	CString fileName = _T("");         //Ĭ�ϴ򿪵��ļ���  ;
	CString filter = _T("ͼ��(*.jpg;*.bmp;*.hobj)|*.jpg;*.bmp;*.hobj||");   //�ļ����ǵ����� ; ��Ƶ(*.mp4;)|*.mp4|
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
		(_tcsrchr(szFilePath_t, _T('\\')))[1] = 0;//ɾ���ļ�����ֻ���·����

		for (int i = 0; i < MAX_PATH + 1; i++)
		{
			if (szFilePath_t[i] != 0)
			{
				szFilePath[i] = szFilePath_t[i];
			}
		}

		(_tcsrchr(szFilePath, _T('\\')))[1] = 0;//ɾ���ļ�����ֻ���·��;
		strcpy(g_savepath, szFilePath);
		CS_save_path = g_savepath;
	}
	else
	{
		strcpy(g_savepath, CS_save_path.GetBuffer());
		//DWORD le0 = CS_data_path.GetLength() * sizeof(TCHAR);
	}
	
	//(_tcsrchr(g_datapath, _T('\\')))[1] = 0;//ɾ���ļ�����ֻ���·��
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

//�Զ��庯��;
//���-��Ŀ¼�ļ����ƺ���;
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

//�Զ��庯��;
void Get_ReadSaveDir(void* param)
{
	CMFC_HALCON_DLLDlg *Dlg = (CMFC_HALCON_DLLDlg*)param;
	//���ļ�������;
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
			AfxMessageBox("���ļ���Ϊ�գ�");
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

//�Զ��庯��;//����-ѵ������;
void Class_Train_Process(CMFC_HALCON_DLLDlg *dlg)
{

	//������������������ѵ��������������������������;
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

	//��������������������ʾ������������������������;
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
	
	//������Ԥ���������Ԥѵ���������͵���ȷ���ģ�͡�;
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
			// 		HString hs1 = HDevExpDefaultException.ErrorMessage(); //�����ı�
			// 		Herror hs2 = HDevExpDefaultException.ErrorCode(); //�������
			HTuple hv_Exception;
			HDevExpDefaultException.ToHTuple(&hv_Exception);
			CString  s_line = hv_Exception[3].S();
			CString  s_ErrorMessage = hv_Exception[4].S();
			AfxMessageBox(" Error��" + s_ErrorMessage + " Line��" + s_line);
			//int iiii = 0;
			return;
		}
		catch (HTuple &HDevExpDefaultException)
		{
			int i_line = HDevExpDefaultException.I();
			CString  s_ErrorMessage = HDevExpDefaultException[1].S();
			CString s_line;
			s_line.Format(_T("%d"), i_line);
			AfxMessageBox(" Error��" + s_ErrorMessage + " Line��" + s_line);
			return;
		}
	}
	else
	{
		AfxMessageBox("HALCON_GPU �����ã�");
	}
}

//�Զ��庯��;//����-Ԥ������;
void Class_Preprocess(CMFC_HALCON_DLLDlg *dlg)
{

	//CMFC_HALCON_DLLDlg *dlg
	HTuple hv_Exception;

	//----->��ȡͼ�����ݵ�ͼ���ֵ�<-----
	//AfxMessageBox("���Ͻ���--��Ԥ����ͼ�������ֵ䣡");
	try
	{	
		read_dl_dataset_classification_ht(hv_RawImageFolder, Class_Prepro.hv_LabelSource, &(Class_Prepro.hv_Class_DLDataset), \
			&(Class_Prepro.hv_ClassNames), &(Class_Prepro.hv_ClassIDs));
	}
	catch (HException &HDevExpDefaultException)
	{
// 		HString hs = HDevExpDefaultException.ProcName();
// 		HString hs1 = HDevExpDefaultException.ErrorMessage(); //�����ı�
// 		Herror hs2 = HDevExpDefaultException.ErrorCode(); //�������
		HDevExpDefaultException.ToHTuple(&hv_Exception);
		CString  s_line = hv_Exception[3].S();
		CString  s_ErrorMessage = hv_Exception[4].S();
		AfxMessageBox(" Error��" + s_ErrorMessage + " Line��" + s_line);
		//int iiii = 0;
		return;
	}
	catch (HTuple &HDevExpDefaultException)
	{	
		int i_line = HDevExpDefaultException.I();
		CString  s_ErrorMessage = HDevExpDefaultException[1].S();
		CString s_line;
		s_line.Format(_T("%d"), i_line);
		AfxMessageBox(" Error��" + s_ErrorMessage + " Line��" + s_line);
		return;
	}
	//AfxMessageBox("Ԥ����ͼ�������ֵ���ɣ�");

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
	
	//AfxMessageBox("Ԥ����ͼ��ؼ�������ʼ��");
	try
	{
		Classify_Preprocess(Class_Prepro.hv_Class_DLDataset, Class_Prepro.hv_TrainingValidationPercent, Class_Prepro.hv_ImagePreprocessFeatures,
			Class_Prepro.hv_Is_overwrite_files, hv_AllDataSaveDir, hv_WindowHandleimage, &(Class_Prepro.hv_DLDatasetFileName),
			&(Class_Prepro.hv_DataDirectory), &(Class_Prepro.hv_PreprocessParamFile), &(Class_Prepro.hv_DLPreprocessParam));

	}
	catch (HException &HDevExpDefaultException)
	{
		// 		HString hs = HDevExpDefaultException.ProcName();
		// 		HString hs1 = HDevExpDefaultException.ErrorMessage(); //�����ı�
		// 		Herror hs2 = HDevExpDefaultException.ErrorCode(); //�������
		HDevExpDefaultException.ToHTuple(&hv_Exception);
		CString  s_line = hv_Exception[3].S();
		CString  s_ErrorMessage = hv_Exception[4].S();
		AfxMessageBox(" Error��" + s_ErrorMessage + " Line��" + s_line);
		//int iiii = 0;
		return;
	}
	catch (HTuple &HDevExpDefaultException)
	{
		int i_line = HDevExpDefaultException.I();
		CString  s_ErrorMessage = HDevExpDefaultException[1].S();
		CString s_line;
		s_line.Format(_T("%d"), i_line);
		AfxMessageBox(" Error��" + s_ErrorMessage + " Line��" + s_line);
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

	AfxMessageBox("Ԥ����ؼ��������!");
}

//�Զ��庯��;//����-��ʾ����;
void Show_Class_Preprocess()
{
	HTuple hv_WindowHandles;

	hv_WindowHandles.Clear();
	hv_WindowHandles.Append(hv_WindowHandleimage);
	hv_WindowHandles.Append(hv_WindowHandlechild);
	// 
	//AfxMessageBox("�����ʾ10��Ԥ����ѵ������ǩͼ��");

	HTuple hv_SplitSamplesName = "train";
	HTuple hv_SamplesNums = 10;
	HTuple hv_KeysForDisplay = "classification_ground_truth";

	Dev_Display_Class_PreprocesSamples(Class_Prepro.hv_Class_DLDataset, hv_WindowHandles, hv_SplitSamplesName,
		hv_SamplesNums, hv_KeysForDisplay, 1);
}

//Ԥ�����̺߳���;
UINT CMFC_HALCON_DLLDlg::thread_preprocess(void* param)
{
	
	CMFC_HALCON_DLLDlg *dlg = (CMFC_HALCON_DLLDlg*)param;

	if (Thread_Running_Type == 1)//����-Ԥ������;
	{
		Class_Preprocess(dlg);
	}
	else if (Thread_Running_Type == 1001)//�����ʾԤ����ͼ��;
	{
		Show_Class_Preprocess();
	}
	else if (Thread_Running_Type == 2)//����-ѵ��;
	{
		Class_Train_Process(dlg);
	}
	else if (Thread_Running_Type == 3)//����-����;
	{
		;
	}
	else if (Thread_Running_Type == 4)//����-�ƶ�;
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
// 	//������ʵ��ǩ����ͼ�����ݵ��ļ��С�;
// 	hv_RawImageBaseFolder = hv_PathExample + "/images/pill/";
// 	//LabelSource���ڶ�ȡ���ݼ��� 'last_folder'����ļ�����Ϊ������ǩ,'file_name'�ļ�����Ϊ������ǩ,'file_name_remove_index'�ļ�����ȥ���������֮����Ϊ������ǩ;
// 	hv_LabelSource = "last_folder";
// 	HTuple  hv_DLDataset;
// 
// 	HTuple hv_Exception, hv_ErrorCode, hv_CocoFileName, hv_DictCocoJson;
// 	
//	AfxMessageBox("���Ͻ���--��Ԥ����ͼ�������ֵ䣡");

// 	try
// 	{
// 		ReadDict(hv_CocoFileName, HTuple(), HTuple(), &hv_DictCocoJson);
// 	}
// 	catch (HException &HDevExpDefaultException)
// 	{
// 		HString hs = HDevExpDefaultException.ProcName();
// 		HString hs1 = HDevExpDefaultException.ErrorMessage(); //�����ı�
// 		Herror hs2 = HDevExpDefaultException.ErrorCode(); //�������
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
// 		HString hs = except.ProcName(); //ʵ�ʵ�HALCON���ӵ�����
// 		HString hs1 = except.ErrorMessage(); //�����ı�
// 		Herror hs2 = except.ErrorCode(); //�������
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
// 	AfxMessageBox("Ԥ����ͼ�������ֵ���ɣ�");
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
// 	//����ͼ��Ԥ������������� ���� �������ȫ�� ��;
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
// 	//�����ֵ��ֵ��ǲ��Ǹ������±���;
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
		


//	AfxMessageBox("��ʼԤ����ؼ�������");



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
//	AfxMessageBox("Ԥ����ؼ��������!");
// 
// 

// 

//	Thread_Running_Type = 0;

//	return 1;
}


//Ԥ����ť;
void CMFC_HALCON_DLLDlg::OnBnClickedButtonPreprocess()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������

	//HTuple  HV_name = Class_Prepros.hv_ClassNames;
// 	CString SSS = "NIHAO";
// 	HTuple  HV_CS = SSS;
// 	HV_CS[1] = "123";
// 	CString SSS1 = HV_CS.S();
// 	CString SSS2 = HV_CS[1].S();
	UpdateData(TRUE);
	if (Thread_Running_Type >0)
	{
		AfxMessageBox("�������������У�");
		return;
	}
	//thread_running = 1;

	CRect rect, rect2;
	CWnd *pWnd = this->GetDlgItem(IDC_STATIC_PICTURE1);//IDC_pictureΪpicture�ؼ�ID;
	pWnd->GetClientRect(&rect);//rcΪ�ؼ��Ĵ�С��;
	// 	int x = rect.Height();
	// 	int y = rect.Width
	CWnd *pWnd0 = this->GetDlgItem(IDC_STATIC_PICTURE2);//IDC_pictureΪpicture�ؼ�ID;
	pWnd0->GetClientRect(&rect2);//rcΪ�ؼ��Ĵ�С��;

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
// 	//������ʵ��ǩ����ͼ�����ݵ��ļ��С�
// 	hv_RawImageBaseFolder = hv_PathExample + "/images/pill/";
// 	//LabelSource���ڶ�ȡ���ݼ��� 'last_folder'����ļ�����Ϊ������ǩ,'file_name'�ļ�����Ϊ������ǩ,'file_name_remove_index'�ļ�����ȥ���������֮����Ϊ������ǩ;
// 	hv_LabelSource = "last_folder";
// 	HTuple  hv_DLDataset;
// 
// 	//AfxMessageBox("Ԥ����ͼ�������ֵ䣡");
// 	//read_dl_dataset_classification_ht(hv_RawImageBaseFolder, hv_LabelSource, &hv_DLDataset);
// 	//AfxMessageBox("Ԥ����ͼ�������ֵ���ɣ�");
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
// 	//����ͼ��Ԥ������������� ���� �������ȫ�� ��;
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
// 	//�����ֵ��ֵ��ǲ��Ǹ������±���
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
// 	CWnd *pWnd = this->GetDlgItem(IDC_STATIC_PICTURE1);//IDC_pictureΪpicture�ؼ�ID;
// 	pWnd->GetClientRect(&rect);//rcΪ�ؼ��Ĵ�С��;
// 	// 	int x = rect.Height();
// 	// 	int y = rect.Width
// 	CWnd *pWnd0 = this->GetDlgItem(IDC_STATIC_PICTURE2);//IDC_pictureΪpicture�ؼ�ID;
// 	pWnd0->GetClientRect(&rect2);//rcΪ�ؼ��Ĵ�С��;
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
// 	CWnd *pWnd0 = GetDlgItem(IDC_STATIC_PICTURE1);//IDC_pictureΪpicture�ؼ�ID;
// 	pWnd0->GetClientRect(&rect);//rcΪ�ؼ��Ĵ�С��;
// 	HTuple m_HWindowID;
// 	m_HWindowID = (Hlong)pWnd0->m_hWnd;
// 	HTuple hv_WindowHandles, hv_WindowHandleimage, hv_WindowHandlechild, m_ImageWidth, m_ImageHeight;
// 	SetWindowAttr("background_color", "black");
// 	OpenWindow(0, 0, rect.Width(), rect.Height(), m_HWindowID, "visible", "", &hv_WindowHandleimage);
// 	HDevWindowStack::Push(hv_WindowHandleimage);

// 
// 
// 	AfxMessageBox("��ʾ��ʼ");
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
// 	AfxMessageBox("������");

}

//ѡ�
void CMFC_HALCON_DLLDlg::OnTcnSelchangeTabClass(NMHDR *pNMHDR, LRESULT *pResult)
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	//��ǰѡ�е�ѡ��ڼ���;

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


//�����ʾͼ������;
void CMFC_HALCON_DLLDlg::OnBnClickedButtonShowPreprocess()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������;

	if (Thread_Running_Type == 0)
	{
		Thread_Running_Type = 1001;
		m_pWinThreadImage = AfxBeginThread(thread_preprocess, this, THREAD_PRIORITY_NORMAL);
	}
	else
	{
		AfxMessageBox("�н����ڴ����У��Եȣ�");
	}
}

//ָ�����ļ��� ��ѡ�� -��Ӧ�¼�-;
void CMFC_HALCON_DLLDlg::OnBnClickedRadioSpecifiedFile()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������

	if (((CButton *)GetDlgItem(IDC_RADIO_SPECIFIED_FILE))->GetCheck() && cs_class_pre_calssnamefile == "")//
	{
		cs_class_pre_calssnamefile = "apple_braeburn,apple_golden_delicious,apple_topaz,peach,pear";
		
	}
	UpdateData(FALSE);
}

//ָ�����ļ��� �༭�� -��Ӧ�¼�-;
void CMFC_HALCON_DLLDlg::OnEnChangeEditClassFile()
{
	// TODO:  ����ÿؼ��� RICHEDIT �ؼ���������
	// ���ʹ�֪ͨ��������д CDialogEx::OnInitDialog()
	// ���������� CRichEditCtrl().SetEventMask()��
	// ͬʱ�� ENM_CHANGE ��־�������㵽�����С�

	// TODO:  �ڴ���ӿؼ�֪ͨ����������
}

//��ʼ��ģ��·��-��ť�¼�;
void CMFC_HALCON_DLLDlg::OnBnClickedButtonModelSave()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	TCHAR szFilePath_t[MAX_PATH + 1];

	if (szFilePathdata[0] == 0)
	{
		GetModuleFileName(NULL, szFilePathdata, MAX_PATH);
		(_tcsrchr(szFilePathdata, _T('\\')))[1] = 0;//ɾ���ļ�����ֻ���·��
	}

	CString defaultDir = szFilePathdata;   //Ĭ�ϴ򿪵��ļ�·��;  
	CString fileName = _T("��ѡģ�ͣ�pretrained_dl_classifier_compact.hdl");         //Ĭ�ϴ򿪵��ļ���  ;
	CString filter = _T("ģ��(*.hdl)|*.hdl||");   //�ļ����ǵ����� ; ��Ƶ(*.mp4;)|*.mp4|
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
// 		(_tcsrchr(szFilePath_t, _T('\\')))[1] = 0;//ɾ���ļ�����ֻ���·����
// 
// 		for (int i = 0; i < MAX_PATH + 1; i++)
// 		{
// 			if (szFilePath_t[i] != 0)
// 			{
// 				szFilePathdata[i] = szFilePath_t[i];
// 			}
// 		}
// 
// 		(_tcsrchr(szFilePathdata, _T('\\')))[1] = 0;//ɾ���ļ�����ֻ���·��;
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

	cs_select_class_modelname = _T("��ѡģ�ͣ�") + firstFileName;


	UpdateData(FALSE);

}

//��ѡ��-��ѡjson�ļ�-�¼���Ӧ����-;
void CMFC_HALCON_DLLDlg::OnBnClickedRadio2()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������;
	UpdateData(TRUE);
	if (((CButton *)GetDlgItem(IDC_RADIO2))->GetCheck() && CS_json_path == "")//
	{
		CS_json_path = "C:\\Users\\Public\\Documents\\MVTec\\HALCON-19.11-Progress\\examples\\hdevelop\\Deep-Learning\\Detection\\pill_bag.json";
		cs_select_jsonname = _T("��ѡjson�ļ���") + CS_json_path.Right(CS_json_path.GetLength() - CS_json_path.ReverseFind('\\') - 1);
	}
	else if (CS_json_path != "")
	{
		cs_select_jsonname = _T("��ѡjson�ļ���") + CS_json_path.Right(CS_json_path.GetLength() - CS_json_path.ReverseFind('\\') - 1);
	}

	UpdateData(FALSE);
}

//ѡ��json�ļ�;
void CMFC_HALCON_DLLDlg::OnBnClickedButtonOpenJson()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������


	TCHAR szFilePath_t[MAX_PATH + 1];

	if (szFilePathdata[0] == 0)
	{
		GetModuleFileName(NULL, szFilePathdata, MAX_PATH);
		(_tcsrchr(szFilePathdata, _T('\\')))[1] = 0;//ɾ���ļ�����ֻ���·��
	}

	CString defaultDir = szFilePathdata;   //Ĭ�ϴ򿪵��ļ�·��;  
	CString fileName = _T("��ѡjson�ļ���pill_bag.json");         //Ĭ�ϴ򿪵��ļ���  ;
	CString filter = _T("json�ļ�(*.json)|*.json||");   //�ļ����ǵ����� ; ��Ƶ(*.mp4;)|*.mp4|
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

	cs_select_jsonname = _T("��ѡjson�ļ���") + CS_json_path.Right(CS_json_path.GetLength() - CS_json_path.ReverseFind('\\') - 1);

	UpdateData(FALSE);
}

//��ѡjson�ļ��༭���¼���Ӧ����;
void CMFC_HALCON_DLLDlg::OnEnChangeEdit1()
{
	// TODO:  ����ÿؼ��� RICHEDIT �ؼ���������
	// ���ʹ�֪ͨ��������д CDialogEx::OnInitDialog()
	// ���������� CRichEditCtrl().SetEventMask()��
	// ͬʱ�� ENM_CHANGE ��־�������㵽�����С�

	// TODO:  �ڴ���ӿؼ�֪ͨ����������

	UpdateData(TRUE);
	if (CS_json_path != "")
	{
		int i_sx = CS_json_path.ReverseFind('\\');
		int i_dx = CS_json_path.ReverseFind('/');
		if (i_dx > i_sx)
		{
			cs_select_jsonname = _T("��ѡjson�ļ���") + CS_json_path.Right(CS_json_path.GetLength() - CS_json_path.ReverseFind('/') - 1);
		}
		else
		{
			cs_select_jsonname = _T("��ѡjson�ļ���") + CS_json_path.Right(CS_json_path.GetLength() - CS_json_path.ReverseFind('\\') - 1);
		}
		
	}
	UpdateData(FALSE);

}

//��ѡģ���ı����¼���Ӧ����;
void CMFC_HALCON_DLLDlg::OnEnChangeEditModelSave()
{
	// TODO:  ����ÿؼ��� RICHEDIT �ؼ���������
	// ���ʹ�֪ͨ��������д CDialogEx::OnInitDialog();
	// ���������� CRichEditCtrl().SetEventMask();
	// ͬʱ�� ENM_CHANGE ��־�������㵽������;

	// TODO:  �ڴ���ӿؼ�֪ͨ����������;
	UpdateData(TRUE);
	if (cs_class_modelfilename != "")
	{
		int i_sx = cs_class_modelfilename.ReverseFind('\\');
		int i_dx = cs_class_modelfilename.ReverseFind('/');

		if (i_dx>i_sx)
		{
			cs_select_class_modelname = _T("��ѡģ�ͣ�") + cs_class_modelfilename.Right(cs_class_modelfilename.GetLength() - cs_class_modelfilename.ReverseFind('/') - 1);
		}
		else
		{
			cs_select_class_modelname = _T("��ѡģ�ͣ�") + cs_class_modelfilename.Right(cs_class_modelfilename.GetLength() - cs_class_modelfilename.ReverseFind('\\') - 1);
		} 
	}
	UpdateData(FALSE);
}

//ѵ����ť;
void CMFC_HALCON_DLLDlg::OnBnClickedButtonTrain()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������;

	if (Thread_Running_Type == 0)
	{
		Thread_Running_Type = 2;
		m_pWinThreadImage = AfxBeginThread(thread_preprocess, this, THREAD_PRIORITY_NORMAL);
	}
	else
	{
		AfxMessageBox("�н����ڴ����У��Եȣ�");
	}

}
