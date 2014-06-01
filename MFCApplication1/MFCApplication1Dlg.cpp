
// MFCApplication1Dlg.cpp : файл реализации
//

#include "stdafx.h"
#include "MFCApplication1Dlg.h"
#include "afxwin.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#endif


list<Street> Global;

// Диалоговое окно CAboutDlg используется для описания сведений о приложении

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

	// Данные диалогового окна
	enum { IDD = IDD_ABOUTBOX };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // поддержка DDX/DDV

	// Реализация
protected:
	DECLARE_MESSAGE_MAP()
};

class CSearchDlg: public CDialogEx
{
public:
	CSearchDlg();

	enum{ IDD = IDD_DIALOG1};
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // поддержка DDX/DDV

	// Реализация
protected:
	DECLARE_MESSAGE_MAP()
public:
	CEdit StreetName;
	CEdit BuildingName;
	CListCtrl* StreetList, *BuildingList;
	afx_msg void OnBnClickedSearch_OK();
};

CAboutDlg::CAboutDlg() : CDialogEx(CAboutDlg::IDD)
{
}

CSearchDlg::CSearchDlg(): CDialogEx(CSearchDlg::IDD)
{
}


void CSearchDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT1, StreetName);
	DDX_Control(pDX, IDC_EDIT2, BuildingName);
}
void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()

BEGIN_MESSAGE_MAP(CSearchDlg, CDialogEx)
	ON_BN_CLICKED(IDOK, &CSearchDlg::OnBnClickedSearch_OK)
END_MESSAGE_MAP()


// диалоговое окно CMFCApplication1Dlg



CMFCApplication1Dlg::CMFCApplication1Dlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CMFCApplication1Dlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMFCApplication1Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST1, StreetListView);
	DDX_Control(pDX, IDC_LIST2, BuildingListView);
	DDX_Control(pDX, IDC_LIST1, StreetListView);
	DDX_Control(pDX, IDC_LIST2, BuildingListView);
	DDX_Control(pDX, IDC_ADD_BTN, Add_Btn);
	DDX_Control(pDX, IDC_EDIT1, NameInput);
	//DDX_Control(pDX, IDC_EDIT2, BuildingAmountInput);
	//DDX_Control(pDX, IDC_EDIT3, TotalFeeAmountInput);
	DDX_Control(pDX, IDC_BUTTON1, BuldingAddBtn);
	DDX_Control(pDX, IDC_EDIT4, BNumberInput);
	DDX_Control(pDX, IDC_EDIT5, BInhabsInput);
	DDX_Control(pDX, IDC_EDIT6, BFloorInput);
	//DDX_Control(pDX, IDC_EDIT7, BFeeInput);
	DDX_Control(pDX, IDC_LIST4, MensListView);
	DDX_Control(pDX, IDC_EDIT_SURNAME, cEditSurname);
	DDX_Control(pDX, IDC_EDIT_NAME, cEditName);
	DDX_Control(pDX, IDC_EDIT_BIRTH_YEAR, CEditYear);
}

