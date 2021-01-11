#define MAX_FONT 6

const PROGMEM uint8_t font5x8[] =
{
  32,     // first character
  5,      // font width, w=0 => multiwidth
  8,      // font height
  5,      // byte per font
  1,      // byte per data
  0x00,0x00,0x00,0x00,0x00,  //
  0x00,0x60,0xFA,0x60,0x00,  // !
  0xE0,0xC0,0x00,0xE0,0xC0,  // "
  0x24,0x7E,0x24,0x7E,0x24,  // #
  0x24,0xD4,0x56,0x48,0x00,  // $
  0xC6,0xC8,0x10,0x26,0xC6,  // %
  0x6C,0x92,0x6A,0x04,0x0A,  // &
  0x00,0xE0,0xC0,0x00,0x00,  // '
  0x00,0x7C,0x82,0x00,0x00,  // (
  0x00,0x82,0x7C,0x00,0x00,  // )
  0x10,0x7C,0x38,0x7C,0x10,  // *
  0x10,0x10,0x7C,0x10,0x10,  // +
  0x00,0x07,0x06,0x00,0x00,  // ,
  0x10,0x10,0x10,0x10,0x10,  // -
  0x00,0x06,0x06,0x00,0x00,  // .
  0x04,0x08,0x10,0x20,0x40,  // /
  0x7C,0x8A,0x92,0xA2,0x7C,  // 0
  0x00,0x42,0xFE,0x02,0x00,  // 1
  0x46,0x8A,0x92,0x92,0x62,  // 2
  0x44,0x92,0x92,0x92,0x6C,  // 3
  0x18,0x28,0x48,0xFE,0x08,  // 4
  0xF4,0x92,0x92,0x92,0x8C,  // 5
  0x3C,0x52,0x92,0x92,0x0C,  // 6
  0x80,0x8E,0x90,0xA0,0xC0,  // 7
  0x6C,0x92,0x92,0x92,0x6C,  // 8
  0x60,0x92,0x92,0x94,0x78,  // 9
  0x00,0x36,0x36,0x00,0x00,  // :
  0x00,0x37,0x36,0x00,0x00,  // ;
  0x10,0x28,0x44,0x82,0x00,  // <
  0x24,0x24,0x24,0x24,0x24,  // =
  0x00,0x82,0x44,0x28,0x10,  // >
  0x40,0x80,0x9A,0x90,0x60,  // ?
  0x7C,0x82,0xBA,0xAA,0x78,  // @
  0x7E,0x88,0x88,0x88,0x7E,  // A
  0xFE,0x92,0x92,0x92,0x6C,  // B
  0x7C,0x82,0x82,0x82,0x44,  // C
  0xFE,0x82,0x82,0x82,0x7C,  // D
  0xFE,0x92,0x92,0x92,0x82,  // E
  0xFE,0x90,0x90,0x90,0x80,  // F
  0x7C,0x82,0x92,0x92,0x5E,  // G
  0xFE,0x10,0x10,0x10,0xFE,  // H
  0x00,0x82,0xFE,0x82,0x00,  // I
  0x0C,0x02,0x02,0x02,0xFC,  // J
  0xFE,0x10,0x28,0x44,0x82,  // K
  0xFE,0x02,0x02,0x02,0x02,  // L
  0xFE,0x40,0x20,0x40,0xFE,  // M
  0xFE,0x40,0x20,0x10,0xFE,  // N
  0x7C,0x82,0x82,0x82,0x7C,  // O
  0xFE,0x90,0x90,0x90,0x60,  // P
  0x7C,0x82,0x8A,0x84,0x7A,  // Q
  0xFE,0x90,0x90,0x98,0x66,  // R
  0x64,0x92,0x92,0x92,0x4C,  // S
  0x80,0x80,0xFE,0x80,0x80,  // T
  0xFC,0x02,0x02,0x02,0xFC,  // U
  0xF8,0x04,0x02,0x04,0xF8,  // V
  0xFC,0x02,0x3C,0x02,0xFC,  // W
  0xC6,0x28,0x10,0x28,0xC6,  // X
  0xE0,0x10,0x0E,0x10,0xE0,  // Y
  0x8E,0x92,0xA2,0xC2,0x00,  // Z
  0x00,0xFE,0x82,0x82,0x00,  // [
  0x40,0x20,0x10,0x08,0x04,  // backslash
  0x00,0x82,0x82,0xFE,0x00,  // ]
  0x20,0x40,0x80,0x40,0x20,  // ^
  0x01,0x01,0x01,0x01,0x01,  // _
  0x00,0xC0,0xE0,0x00,0x00,  // `
  0x04,0x2A,0x2A,0x2A,0x1E,  // a
  0xFE,0x22,0x22,0x22,0x1C,  // b
  0x1C,0x22,0x22,0x22,0x14,  // c
  0x1C,0x22,0x22,0x22,0xFE,  // d
  0x1C,0x2A,0x2A,0x2A,0x10,  // e
  0x10,0x7E,0x90,0x90,0x00,  // f
  0x18,0x25,0x25,0x25,0x3E,  // g
  0xFE,0x20,0x20,0x1E,0x00,  // h
  0x00,0x00,0xBE,0x02,0x00,  // i
  0x02,0x01,0x21,0xBE,0x00,  // j
  0xFE,0x08,0x14,0x22,0x00,  // k
  0x00,0x00,0xFE,0x02,0x00,  // l
  0x3E,0x20,0x18,0x20,0x1E,  // m
  0x3E,0x20,0x20,0x1E,0x00,  // n
  0x1C,0x22,0x22,0x22,0x1C,  // o
  0x3F,0x22,0x22,0x22,0x1C,  // p
  0x1C,0x22,0x22,0x22,0x3F,  // q
  0x22,0x1E,0x22,0x20,0x10,  // r
  0x10,0x2A,0x2A,0x2A,0x04,  // s
  0x20,0x7C,0x22,0x24,0x00,  // t
  0x3C,0x02,0x04,0x3E,0x00,  // u
  0x38,0x04,0x02,0x04,0x38,  // v
  0x3C,0x06,0x0C,0x06,0x3C,  // w
  0x36,0x08,0x08,0x36,0x00,  // x
  0x39,0x05,0x06,0x3C,0x00,  // y
  0x26,0x2A,0x2A,0x32,0x00,  // z
  0x10,0x7C,0x82,0x82,0x00,  // {
  0x00,0x00,0xEE,0x00,0x00,  // |
  0x00,0x82,0x82,0x7C,0x10,  // }
  0x40,0x80,0x40,0x80,0x00,  // ~
  0x3C,0x64,0xC4,0x64,0x3C,  // 
};

