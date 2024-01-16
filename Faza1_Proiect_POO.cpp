//Domeniul ales: ANATOMIE

#include <iostream>
#include <fstream>
#include <typeinfo> 

using namespace std;

//PRIMA CLASA ABSTRACTA

class Organism
{
public:

	virtual void afisareDetalii() = 0; //pura
};

//A DOUA CLASA ABSTRACTA

class SistemMuscular
{
public:
	
	virtual void afisareDetaliim() = 0;
};

//PRIMA CLASA

class Corp: public Organism
{
private:

	const float id;
	static int nrMembre;
	int inaltime;
	float greutate;
	char* tipCorporal;

public:

	void afisareDetalii()
	{
		cout << "Corpul are inaltimea de " << this->getInaltime() <<" si gretatea de " << getGreutate() <<" kilograme." << endl;
	}

	//primul constructor

	Corp() : id(1.1)
	{
		this->inaltime = 172;
		this->greutate = 64.5;
		this->tipCorporal = new char[strlen("ectomorf") + 1];
		strcpy_s(this->tipCorporal, strlen("ectomorf") + 1, "ectomorf");
	}

	//al doilea constructor

	Corp(float idNou, float greutateNoua) : id(idNou)
	{
		this->inaltime = 180;
		this->greutate = greutateNoua;
		this->tipCorporal = new char[strlen("mezomorf") + 1];
		strcpy_s(this->tipCorporal, strlen("mezomorf") + 1, "mezomorf");
	}

	//al treilea constructor

	Corp(float idNou, int inaltimeNoua, float greutateNoua, char* tipCorporalNou) : id(idNou), inaltime(inaltimeNoua), greutate(greutateNoua)
	{
		this->tipCorporal = new char[strlen(tipCorporalNou) + 1];
		strcpy_s(this->tipCorporal, strlen(tipCorporalNou) + 1, tipCorporalNou);
	}

	//constructor de copiere

	Corp(const Corp& c) :id(c.id)
	{
		this->inaltime = c.inaltime;
		this->greutate = c.greutate;
		this->tipCorporal = new char[strlen("mezomorf") + 1];
		strcpy_s(this->tipCorporal, strlen(c.tipCorporal) + 1, c.tipCorporal);
	}

	//destructor

	virtual ~ Corp()
	{
		if(this->tipCorporal!=NULL)
		delete[]this->tipCorporal;
	}


	//afisare

		/*void afisare()
		{
			cout << "-----------------------------------------------------------------------------------------------------" << endl;
			cout << id << endl<<"Aceasta persoana are " << greutate << " kilograme si o inaltme de " << inaltime << " centimetri." << endl;
			cout << "Are " << nrMembre << " membre." << endl;
			cout << "Tipul corporal este " << tipCorporal << "." << endl;
			cout << "-----------------------------------------------------------------------------------------------------" << endl;
			cout << endl;
		}*/

		//getteri

	const float getId()
	{
		return this->id;
	}

	static int getNrMembre()
	{
		return nrMembre;
	}

	int getInaltime()
	{
		return this->inaltime;
	}

	float getGreutate()
	{
		return this->greutate;
	}

	char* getTipCorporal()
	{
		return this->tipCorporal;
	}

	//setteri

	static void setNrMembre(int nrMembreN)
	{
		Corp::nrMembre = nrMembreN;
	}

	void setInaltime(int inaltimeN)
	{
		this->inaltime = inaltimeN;
	}

	void setGreutate(float greutateN)
	{
		this->greutate = greutateN;
	}

	void setTipCorporal(char* tipCorporalN)
	{
		if (this->tipCorporal != NULL)
			delete[]this->tipCorporal;
		this->tipCorporal = new char[strlen(tipCorporalN) + 1];
		strcpy_s(tipCorporal, strlen(tipCorporalN) + 1, tipCorporalN);
	}

	//functiile prietene

	friend ostream& operator<<(ostream& ecran, const Corp& c);
	friend istream& operator>>(istream& tastatura, Corp& c);

	//supraincarcare operator =

	Corp& operator=(const Corp& c)
	{
		if (this != &c)
		{
			if (this->tipCorporal != NULL)
			{
				delete[]this->tipCorporal;

			}
			this->inaltime = c.inaltime;
			this->greutate = c.greutate;
			this->tipCorporal = new char[strlen(c.tipCorporal) + 1];
			strcpy_s(this->tipCorporal, strlen(c.tipCorporal) + 1, c.tipCorporal);

		}

		return *this;
	}

	//supraincarcare operator >

	bool operator>(const Corp& c) const
	{
		return this->inaltime > c.inaltime;
	}

	//supraincarcare operator <

	bool operator<(const Corp& c)const
	{
		return this->greutate < c.greutate;
	}

	//supaincarcare operator ==

	bool operator==(const Corp& c) const
	{
		return this->inaltime == c.inaltime;
	}

	//SCRIERE FISIER TEXT

	friend ofstream& operator<<(ofstream& fisier, const Corp& c)
	{
		fisier << c.inaltime << endl;
		fisier << c.greutate << endl;
		fisier << c.tipCorporal << endl;
		return fisier;
	}

	//CITIRE FISIER TEXT

	friend ifstream& operator>>(ifstream& fisier, Corp& c)
	{
		fisier >> c.inaltime;
		fisier >> c.greutate;
		if (c.tipCorporal != NULL)
			delete[]c.tipCorporal;
		char tip[50] = {};
		fisier >> tip;
		c.tipCorporal = new char[strlen(tip) + 1];
		strcpy_s(c.tipCorporal, strlen(tip) + 1, tip);
		return fisier;
	}
};

int Corp::nrMembre = 4;


//functii globale pietene
//ostream

ostream& operator<<(ostream& ecran, const Corp& c)
{
	ecran << "-----------------------------------------------------------------------------------------------------" << endl;
	ecran << c.id << endl << "Aceasta persoana are " << c.greutate << " kilograme si o inaltme de " << c.inaltime << " centimetri." << endl;
	ecran << "Are " << c.nrMembre << " membre." << endl;
	ecran << "Tipul corporal este " << c.tipCorporal << "." << endl;
	ecran << "-----------------------------------------------------------------------------------------------------" << endl;
	ecran << endl;

	return ecran;
}

//istream

