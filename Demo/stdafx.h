
// stdafx.h : include file for standard system include files,
// or project specific include files that are used frequently,
// but are changed infrequently

#pragma once

#ifndef VC_EXTRALEAN
#define VC_EXTRALEAN            // Exclude rarely-used stuff from Windows headers
#endif

#include "targetver.h"

#define _ATL_CSTRING_EXPLICIT_CONSTRUCTORS      // some CString constructors will be explicit

// turns off MFC's hiding of some common and often safely ignored warning messages
#define _AFX_ALL_WARNINGS

#include <afxwin.h>         // MFC core and standard components
#include <afxext.h>         // MFC extensions


#include <afxdisp.h>        // MFC Automation classes



#ifndef _AFX_NO_OLE_SUPPORT
#include <afxdtctl.h>           // MFC support for Internet Explorer 4 Common Controls
#endif
#ifndef _AFX_NO_AFXCMN_SUPPORT
#include <afxcmn.h>             // MFC support for Windows Common Controls
#endif // _AFX_NO_AFXCMN_SUPPORT

#include <afxcontrolbars.h>     // MFC support for ribbons and control bars

#ifdef _UNICODE
#if defined _M_IX86
#pragma comment(linker,"/manifestdependency:\"type='win32' name='Microsoft.Windows.Common-Controls' version='6.0.0.0' processorArchitecture='x86' publicKeyToken='6595b64144ccf1df' language='*'\"")
#elif defined _M_X64
#pragma comment(linker,"/manifestdependency:\"type='win32' name='Microsoft.Windows.Common-Controls' version='6.0.0.0' processorArchitecture='amd64' publicKeyToken='6595b64144ccf1df' language='*'\"")
#else
#pragma comment(linker,"/manifestdependency:\"type='win32' name='Microsoft.Windows.Common-Controls' version='6.0.0.0' processorArchitecture='*' publicKeyToken='6595b64144ccf1df' language='*'\"")
#endif
#endif

#ifdef _M_IX86 
#define APPID ""
#define FD_SDKKEY		""
#define FT_SDKKEY		""
#define FR_SDKKEY		""
#define AGE_SDKKEY		""
#define GENDER_SDKKEY	""
#elif defined _M_X64
#define APPID "9pVbYVJdaYKqB4bMXyKBkRzh9mUpb5UqVGsicHpt14ba"
#define FD_SDKKEY		"7JbJR9uQAhSD9f1knGpgBbEX6DZxeQhCr3YJe2fj9nFq"
#define FT_SDKKEY		"7JbJR9uQAhSD9f1knGpgBbEPvpJrq8Z6KZ8JcmAaFrbC"
#define FR_SDKKEY		"7JbJR9uQAhSD9f1knGpgBbEeFcq9rU1bqNttSCffr3Jn"
#define AGE_SDKKEY		"7JbJR9uQAhSD9f1knGpgBbFG4d8yyCsr1NevDGsAMpuU"
#define GENDER_SDKKEY	"7JbJR9uQAhSD9f1knGpgBbFPE2QDL7AodL9EZw8y75LE"
#endif