const PROGMEM uint8_t font8x8[] = {
  32,7,8,7,1,
  0x00,0x00,0x00,0x00,0x00,0x00,0x00,  //
  0x00,0x00,0x00,0xFA,0xFA,0x00,0x00,  // !
  0x00,0xE0,0xE0,0x00,0xE0,0xE0,0x00,  // "
  0x28,0xFE,0xFE,0x28,0xFE,0xFE,0x28,  // #
  0x24,0x74,0x54,0xD6,0xD6,0x5C,0x48,  // $
  0x62,0x66,0x0C,0x18,0x30,0x66,0x46,  // %
  0x0C,0x5E,0xF2,0xBA,0xEC,0x5E,0x12,  // &
  0x00,0x20,0xE0,0xC0,0x00,0x00,0x00,  // '
  0x00,0x00,0x38,0x7C,0xC6,0x82,0x00,  // (
  0x00,0x00,0x82,0xC6,0x7C,0x38,0x00,  // )
  0x10,0x54,0x7C,0x38,0x38,0x7C,0x54,  // *
  0x00,0x10,0x10,0x7C,0x7C,0x10,0x10,  // +
  0x00,0x00,0x01,0x07,0x06,0x00,0x00,  // ,
  0x00,0x10,0x10,0x10,0x10,0x10,0x10,  // -
  0x00,0x00,0x00,0x06,0x06,0x00,0x00,  // .
  0x06,0x0C,0x18,0x30,0x60,0xC0,0x80,  // /
  0x7C,0xFE,0x9A,0xB2,0xE2,0xFE,0x7C,  // 0
  0x00,0x02,0x42,0xFE,0xFE,0x02,0x02,  // 1
  0x4E,0xDE,0x92,0x92,0x92,0xF2,0x62,  // 2
  0x82,0x82,0x92,0x92,0x92,0xFE,0x6C,  // 3
  0x78,0x78,0x08,0x08,0xFE,0xFE,0x08,  // 4
  0xE4,0xE6,0xA2,0xA2,0xA2,0xBE,0x9C,  // 5
  0x7C,0xFE,0x92,0x92,0x92,0x9E,0x0C,  // 6
  0x80,0x80,0x86,0x8E,0x98,0xF0,0xE0,  // 7
  0x6C,0xFE,0x92,0x92,0x92,0xFE,0x6C,  // 8
  0x60,0xF2,0x92,0x92,0x92,0xFE,0x7C,  // 9
  0x00,0x00,0x00,0x66,0x66,0x00,0x00,  // :
  0x00,0x00,0x01,0x67,0x66,0x00,0x00,  // ;
  0x00,0x10,0x38,0x6C,0xC6,0x82,0x00,  // <
  0x00,0x28,0x28,0x28,0x28,0x28,0x28,  // =
  0x00,0x00,0x82,0xC6,0x6C,0x38,0x10,  // >
  0x00,0x40,0xC0,0x9A,0xBA,0xE0,0x40,  // ?
  0x7C,0xFE,0x82,0xBA,0xBA,0xFA,0x7A,  // @
  0x3E,0x7E,0xC8,0x88,0xC8,0x7E,0x3E,  // A
  0xFE,0xFE,0x92,0x92,0x92,0xFE,0x6C,  // B
  0x7C,0xFE,0x82,0x82,0x82,0xC6,0x44,  // C
  0xFE,0xFE,0x82,0x82,0xC6,0x7C,0x38,  // D
  0xFE,0xFE,0x92,0x92,0x92,0x82,0x82,  // E
  0xFE,0xFE,0x90,0x90,0x90,0x80,0x80,  // F
  0x7C,0xFE,0x82,0x82,0x8A,0xCE,0x4C,  // G
  0xFE,0xFE,0x10,0x10,0x10,0xFE,0xFE,  // H
  0x00,0x82,0x82,0xFE,0xFE,0x82,0x82,  // I
  0x04,0x06,0x02,0x02,0x02,0xFE,0xFC,  // J
  0xFE,0xFE,0x10,0x38,0x6C,0xC6,0x82,  // K
  0xFE,0xFE,0x02,0x02,0x02,0x02,0x02,  // L
  0xFE,0xFE,0x70,0x38,0x70,0xFE,0xFE,  // M
  0xFE,0xFE,0x60,0x30,0x18,0xFE,0xFE,  // N
  0x7C,0xFE,0x82,0x82,0x82,0xFE,0x7C,  // O
  0xFE,0xFE,0x90,0x90,0x90,0xF0,0x60,  // P
  0x7C,0xFE,0x82,0x8E,0x86,0xFF,0x7D,  // Q
  0xFE,0xFE,0x90,0x98,0x9C,0xF6,0x62,  // R
  0x64,0xF6,0x92,0x92,0x92,0xDE,0x4C,  // S
  0x80,0x80,0x80,0xFE,0xFE,0x80,0x80,  // T
  0xFE,0xFE,0x02,0x02,0x02,0xFE,0xFE,  // U
  0xF8,0xFC,0x06,0x06,0x06,0xFC,0xF8,  // V
  0xFC,0xFE,0x06,0x0C,0x06,0xFE,0xFC,  // W
  0xC6,0xEE,0x38,0x10,0x38,0xEE,0xC6,  // X
  0xE2,0xF2,0x16,0x1C,0x18,0xF0,0xE0,  // Y
  0x82,0x86,0x8E,0x9A,0xB2,0xE2,0xC2,  // Z
  0x00,0x00,0xFE,0xFE,0x82,0x82,0x00,  // [
  0x80,0xC0,0x60,0x30,0x18,0x0C,0x06,  // backslash
  0x00,0x00,0x82,0x82,0xFE,0xFE,0x00,  // ]
  0x10,0x30,0x60,0xC0,0x60,0x30,0x10,  // ^
  0x01,0x01,0x01,0x01,0x01,0x01,0x01,  // _
  0x00,0x00,0x00,0xC0,0xE0,0x20,0x00,  // `
  0x04,0x2E,0x2A,0x2A,0x2A,0x3E,0x1E,  // a
  0xFE,0xFE,0x12,0x12,0x12,0x1E,0x0C,  // b
  0x1C,0x3E,0x22,0x22,0x22,0x36,0x14,  // c
  0x0C,0x1E,0x12,0x12,0x12,0xFE,0xFE,  // d
  0x1C,0x3E,0x2A,0x2A,0x2A,0x3A,0x18,  // e
  0x00,0x12,0x7E,0xFE,0x92,0xC0,0x40,  // f
  0x19,0x3D,0x25,0x25,0x25,0x3F,0x3E,  // g
  0xFE,0xFE,0x20,0x20,0x20,0x3E,0x1E,  // h
  0x00,0x00,0x22,0xBE,0xBE,0x02,0x00,  // i
  0x02,0x03,0x01,0x01,0x01,0xBF,0xBE,  // j
  0xFE,0xFE,0x08,0x18,0x3C,0x26,0x02,  // k
  0x00,0x00,0x82,0xFE,0xFE,0x02,0x00,  // l
  0x3E,0x3E,0x18,0x1E,0x38,0x3E,0x1E,  // m
  0x3E,0x3E,0x20,0x20,0x20,0x3E,0x1E,  // n
  0x1C,0x3E,0x22,0x22,0x22,0x3E,0x1C,  // o
  0x3F,0x3F,0x24,0x24,0x24,0x3C,0x18,  // p
  0x18,0x3C,0x24,0x24,0x24,0x3F,0x3F,  // q
  0x3E,0x3E,0x20,0x20,0x20,0x30,0x10,  // r
  0x12,0x3A,0x2A,0x2A,0x2A,0x2E,0x24,  // s
  0x00,0x20,0x20,0xFC,0xFE,0x22,0x22,  // t
  0x3C,0x3E,0x02,0x02,0x02,0x3E,0x3E,  // u
  0x38,0x3C,0x06,0x06,0x06,0x3C,0x38,  // v
  0x3C,0x3E,0x06,0x0C,0x06,0x3E,0x3C,  // w
  0x22,0x36,0x1C,0x08,0x1C,0x36,0x22,  // x
  0x39,0x3D,0x05,0x05,0x05,0x3F,0x3E,  // y
  0x22,0x26,0x2E,0x2A,0x3A,0x32,0x22,  // z
  0x00,0x10,0x10,0x7C,0xEE,0x82,0x82,  // {
  0x00,0x00,0x00,0xEE,0xEE,0x00,0x00,  // |
  0x00,0x82,0x82,0xEE,0x7C,0x10,0x10,  // }
  0x40,0xC0,0x80,0xC0,0x40,0xC0,0x80,  // ~
  0x0E,0x1E,0x32,0x62,0x32,0x1E,0x0E,  // 
};