BEGIN_MESSAGE_MAP(CMFCApplication1Dlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_ADD_BTN, &CMFCApplication1Dlg::OnBnClickedAddBtn)
	ON_NOTIFY(NM_CLICK, IDC_LIST1, &CMFCApplication1Dlg::OnNMClickStreetView)
	ON_NOTIFY(NM_KILLFOCUS, IDC_LIST1, &CMFCApplication1Dlg::OnNMKillfocusList1)
	ON_BN_CLICKED(IDC_BUTTON1, &CMFCApplication1Dlg::OnBuildAddBtnClicked)
	ON_NOTIFY(NM_CLICK, IDC_LIST2, &CMFCApplication1Dlg::OnNMClickBuildingList)
	ON_NOTIFY(NM_KILLFOCUS, IDC_LIST2, &CMFCApplication1Dlg::OnNMKillfocusBList)
	ON_COMMAND(ID_32772, &CMFCApplication1Dlg::OnSaveBtn)
	ON_COMMAND(ID_32773, &CMFCApplication1Dlg::OnOpen)
	ON_BN_CLICKED(IDC_BSaveBtn, &CMFCApplication1Dlg::OnBnClickedBsavebtn)
	ON_COMMAND(ID_About, &CMFCApplication1Dlg::OnAbout) 
	ON_NOTIFY(LVN_KEYDOWN, IDC_LIST2, &CMFCApplication1Dlg::OnLvnKeydownBListVie)
	ON_NOTIFY(LVN_KEYDOWN, IDC_LIST1, &CMFCApplication1Dlg::OnLvnKeydownStreetListView)
	ON_COMMAND(ID_Search, &CMFCApplication1Dlg::OnSearch)
	ON_NOTIFY(LVN_KEYDOWN, IDC_LIST4, &CMFCApplication1Dlg::OnLvnKeydownMensList)
	ON_NOTIFY(NM_CLICK, IDC_LIST4, &CMFCApplication1Dlg::OnNMClickMensList)
	ON_NOTIFY(NM_KILLFOCUS, IDC_LIST4, &CMFCApplication1Dlg::OnNMKillfocusMensList)
END_MESSAGE_MAP()


// обработчики сообщений CMFCApplication1Dlg

BOOL CMFCApplication1Dlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	CRect rect;
	StreetListView.GetClientRect(&rect);
	int nColInterval = rect.Width();

	StreetListView.SetExtendedStyle(LVS_EX_FULLROWSELECT | LVS_SHOWSELALWAYS);

	StreetListView.InsertColumn(0, _T("Улица"), LVCFMT_LEFT, nColInterval);

	BuildingListView.SetExtendedStyle(LVS_EX_FULLROWSELECT);

	BuildingListView.InsertColumn(0, _T("Дом №"), LVCFMT_LEFT, nColInterval/3);
	BuildingListView.InsertColumn(1, _T("Жильцов"), LVCFMT_LEFT, nColInterval/3);
	BuildingListView.InsertColumn(2, _T("Этажей"), LVCFMT_LEFT, nColInterval/3);

	MensListView.SetExtendedStyle(LVS_EX_FULLROWSELECT);

	MensListView.InsertColumn(0, _T("Фамилия"), LVCFMT_LEFT, nColInterval/3);
	MensListView.InsertColumn(1, _T("Имя"), LVCFMT_LEFT, nColInterval/3);
	MensListView.InsertColumn(2, _T("Год рождения"), LVCFMT_LEFT, nColInterval/3);


	// Добавление пункта "О программе..." в системное меню.

	// IDM_ABOUTBOX должен быть в пределах системной команды.
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
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, L"О программе");
		}
	}

	// Задает значок для этого диалогового окна. Среда делает это автоматически,
	//  если главное окно приложения не является диалоговым
	SetIcon(m_hIcon, TRUE);			// Крупный значок
	SetIcon(m_hIcon, FALSE);		// Мелкий значок

	// TODO: добавьте дополнительную инициализацию

	return TRUE;  // возврат значения TRUE, если фокус не передан элементу управления
}

void CMFCApplication1Dlg::OnSysCommand(UINT nID, LPARAM lParam)
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

// При добавлении кнопки свертывания в диалоговое окно нужно воспользоваться приведенным ниже кодом,
//  чтобы нарисовать значок. Для приложений MFC, использующих модель документов или представлений,
//  это автоматически выполняется рабочей областью.

void CMFCApplication1Dlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // контекст устройства для рисования

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Выравнивание значка по центру клиентского прямоугольника
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Нарисуйте значок
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// Система вызывает эту функцию для получения отображения курсора при перемещении
//  свернутого окна.
HCURSOR CMFCApplication1Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


bool LookFor  


