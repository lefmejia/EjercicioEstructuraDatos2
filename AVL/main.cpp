#include "ArbolBinario.h"
#include <iostream>
int main()
{
	ArbolBinario avl;
	/*avl.insert(10);
	avl.insert(4);
	avl.insert(14);
	avl.insert(2);
	avl.insert(5);
	avl.insert(12);
	avl.insert(15);
	avl.insert(30);*/
	avl.insert(4);
	avl.insert(2);
	avl.insert(1);
	avl.insert(5);
	avl.insert(7);

	std::cout << avl.AlturaArbol();
}