istream& operator>>(istream& tastatura, Corp& c)
{
	c.tipCorporal = new char[80];
	cout << "Intoduceti greutatea persoanei:";
	tastatura >> c.greutate;
	cout << "Intoduceti inaltimea persoanei:";
	tastatura >> c.inaltime;
	cout << "Introduceti tipul corporal (ectomorf, endomorf, mezomorf):";
	tastatura >> c.tipCorporal;
	cout << endl;
	return tastatura;

}





//A DOUA CLASA

class Organ
{
private:

	const float id;
	static int nrOrgan;
	float greutate;
	bool esteSanatos;
	char* denumire;

public:

	//primul constructor

	Organ() : id(2.1)
	{
		this->greutate = 250;
		this->esteSanatos = 1;
		this->denumire = new char[strlen("inima") + 1];
		strcpy_s(denumire, strlen("inima") + 1, "inima");
	}

	//al doilea constructor

	Organ(float idNou, float greutateNoua) : id(2.2)
	{
		this->greutate = greutateNoua;
		this->esteSanatos = 0;
		this->denumire = new char[strlen("pancreas") + 1];
		strcpy_s(denumire, strlen("pancreas") + 1, "pancreas");
	}

	//al treilea constructor

	Organ(float idNou, float greutateNoua, bool esteSanatosNou, char* denumireNoua) : id(idNou), greutate(greutateNoua), esteSanatos(esteSanatosNou)
	{
		this->denumire = new char[strlen(denumireNoua) + 1];
		strcpy_s(denumire, strlen(denumireNoua) + 1, denumireNoua);
	}

	//constructor de copiere

	Organ(const Organ& o) : id(o.id)
	{
		this->greutate = o.greutate;
		this->esteSanatos = o.esteSanatos;
		this->denumire = new char[strlen(o.denumire)+1];
		strcpy_s(this->denumire, strlen(o.denumire) + 1, o.denumire);
	}

	//destructor

	~Organ()
	{
		if(this->denumire!=NULL)
		delete[]this->denumire;
	}

	//afisare

		/*void afisare()
		{
			cout << "-----------------------------------------------------------------------------------------------------" << endl;
			cout << id << " Organul este: " << denumire << " si are o greutate de aproximativ " << greutate << " de grame. Acesta " << (esteSanatos ? "este" : "nu este") << " sanatos. " << endl;
			cout << "Se afla " << nrOrgan << " in corp." << endl;
			cout << "-----------------------------------------------------------------------------------------------------" << endl;
			cout << endl;
		}*/

		//getteri

	const float getId()
	{
		return this->id;
	}

	static int getNrOrgan()
	{
		return nrOrgan;
	}

	float getGreutate()
	{
		return this->greutate;
	}

	bool getEsteSanatos()
	{
		return this->esteSanatos;
	}

	char* getDenumire()
	{
		return this->denumire;
	}

	//setteri

	static void setNrOrgan(int nrOrganN)
	{
		Organ::nrOrgan = nrOrganN;
	}

	void setGreutate(float greutateN)
	{
		this->greutate = greutateN;
	}

	void setEsteSanatos(bool esteSanatosN)
	{
		this->esteSanatos = esteSanatosN;
	}

	void setDenumire(char* denumireN)
	{
		if (this->denumire != NULL)
			delete[]this->denumire;
		this->denumire = new char[strlen(denumireN)+1];
		strcpy_s(denumire, strlen(denumireN) + 1, denumireN);
	}

	//functii prietene

	friend ostream& operator<<(ostream& ecran, const Organ& o);
	friend istream& operator>>(istream& tastatura, Organ& o);

	// supraincarcare operator =

	Organ& operator=(const Organ& o)
	{
		if (this != &o)
		{
			if (this->denumire != NULL)
			{
				delete[]this->denumire;

			}
			this->greutate = o.greutate;
			this->esteSanatos = o.esteSanatos;
			this->denumire = new char[strlen(o.denumire) + 1];
			strcpy_s(this->denumire, strlen(o.denumire) + 1, o.denumire);

		}
		return *this;
	}

	//supraincarcare operator !=

	bool operator!=(const Organ& o) const
	{
		return this->greutate != o.greutate;
	}

	//supraincarcare operator +

	friend Organ operator+(float greutate, const Organ& o)
	{
		Organ aux = o;
		aux.greutate = o.greutate + greutate;
		return aux;
	}

	//SCRIERE FISIER TEXT

	friend ofstream& operator<<(ofstream& fisier, const Organ& o)
	{
		fisier << o.greutate << endl;
		fisier << o.esteSanatos << endl;
		fisier << o.denumire << endl;
		return fisier;
	}

	//CITIRE FISIER TEXT

	friend ifstream& operator>>(ifstream& fisier, Organ& o)
	{
		fisier >> o.greutate;
		fisier >> o.esteSanatos;
		if (o.denumire != NULL)
			delete[]o.denumire;
		char den[50] = {};
		fisier >> den;
		o.denumire = new char[strlen(den) + 1];
		strcpy_s(o.denumire, strlen(den) + 1, den);
		return fisier;
	}

};

int Organ::nrOrgan = 1;

ostream& operator<<(ostream& ecran, const Organ& o)
{
	ecran << "-----------------------------------------------------------------------------------------------------" << endl;
	ecran << o.id << " Organul este: " << o.denumire << " si are o greutate de aproximativ " << o.greutate << " de grame. Acesta " << (o.esteSanatos ? "este" : "nu este") << " sanatos. " << endl;
	ecran << "Se afla " << o.nrOrgan << " in corp." << endl;
	ecran << "-----------------------------------------------------------------------------------------------------" << endl;
	ecran << endl;

	return ecran;
}

istream& operator>>(istream& tastatura, Organ& o)
{
	o.denumire = new char[80];
	cout << "Intoduceti denumirea organului: ";
	tastatura >> o.denumire;
	cout << "Introduceti greutatea organului (in grame): ";
	tastatura >> o.greutate;
	cout << "Organul este sanatos? (0-NU , 1-DA): ";
	tastatura >> o.esteSanatos;
	cout << "Introduceti numarul de bucati al organului: (exemplu: 1 pentru creier, 2 pentru rinichi) : ";
	tastatura >> o.nrOrgan;

	return tastatura;
}





//A TREIA CLASA

