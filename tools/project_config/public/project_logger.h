#pragma once

enum LogVerbosity
{
	Trace= 1,
	Debug,
	Info,
	Warn,
	Error,
	Critical,
	Application
};

#define USE_SIMPLE_LOGGER() false

#if CONFIGURATION_DEBUG==true

#define LOG_VERBOSITY() LogVerbosity::Debug
#define LOGGING_ENABLED_DIAGNOSTIC() false
#define LOGGING_ENABLED_CONSOLE() true
#define LOGGING_ENABLED_FILE() true

#endif


#if CONFIGURATION_PROFILER==true

#define LOG_VERBOSITY() LogVerbosity::Info
#define LOGGING_ENABLED_DIAGNOSTIC() false
#define LOGGING_ENABLED_CONSOLE() true
#define LOGGING_ENABLED_FILE() false

#endif


#if CONFIGURATION_RELEASE==true

#define LOG_VERBOSITY() LogVerbosity::Info
#define LOGGING_ENABLED_DIAGNOSTIC() false
#define LOGGING_ENABLED_CONSOLE() true
#define LOGGING_ENABLED_FILE() false

#endif

#if USE_DIAGNOSTIC_VIEWER()==false && LOGGING_ENABLED_DIAGNOSTIC()==true
#undef  LOGGING_ENABLED_DIAGNOSTIC
#define LOGGING_ENABLED_DIAGNOSTIC() false
#endif

