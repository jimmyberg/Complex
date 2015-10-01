Made by Jimmy van den Berg in The Netherlands
1 October 2015

c++ library for complex number calculations.

## Example

**main.cpp**
```c++
#include <iostream>
#include "Complex.hpp"
using namespace std;

int main(int argc, char** argv){
	Complex a(3, 4);
	Complex b(1, -2);
	cout << a << " + " << b << " = " << a + b << endl;
	cout << a << " - " << b << " = " << a - b << endl;
	cout << a << " * " << b << " = " << a * b << endl;
	cout << a << " / " << b << " = " << a / b << endl;
	cout << a << " * 1.25 = " << a * 1.25 << endl;
	cout << "Argument of " << b << " = " << b.argument() << endl;

	std::cout << "Press enter to exit." << std::endl;
	std::cin.get();
	return 1;
}
```
**output**
```
3+4i + 1-2i = 4+2i
3+4i - 1-2i = 2+6i
3+4i * 1-2i = 11-2i
3+4i / 1-2i = -1+2i
3+4i * 1.25 = 3.75+5i
Argument of 1-2i = -1.10715
Press enter to exit.
```