class Muschi: public SistemMuscular 
{
private:
	const float id;
	static int nrMuschi;
	int masa;
	float lungime;
	char* nume;

public:

	void afisareDetaliim()
	{
		cout << "Masa muschiului este: " << getMasa() <<" grame si lungimea muschiului este: "<< getLungime() << " cm."<<endl;
	}
	//primul constructor

	Muschi() : id(3.1)
	{
		this->masa = 250;
		this->lungime = 10.3;
		this->nume = new char[strlen("biceps") + 1];
		strcpy_s(nume, strlen("biceps") + 1, "biceps");
	}

	//al doilea constructor 

	Muschi(float idNou, int masaNoua) : id(idNou), masa(masaNoua)
	{
		this->lungime = 10;
		this->nume = new char[strlen("triceps") + 1];
		strcpy_s(nume, strlen("triceps") + 1, "triceps");
	}

	//al treilea constructor

	Muschi(float idNou, int masaNoua, float lungimeNoua, char* numeNou) : id(idNou), masa(masaNoua), lungime(lungimeNoua)
	{
		this->nume = new char[strlen(numeNou) + 1];
		strcpy_s(nume, strlen(numeNou) + 1, numeNou);
	}

	//constructor de copiere

	Muschi(const Muschi& m) : id(m.id)
	{
		this->masa = m.masa;
		this->lungime = m.lungime;
		this->nume = new char[strlen(m.nume)+1];
		strcpy_s(this->nume, strlen(m.nume) + 1, m.nume);
	}

	//destructor

	virtual ~Muschi()
	{
		if(this->nume!=NULL)
		delete[]this->nume;
	}

	//afisre

		//void afisare()
		//{
		//	cout << "-----------------------------------------------------------------------------------------------------" << endl;
		//	cout << id << ". Denumirea muschiului este: " << nume << " are o greutate de " << masa << " grame si o lungime de " << lungime << " cm. " << endl;
		//	cout << "Numarul aproximativ de muschi din corp este: " << nrMuschi << endl;
		//	cout << "-----------------------------------------------------------------------------------------------------" << endl;
		//	cout << endl;
		//}

	//getteri

	const float getId()
	{
		return this->id;
	}

	static int getNrMuschi()
	{
		return nrMuschi;
	}

	int getMasa()
	{
		return this->masa;
	}

	float getLungime()
	{
		return this->lungime;
	}

	char* getNume()
	{
		return this->nume;
	}

	//setteri

	static void setNrMuschi(int nrMuschiN)
	{
		nrMuschi = nrMuschiN;
	}

	void setMasa(int masaN)
	{
		this->masa = masaN;
	}

	void setLungime(float lungimeN)
	{
		this->lungime = lungimeN;
	}

	void setNume(char* numeN)
	{
		if (this->nume != NULL)
			delete[]this->nume;
		this->nume = new char[strlen(numeN)+1];
		strcpy_s(nume, strlen(numeN) + 1, numeN);
	}


	//functii prietene

	friend istream& operator>>(istream& tastatura, Muschi& m);
	friend ostream& operator<<(ostream& ecran, const Muschi& m);

	//supraincarcare operator =

	Muschi& operator=(const Muschi& m)
	{
		if (this != &m)
		{
			if (this->nume != NULL)
			{
				delete[]this->nume;

			}
			this->masa = m.masa;
			this->lungime = m.lungime;
			this->nume = new char[strlen(m.nume) + 1];
			strcpy_s(this->nume, strlen(m.nume) + 1, m.nume);

		}
		return *this;
	}

	//supraincarcare operator ++

		Muschi& operator++(int)
		{
			Muschi copie = *this;
			this->masa = masa + 1;
			if(nume!=NULL)
				delete[]this->nume;
			nume = new char[strlen(copie.nume) + 1];
			strcpy_s(nume, strlen(copie.nume) + 1, copie.nume);
			return *this;
		}


		//supraincarcare operator >=

	bool operator>=(const Muschi& m)const
	{
		return this->masa >= m.masa;
	}

	//SCRIERE FISIER 

	friend ofstream& operator<<(ofstream& fisier, const Muschi& m)
	{
		fisier << m.masa << endl;
		fisier << m.lungime << endl;
		fisier << m.nume << endl;
		return fisier;
	}

	//CITIRE FISIER 

	friend ifstream& operator>>(ifstream& fisier, Muschi& m)
	{
		fisier >> m.masa;
		fisier >> m.lungime;
		if (m.nume != NULL)
			delete[]m.nume;
		char num[50] = {};
		fisier >> num;
		m.nume = new char[strlen(num) + 1];
		strcpy_s(m.nume, strlen(num) + 1, num);
		return fisier;
	}

};

int Muschi::nrMuschi = 500;

//functii globale prietene
//ostream

ostream& operator<<(ostream& ecran, const Muschi& m)
{
	ecran << "-----------------------------------------------------------------------------------------------------" << endl;
	ecran << m.id << ". Denumirea muschiului este: " << m.nume << " are o greutate de " << m.masa << " grame si o lungime de " << m.lungime << " cm. " << endl;
	ecran << "Numarul aproximativ de muschi din corp este: " << m.nrMuschi << endl;
	ecran << "-----------------------------------------------------------------------------------------------------" << endl;
	ecran << endl;

	return ecran;
}

//istream

istream& operator>>(istream& tastatura, Muschi& m)
{
	m.nume = new char[80];
	cout << "Introduceti denumirea muschiului: ";
	tastatura >> m.nume;
	cout << "Introduceti greutatea muschiului(grame): ";
	tastatura >> m.masa;
	cout << "Introduceti lungimea muschiului(cm): ";
	tastatura >> m.lungime;

	return tastatura;
}

//relatie has-a
//A PATRA CLASA

class Tesut 
{

private:

	string denumireTesut;
	string functie;
	Organ organ;
	Organism *org;

public:

	void organismDetalii()
	{
		cout << "Tipul organismului din tesut este: " << typeid(*(this->org)).name()<<endl; 
	}

	//getteri

	string getDenumireTesut()
	{
		return this->denumireTesut;
	}

	string getFunctie()
	{
		return this->functie;
	}

	Organ getOrgan()
	{
		return this->organ;
	}


	//setteri

