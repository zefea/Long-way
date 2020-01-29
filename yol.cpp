/*yol.cpp
 * 
 * Bu dosya yol.h dosyasındaki sınıfların gerçeklemesidir.
 * Sırasıyla Surucu,Yolcu,Yuk,Arac,Otobus,Kamyon sınıflarını içerir.
 * 
 */
 
#include "yol.h"
//********************************************************************************
//-----------------SURUCU-----------------------------
//********************************************************************************
ostream & operator<<(ostream & o, const Surucu& s){
	
		o << "Isim: "; 
		for(unsigned i=0 ; i < strlen(s.name) ; ++i){
			o << s.name[i];
		}
		o << endl << "Yas:" << s.age.yas + 30 << endl;
		if(s.level == 0){
			o << "Ehliyet Sinifi: " << "B";
		}else if(s.level == 1){
			o << "Ehliyet Sinifi: " << "C";
		}else if(s.level == 2){
			o << "Ehliyet Sinifi: " << "D";
		}else if(s.level == 3){
			o << "Ehliyet Sinifi: " << "E";
		}
		o << endl;
	return o;
}
Surucu::Surucu(){
	name = nullptr;
	age.yas = 0;
}
Surucu::Surucu(char* name1, unsigned int age1,EhliyetSinifi level1){
	
	setName(name1);
	age.yas = age1 - 30 ;
	level = level1;
}	
char* Surucu::getName() const{
	return name;
}
unsigned int Surucu::getAge() const{
	return age.yas;
};

