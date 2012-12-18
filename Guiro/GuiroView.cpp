// This MFC Samples source code demonstrates using MFC Microsoft Office Fluent User Interface 
// (the "Fluent UI") and is provided only as referential material to supplement the 
// Microsoft Foundation Classes Reference and related electronic documentation 
// included with the MFC C++ library software.  
// License terms to copy, use or distribute the Fluent UI are available separately.  
// To learn more about our Fluent UI licensing program, please visit 
// http://msdn.microsoft.com/officeui.
//
// Copyright (C) Microsoft Corporation
// All rights reserved.

// GuiroView.cpp : implementation of the CGuiroView class
//

#include "stdafx.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "Guiro.h"
#endif

#include "GuiroDoc.h"
#include "GuiroView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CGuiroView

IMPLEMENT_DYNCREATE(CGuiroView, CView)

BEGIN_MESSAGE_MAP(CGuiroView, CView)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
END_MESSAGE_MAP()

// CGuiroView construction/destruction

CGuiroView::CGuiroView()
{
	// TODO: add construction code here

}

CGuiroView::~CGuiroView()
{
}

BOOL CGuiroView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

// CGuiroView drawing

void CGuiroView::OnDraw(CDC* /*pDC*/)
{
	CGuiroDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: add draw code for native data here
}

void CGuiroView::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CGuiroView::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CGuiroView diagnostics

#ifdef _DEBUG
void CGuiroView::AssertValid() const
{
	CView::AssertValid();
}

void CGuiroView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CGuiroDoc* CGuiroView::GetDocument() const // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CGuiroDoc)));
	return (CGuiroDoc*)m_pDocument;
}
#endif //_DEBUG


// CGuiroView message handlers
