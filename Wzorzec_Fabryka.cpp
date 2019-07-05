/*Zadanie:

Stw�rz aplikacj� symuluj�c� produkcj� jednostek w grze komputerowej. 
Produkcja ta b�dzie realizowana poprzez tworzenie nowych obiekt�w 
(jednostek) danego typu z innego obiektu b�d�cego "Fabryk�" 
(budynek produkcyjny). Oczywi�cie trzeba w tym celu 
wykorzysta� wzorzec projektowy "Fabryka".


Przyk�adowa struktura projektu symuluj�cego produkcje jednostek:

Klasy typu wyliczeniowego (ang. enumerable) 
Klasa �o�nierz - reprezentuj�ca jednostk� naziemn�. Oczywi�cie taka klasa powinna mie� swoje pola i metody,
Klasa helikopter - reprezentuj�ca jednostk� powietrzn�,
Klasa statek - reprezentuj�ca jednostk� wodn�,
Interfejsy IJednostkaNaziemna, IJednostkaPowietrzna, IJednostkaWodna - 
interfejsy s� nam potrzebne po to, �eby metoda fabryki tworz�cej obiekty 
nie zwraca�a konkretnego typu jednostki, a tylko pewien typ abstrakcyjny (interfejs).
Klasy koszary, hangar, port - klasy te reprezentuj� poszczeg�lne fabryki, kt�re b�d� produkowa� odpowiednie jednostki.
*/

#include <iostream>
#include <string>
 
using namespace std;
  
	class JednostkaNaziemna {
		public:
		virtual JednostkaNaziemna* dawajNaziemna() = 0;
		virtual ~JednostkaNaziemna() {};
	};
	 
	class JednostkaPowietrzna {
		public:
		virtual JednostkaPowietrzna* dawajPowietrzna() = 0;
		virtual ~JednostkaPowietrzna() {};
	};
	
		class JednostkaWodna {
		public:
		virtual JednostkaWodna* dawajWodna() = 0;
		virtual ~JednostkaWodna() {};
	};
	 
	class FabrykaPodzespolowObiektow {
		public:
		virtual JednostkaNaziemna* produkujemyNaziemna() = 0;
		virtual JednostkaPowietrzna* produkujemyPowietrzna() = 0;
		virtual JednostkaWodna* produkujemyWodna() = 0;
		virtual ~FabrykaPodzespolowObiektow() {}
	};
	 
	 
	class Zolnierz: public JednostkaNaziemna {
		private:
		string name;
		public:
		Zolnierz() { name = "Zolnierz"; }
		 
		JednostkaNaziemna* dawajNaziemna() {
			cout << "Dodaje " + name << endl;
			return new Zolnierz();
		}
	};
	 
	class FabrykaKoszary:
	public FabrykaPodzespolowObiektow
	{

		JednostkaNaziemna* produkujemyNaziemna() {
			return new Zolnierz();
		}
		 
		JednostkaPowietrzna* produkujemyPowietrzna() {
			return NULL;
		}
		JednostkaWodna* produkujemyWodna() {
			return NULL;
		}
	};


	 
	class Helikopter: public JednostkaPowietrzna {
		private:
		string name;
		public:
		Helikopter() { name = "Helikopter"; }
		 
		JednostkaPowietrzna* dawajPowietrzna() {
			cout << "Dodaje " + name << endl;
			return new Helikopter();
		}
	};
	 
	class FabrykaHangar:
	public FabrykaPodzespolowObiektow
	{
		public:
		JednostkaNaziemna* produkujemyNaziemna() {
			return NULL;
		}
		 
		JednostkaPowietrzna* produkujemyPowietrzna() {
			return new Helikopter();
		}
		
				JednostkaWodna* produkujemyWodna() {
			return NULL;
		}
	};
	 
	 
	 	class Statek: public JednostkaWodna {
		private:
		string name;
		public:
		Statek() { name = "Statek"; }
		 
		JednostkaWodna* dawajWodna() {
			cout << "Dodaje " + name << endl;
			return new Statek();
		}
	};
	 	class FabrykaPort:
	public FabrykaPodzespolowObiektow
	{
		
		public:	
		JednostkaNaziemna* produkujemyNaziemna() {
			return NULL;
		}
		 
		JednostkaPowietrzna* produkujemyPowietrzna() {
			return NULL;
		}
		
		JednostkaWodna* produkujemyWodna() {
			return new Statek();
		}

	};
	class Obiekt {
		protected:
		JednostkaNaziemna* naziemna; JednostkaNaziemna* naziemna_tmp;
		JednostkaPowietrzna* powietrzna; JednostkaPowietrzna* powietrzna_tmp;
		JednostkaWodna* wodna; JednostkaWodna* wodna_tmp;
		 
		virtual void skladanie() = 0;
		public:
		void produkowanieJednostek() {
			cout << "Produkowanie jednostek..." << endl;
		}
		 
		void instalowanie() {
			cout << "Instalowanie..." << endl;
		}
		 
		 
		virtual ~Obiekt() { }
	};
	 
	class Koszary: public Obiekt {
		private:
		FabrykaPodzespolowObiektow* f;
		protected:
		void skladanie() {
			naziemna_tmp = f->produkujemyNaziemna();
			naziemna = naziemna_tmp->dawajNaziemna();
		}
		public:
		Koszary(FabrykaKoszary* fKoszary) : f(fKoszary) {
			skladanie();
		}
		 
		~Koszary() {
			delete naziemna_tmp; delete naziemna;
			delete f;
		}
	};
	 
	class Hangar: public Obiekt {
		private:
		FabrykaPodzespolowObiektow* f;
		protected:
		void skladanie() {
			powietrzna_tmp = f->produkujemyPowietrzna();
			powietrzna = powietrzna_tmp->dawajPowietrzna();
		}
		public:
		Hangar(FabrykaHangar *fHangar) : f(fHangar) {
			skladanie();
		}
		 
		~Hangar() {
			delete powietrzna_tmp; delete powietrzna;
			delete f;
		}
	};
	 
	 	class Port: public Obiekt {
		private:
		FabrykaPodzespolowObiektow* f;
		protected:
		void skladanie() {
			wodna_tmp = f->produkujemyWodna();
			wodna = wodna_tmp->dawajWodna();
		}
		public:
		Port(FabrykaPort* fPort) : f(fPort) {
			skladanie();
		}
		 
		~Port() {
			delete wodna_tmp; delete wodna;
			delete f;
		}
	};
	class FabrykaObiektow {
	private:
	Obiekt* zlozObiekt(string model) {
	Obiekt* obiekt;
	if("Koszary" == model)
	obiekt = new Koszary(new FabrykaKoszary());
	else if ("Hangar" == model)
	obiekt = new Hangar(new FabrykaHangar());
	else
	 obiekt = new Port(new FabrykaPort());
	 
	return obiekt;
	}
	public:
	Obiekt* wydajObiekt(string model) {
	Obiekt* obiekt = zlozObiekt(model);
	obiekt->produkowanieJednostek();
	obiekt->instalowanie();
	return obiekt;
	}
	};
	 
	int main() {
	FabrykaObiektow* fabrykaObiektow = new FabrykaObiektow();
	 
	Obiekt* koszary = fabrykaObiektow->wydajObiekt("Koszary");
	Obiekt* hangar = fabrykaObiektow->wydajObiekt("Hangar");
	Obiekt* port = fabrykaObiektow->wydajObiekt("Port");
	
	delete hangar;
	delete koszary;
	delete port;
	delete fabrykaObiektow;
	 
	return 0;
	}
