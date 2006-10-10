// pagetreemap.h - Declaration of CDemoControl and CPageTreemap
//
// WinDirStat - Directory Statistics
// Copyright (C) 2003-2005 Bernhard Seifert
// Copyright (C) 2004-2006 Oliver Schneider (assarbad.net)
//
// This program is free software; you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation; either version 2 of the License, or
// (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with this program; if not, write to the Free Software
// Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
//
// Author(s): - bseifert -> bseifert@users.sourceforge.net, bseifert@daccord.net
//            - assarbad -> http://assarbad.net/en/contact
//
// $Id$

#pragma once

#include "colorbutton.h"
#include "treemap.h"
#include "xyslider.h"
#include "afxwin.h"

//
// CPageTreemap. "Settings" property page "Treemap".
//
class CPageTreemap : public CPropertyPage
{
	DECLARE_DYNAMIC(CPageTreemap)
	enum { IDD = IDD_PAGE_TREEMAP };

public:
	CPageTreemap();
	virtual ~CPageTreemap();

protected:
	void UpdateOptions(bool save = true);
	void UpdateStatics();
	void OnSomethingChanged();
	void ValuesAltered(bool altered = true);

	virtual void DoDataExchange(CDataExchange* pDX);
	virtual BOOL OnInitDialog();
	virtual void OnOK();

	CTreemap::Options m_options;	// Current options

	bool m_altered;				// Values have been altered. Button reads "Reset to defaults".
	CTreemap::Options m_undo;	// Valid, if m_altered = false

	CTreemapPreview m_preview;

	int m_style;
	CColorButton m_highlightColor;
	BOOL m_grid;
	CColorButton m_gridColor;
	
	CSliderCtrl m_brightness;
	CString m_sBrightness;
	int m_nBrightness;

	CSliderCtrl m_cushionShading;
	CString m_sCushionShading;
	int m_nCushionShading;

	CSliderCtrl m_height;
	CString m_sHeight;
	int m_nHeight;

	CSliderCtrl m_scaleFactor;
	CString m_sScaleFactor;
	int m_nScaleFactor;

	CXySlider m_lightSource;
	CPoint m_ptLightSource;

	CButton m_resetButton;

	DECLARE_MESSAGE_MAP()
	afx_msg void OnColorChangedTreemapGrid(NMHDR *, LRESULT *);
	afx_msg void OnColorChangedTreemapHighlight(NMHDR *, LRESULT *);
	afx_msg void OnVScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar);
	afx_msg void OnLightSourceChanged(NMHDR *, LRESULT *);
	afx_msg void OnBnClickedKdirstat();
	afx_msg void OnBnClickedSequoiaview();
	afx_msg void OnBnClickedTreemapgrid();
	afx_msg void OnBnClickedReset();

};

// $Log$
// Revision 1.10  2006/10/10 01:41:50  assarbad
// - Added credits for Gerben Wieringa (Dutch translation)
// - Replaced Header tag by Id for the CVS tags in the source files ...
// - Started re-ordering of the files inside the project(s)/solution(s)
//
// Revision 1.9  2006/07/04 23:37:39  assarbad
// - Added my email address in the header, adjusted "Author" -> "Author(s)"
// - Added CVS Log keyword to those files not having it
// - Added the files which I forgot during last commit
//
// Revision 1.8  2006/07/04 22:49:20  assarbad
// - Replaced CVS keyword "Date" by "Header" in the file headers
//
// Revision 1.7  2006/07/04 20:45:22  assarbad
// - See changelog for the changes of todays previous check-ins as well as this one!
//
// Revision 1.6  2004/11/13 08:17:07  bseifert
// Remove blanks in Unicode Configuration names.
//
// Revision 1.5  2004/11/12 22:14:16  bseifert
// Eliminated CLR_NONE. Minor corrections.
//
// Revision 1.4  2004/11/05 16:53:06  assarbad
// Added Date and History tag where appropriate.
//