void CMFCApplication1Dlg::OnBnClickedAddBtn()
{
	CString Name, BuildingAmount, TotalFee;
	NameInput.GetWindowText(Name);
	if(Name.IsEmpty()) 
	{
		MessageBox(_T("Street name can't be empty"), _T("Error"), 
			MB_ICONERROR | MB_OK);
		return;
	}

	if(Global.(Name))
	{
		MessageBox(_T("There's already the same street"), _T("Error"), 
			MB_ICONERROR | MB_OK);
		return;
	}

	 
	int nIndex = StreetListView.InsertItem(Global.GetListSize(), Name);



	StreetListView.SetItemText(nIndex, 1, L"0");


	Global.AddContent(Name);

	NameInput.SetSel(0, -1);
	NameInput.Clear();

}




void CMFCApplication1Dlg::OnNMClickStreetView(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMITEMACTIVATE pNMItemActivate = reinterpret_cast<LPNMITEMACTIVATE>(pNMHDR);
	*pResult = 0;


	BuildingListView.DeleteAllItems();
	int row = StreetListView.GetSelectionMark();
	if(row < 0)
		return;

	CString Name = StreetListView.GetItemText(row, 0);
	CString BuildingAmount = StreetListView.GetItemText(row, 1);
	CString TotalFee = StreetListView.GetItemText(row, 2);
	CString FloorCount, InhabsCount, FeeAmount;


	Street* Str = Global.GetContent(row);

	int BSize = Str->GetListSize();

	this->ClearStreetInput();
	this->ClearBuildingInput();
	NameInput.SetWindowTextW(Name);


	if (!BSize)
		return;
	else
	{
		//Building* Build = Str->GetBuilding(0);

		for (int i =0; i < BSize; i++)
		{
			InhabsCount.Format(L"%d", Str->GetBuilding(i)->GetInhabsCount());
			FloorCount.Format(L"%d", Str->GetBuilding(i)->GetFloorCount());
			BuildingListView.InsertItem(i, Str->GetBuilding(i)->GetBuildingNumber());
			BuildingListView.SetItemText(i, 1, InhabsCount);
			BuildingListView.SetItemText(i, 2, FloorCount);

		}
	}

	*pResult = 0;
}





void CMFCApplication1Dlg::OnNMKillfocusList1(NMHDR *pNMHDR, LRESULT *pResult)
{

	NameInput.SetSel(0, -1);
	NameInput.Clear();
	//
	//BuildingAmountInput.SetSel(0, -1);
	//BuildingAmountInput.Clear();
	//
	//TotalFeeAmountInput.SetSel(0, -1);
	//TotalFeeAmountInput.Clear();


	*pResult = 0;
}




void CMFCApplication1Dlg::OnBuildAddBtnClicked()
{
	CString BNumber, InhabsCount, FloorCount, FeeAmount;

	int CurrentStreetIndex = StreetListView.GetSelectionMark();
	int CurrentBuildingIndex = BuildingListView.GetSelectionMark();



	if(CurrentStreetIndex == -1) 
	{
		MessageBox(_T("First of all choose a street"), _T("Error"), 
			MB_ICONERROR | MB_OK);
		return;

	}
	Street* Str = Global.GetContent(CurrentStreetIndex);


	BNumberInput.GetWindowText(BNumber);

	if(Str->HasBuilding(BNumber))
	{
		MessageBox(_T("The street already contains that building"), _T("Error"), 
			MB_ICONERROR | MB_OK);
		return;
	}

	BInhabsInput.GetWindowText(InhabsCount);
	BFloorInput.GetWindowText(FloorCount);

	if (BNumber.IsEmpty()|FloorCount.IsEmpty()|InhabsCount.IsEmpty()|FeeAmount.IsEmpty())
	{
		MessageBox(_T("One or more fields are empty"), _T("Error"), 
			MB_ICONERROR | MB_OK);
		return;
	}

	int nIndex = BuildingListView.InsertItem(Str->GetListSize(), BNumber);
	BuildingListView.SetItemText(nIndex, 1, InhabsCount);
	BuildingListView.SetItemText(nIndex, 2, FloorCount);
	BuildingListView.SetItemText(nIndex, 3, FeeAmount);


	Building B(BNumber, 0, _wtoi(FloorCount), _wtoi(InhabsCount), _wtof(FeeAmount));
	Str->AddBuilding(B);


	CString s;
	s.Format(L"%d", Str->GetListSize());
	StreetListView.SetItemText(CurrentStreetIndex, 1, s);
	s.Format(L"%.2lf", Str->GetTotalFee());
	StreetListView.SetItemText(CurrentStreetIndex, 2, s);

	//Street* Check = Global.GetContent(CurrentStreetIndex);

	this->ClearBuildingInput();

}


