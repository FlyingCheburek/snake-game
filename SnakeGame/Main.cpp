#include "WindowsServices.h"
#include "ComplexPrinter.h"

int main() {
	ComplexPrinter cprinter(219, WindowsServices::TerminalGraphics::WHITE);
	cprinter.printMatrix({
		{0, 1, 1, 0},
		{1, 0, 0, 1},
		{1, 1, 1, 1},
		{1, 0, 0, 1}, 
		{1, 0, 0, 1},
	}, 219, TerminalGraphics::YELLOW);
	cprinter.printCanvas({
		{ ComplexPrinter::CanvasCell(219, cprinter.console.CYAN), ComplexPrinter::CanvasCell('x', cprinter.console.YELLOW), ComplexPrinter::CanvasCell(177, cprinter.console.CYAN) }, 
		{ ComplexPrinter::CanvasCell(190, cprinter.console.DARKYELLOW), ComplexPrinter::CanvasCell(188, cprinter.console.BLUE), ComplexPrinter::CanvasCell('7', cprinter.console.WHITE)}
	});
	cprinter.print("teste");
	cprinter.verticalPrint("teste2");
	cprinter.setDefaultColor(cprinter.console.CYAN);
	cprinter.printIcon(5);
	cprinter.verticalPrintIcon(4);
	return 0;
}