#pragma once

#ifdef YU_PLATFORM_WINDOWS

extern Yuna::Application *Yuna::CreateApplication();

int main(int argc, char** argv)
{
	Yuna::Log::Init();
	YU_CORE_WARN("Initialized Log!");
	YU_INFO("Hello from the {0} system", 1707);

	auto app = Yuna::CreateApplication();
	app->Run();
	delete app;

	return 0;
}

#else
	#error Yuna only supports Windows!
#endif // YU_PLATFORM_WINDOWS