void CMFCApplication1Dlg::ClearStreetInput()
{
	NameInput.SetSel(0, -1);
	NameInput.Clear();

}

void CMFCApplication1Dlg::ClearBuildingInput()
{
	BNumberInput.SetSel(0, -1);
	BNumberInput.Clear();

	BInhabsInput.SetSel(0, -1);
	BInhabsInput.Clear();

	BFloorInput.SetSel(0, -1);
	BFloorInput.Clear();

}

void CMFCApplication1Dlg::OnNMClickBuildingList(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMITEMACTIVATE pNMItemActivate = reinterpret_cast<LPNMITEMACTIVATE>(pNMHDR);

	int row = BuildingListView.GetSelectionMark();
	int CurrentStreetIndex = StreetListView.GetSelectionMark();
	if(row < 0)
	{
		return;
	}

	CString BNumber = BuildingListView.GetItemText(row, 0);
	CString InhabsCount = BuildingListView.GetItemText(row, 1);
	CString FloorCount = BuildingListView.GetItemText(row, 2);
	CString TotalFee = BuildingListView.GetItemText(row, 3);

	BNumberInput.SetWindowTextW(BNumber);
	BInhabsInput.SetWindowTextW(InhabsCount);
	BFloorInput.SetWindowTextW(FloorCount);

	*pResult = 0;
}


void CMFCApplication1Dlg::OnNMKillfocusBList(NMHDR *pNMHDR, LRESULT *pResult)
{
	//if( (HWND)pResult == BNumberInput.GetHandle() | pResult == BInhabsInput.GetHandle()
	//	| pResult == BFloorInput.GetHandle() | pResult ==  BFeeInput.GetHandle())
	//	return;
	//ClearBuildingInput();
	*pResult = 0;
}


void CMFCApplication1Dlg::OnSaveBtn()
{
	// TODO: добавьте свой код обработчика команд
	char strFilter[] = { "Text Files (*.txt)|*.txt|" }; 


	_wsetlocale(LC_CTYPE , _T("rus")); //Для записи юникодовских символов
	CFileDialog FileDlg(FALSE, CString(".txt"), NULL, OFN_HIDEREADONLY | OFN_OVERWRITEPROMPT, CString(strFilter));

	if (FileDlg.DoModal() == IDOK)  
	{  
		CStdioFile File;


		File.Open(FileDlg.GetPathName(), CFile::modeCreate | CFile::modeWrite);

		for (int i = 0; i< Global.GetListSize(); i++)
		{
			Street* CurStr = Global.GetContent(i);
			int b = Global.GetListSize();
			CString StrName = CurStr->GetName();
			CString BCount;
			int CurBCount = CurStr->GetListSize();
			BCount.Format(L"%d", CurBCount);

			CString StrFeeAmount;
			StrFeeAmount.Format(L"%.2lf", CurStr->GetTotalFee());

			File.WriteString(L"Street::\n");
			File.WriteString(StrName+"\n");
			//File.WriteString(BCount);
			//File.WriteString(StrFeeAmount);

			for (int k =0; k < CurBCount; k++)
			{			
				Building* CurB = CurStr->GetBuilding(k);
				CString s = CurB->GetBuildingNumber();

				File.WriteString(L"Building::\n");
				File.WriteString(s+"\n");
				s.Format(L"%d", CurB->GetInhabsCount());
				File.WriteString(s+"\n");
				s.Format(L"%d", CurB->GetFloorCount());
				File.WriteString(s+"\n");
				s.Format(L"%.2lf", CurB->GetFeeAmount());
				File.WriteString(s+"\n");

			}
		}

		AfxGetMainWnd()->SetFocus();
	}
}


