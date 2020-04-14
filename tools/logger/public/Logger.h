
#pragma once

#include <memory>
#include <fmt/core.h>
#include <fmt/color.h>


#include <iostream>
#include <fstream>
#include <string>

namespace file_logger
{
	inline std::string file_logger_path;

	inline void set_logger_file_output(std::string_view file)
	{
		static bool has_been_set = false;

		if (has_been_set == false)
		{
			file_logger_path = file;
			has_been_set = true;
		}
	}

	inline void log(const std::string &text)
	{
		std::ofstream myfile(file_logger_path, std::ios_base::app);
		if (myfile.is_open())
		{
			myfile << text << '\n';
			myfile.close();
		}
	}
}

#define IS_VERBOSITY_ACCEPET(verbosity) (LOG_VERBOSITY()<=LogVerbosity::##verbosity) 


#if USE_SIMPLE_LOGGER() == true

#define TRACE_LOG(log_msg,...)  	\
if constexpr(LOGGING_ENABLED_CONSOLE() && IS_VERBOSITY_ACCEPET(Trace))   {fmt::print(fmt::fg(fmt::color::gray),std::string(log_msg)+"\n",__VA_ARGS__);} \
if constexpr (LOGGING_ENABLED_FILE() && IS_VERBOSITY_ACCEPET(Trace)) { file_logger::log(fmt::format(std::string("[trace] ").append(std::string(log_msg)), __VA_ARGS__).c_str()); }

#define DEBUG_LOG(log_msg,...)  	\
if constexpr(LOGGING_ENABLED_CONSOLE() &&  IS_VERBOSITY_ACCEPET(Debug))   {fmt::print(fmt::fg(fmt::color::white),std::string(log_msg)+"\n",__VA_ARGS__);} \
if constexpr (LOGGING_ENABLED_FILE() && IS_VERBOSITY_ACCEPET(Debug)) { file_logger::log(fmt::format(std::string("[debug] ").append(std::string(log_msg)), __VA_ARGS__).c_str()); }

#define INFO_LOG(log_msg,...)  	\
if constexpr(LOGGING_ENABLED_CONSOLE() && IS_VERBOSITY_ACCEPET(Info))    {fmt::print(fmt::fg(fmt::color::light_green),std::string(log_msg)+"\n",__VA_ARGS__);} \
if constexpr (LOGGING_ENABLED_FILE() && IS_VERBOSITY_ACCEPET(Info)) { file_logger::log(fmt::format(std::string("[info] ").append(std::string(log_msg)), __VA_ARGS__).c_str()); } 

#define WARN_LOG(log_msg,...)  	\
if constexpr(LOGGING_ENABLED_CONSOLE() && IS_VERBOSITY_ACCEPET(Warn))    {fmt::print(fmt::fg(fmt::color::yellow),std::string(log_msg)+"\n",__VA_ARGS__);} \
if constexpr (LOGGING_ENABLED_FILE() && IS_VERBOSITY_ACCEPET(Warn)) { file_logger::log(fmt::format(std::string("[warn] ").append(std::string(log_msg)), __VA_ARGS__).c_str()); }

#define ERROR_LOG(log_msg,...)  	\
if constexpr(LOGGING_ENABLED_CONSOLE() && IS_VERBOSITY_ACCEPET(Error))   {fmt::print(fmt::fg(fmt::color::tomato),std::string(log_msg)+"\n",__VA_ARGS__);}  \
if constexpr (LOGGING_ENABLED_FILE() && IS_VERBOSITY_ACCEPET(Error)) { file_logger::log(fmt::format(std::string("[error] ").append(std::string(log_msg)), __VA_ARGS__).c_str()); }

#define CRITICAL_LOG(log_msg,...)  	\
if constexpr(LOGGING_ENABLED_CONSOLE() && IS_VERBOSITY_ACCEPET(Critical))   {fmt::print(fmt::fg(fmt::color::red),std::string(log_msg)+"\n",__VA_ARGS__);} \
if constexpr (LOGGING_ENABLED_FILE() && IS_VERBOSITY_ACCEPET(Critical)) { file_logger::log(fmt::format(std::string("[critical] ").append(std::string(log_msg)), __VA_ARGS__).c_str()); }

#define APP_LOG(log_msg,...)  	\
if constexpr(LOGGING_ENABLED_CONSOLE() && IS_VERBOSITY_ACCEPET(Application))   {fmt::print(fmt::fg(fmt::color::light_blue),std::string(log_msg)+"\n",__VA_ARGS__);} \
if constexpr (LOGGING_ENABLED_FILE() && IS_VERBOSITY_ACCEPET(Application)) { file_logger::log(fmt::format(std::string("[app] ").append(std::string(log_msg)), __VA_ARGS__).c_str()); }


#else

#include  "fidelity/FidelityIGLogger.h"
#include <imgui.h>

#define TRACE_LOG(log_msg,...)  	\
if constexpr(LOGGING_ENABLED_DIAGNOSTIC() &&  IS_VERBOSITY_ACCEPET(Trace)){ImGui::logText(ImGui::LogCategory::Trace,fmt::format(std::string("[trace] ").append(std::string(log_msg)),__VA_ARGS__).c_str());} \
if constexpr(LOGGING_ENABLED_CONSOLE() && IS_VERBOSITY_ACCEPET(Trace))   {fmt::print(fmt::fg(fmt::color::gray),std::string(log_msg)+"\n",__VA_ARGS__);} \
if constexpr (LOGGING_ENABLED_FILE() && IS_VERBOSITY_ACCEPET(Trace)) { file_logger::log(fmt::format(std::string("[trace] ").append(std::string(log_msg)), __VA_ARGS__).c_str()); }


