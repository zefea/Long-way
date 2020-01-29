/* dosya okuma.cpp
 * 
 * dosyadanoku fonksiyonunun gerçeklemesini yapan cpp dosyasıdır.
 * XML reader source niteliğindedir
 * 
 */
#include <string.h>
#include <stdio.h>
#include <iostream>
#include <fstream>
#include <vector>

#include <locale>

#include "rapidxml.hpp"
#include "yol.h"

using namespace std;
using namespace rapidxml;


unsigned int dosyadanOku(const string& filename, list<Arac*> araclar){
	setlocale(LC_ALL, "tr_TR.utf8"); // Turkish locale settings

	xml_document<> doc;
	xml_node<> * root_node;

	// Read the xml file into a vector
	ifstream theFile(filename.c_str());
	if(theFile.fail())
		exit(-1);

	vector<char> buffer((istreambuf_iterator<char>(theFile)), istreambuf_iterator<char>());
	buffer.push_back('\0');

	// Parse the buffer using the xml file parsing library into doc 
	doc.parse<0>(&buffer[0]);

	// Set the root node
	root_node = doc.first_node("Araclar");
	cout << "Parsing Vehicles.xml..." << endl;

	/*aracın türünü,plakasını
	 *surucunun ismini, yaşını ve ehliyet sınıfını
	 * yolcuların isimlerini ve yuklerin iniş biniş noktalarını
	 */
	string arac_tur,soz,plaka1,age_string,level_string,inis,binis_string;
	char* name1;
	char* binis, *plaka2,*soz2;
	Surucu::EhliyetSinifi a;			
	unsigned int vehicle_number =0;
	for (auto * vehicle_node = root_node->first_node("Arac"); vehicle_node; vehicle_node = vehicle_node->next_sibling())
	{	
		list<Surucu>s;			//sürücü tutan list
		vector<Yolcu>yolcu_vec;	//yolcu tutan vector
		vector<Yuk>yuk_vec;		//yuk tutan vector
	
		arac_tur = vehicle_node->first_node("Turu")->value();
		plaka2 = vehicle_node->first_node("Plaka")->value();
		 
		//OzluSoz okunması
		if (!strcmp(vehicle_node->first_node("Turu")->value(), "Kamyon"))
			soz2 = vehicle_node->first_node("OzluSoz")->value();	
			
		//Suruculerin okunması
		auto * drivers_root_node = vehicle_node->first_node("Suruculer");
		for (auto * driver_node = drivers_root_node->first_node("Surucu"); driver_node; driver_node = driver_node->next_sibling())
		{
			name1 = driver_node->first_node("Adi")->value();
			age_string = driver_node->first_node("Yasi")->value();
			level_string = driver_node->first_node("EhliyetSinifi")->value();
			if(level_string == "B"){
				 a = Surucu::EhliyetSinifi::B;
			}else if(level_string == "C"){
				 a = Surucu::EhliyetSinifi::C;
			}else if(level_string == "D"){
				 a = Surucu::EhliyetSinifi::D;
			}else if(level_string == "E"){
				 a = Surucu::EhliyetSinifi::E;
			}
			
			Surucu drivers(name1,atoi(age_string.c_str()),a);
			s.push_back(drivers);
		}	
		
		//Araç türüne göre (otobüs-kamyonsa) yolcu veya yüklerin okunması
		if (arac_tur == "Otobüs"){
			//Yolcuların okunması
			auto * passenger_root_node = vehicle_node->first_node("Yolcular");
			for (auto * passenger_node = passenger_root_node->first_node("Yolcu"); passenger_node; passenger_node = passenger_node->next_sibling())
			{
				name1 = passenger_node->first_node("Adi")->value();
				binis = passenger_node->first_node("BinisNoktasi")->value();  
				inis = passenger_node->first_node("InisNoktasi")->value();
				Yolcu yol(name1,binis,inis);	
				yolcu_vec.push_back(yol);
			}
			try{
				Arac *n = new Otobus(plaka2,s,yolcu_vec); 
				if(n == nullptr)
					throw 99;
				araclar.push_back(n);
			}catch(int a){
				cout << "ERROR" << endl << "Code:" << a << endl ;
			}
			vehicle_number++;
			
		}else{
			//Yüklerin okunması
			char* icerik; 			//Yükün cinsini C tarzı string olarak tutar. Dinamik bellek yönetimi gerekir.
			string agirlik;			//Yükün ağırlığını string olarak tutar.
			string hacim; 			//Yükün hacmini string olarak tutar.
			string alici;			//Yükü alacak kişinin adını ve soyadını C++ tarzı string nesnesi olarak tutar.
			string binis2;			//Yolcunun bineceği yeri C++ tarzı string nesnesi olarak tutar.
			string inis2;		
			auto * load_root_node = vehicle_node->first_node("Yukler");
			for (auto * load_node = load_root_node->first_node("Yuk"); load_node; load_node = load_node->next_sibling())
			{
				icerik = load_node->first_node("Icerik")->value();
				agirlik = load_node->first_node("Agirlik")->value();
				hacim = load_node->first_node("Hacim")->value();
				alici = load_node->first_node("Alici")->value();
				binis2 = load_node->first_node("BinisNoktasi")->value();  //atama yapıyor mu set but not used??
				inis2 = load_node->first_node("InisNoktasi")->value();
				Yuk yuk(icerik,stod(agirlik),stod(hacim),alici,binis2,inis2);	
				yuk_vec.push_back(yuk);
			}
			try{
				Arac *n2 = new Kamyon(plaka2,s,soz2,yuk_vec);
				if(n2 == nullptr)
					throw 99;
				araclar.push_back(n2);
			}catch(int a){
				cout << "ERROR" << endl << "Code:" << a << endl ;
			}
			vehicle_number++;
		}
	}
	//parametre olarak referans işareti konulmazsa
	for(Arac* v : araclar)
		cout<< *v;
	cout << endl;
	theFile.close();
	
	return vehicle_number;

}
