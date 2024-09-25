#include "WindowsServices.h"
#include "ComplexPrinter.h"

int main() {
	ComplexPrinter cprinter(177, WindowsServices::TerminalGraphics::DARKMAGENTA);
	cprinter.printMatrix({
		{1, 0, 1},
		{0, 1, 0},
		{1, 0, 1}
	});
	return 0;
}