	void setOrgan(Organ organN)
	{
		this->organ = organN;
	}

	void setDenumireTesut(string denumireTestutN)
	{
		this->denumireTesut = denumireTestutN;
	}

	void setFunctie(string functieN)
	{
		this->functie = functieN;
	}

	//functii prietene

	friend ostream& operator<<(ostream& ost, const Tesut& t);
	friend istream& operator>>(istream& tastatura, Tesut& t);

	//constructor fara parametri

	Tesut(): organ()
	{
		this->denumireTesut = "epitelial";
		this->functie = "protectie";
		this->org = new Corp();
	}

	//constructor cu trei parametri

	Tesut(string denumireTesutN, string functieN, Organism* orgN) : denumireTesut(denumireTesutN), functie(functieN) , organ()
	{
		this->org = orgN;
	}

	

	//constructor de copiere

	Tesut(const Tesut& t)
	{
		this->denumireTesut = t.denumireTesut;
		this->functie = t.functie;
		this->organ = t.organ;
	}

	//destructor

	~Tesut()
	{
		if (this->org != NULL)
			delete[]this->org;
	}

	//operatorul =

	Tesut& operator=(const Tesut& t)
	{
		if (this != &t)
		{
			this->denumireTesut = t.denumireTesut;
			this->functie = t.functie;
			this->organ = t.organ;
		}
		return *this;
	}

	////SCRIERE FISIER 

	friend ofstream& operator<<(ofstream& fisier, const Tesut& t)
	{
		fisier << t.denumireTesut;
		fisier << t.functie;
		fisier << t.organ;
		return fisier;
	}

	//CITIRE FISIER 

	friend ifstream& operator>>(ifstream& fisier, Tesut& t)
	{
		fisier >> t.denumireTesut;
		return fisier;
	}

};

//ostream

ostream& operator<<(ostream& ost, const Tesut& t)
{
	ost << "-----------------------------------------------------------------------------------------------------" << endl;
	ost << "Orgnul este alcatuit dintr-un tesut " << t.denumireTesut << "." << endl;
	ost << "Functia tesutului este de " << t.functie << "." << endl;
	ost << "Detalii despre organ:" << endl << t.organ << endl;
	return ost;
}

//istream

istream& operator>>(istream& tastatura, Tesut& t)
{
	cout << "Introduceti denumirea tesutului organului (epitelial, muscular conjunctiv, nervos): ";
	cin >> t.denumireTesut;
	cout << "Introduceti functia tesutului (de protectie, de transport, de secretie etc.): ";
	cin >> t.functie;

	return tastatura;

}


//Relatie is-a 
//A CINCEA CLASA 

class CorpSanatos : public Corp
{
private:

	float tensiune;
	int puls;
	int glicemie;

public:

	void afiseazaDetalii()
	{
		cout << "Tensiunea persoanei este: " << getTensiune() << " ,pulsul este: "<<getPuls() <<" ,iar glcemia este: "<< getGlicemie() << endl;
	}

	//constructor fara parametri

	CorpSanatos() : Corp()
	{
		this->tensiune = 120.82;
		this->puls = 89;
		this->glicemie = 103;
	}

	//constructor cu un parametru

	CorpSanatos(float pulsN, int glicemieN) : Corp(1.9, 79)
	{
		this->puls = pulsN;
		this->glicemie = glicemieN;
		this->tensiune = 129.85;
	}

	//Constructor de copiere

	CorpSanatos(const CorpSanatos& cs) :Corp(cs)
	{
		this->tensiune = cs.tensiune;
		this->puls = cs.puls;
		this->glicemie = cs.glicemie;
	}

	//destructor

	~CorpSanatos()
	{

	}

	//getteri

	float getTensiune()
	{
		return this->tensiune;
	}

	int getPuls()
	{
		return this->puls;
	}

	int getGlicemie()
	{
		return this->glicemie;
	}

	//setteri

	void setTensiune(float tensiuneN)
	{
		this->tensiune = tensiuneN;
	}

	void setPuls(int pulsN)
	{
		this->puls = pulsN;
	}

	void setGlicemie(int glicemieN)
	{
		this->glicemie = glicemieN;
	}

	//Operator =

	CorpSanatos operator=(const CorpSanatos& cs)
	{
		if (this != &cs)
		{
		
			this->tensiune = cs.tensiune;
			this->puls = cs.puls;
			this->glicemie = cs.glicemie;
			
		}
		return *this;
	}



	//functii prietene

	friend ostream& operator<<(ostream& ost, const CorpSanatos& cs);
	friend istream& operator>>(istream& tastatura, CorpSanatos& cs);

};

ostream& operator<<(ostream& ost, const CorpSanatos& cs)
{
	ost << "-----------------------------------------------------------------------------------------------------" << endl;
	ost << "Persoana are tensiunea egala cu: " << cs.tensiune << endl;
	ost << "Pulsul este egal cu: " << cs.puls << endl;
	ost << "Glicemia este egala cu: " << cs.glicemie << endl;
	ost << "-----------------------------------------------------------------------------------------------------" << endl;
	return ost;
}

istream& operator>>(istream& tastatura, CorpSanatos& cs)
{
	cout << "Introduceti tensiunea persoanei: ";
	tastatura >> cs.tensiune;
	cout << "Introduceti pulsul persoanei: ";
	tastatura >> cs.puls;
	cout << "Introduceti glicemia persoanei: ";
	tastatura >> cs.glicemie;
	return tastatura;
}

//A SASEA CLASA

class MuschiIntins : public Muschi
{
private:

	int gradIntindere;
	string detaliiIntindere;
	int nrSaptamaniRecuperare;
	//daca numarul de saptamani de recuperare este mai mare de 1  si mai mic de 12 atunci
	//returneaza vizita la spital periodica
	// daca numarul de saptamani de recuperare este mai mare de 12  atunci kinetoterapie

public:

	void afisareDetaliim()
	{
		cout << "Numarul de saptamani de recuperare este:" << getNrSaptamaniRecuperare() << endl;
	}

	//constructor fara parametri

	MuschiIntins() : Muschi()
	{
		this->gradIntindere = 1;
		this->detaliiIntindere = "usoara";
		this->nrSaptamaniRecuperare = 1;

	}

	//constructor cu un parametru

