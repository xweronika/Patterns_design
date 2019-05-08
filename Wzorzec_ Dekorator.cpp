/*Zadanie 4 (dekorator)
Stwórz aplikacjê symuluj¹c¹ ulepszanie/rozwój postaci (bohatera) w grze komputerowej. 
Rozwój ten bêdzie realizowany poprzez przypisywanie nowych przedmiotów do naszej postaci. 
Oczywiœcie trzeba w tym celu wykorzystaæ wzorzec projektowy "Dekorator".

Klasa Bohater bêdzie posiadaæ nastêpuj¹ce trzy parametry z wartoœciami pocz¹tkowymi:
HP - parametr okreœlaj¹cy iloœæ ¿ycia danej postaci (wartoœæ pocz¹tkowa 100),
Atak - parametr okreœlaj¹cy wartoœæ ataku danej postaci (pocz¹tkowa wartoœæ 10),
Obrona - parametr okreœlaj¹cy wartoœæ obrony danej postaci (pocz¹tkowa wartoœæ 10).

Przedmioty, które bêd¹ zwiêkszaæ statystyki bohatera (statystki zapisane w formacie HP/atak/obrona) to:
Rzadkie rêkawice - +10/+3/+4,
Pospolite buty - +3/+1/+2,
Spodnie - +5/+3/+2,
Epicki he³m - +15/+5/+5,
Legendarny miecz - +25/+10/+10. */

#include <iostream>
#include <string>
using namespace std;
 
/* Standardowy nieudekorowany bohater */
class Bohater {
	protected:
	string bohater;
	double wartosc, wartosc2, wartosc3;
	 
	public:
	Bohater(){
		bohater = "Bohater podstawowy";
		wartosc=0;
		wartosc2=0;
		wartosc3=0;
	}
	 
	virtual string about(){
		return bohater;
	}
	 
	virtual double cena(){
		return wartosc;
	}
	virtual double cena2(){
		return wartosc2;
	}
	virtual double cena3(){
		return wartosc3;
	}

};
 
/* abstrakcyjny dekorator */
class Dekorator : public Bohater {
 
	public:
	virtual string about(){
		return "hmm";
	}
};
 
/* teraz mamy 3 parametry bohatera */
class HP : public Bohater {
 
	public: HP():Bohater(){
		bohater = "HP";
		wartosc=100;
	}
 
};
 
class Atak : public Bohater {
	 
	public: Atak():Bohater(){
		bohater = "Atak";
		wartosc2=10;
	}
 
};

class Obrona : public Bohater {
	 
	public: Obrona():Bohater(){
		bohater = "Obrona";
		wartosc3=10;
	}
 
};
 
/* czas na same dodatki */
class Rekawice : public Dekorator {
	Bohater *hero;
	 
	public: Rekawice(Bohater *bohater):Dekorator(){
		hero = bohater;
	}
	 
	string about(){
		return hero->about() + " + Rzadkie rekawice";
	}
	 
	double cena(){
		return hero->cena()+10;
	}
	double cena2(){
		return hero->cena2()+3;
	}
	double cena3(){
		return hero->cena3()+4;
	}
};
 
class Buty : public Dekorator {
	Bohater *hero;
	 
	public: Buty(Bohater *bohater):Dekorator(){
		hero = bohater;
	}
	 
	string about()
	{
		return hero->about() + " + Pospolite buty";
	}
	 
	
	double cena()
	{
		return hero->cena() + 3;
	}
	double cena2(){
		return hero->cena2()+1;
	}
	double cena3(){
		return hero->cena3()+2;
	}
};

class Spodnie : public Dekorator {
	Bohater *hero;
	public: Spodnie(Bohater *bohater):Dekorator(){
		hero = bohater;
	}
	 
	string about(){
		return hero->about() + " + Spodnie";
	}
	 
	double cena(){
		return hero->cena()+5;
	}
	double cena2(){
		return hero->cena2()+3;
	}
	double cena3(){
		return hero->cena3()+2;
	}
};
 
class Helm : public Dekorator {
	Bohater *hero;
	public: Helm(Bohater *bohater):Dekorator(){
		hero = bohater;
	}
	 
	string about(){
		return hero->about() + " + Epicki helm";
	}
	 
	double cena(){
		return hero->cena()+15;
	}
	double cena2(){
		return hero->cena2()+5;
	}
	double cena3(){
		return hero->cena3()+5;
	}
};

class Miecz : public Dekorator {
	Bohater *hero;
	public: Miecz(Bohater *bohater):Dekorator(){
		hero = bohater;
	}
	 
	string about(){
		return hero->about() + " + Legendarny miecz";
	}
	 
	double cena(){
		return hero->cena()+25;
	}
	double cena2(){
		return hero->cena2()+10;
	}
	double cena3(){
		return hero->cena3()+10;
	}
};

