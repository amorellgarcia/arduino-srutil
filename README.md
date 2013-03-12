# arduino-srutil

Fast-Delegate library for Arduino based on the SRUtil library (http://www.codeproject.com/Articles/11015/The-Impossibly-Fast-C-Delegates) wrote by Sergey Ryazanov.

## License
  As original SRUtil library this library is distributed under the MIT license. See LICENSE.TXT for more details.

## Installation
  Create a directory SRUtilLib (or whatever) in "libraries" folder of your sketchbooks.
  Copy all contents of this library to it.

## Usage
  Include file <SRUtilLib.h> in your sketch (file .ino) so Arduino includes this library at compilation.
  Include file <srutil/delegate.hpp> in each file that you want to use delegate class.
  See DelegateDemo for an example.
  Note that event.hpp are currently not supported as it needs BOOST libraries. See TODO.

## Version History

### 1.0 Initial version (12 March 2013)
  Refactored original SRUtil library to ease use in Arduino environment.

## TODO
  - Event implementation currently requires boost libraries, so event.hpp is currently useless. Create a custom binder that only uses delegates.
