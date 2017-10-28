#pragma once

// Stubbed out for test
enum KeyboardKeycode: uint8_t {
    KKC1 = 1,
    KKC2 = 2,
    KKC3 = 3,
    KKC4 = 4,
    KKC5 = 5,
    KKC6 = 6,
    KKC7 = 7,
    KKC8 = 8,
    KKC9 = 9,
    KEY_RESERVED = 0,
    KEY_LEFT_CTRL = 128,
    KEY_RIGHT_GUI = 128+7,
};

enum ConsumerKeycode : uint16_t {
    HID_CONSUMER_UNASSIGNED = 0
};

typedef union {
    // Low level key report: up to 6 keys and shift, ctrl etc at once
    uint8_t whole8[8];
    uint16_t whole16[4];
    uint32_t whole32[2];
    struct {
        uint8_t modifiers;
        uint8_t reserved;
        KeyboardKeycode keycodes[6];
    };
    uint8_t keys[8];
} HID_KeyboardReport_Data_t;

class DefaultKeyboardAPI
{
public:
    DefaultKeyboardAPI();

    size_t DefaultKeyboardAPI::set(KeyboardKeycode k, bool s);

    inline size_t write(ConsumerKeycode k);
    inline size_t press(ConsumerKeycode k);
    inline size_t release(ConsumerKeycode k);
    inline size_t add(ConsumerKeycode k);
    inline size_t remove(ConsumerKeycode k);
    size_t removeAll(void);

    HID_KeyboardReport_Data_t _keyReport;

    int send(void) {}
    void setWriteError(void) {}
};
