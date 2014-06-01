
// MFCApplication1Dlg.h : файл заголовка
//

#pragma once
#include "stdafx.h"
#include "afxwin.h"
#include "afxcmn.h"


using namespace std;
// диалоговое окно CMFCApplication1Dlg
class CMFCApplication1Dlg : public CDialogEx
{
// Создание
public:
	CMFCApplication1Dlg(CWnd* pParent = NULL);	// стандартный конструктор

// Данные диалогового окна
	enum { IDD = IDD_MFCAPPLICATION1_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// поддержка DDX/DDV


// Реализация
protected:
	HICON m_hIcon;

	// Созданные функции схемы сообщений
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	CListCtrl StreetListView;
	CListCtrl BuildingListView;
	CListCtrl MensListView;
	CButton Add_Btn;
	CButton BuldingAddBtn;
	CEdit NameInput;
	CEdit BNumberInput;
	CEdit BInhabsInput;
	CEdit BFloorInput;
	CEdit cEditSurname;
	CEdit cEditName;
	CEdit CEditYear;

	void CMFCApplication1Dlg::ClearStreetInput();
	void CMFCApplication1Dlg::ClearBuildingInput();
	afx_msg void OnBnClickedAddBtn();

	afx_msg void OnNMClickStreetView(NMHDR *pNMHDR, LRESULT *pResult);

	afx_msg void OnNMKillfocusList1(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnBuildAddBtnClicked();

	afx_msg void OnNMClickBuildingList(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnNMKillfocusBList(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnSaveBtn();
	afx_msg void OnOpen();
	afx_msg void OnBnClickedStrsavebtn();
	afx_msg void OnBnClickedBsavebtn();
	afx_msg void OnAbout();
	afx_msg void OnLvnKeydownBListVie(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnLvnKeydownStreetListView(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnSearch();
	
	afx_msg void OnLvnKeydownMensList(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnNMClickMensList(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnNMKillfocusMensList(NMHDR *pNMHDR, LRESULT *pResult);
	
};