#include <iostream>

class FooBar {
	private:
		bool isFoo;
	public:
		bool getIsFoo() {
			return isFoo;
		}
		void setIsFoo(bool value) {
			isFoo = value;
		}
};

class Foo {
	private:
		static FooBar* _instance;
	public:
		static FooBar* Instance() {
			if (_instance == nullptr) {
				_instance = new FooBar;
			}
			return _instance;
		}

		static void destroy() {
			if (_instance != nullptr) {
				delete _instance;
			}
		}
};
FooBar* Foo::_instance = nullptr;

class A : Foo {
	public:
		void Foo() {
			if (Instance()->getIsFoo()) {
				std::cout << "8=))" << std::endl;
			}
		}

		void SetFooBar(bool value) {
			Instance()->setIsFoo(value);
		}

		~A() {
			destroy();
		}
};

int main() {
	A a = A();

	std::cout << "Regularly: " << std::endl;;
	a.Foo();

	std::cout << "Setting it to true: " << std::endl;;
	a.SetFooBar(true);
	a.Foo();

	return 0;
}
