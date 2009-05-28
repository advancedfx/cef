// Copyright (c) 2009 The Chromium Embedded Framework Authors. All rights
// reserved. Use of this source code is governed by a BSD-style license that
// can be found in the LICENSE file.

#ifndef _BROWSER_CTOCPP_H
#define _BROWSER_CTOCPP_H

#ifndef USING_CEF_SHARED
#pragma message("Warning: "__FILE__" may be accessed wrapper-side only")
#else // USING_CEF_SHARED

#include "cef.h"
#include "cef_capi.h"
#include "ctocpp.h"


// Wrap a C browser structure with a C++ browser class.
// This class may be instantiated and accessed wrapper-side only.
class CefBrowserCToCpp
    : public CefCToCpp<CefBrowserCToCpp, CefBrowser, cef_browser_t>
{
public:
  CefBrowserCToCpp(cef_browser_t* str)
    : CefCToCpp<CefBrowserCToCpp, CefBrowser, cef_browser_t>(str) {}
  virtual ~CefBrowserCToCpp() {}

  // CefBrowser methods
  virtual bool CanGoBack();
  virtual void GoBack();
  virtual bool CanGoForward();
  virtual void GoForward();
  virtual void Reload();
  virtual void StopLoad();
  virtual void SetFocus(bool enable);
  virtual CefWindowHandle GetWindowHandle();
  virtual bool IsPopup();
  virtual CefRefPtr<CefHandler> GetHandler();
  virtual CefRefPtr<CefFrame> GetMainFrame();
  virtual CefRefPtr<CefFrame> GetFocusedFrame();
  virtual CefRefPtr<CefFrame> GetFrame(const std::wstring& name);
  virtual void GetFrameNames(std::vector<std::wstring>& names);
};


#endif // USING_CEF_SHARED
#endif // _BROWSER_CTOCPP_H
