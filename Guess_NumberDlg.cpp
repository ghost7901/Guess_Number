// Guess_NumberDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "Guess_Number.h"
#include "Guess_NumberDlg.h"
#include ".\guess_numberdlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// ����Ӧ�ó��򡰹��ڡ��˵���� CAboutDlg �Ի���

class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

// �Ի�������
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

// ʵ��
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
END_MESSAGE_MAP()


// CGuess_NumberDlg �Ի���



CGuess_NumberDlg::CGuess_NumberDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CGuess_NumberDlg::IDD, pParent)
	, m_dwBegin(0)
	, m_dwEnd(100)
	, m_dwEdit(0)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CGuess_NumberDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_BEGIN, m_dwBegin);
	DDX_Text(pDX, IDC_END, m_dwEnd);
	DDX_Text(pDX, IDC_EDIT, m_dwEdit);
	DDX_Control(pDX, IDC_INFOLIST, m_InfoList);
}

BEGIN_MESSAGE_MAP(CGuess_NumberDlg, CDialog)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	//}}AFX_MSG_MAP
	ON_BN_CLICKED(IDC_ANSWER, OnBnClickedAnswer)
	ON_BN_CLICKED(IDC_INIT, OnBnClickedInit)
	ON_BN_CLICKED(IDOK, OnBnClickedOk)
END_MESSAGE_MAP()


// CGuess_NumberDlg ��Ϣ�������

BOOL CGuess_NumberDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// ��\������...\���˵�����ӵ�ϵͳ�˵��С�

	// IDM_ABOUTBOX ������ϵͳ���Χ�ڡ�
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		CString strAboutMenu;
		strAboutMenu.LoadString(IDS_ABOUTBOX);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// ���ô˶Ի����ͼ�ꡣ��Ӧ�ó��������ڲ��ǶԻ���ʱ����ܽ��Զ�
	//  ִ�д˲���
	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		// ����Сͼ��

	// TODO: �ڴ���Ӷ���ĳ�ʼ������
	//-------------------------------------------------------------
	#ifndef  NDEBUG
     AllocConsole();                  //����Console����
     freopen( "CONOUT$", "a", stdout ); //ʹ��׼�������Console����
	#endif
	//-------------------------------------------------------------

	 printf( "Start!\n" );

	
	return TRUE;  // ���������˿ؼ��Ľ��㣬���򷵻� TRUE
}

void CGuess_NumberDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialog::OnSysCommand(nID, lParam);
	}
}

// �����Ի��������С����ť������Ҫ����Ĵ���
//  �����Ƹ�ͼ�ꡣ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void CGuess_NumberDlg::OnPaint() 
{
	if (IsIconic())
	{
		CPaintDC dc(this); // ���ڻ��Ƶ��豸������

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// ʹͼ���ڹ��������о���
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
		CDialog::OnPaint();
	}
}

//���û��϶���С������ʱϵͳ���ô˺���ȡ�ù����ʾ��
HCURSOR CGuess_NumberDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

void CGuess_NumberDlg::OnBnClickedAnswer()
{
	DWORD ans=m_Guess.GetAnswer();
	char s[100];
	sprintf(s,"%ld",ans);
	MessageBox(s);

	CEdit *edt=(CEdit *)GetDlgItem(IDC_EDIT);
	edt->EnableWindow(false);

	CButton *btn=(CButton *)GetDlgItem(IDOK);
	btn->EnableWindow(false);

	btn=(CButton *)GetDlgItem(IDC_ANSWER);
	btn->EnableWindow(false);
}

void CGuess_NumberDlg::OnBnClickedInit()
{
	UpdateData();
	m_Guess.Init(m_dwBegin,m_dwEnd);
	char s[100];
	sprintf(s,"��Χ����%ld-%ld��",m_dwBegin,m_dwEnd);
	MessageBox(s);

	CEdit *edt=(CEdit *)GetDlgItem(IDC_EDIT);
	edt->EnableWindow(true);
	edt->SetFocus();
	edt->SetSel(1000);

	CButton *btn=(CButton *)GetDlgItem(IDOK);
	btn->EnableWindow(true);

	btn=(CButton *)GetDlgItem(IDC_ANSWER);
	btn->EnableWindow(true);

	m_InfoList.ResetContent();
}

void CGuess_NumberDlg::OnBnClickedOk()
{
	UpdateData();
	int same1,same2;
	bool bOK=m_Guess.Compare(m_dwEdit,same1,same2);
	if(bOK)
		MessageBox("��ϲ��������ˣ�");
	else
	{
		char s[100];
		sprintf(s,"%ld���¶���%ld�����֣����ֺ���λ���Ե���%ld����",m_dwEdit,same1,same2);
		m_InfoList.InsertString(-1,s);
		m_InfoList.SetCurSel(m_InfoList.GetCount()-1);

		CEdit *edt=(CEdit *)GetDlgItem(IDC_EDIT);
		edt->SetFocus();
		edt->SetSel(1000);
	}	
	//OnOK();
}