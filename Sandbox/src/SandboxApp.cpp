#include <Yuna.h>

class Sandbox : public Yuna::Application
{
public:
	Sandbox()
	{

	}
	~Sandbox()
	{

	}
};

Yuna::Application *Yuna::CreateApplication()
{
	return new Sandbox();
}