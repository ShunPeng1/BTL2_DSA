#ifndef __MAIN_H__
#define __MAIN_H__

#define _CRTDBG_MAP_ALLOC
#include <crtdbg.h>
#include <stdlib.h>
#include <iostream>
#include <sstream>
#include <string>

#ifdef _DEBUG
    #define DBG_NEW new ( _NORMAL_BLOCK , __FILE__ , __LINE__ )
    // Replace _NORMAL_BLOCK with _CLIENT_BLOCK if you want the
    // allocations to be of _CLIENT_BLOCK type
#else
    #define DBG_NEW new
#endif

using namespace std;

#endif