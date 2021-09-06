#include "test.hpp"
#include <iostream>
#include <windows.h>

using namespace std;

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance,
                   LPSTR lpCmdLine, int nCmdShow) {
  hello();
  test_createFile("test_createFile.tmp");
  test_getFileSize("test_getFileSize.tmp");
  return 0;
}