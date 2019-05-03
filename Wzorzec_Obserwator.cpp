/*Zadanie 3 (obserwator)
Wprowadzenie
W domu chcielibyœmy zainstalowaæ kilka zegarów w ró¿nych pomieszczeniach. 
Zale¿y nam na tym ¿eby wszystkie zegary wyœwietla³y dok³adnie t¹ sam¹ godzinê. 
Dodatkowo chcielibyœmy unikn¹æ uci¹¿liwego dostosowywania godziny na ka¿dym z 
nich podczas zmiany czasu. Z tego wzglêdu zamiast kupowaæ N zegarków, to kupimy 
jeden zegar centralny, który bêdzie odpowiedzialny tylko za odmierzanie czasu, 
a osobno dokupimy N wyœwietlaczy, które bêd¹ ³¹czyæ siê z zegarem centralnym 
i pobieraæ z niego informacjê o aktualnej godzinie.

Zadanie
Stwórz aplikacjê naœladuj¹c¹ zachowanie zegara centralnego i pod³¹czonych do niego 
wyœwietlaczy cyfrowych. Oczywiœcie trzeba w tym celu wykorzystaæ wzorzec projektowy 
"Obserwator". Program mo¿e sk³adaæ siê z trzech klas reprezentuj¹cych wyœwietlacze 
czasu w formacie hh:mm (bêd¹cych obserwatorami):
WyswietlaczPokojowy
WyswietlaczKuchenny
WyswietlaczOgrodowy
Oraz jednej klasy obserwowanej ZegarCentralny, która symuluje zachowanie zegara 
centralnego i s³u¿y jedynie do odmierzania czasu (nie posiada on mechanizmu wyœwietlania). 
Za wyœwietlanie aktualnego czasu s¹ odpowiedzialne klasy wyœwietlaczy i tylko one maj¹ 
realizowaæ t¹ funkcjonalnoœæ. Klasa ZegarCentralny ma byæ obserwowana przez klasy 
wyœwietlaczy i ma te obiekty informowaæ o zmianie czasu.


Uwagi:
Program powinien umo¿liwiaæ pod³¹czenie/od³¹czenie danego wyœwietlacza (obserwatora) 
od zegara centralnego (obiektu obserwowanego) w trakcie dzia³ania programu.  
Zak³adamy, ¿e aktualizacja wyœwietlanego czasu odbywa siê co 1 minutê. 
Proszê pamiêtaæ o wykorzystaniu interfejsów!*/

#include <iostream>
#include <string>
#include <list>
#include <ctime>
#include <windows.h>
#include <conio.h>
using namespace std;

class Obserwator {
public:
    virtual void update() = 0;
};

class Obserwowany {
protected:
    list <Obserwator*> obserwatorzy;
public:
    void dodaj(Obserwator *o) {
        obserwatorzy.push_back (o);
    }
    void usun() {
       // obserwatorzy.remove (o);
        
        obserwatorzy.clear();
        
    }
 
    void powiadom () {
        list<Obserwator *>::iterator it;
        for (it = obserwatorzy.begin(); it != obserwatorzy.end(); it++) {
            (*it)->update ();
        }
    }
};

class ZegarCentralny : public Obserwowany{
	string czas;
	public:
	string pobierzCzas(){
		
		return czas;
	}

	void ustawCzas(){
		
	time_t now = time(0);
		
  	 char* dt = ctime(&now);
  	 string data(dt);
  	 
  	czas = data;
  	 cout << endl<< "Uruchomiono zegar centralny." << endl;
  	        
		powiadom();
	}
	
};


class ObserwatorZegar : public Obserwator {

protected:
    string zegarId;
        ZegarCentralny *zegar;
public:
    ObserwatorZegar (ZegarCentralny *h, string id) {
        zegar = h;
        zegarId = id;
    }
    void update () {
        string czas = zegar->pobierzCzas();
        cout<<zegarId<<", godzina: "<<czas;
    }
    
};


main(){
	
	char znak;
	int choice;
	
	cout<<"Menu"<<endl;
	
cout<<"0. Aby zatrzymaæ dzia³anie programu naciœnij '0'."<<endl;
cout<<"1. Aby uruchomiæ zegar centralny naciœnij '1'."<<endl;
cout<<"2. W celu dodania wyswietlacza pokojowego naciœnij '2'."<<endl;
cout<<"3. W celu dodania wyswietlacza kuchennego naciœnij '3'."<<endl;
cout<<"4. W celu dodania wyswietlacza ogrodowego naciœnij '4'."<<endl;
cout<<"5. Aby usunac wszystkie wyswietlacze naciœnij '5'."<<endl;
	
	
	ZegarCentralny zegar ;



	do{
		cin>>choice;

		if (choice==1){
		
			while(1){
				zegar.ustawCzas();
				Sleep(1000*2); // timer
			
				if (kbhit()){
		        	znak=getch();
		        break;
		    	}
			}
		}
		if (choice==2){
			Obserwator *zegar1 = new ObserwatorZegar(&zegar, "Wyœwietlacz pokojowy");
			zegar.dodaj(zegar1);
			cout<<"Dodano wyswietlacz pokojowy."<<endl;
		}
		
		if (choice==3){
			Obserwator *zegar2 = new ObserwatorZegar(&zegar, "Wyœwietlacz kuchenny");
			zegar.dodaj(zegar2);
			cout<<"Dodano wyswietlacz kuchenny."<<endl;
		}
		if (choice==4){
			Obserwator *zegar3 = new ObserwatorZegar(&zegar, "Wyœwietlacz ogrodowy");
			zegar.dodaj(zegar3);
			cout<<"Dodano wyœwietlacz ogrodowy."<<endl;
		}
		
		if(choice==5){
			zegar.usun();
			cout<<"Usunieto wszystkie wyswietlacze."<<endl;
		}
		
	
	}while(choice!=0);

}

