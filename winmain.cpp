#include "test.hpp"
#include <iostream>
#include <windows.h>

using namespace std;

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance,
                   LPSTR lpCmdLine, int nCmdShow) {
  test_createFile("test_createFile.tmp");
  test_getFileSize("test_createFile.tmp");
  test_openFile("test_createFile.tmp");
  test_openFile("null.tmp");
  test_deleteFie("test_getFileSize.tmp");
  test_deleteFie("test_createFile.tmp");
  test_deleteFie("null.tmp");
  return 0;
}