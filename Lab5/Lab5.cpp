// Lab5.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>
#include <string>
using namespace std;

class Electronics {
public:

	Electronics() {
		cout << "---Some electronic device is CREATED---" << endl;
	};
	
	virtual string classname() {
		return "Electronics";
	}

	virtual bool isA(string classname) {//isA проверка на принадлежность классу
			if (this->classname() == classname) return true;
			else return false;
	}


	void TurnOn() {
		cout << "You turned ON some electronic device!" << endl;
	}
	virtual void TurnOff() {
		cout << "You turned OFF some electronic device..." << endl;
	}

	void Method1() {
		cout << "Method1";
		Method2();
	}

	void Method2() {
		cout << " + Method2 of Base Class" << endl;
	}

	void Method1V() {
		cout << "Method1";
		Method2V();
	}

	virtual void Method2V() {
		cout << " + Method2 of Base Class" << endl;
	}

	virtual ~Electronics() {
		cout << "~~~Electronic device is DELETED~~~" << endl;
	};
};

class TV : public Electronics {
public: 

	TV() {
		cout << "---TV is CREATED---" << endl;
	};

	string classname() override {
		return "TV";
	}

	bool isA(string classname) override {
		if ((this->classname() == classname) || (Electronics::classname() == classname)) return true;
		else return false;
	}


	void WatchTV() {
		cout << "I am watching TV!" << endl;
	}
	
	void TurnOn() {
		cout << "You turned On TV! Let's watch movies!" << endl;
	}
	void TurnOff() override { 
		cout << "You turned Off TV..." << endl;
	}

	void Method2() {
		cout << "+ Method2 of Derived Class" << endl;
	}

	void Method2V() override {
		cout << " + Method2 of Derived Class" << endl;
	}

	~TV() {
		cout << "~~~TV is DELETED~~~" << endl;
	};
};

class Computer : public Electronics {
public:
	Computer() {
		cout << "---Computer is CREATED---" << endl;
	};

	string classname() override {
		return "Computer";
	}

	bool isA(string classname) override {
		if ((this->classname() == classname) || (Electronics::classname() == classname)) return true;
		else return false;
	}


	void Programming() {
		cout << "I am making a program on this computer!" << endl;
	}

	void TurnOn() {
		cout << "You turned On Computer!" << endl;
	}
	void TurnOff() override {
		cout << "You turned Off Computer..." << endl;
	}

	~Computer() {
		cout << "~~~Computer is DELETED~~~" << endl;
	};
};

class Monitor : public Computer {
public:
	Monitor() {
		cout << "---Monitor is CREATED---" << endl;
	};

	string classname() override {
		return "Monitor";
	}

	bool isA(string classname) override {
		if ((this->classname() == classname) || (Electronics::classname() == classname) || (Computer::classname() == classname)) return true;
		else return false;
	}


	void WatchMovie() {
		cout << "I am watching movie on this computer's monitor!" << endl;
	}

	void TurnOn() {
		cout << "You turned On Monitor! Now we can fully use a computer!" << endl;
	}
	void TurnOff() override {
		cout << "You turned Off Monitor..." << endl;
	}

	~Monitor() {
		cout << "~~~Monitor is DELETED~~~" << endl;
	};
};

class Speakers : public Computer {
public:
	Speakers() {
		cout << "---Speakers are CREATED---" << endl;
	};

	string classname() override {
		return "Speakers";
	}

	bool isA(string classname) override {
		if (Electronics::classname() == classname || Computer::classname() == classname || this->classname() == classname) return true;
		else return false;
	}


	void ListenToMusic() {
		cout << "I'm listening to my favorite song!" << endl;
	}

	void TurnOn() {
		cout << "You turned On Speakers! Now we can listen to music!" << endl;
	}
	void TurnOff() override {
		cout << "You turned Off Speakers..." << endl;
	}

	~Speakers() {
		cout << "~~~Speakers are DELETED~~~" << endl;
	};
};


class Base {

public:

	Base() {
		cout << "BASE - Default Constructor" << endl;
	};

	Base(Base *obj) {
		cout << "BASE - Constructor with *obj" << endl;
	};
	Base(Base &obj) {
		cout << "BASE - Constructor with &obj" << endl;
	};
	virtual ~Base() {
		cout << "BASE - Destructor" << endl;
	};
};

