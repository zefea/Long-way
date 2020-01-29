/*main.cpp
 * 
 * UzunYol ödevi main dosyasıdır.
 * 
 */

#include "yol.h"

int main(int argc, char **argv)
{
	list<Arac*>arac;
	cout << "Okunan Arac Sayisi:  ";
	cout << dosyadanOku("bil122_hw08.xml",arac);
	
	return 0;
}

