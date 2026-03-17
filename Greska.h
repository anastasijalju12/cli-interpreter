#pragma once
#include <exception>
#include <string>
class GNeispravanUnosArgumenta : public std::exception
{
public:
	GNeispravanUnosArgumenta() : exception("Greska: Unos nije ispravan.Komandna linija nije ispravno zadata.\n") {}
};
class GArgumentIUlaznaRedirekcija : public std::exception
{
public:
	GArgumentIUlaznaRedirekcija() : exception("Greska: Nije dozvoljen argument i ulazna redirekcija.\n") {}
};
class GDateImaArgument : public std::exception
{
public:
	GDateImaArgument() : exception("Greska: Komanda date ne moze imati argumente.\n") {}
};
class GTimeImaArgument : public std::exception
{
public:
	GTimeImaArgument() : exception("Greska: Komanda time ne moze imati argumente.\n") {}
};
class GNijeMoguceObrisatiFajl : public std::exception
{
public:
	GNijeMoguceObrisatiFajl() : exception("Greska: Nije moguce obrisati fajl sa zadatim nazivom, fajl nije pronadjen.\n") {}
};
class GNazivFajlSaNavodnicima : public std::exception
{
public:
	GNazivFajlSaNavodnicima() : exception("Greska.Naziv fajla ne moze biti unutar navodnika.\n") {}
};
class GFajlVecPostoji : public std::exception {
public:
	GFajlVecPostoji() : exception("Greska. Fajl sa zadatim nazivom vec postoji.\n") {}
};
class GNijeMoguceOtvoritiFajl : public std::exception {
public:
	GNijeMoguceOtvoritiFajl() : exception("Greska. Nije moguce otvoriti fajl sa zadatim nazivom.\n") {}

};
class GNijeMoguceOtvoritiFajlDodavanjeTeksta : public std::exception {
public:
	GNijeMoguceOtvoritiFajlDodavanjeTeksta() : exception("Greska. Nije moguce otvoriti fajl sa zadatim nazivom za dodavanje teksta.\n") {}

};
class GNijeMoguceOtvoritiFajlPisanjeTeksta : public std::exception {
public:
	GNijeMoguceOtvoritiFajlPisanjeTeksta() : exception("Greska. Nije moguce otvoriti fajl sa zadatim nazivom za pisanje teksta.\n") {}

};
class GFajlNijePronadjen : public std::exception {
public:
	GFajlNijePronadjen() : exception("Fajl nije pronadjen.\n") {}

};
class GOpcijaSaNavodnicima : public std::exception
{
public:
	GOpcijaSaNavodnicima() : exception("Greska.Opcija ne moze biti unutar navodnika.") {}
};
class GNeispravanUnosRedirekcije : public std::exception
{
public:
	GNeispravanUnosRedirekcije() : exception("Redirekcija mora biti zadata na kraju komandne linije.\n") {}
};
class GRedirekcijaIzlaznogToka : public std::exception
{
public:
	GRedirekcijaIzlaznogToka() : exception("Greska: Ne moze postojati redirekcija izlaznog toka komande na pocetku ili u sredini cevovoda. Izlazni tok je povezan u cevovod.\n") {}
};
class GRedirekcijaUlaznogToka : public std::exception {
public:
	GRedirekcijaUlaznogToka() : exception("Greska: Ne moze postojari redirekcija ulaznog toka u sredini ili na kraju cevovoda.Ulazni tok je povezan u cevovod.\n") {}
};
class GNeispravanUnosVariableArgument : public std::exception {
public:
	GNeispravanUnosVariableArgument() : exception("Komanda koja moze i ne mora da ima argument nije dobro formulisana unutar cevovoda.\n") {}
};
class GNeispravanUnosRequiredArgument : public std::exception {
public:
	GNeispravanUnosRequiredArgument() : exception("Komanda sa zahtevajucim argumentom nije dobro formulisana unutar cevovoda.\n") {}
};
class GNeispravanUnosPipeEcho : public std::exception {
public:
	GNeispravanUnosPipeEcho() : exception("Echo nije dobro formulisan unutar cevovoda.\n") {}
};
class GNeispravanUnosPipeWc : public std::exception {
public:
	GNeispravanUnosPipeWc() : exception("Wc nije dobro formulisan unutar cevovoda.\n") {}
};
class GPromptUcevovoduSredina : public std::exception {
public:
	GPromptUcevovoduSredina() : exception("Komanda prompt se ne moze naci u sredini cevovoda.\n") {}
};
class GPromptUcevovoduPocetak : public std::exception {
public:
	GPromptUcevovoduPocetak() : exception("Komanda prompt se ne moze naci na pocetku cevovoda.\n") {}
};
class GPogresniNavodnici : public std::exception {
public:
	GPogresniNavodnici() : exception("Argument nema navodnike za zatvaranje.\n") {
	}
};
class GRequiredArgumentDontHaveArgument : public std::exception {
public:
	GRequiredArgumentDontHaveArgument() : exception("Nije unet argument, komanda ovog tipa zahteva argument.\n") {
	}
}; 
class GRequiredArgumentRedirection : public std::exception {
public:
	GRequiredArgumentRedirection() : exception("Komanda ovog tipa ne moze da ima redirekciju.\n") {
	}
};
class GNeDozvoljenNazivFajla : public std::exception {
public:
	GNeDozvoljenNazivFajla() : exception("Fajl nije napravljen. Za naziv fajla je koriscen ne dozvoljen znak(Ne dozvoljeni znaci:   /   :   *   ?   < > | ). \n") {
	}
};
class GRazmakIzmedjuDvostrukogZnakaVece : public std::exception {
public: 
	GRazmakIzmedjuDvostrukogZnakaVece() : exception("Razmak izmedju dva znaka vece nije dozvoljen.\n") {}
};
class GNeispravanUnosPipeWithoutDataObjects : public std::exception {
	public:
		GNeispravanUnosPipeWithoutDataObjects() : exception("Objekat tipa date ili time nije dobro formulisan unutar cevovoda.\n") {}
};
class GHead : public std::exception{
	public:
		GHead() : exception("Head komanda nije ispravno zadata.\n") {}
};
class GPromptFajl : public std::exception {
public:
	GPromptFajl() : exception("Prompt ne moze citati iz fajla, argument mora biti pod navonicima.\n") {}
};
class GBatchPogresnoUCevovodu : public std::exception {
public:
	GBatchPogresnoUCevovodu() : exception("Batch se ne moze naci na zadatom mestu u cevovodu.\n") {}
};

/*
class Nema_izlaz: public std::logic_error {
public:
	Nema_izlaz(const string& ime) : logic_error("Command "+ime+"doesnt have input for the next  command"){}
	//logic_error je nasledjena iz excepiton, ima konstruktor koji prima string
};

*/