void Menu(){
	
	cout<<"Menu:\n";
	
	cout<<"1. Aby stworzyc nowego bohatera nacisnij 1.\n";
	cout<<"2. W celu dodania rekawic do aktualnego bohatera nacisnij 2.\n";
	cout<<"3. W celu dodania butow do aktualnego bohatera nacisnij 3.\n";
	cout<<"4. W celu dodania spodni do aktualnego bohatera nacisnij 4.\n";
	cout<<"5. W celu dodania helmu do aktualnego bohatera nacisnij 5.\n";
	cout<<"6. W celu dodania miecza do aktualnego bohatera nacisnij 6.\n";
	cout<<"7. W celu usuniecia wszystkich dodatkowych przedmiotow nacisnij 7.\n";
	cout<<"8. Aby wyswietlic aktualne statystyki oraz menu nacisnij 8.\n";
	cout<<"9. Aby zatrzymac dzialanie programu nacisnij 0.\n";
}
 
int main(){
	


	Menu();

	int choice, choice1;
	cin>>choice1;
	
	if (choice1==1){
				Bohater *s1 = new HP();
				Bohater *s2 = new Atak();
				Bohater *s3 = new Obrona();
				cout<<"\nStworzono nowego bohatera (bez dodatkowych przedmiotow)."<<endl;
				cout<<s1->about()<<" "<<s1->cena()<<endl;
				cout<<s2->about()<<" "<<s2->cena2()<<endl;
				cout<<s3->about()<<" "<<s3->cena3()<<endl;
			
		
		do{
			cin>>choice;
			
			if (choice==2){
				//dodajemy rekawice
				s1 = new Rekawice(s1);
				s2 = new Rekawice(s2);
				s3 = new Rekawice(s3);
				cout<<"\nDodano rzadkie rekawice - +10/+3/+4 :"<<endl;
				cout<<s1->about()<<" "<<s1->cena()<<endl;	
				cout<<s2->about()<<" "<<s2->cena2()<<endl;
				cout<<s3->about()<<" "<<s3->cena3()<<endl;	
			}
			
			if (choice==3){
				// dodajemy buty
				s1 = new Buty(s1);
				s2 = new Buty(s2);
				s3 = new Buty(s3);
				cout<<"\nDodano pospolite buty - +3/+1/+2 :"<<endl;
				cout<<s1->about()<<" "<<s1->cena()<<endl;
				cout<<s2->about()<<" "<<s2->cena2()<<endl;
				cout<<s3->about()<<" "<<s3->cena3()<<endl;
			}	
				
			if (choice==4){
				//dodajemy spodnie
				s1 = new Spodnie(s1);
				s2 = new Spodnie(s2);
				s3 = new Spodnie(s3);
				cout<<"\nDodano spodnie - +5/+3/+2 :"<<endl;
				cout<<s1->about()<<" "<<s1->cena()<<endl;	
				cout<<s2->about()<<" "<<s2->cena2()<<endl;
				cout<<s3->about()<<" "<<s3->cena3()<<endl;
			}
			
			if (choice==5){
				// dodajemy helm
				s1 = new Helm(s1);
				s2 = new Helm(s2);
				s3 = new Helm(s3);
				cout<<"\nDodano epicki helm - +15/+5/+5 :"<<endl;
				cout<<s1->about()<<" "<<s1->cena()<<endl;
				cout<<s2->about()<<" "<<s2->cena2()<<endl;
				cout<<s3->about()<<" "<<s3->cena3()<<endl;
			}
			
			if (choice==6){
				// dodajemy miecz
				s1 = new Miecz(s1);
				s2 = new Miecz(s2);
				s3 = new Miecz(s3);
				cout<<"\nDodano legendarny miecz - +25/+10/+10 :"<<endl;
				cout<<s1->about()<<" "<<s1->cena()<<endl;
				cout<<s2->about()<<" "<<s2->cena2()<<endl;
				cout<<s3->about()<<" "<<s3->cena3()<<endl;
		
			}
			
			if (choice==7){
				
				delete s1;
				delete s2;
				delete s3;
				

				s1 = new HP();
				s2 = new Atak();
				s3 = new Obrona();			
								
				cout<<"\nUsunieto wszystkie dodatkowe przedmioty. Aktualne wartosci bohatera:"<<endl;
				cout<<s1->about()<<" "<<s1->cena()<<endl;
				cout<<s2->about()<<" "<<s2->cena2()<<endl;
				cout<<s3->about()<<" "<<s3->cena3()<<endl;

			}
			
			if (choice==8){
				system( "cls" );
				Menu();
				cout<<"\nAktualne statystyki:"<<endl;
				cout<<s1->about()<<" "<<s1->cena()<<endl;
				cout<<s2->about()<<" "<<s2->cena2()<<endl;
				cout<<s3->about()<<" "<<s3->cena3()<<endl<<endl;
			}
			
		}while(choice!=0);
	}

	
	
	system("PAUSE");
	return 0;
}
