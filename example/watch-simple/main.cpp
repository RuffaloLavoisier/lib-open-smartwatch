#include <FakeArduino.h>
#include <SDLWindow.h>
#include <stdint.h>

#include <iostream>

#include "../../anim/p3dt_anim_doom_fire.h"
#include "../../gfx/p3dt_gfx_2d.h"
#include "../../gfx/p3dt_gfx_util.h"
using namespace std;

#define BUF_W 240
#define BUF_H 240
uint16_t screenBuffer[BUF_W * BUF_H];

Graphics2D gfx2d(BUF_W, BUF_H, 16);

uint8_t badBitmap[] = {0b10101010, 0b01010101, 0b00001111, 0b10000001};

class WatchSimpleWindow : public SDLWindowRGB565 {
 public:
  WatchSimpleWindow(Graphics2D* gfx2d, int w, int h) : SDLWindowRGB565(gfx2d, w, h) {}
  void setup() {}

  void loop() {
    static uint x = 0;
    x++;
    x = x % BUF_W;

    // gfx2d.drawLine(0, 0, x, x, rgb565(x, x, 255));
    // gfx2d.fillFrame(10, 10, 10, 10, rgb565(x, x, 100));
    // gfx2d.drawCircle(120, 120, 32, rgb565(255, 255, 255));
    // gfx2d.fillFrame(10, 10, 10, 10, rgb565(255, 255, 100));
    // gfx2d.drawEllipse(20, 20, 5, 20, rgb565(255, 0, 0));
    // gfx2d.fillEllipse(120, 20, 5, 20, rgb565(255, 0, 0));
    // gfx2d.fillFrame(10, 10, 10, 10, rgb565(255, 255, 100));
    // gfx2d.drawEllipse(20, 20, 5, 20, rgb565(255, 0, 0));
    // gfx2d.fillEllipse(120, 20, 5, 20, rgb565(255, 0, 0));
    // gfx2d.fillRFrame(40, 40, 20, 30, 4, rgb565(255, 255, 100));
    // gfx2d.drawRFrame(60, 60, 30, 20, 4, rgb565(255, 0, 0));
    gfx2d.drawWatchFace(BUF_W / 2, BUF_H / 2, 100, rgb565(255, 255, 255));

    delay(1000 / 30);  // 30FPS
  }
};

int main(int argc, char* argv[]) {
  WatchSimpleWindow wsw(&gfx2d, BUF_W, BUF_H);
  wsw.run();
  return 0;
}