#include "test.hpp"
#include <iostream>
#include <windows.h>

using namespace std;

void test_getFileSize(const char *filePath) {
  HANDLE hFile;
  DWORD size;

  hFile = CreateFile((LPSTR)filePath, GENERIC_READ, 0, NULL, OPEN_ALWAYS,
                     FILE_ATTRIBUTE_NORMAL, NULL);
  if (hFile == INVALID_HANDLE_VALUE) {
    cout << "CreateFile error\n";
  }
  cout << "CreateFile:" << filePath << "\n";
  size = GetFileSize(hFile, NULL);
  cout << "GetFileSize:" << size << "\n";
  CloseHandle(hFile);
}

void test_createFile(const char *filePath) {
  HANDLE hFile;

  hFile = CreateFile((LPSTR)filePath, GENERIC_READ, 0, NULL, OPEN_ALWAYS,
                     FILE_ATTRIBUTE_NORMAL, NULL);
  if (hFile == INVALID_HANDLE_VALUE) {
    cout << "CreateFile error\n";
  }
  cout << "CreateFile:" << filePath << "\n";

  CloseHandle(hFile);
}

void hello() { cout << "hello\n"; }