void CMFCApplication1Dlg::OnOpen()
{
	_wsetlocale(LC_CTYPE , _T("rus"));
	char strFilter[] = { "Text Files (*.txt)|*.txt|" };
	CFileDialog fileDialog(TRUE,NULL,CString(".txt"),NULL, CString(strFilter));


	if(fileDialog.DoModal() == IDOK)
	{
		CStdioFile File;
		CString s;
		StreetListView.DeleteAllItems();
		BuildingListView.DeleteAllItems();
		Global.Clear();

		File.Open(fileDialog.GetPathName(),CFile::modeReadWrite);

		File.ReadString(s);
		while(s!="")
		{
			if(s=="Street::")
			{
				File.ReadString(s);
				Global.AddContent(s);
				File.ReadString(s);
			}
			if(s=="Building::")
			{
				//int i=0;
				Building B;
				File.ReadString(s);
				CString BNumber = s;
				//BuildingListView.InsertItem(i, BNumber);

				File.ReadString(s);
				//BuildingListView.SetItemText(i, 1, s);
				int InhabsCount = _wtoi(s);

				File.ReadString(s);
				//BuildingListView.SetItemText(i, 2, s);
				int FloorCount = _wtoi(s);

				File.ReadString(s);
				//BuildingListView.SetItemText(i, 3, s);
				double FeeAmount = _wtof(s);

				B.SetBuildingParams(BNumber, 0, FloorCount, InhabsCount, FeeAmount);
				Global.GetContent(Global.GetListSize()-1)->AddBuilding(B);
				File.ReadString(s);

			}
		}

		for( int i=0; i<Global.GetListSize(); i++)
		{
			//if (Global.GetListSize())
			//{
			//int index = Global.GetListSize();
			Street* CurStr = Global.GetContent(i);
			CString s;
			int index = StreetListView.InsertItem(i, CurStr->GetName());	

			s.Format(L"%d", CurStr->GetListSize());
			StreetListView.SetItemText(index, 1, s);

			s.Format(L"%.2lf", CurStr->GetTotalFee());
			StreetListView.SetItemText(index, 2, s);

			//}

		}

	}


}




void CMFCApplication1Dlg::OnBnClickedBsavebtn()
{

	CString BNumber, InhabsCount, FloorCount, FeeAmount;

	int CurrentStreetIndex = StreetListView.GetSelectionMark();
	int CurrentBuildingIndex = BuildingListView.GetSelectionMark();



	if(CurrentBuildingIndex == -1) 
	{
		MessageBox(_T("Nothing to edit"), _T("Error"), 
			MB_ICONERROR | MB_OK);
		return;

	}
	Street* Str = Global.GetContent(CurrentStreetIndex);



	Home* B = Str->GetBuilding(CurrentBuildingIndex);
	BNumberInput.GetWindowText(BNumber);
	BInhabsInput.GetWindowText(InhabsCount);
	BFloorInput.GetWindowText(FloorCount);

	BuildingListView.SetItemText(CurrentBuildingIndex, 0, BNumber);
	BuildingListView.SetItemText(CurrentBuildingIndex, 1, InhabsCount);

	BuildingListView.SetItemText(CurrentBuildingIndex, 2, FloorCount);

	BuildingListView.SetItemText(CurrentBuildingIndex, 3, FeeAmount);


	B->SetBuildingParams(BNumber, 0, _wtoi(FloorCount), _wtoi(InhabsCount), _wtof(FeeAmount));
	Str->UpdateTotalFee();
	CString s;
	s.Format(L"%.2lf", Str->GetTotalFee());
	StreetListView.SetItemText(CurrentStreetIndex, 2, s);

	//TotalFeeAmountInput.SetWindowTextW(s);
}


