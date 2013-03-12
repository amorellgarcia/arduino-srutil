////////////////////////////////////////////////////////////////////////////////
/// @section LICENSE                                                         ///
///   Copyright (c) 2005 Sergey Ryazanov (http://home.onego.ru/~ryazanov)    ///
///                Distributed under the MIT License                         ///
///              (http://opensource.org/licenses/MIT)                        ///
///                                                                          ///
/// @file                                                                    ///
/// @author 2005 Sergey Ryazanov (http://home.onego.ru/~ryazanov)            ///
/// @author 2013 Alejandro Morell Garcia (http://github.com/amorellgarcia)   ///
/// @section DESCRIPTION                                                     ///
/// A simple example of using delegates with prefered syntax.                ///
/// Modified to be compatible with Arduino.                                  ///
////////////////////////////////////////////////////////////////////////////////

#include <SRUtilLib.h>

// Warning: needed header to declare TestDelegate type, because Arduino appends
// function declarations after includes and before any code.
#include "DelegateDemo.h"


void f(int, int) {
	Serial.println("f invoked.");
}

class TestClass {
public:
	void m1(int, int) {
		printInvokedForObject("m1");
	}

	void m2(int, int) const {
		printInvokedForObject("m2");
	}

	static void m3(int, int) {
		Serial.println("m3 invoked.");
	}

private:
	void printInvokedForObject(const char *prefix) const {
		Serial.print(prefix);
		Serial.print(" invoked for object 0x");
		Serial.print((uintptr_t)this, 16);
		Serial.println('.');
	}
};

void testDelegate(TestDelegate d) {
	if (d) {
		Serial.print("Direct invoking... ");
		d(5, 10);

		Serial.print("Invoking through invoker... ");
		TestDelegate::invoker_type inv(5, 10);
		inv(d);
	}

	if (!d) {
		Serial.println("The delegate is empty.");
	}
}

void setup() {
	TestClass obj;

	Serial.begin(9600);
	testDelegate(TestDelegate());
	testDelegate(TestDelegate::from_function<&f>());
	testDelegate(TestDelegate::from_method<TestClass, &TestClass::m1>(&obj));
	testDelegate(TestDelegate::from_const_method<TestClass, &TestClass::m2>(&obj));
	testDelegate(TestDelegate::from_function<&TestClass::m3>());
}

void loop() {
}

