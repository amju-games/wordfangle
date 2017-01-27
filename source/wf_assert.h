// -----------------------------------------------------------------------------
// Wordfangle - Jason Colman 2017
// -----------------------------------------------------------------------------

#pragma once

#ifdef MACOSX
#include <cassert> // TODO TEMP TEST
#endif

#include "log.h"

template<typename T>
void wf_assert_(T expr, const char* expr_str, const char* file, int line)
{
  if (!expr)
  {
    log(msg() << "ASSERT FAILED: " << expr_str << " in " << file << ": " << line);

#ifdef WIN32
    _CrtDbgBreak(); // windows only
#endif

#ifdef MACOSX
    assert(0);
#endif
  }
}

#ifndef wf_stop
#define wf_stop    wf_assert_(false, "Stopped.", __FILE__, __LINE__)
#endif

#ifndef wf_assert
#define wf_assert(expr)    wf_assert_(expr, #expr, __FILE__, __LINE__)
#endif
