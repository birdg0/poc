// $ c++ `Magick++-config --cxxflags --cppflags` -O2 -o poc poc.cpp `Magick++-config --ldflags --libs`
// $ ./poc

#include <Magick++.h>
#include <iostream>

using namespace std;
using namespace Magick;

int main(int argc, char **argv) {
  Image image;
  image.read("logo.png");
  image.magick("MPEG");
  image.write("out.mp4");
  return 0;
}