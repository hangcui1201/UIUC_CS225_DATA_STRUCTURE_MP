#include <cmath>
#include <iostream>
#include"cs225/PNG.h"
#include"cs225/HSLAPixel.h"
#include "Image.h"
#include "StickerSheet.h"

using namespace std;
using namespace cs225;

int main() {

  //
  // Reminder:
  //   Before exiting main, save your creation to disk as myImage.png
  //

  Image alma;
  alma.readFromFile("alma.png");

  Image i;
  i.readFromFile("i.png");

  Image zilles;
  zilles.readFromFile("zilles.png");

  Image wade;
  wade.readFromFile("wade.png");

  StickerSheet sheet(alma, 4);
  sheet.addSticker(i, 10, 10);
  sheet.addSticker(zilles, 200, 30);
  sheet.addSticker(wade,500,30);

  Image result = sheet.render();

  // cout << result.width() << endl;
  // cout << result.height() << endl;

  result.writeToFile("myImage.png");

  return 0;
}