Surucu::EhliyetSinifi Surucu::getEhliyet() const{
	return level;
}
void Surucu::setName(char* name1){
	
	unsigned size = strlen(name1);
	name = nullptr;
	try{
		name = new char[size+1];
	}catch(bad_alloc *a){
		cout << "ERROR-RAN OUT OF MEMORY" << endl;
		exit(-1);
	}
	for(unsigned i=0 ; i<size ; ++i)
		name[i] = name1[i];
	name[size] = '\0';
}
void Surucu::setAge(unsigned int age1){
	age.yas = age1;
}
void Surucu::setEhliyet(EhliyetSinifi a){
	level = a;
}
Surucu::~Surucu(){
	if(name != nullptr)
		delete[] name;
}
//copy constructor
Surucu::Surucu(const Surucu& s){
	
	unsigned size = strlen(s.name);
	name = nullptr;
	try{
		name = new char[size+1];
	}catch(bad_alloc *a){
		cout << "ERROR-RAN OUT OF MEMORY" << endl;
		exit(-1);
	}
	for(unsigned i=0 ; i<size ; ++i){
		name[i] = s.name[i];
	}
	name[size] = '\0';
	age.yas = s.age.yas ;
	level = s.level;
}
//surucu assignement
Surucu &Surucu::operator =(const Surucu& s){
	
	if(this == &s)
		return *this;
		
	unsigned size = strlen(s.name);
	if(name != nullptr)
		delete[] name;
	try{
		name = new char[size+1];
	}catch(bad_alloc *a){
		cout << "ERROR-RAN OUT OF MEMORY" << endl;
		exit(-1);
	}
	for(unsigned i=0 ; i<size ; ++i){
		name[i] = s.name[i];
	}
	name[size] = '\0';
	age.yas = s.age.yas;
	level = s.level;
	return *this;
}
//********************************************************************************
//-----------------------YOLCU-------------------------------------
//********************************************************************************
ostream& operator<<(ostream& o,const Yolcu &s){
	
	if(s.name != nullptr && s.BinisNoktasi != nullptr){
		o << "Isim: "; 
		for(unsigned i=0 ; i < strlen(s.name) ; ++i){
			o << s.name[i];
		}
		o << endl;
		o << "Binis Noktasi: "; 
		for(unsigned i=0 ; i < strlen(s.BinisNoktasi) ; ++i){
			o << s.BinisNoktasi[i];
		}
		o << endl;
		o << "Inis Noktasi: "; 
		o << s.InisNoktasi << endl;
	}else 
		o << "Bos" << endl;
	
	return o;
}
//default
Yolcu::Yolcu(){
	
	name = nullptr;
	BinisNoktasi = nullptr;    
	InisNoktasi = ""; 
}
Yolcu::Yolcu(char *name1, char *binis ,string inis){
	
	unsigned int size_name = strlen(name1);
	unsigned int size_binis = strlen(binis);
	
	name = nullptr;
	
	try{
		name = new char[size_name+1];
	}catch(bad_alloc *a){
		cout << "ERROR-RAN OUT OF MEMORY" << endl;
		exit(-1);
	}
	for(unsigned i=0 ; i<size_name ; ++i){
		name[i] = name1[i];
	}
	name[size_name] = '\0';
	try{
		BinisNoktasi = new char[size_binis+1];
	}catch(bad_alloc *a){
		cout << "ERROR-RAN OUT OF MEMORY" << endl;
		exit(-1);
	}
	for(unsigned i=0 ; i<size_binis ; ++i){
		BinisNoktasi[i] = binis[i];
	}
	BinisNoktasi[size_binis] = '\0';
	
	InisNoktasi = inis;
}
//destructor
Yolcu::~Yolcu(){
	
	if(name != nullptr)
		delete[] name;
	if(BinisNoktasi != nullptr)
		delete[] BinisNoktasi;
}
//copy constructor
Yolcu::Yolcu(const Yolcu &other){
	
	unsigned int size_name = strlen(other.name);
	unsigned int size_binis = strlen(other.BinisNoktasi);
	
	name = nullptr;
	try{
		name = new char[size_name+1];
	}catch(bad_alloc *a){
		cout << "ERROR-RAN OUT OF MEMORY" << endl;
		exit(-1);
	}
	for(unsigned i=0 ; i<size_name ; ++i){
		name[i] = other.name[i];
	}
	name[size_name] = '\0';
	try{
		BinisNoktasi = new char[size_binis+1];
	}catch(bad_alloc *a){
		cout << "ERROR-RAN OUT OF MEMORY" << endl;
		exit(-1);
	}
	for(unsigned i=0 ; i<size_binis ; ++i){
		BinisNoktasi[i] = other.BinisNoktasi[i];
	}
	BinisNoktasi[size_binis] = '\0';
	InisNoktasi = other.InisNoktasi;
}
//assignment
Yolcu& Yolcu::operator=(const Yolcu &other){
	
	if(this == &other)
		return *this;
		
	unsigned int size_name = strlen(other.name);
	unsigned int size_binis = strlen(other.BinisNoktasi);
	
	if(name != nullptr)
		delete[] name;
	
	try{
		name = new char[size_name+1];
	}catch(bad_alloc *a){
		cout << "ERROR-RAN OUT OF MEMORY" << endl;
		exit(-1);
	}
	for(unsigned i=0 ; i<size_name ; ++i){
		name[i] = other.name[i];
	}
	name[size_name] = '\0';
	
	if(BinisNoktasi != nullptr)
		delete[] BinisNoktasi;
	try{
		BinisNoktasi = new char[size_binis+1];
	}catch(bad_alloc *a){
		cout << "ERROR-RAN OUT OF MEMORY" << endl;
		exit(-1);
	}
	for(unsigned i=0 ; i<size_binis ; ++i){
		BinisNoktasi[i] = other.BinisNoktasi[i];
	}
	BinisNoktasi[size_binis] = '\0';
	InisNoktasi = other.InisNoktasi;
	return *this;	
}
//getter
char* Yolcu::getName()const{
	return name;
}
char* Yolcu::getBinisNoktasi()const{
	return BinisNoktasi;
}
string Yolcu::getInisNoktas()const{
	return InisNoktasi;
}
//setter
void Yolcu::setName(char* name1){
	
	unsigned size = strlen(name1);
	name = nullptr;
	try{
		name = new char[size+1];
	}catch(bad_alloc *a){
		cout << "ERROR-RAN OUT OF MEMORY" << endl;
		exit(-1);
	}
	for(unsigned i=0 ; i<size ; ++i)
		name[i] = name1[i];
	name[size] = '\0';
		
}
void Yolcu::setBinisNoktasi(char* binis){
	unsigned size = strlen(binis);
	binis = nullptr;
	try{
		binis = new char[size+1];
	}catch(bad_alloc *a){
		cout << "ERROR-RAN OUT OF MEMORY" << endl;
		exit(-1);
	}
	for(unsigned i=0 ; i<size ; ++i)
		BinisNoktasi[i] = binis[i];
	binis[size] = '\0';
}
void Yolcu::setInisNoktas(string inis){
	InisNoktasi = inis;
}
//********************************************************************************
//---------------------YUK------------------------------------
//********************************************************************************
ostream& operator<<(ostream& o,const Yuk &s){
	if(s.Icerik != nullptr){
		o << "Icerik: "; 
		for(unsigned i=0 ; i < strlen(s.Icerik) ; ++i)
			o << s.Icerik[i];
		o << endl;
		o << "Agirlik: " << s.Agirlik << endl;			
		o << "Hacim: " << s.Hacim << endl; 			
		o << "Alici: " << s.Alici << endl; 	
		o << "Binis Noktasi: " << s.BinisNoktasi << endl; 
		o << "Inis Noktasi: " << s.InisNoktasi << endl;
	}else 
		o << "Bos" << endl;
	return o;
}
//default
Yuk::Yuk(){
	Icerik = nullptr; 			
	Agirlik = 0;			
	Hacim = 0; 			
	Alici = "";			
	BinisNoktasi ="";
	InisNoktasi = "";	
}
Yuk::Yuk(char *icerik,double agirlik, double hacim ,string alici,string binis,string inis){
	
	unsigned int size = strlen(icerik);
	Icerik = nullptr;
	try{
		Icerik = new char[size+1];
	}catch(bad_alloc *a){
		cout << "ERROR-RAN OUT OF MEMORY" << endl;
		exit(-1);
	}
	for(unsigned i = 0 ; i<size ; ++i){
		Icerik[i] = icerik[i];
	}
	Icerik[size] = '\0';
	Agirlik = agirlik;			
	Hacim = hacim; 			
	Alici = alici;			
	BinisNoktasi = binis;
	InisNoktasi = inis;		
}
//destructor
Yuk::~Yuk(){
	if(Icerik != nullptr)
		delete[] Icerik;
}
//copy constructor
Yuk::Yuk(const Yuk &other){
	
	unsigned int size = strlen(other.Icerik);
	Icerik = nullptr;
	try{
		Icerik = new char[size+1];
	}catch(bad_alloc *a){
		cout << "ERROR-RAN OUT OF MEMORY" << endl;
		exit(-1);
	}
		
	for(unsigned i = 0 ; i<size ; ++i){
		Icerik[i] = other.Icerik[i];
	}
	Icerik[size] = '\0';
	Agirlik = other.Agirlik;			
	Hacim = other.Hacim; 			
	Alici = other.Alici;			
	BinisNoktasi = other.BinisNoktasi;
	InisNoktasi = other.InisNoktasi;	
}
//assignment
Yuk& Yuk::operator=(const Yuk &other){
	
	if(this == &other)
		return *this;
	
	if(Icerik != nullptr)
		delete[] Icerik;
	unsigned int size = strlen(other.Icerik);
	try{
		Icerik = new char[size+1];
	}catch(bad_alloc *a){
		cout << "ERROR-RAN OUT OF MEMORY" << endl;
		exit(-1);
	}
	
	for(unsigned i =0 ; i<size ; ++i){
		Icerik[i] = other.Icerik[i];
	}
	Icerik[size] = '\0';
	Agirlik = other.Agirlik;			
	Hacim = other.Hacim; 			
	Alici = other.Alici;			
	BinisNoktasi = other.BinisNoktasi;
	InisNoktasi = other.InisNoktasi;
	
	return *this;
}
//getter
char* Yuk::getIcerik()const{
	return Icerik;
}
double Yuk::getAgirlik()const{
	return Agirlik;
}
double Yuk::getHacim()const{
	return Hacim;
}
string Yuk::getAlici()const{
	return Alici;
}
string Yuk::getBinisNoktasi()const{
	return BinisNoktasi;
}
string Yuk::getInisNoktasi()const{
	return InisNoktasi;
}
//setter
void Yuk::setIcerik(char* icerik){
	unsigned size = strlen(icerik);
	icerik = nullptr;
	try{
		icerik = new char[size+1];
	}catch(bad_alloc *a){
		cout << "ERROR-RAN OUT OF MEMORY" << endl;
		exit(-1);
	}
	for(unsigned i=0 ; i<size ; ++i)
		Icerik[i] = icerik[i];
	Icerik[size] = '\0';
}
void Yuk::setAgirlik(double a){
	Agirlik = a;
}
void Yuk::setHacim(double h){
	Hacim = h;
}
void Yuk::setAlici(string a){
	Alici = a;
}
void Yuk::setBinisNoktasi(string b){
	BinisNoktasi = b;
}
void Yuk::setInisNoktasi(string in){
	InisNoktasi = in;
}
//********************************************************************************
//-----------------------ARAC--------------------------------------
//********************************************************************************
ostream& operator<<(ostream& out,const Arac &s){
	s.yaz(out);
	return out;
}
void Arac::yaz(ostream& out) const{
	
	out << "Plaka: ";
	out << getPlaka() << endl;
	out << "Suruculer" << endl;
	for(Surucu v : Suruculer)
		out << v;
	out << endl;
}
Arac::Arac(){
	Plaka = nullptr;
}
Arac::Arac(char *Plaka1,list<Surucu>Suruculer1){
	
	Suruculer = Suruculer1;
	unsigned size = strlen(Plaka1);
	Plaka = nullptr;
	try{
		Plaka = new char[size+1];
	}catch(bad_alloc *a){
		cout << "ERROR-RAN OUT OF MEMORY" << endl;
		exit(-1);
	}
	for(unsigned i=0 ; i<size ; ++i)
		Plaka[i] = Plaka1[i];
	Plaka[size] = '\0';
	
}