void CMFCApplication1Dlg::OnAbout()
{
	CAboutDlg dlgAbout;
	dlgAbout.DoModal();
}


void CMFCApplication1Dlg::OnLvnKeydownBListVie(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMLVKEYDOWN pLVKeyDow = reinterpret_cast<LPNMLVKEYDOWN>(pNMHDR);
	CString BNumber, s;

	int CurrentStreetIndex = StreetListView.GetSelectionMark();
	int CurrentBuildingIndex = BuildingListView.GetSelectionMark();

	BNumber = BuildingListView.GetItemText(CurrentBuildingIndex, 0);
	s.Format(L"%d", Global.GetContent(CurrentStreetIndex)->GetListSize()-1);

	//	LV_KEYDOWN* pLVKeyDow = (LV_KEYDOWN*)pNMHDR;

	// TODO
	if ( pLVKeyDow->wVKey == VK_BACK)
	{
		Global.GetContent(CurrentStreetIndex)->DeleteKeyBuilding(BNumber, 0);
		BuildingListView.DeleteItem(CurrentBuildingIndex);

		StreetListView.SetItemText(CurrentStreetIndex, 1, s);
		//BuildingAmountInput.SetWindowTextW(s);

		s.Format(L"%.2lf", Global.GetContent(CurrentStreetIndex)->GetTotalFee());
		// TotalFeeAmountInput.SetWindowTextW(s);
		StreetListView.SetItemText(CurrentStreetIndex, 2, s);

	}

	*pResult = 0;
}


void CMFCApplication1Dlg::OnLvnKeydownStreetListView(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMLVKEYDOWN pLVKeyDow = reinterpret_cast<LPNMLVKEYDOWN>(pNMHDR);
	int CurrentStreetIndex = StreetListView.GetSelectionMark();
	int CurrentBuildingIndex = BuildingListView.GetSelectionMark();


	if ( pLVKeyDow->wVKey == VK_BACK)
	{
		Global.DeleteKeyUnit(Global.GetContent(CurrentStreetIndex)->GetName());
		StreetListView.DeleteItem(CurrentStreetIndex);
		BuildingListView.DeleteAllItems();

	}

	*pResult = 0;
}


void CMFCApplication1Dlg::OnSearch()
{
	CSearchDlg Dlg;
	Dlg.DoModal();
}

void CSearchDlg::OnBnClickedSearch_OK()
{
	// TODO: добавьте свой код обработчика уведомлений
	CString StrName, BName;
	CMFCApplication1Dlg* pParent = &(CMFCApplication1Dlg)GetParent();
	//CMFCApplication1Dlg pParent = static_cast<CMFCApplication1Dlg>(GetParent());


	StreetName.GetWindowTextW(StrName);
	BuildingName.GetWindowTextW(BName);
	int CurrentStreetIndex = pParent->StreetListView.GetSelectionMark();
	int CurrentBuildingIndex = BuildingList->GetSelectionMark();

	Street* CurStr = Global.GetContent(CurrentStreetIndex);

	int nRow = Global.FindUnit(StrName);

	pParent->StreetListView.SetSelectionMark(nRow);


		CDialogEx::OnOK();
}


void CMFCApplication1Dlg::OnLvnKeydownMensList(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMLVKEYDOWN pLVKeyDow = reinterpret_cast<LPNMLVKEYDOWN>(pNMHDR);
	// TODO: добавьте свой код обработчика уведомлений
	*pResult = 0;
}


void CMFCApplication1Dlg::OnNMClickMensList(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMITEMACTIVATE pNMItemActivate = reinterpret_cast<LPNMITEMACTIVATE>(pNMHDR);
	// TODO: добавьте свой код обработчика уведомлений
	*pResult = 0;
}


void CMFCApplication1Dlg::OnNMKillfocusMensList(NMHDR *pNMHDR, LRESULT *pResult)
{
	// TODO: добавьте свой код обработчика уведомлений
	*pResult = 0;
}
