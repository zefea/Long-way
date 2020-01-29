/*
 * yol.h
 * 
 * Sırasıyla Surucu,Yolcu,Yuk,Arac,Otobus,Kamyon sınıfları içerir.
 */ 
#include <iostream>
#include <iostream>
#include <vector>
#include <cstring>
#include <list>
#include <iterator>
#include <new>
#include <string>
//using namespace System::Xml;
class Arac;
using namespace std;
unsigned int dosyadanOku(const string& filename, list<Arac*> araclar);
struct Age{
	unsigned int yas: 5; 
};
//surucu sinifi
class Surucu{
	
	friend ostream & operator<<(ostream & o, const Surucu & s);
	
	public:
		enum EhliyetSinifi{B,C,D,E};
		Surucu();
		Surucu(char* name1, unsigned int age1,EhliyetSinifi level);
		
		~Surucu();								//destructor
		Surucu(const Surucu& s);				//copy const
		Surucu &operator =(const Surucu& s);	//assignment
		//getter
		char* getName() const;		
		unsigned int getAge() const;
		EhliyetSinifi getEhliyet() const;
		//setter
		void setName(char* name1);
		void setAge(unsigned int age1);
		void setEhliyet(EhliyetSinifi a);
		
	private:
		char *name;				//c stringi olarak tutar
		Age age;	
		EhliyetSinifi level;
};

//otobus yolculari
class Yolcu 
{
	friend ostream& operator<<(ostream& o,const Yolcu &s); 
	
	public:
		Yolcu();
		Yolcu(char *name1, char *binis ,string inis);
		
		~Yolcu();
		Yolcu(const Yolcu &other);
		Yolcu& operator=(const Yolcu &other);
		//getter
		char* getName() const;
		char* getBinisNoktasi()const;
		string getInisNoktas()const;
		//setter
		void setName(char* name1);
		void setBinisNoktasi(char* binis);
		void setInisNoktas(string inis);
	
	private:
		char* name;	
		char *BinisNoktasi; 		//Yolcunun bineceği yeri C tarzı string olarak tutar. Dinamik bellek yönetimi gerekir.
		string InisNoktasi;
	
};
//kamyon yukleri
class Yuk
{
	friend ostream& operator<<(ostream& o,const Yuk &a); 
	public:
		Yuk();
		Yuk(char *icerik,double agirlik, double hacim ,string alici,string binis,string inis);
		
		~Yuk();
		Yuk(const Yuk &other);
		Yuk& operator=(const Yuk &other);
		//getter
		char* getIcerik()const;
		double getAgirlik()const;
		double getHacim()const;
		string getAlici()const;
		string getBinisNoktasi()const;
		string getInisNoktasi()const;
		//setter
		void setIcerik(char* icerik);
		void setAgirlik(double a);
		void setHacim(double h);
		void setAlici(string a);
		void setBinisNoktasi(string b);
		void setInisNoktasi(string in);
		
	private:
		char* Icerik; 			//Yükün cinsini C tarzı string olarak tutar. Dinamik bellek yönetimi gerekir.
		double Agirlik;			//Yükün ağırlığını tutar.
		double Hacim; 			//Yükün hacmini tutar.
		string Alici;			//Yükü alacak kişinin adını ve soyadını C++ tarzı string nesnesi olarak tutar.
		string BinisNoktasi;	//Yolcunun bineceği yeri C++ tarzı string nesnesi olarak tutar.
		string InisNoktasi;		//Yolcunun ineceği yeri C++ tarzı string nesnesi olarak tutar.
};

//Soyut arac sinifi
class Arac{
	
	friend ostream& operator<<(ostream& out,const Arac &s); 
	public: 
	
		virtual void yaz(ostream& out) const =0;
		Arac();
		Arac(char *Plaka1,list<Surucu>Suruculer1);
		
		//dynamic 
		virtual ~Arac();
		Arac(const Arac &other);
		Arac& operator =(const Arac &other);
		//getter
		char* getPlaka() const;
		list<Surucu> getSurucu() const;
		//setter
		void setPlaka(char* plaka1);
		void setSurucu(list<Surucu>Suruculer1);
		
	private:
		char* Plaka;
		list<Surucu>Suruculer;
};

//arac sinifina ait otobus
class Otobus: public Arac{
	friend ostream& operator<<(ostream& out,const Otobus &a);
	 
	public:
		void yaz(ostream& out) const;
		Otobus();
		Otobus(char* Plaka1,list<Surucu>Suruculer1,vector<Yolcu>other);
		
		//getter-setter
		vector<Yolcu> getYolcu()const;
		void setYolcu(vector<Yolcu>Yolcular1);

	private:
		vector<Yolcu>Yolcular;	//Otobüste yolculuk eden yolcular bir stl vektör içinde tutulmaktadır.
};
//arac sinifina ait kamyon
class Kamyon: public Arac{
	friend ostream& operator<<(ostream& out,const Kamyon &s); 
	
	public:
		void yaz(ostream& out) const;
		
		Kamyon();
		Kamyon(char* Plaka1,list<Surucu>Suruculer1,char *soz,vector<Yuk>other);
		
		virtual ~Kamyon();
		Kamyon(const Kamyon &other);
		Kamyon& operator =(const Kamyon &other);
		
		//getter-setter
		char* getOzluSoz()const;
		vector<Yuk> getYuk()const;
		void setOzluSoz(char * soz);
		void setYuk(vector<Yuk>Yukler1);
		
	private:
		char* OzluSoz;			//Kamyonun üzerine yazılı aydınlatıcı, özlü sözdür. C tarzı string olarak tutulur ve dinamik bellek yönetimi gerekir.
		vector<Yuk>Yukler;		//Kamyonda taşınan yükler bir stl vektör içinde tutulmaktadır.
};