//destructor
Arac::~Arac(){
	if(Plaka != nullptr)
		delete[] Plaka;
}
//copy con.
Arac::Arac(const Arac &other){
	
	Suruculer = other.Suruculer;
	unsigned size = strlen(other.Plaka);
	Plaka = nullptr;
	try{
		Plaka = new char[size+1];
	}catch(bad_alloc *a){
		cout << "ERROR-RAN OUT OF MEMORY" << endl;
		exit(-1);
	}
	for(unsigned i=0 ; i<size ; ++i)
		Plaka[i] = other.Plaka[i];
	Plaka[size] = '\0';			
}
Arac& Arac::operator =(const Arac &other){
	
	if(this == &other)
		return *this;
	/*
	list<Surucu>::iterator p;
	for(p = other.getSurucu().begin() ; p != other.getSurucu().end() ; ++p)
		Suruculer.push_back(*p);
	*/
	Suruculer = other.Suruculer;
	unsigned size = strlen(other.Plaka);
	Plaka = nullptr;
	try{
		Plaka = new char[size+1];
	}catch(bad_alloc *a){
		cout << "ERROR-RAN OUT OF MEMORY" << endl;
		exit(-1);
	}
	for(unsigned i=0 ; i<size ; ++i)
		Plaka[i] = other.Plaka[i];
	Plaka[size] = '\0';
	
	return *this;
}

