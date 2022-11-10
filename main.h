#ifndef __MAIN_H__
#define __MAIN_H__

#define _CRTDBG_MAP_ALLOC
#include<iostream>
#include <stdlib.h>
#include <crtdbg.h>
#include <sstream>
#include <string>
#ifdef _DEBUG
#define DEBUG_NEW new(_NORMAL_BLOCK, __FILE__, __LINE__)
#define new DEBUG_NEW
#endif


using namespace std;

#endif