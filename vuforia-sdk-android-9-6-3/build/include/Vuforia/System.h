/*===============================================================================
Copyright (c) 2018 PTC Inc. All Rights Reserved.

Copyright (c) 2010-2014 Qualcomm Connected Experiences, Inc. All Rights Reserved.

Vuforia is a trademark of PTC Inc., registered in the United States and other 
countries.

\file
    System.h

\brief
    System specific definitions.
===============================================================================*/

#ifndef _VUFORIA_SYSTEM_H_
#define _VUFORIA_SYSTEM_H_

// Include files
#if defined(_WIN32_WCE) || defined(WIN32) || defined(_WIN32)
#  define VUFORIA_IS_WINDOWS
#endif

// Define exporting/importing of methods from module
//
#ifdef VUFORIA_IS_WINDOWS

#  ifdef VUFORIA_EXPORTS
#    define VUFORIA_API __declspec(dllexport)
#  elif defined(VUFORIA_STATIC)
#    define VUFORIA_API
#  else
#    define VUFORIA_API __declspec(dllimport)
#  endif

#else // !VUFORIA_IS_WINDOWS

#  ifdef VUFORIA_EXPORTS
#    define VUFORIA_API __attribute__((visibility("default"))) 
#  elif defined(VUFORIA_STATIC)
#    define VUFORIA_API
#  else
#    define VUFORIA_API __attribute__((visibility("default")))
#  endif

#endif


// Platform defines
#ifdef __cplusplus

#ifdef VUFORIA_IS_WINDOWS

namespace Vuforia
{
    typedef unsigned __int16 UInt16;
    typedef __int64 Int64;
}

#else // !VUFORIA_IS_WINDOWS

#include <stdio.h> 

namespace Vuforia
{
    typedef __uint16_t UInt16;
    typedef __int64_t Int64;
}

#endif

#endif // __cplusplus

#endif // _VUFORIA_SYSTEM_H_
