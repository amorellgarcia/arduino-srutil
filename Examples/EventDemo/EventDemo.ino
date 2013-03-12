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
/// An example of using SRUtil.Event library with callback interfaces.       ///
/// Modified to be compatible with Arduino.                                  ///
////////////////////////////////////////////////////////////////////////////////

#include <SRUtilLib.h>

#include <srutil/delegate.hpp>
#include <srutil/event.hpp>

// TODO Implement stub boost::noncopyable To avoid modifying original demo
namespace boost {
struct noncopyable {
};
}

class Widget : boost::noncopyable {
public:
	class MouseEventsListener;
	typedef srutil::event_source<MouseEventsListener*> MouseEventsSource;

	MouseEventsSource const & getMouseEventsSource() const {
		return mouseEventSource;
	}
	void Test();

private:
	MouseEventsSource mouseEventSource;
};

class Widget::MouseEventsListener : boost::noncopyable {
public:
	virtual void onMouseMove(int x, int y) = 0;
	virtual void onMouseDown(int x, int y, int button) = 0;
	virtual void onMouseUp(int x, int y, int button) = 0;
};

class WidgetObserver : Widget::MouseEventsListener {
public:
	WidgetObserver(Widget* widget) {
		binder.bind(widget->getMouseEventsSource(), this);
	}

private:
	Widget::MouseEventsSource::binder_type binder;

	void printXY(int x, int y) {
		Serial.print("(");
		Serial.print(x);
		Serial.print(", ");
		Serial.print(y);
		Serial.println(").");
	}

	void onMouseMove(int x, int y) {
		Serial.print("Mouse pointer moved to ");
		printXY(x, y);
	}
	void onMouseDown(int x, int y, int button) {
		Serial.print("Mouse button ");
		Serial.print(button);
		Serial.print(" pressed at ");
		printXY(x, y);
	}
	void onMouseUp(int x, int y, int button) {
		Serial.print("Mouse button ");
		Serial.print(button);
		Serial.print(" released at ");
		printXY(x, y);
	}
};


void Widget::Test() {
// TODO create a custom binder which can replace boost::bind
//	mouseEventSource.emit(boost::bind(&MouseEventsListener::onMouseDown, _1, 10, 10, 1));
//	mouseEventSource.emit(boost::bind(&MouseEventsListener::onMouseMove, _1, 15, 15));
//	mouseEventSource.emit(boost::bind(&MouseEventsListener::onMouseMove, _1, 20, 15));
//	mouseEventSource.emit(boost::bind(&MouseEventsListener::onMouseMove, _1, 25, 15));
//	mouseEventSource.emit(boost::bind(&MouseEventsListener::onMouseMove, _1, 25, 20));
//	mouseEventSource.emit(boost::bind(&MouseEventsListener::onMouseUp, _1, 25, 20, 1));
}

void setup() {
	Serial.begin(9600);

	Widget widget;
	widget.Test(); // no listeners, nothing happened

	WidgetObserver observer(&widget);
	widget.Test(); // observer revieves events
}

void loop() {
}