const PROGMEM uint8_t font4x6[] = {
  32,3,5,3,1,
  0x00,0x00,0x00,  //
  0x00,0xE8,0x00,  // !
  0xC0,0x00,0xC0,  // "
  0xF8,0x50,0xF8,  // #
  0x28,0xFC,0x50,  // $
  0x90,0x20,0x48,  // %
  0x58,0xA8,0x78,  // &
  0xC0,0x80,0x00,  // '
  0x70,0x88,0x00,  // (
  0x88,0x70,0x00,  // )
  0xA8,0x70,0xA8,  // *
  0x20,0x70,0x20,  // +
  0x0C,0x08,0x00,  // ,
  0x20,0x20,0x20,  // -
  0x00,0x08,0x00,  // .
  0x18,0x20,0xC0,  // /
  0x78,0x88,0xF0,  // 0
  0x48,0xF8,0x08,  // 1
  0x98,0xA8,0x48,  // 2
  0x88,0xA8,0x50,  // 3
  0x60,0x20,0xF8,  // 4
  0xE8,0xA8,0x90,  // 5
  0x70,0xA8,0x10,  // 6
  0x80,0xB8,0xE0,  // 7
  0x50,0xA8,0x50,  // 8
  0x40,0xA8,0x70,  // 9
  0x00,0x28,0x00,  // :
  0x0C,0x28,0x00,  // ;
  0x20,0x50,0x88,  // <
  0x28,0x28,0x28,  // =
  0x88,0x50,0x20,  // >
  0x80,0xA8,0x40,  // ?
  0xF8,0x88,0xE8,  // @
  0x78,0xA0,0x78,  // A
  0xF8,0xA8,0x50,  // B
  0x70,0x88,0x88,  // C
  0xF8,0x88,0x70,  // D
  0xF8,0xA8,0x88,  // E
  0xF8,0xA0,0x80,  // F
  0x70,0x88,0xB8,  // G
  0xF8,0x20,0xF8,  // H
  0x88,0xF8,0x88,  // I
  0x10,0x08,0xF0,  // J
  0xF8,0x20,0xD8,  // K
  0xF8,0x08,0x08,  // L
  0xF8,0x60,0xF8,  // M
  0xF8,0x40,0xF8,  // N
  0x70,0x88,0x70,  // O
  0xF8,0xA0,0x40,  // P
  0x70,0x98,0x78,  // Q
  0xF8,0xA0,0x58,  // R
  0x68,0xA8,0xB0,  // S
  0x80,0xF8,0x80,  // T
  0xF8,0x08,0xF8,  // U
  0xF0,0x08,0xF0,  // V
  0xF8,0x30,0xF8,  // W
  0xD8,0x20,0xD8,  // X
  0xC0,0x38,0xC0,  // Y
  0x98,0xA8,0xC8,  // Z
  0xF8,0x88,0x00,  // [
  0xC0,0x20,0x18,  // backslash
  0x88,0xF8,0x00,  // ]
  0x40,0x80,0x40,  // ^
  0x04,0x04,0x04,  // _
  0x80,0xC0,0x00,  // `
  0x18,0x28,0x38,  // a
  0xF8,0x28,0x10,  // b
  0x10,0x28,0x28,  // c
  0x10,0x28,0xF8,  // d
  0x30,0x38,0x28,  // e
  0x20,0x78,0xA0,  // f
  0x34,0x24,0x3C,  // g
  0xF8,0x20,0x18,  // h
  0x00,0xB8,0x00,  // i
  0x04,0xBC,0x00,  // j
  0xF8,0x10,0x28,  // k
  0x00,0xF8,0x00,  // l
  0x38,0x30,0x38,  // m
  0x38,0x20,0x18,  // n
  0x10,0x28,0x10,  // o
  0x3C,0x28,0x10,  // p
  0x10,0x28,0x3C,  // q
  0x38,0x20,0x00,  // r
  0x08,0x38,0x20,  // s
  0x20,0x78,0x28,  // t
  0x38,0x08,0x38,  // u
  0x30,0x08,0x30,  // v
  0x38,0x18,0x38,  // w
  0x28,0x10,0x28,  // x
  0x34,0x08,0x30,  // y
  0x20,0x38,0x08,  // z
  0x20,0xF8,0x88,  // {
  0x00,0xF8,0x00,  // |
  0x88,0xF8,0x20,  // }
  0x80,0x40,0x80,  // ~
  0x30,0x50,0x30,  // 
};

