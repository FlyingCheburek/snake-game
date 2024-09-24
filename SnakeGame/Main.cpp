#include "WindowsServices.h"
#include "Printer.h"

int main() {
	Printer p(177, WindowsServices::TerminalGraphics::DARKMAGENTA);
	p.print("ameixa", 5);
	std::cout << '\n';
	p.setDefaultColor(p.console.YELLOW);
	p.print("banana", 2);
	std::cout << '\n';
	p.setDefaultColor(p.console.GREEN);
	p.printIcon(10);
	std::cout << '\n';
	p.setDefaultColor(p.console.WHITE);
	p.verticalPrintIcon();
	p.setDefaultColor(p.console.DARKYELLOW);
	p.verticalPrint("kiwi", 3);
	return 0;
}