#ifndef GFXLIB_H_
#define GFXLIB_H_

#define swap(a, b) { int16_t t = a; a = b; b = t; }

Adafruit_GFX(int16_t w, int16_t h); // Constructor

// This MUST be defined by the subclass:
void drawPixel(int16_t x, int16_t y, uint16_t color);

// These MAY be overridden by the subclass to provide device-specific
// optimized code.  Otherwise 'generic' versions are used.

void drawLine(int16_t x0, int16_t y0, int16_t x1, int16_t y1, uint16_t color);
void drawFastVLine(int16_t x, int16_t y, int16_t h, uint16_t color);
void drawFastHLine(int16_t x, int16_t y, int16_t w, uint16_t color);
void drawRect(int16_t x, int16_t y, int16_t w, int16_t h, uint16_t color);
void fillRect(int16_t x, int16_t y, int16_t w, int16_t h, uint16_t color);
void fillScreen(uint16_t color);
void invertDisplay(boolean i);

// These exist only with Adafruit_GFX (no subclass overrides)
void drawCircle(int16_t x0, int16_t y0, int16_t r, uint16_t color);
void drawCircleHelper(int16_t x0, int16_t y0, int16_t r, uint8_t cornername, uint16_t color),
void fillCircle(int16_t x0, int16_t y0, int16_t r, uint16_t color);
void fillCircleHelper(int16_t x0, int16_t y0, int16_t r, uint8_t cornername, int16_t delta, uint16_t color),
void drawTriangle(int16_t x0, int16_t y0, int16_t x1, int16_t y1, int16_t x2, int16_t y2, uint16_t color);
void fillTriangle(int16_t x0, int16_t y0, int16_t x1, int16_t y1, int16_t x2, int16_t y2, uint16_t color);
void drawRoundRect(int16_t x0, int16_t y0, int16_t w, int16_t h, int16_t radius, uint16_t color);
void fillRoundRect(int16_t x0, int16_t y0, int16_t w, int16_t h, int16_t radius, uint16_t color);
void drawBitmap(int16_t x, int16_t y, const uint8_t *bitmap, int16_t w, int16_t h, uint16_t color);
void drawChar(int16_t x, int16_t y, unsigned char c, uint16_t color, uint16_t bg, uint8_t size);
void setCursor(int16_t x, int16_t y);
void setTextColor(uint16_t c);
void setTextColor(uint16_t c, uint16_t bg);
void setTextSize(uint8_t s);
void setTextWrap(boolean w);
void setRotation(uint8_t r);
void   write(uint8_t);

int16_t height(void);
int16_t width(void);
uint8_t getRotation(void);

#endif /* GFXLIB_H_ */