class Desk : public Base {

public:

	Desk() {
		cout << "DESK - Default Constructor" << endl;
	};

	Desk(Desk *obj) {
		cout << "DESK - Constructor with *obj" << endl;
	};

	Desk(Desk &obj) {
		cout << "DESK - Constructor with &obj" << endl;
	};

	~Desk() {
		cout << "DESK - Destructor" << endl;
	};
};

void func1(Base obj) {		//По значению
	cout << "func1" << endl;
};

void func2(Base *obj) {		//По адресу
	cout << "func2" << endl;
};

void func3(Base &obj) {		//По ссылке
	cout << "func3" << endl;
};

void func1(Desk obj) {		//По значению
	cout << "func1" << endl;
};

void func2(Desk *obj) {		//По адресу
	cout << "func2" << endl;
};

void func3(Desk &obj) {		//По ссылке
	cout << "func3" << endl;
};

template<class cl1, class cl2>
bool isX(cl2* obj)
{
	cl1* a = dynamic_cast<cl1*>(obj);
	if (a) return true;
	else return false;
}

int main()//мейн
{
	Electronics elec;
	TV tele;
	Computer *a = new Computer;
	Electronics *b = new Monitor;

	cout << endl << "\\_________Using non-virtual methods_________/" << endl << endl;
	
	elec.TurnOn();//вызов не винртуальных методов 
	tele.TurnOn();
	a->TurnOn();
	b->TurnOn();

	cout << endl << "\\_________Using virtual methods_________/" << endl << endl;
	elec.TurnOff();//вызов виртуальных методов 
	tele.TurnOff();
	a->TurnOff();
	b->TurnOff();
	cout << endl;

	delete a;
	delete b;

	cout << endl << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl << endl;
    
	cout << endl << "\\_________Using classname and isA to check if object belongs to the class_________/" << endl << endl;
	
	Electronics* obj[5];
	obj[0] = new Electronics();
	obj[1] = new TV();
	obj[2] = new Computer();
	obj[3] = new Monitor();
	obj[4] = new Speakers();


	for (int i = 0; i < 5; i++) {
		cout << obj[i]->classname() << ": " << endl;
		cout << "Electronics - " << obj[i]->isA("Electronics") << endl;
		cout << "TV - " << obj[i]->isA("TV") << endl;
		cout << "Computer - " << obj[i]->isA("Computer") << endl;
		cout << "Monitor - " << obj[i]->isA("Monitor") << endl;
		cout << "Speakers - " << obj[i]->isA("Speakers") << endl << endl;
	}

	cout << endl << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl << endl;

	cout << endl << "\\_________Using isA for unsafe type conversion_________/" << endl << endl;

	for (int i = 0; i < 5; i++) {
		cout << "USING ISA" << endl;
		if (obj[i]->isA("Speakers")) {
			((Speakers*)obj[i])->ListenToMusic();
		}
		if (obj[i]->isA("Monitor")) {
			((Monitor*)obj[i])->WatchMovie();
		}
		if (obj[i]->isA("Computer")) {
			((Computer*)obj[i])->Programming();
		}
		if (obj[i]->isA("TV")) {
			((TV*)obj[i])->WatchTV();
		}

		cout << "USING DYNAMIC CAST" << endl;
		Speakers* sp = dynamic_cast<Speakers*>(obj[i]);
		if (sp) sp->ListenToMusic();

		Monitor* mon = dynamic_cast<Monitor*>(obj[i]);
		if (mon) mon->WatchMovie();

		Computer* comp = dynamic_cast<Computer*>(obj[i]);
		if (comp) comp->Programming();

		TV* tv = dynamic_cast<TV*>(obj[i]);
		if (tv) tv->WatchTV();

	}
	cout << endl;

	for (int i = 0; i < 5; i++) {
		delete obj[i];
	}

	cout << endl << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl << endl;

	cout << endl << "\\_________Using func1, func2, func3_________/" << endl << endl;

	Base base1;

	func1(base1);

	func2(&base1);

	func3(base1);

	cout << endl;

	Desk desk1;

	func1(desk1);

	func2(&desk1);

	func3(desk1);

	cout << endl << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl << endl;


	return 0;

}

