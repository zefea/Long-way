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
	cout << dosyadanOku("source.xml",arac);
	
	return 0;
}