	MuschiIntins(int gradIntindereN) : Muschi()
	{
		this->gradIntindere = gradIntindereN;
		if (this->gradIntindere == 1)
		{
			this->detaliiIntindere = "usoara";
			this->nrSaptamaniRecuperare = 2;
		}
		else
			if (this->gradIntindere == 2)
			{
				this->detaliiIntindere = "moderata";
				this->nrSaptamaniRecuperare = 8;
			}
			else
				if (this->gradIntindere == 3)
				{
					this->detaliiIntindere = "grava";
					this->nrSaptamaniRecuperare = 14;
				}
	}
	
	MuschiIntins(int nrSaptamaniRecuperareN,int gradIntindereN) : Muschi()
	{
		this->gradIntindere = gradIntindereN;
		this->detaliiIntindere = "moderata";
		this->nrSaptamaniRecuperare = nrSaptamaniRecuperareN;
	}

	//destructor

	~MuschiIntins()
	{

	}

	//getteri

	int getGradIntindere()
	{
		return this->gradIntindere;
	}

	string getDetaliiIntindere()
	{
		return this->detaliiIntindere;
	}

	int getNrSaptamaniRecuperare()
	{
		return this->nrSaptamaniRecuperare;
	}

	//setteri

	void setGradIntindere(int gradIntindereN)
	{
		this->gradIntindere = gradIntindereN;
	}

	void setDetaliiIntindere(string detaliiIntindereN)
	{
		this->detaliiIntindere = detaliiIntindereN;
	}

	void setNrSaptamaniRecuperare(int nrSaptamaniRecuperareN)
	{
		this->nrSaptamaniRecuperare = nrSaptamaniRecuperareN;
	}

	//Operator =

	MuschiIntins operator=(const MuschiIntins& mi)
	{
		if (this != &mi)
		{
			this->gradIntindere = mi.gradIntindere;
			this->detaliiIntindere = mi.detaliiIntindere;
			this->nrSaptamaniRecuperare = mi.nrSaptamaniRecuperare;
		}
		return *this;
	}

	//Constructor de copiere

	MuschiIntins(const MuschiIntins& mi)
	{
		gradIntindere = mi.gradIntindere;
		detaliiIntindere = mi.detaliiIntindere;
		nrSaptamaniRecuperare = mi.nrSaptamaniRecuperare;
	}

	//functii prietene
	friend ostream& operator<<(ostream& ecran, const MuschiIntins& mi);
	friend istream& operator>>(istream& tastatura, MuschiIntins& mi);

};

ostream& operator<<(ostream& ecran, const MuschiIntins& mi)
{
	ecran << "-----------------------------------------------------------------------------------------------------" << endl;
	ecran << "Muschiul are o intindere de gradul " << mi.gradIntindere << ". Este o intindere " << mi.detaliiIntindere <<"." << endl;
	if (mi.nrSaptamaniRecuperare == 1)
		ecran << "Este necesara o saptamana de recuperare."<<endl;
	else
		ecran << "Sunt necesare " << mi.nrSaptamaniRecuperare << " saptamani de recuperare."<<endl;
	ecran << "-----------------------------------------------------------------------------------------------------" << endl;
	return ecran;
}

istream& operator>>(istream& tastatura, MuschiIntins& mi)
{
	cout << "Introduceti gradul de intindere al muschiului (1,2 sau 3): ";
	tastatura >> mi.gradIntindere;
	cout << "Introduceti detalii despre intindere: (usoara, moderata, grava): ";
	tastatura >> mi.detaliiIntindere;
	cout << "Introduceti numarul de saptamani de recuperare: ";
	tastatura >> mi.nrSaptamaniRecuperare;
	return tastatura;
}


