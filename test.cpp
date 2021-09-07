#include "test.hpp"
#include <iostream>
#include <windows.h>

using namespace std;

void test_MessageBox(const char *msg, const char *title) {
  MessageBoxA(NULL, (LPCSTR)msg, (LPCSTR)title, MB_OK);
}

void test_GetLastError() {
  LPVOID msg;
  DWORD err = GetLastError();

  FormatMessage(FORMAT_MESSAGE_ALLOCATE_BUFFER | FORMAT_MESSAGE_FROM_SYSTEM |
                    FORMAT_MESSAGE_IGNORE_INSERTS,
                NULL, err, MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT),
                (LPTSTR)&msg, 0, NULL);
  cout << "Error:" << (char *)msg;
}

void test_deleteFie(const char *filePath) {
  BOOL ret;
  ret = DeleteFile((LPCTSTR)filePath);
  if (ret == false) {
    cout << "DeleteFile Error:" << filePath << "\n";
    test_GetLastError();
    return;
  }
  cout << "DeleteFile:" << filePath << "\n";
  return;
}

void test_openFile(const char *filePath) {
  HFILE hFile;
  OFSTRUCT buf;
  hFile = OpenFile((LPSTR)filePath, &buf, OF_EXIST);
  if (hFile == HFILE_ERROR) {
    cout << "OpenFile Error:" << filePath << "\n";
    test_GetLastError();
    return;
  }
  cout << "OpenFile:" << filePath << "\n";
  CloseHandle((HANDLE)hFile);
  return;
}

void test_getFileSize(const char *filePath) {
  HANDLE hFile;
  DWORD size;

  hFile = CreateFileA((LPSTR)filePath, GENERIC_READ, 0, NULL, OPEN_EXISTING,
                      FILE_ATTRIBUTE_NORMAL, NULL);
  if (hFile == INVALID_HANDLE_VALUE) {
    cout << "CreateFile Error:" << filePath << "\n";
    test_GetLastError();
    CloseHandle(hFile);
    return;
  }
  cout << "CreateFile OPEN_EXISTING:" << filePath << "\n";
  size = GetFileSize(hFile, NULL);
  cout << "GetFileSize:" << size << "byte\n";
  CloseHandle(hFile);
  return;
}

void test_createFile(const char *filePath) {
  HANDLE hFile;

  hFile = CreateFileA((LPSTR)filePath, GENERIC_READ, 0, NULL, OPEN_ALWAYS,
                      FILE_ATTRIBUTE_NORMAL, NULL);
  if (hFile == INVALID_HANDLE_VALUE) {
    cout << "CreateFile Error:" << filePath << "\n";
    test_GetLastError();
    CloseHandle(hFile);
    return;
  }
  cout << "CreateFile OPEN_ALWAYS:" << filePath << "\n";
  CloseHandle(hFile);
  return;
}