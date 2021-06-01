/*
 * Copyright © 2015 Red Hat, Inc.
 *
 * Permission is hereby granted, free of charge, to any person obtaining a
 * copy of this software and associated documentation files (the "Software"),
 * to deal in the Software without restriction, including without limitation
 * the rights to use, copy, modify, merge, publish, distribute, sublicense,
 * and/or sell copies of the Software, and to permit persons to whom the
 * Software is furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice (including the next
 * paragraph) shall be included in all copies or substantial portions of the
 * Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.  IN NO EVENT SHALL
 * THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
 * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
 * DEALINGS IN THE SOFTWARE.
 */

#include "config.h"

#include "litest.h"
#include "litest-int.h"

static struct input_id input_id = {
	.bustype = 0x3,
	.vendor = 0x5ac,
	.product = 0x273,
};

static int events[] = {
	EV_KEY, KEY_ESC,
	EV_KEY, KEY_1,
	EV_KEY, KEY_2,
	EV_KEY, KEY_3,
	EV_KEY, KEY_4,
	EV_KEY, KEY_5,
	EV_KEY, KEY_6,
	EV_KEY, KEY_7,
	EV_KEY, KEY_8,
	EV_KEY, KEY_9,
	EV_KEY, KEY_0,
	EV_KEY, KEY_MINUS,
	EV_KEY, KEY_EQUAL,
	EV_KEY, KEY_BACKSPACE,
	EV_KEY, KEY_TAB,
	EV_KEY, KEY_Q,
	EV_KEY, KEY_W,
	EV_KEY, KEY_E,
	EV_KEY, KEY_R,
	EV_KEY, KEY_T,
	EV_KEY, KEY_Y,
	EV_KEY, KEY_U,
	EV_KEY, KEY_I,
	EV_KEY, KEY_O,
	EV_KEY, KEY_P,
	EV_KEY, KEY_LEFTBRACE,
	EV_KEY, KEY_RIGHTBRACE,
	EV_KEY, KEY_ENTER,
	EV_KEY, KEY_LEFTCTRL,
	EV_KEY, KEY_A,
	EV_KEY, KEY_S,
	EV_KEY, KEY_D,
	EV_KEY, KEY_F,
	EV_KEY, KEY_G,
	EV_KEY, KEY_H,
	EV_KEY, KEY_J,
	EV_KEY, KEY_K,
	EV_KEY, KEY_L,
	EV_KEY, KEY_SEMICOLON,
	EV_KEY, KEY_APOSTROPHE,
	EV_KEY, KEY_GRAVE,
	EV_KEY, KEY_LEFTSHIFT,
	EV_KEY, KEY_BACKSLASH,
	EV_KEY, KEY_Z,
	EV_KEY, KEY_X,
	EV_KEY, KEY_C,
	EV_KEY, KEY_V,
	EV_KEY, KEY_B,
	EV_KEY, KEY_N,
	EV_KEY, KEY_M,
	EV_KEY, KEY_COMMA,
	EV_KEY, KEY_DOT,
	EV_KEY, KEY_SLASH,
	EV_KEY, KEY_RIGHTSHIFT,
	EV_KEY, KEY_KPASTERISK,
	EV_KEY, KEY_LEFTALT,
	EV_KEY, KEY_SPACE,
	EV_KEY, KEY_CAPSLOCK,
	EV_KEY, KEY_F1,
	EV_KEY, KEY_F2,
	EV_KEY, KEY_F3,
	EV_KEY, KEY_F4,
	EV_KEY, KEY_F5,
	EV_KEY, KEY_F6,
	EV_KEY, KEY_F7,
	EV_KEY, KEY_F8,
	EV_KEY, KEY_F9,
	EV_KEY, KEY_F10,
	EV_KEY, KEY_NUMLOCK,
	EV_KEY, KEY_SCROLLLOCK,
	EV_KEY, KEY_KP7,
	EV_KEY, KEY_KP8,
	EV_KEY, KEY_KP9,
	EV_KEY, KEY_KPMINUS,
	EV_KEY, KEY_KP4,
	EV_KEY, KEY_KP5,
	EV_KEY, KEY_KP6,
	EV_KEY, KEY_KPPLUS,
	EV_KEY, KEY_KP1,
	EV_KEY, KEY_KP2,
	EV_KEY, KEY_KP3,
	EV_KEY, KEY_KP0,
	EV_KEY, KEY_KPDOT,
	EV_KEY, KEY_ZENKAKUHANKAKU,
	EV_KEY, KEY_102ND,
	EV_KEY, KEY_F11,
	EV_KEY, KEY_F12,
	EV_KEY, KEY_RO,
	EV_KEY, KEY_KATAKANA,
	EV_KEY, KEY_HIRAGANA,
	EV_KEY, KEY_HENKAN,
	EV_KEY, KEY_KATAKANAHIRAGANA,
	EV_KEY, KEY_MUHENKAN,
	EV_KEY, KEY_KPJPCOMMA,
	EV_KEY, KEY_KPENTER,
	EV_KEY, KEY_RIGHTCTRL,
	EV_KEY, KEY_KPSLASH,
	EV_KEY, KEY_SYSRQ,
	EV_KEY, KEY_RIGHTALT,
	EV_KEY, KEY_HOME,
	EV_KEY, KEY_UP,
	EV_KEY, KEY_PAGEUP,
	EV_KEY, KEY_LEFT,
	EV_KEY, KEY_RIGHT,
	EV_KEY, KEY_END,
	EV_KEY, KEY_DOWN,
	EV_KEY, KEY_PAGEDOWN,
	EV_KEY, KEY_INSERT,
	EV_KEY, KEY_DELETE,
	EV_KEY, KEY_MUTE,
	EV_KEY, KEY_VOLUMEDOWN,
	EV_KEY, KEY_VOLUMEUP,
	EV_KEY, KEY_POWER,
	EV_KEY, KEY_KPEQUAL,
	EV_KEY, KEY_PAUSE,
	EV_KEY, KEY_SCALE,
	EV_KEY, KEY_KPCOMMA,
	EV_KEY, KEY_HANGEUL,
	EV_KEY, KEY_HANJA,
	EV_KEY, KEY_YEN,
	EV_KEY, KEY_LEFTMETA,
	EV_KEY, KEY_RIGHTMETA,
	EV_KEY, KEY_COMPOSE,
	EV_KEY, KEY_STOP,
	EV_KEY, KEY_AGAIN,
	EV_KEY, KEY_PROPS,
	EV_KEY, KEY_UNDO,
	EV_KEY, KEY_FRONT,
	EV_KEY, KEY_COPY,
	EV_KEY, KEY_OPEN,
	EV_KEY, KEY_PASTE,
	EV_KEY, KEY_FIND,
	EV_KEY, KEY_CUT,
	EV_KEY, KEY_HELP,
	EV_KEY, KEY_CALC,
	EV_KEY, KEY_SLEEP,
	EV_KEY, KEY_WWW,
	EV_KEY, KEY_COFFEE,
	EV_KEY, KEY_BACK,
	EV_KEY, KEY_FORWARD,
	EV_KEY, KEY_EJECTCD,
	EV_KEY, KEY_NEXTSONG,
	EV_KEY, KEY_PLAYPAUSE,
	EV_KEY, KEY_PREVIOUSSONG,
	EV_KEY, KEY_STOPCD,
	EV_KEY, KEY_REWIND,
	EV_KEY, KEY_REFRESH,
	EV_KEY, KEY_EDIT,
	EV_KEY, KEY_SCROLLUP,
	EV_KEY, KEY_SCROLLDOWN,
	EV_KEY, KEY_KPLEFTPAREN,
	EV_KEY, KEY_KPRIGHTPAREN,
	EV_KEY, KEY_F13,
	EV_KEY, KEY_F14,
	EV_KEY, KEY_F15,
	EV_KEY, KEY_F16,
	EV_KEY, KEY_F17,
	EV_KEY, KEY_F18,
	EV_KEY, KEY_F19,
	EV_KEY, KEY_F20,
	EV_KEY, KEY_F21,
	EV_KEY, KEY_F22,
	EV_KEY, KEY_F23,
	EV_KEY, KEY_F24,
	EV_KEY, KEY_DASHBOARD,
	EV_KEY, KEY_FASTFORWARD,
	EV_KEY, KEY_BRIGHTNESSDOWN,
	EV_KEY, KEY_BRIGHTNESSUP,
	EV_KEY, KEY_SWITCHVIDEOMODE,
	EV_KEY, KEY_KBDILLUMTOGGLE,
	EV_KEY, KEY_KBDILLUMDOWN,
	EV_KEY, KEY_KBDILLUMUP,
	EV_KEY, KEY_UNKNOWN,
	EV_KEY, KEY_FN,
	EV_MSC, MSC_SCAN,

	EV_LED, LED_NUML,
	EV_LED, LED_CAPSL,
	EV_LED, LED_SCROLLL,
	EV_LED, LED_COMPOSE,
	EV_LED, LED_KANA,
	-1, -1
};

TEST_DEVICE("apple-keyboard",
	.type = LITEST_APPLE_KEYBOARD,
	.features = LITEST_KEYS,
	.interface = NULL,

	.name = "Apple Inc. Apple Internal Keyboard / Trackpad",
	.id = &input_id,
	.events = events,
	.absinfo = NULL,
)