const PROGMEM uint8_t decor9x16[] = {
  32,8,16,16,2,
  0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,  //  
  0x00,0x00,0x00,0x00,0x1E,0x08,0x3F,0xDC,0x1E,0x08,0x00,0x00,0x00,0x00,0x00,0x00,  // !
  0x00,0x00,0x1E,0x00,0x3C,0x00,0x00,0x00,0x00,0x00,0x1E,0x00,0x3C,0x00,0x00,0x00,  // "
  0x00,0x00,0x02,0x20,0x0F,0xFC,0x1F,0xF8,0x02,0x20,0x0F,0xFC,0x1F,0xF8,0x02,0x20,  // #
  0x00,0x00,0x06,0x08,0x0F,0x1C,0x13,0x8C,0x7F,0xFF,0x18,0xE4,0x1C,0x78,0x08,0x30,  // $
  0x00,0x10,0x0C,0x30,0x1E,0x60,0x12,0xD8,0x0D,0xBC,0x03,0x24,0x06,0x18,0x04,0x00,  // %
  0x00,0x00,0x00,0x78,0x06,0xFC,0x0F,0x0C,0x11,0x88,0x1B,0xF0,0x0C,0xFC,0x01,0x8C,  // &
  0x00,0x00,0x00,0x00,0x12,0x00,0x3C,0x00,0x18,0x00,0x00,0x00,0x00,0x00,0x00,0x00,  // '
  0x00,0x00,0x00,0x00,0x01,0xE0,0x07,0xF8,0x0C,0x3C,0x10,0x0E,0x20,0x04,0x00,0x00,  // (
  0x00,0x00,0x00,0x00,0x10,0x02,0x38,0x04,0x1E,0x18,0x0F,0xF0,0x03,0xC0,0x00,0x00,  // )
  0x00,0x80,0x02,0x90,0x07,0xA0,0x03,0xC0,0x01,0xE0,0x02,0xF0,0x04,0xA0,0x00,0x80,  // *
  0x00,0x80,0x01,0x80,0x01,0x80,0x07,0xF0,0x0F,0xE0,0x01,0x80,0x01,0x80,0x01,0x00,  // +
  0x00,0x00,0x00,0x00,0x00,0x09,0x00,0x1E,0x00,0x0C,0x00,0x00,0x00,0x00,0x00,0x00,  // ,
  0x00,0x00,0x00,0x80,0x01,0x80,0x01,0x80,0x01,0x80,0x01,0x80,0x01,0x80,0x01,0x00,  // -
  0x00,0x00,0x00,0x00,0x00,0x08,0x00,0x1C,0x00,0x08,0x00,0x00,0x00,0x00,0x00,0x00,  // .
  0x00,0x00,0x00,0x0E,0x00,0x38,0x00,0xE0,0x03,0x80,0x0E,0x00,0x38,0x00,0x00,0x00,  // /
  0x00,0x00,0x03,0xF0,0x07,0xF8,0x08,0x5C,0x18,0x8C,0x1D,0x08,0x0F,0xF0,0x07,0xE0,  // 0
  0x00,0x00,0x01,0x00,0x02,0x00,0x04,0x00,0x0F,0xFC,0x1F,0xF8,0x00,0x00,0x00,0x00,  // 1
  0x00,0x00,0x04,0x0C,0x08,0x1C,0x18,0x2C,0x18,0x4C,0x18,0x8C,0x1F,0x0C,0x0E,0x08,  // 2
  0x00,0x00,0x08,0x04,0x18,0x0E,0x19,0x06,0x1B,0x06,0x1D,0x84,0x19,0xF8,0x10,0xF0,  // 3
  0x00,0x70,0x00,0xF0,0x01,0xB0,0x03,0x30,0x06,0x30,0x0F,0xFE,0x1F,0xFC,0x00,0x20,  // 4
  0x00,0x00,0x03,0x04,0x0D,0x0E,0x19,0x06,0x19,0x06,0x19,0x84,0x19,0xF8,0x10,0xF0,  // 5
  0x00,0x00,0x07,0xF8,0x0F,0xFC,0x11,0x8C,0x31,0x8C,0x31,0x88,0x21,0xF0,0x00,0xE0,  // 6
  0x04,0x00,0x08,0x02,0x18,0x0E,0x18,0x3E,0x18,0xF8,0x1B,0xC0,0x1E,0x00,0x10,0x00,  // 7
  0x00,0x00,0x0E,0x38,0x1F,0xFC,0x33,0x8C,0x31,0x8C,0x31,0xCC,0x3F,0xF8,0x1C,0x70,  // 8
  0x00,0x00,0x03,0x80,0x07,0xC2,0x08,0xC6,0x18,0xC6,0x18,0xC4,0x1F,0xF8,0x0F,0xF0,  // 9
  0x00,0x00,0x00,0x00,0x02,0x10,0x07,0x38,0x02,0x10,0x00,0x00,0x00,0x00,0x00,0x00,  // :
  0x00,0x00,0x00,0x00,0x02,0x12,0x07,0x3C,0x02,0x18,0x00,0x00,0x00,0x00,0x00,0x00,  // ;
  0x00,0x00,0x00,0x80,0x01,0xC0,0x03,0xE0,0x06,0x70,0x0C,0x38,0x08,0x10,0x00,0x00,  // <
  0x00,0x00,0x01,0x10,0x03,0x30,0x03,0x30,0x03,0x30,0x03,0x30,0x03,0x30,0x02,0x20,  // =
  0x00,0x00,0x04,0x08,0x0E,0x18,0x07,0x30,0x03,0xE0,0x01,0xC0,0x00,0x80,0x00,0x00,  // >
  0x00,0x00,0x04,0x00,0x08,0x00,0x18,0x40,0x18,0xEC,0x19,0x2C,0x1E,0x40,0x0C,0x00,  // ?
  0x03,0xF0,0x07,0xF8,0x08,0x0C,0x11,0xE4,0x13,0xE4,0x1A,0x24,0x1F,0xC8,0x0F,0x90,  // @
  0x01,0xFC,0x03,0xF8,0x04,0x60,0x08,0x60,0x1C,0x60,0x0E,0x60,0x07,0xFC,0x03,0xF8,  // A
  0x08,0x00,0x1F,0xFC,0x1F,0xFC,0x19,0x8C,0x19,0x8C,0x19,0xCC,0x1F,0xF8,0x0E,0x70,  // B
  0x03,0xF0,0x07,0xF8,0x08,0x1C,0x18,0x0C,0x18,0x0C,0x18,0x0C,0x1C,0x08,0x08,0x10,  // C
  0x08,0x00,0x1F,0xFC,0x1F,0xFC,0x18,0x0C,0x18,0x0C,0x1C,0x08,0x0F,0xF0,0x07,0xE0,  // D
  0x08,0x00,0x1F,0xFC,0x1F,0xFC,0x19,0x8C,0x19,0x8C,0x19,0x8C,0x19,0x0C,0x10,0x18,  // E
  0x08,0x00,0x1F,0xFC,0x1F,0xFC,0x18,0xC8,0x18,0xC0,0x18,0xC0,0x18,0x80,0x10,0x00,  // F
  0x03,0xF0,0x07,0xF8,0x08,0x1C,0x18,0x0C,0x18,0x44,0x18,0xC4,0x1C,0xFC,0x08,0xF8,  // G
  0x08,0x00,0x1F,0xFC,0x1F,0xF8,0x00,0x80,0x00,0x80,0x00,0x80,0x0F,0xFC,0x1F,0xF8,  // H
  0x00,0x00,0x00,0x00,0x08,0x04,0x1F,0xFC,0x1F,0xFC,0x10,0x08,0x00,0x00,0x00,0x00,  // I
  0x00,0x00,0x04,0x01,0x08,0x01,0x18,0x01,0x1F,0xFE,0x1F,0xFC,0x10,0x00,0x00,0x00,  // J
  0x08,0x00,0x1F,0xFC,0x1F,0xF8,0x01,0xC0,0x03,0xE0,0x06,0x70,0x1C,0x3C,0x18,0x18,  // K
  0x00,0x04,0x0F,0xFC,0x1F,0xFC,0x18,0x0C,0x10,0x0C,0x00,0x0C,0x00,0x0C,0x00,0x18,  // L
  0x04,0x00,0x0F,0xFC,0x1E,0x00,0x07,0xC0,0x03,0x80,0x06,0x00,0x0F,0xFC,0x1F,0xF8,  // M
  0x04,0x00,0x0F,0xFC,0x1C,0x08,0x0F,0x00,0x03,0xC0,0x00,0xF0,0x08,0x3C,0x1F,0xF8,  // N
  0x03,0xF0,0x07,0xF8,0x08,0x1C,0x18,0x0C,0x18,0x0C,0x1C,0x08,0x0F,0xF0,0x07,0xE0,  // O
  0x08,0x00,0x1F,0xFC,0x1F,0xFC,0x18,0x48,0x18,0x40,0x18,0x40,0x1F,0x80,0x0F,0x00,  // P
  0x03,0xF0,0x07,0xF8,0x08,0x18,0x18,0x0A,0x18,0x06,0x1C,0x0F,0x0F,0xF3,0x07,0xE2,  // Q
  0x08,0x00,0x1F,0xFC,0x1F,0xF8,0x18,0xC0,0x18,0xE0,0x19,0x70,0x1F,0x3C,0x0E,0x18,  // R
  0x06,0x08,0x0F,0x1C,0x13,0x8C,0x11,0xC4,0x18,0xE4,0x1C,0x78,0x08,0x30,0x00,0x00,  // S
  0x04,0x00,0x08,0x00,0x18,0x00,0x1F,0xFC,0x1F,0xFC,0x18,0x08,0x18,0x00,0x10,0x00,  // T
  0x04,0x00,0x0F,0xF8,0x1F,0xFC,0x00,0x0C,0x00,0x04,0x00,0x04,0x0F,0xF8,0x1F,0xF0,  // U
  0x04,0x00,0x0F,0x80,0x1F,0xE0,0x00,0xF8,0x00,0x3C,0x00,0x30,0x0F,0xC0,0x1F,0x00,  // V
  0x04,0x00,0x0F,0xFC,0x1F,0xF8,0x00,0x30,0x00,0xE0,0x01,0xF0,0x08,0x3C,0x1F,0xF8,  // W
  0x0C,0x0C,0x1E,0x18,0x07,0x30,0x03,0xE0,0x03,0xE0,0x06,0x70,0x0C,0x3C,0x18,0x18,  // X
  0x04,0x00,0x0E,0x00,0x1F,0x00,0x03,0x80,0x01,0xFC,0x01,0xF8,0x0F,0x00,0x1E,0x00,  // Y
  0x04,0x0C,0x08,0x1C,0x18,0xAC,0x18,0xCC,0x19,0x8C,0x1A,0x8C,0x1C,0x08,0x18,0x10,  // Z
  0x00,0x00,0x00,0x00,0x00,0x00,0x1F,0xFE,0x3F,0xFE,0x30,0x06,0x30,0x06,0x20,0x04,  // [
  0x18,0x00,0x3E,0x00,0x0F,0x80,0x03,0xE0,0x00,0xF8,0x00,0x3E,0x00,0x0C,0x00,0x00,  // backslash
  0x00,0x00,0x10,0x02,0x30,0x06,0x30,0x06,0x3F,0xFE,0x3F,0xFC,0x00,0x00,0x00,0x00,  // ]
  0x00,0x00,0x0C,0x00,0x18,0x00,0x30,0x00,0x70,0x00,0x38,0x00,0x1C,0x00,0x08,0x00,  // ^
  0x00,0x00,0x00,0x01,0x00,0x01,0x00,0x01,0x00,0x01,0x00,0x01,0x00,0x01,0x00,0x01,  // _
  0x00,0x00,0x00,0x00,0x00,0x00,0x30,0x00,0x78,0x00,0x24,0x00,0x00,0x00,0x00,0x00,  // `
  0x00,0xF8,0x01,0xFC,0x02,0x0C,0x06,0x08,0x06,0x10,0x07,0xF8,0x07,0xFC,0x00,0x08,  // a
  0x20,0x00,0x7F,0xFC,0xFF,0xFC,0x01,0x0C,0x02,0x0C,0x06,0x08,0x07,0xF0,0x03,0xE0,  // b
  0x00,0xF8,0x01,0xFC,0x02,0x0C,0x06,0x04,0x06,0x04,0x06,0x04,0x04,0x08,0x00,0x10,  // c
  0x00,0xF8,0x01,0xFC,0x02,0x0C,0x06,0x08,0x46,0x10,0xFF,0xF8,0xFF,0xFC,0x00,0x08,  // d
  0x00,0xF8,0x01,0xFC,0x02,0x4C,0x04,0x44,0x06,0x44,0x07,0x84,0x03,0x08,0x00,0x10,  // e
  0x00,0x00,0x01,0x00,0x03,0x00,0x1F,0xFF,0x3F,0xFF,0x43,0x00,0xC2,0x00,0x80,0x00,  // f
  0x00,0xF8,0x01,0xFC,0x02,0x0C,0x06,0x08,0x06,0x10,0x07,0xFF,0x07,0xFF,0x00,0x00,  // g
  0x20,0x00,0x7F,0xFC,0xFF,0xF8,0x01,0x00,0x02,0x00,0x07,0xF8,0x07,0xFC,0x00,0x08,  // h
  0x00,0x00,0x01,0x00,0x02,0x00,0x67,0xF8,0x47,0xFC,0x00,0x08,0x00,0x10,0x00,0x20,  // i
  0x00,0x00,0x00,0x00,0x01,0x00,0x02,0x00,0x67,0xFF,0x47,0xFF,0x00,0x00,0x00,0x00,  // j
  0x20,0x00,0x7F,0xFC,0xFF,0xF8,0x02,0x60,0x04,0x70,0x07,0xB8,0x07,0x1C,0x00,0x08,  // k
  0x00,0x00,0x10,0x00,0x20,0x00,0x7F,0xF8,0xFF,0xFC,0x00,0x08,0x00,0x10,0x00,0x20,  // l
  0x02,0x00,0x07,0xFC,0x07,0xF8,0x02,0x00,0x07,0xF8,0x02,0x00,0x07,0xFC,0x07,0xF8,  // m
  0x02,0x00,0x07,0xFC,0x07,0xF8,0x01,0x00,0x02,0x00,0x07,0xF8,0x07,0xFC,0x00,0x08,  // n
  0x00,0xF8,0x01,0xFC,0x02,0x0C,0x06,0x0C,0x06,0x08,0x07,0xF0,0x03,0xE0,0x00,0x00,  // o
  0x02,0x00,0x07,0xFF,0x07,0xFF,0x01,0x0C,0x02,0x0C,0x06,0x08,0x07,0xF0,0x03,0xE0,  // p
  0x00,0xF8,0x01,0xFC,0x02,0x0C,0x06,0x08,0x06,0x10,0x07,0xFF,0x07,0xFF,0x00,0x00,  // q
  0x01,0x00,0x02,0x00,0x07,0xFC,0x03,0xF8,0x01,0x00,0x02,0x00,0x06,0x00,0x04,0x00,  // r
  0x00,0x00,0x01,0x04,0x03,0x8C,0x05,0xC4,0x04,0xEC,0x06,0x78,0x04,0x30,0x00,0x00,  // s
  0x02,0x00,0x06,0x00,0x1F,0xF8,0x3F,0xFC,0x06,0x0C,0x06,0x04,0x04,0x08,0x00,0x00,  // t
  0x02,0x00,0x07,0xF8,0x07,0xFC,0x00,0x08,0x00,0x10,0x03,0xF8,0x07,0xFC,0x00,0x08,  // u
  0x02,0x00,0x07,0xF0,0x07,0xF8,0x00,0x1C,0x00,0x08,0x00,0x10,0x03,0xE0,0x07,0xC0,  // v
  0x02,0x00,0x07,0xFC,0x07,0xF8,0x00,0x10,0x00,0x78,0x00,0xFC,0x02,0x18,0x07,0xF0,  // w
  0x02,0x04,0x06,0x0C,0x03,0x18,0x01,0xF0,0x01,0xF0,0x03,0x18,0x06,0x0C,0x04,0x08,  // x
  0x02,0x00,0x07,0xE0,0x07,0xF0,0x00,0x18,0x00,0x08,0x00,0x10,0x03,0xFF,0x07,0xFF,  // y
  0x00,0x00,0x03,0x0C,0x06,0x5C,0x06,0x6C,0x06,0xCC,0x07,0x4C,0x04,0x08,0x00,0x10,  // z
  0x00,0x00,0x00,0x00,0x00,0x80,0x01,0xC0,0x1F,0xFC,0x3E,0x7E,0x30,0x06,0x20,0x04,  // {
  0x00,0x00,0x00,0x00,0x00,0x00,0x1F,0xBF,0x3F,0x7E,0x00,0x00,0x00,0x00,0x00,0x00,  // |
  0x00,0x00,0x10,0x02,0x30,0x06,0x3F,0x3E,0x1F,0xFC,0x01,0xC0,0x00,0x80,0x00,0x00,  // }
  0x00,0x00,0x04,0x00,0x08,0x00,0x18,0x00,0x1C,0x00,0x0C,0x00,0x08,0x00,0x10,0x00,  // ~
};