void main()
{
	
		//PRIMA CLASA
	
		//apelare + afisare constructor1
	
		cout << "Apel primul constructor:" << endl << endl;
	
		Corp persoana1;
		cout << persoana1;
	
		//apelare + afisare constructor2
	
		cout << "Apel al doilea constructor:" << endl << endl;
	
		Corp persoana2(1.2, 48.7);
		cout << persoana2;
	
		char* tipCorporal = new char[strlen("endomorf") + 1];
		strcpy_s(tipCorporal, strlen("endomorf") + 1, "endomorf");
	
		//apelare + afisare constructor3
	
		cout << "Apel al treilea constructor:" << endl << endl;
	
		Corp persoana3(1.3, 193, 80.4, tipCorporal);
		persoana3.setNrMembre(3);
		cout << persoana3;
	
		//getteri si setteri
	
		cout << "Getter:" << endl << endl;
	
		Corp persoana4;
		cout << "-----------------------------------------------------------------------------------------------------" << endl;
		cout << persoana4.getId() << endl << "Aceasta persoana are " << persoana4.getGreutate() << " kilograme si o inaltme de " << persoana4.getInaltime() << " centimetri." << endl;
		cout << "Are " << persoana4.getNrMembre() << " membre." << endl;
		cout << "Tipul corporal este " << persoana4.getTipCorporal() << "." << endl;
		cout << "-----------------------------------------------------------------------------------------------------" << endl;
		cout << endl;
	
		cout << "Setter:" << endl << endl;
		char* tipCorporal1 = new char[strlen("mezomorf") + 1];
		strcpy_s(tipCorporal1, strlen("mezomorf") + 1, "mezomorf");
	
		persoana4.setGreutate(73.1);
		persoana4.setInaltime(175);
		persoana4.setNrMembre(4);
		persoana4.setTipCorporal(tipCorporal1);
	
		cout << "-----------------------------------------------------------------------------------------------------" << endl;
		cout << persoana4.getId() << endl << "Aceasta persoana are " << persoana4.getGreutate() << " kilograme si o inaltme de " << persoana4.getInaltime() << " centimetri." << endl;
		cout << "Are " << persoana4.getNrMembre() << " membre." << endl;
		cout << "Tipul corporal este " << persoana4.getTipCorporal() << "." << endl;
		cout << "-----------------------------------------------------------------------------------------------------" << endl;
		cout << endl;
	
		//apel functii prietene
		//ostream
	
		Corp persoana5;
		cout << "Apel ostream:" << endl << endl;
		cout << persoana5;
	
		//istream
	
		Corp persoana6;
		cout << "Apel istream:" << endl << endl;
		cin >> persoana6;
		cout << persoana6;
	
		//operator =
	
		cout << "Operator =: " << endl << endl;
		persoana6 = persoana2;
		cout << persoana6;
	
		//operator >
	
		cout << "Operator >: " << endl << endl;
		cout << "Prima persoana (persoana1): " << endl << endl;
		cout << persoana1 << endl;
		cout << "A doua persoana (persoana2): " << endl << endl;
		cout << persoana2 << endl;
		if (persoana2 > persoana1)
			cout << "A doua persoana este mai inalta decat prima persoana." << endl<<endl;
		else
			cout << "Prima persoana este mai inalta decat a doua persoana." << endl<<endl;
	
		//operator <
	
		cout << " Operator <: " << endl << endl;
		cout << "Prima persoana (persoana6): " << endl << endl;
		cout << persoana6 << endl;
		cout << "A doua persoana (persoana3): " << endl << endl;
		cout << persoana3 << endl;
		if (persoana6 < persoana3)
			cout << "Prima persoana este mai slaba decat a doua." << endl<<endl;
		else
			cout << "A doua persoana este mai slaba decat prima." << endl<<endl;
	
		//operator ==
	
		cout << " Operator ==: " << endl << endl;
		cout << "Prima persoana (persoana4): " << endl << endl;
		cout << persoana4 << endl;
		cout << "A doua persoana (persoana5): " << endl << endl;
		cout << persoana5 << endl;
		if (persoana4 == persoana5)
			cout << "Cele doua persoane au aceeasi inaltime" << endl;
		else
			cout << "Cele doua persoane nu au aceeasi inaltime" << endl;
	
	
	
	
	
		//A DOUA CLASA
	
		cout << endl << endl;
		cout << "A doua clasa:" << endl << endl;
	
		//apel + afisare constructor1
	
		cout << "Apel primul constructor:" << endl << endl;
		Organ organ1;
		cout << organ1;
	
		//apel + afisare constructor2
	
		cout << "Apel al doilea constructor:" << endl << endl;
		Organ organ2(2.2, 70);
		cout << organ2;
	
		//apel + afisare constructor3
	
		cout << "Apel al treilea constructor:" << endl << endl;
		char* denumire = new char[strlen("plaman") + 1];
		strcpy_s(denumire, strlen("plaman") + 1, "plaman");
		Organ organ3(2.3, 600, 1, denumire);
		organ3.setNrOrgan(2);
		cout << organ3;
	
		//getteri si setteri
	
		cout << "Getter:" << endl << endl;
	
		Organ organ4;
		organ4.setNrOrgan(1);
		cout << "-----------------------------------------------------------------------------------------------------" << endl;
		cout << organ4.getId() << " Organul este: " << organ4.getDenumire() << " si are o greutate de aproximativ " << organ4.getGreutate() << " de grame. Acesta " << (organ4.getEsteSanatos() ? "este" : "nu este") << " sanatos. " << endl;
		cout << "Se afla " << organ4.getNrOrgan() << " in corp." << endl;
		cout << "-----------------------------------------------------------------------------------------------------" << endl;
		cout << endl;
	
		cout << "Setter:" << endl << endl;
		char* denumire1 = new char[strlen("creier") + 1];
		strcpy_s(denumire1, strlen("creier") + 1, "creier");
	
		organ4.setDenumire(denumire1);
		organ4.setEsteSanatos(1);
		organ4.setGreutate(1400);
		organ4.setNrOrgan(1);
	
		cout << "-----------------------------------------------------------------------------------------------------" << endl;
		cout << organ4.getId() << " Organul este: " << organ4.getDenumire() << " si are o greutate de aproximativ " << organ4.getGreutate() << " de grame. Acesta " << (organ4.getEsteSanatos() ? "este" : "nu este") << " sanatos. " << endl;
		cout << "Se afla " << organ4.getNrOrgan() << " in corp." << endl;
		cout << "-----------------------------------------------------------------------------------------------------" << endl;
		cout << endl;
	
		//apel functii prietene
		//ostream
	
		Organ organ5;
		cout << "Apel ostream: " << endl << endl;
		cout << organ5;
	
		//istream
	
		Organ organ6;
		cout << "Apel istream: " << endl << endl;
		cin >> organ6;
		cout << organ6;
	
		//operator =
	
		cout << "Operator =: " << endl << endl;
		organ2 = organ6;
		cout << organ6;
	
		//supraincarcare operator !=
	
		cout << "Operator !=: " << endl << endl;
		cout << "Primul organ (organ2): " << endl << endl;
		cout << organ2 << endl;
		cout << "Al doilea organ (organ6): " << endl << endl;
		cout << organ6 << endl;
		if (organ2 != organ6)
			cout << "Greutatea primului organ este diferita de greutatea celui de-al doilea organ.";
		else
			cout << "Cele doua organe au aceeasi greutate." << endl << endl;
	
		//supraincarcare operator +


		cout << "Operator +: " << endl << endl;
		cout << "Organul (organ5): " << endl << endl;
		cout << organ5 << endl;
		cout << "Dupa modificarea greutatii organului: (+10.3) ";
		organ5 = 10.3 + organ5;
		cout << endl;
		cout << organ5<<endl;
	
	
	
	
	
			//A TREIA CLASA
	
		cout << endl << endl;
		cout << "A treia clasa: " << endl << endl;
	
		//apel + afisare constructor1
	
		cout << "Primul constructor: " << endl << endl;
		Muschi muschi1;
		cout << muschi1;
	
		//apel + afisare constructor2
	
		cout << "Al doilea constructor: " << endl << endl;
		Muschi muschi2(3.2, 200);
		cout << muschi2;
	
		//apel + afisare constructor3
	
		cout << "Al treilea constructor" << endl << endl;
		char* nume = new char[strlen("cvadriceps") + 1];
		strcpy_s(nume, strlen("cvadriceps") + 1, "cvadriceps");
		Muschi muschi3(3.3, 400, 40.5, nume);
		muschi3.setNrMuschi(498);
		cout << muschi3;
	
		//getteri si setteri
	
		cout << "Getter: " << endl << endl;
	
		Muschi muschi4;
		muschi4.setNrMuschi(500);
		cout << "-----------------------------------------------------------------------------------------------------" << endl;
		cout << muschi4.getId() << ". Denumirea muschiului este: " << muschi4.getNume() << " are o greutate de " << muschi4.getMasa() << " grame si o lungime de " << muschi4.getLungime() << " cm. " << endl;
		cout << "Numarul aproximativ de muschi din corp este: " << muschi4.getNrMuschi() << endl;
		cout << "-----------------------------------------------------------------------------------------------------" << endl;
		cout << endl;
	
		cout << "Setter: " << endl << endl;
		char* nume1 = new char[strlen("trapez") + 1];
		strcpy_s(nume1, strlen("trapez") + 1, "trapez");
	
		muschi4.setNume(nume1);
		muschi4.setMasa(50);
		muschi4.setLungime(20);
		muschi4.setNrMuschi(499);
	
		cout << "-----------------------------------------------------------------------------------------------------" << endl;
		cout << muschi4.getId() << ". Denumirea muschiului este: " << muschi4.getNume() << " are o greutate de " << muschi4.getMasa() << " grame si o lungime de " << muschi4.getLungime() << " cm. " << endl;
		cout << "Numarul aproximativ de muschi din corp este: " << muschi4.getNrMuschi() << endl;
		cout << "-----------------------------------------------------------------------------------------------------" << endl;
		cout << endl;
	
		//apel functii prietene 
		//ostream
	
		Muschi muschi5;
		cout << "Apel ostream: " << endl << endl;
		cout << muschi5;
	
		//istream
	
		Muschi muschi6;
		muschi6.setNrMuschi(500);
		cout << "Apel istream: " << endl << endl;
		cin >> muschi6;
		cout << muschi6;
	
		//supraincarcare operator =
	
		cout << "Operator =: " << endl << endl;
		muschi1 = muschi6;
		cout << muschi1;
	
		//supraincarcare operator ++
	
	//Muschi muschi1;
	cout << "Operator ++:" << endl << endl;
	cout << "Muschiul este:" << endl;
	cout << muschi1<<endl;
	cout << "Adunam masa muschiului cu 1. Noua masa este:" << endl;
	muschi1++;
	cout << muschi1;
	
		//supraincarcare operator>=   
	/*char* nume = new char[strlen("cvadriceps") + 1];
	strcpy_s(nume, strlen("cvadriceps") + 1, "cvadriceps");
	Muschi muschi3(3.3, 400, 40.5, nume);*/
	//Muschi muschi2(3.2, 200);
	cout << "Operator >=: " << endl << endl;
	cout << "Primul muschi (muschi3): " << endl << endl;
	cout << muschi3 << endl;
	cout << "Al doilea muschi (muschi2): " << endl << endl;
	cout << muschi2 << endl;
	if (muschi3 >= muschi2)
		cout << "Primul muschi este mai greu sau egal cu al doilea muschi." << endl;
	else
		cout << "Al doilea muschi este mai greu sau egal cu primul muschi." << endl;
	
	
		cout << endl << endl << endl << endl;
		cout << "Vectori de obiecte:" << endl << endl;
	
		//Vector prima clasa
	
		cout << "Vector cu obiecte prima clasa(corp):" << endl;
	
		Corp* c_corp = new Corp[3];
		c_corp[0] = persoana1;
		c_corp[1] = persoana2;
		c_corp[2] = persoana3;
		for (int i = 0; i < 3; i++)
		{
			cout << "Persoana " << i + 1 << " :" << endl;
			cout << c_corp[i] << endl;
		}
	
		delete[]c_corp;
	
		//Vector a doua clasa
	
		cout << "Vector cu obiecte a doua clasa(organ):" << endl;
	
		Organ* o_organ = new Organ[4];
		o_organ[0] = organ1;
		o_organ[1] = organ2;
		o_organ[2] = organ3;
		o_organ[3] = organ4;
		for (int i = 0; i < 4; i++)
		{
			cout << "Organul " << i + 1 << " :" << endl;
			cout << o_organ[i] << endl;
		}
	
		delete[]o_organ;
	
		//Vector a treia clasa
	
		cout << "Vector cu obiecte a treia clasa(muschi):" << endl;
	
		Muschi* m_muschi = new Muschi[3];
		m_muschi[0] = muschi1;
		m_muschi[1] = muschi2;
		m_muschi[2] = muschi5;
		for (int i = 0; i < 3; i++)
		{
			cout << "Muschiul " << i + 1 << " :" << endl;
			cout << m_muschi[i] << endl;
		}
	
		delete[]m_muschi;
	
		//Matrice a treia clasa
	
		cout << endl << endl << "Matrice clasa(muschi): " << endl << endl;
		Muschi** matrice = new Muschi * [3];
		for (int i = 0; i < 3; i++)
			matrice[i] = new Muschi[3];
	
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				cout << matrice[i][j];
			}
		}
	
		for (int i = 0; i < 3; i++)
		{
			delete[] matrice[i];
		}
		delete[]matrice;
	
		//Fisier1 text
	
		cout << "Am creat primul fisier text." << endl << endl;
		Corp p7;
		ofstream c("Corp.txt", ios::app);
		c << p7;
		c.close();
	
		ifstream c1("Corp.txt", ios::in);
		c1 >> persoana1;
		cout << persoana1;
		c1.close();
	
		//Fisier2 text
	
		/*cout << "Am creat al doilea fisier text." << endl << endl;
		ofstream o("Organ.txt", ios::app);
		o << organ3;
		o.close();*/
	
		ifstream o1("Organ.txt", ios::in);
		Organ organ7(7.1, 600);
		o1 >> organ7;
		cout << organ7;
		o1.close();
		cout << endl;
	
	
	
	
		//A PATRA CLASA
	
		//apelare + afisare primul constructror;
	
		cout << "Apel primul constructor: " << endl << endl;
		Tesut tesut1;
		cout << tesut1;
	
	
		//getteri si setteri
	
		cout << "Getter: " << endl << endl;
		cout << "-----------------------------------------------------------------------------------------------------" << endl;
		cout << "Organul are un tesut " << tesut1.getDenumireTesut() << ". Functia acestuia este de " << tesut1.getFunctie()<<"." << endl;
		cout << "-----------------------------------------------------------------------------------------------------" << endl;
		cout << endl;
	
		Tesut tesut3;
		tesut3.setFunctie("protectie");
		cout << "Setter: " << endl << endl;
		cout << "-----------------------------------------------------------------------------------------------------" << endl;
		cout << "Organul are un tesut " << tesut3.getDenumireTesut() << ". Functia acestuia este de " << tesut3.getFunctie() <<"." << endl;
		cout << "-----------------------------------------------------------------------------------------------------" << endl;
		cout << endl;
	
		//apel functii prietene
		//ostream
	
		Tesut tesut4;
		tesut4.setDenumireTesut("epitelial");
		tesut4.setFunctie("secretie");
		cout << tesut4;
	
		//Fisier1 binar
	
		cout << "Am creat primul fisier binar." << endl << endl;
		fstream m("Muschi.bin", ios::out | ios::binary);
		m.write((char*)&muschi1, sizeof(Muschi));
		m.close();
	
		fstream m1("Muschi1.bin", ios::in | ios::binary);
		m1.read((char*)&muschi1, sizeof(Muschi));
		m1.close();
	
		////Fisier2 binar
	
		cout << "Am creat al doilea fisier binar." << endl << endl;
		fstream t("Tesut.bin", ios::out | ios::binary);
		t.write((char*)&tesut1, sizeof(Tesut));
		t.close();
	
		fstream t1("Tesut1.bin", ios::in | ios::binary);
		t1.read((char*)&tesut1, sizeof(Tesut));
		t1.close();
	
		//supraincarcare operator =
	
		cout << "Operator =:" << endl << endl;
		tesut1 = tesut3;
		cout << tesut1;


		//A CINCEA CLASA 


		//apelare + afisare primul constructror;

		cout << "Apel primul constructor:" << endl << endl;
	CorpSanatos cs1;
	cout << cs1;

	//apelare + afisare al doilea constructor

	cout << "Apel al doilea constructor:" << endl << endl;
	CorpSanatos cs2(98, 143);
	cout << cs2;

	//getteri si setteri

	cout << endl;
	cout << "Getter: " << endl << endl;
	cout << "-----------------------------------------------------------------------------------------------------" << endl;
	cout << "Persoana are tensiunea egala cu: " << cs2.getTensiune() << ". Pulsul este de: " << cs2.getPuls() << ", iar glicemia este egala cu: " << cs2.getGlicemie() << "." << endl;
	cout << "-----------------------------------------------------------------------------------------------------" << endl;
	cout << endl;

	cout << "Setter:" << endl;
	cs2.setGlicemie(198);
	cout << "-----------------------------------------------------------------------------------------------------" << endl;
	cout << "Persoana are tensiunea egala cu: " << cs2.getTensiune() << ". Pulsul este de: " << cs2.getPuls() << ", iar glicemia este egala cu: " << cs2.getGlicemie() << "." << endl;
	cout << "-----------------------------------------------------------------------------------------------------" << endl;
	cout << endl;

	//functii prietene
	//ostream

	CorpSanatos cs3;
	cout << "Apel ostream: " << endl << endl;
	cout << cs3;

	//istream

	CorpSanatos cs4;
	cout <<endl<< "Apel istream: " << endl << endl;
	cin >> cs4;
	cout << cs4;

	//supraincarcare operator=

	cout <<endl<< "Operator =:" << endl << endl;
	cs1 = cs2;
	cout << cs1;


	//A SASEA CLASA

	//apelare + afisare primul constructor

	cout <<endl<< "Apel primul constructor:" << endl << endl;
	MuschiIntins mi1;
	cout << mi1;

	//apelare + afisare al doilea constructor
	
	cout << "Apel al doilea constructor:" << endl << endl;
	MuschiIntins mi2(8);
	cout << mi2;

	//getteri si setteri

	cout <<endl<< "Getter: " << endl<<endl;
	cout << "-----------------------------------------------------------------------------------------------------" << endl;
	cout << "Gradul de intindere al muschiului este " << mi2.getGradIntindere() << ". Este o " << mi2.getDetaliiIntindere() << ". Numarul de saptamani de recuperare este " << mi2.getNrSaptamaniRecuperare() << endl;
	cout << "-----------------------------------------------------------------------------------------------------" << endl;
	cout << endl;

	cout << "Setter:" << endl<<endl;
	mi2.setGradIntindere(2);
	cout << "-----------------------------------------------------------------------------------------------------" << endl;
	cout << "Gradul de intindere al muschiului este " << mi2.getGradIntindere() << ". Este o " << mi2.getDetaliiIntindere() << ". Numarul de saptamani de recuperare este " << mi2.getNrSaptamaniRecuperare() << endl;
	cout << "-----------------------------------------------------------------------------------------------------" << endl;
	cout << endl;

	//functii prietene
	//ostream

	MuschiIntins mi3;
	cout << "Apel ostream: " << endl << endl;
	cout << mi3;

	//istream

	MuschiIntins mi4;
	cout <<endl<<"Apel istream: " << endl << endl;
	cin >> mi4;
	cout << mi4;

	//supraincarcare operator=

	cout << endl<<"Operator =: " << endl << endl;
	mi3 = mi4;
	cout << mi3;

	//CLASA ABSTRACTA
	char* numee = new char[strlen("late-binding") + 1];
	strcpy_s(numee, strlen("late-binding") + 1, "late-binding");

	cout << endl << "Late-binding" << endl << endl;
	SistemMuscular** sm1 = new SistemMuscular*[10];
	sm1[0] = new MuschiIntins(0,2);
	sm1[1] = new MuschiIntins(1,2);
	sm1[2] = new MuschiIntins(2,2);
	sm1[3] = new MuschiIntins(3,2);
	sm1[4] = new MuschiIntins(4,2);
	sm1[5] = new MuschiIntins(5,2);
	sm1[6] = new MuschiIntins(6,2);
	sm1[7] = new MuschiIntins(7,2);
	sm1[8] = new MuschiIntins(8,2);
	sm1[9] = new MuschiIntins(9,2);

	for (int i = 0; i < 10; i++)
	{
		sm1[i]->afisareDetaliim();
	}

	cout <<endl<< "Has-a, referire tip abstract" << endl << endl;
	Tesut tes("conjunctiv","protectie", new CorpSanatos());
	tes.organismDetalii();
	cout << endl;
	Tesut tes1("muscular","transport", new Corp());
	tes1.organismDetalii();
}
