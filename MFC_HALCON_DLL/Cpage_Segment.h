#pragma once


// Cpage_Segment �Ի���

class Cpage_Segment : public CDialogEx
{
	DECLARE_DYNAMIC(Cpage_Segment)

public:
	Cpage_Segment(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~Cpage_Segment();

// �Ի�������
	enum { IDD = IDD_DIALOG_SEGMENT };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
};
