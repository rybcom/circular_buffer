#pragma once

#pragma region preprocessor defines

#define UNIT_TESTING_MODE() false
#define LOG_UPDATE_PERFORMANCE_STATS() false
#define SLEEP_MAIN_THRED_LOOP() true

#if CONFIGURATION_DEBUG==true

#define USE_DIAGNOSTIC_VIEWER() false
#define USE_USER_INPUT_EVENTS() true
#define USE_MEMORY_PROFILER() true
#define USE_PERFORMANCE_PROFILER() true
#define USE_PERFORMANCE_PROFILER_TRACING() false
#define TUNNING_MODE() false
#define SANITY_CHECK_ENABLED() true

#endif

#if CONFIGURATION_PROFILER==true

#define USE_DIAGNOSTIC_VIEWER() false
#define USE_USER_INPUT_EVENTS() true
#define USE_MEMORY_PROFILER() true
#define USE_PERFORMANCE_PROFILER() true
#define USE_PERFORMANCE_PROFILER_TRACING() false
#define TUNNING_MODE() false
#define SANITY_CHECK_ENABLED() true


#endif


#if CONFIGURATION_RELEASE==true

#define USE_DIAGNOSTIC_VIEWER() false
#define USE_USER_INPUT_EVENTS() true
#define USE_MEMORY_PROFILER() true
#define USE_PERFORMANCE_PROFILER() true
#define USE_PERFORMANCE_PROFILER_TRACING() false
#define TUNNING_MODE() false
#define SANITY_CHECK_ENABLED() true

#endif

#pragma endregion

#pragma region main 

#define  RUN_AS_UNIT_TESTING() (UNIT_TESTING_MODE() == true)

#pragma endregion

#pragma region misc


#define DEBUGGER_ASSERTION_ENABLED() false

#if DEBUGGER_ASSERTION_ENABLED() ==  true
#define DEBUG_BREAKPOINT() __debugbreak()
#else
#define DEBUG_BREAKPOINT()
#endif


#if USE_MEMORY_PROFILER() == true

#include "MemoryProfiler.h"

#endif

#if USE_PERFORMANCE_PROFILER_TRACING() == true

#include "ProfilingTools.h"

#define  SCOPE_PROFILE(name) ProfilerTimeWatch timer##__LINE__(name)
#define  FUNCTION_PROFILE()  SCOPE_PROFILE(__FUNCSIG__)
#define  BEGIN_PROFILER_SESSION(name) ProfilerInstrument::Get().BeginSession(name) 
#define  END_PROFILER_SESSION(name) ProfilerInstrument::Get().EndSession() 

#else

#define  SCOPE_PROFILE(name) 
#define  FUNCTION_PROFILE()
#define  BEGIN_PROFILER_SESSION(name)  
#define  END_PROFILER_SESSION(name)

#endif

#define  TRACE_AND_PROFILE_FUNCTION() \
LOG_TRACE_FUNCTION(); \
FUNCTION_PROFILE() \

#if SANITY_CHECK_ENABLED() == true
#define TESTCHECK(expression) expression
#else
#define TESTCHECK(expression) 
#endif

#pragma endregion

