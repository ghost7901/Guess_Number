// Guess_NumberDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "Guess_Number.h"
#include "Guess_NumberDlg.h"
#include ".\guess_numberdlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// 用于应用程序“关于”菜单项的 CAboutDlg 对话框

class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

// 对话框数据
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

// 实现
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


// CGuess_NumberDlg 对话框



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


// CGuess_NumberDlg 消息处理程序

BOOL CGuess_NumberDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// 将\“关于...\”菜单项添加到系统菜单中。

	// IDM_ABOUTBOX 必须在系统命令范围内。
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

	// 设置此对话框的图标。当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO: 在此添加额外的初始化代码
	//-------------------------------------------------------------
	#ifndef  NDEBUG
     AllocConsole();                  //创建Console窗口
     freopen( "CONOUT$", "a", stdout ); //使标准输出导向Console窗口
	#endif
	//-------------------------------------------------------------

	 printf( "Start!\n" );

	
	return TRUE;  // 除非设置了控件的焦点，否则返回 TRUE
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

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CGuess_NumberDlg::OnPaint() 
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作矩形中居中
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
		CDialog::OnPaint();
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标显示。
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
	sprintf(s,"范围：（%ld-%ld）",m_dwBegin,m_dwEnd);
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
		MessageBox("恭喜您！答对了！");
	else
	{
		char s[100];
		sprintf(s,"%ld：猜对了%ld个数字，数字和数位都对的有%ld个；",m_dwEdit,same1,same2);
		m_InfoList.InsertString(-1,s);
		m_InfoList.SetCurSel(m_InfoList.GetCount()-1);

		CEdit *edt=(CEdit *)GetDlgItem(IDC_EDIT);
		edt->SetFocus();
		edt->SetSel(1000);
	}	
	//OnOK();
}