const PROGMEM uint8_t digit8x16a[] = {
  48,0,14,17,2,
  0x08,0x3f,0xf0,0x7f,0xf8,0xff,0xfc,0x81,0xc4,0x87,0x04,0xff,0xfc,0x7f,0xf8,0x3f,0xf0,  // 0
  0x08,0x00,0x00,0x08,0x04,0x18,0x04,0x3f,0xfc,0x7f,0xfc,0xff,0xfc,0x00,0x04,0x00,0x04,  // 1
  0x08,0x30,0x3c,0x70,0x7c,0xf0,0xfc,0xc1,0xe4,0xc3,0xc4,0xff,0x8c,0x7f,0x0c,0x3e,0x0c,  // 2
  0x08,0x20,0x10,0x60,0x18,0xe2,0x1c,0x82,0x04,0x87,0x04,0xff,0xfc,0x7d,0xf8,0x38,0xf0,  // 3
  0x08,0x00,0x60,0x01,0xe0,0x07,0xe0,0x1e,0x20,0x7f,0xfc,0xff,0xfc,0xff,0xfc,0x00,0x20,  // 4
  0x08,0xfc,0x10,0xfc,0x18,0xfc,0x1c,0x88,0x04,0x88,0x04,0xcf,0xfc,0xc7,0xf8,0xc3,0xf0,  // 5
  0x08,0x7f,0xf0,0xff,0xf8,0xff,0xfc,0x88,0x04,0x88,0x04,0xcf,0xfc,0xc7,0xf8,0x43,0xf0,  // 6
  0x08,0xe0,0x00,0xe0,0x00,0xe0,0x7c,0x81,0xfc,0x87,0xfc,0xff,0x80,0xfe,0x00,0xf8,0x00,  // 7
  0x08,0x31,0xf0,0x7b,0xf8,0xff,0xfc,0x84,0x04,0x84,0x04,0xff,0xfc,0x7b,0xf8,0x31,0xf0,  // 8
  0x08,0x3f,0x08,0x7f,0x8c,0xff,0xcc,0x80,0x44,0x80,0x44,0xff,0xfc,0x7f,0xf8,0x3f,0xf0,  // 9
  0x03,0x18,0x60,0x3c,0xf0,0x18,0x60,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,  // :
};

