# arduino-srutil

Delegate library for Arduino based on the SRUtil library (http://www.codeproject.com/Articles/11015/The-Impossibly-Fast-C-Delegates).

## Installation
  Create a directory SRUtil (or whatever) in "libraries" folder of your sketchbooks.
  Copy all contents to it.

## Usage
  Include file <SRUtilLib.h> in your sketch (file .ino) so Arduino includes this library at compilation.
  Include file <srutil/delegate.hpp> in each file that you want to use delegate class.
  See DelegateDemo for an example.

## Version History

### 1.0 Initial version.
  Refactored original SRUtil library to ease use in Arduino environment.
