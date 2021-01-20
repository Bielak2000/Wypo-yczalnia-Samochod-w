#include <iostream>
#include <windows.h>
#include "Data.h"
#include "Klient.h"
#include "Osoba.h"
#include "Platnosc.h"
#include "Pojazd.h"
#include "Wlasciciel.h"
#include "Wypozyczenie.h"
#include <fstream>
#include <sstream>

using namespace std;

int main()	//Funkcja g³ówna
{

	//Przepisanie informacji z plików do tablic
	int n;
	Pojazd* pojazdy = Pojazd::wczytaj_z_pliku(n);
	int k;
	Klient* klienci = Klient::wczytaj_z_pliku(k);
	int w;
	Wypozyczenie* wypozyczenia = Wypozyczenie::wczytaj_z_pliku(w);

	//Sprawdzanie b³êdu przy wczytywaniu danych
	if (pojazdy == nullptr || klienci == nullptr || wypozyczenia == nullptr)
	{
		cout << "Blad przy wczytaniu danych z pliku!" << endl;
		return 1;
	}

	//Przywitanie
	system("cls");
	int wybor;
	cout << "Witaj w naszej wypozyczalni pojazdow!" << endl;
	Sleep(3000);
	system("cls");

	//Wybor kim jestes
	cout << "Kim jestes?" << endl;
	cout << "1.Klientem." << endl;
	cout << "2.Wlascicielem." << endl;
	cin >> wybor;
	system("cls");

	int zmienna = 0; //zmienna sterujaca petlami
	
	//Gdy wybierasz klienta
	if (wybor == 1)
	{
		int sprawdzacz = 0;
		int sprawdzacz2 = 0;

		//Pêtla klienta
		for(;;)
		{

			//menu
			int wybor1;
			cout << "Wybierz opcje." << endl;
			cout << "1.Wypozyczenie pojazdu." << endl;
			cout << "2.Zarzadzaj wypozyczeniem." << endl;
			cout << "3.Zwroc pojazd." << endl;
			cout << "4.Wyswietl oferte." << endl;
			cout << "5.Dokonaj platnosci." << endl;
			cout << "6.Pokaz swoje wypozyczenia." << endl;
			cout << "7.Wyjdz." << endl;
			cin >> wybor1;
			system("cls");
			Klient k;
			k.zmniejsz_liczba_klientow(); //Teraz bedzie prawidlowa ilosc klientow

			//Wybory z menu
			if (wybor1 == 1)
			{
				bool sprawdzenie;
				sprawdzenie=k.wypozycz(pojazdy);
				if(sprawdzenie)
					k.aktualizuj_plik(klienci);
			}
			else if (wybor1 == 2)
			{
				string pes, nr;
				int wybor2;
				cout << "Wpisz swoj pesel: ";
				cin >> pes;
				cout << "Oto twoja lista wypozyczen: " << endl;

				//Pêtla wypisuj¹ca liste wypozyczeñ klienta
				for (int i = 0; i < wypozyczenia[0].get_liczba_wypozyczen(); i++)
				{
					
					//Gdy wypozyczenie nale¿y do klienta
					if (wypozyczenia[i].get_pesel() == pes)
					{
						cout << endl;
						cout << "Data rozpoczecia: ";
						cout << wypozyczenia[i].get_data_od().get_godzina() << ":" << "00 ";
						cout << wypozyczenia[i].get_data_od().get_dzien() << ".";
						cout << wypozyczenia[i].get_data_od().get_miesiac() << ".";
						cout << wypozyczenia[i].get_data_od().get_rok() << ".";
						cout << endl;

						cout << "Data zakonczenia: ";
						cout << wypozyczenia[i].get_data_do().get_godzina() << ":" << "00 ";
						cout << wypozyczenia[i].get_data_do().get_dzien() << ".";
						cout << wypozyczenia[i].get_data_do().get_miesiac() << ".";
						cout << wypozyczenia[i].get_data_do().get_rok() << ".";
						cout << endl;

						cout << "Numer rejestracyjny: " << wypozyczenia[i].get_numer_rejestracyjny() << endl;
						cout << "Status: ";
						if (wypozyczenia[i].get_zakonczone() == 0)
							cout << "Niezakonczone" << endl;
						else
							cout << "Zakonczone" << endl;
						cout << "Metoda platnosci: " << wypozyczenia[i].get_rachunek().get_sposob_platnosci() << endl;
						cout << "Kwota do zaplaty: " << wypozyczenia[i].get_rachunek().get_kwota() << endl;
						cout << "Status platnosci: ";
						if (wypozyczenia[i].get_rachunek().get_potwierdzenie())
							cout << "Zaplacone" << endl;
						else
							cout << "Niezaplacone" << endl;

						cout << "Termin platnosci: ";
						cout << wypozyczenia[i].get_termin_platnosci().get_godzina() << ":" << "00 ";
						cout << wypozyczenia[i].get_termin_platnosci().get_dzien() << ".";
						cout << wypozyczenia[i].get_termin_platnosci().get_miesiac() << ".";
						cout << wypozyczenia[i].get_termin_platnosci().get_rok() << ".";
						cout << endl << endl;
						sprawdzacz = 1;
					}
				}
				if (!sprawdzacz)
				{
					cout << "Nie posiadasz zadnych wypozyczen!" << endl;
					cout << "Nie mozesz zarzadzac wypozyczeniami" << endl;
				}
				else
				{
					cout << "Podaj numer rejestracyjny ktorego wypozyczenie chcesz zmodyfikowac: ";
					cin >> nr;
					int indeks=-1;
					for (int i = 0; i < wypozyczenia[0].get_liczba_wypozyczen(); i++)
					{
						if (wypozyczenia[i].get_pesel() == pes && wypozyczenia[i].get_numer_rejestracyjny() == nr)
						{
							indeks = i;
							break;
						}
					}
					if (indeks == -1)
					{
						cout << "Podano zly numer rejestracyjny pojazdu!" << endl;
						Sleep(2000);
						system("cls");
						continue;
					}
					Sleep(1000);
					system("cls");

					//Pêtla zmiany d³ugoœci wypozyczenia
					do {
						sprawdzacz2 = 0;
						cout << "Co chcesz zrobic z tym wypozyczeniem: " << endl;
						cout << "1.Skrocic czas wypozyczenia." << endl;
						cout << "2.Wydluzyc czas wypozyczenia." << endl;
						cin >> wybor2;
						system("cls");
						if (wybor2 == 1)
						{
							Data d;
							int zmienna;
							cout << "Podaj nowy rok: ";
							cin >> zmienna;
							d.set_rok(zmienna);
							cout << "Podaj nowy miesiac: ";
							cin >> zmienna;
							d.set_miesiac(zmienna);
							cout << "Podaj nowy dzien: ";
							cin >> zmienna;
							d.set_dzien(zmienna);
							cout << "Podaj nowy godzina: ";
							cin >> zmienna;
							d.set_godzina(zmienna);
							bool udane = wypozyczenia[indeks].skroc_okres(d);

							//Gdy podana data jest mniejsza od pocz¹tkowej lub wiêksza od koñcowej
							if (!udane)
							{
								cout << "Podano nieprawidlowa date!" << endl;
								Sleep(2000);
								system("cls");
								sprawdzacz2 = 1;
							}
							else
							{
								wypozyczenia[indeks].set_termin_platnosci(d);

								//Liczenie ceny
								int cena = 0;
								int miesiac, dzien;
								miesiac = wypozyczenia[indeks].get_data_do().get_miesiac() - wypozyczenia[indeks].get_data_od().get_miesiac();
								miesiac += 12 * (wypozyczenia[indeks].get_data_do().get_rok() - wypozyczenia[indeks].get_data_od().get_rok());
								dzien = wypozyczenia[indeks].get_data_do().get_dzien() - wypozyczenia[indeks].get_data_od().get_dzien();
								for (int m = 0; m < miesiac; m++)
								{
									int ktory = (wypozyczenia[indeks].get_data_od().get_miesiac() + m) % 12;
									if (ktory == 1 || ktory == 3 || ktory == 5 || ktory == 7 || ktory == 8 || ktory == 10 || ktory == 12)
									{
										dzien += 31;
									}
									else if (ktory == 2)
									{
										dzien += 28;
									}
									else
									{
										dzien += 30;
									}
								}
								int godzina = wypozyczenia[indeks].get_data_do().get_godzina() - wypozyczenia[indeks].get_data_od().get_miesiac();
								godzina += dzien * 24;
								for (int j = 0; j < pojazdy[0].get_liczba_pojazdow(); j++)
								{
									if (wypozyczenia[indeks].get_numer_rejestracyjny() == pojazdy[j].get_numer_rejestracyjny())
									{
										cena = godzina * pojazdy[j].get_cena_za_godzine();
										break;
									}
								}
								wypozyczenia[indeks].get_rachunek1()->set_kwota(cena);
								wypozyczenia[indeks].aktualizuj_plik(wypozyczenia);
								cout << "Dokonano zmiany terminu" << endl;
								Sleep(2000);
							}
						}
						else if (wybor2 == 2)
						{
							Data d;
							int zmienna;
							cout << "Podaj nowy rok: ";
							cin >> zmienna;
							d.set_rok(zmienna);
							cout << "Podaj nowy miesiac: ";
							cin >> zmienna;
							d.set_miesiac(zmienna);
							cout << "Podaj nowy dzien: ";
							cin >> zmienna;
							d.set_dzien(zmienna);
							cout << "Podaj nowy godzina: ";
							cin >> zmienna;
							d.set_godzina(zmienna);
							bool udane = wypozyczenia[indeks].wydluz_okres(d);

							//Gdy podana data mniejsza od koncowej
							if (!udane)
							{
								cout << "Podano nieprawidlowa date!" << endl;
								Sleep(2000);
								system("cls");
								sprawdzacz2 = 1;
							}
							else
							{
								wypozyczenia[indeks].set_termin_platnosci(d);

								//Liczenie ceny
								int cena = 0;
								int miesiac, dzien;
								miesiac = wypozyczenia[indeks].get_data_do().get_miesiac() - wypozyczenia[indeks].get_data_od().get_miesiac();
								miesiac += 12 * (wypozyczenia[indeks].get_data_do().get_rok() - wypozyczenia[indeks].get_data_od().get_rok());
								dzien = wypozyczenia[indeks].get_data_do().get_dzien() - wypozyczenia[indeks].get_data_od().get_dzien();
								for (int m = 0; m < miesiac; m++)
								{
									int ktory = (wypozyczenia[indeks].get_data_od().get_miesiac() + m) % 12;
									if (ktory == 1 || ktory == 3 || ktory == 5 || ktory == 7 || ktory == 8 || ktory == 10 || ktory == 12)
									{
										dzien += 31;
									}
									else if (ktory == 2)
									{
										dzien += 28;
									}
									else
									{
										dzien += 30;
									}
								}
								int godzina = wypozyczenia[indeks].get_data_do().get_godzina() - wypozyczenia[indeks].get_data_od().get_miesiac();
								godzina += dzien * 24;
								for (int j = 0; j < pojazdy[0].get_liczba_pojazdow(); j++)
								{
									if (wypozyczenia[indeks].get_numer_rejestracyjny() == pojazdy[j].get_numer_rejestracyjny())
									{
										cena = godzina * pojazdy[j].get_cena_za_godzine();
										break;
									}
								}
								wypozyczenia[indeks].get_rachunek1()->set_kwota(cena);
								wypozyczenia[indeks].aktualizuj_plik(wypozyczenia);
								cout << "Dokonano zmiany terminu" << endl;
								Sleep(2000);
							}
						}
						else
						{
							cout << "Zly wybor! Sprobuj ponownie!" << endl;
							sprawdzacz2 = 1;
						}
					} while (sprawdzacz2 == 1);
				}
			}
			else if (wybor1 == 3)
			{
				k.zwroc_pojazd(wypozyczenia, pojazdy);

			}
			else if (wybor1 == 4)
			{
				k.wyswietl_oferte(pojazdy);
			}
			else if (wybor1 == 5)
			{
				k.dokonaj_platnosci(wypozyczenia);
			}
			else if (wybor1 == 6)
			{
				string p;
				cout << "Podaj swoj pesel: ";
				cin >> p;

				//Pêtla wypisuj¹ca liste wypozyczeñ klienta
				for (int i = 0; i < wypozyczenia[0].get_liczba_wypozyczen(); i++)
				{

					//Gdy wypozyczenie nale¿y do klienta
					if (wypozyczenia[i].get_pesel() == p)
					{
						cout << endl;
						cout << "Data rozpoczecia: ";
						cout << wypozyczenia[i].get_data_od().get_godzina() << ":" << "00 ";
						cout << wypozyczenia[i].get_data_od().get_dzien() << ".";
						cout << wypozyczenia[i].get_data_od().get_miesiac() << ".";
						cout << wypozyczenia[i].get_data_od().get_rok() << ".";
						cout << endl;

						cout << "Data zakonczenia: ";
						cout << wypozyczenia[i].get_data_do().get_godzina() << ":" << "00 ";
						cout << wypozyczenia[i].get_data_do().get_dzien() << ".";
						cout << wypozyczenia[i].get_data_do().get_miesiac() << ".";
						cout << wypozyczenia[i].get_data_do().get_rok() << ".";
						cout << endl;

						cout << "Numer rejestracyjny: " << wypozyczenia[i].get_numer_rejestracyjny() << endl;
						cout << "Status: ";
						if (wypozyczenia[i].get_zakonczone() == 0)
							cout << "Niezakonczone" << endl;
						else
							cout << "Zakonczone" << endl;
						cout << "Metoda platnosci: " << wypozyczenia[i].get_rachunek().get_sposob_platnosci() << endl;
						cout << "Kwota do zaplaty: " << wypozyczenia[i].get_rachunek().get_kwota() << endl;
						cout << "Status platnosci: ";
						if (wypozyczenia[i].get_rachunek().get_potwierdzenie())
							cout << "Zaplacone" << endl;
						else
							cout << "Niezaplacone" << endl;

						cout << "Termin platnosci: ";
						cout << wypozyczenia[i].get_termin_platnosci().get_godzina() << ":" << "00 ";
						cout << wypozyczenia[i].get_termin_platnosci().get_dzien() << ".";
						cout << wypozyczenia[i].get_termin_platnosci().get_miesiac() << ".";
						cout << wypozyczenia[i].get_termin_platnosci().get_rok() << ".";
						cout << endl << endl;
						sprawdzacz = 1;
					}
				}
				if (!sprawdzacz)
					cout << "Nie posiadasz zadnych wypozyczen!" << endl;
			}
			else if (wybor1 == 7)
			{
				return 0;
			}
			else
			{
				cout << "Zly wybor! Sprobuj ponownie!" << endl;
				Sleep(2000);
				system("cls");
			}
		}
	}
	else if (wybor == 2)
	{
		string login, haslo;
		int wybor2;
		Wlasciciel w;

		//Logowanie w³aœciciela
		do 
		{
					cout << "Podaj login: ";
					cin >> login;
					cout << "Podaj haslo: ";
					cin >> haslo;
					if (w.get_login() == login && w.get_haslo() == haslo)
					{
						cout << "Zalogowano!" << endl;
						Sleep(2000);
						system("cls");

						//Menu w³aœciciela
						for (;;)
						{
							int wybor1;
							cout << "Wybierz opcje." << endl;
							cout << "1.Dodaj pojazd." << endl;
							cout << "2.Usun pojazd." << endl;
							cout << "3.Zmien cennik." << endl;
							cout << "4.Pokaz posiadane pojazdy." << endl;
							cout << "5.Wyjdz." << endl;
							cin >> wybor1;
							system("cls");
							if (wybor1 == 1)
							{
								w.dodaj_pojazd();
							}
							else if (wybor1 == 2)
							{
								string nr_rej_usun;
								cout << "Podaj numer rejestracyjny pojazdu, ktory chcesz usunac: ";
								cin >> nr_rej_usun;
								w.usun_pojazd(nr_rej_usun, pojazdy);
							}
							else if (wybor1 == 3)
							{
								string numer_rejestracyjny;
								cout << "Podaj numer rejestracyjny pojazdu, ktorego cene za godzine chcesz zmienic: ";
								cin >> numer_rejestracyjny;
								w.zmien_cene(numer_rejestracyjny, pojazdy);
							}
							else if (wybor1 == 4)
							{
								for (int i = 0; i < pojazdy[0].get_liczba_pojazdow(); i++)
								{
									pojazdy[i].wyswietl_dane();
									cout << endl << endl;
								}
							}
							else if (wybor1 == 5)
							{
								return 0;
							}
							else
							{
								cout << "Podano nieprawidlowy numer wyboru!";
								Sleep(2000);
								system("cls");
							}
						}
					}
					else
					{
						cout << "Niepoprawne dane!" << endl;
						cout << "Chcesz kontynuowac?" << endl;
						cout << "1.Tak." << endl;
						cout << "2.Nie" << endl;
						cin >> wybor2;
						if(wybor2==1)
							zmienna = 1;
						system("cls");
					}
		} while (zmienna == 1);
	}
}
//Koniec programu