char* Arac::getPlaka() const{
	return Plaka;
}
list<Surucu> Arac::getSurucu() const{
	return Suruculer;
}
void Arac::setPlaka(char* plaka1){
	unsigned size = strlen(plaka1);
	Plaka = nullptr;
	try{
		Plaka = new char[size+1];
	}catch(bad_alloc *a){
		cout << "ERROR-RAN OUT OF MEMORY" << endl;
		exit(-1);
	}
	for(unsigned i=0 ; i<size ; ++i)
		Plaka[i] = plaka1[i];
	Plaka[size] = '\0';
}
void Arac::setSurucu(list<Surucu>Suruculer1){
	Suruculer = Suruculer1;
}

//********************************************************************************
//--------------------------OTOBUS----------------------------
//********************************************************************************
ostream& operator<<(ostream& out,const Otobus &s){
	
	s.yaz(out);
	return out;
}
void Otobus::yaz(ostream& out) const{
	out << "---------------------" << endl;
	out << "OTOBUS" << endl;
	out << "---------------------" << endl;
	out << "Plaka: " << getPlaka() << endl;
	
	out << "Yolcular" << endl;
	unsigned size = Yolcular.size();
	for(unsigned i = 0; i<size ; ++i)
		out << Yolcular[i]; 
	out << "---------------------" << endl;
	out << "Suruculer" << endl;
	for(Surucu v : getSurucu())
		out << v;
	out << endl;
}
Otobus::Otobus(){}
Otobus::Otobus(char* Plaka1,list<Surucu>Suruculer1,vector<Yolcu>other) : Arac(Plaka1,Suruculer1){
	
	unsigned size = other.size();
	for(unsigned i = 0; i<size ; ++i)
		Yolcular.push_back(other[i]);
}
vector<Yolcu> Otobus::getYolcu()const{
	return Yolcular;
}
void Otobus::setYolcu(vector<Yolcu>Yolcular1){
	unsigned size = Yolcular1.size();
	for(unsigned i = 0; i<size ; ++i)
		Yolcular.push_back(Yolcular1[i]);
}
//********************************************************************************
//------------------------KAMYON---------------------------
//********************************************************************************
ostream& operator<<(ostream& out,const Kamyon &s){
	
	s.yaz(out);
	return out;
}
void Kamyon::yaz(ostream& out) const{
	
	out << "---------------------" << endl;
	out << "KAMYON" << endl;
	out << "---------------------" << endl;
	out << "Plaka: " << getPlaka() << endl;
	out << "Ozlu Soz: " << getOzluSoz() << endl;
	out << "Yukler" << endl;
	unsigned size = Yukler.size();
	for(unsigned i = 0; i<size ; ++i)
		out << Yukler[i];
	out << "---------------------" << endl;
	out << "Suruculer" << endl;
	for(Surucu v : getSurucu())
		out << v;
	out << "---------------------" << endl;
	
	
}
Kamyon::Kamyon(){
	OzluSoz = nullptr;
}
Kamyon::Kamyon(char* Plaka1,list<Surucu>Suruculer1,char *soz,vector<Yuk>other) : Arac(Plaka1,Suruculer1){
	
	unsigned size = strlen(soz);
	OzluSoz = nullptr;
	try{
		OzluSoz = new char[size+1];
	}catch(bad_alloc *a){
		cout << "ERROR-RAN OUT OF MEMORY" << endl;
		exit(-1);
	}
	for(unsigned i=0 ; i< size ;++i)
		OzluSoz[i] = soz[i];
		
	OzluSoz[size] = '\0';
	unsigned size2 = other.size();
	for(unsigned i = 0; i<size2 ; ++i)
		Yukler.push_back(other[i]);
}
//destructor
Kamyon::~Kamyon(){
	if(OzluSoz != nullptr)
		delete[] OzluSoz;
}
Kamyon::Kamyon(const Kamyon &other): Arac(other.getPlaka(),other.getSurucu()){
	
	unsigned int size = strlen(other.OzluSoz);
	OzluSoz = nullptr;
	try{
		OzluSoz = new char[size+1];
	}catch(bad_alloc *a){
		cout << "ERROR-RAN OUT OF MEMORY" << endl;
		exit(-1);
	}
	for(unsigned i=0 ; i< size ;++i)
		OzluSoz[i] = other.OzluSoz[i];
		
	OzluSoz[size] = '\0';
	unsigned size2 = other.Yukler.size();
	for(unsigned i = 0; i<size2 ; ++i)
		Yukler.push_back(other.Yukler[i]);	
}
Kamyon& Kamyon::operator =(const Kamyon &other){
	
	if(this == &other)
		return *this;
		
	unsigned int size = strlen(other.OzluSoz);
	if(OzluSoz != nullptr)
		delete[] OzluSoz;
	
	try{
		OzluSoz = new char[size+1];
	}catch(bad_alloc *a){
		cout << "ERROR-RAN OUT OF MEMORY" << endl;
		exit(-1);
	}
		
	for(unsigned i=0 ; i<size ;++i)
		OzluSoz[i] = other.OzluSoz[i];
		
	OzluSoz[size] = '\0';
	unsigned size2 = other.Yukler.size();
	for(unsigned i = 0; i<size2 ; ++i)
		Yukler.push_back(other.Yukler[i]);	
	
	return *this;	
}
char* Kamyon::getOzluSoz()const{
	return OzluSoz;
}
vector<Yuk> Kamyon::getYuk()const{
	return Yukler;	
}
void Kamyon::setOzluSoz(char * soz){
	unsigned int size = strlen(soz);
	OzluSoz = nullptr;
	try{
		OzluSoz = new char[size+1];
	}catch(bad_alloc *a){
		cout << "ERROR-RAN OUT OF MEMORY" << endl;
		exit(-1);
	}
	for(unsigned i=0 ; i<size ;++i)
		OzluSoz[i] = soz[i];
	OzluSoz[size] = '\0';
}
void Kamyon::setYuk(vector<Yuk>Yukler1){
	unsigned size = Yukler1.size();
	for(unsigned i = 0; i<size ; ++i)
		Yukler.push_back(Yukler1[i]);
}



















