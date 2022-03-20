#pragma once

#include "Core.h"

namespace Yuna
{

	class YUNA_API Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();
	};

	// Defined in CLIENT
	Application *CreateApplication();
}