const PROGMEM uint8_t digit8x8a[] = {
  48,0,8,8,1,
  0x07,0x7C,0xFE,0x9A,0xB2,0xE2,0xFE,0x7C,  // 0
  0x07,0x00,0x02,0x42,0xFE,0xFE,0x02,0x02,  // 1
  0x07,0x4E,0xDE,0x92,0x92,0x92,0xF2,0x62,  // 2
  0x07,0x82,0x82,0x92,0x92,0x92,0xFE,0x6C,  // 3
  0x07,0x78,0x78,0x08,0x08,0xFE,0xFE,0x08,  // 4
  0x07,0xE4,0xE6,0xA2,0xA2,0xA2,0xBE,0x9C,  // 5
  0x07,0x7C,0xFE,0x92,0x92,0x92,0x9E,0x0C,  // 6
  0x07,0x80,0x80,0x86,0x8E,0x98,0xF0,0xE0,  // 7
  0x07,0x6C,0xFE,0x92,0x92,0x92,0xFE,0x6C,  // 8
  0x07,0x60,0xF2,0x92,0x92,0x92,0xFE,0x7C,  // 9
  0x02,0x66,0x66,0x00,0x00,0x00,0x00,0x00,  // :
};

const uint8_t* xfont[MAX_FONT] = { font4x6,font5x8,font8x8,decor9x16,digit8x8a,digit8x16a };