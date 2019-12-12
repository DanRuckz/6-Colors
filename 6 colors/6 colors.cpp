#include "inits.h"
#include "Window_Manager.h"
bool Window_Manager::again = false;
int main()
{
	reload:
	Window_Manager engine;
	if (Window_Manager::getAgain() == true)
	{
		Window_Manager::setAgain(false);
		goto reload;
	}
	return 0;
}