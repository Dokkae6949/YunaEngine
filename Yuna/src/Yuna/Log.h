#pragma once

#include "Core.h"
#include "spdlog/spdlog.h"

namespace Yuna
{

	class YUNA_API Log
	{
	public:
		static void Init();

		inline static std::shared_ptr<spdlog::logger> &GetCoreLogger() { return s_CoreLogger; }
		inline static std::shared_ptr<spdlog::logger> &GetClientLogger() { return s_ClientLogger; }
	private:
		static std::shared_ptr<spdlog::logger> s_CoreLogger;
		static std::shared_ptr<spdlog::logger> s_ClientLogger;
	};

}

// Core log macros
#define YU_CORE_TRACE(...) ::Yuna::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define YU_CORE_INFO(...)  ::Yuna::Log::GetCoreLogger()->info(__VA_ARGS__)
#define YU_CORE_WARN(...)  ::Yuna::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define YU_CORE_ERROR(...) ::Yuna::Log::GetCoreLogger()->error(__VA_ARGS__)
#define YU_CORE_FATAL(...) ::Yuna::Log::GetCoreLogger()->fatal(__VA_ARGS__)

// Client log macros
#define YU_TRACE(...) ::Yuna::Log::GetClientLogger()->trace(__VA_ARGS__)
#define YU_INFO(...)  ::Yuna::Log::GetClientLogger()->info(__VA_ARGS__)
#define YU_WARN(...)  ::Yuna::Log::GetClientLogger()->warn(__VA_ARGS__)
#define YU_ERROR(...) ::Yuna::Log::GetClientLogger()->error(__VA_ARGS__)
#define YU_FATAL(...) ::Yuna::Log::GetClientLogger()->fatal(__VA_ARGS__)