#include <iostream>
#include <vector>
#include <list>
#include <iterator>
#include <algorithm>
#include <ctime>
#include <string>
using namespace std;

class Person {
	public:
		Person(const char *name = "nobody");
		virtual ~Person() = default;
		virtual void identity() const;
		virtual void interrogate();
	private:
		string name;
};
Person::Person(const char *name ){
	this->name = name;
}
void Person::identity()const{
	cout<<"My name is: "<<this->name<<endl;
}
void Person::interrogate(){}

class Spy: public Person{
	public:
		Spy(const char *realName, string aliasName, int resistance0);
		void set_identity(const char *alias);
		virtual void identity() const;
		virtual void interrogate();
	private:
		string alias;
		int resistance;
};

Spy::Spy (const char *realName, string aliasName, int resistance0 ): Person(realName), alias(aliasName), resistance(resistance0) {}
void Spy::set_identity(const char *alias){
	this->alias = alias;
}
void Spy::interrogate(){
	if(this->resistance>0){
		this->resistance -=1;
	}
}
void Spy::identity()const{
	if(this->resistance>0){
		cout<<"My name is: "<<this->alias<<endl;
	}else{
		//string name = Person::identity();
		Person::identity();
		cout<<"My alias is: "<<this->alias<<endl;
	}
}

int main(int argc, char** argv) {

	Person agent("James Bond");
	Spy spy("Emilio Largo", "William Johnson", 3);
	Spy spy2("Ernst Blofield", "John Keats", 5);

	cout << endl << "Nice to meet you. ";
	agent.identity();

	for (int i = 0; i < 6; ++i) {
		cout << "Who are you?" << endl;
		spy.interrogate();
		spy.identity();
	}
	spy.set_identity("Bill Munny");
	spy.identity();

	cout << endl << "Nice to meet you. ";
	agent.identity();

	for (int i = 0; i < 6; ++i) {
		cout << "Who are you?" << endl;
		spy2.interrogate();
		spy2.identity();
	}

	return 0;
}