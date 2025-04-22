
// MFC_HALCON_DLLDlg.h : 头文件
//

#pragma once
#include "afxcmn.h"

#include "Cpage_Class.h"
#include "Cpage_Detect.h"
#include "Cpage_Detect_Orienta.h"
#include "Cpage_Segment.h"
#include "Cpage_Anomaly.h"
#include "afxwin.h"

// CMFC_HALCON_DLLDlg 对话框
class CMFC_HALCON_DLLDlg : public CDialogEx
{
// 构造
public:
	CMFC_HALCON_DLLDlg(CWnd* pParent = NULL);	// 标准构造函数

// 对话框数据
	enum { IDD = IDD_MFC_HALCON_DLL_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持

	static UINT thread_preprocess(void *param);//视频线程;
// 实现
protected:
	HICON m_hIcon;

	Cpage_Class  m_page_class;
	Cpage_Detect m_page_detect;
	Cpage_Detect_Orienta m_page_detect_orienta;
	Cpage_Segment m_page_segment;
	Cpage_Anomaly m_page_anomaly;

	// 生成的消息映射函数
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	CString CS_data_path;
	CString CS_save_path;
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButtonOpenSavePath();
	afx_msg void OnBnClickedButtonPreprocess();
	CTabCtrl m_tab_class;
	afx_msg void OnTcnSelchangeTabClass(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnBnClickedButtonShowPreprocess();
	CString CS_json_path;

// 	
// 	CButton m_check_all_file;
// 	CButton m_check_spec_file;
	CButton m_radio_all_file;
	CString cs_class_pre_calssnamefile;
	afx_msg void OnBnClickedRadioSpecifiedFile();
	afx_msg void OnBnClickedButtonModelSave();
	CString cs_class_modelfilename;
	CString cs_select_class_modelname;
	afx_msg void OnBnClickedRadio2();
	//afx_msg void OnEnChangeEditSavePath();
	CString cs_select_jsonname;
	afx_msg void OnBnClickedButtonOpenJson();
	afx_msg void OnEnChangeEdit1();
	afx_msg void OnEnChangeEditModelSave();
	afx_msg void OnEnChangeEditClassFile();
	CString cs_class_prepro_DLDatasetFileName;
	CString cs_class_prepro_PreprocessDirect;
	afx_msg void OnBnClickedButtonTrain();
};