#define DEBUG_LOG(log_msg,...)  	\
if constexpr(LOGGING_ENABLED_DIAGNOSTIC() && IS_VERBOSITY_ACCEPET(Debug))	   {ImGui::logText(ImGui::LogCategory::Trace,fmt::format(std::string("[debug] ").append(std::string(log_msg)),__VA_ARGS__).c_str());} \
if constexpr(LOGGING_ENABLED_CONSOLE() &&  IS_VERBOSITY_ACCEPET(Debug))   {fmt::print(fmt::fg(fmt::color::white),std::string(log_msg)+"\n",__VA_ARGS__);} \
if constexpr (LOGGING_ENABLED_FILE() && IS_VERBOSITY_ACCEPET(Debug)) { file_logger::log(fmt::format(std::string("[debug] ").append(std::string(log_msg)), __VA_ARGS__).c_str()); }


#define INFO_LOG(log_msg,...)  	\
if constexpr(LOGGING_ENABLED_DIAGNOSTIC() && IS_VERBOSITY_ACCEPET(Info)) {ImGui::logText(ImGui::LogCategory::Info,fmt::format(std::string("[info] ").append(std::string(log_msg)),__VA_ARGS__).c_str());} \
if constexpr(LOGGING_ENABLED_CONSOLE() && IS_VERBOSITY_ACCEPET(Info))    {fmt::print(fmt::fg(fmt::color::light_green),std::string(log_msg)+"\n",__VA_ARGS__);} \
if constexpr (LOGGING_ENABLED_FILE() && IS_VERBOSITY_ACCEPET(Info)) { file_logger::log(fmt::format(std::string("[info] ").append(std::string(log_msg)), __VA_ARGS__).c_str()); } 

#define WARN_LOG(log_msg,...)  	\
if constexpr(LOGGING_ENABLED_DIAGNOSTIC() && IS_VERBOSITY_ACCEPET(Warn)) {ImGui::logText(ImGui::LogCategory::Warn,fmt::format(std::string("[warn] ").append(std::string(log_msg)),__VA_ARGS__).c_str());} \
if constexpr(LOGGING_ENABLED_CONSOLE() && IS_VERBOSITY_ACCEPET(Warn))    {fmt::print(fmt::fg(fmt::color::yellow),std::string(log_msg)+"\n",__VA_ARGS__);} \
if constexpr (LOGGING_ENABLED_FILE() && IS_VERBOSITY_ACCEPET(Warn)) { file_logger::log(fmt::format(std::string("[warn] ").append(std::string(log_msg)), __VA_ARGS__).c_str()); }

#define ERROR_LOG(log_msg,...)  	\
if constexpr(LOGGING_ENABLED_DIAGNOSTIC() && IS_VERBOSITY_ACCEPET(Error)){ImGui::logText(ImGui::LogCategory::Error,fmt::format(std::string("[error] ").append(std::string(log_msg)),__VA_ARGS__).c_str());} \
if constexpr(LOGGING_ENABLED_CONSOLE() && IS_VERBOSITY_ACCEPET(Error))   {fmt::print(fmt::fg(fmt::color::tomato),std::string(log_msg)+"\n",__VA_ARGS__);}  \
if constexpr (LOGGING_ENABLED_FILE() && IS_VERBOSITY_ACCEPET(Error)) { file_logger::log(fmt::format(std::string("[error] ").append(std::string(log_msg)), __VA_ARGS__).c_str()); }

#define CRITICAL_LOG(log_msg,...)  	\
if constexpr(LOGGING_ENABLED_DIAGNOSTIC() && IS_VERBOSITY_ACCEPET(Critical)){ImGui::logText(ImGui::LogCategory::Critical,fmt::format(std::string("[critical] ").append(std::string(log_msg)),__VA_ARGS__).c_str());} \
if constexpr(LOGGING_ENABLED_CONSOLE() && IS_VERBOSITY_ACCEPET(Critical))   {fmt::print(fmt::fg(fmt::color::red),std::string(log_msg)+"\n",__VA_ARGS__);} \
if constexpr (LOGGING_ENABLED_FILE() && IS_VERBOSITY_ACCEPET(Critical)) { file_logger::log(fmt::format(std::string("[critical] ").append(std::string(log_msg)), __VA_ARGS__).c_str()); }

#define APP_LOG(log_msg,...)  	\
if constexpr(LOGGING_ENABLED_DIAGNOSTIC() && IS_VERBOSITY_ACCEPET(Application)){ImGui::logText(ImGui::LogCategory::Application,fmt::format(std::string("[app] ").append(std::string(log_msg)),__VA_ARGS__).c_str());} \
if constexpr(LOGGING_ENABLED_CONSOLE() && IS_VERBOSITY_ACCEPET(Application))   {fmt::print(fmt::fg(fmt::color::light_blue),std::string(log_msg)+"\n",__VA_ARGS__);} \
if constexpr (LOGGING_ENABLED_FILE() && IS_VERBOSITY_ACCEPET(Application)) { file_logger::log(fmt::format(std::string("[app] ").append(std::string(log_msg)), __VA_ARGS__).c_str()); }


#endif

#define  LOG_TRACE_FUNCTION()  TRACE_LOG(__FUNCSIG__)


