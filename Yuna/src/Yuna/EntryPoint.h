#pragma once

#ifdef YU_PLATFORM_WINDOWS

extern Yuna::Application *Yuna::CreateApplication();

int main(int argc, char** argv)
{
	auto app = Yuna::CreateApplication();
	app->Run();
	delete app;

	return 0;
}

#else
	#error Yuna only supports Windows!
#endif // YU_PLATFORM_WINDOWS
