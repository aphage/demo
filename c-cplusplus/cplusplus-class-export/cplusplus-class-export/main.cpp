#include <iostream>
#include <string>

#ifdef MAKEDLL
#  define EXPORT __declspec(dllexport)
#else
#  define EXPORT __declspec(dllimport)
#endif


class EXPORT Hello {

public:
	Hello(std::string&& name);

	void Say(std::string&& s);

private:
	std::string name;
};

class Hello2 {

public:
	EXPORT	Hello2(std::string&& name);
	EXPORT ~Hello2();

	EXPORT void Say(std::string&& s);

private:
	std::string name;
};

template<typename T>
class EXPORT Hello3 {

public:
	Hello3(std::string&& name);

	void Say(T v);

private:
	std::string name;
};

template<typename T>
EXPORT T Echo(T&& v);


class EXPORT Hello4 {

public:
	Hello4(const char* name);
	~Hello4();

	void Say(const char* s);

private:
	std::string* name;
};

#pragma comment(lib,"./../Debug/hello-aphage.lib")

int main() {
	Hello hello("aphage");
	hello.Say("aqua suki");

	Hello2 hello2("aphage");
	hello2.Say("alice suki,alice foo foo~");

	Hello3<std::string> hello3("aphage");
	hello3.Say("aqua suki");

	Hello3<int> hello31("aphage");
	hello31.Say(1);

	//error, No explicit instantiation
	//Hello3<char> hello31("aphage");
	//hello31.Say(1);

	Echo<int>(2233);

	Hello4 hello4("aphage");
	hello4.Say("aqua suki");

	//https://docs.microsoft.com/en-us/cpp/error-messages/compiler-warnings/compiler-warning-level-1-c4251?view=vs-2019

	return 0;
}