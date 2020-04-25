#include <iostream>
#include <string>

#define MAKEDLL

#ifdef MAKEDLL
#  define EXPORT __declspec(dllexport)
#else
#  define EXPORT __declspec(dllimport)
#endif


//warning C4251 https://docs.microsoft.com/en-us/cpp/error-messages/compiler-warnings/compiler-warning-level-1-c4251?view=vs-2019
/*
Inconsistent possible std::string implementation
You can choose to export it or instantiate it in the constructor yourself

std::string ����ʵ�ֵĲ�һ��
������ѡ���Լ��������ڹ��캯����ʵ������
*/

class EXPORT Hello {

public:
	Hello(std::string&& name) {
		this->name = name;
	}

	void Say(std::string&& s) {
		std::cout << name << ": " << s << std::endl;
	}

private:
	std::string name;
};

class Hello2 {

public:
	EXPORT	Hello2(std::string&& name) {
		this->name = name;
	}
	EXPORT ~Hello2() {

	}

	EXPORT void Say(std::string&& s) {
		std::cout << name << ": " << s << std::endl;
	}

private:
	std::string name;
};

template<typename T>
class EXPORT Hello3 {

public:
	Hello3(std::string&& name) {
		this->name = name;
	}

	void Say(T v) {
		std::cout << name << ": " << v << std::endl;
	}

private:
	std::string name;
};

//Explicit instantiation
template class Hello3<std::string>;
template class EXPORT Hello3<int>;
//EXPORT can be written on the CLASS or here
//EXPORT ����д�� CLASS �ϻ�������



//���ﲻ��д EXPORT
template<typename T>
T Echo(T&& v) {
	std::cout << "Echo: " << v << std::endl;
	return v;
}

//Explicit instantiation
template EXPORT int Echo(int&&);
template EXPORT double Echo(double&&);