#include <ProteinDOFparser/Manipulator.h>

int main(int argc, char *argv[])
{
	Manipulator manipulator;

	try
	{
		manipulator.read(argc, argv);
		manipulator.init();	
		manipulator.run();
	}
	catch (ProDofError& XE)
	{
		
		std::cerr << XE.message << std::endl;
		std::cout << manipulator.usage << std::endl;
		return PRODofError_EXIT_FAILURE;
	}

	return PRODofError_EXIT_SUCCESS;
}




