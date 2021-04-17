/*
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.	See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston,
 * MA 02110-1301, USA.
 *
 */

#include "rgb_keyboard.h"

// keycodes for custom led patterns (ANSI layout)
const std::map<std::string, std::array<uint8_t, 3>> rgb_keyboard::keyboard::keycodes_ansi = {
	{"Esc", {0x57, 0x03, 0x00}},
	{"F1", {0x5a, 0x06, 0x00}},
	{"F2", {0x5d, 0x09, 0x00}},
	{"F3", {0x60, 0x0c, 0x00}},
	{"F4", {0x63, 0x0f, 0x00}},
	{"F5", {0x66, 0x12, 0x00}},
	{"F6", {0x69, 0x15, 0x00}},
	{"F7", {0x6c, 0x18, 0x00}},
	{"F8", {0x6f, 0x1b, 0x00}},
	{"F9", {0x72, 0x1e, 0x00}},
	{"F10", {0x75, 0x21, 0x00}},
	{"F11", {0x78, 0x24, 0x00}},
	{"F12", {0x7b, 0x27, 0x00}},
	{"PrtSc", {0x93, 0x3e, 0x01}},
	{"ScrLk", {0x96, 0x41, 0x01}},
	{"Pause", {0x99, 0x44, 0x01}},
	{"Tilde", {0x8a, 0x36, 0x00}},
	{"1", {0x8d, 0x39, 0x00}},
	{"2", {0x90, 0x3c, 0x00}},
	{"3", {0x93, 0x3f, 0x00}},
	{"4", {0x96, 0x42, 0x00}},
	{"5", {0x99, 0x45, 0x00}},
	{"6", {0x9c, 0x48, 0x00}},
	{"7", {0x9f, 0x4b, 0x00}},
	{"8", {0xa2, 0x4e, 0x00}},
	{"9", {0xa5, 0x51, 0x00}},
	{"0", {0xa8, 0x54, 0x00}},
	{"Minus", {0xab, 0x57, 0x00}},
	{"Equals", {0xae, 0x5a, 0x00}},
	{"Backspace", {0x7b, 0x26, 0x01}},
	{"Insert", {0x9f, 0x4a, 0x01}},
	{"Home", {0xa2, 0x4d, 0x01}},
	{"PgUp", {0xa5, 0x50, 0x01}},
	{"Delete", {0xa8, 0x53, 0x01}},
	{"End", {0xab, 0x56, 0x01}},
	{"PgDn", {0xae, 0x59, 0x01}},
	{"Tab", {0xbd, 0x69, 0x00}},
	{"q", {0xc0, 0x6c, 0x00}},
	{"w", {0xc3, 0x6f, 0x00}},
	{"e", {0xc6, 0x72, 0x00}},
	{"r", {0xc9, 0x75, 0x00}},
	{"t", {0xcc, 0x78, 0x00}},
	{"y", {0xcf, 0x7b, 0x00}},
	{"u", {0xd2, 0x7e, 0x00}},
	{"i", {0xd5, 0x81, 0x00}},
	{"o", {0xd8, 0x84, 0x00}},
	{"p", {0xdb, 0x87, 0x00}},
	{"Bracket_l", {0xde, 0x8a, 0x00}},
	{"Bracket_r", {0xe1, 0x8d, 0x00}},
	{"Backslash", {0x14, 0xc0, 0x00}},
	{"Up", {0x75, 0x20, 0x01}},
	{"Left", {0x6f, 0x1a, 0x01}},
	{"Down", {0x72, 0x1d, 0x01}},
	{"Right", {0x78, 0x23, 0x01}},
	{"Caps_Lock", {0xf0, 0x9c, 0x00}},
	{"a", {0xf3, 0x9f, 0x00}},
	{"s", {0xf6, 0xa2, 0x00}},
	{"d", {0xf9, 0xa5, 0x00}},
	{"f", {0xfc, 0xa8, 0x00}},
	{"g", {0xff, 0xab, 0x00}},
	{"h", {0x02, 0xae, 0x00}},
	{"j", {0x05, 0xb1, 0x00}},
	{"k", {0x08, 0xb4, 0x00}},
	{"l", {0x0b, 0xb7, 0x00}},
	{"Semicolon", {0x0e, 0xba, 0x00}},
	{"Apostrophe", {0x11, 0xbd, 0x00}},
	{"Return", {0x47, 0xf3, 0x00}},
	{"Shift_l", {0x23, 0xcf, 0x00}},
	{"z", {0x26, 0xd2, 0x00}},
	{"x", {0x29, 0xd5, 0x00}},
	{"c", {0x2c, 0xd8, 0x00}},
	{"v", {0x2f, 0xdb, 0x00}},
	{"b", {0x32, 0xde, 0x00}},
	{"n", {0x35, 0xe1, 0x00}},
	{"m", {0x38, 0xe4, 0x00}},
	{"Comma", {0x3b, 0xe7, 0x00}},
	{"Period", {0x3e, 0xea, 0x00}},
	{"Slash", {0x41, 0xed, 0x00}},
	{"Shift_r", {0x44, 0xf0, 0x00}},
	{"Ctrl_l", {0x57, 0x02, 0x01}},
	{"Super_l", {0x5a, 0x05, 0x01}},
	{"Alt_l", {0x5d, 0x08, 0x01}},
	{"Space", {0x60, 0x0b, 0x01}},
	{"Alt_r", {0x63, 0x0e, 0x01}},
	{"Fn", {0x66, 0x11, 0x01}},
	{"Menu", {0x69, 0x14, 0x01}},
	{"Ctrl_r", {0x6c, 0x17, 0x01}},
	{"Num_Lock", {0xb1, 0x5d, 0x00}},
	{"Num_Slash", {0xb4, 0x60, 0x00}},
	{"Num_Asterisk", {0xb7, 0x63, 0x00}},
	{"Num_Minus", {0xb1, 0x5c, 0x01}},
	{"Num_7", {0xe4, 0x90, 0x00}},
	{"Num_8", {0xe7, 0x93, 0x00}},
	{"Num_9", {0xea, 0x96, 0x00}},
	{"Num_Plus", {0xb4, 0x5f, 0x01}},
	{"Num_4", {0x17, 0xc3, 0x00}},
	{"Num_5", {0x1a, 0xc6, 0x00}},
	{"Num_6", {0x1d, 0xc9, 0x00}},
	{"Num_1", {0x4a, 0xf6, 0x00}},
	{"Num_2", {0x4d, 0xf9, 0x00}},
	{"Num_3", {0x50, 0xfc, 0x00}},
	{"Num_0", {0x7e, 0x29, 0x01}},
	{"Num_Period", {0x81, 0x2c, 0x01}},
	{"Num_Return", {0x84, 0x2f, 0x01}},
	{"Int_Key", {0x4f, 0x3b, 0x01}}
};

// keycodes for custom led patterns (brazilian layout)
const std::map<std::string, std::array<uint8_t, 3>> rgb_keyboard::keyboard::keycodes_brazil = {
	{"0", { 0xb1, 0x5d, 0x00 }},
	{"1", { 0x96, 0x42, 0x00 }},
	{"2", { 0x99, 0x45, 0x00 }},
	{"3", { 0x9c, 0x48, 0x00 }},
	{"4", { 0x9f, 0x4b, 0x00 }},
	{"5", { 0xa2, 0x4e, 0x00 }},
	{"6", { 0xa5, 0x51, 0x00 }},
	{"7", { 0xa8, 0x54, 0x00 }},
	{"8", { 0xab, 0x57, 0x00 }},
	{"9", { 0xae, 0x5a, 0x00 }},
	{"Acute", { 0xf3, 0x9f, 0x00 }},
	{"Alt_l", { 0x96, 0x41, 0x01 }},
	{"Alt_r", { 0x9c, 0x47, 0x01 }},
	{"Apostrophe", { 0x93, 0x3f, 0x00 }},
	{"Backspace", { 0xba, 0x66, 0x00 }},
	{"Bracket_l", { 0xf6, 0xa2, 0x00 }},
	{"Bracket_r", { 0x35, 0xe1, 0x00 }},
	{"Caps_Lock", { 0x11, 0xbd, 0x00 }},
	{"Cc", { 0x2f, 0xdb, 0x00 }},
	{"Comma", { 0x6c, 0x17, 0x01 }},
	{"Ctrl_l", { 0x4f, 0x3b, 0x01 }},
	{"Ctrl_r", { 0xa8, 0x53, 0x01 }},
	{"Delete", { 0xfc, 0xa8, 0x00 }},
	{"End", { 0xff, 0xab, 0x00 }},
	{"Equals", { 0xb7, 0x63, 0x00 }},
	{"Esc", { 0x54, 0x00, 0x00 }},
	{"F1", { 0x57, 0x03, 0x00 }},
	{"F10", { 0x72, 0x1e, 0x00 }},
	{"F11", { 0x75, 0x21, 0x00 }},
	{"F12", { 0x78, 0x24, 0x00 }},
	{"F2", { 0x5a, 0x06, 0x00 }},
	{"F3", { 0x5d, 0x09, 0x00 }},
	{"F4", { 0x60, 0x0c, 0x00 }},
	{"F5", { 0x63, 0x0f, 0x00 }},
	{"F6", { 0x66, 0x12, 0x00 }},
	{"F7", { 0x69, 0x15, 0x00 }},
	{"F8", { 0x6c, 0x18, 0x00 }},
	{"F9", { 0x6f, 0x1b, 0x00 }},
	{"Fn", { 0x9f, 0x4a, 0x01 }},
	{"Home", { 0xc0, 0x6c, 0x00 }},
	{"Insert", { 0xbd, 0x69, 0x00 }},
	{"Menu", { 0xa2, 0x4d, 0x01 }},
	{"Minus", { 0xb4, 0x60, 0x00 }},
	{"Pause", { 0x84, 0x30, 0x00 }},
	{"Period", { 0x6f, 0x1a, 0x01 }},
	{"PgDn", { 0x02, 0xae, 0x00 }},
	{"PgUp", { 0xc3, 0x6f, 0x00 }},
	{"PrtSc", { 0x7e, 0x2a, 0x00 }},
	{"Return", { 0x38, 0xe4, 0x00 }},
	{"ScrLk", { 0x81, 0x2d, 0x00 }},
	{"Semicolon", { 0x72, 0x1d, 0x01 }},
	{"Shift_l", { 0x50, 0xfc, 0x00 }},
	{"Backslash", { 0x53   , 0xff, 0x00 }},
	{"Shift_r", { 0x78, 0x23, 0x01 }},
	{"Slash", { 0x75, 0x20, 0x01 }},
	{"Space", { 0x99, 0x44, 0x01 }},
	{"Super_l", { 0x93, 0x3e, 0x01 }},
	{"Tab", { 0xd2, 0x7e, 0x00 }},
	{"Tilde", { 0x32, 0xde, 0x00 }},
	{"Up", { 0x7e, 0x29, 0x01 }},
	{"Left", { 0xba, 0x65, 0x01 }},
	{"Down", { 0xbd, 0x68, 0x01 }},
	{"Right", { 0xc0, 0x6b, 0x01 }},
	{"a", { 0x14, 0xc0, 0x00 }},
	{"b", { 0x63, 0x0e, 0x01 }},
	{"c", { 0x5d, 0x08, 0x01 }},
	{"d", { 0x1a, 0xc6, 0x00 }},
	{"e", { 0xdb, 0x87, 0x00 }},
	{"f", { 0x1d, 0xc9, 0x00 }},
	{"g", { 0x20, 0xcc, 0x00 }},
	{"h", { 0x23, 0xcf, 0x00 }},
	{"i", { 0xea, 0x96, 0x00 }},
	{"j", { 0x26, 0xd2, 0x00 }},
	{"k", { 0x29, 0xd5, 0x00 }},
	{"l", { 0x2c, 0xd8, 0x00 }},
	{"m", { 0x69, 0x14, 0x01 }},
	{"n", { 0x66, 0x11, 0x01 }},
	{"o", { 0xed, 0x99, 0x00 }},
	{"p", { 0xf0, 0x9c, 0x00 }},
	{"q", { 0xd5, 0x81, 0x00 }},
	{"r", { 0xde, 0x8a, 0x00 }},
	{"s", { 0x17, 0xc3, 0x00 }},
	{"t", { 0xe1, 0x8d, 0x00 }},
	{"u", { 0xe7, 0x93, 0x00 }},
	{"v", { 0x60, 0x0b, 0x01 }},
	{"w", { 0xd8, 0x84, 0x00 }},
	{"x", { 0x5a, 0x05, 0x01 }},
	{"y", { 0xe4, 0x90, 0x00 }},
	{"z", { 0x57, 0x02, 0x01 }}
};

// keycodes/data offsets for keymapping (ANSI layout)
std::map<std::string, std::array<std::array<uint8_t, 2>, 3>>
	rgb_keyboard::keyboard::_keymap_offsets = {
		{"Esc", {{{1, 11}, {1, 12}, {1, 13}}}},
		{"F1", {{{1, 14}, {1, 15}, {1, 16}}}},
		{"F2", {{{1, 17}, {1, 18}, {1, 19}}}},
		{"F3", {{{1, 20}, {1, 21}, {1, 22}}}},
		{"F4", {{{1, 23}, {1, 24}, {1, 25}}}},
		{"F5", {{{1, 26}, {1, 27}, {1, 28}}}},
		{"F6", {{{1, 29}, {1, 30}, {1, 31}}}},
		{"F7", {{{1, 32}, {1, 33}, {1, 34}}}},
		{"F8", {{{1, 35}, {1, 36}, {1, 37}}}},
		{"F9", {{{1, 38}, {1, 39}, {1, 40}}}},
		{"F10", {{{1, 41}, {1, 42}, {1, 43}}}},
		{"F11", {{{1, 44}, {1, 45}, {1, 46}}}},
		{"F12", {{{1, 47}, {1, 48}, {1, 49}}}},
		{"PrtSc", {{{6, 46}, {6, 47}, {6, 48}}}},
		{"ScrLk", {{{6, 49}, {6, 50}, {6, 51}}}},
		{"Pause", {{{6, 52}, {6, 53}, {6, 54}}}},
		{"Tilde", {{{1, 62}, {1, 63}, {2, 8}}}},
		{"1", {{{2, 9}, {2, 10}, {2, 11}}}},
		{"2", {{{2, 12}, {2, 13}, {2, 14}}}},
		{"3", {{{2, 15}, {2, 16}, {2, 17}}}},
		{"4", {{{2, 18}, {2, 19}, {2, 20}}}},
		{"5", {{{2, 21}, {2, 22}, {2, 23}}}},
		{"6", {{{2, 24}, {2, 25}, {2, 26}}}},
		{"7", {{{2, 27}, {2, 28}, {2, 29}}}},
		{"8", {{{2, 30}, {2, 31}, {2, 32}}}},
		{"9", {{{2, 33}, {2, 34}, {2, 35}}}},
		{"0", {{{2, 36}, {2, 37}, {2, 38}}}},
		{"Minus", {{{2, 39}, {2, 40}, {2, 41}}}},
		{"Equals", {{{2, 42}, {2, 43}, {2, 44}}}},
		{"Backspace", {{{6, 22}, {6, 23}, {6, 24}}}},
		{"Insert", {{{6, 58}, {6, 59}, {6, 60}}}},
		{"Home", {{{6, 61}, {6, 62}, {6, 63}}}},
		{"PgUp", {{{7, 8}, {7, 9}, {7, 10}}}},
		{"Delete", {{{7, 11}, {7, 12}, {7, 13}}}},
		{"End", {{{7, 14}, {7, 15}, {7, 16}}}},
		{"PgDn", {{{7, 17}, {7, 18}, {7, 19}}}},
		{"Tab", {{{2, 57}, {2, 58}, {2, 59}}}},
		{"q", {{{2, 60}, {2, 61}, {2, 62}}}},
		{"w", {{{3, 7}, {3, 8}, {3, 9}}}},
		{"e", {{{3, 10}, {3, 11}, {3, 12}}}},
		{"r", {{{3, 13}, {3, 14}, {3, 15}}}},
		{"t", {{{3, 16}, {3, 17}, {3, 18}}}},
		{"y", {{{3, 19}, {3, 20}, {3, 21}}}},
		{"u", {{{3, 22}, {3, 23}, {3, 24}}}},
		{"i", {{{3, 25}, {3, 26}, {3, 27}}}},
		{"o", {{{3, 28}, {3, 29}, {3, 30}}}},
		{"p", {{{3, 31}, {3, 32}, {3, 33}}}},
		{"Bracket_l", {{{3, 34}, {3, 35}, {3, 36}}}},
		{"Bracket_r", {{{3, 37}, {3, 38}, {1, 39}}}},
		{"Backslash", {{{4, 32}, {4, 33}, {4, 34}}}},
		{"Up", {{{6, 16}, {6, 17}, {6, 18}}}},
		{"Left", {{{6, 10}, {6, 11}, {6, 12}}}},
		{"Down", {{{6, 13}, {6, 14}, {6, 15}}}},
		{"Right", {{{6, 19}, {6, 20}, {6, 21}}}},
		{"Caps_Lock", {{{3, 52}, {3, 53}, {3, 54}}}},
		{"a", {{{3, 55}, {3, 56}, {3, 57}}}},
		{"s", {{{3, 58}, {3, 59}, {3, 60}}}},
		{"d", {{{3, 61}, {3, 62}, {3, 63}}}},
		{"f", {{{4, 8}, {4, 9}, {4, 10}}}},
		{"g", {{{4, 11}, {4, 12}, {4, 13}}}},
		{"h", {{{4, 14}, {4, 15}, {4, 16}}}},
		{"j", {{{4, 17}, {4, 18}, {4, 19}}}},
		{"k", {{{4, 20}, {4, 21}, {4, 22}}}},
		{"l", {{{4, 23}, {4, 24}, {4, 25}}}},
		{"Semicolon", {{{4, 26}, {4, 27}, {4, 28}}}},
		{"Apostrophe", {{{4, 29}, {4, 30}, {4, 31}}}},
		{"Return", {{{5, 27}, {5, 28}, {5, 29}}}},
		{"z", {{{4, 50}, {4, 51}, {4, 52}}}},
		{"x", {{{4, 53}, {4, 54}, {4, 55}}}},
		{"c", {{{4, 56}, {4, 57}, {4, 58}}}},
		{"v", {{{4, 59}, {4, 60}, {4, 61}}}},
		{"b", {{{4, 62}, {4, 63}, {5, 8}}}},
		{"n", {{{5, 9}, {5, 10}, {5, 11}}}},
		{"m", {{{5, 12}, {5, 13}, {5, 14}}}},
		{"Comma", {{{5, 15}, {5, 16}, {5, 17}}}},
		{"Period", {{{5, 18}, {5, 19}, {5, 20}}}},
		{"Slash", {{{5, 21}, {5, 22}, {5, 23}}}},
		{"Shift_l", {{{4, 47}, {4, 48}, {4, 49}}}},
		{"Shift_r", {{{5, 24}, {5, 25}, {5, 26}}}},
		{"Ctrl_l", {{{5, 42}, {5, 43}, {5, 44}}}},
		{"Super_l", {{{5, 45}, {5, 46}, {5, 47}}}},
		{"Alt_l", {{{5, 48}, {5, 49}, {5, 50}}}},
		{"Space", {{{5, 51}, {5, 52}, {5, 53}}}},
		{"Alt_r", {{{5, 54}, {5, 55}, {5, 56}}}},
		{"Fn", {{{5, 57}, {5, 58}, {5, 59}}}},
		{"Menu", {{{5, 60}, {5, 61}, {5, 62}}}},
		{"Ctrl_r", {{{5, 63}, {6, 8}, {6, 9}}}},
		{"Num_Lock", {{{2, 45}, {2, 46}, {2, 47}}}},
		{"Num_Slash", {{{2, 48}, {2, 49}, {2, 50}}}},
		{"Num_Asterisk", {{{2, 51}, {2, 52}, {2, 53}}}},
		{"Num_Minus", {{{7, 20}, {7, 21}, {7, 22}}}},
		{"Num_Plus", {{{7, 23}, {7, 24}, {7, 25}}}},
		{"Num_1", {{{5, 30}, {5, 31}, {5, 32}}}},
		{"Num_2", {{{5, 33}, {5, 34}, {5, 35}}}},
		{"Num_3", {{{5, 36}, {5, 37}, {5, 38}}}},
		{"Num_4", {{{4, 35}, {4, 36}, {4, 37}}}},
		{"Num_5", {{{4, 38}, {4, 39}, {4, 40}}}},
		{"Num_6", {{{4, 41}, {4, 42}, {4, 43}}}},
		{"Num_7", {{{3, 40}, {3, 41}, {3, 42}}}},
		{"Num_8", {{{3, 43}, {3, 44}, {3, 45}}}},
		{"Num_9", {{{3, 46}, {3, 47}, {3, 48}}}},
		{"Num_0", {{{6, 25}, {6, 26}, {6, 27}}}},
		{"Num_Period", {{{6, 28}, {6, 29}, {6, 30}}}},
		{"Num_Return", {{{6, 31}, {6, 32}, {6, 33}}}},
		{"Int_Key", {{{7, 44}, {7, 45}, {7, 46}}}}};

// keycodes/data offsets for keymapping (ISO layout)
std::map<std::string, std::array<std::array<uint8_t, 2>, 3>>
	rgb_keyboard::keyboard::_keymap_offsets_iso = {
		{"Esc", {{{1, 11}, {1, 12}, {1, 13}}}},
		{"F1", {{{1, 14}, {1, 15}, {1, 16}}}},
		{"F2", {{{1, 17}, {1, 18}, {1, 19}}}},
		{"F3", {{{1, 20}, {1, 21}, {1, 22}}}},
		{"F4", {{{1, 23}, {1, 24}, {1, 25}}}},
		{"F5", {{{1, 26}, {1, 27}, {1, 28}}}},
		{"F6", {{{1, 29}, {1, 30}, {1, 31}}}},
		{"F7", {{{1, 32}, {1, 33}, {1, 34}}}},
		{"F8", {{{1, 35}, {1, 36}, {1, 37}}}},
		{"F9", {{{1, 38}, {1, 39}, {1, 40}}}},
		{"F10", {{{1, 41}, {1, 42}, {1, 43}}}},
		{"F11", {{{1, 44}, {1, 45}, {1, 46}}}},
		{"F12", {{{1, 47}, {1, 48}, {1, 49}}}},
		{"PrtSc", {{{6, 46}, {6, 47}, {6, 48}}}},
		{"ScrLk", {{{6, 49}, {6, 50}, {6, 51}}}},
		{"Pause", {{{6, 52}, {6, 53}, {6, 54}}}},
		{"Tilde", {{{1, 62}, {1, 63}, {2, 8}}}},
		{"1", {{{2, 9}, {2, 10}, {2, 11}}}},
		{"2", {{{2, 12}, {2, 13}, {2, 14}}}},
		{"3", {{{2, 15}, {2, 16}, {2, 17}}}},
		{"4", {{{2, 18}, {2, 19}, {2, 20}}}},
		{"5", {{{2, 21}, {2, 22}, {2, 23}}}},
		{"6", {{{2, 24}, {2, 25}, {2, 26}}}},
		{"7", {{{2, 27}, {2, 28}, {2, 29}}}},
		{"8", {{{2, 30}, {2, 31}, {2, 32}}}},
		{"9", {{{2, 33}, {2, 34}, {2, 35}}}},
		{"0", {{{2, 36}, {2, 37}, {2, 38}}}},
		{"Minus", {{{2, 39}, {2, 40}, {2, 41}}}},
		{"Equals", {{{2, 42}, {2, 43}, {2, 44}}}},
		{"Backspace", {{{6, 22}, {6, 23}, {6, 24}}}},
		{"Insert", {{{6, 58}, {6, 59}, {6, 60}}}},
		{"Home", {{{6, 61}, {6, 62}, {6, 63}}}},
		{"PgUp", {{{7, 8}, {7, 9}, {7, 10}}}},
		{"Delete", {{{7, 11}, {7, 12}, {7, 13}}}},
		{"End", {{{7, 14}, {7, 15}, {7, 16}}}},
		{"PgDn", {{{7, 17}, {7, 18}, {7, 19}}}},
		{"Tab", {{{2, 57}, {2, 58}, {2, 59}}}},
		{"q", {{{2, 60}, {2, 61}, {2, 62}}}},
		{"w", {{{3, 7}, {3, 8}, {3, 9}}}},
		{"e", {{{3, 10}, {3, 11}, {3, 12}}}},
		{"r", {{{3, 13}, {3, 14}, {3, 15}}}},
		{"t", {{{3, 16}, {3, 17}, {3, 18}}}},
		{"y", {{{3, 19}, {3, 20}, {3, 21}}}},
		{"u", {{{3, 22}, {3, 23}, {3, 24}}}},
		{"i", {{{3, 25}, {3, 26}, {3, 27}}}},
		{"o", {{{3, 28}, {3, 29}, {3, 30}}}},
		{"p", {{{3, 31}, {3, 32}, {3, 33}}}},
		{"Bracket_l", {{{3, 34}, {3, 35}, {3, 36}}}},
		{"Bracket_r", {{{3, 37}, {3, 38}, {3, 39}}}},
		{"Backslash", {{{4, 32}, {4, 33}, {4, 34}}}},
		{"Up", {{{6, 16}, {6, 17}, {6, 18}}}},
		{"Left", {{{6, 10}, {6, 11}, {6, 12}}}},
		{"Down", {{{6, 13}, {6, 14}, {6, 15}}}},
		{"Right", {{{6, 19}, {6, 20}, {6, 21}}}},
		{"Caps_Lock", {{{3, 52}, {3, 53}, {3, 54}}}},
		{"a", {{{3, 55}, {3, 56}, {3, 57}}}},
		{"s", {{{3, 58}, {3, 59}, {3, 60}}}},
		{"d", {{{3, 61}, {3, 62}, {3, 63}}}},
		{"f", {{{4, 8}, {4, 9}, {4, 10}}}},
		{"g", {{{4, 11}, {4, 12}, {4, 13}}}},
		{"h", {{{4, 14}, {4, 15}, {4, 16}}}},
		{"j", {{{4, 17}, {4, 18}, {4, 19}}}},
		{"k", {{{4, 20}, {4, 21}, {4, 22}}}},
		{"l", {{{4, 23}, {4, 24}, {4, 25}}}},
		{"Semicolon", {{{4, 26}, {4, 27}, {4, 28}}}},
		{"Apostrophe", {{{4, 29}, {4, 30}, {4, 31}}}},
		{"Return", {{{5, 27}, {5, 28}, {5, 29}}}},
		{"z", {{{4, 50}, {4, 51}, {4, 52}}}},
		{"x", {{{4, 53}, {4, 54}, {4, 55}}}},
		{"c", {{{4, 56}, {4, 57}, {4, 58}}}},
		{"v", {{{4, 59}, {4, 60}, {4, 61}}}},
		{"b", {{{4, 62}, {4, 63}, {5, 8}}}},
		{"n", {{{5, 9}, {5, 10}, {5, 11}}}},
		{"m", {{{5, 12}, {5, 13}, {5, 14}}}},
		{"Comma", {{{5, 15}, {5, 16}, {5, 17}}}},
		{"Period", {{{5, 18}, {5, 19}, {5, 20}}}},
		{"Slash", {{{5, 21}, {5, 22}, {5, 23}}}},
		{"Shift_l", {{{4, 47}, {4, 48}, {4, 49}}}},
		{"Shift_r", {{{5, 24}, {5, 25}, {5, 26}}}},
		{"Ctrl_l", {{{5, 42}, {5, 43}, {5, 44}}}},
		{"Super_l", {{{5, 45}, {5, 46}, {5, 47}}}},
		{"Alt_l", {{{5, 48}, {5, 49}, {5, 50}}}},
		{"Space", {{{5, 51}, {5, 52}, {5, 53}}}},
		{"Alt_r", {{{5, 54}, {5, 55}, {5, 56}}}},
		{"Fn", {{{5, 57}, {5, 58}, {5, 59}}}},
		{"Menu", {{{5, 60}, {5, 61}, {5, 62}}}},
		{"Ctrl_r", {{{5, 63}, {6, 8}, {6, 9}}}},
		{"Num_Lock", {{{2, 45}, {2, 46}, {2, 47}}}},
		{"Num_Slash", {{{2, 48}, {2, 49}, {2, 50}}}},
		{"Num_Asterisk", {{{2, 51}, {2, 52}, {2, 53}}}},
		{"Num_Minus", {{{7, 20}, {7, 21}, {7, 22}}}},
		{"Num_Plus", {{{7, 23}, {7, 24}, {7, 25}}}},
		{"Num_1", {{{5, 30}, {5, 31}, {5, 32}}}},
		{"Num_2", {{{5, 33}, {5, 34}, {5, 35}}}},
		{"Num_3", {{{5, 36}, {5, 37}, {5, 38}}}},
		{"Num_4", {{{4, 35}, {4, 36}, {4, 37}}}},
		{"Num_5", {{{4, 38}, {4, 39}, {4, 40}}}},
		{"Num_6", {{{4, 41}, {4, 42}, {4, 43}}}},
		{"Num_7", {{{3, 40}, {3, 41}, {3, 42}}}},
		{"Num_8", {{{3, 43}, {3, 44}, {3, 45}}}},
		{"Num_9", {{{3, 46}, {3, 47}, {3, 48}}}},
		{"Num_0", {{{6, 25}, {6, 26}, {6, 27}}}},
		{"Num_Period", {{{6, 28}, {6, 29}, {6, 30}}}},
		{"Num_Return", {{{6, 31}, {6, 32}, {6, 33}}}},
		{"Int_Key", {{{6, 43}, {6, 44}, {6, 45}}}}};

// options for keymapping
std::map<std::string, std::array<uint8_t, 3>>
	rgb_keyboard::keyboard::_keymap_options = {
		// top row
		{"Esc", {0x02, 0x02, 0x29}},
		{"F1", {0x02, 0x02, 0x3a}},
		{"F2", {0x02, 0x02, 0x3b}},
		{"F3", {0x02, 0x02, 0x3c}},
		{"F4", {0x02, 0x02, 0x3d}},
		{"F5", {0x02, 0x02, 0x3e}},
		{"F6", {0x02, 0x02, 0x3f}},
		{"F7", {0x02, 0x02, 0x40}},
		{"F8", {0x02, 0x02, 0x41}},
		{"F9", {0x02, 0x02, 0x42}},
		{"F10", {0x02, 0x02, 0x43}},
		{"F11", {0x02, 0x02, 0x44}},
		{"F12", {0x02, 0x02, 0x45}},
		{"PrtSc", {0x02, 0x02, 0x46}},
		{"ScrLk", {0x02, 0x02, 0x47}},
		{"Pause", {0x02, 0x02, 0x48}},
		// Alphanumeric
		{"a", {0x02, 0x02, 0x04}},
		{"b", {0x02, 0x02, 0x05}},
		{"c", {0x02, 0x02, 0x06}},
		{"d", {0x02, 0x02, 0x07}},
		{"e", {0x02, 0x02, 0x08}},
		{"f", {0x02, 0x02, 0x09}},
		{"g", {0x02, 0x02, 0x0a}},
		{"h", {0x02, 0x02, 0x0b}},
		{"i", {0x02, 0x02, 0x0c}},
		{"j", {0x02, 0x02, 0x0d}},
		{"k", {0x02, 0x02, 0x0e}},
		{"l", {0x02, 0x02, 0x0f}},
		{"m", {0x02, 0x02, 0x10}},
		{"n", {0x02, 0x02, 0x11}},
		{"o", {0x02, 0x02, 0x12}},
		{"p", {0x02, 0x02, 0x13}},
		{"q", {0x02, 0x02, 0x14}},
		{"r", {0x02, 0x02, 0x15}},
		{"s", {0x02, 0x02, 0x16}},
		{"t", {0x02, 0x02, 0x17}},
		{"u", {0x02, 0x02, 0x18}},
		{"v", {0x02, 0x02, 0x19}},
		{"w", {0x02, 0x02, 0x1a}},
		{"x", {0x02, 0x02, 0x1b}},
		{"y", {0x02, 0x02, 0x1c}},
		{"z", {0x02, 0x02, 0x1d}},
		{"1", {0x02, 0x02, 0x1e}},
		{"2", {0x02, 0x02, 0x1f}},
		{"3", {0x02, 0x02, 0x20}},
		{"4", {0x02, 0x02, 0x21}},
		{"5", {0x02, 0x02, 0x22}},
		{"6", {0x02, 0x02, 0x23}},
		{"7", {0x02, 0x02, 0x24}},
		{"8", {0x02, 0x02, 0x25}},
		{"9", {0x02, 0x02, 0x26}},
		{"0", {0x02, 0x02, 0x27}},
		// Modifiers
		{"Tab", {0x02, 0x02, 0x2b}},
		{"Caps_Lock", {0x02, 0x02, 0x39}},
		{"Shift_l", {0x02, 0x02, 0xe1}},
		{"Ctrl_l", {0x02, 0x02, 0xe0}},
		{"Alt_l", {0x02, 0x02, 0xe2}},
		{"Super_l", {0x02, 0x02, 0xe3}},
		{"Super_r", {0x02, 0x02, 0xe7}},
		{"Alt_r", {0x02, 0x02, 0xe6}},
		{"Menu", {0x02, 0x02, 0x65}},
		{"Ctrl_r", {0x02, 0x02, 0xe4}},
		{"Shift_r", {0x02, 0x02, 0xe5}},
		{"Return", {0x02, 0x02, 0x28}},
		{"Backspace", {0x02, 0x02, 0x2a}},
		{"Caps_Lock", {0x02, 0x02, 0x39}},
		{"Fn", {0x05, 0x02, 0x02}},
		// Special characters
		{"Space", {0x02, 0x02, 0x2b}},
		{"Tilde", {0x02, 0x02, 0x35}},
		{"Minus", {0x02, 0x02, 0x2d}},
		{"Equals", {0x02, 0x02, 0x2e}},
		{"Bracket_l", {0x02, 0x02, 0x2f}},
		{"Bracket_r", {0x02, 0x02, 0x30}},
		{"Backslash", {0x02, 0x02, 0x31}},
		{"Hash", {0x02, 0x02, 0x32}},
		{"Semicolon", {0x02, 0x02, 0x33}},
		{"Apostrophe", {0x02, 0x02, 0x34}},
		{"Comma", {0x02, 0x02, 0x36}},
		{"Period", {0x02, 0x02, 0x37}},
		{"Slash", {0x02, 0x02, 0x38}},
		{"Int_Key", {0x02, 0x02, 0x64}},
		// Navigation
		{"Right", {0x02, 0x02, 0x4f}},
		{"Left", {0x02, 0x02, 0x50}},
		{"Down", {0x02, 0x02, 0x51}},
		{"Up", {0x02, 0x02, 0x52}},
		{"Insert", {0x02, 0x02, 0x49}},
		{"Home", {0x02, 0x02, 0x4a}},
		{"PgUp", {0x02, 0x02, 0x4b}},
		{"Delete", {0x02, 0x02, 0x4c}},
		{"End", {0x02, 0x02, 0x4d}},
		{"PgDown", {0x02, 0x02, 0x4e}},
		// Numpad
		{"Num_Slash", {0x02, 0x02, 0x54}},
		{"Num_Asterisk", {0x02, 0x02, 0x55}},
		{"Num_Minus", {0x02, 0x02, 0x56}},
		{"Num_Plus", {0x02, 0x02, 0x57}},
		{"Num_Return", {0x02, 0x02, 0x58}},
		{"Num_1", {0x02, 0x02, 0x59}},
		{"Num_2", {0x02, 0x02, 0x5a}},
		{"Num_3", {0x02, 0x02, 0x5b}},
		{"Num_4", {0x02, 0x02, 0x5c}},
		{"Num_5", {0x02, 0x02, 0x5d}},
		{"Num_6", {0x02, 0x02, 0x5e}},
		{"Num_7", {0x02, 0x02, 0x5f}},
		{"Num_8", {0x02, 0x02, 0x60}},
		{"Num_9", {0x02, 0x02, 0x61}},
		{"Num_0", {0x02, 0x02, 0x62}},
		{"Num_Period", {0x02, 0x02, 0x63}},
		{"Num_Lock", {0x02, 0x02, 0x53}},
		{"Num_Equals", {0x02, 0x02, 0x67}},
		{"Num_Comma", {0x02, 0x02, 0x85}},
		{"Num_Paren_l", {0x02, 0x02, 0xb6}},
		{"Num_Paren_r", {0x02, 0x02, 0xb7}},
		// Media controls, etc. (NOT standard keycode based)
		{"Mediaplayer", {0x03, 0x83, 0x01}},
		{"PlayPause", {0x03, 0xcd, 0x00}},
		{"Stop", {0x03, 0xb7, 0x00}},
		{"Previous", {0x03, 0xb6, 0x00}},
		{"Next", {0x03, 0xb5, 0x00}},
		{"Volume-", {0x03, 0xea, 0x00}},
		{"Volume+", {0x03, 0xe9, 0x00}},
		{"Mute", {0x03, 0xe2, 0x00}},
		{"BrowserHome", {0x03, 0x23, 0x02}},
		{"BrowserRefresh", {0x03, 0x27, 0x02}},
		{"BrowserStop", {0x03, 0x26, 0x02}},
		{"BrowserBack", {0x03, 0x24, 0x02}},
		{"BrowserForward", {0x03, 0x25, 0x02}},
		{"BrowserFavorite", {0x03, 0x2a, 0x02}},
		{"BrowserSearch", {0x03, 0x21, 0x02}},
		{"FileExplorer", {0x03, 0x94, 0x01}},
		{"Calculator", {0x03, 0x92, 0x01}},
		{"Email", {0x03, 0x8a, 0x01}},
		// Standard keycode based special keys
		{"Power", {0x02, 0x02, 0x66}},
		{"Key_Execute", {0x02, 0x02, 0x74}},
		{"Key_Help", {0x02, 0x02, 0x75}},
		{"Key_Props", {0x02, 0x02, 0x76}},
		{"Key_Select", {0x02, 0x02, 0x77}},
		{"Key_Stop", {0x02, 0x02, 0x78}},
		{"Key_Again", {0x02, 0x02, 0x79}},
		{"Key_Undo", {0x02, 0x02, 0x7a}},
		{"Key_Cut", {0x02, 0x02, 0x7b}},
		{"Key_Copy", {0x02, 0x02, 0x7c}},
		{"Key_Paste", {0x02, 0x02, 0x7d}},
		{"Key_Find", {0x02, 0x02, 0x7e}},
		{"Key_Mute", {0x02, 0x02, 0x7f}},
		{"Key_Volume_Up", {0x02, 0x02, 0x80}},
		{"Key_Volume_Down", {0x02, 0x02, 0x81}},
		// Standard keycode based media keys
		{"Media_Play_Pause", {0x02, 0x02, 0xe8}},
		{"Media_Stop_CD", {0x02, 0x02, 0xe9}},
		{"Media_Previous", {0x02, 0x02, 0xea}},
		{"Media_Next", {0x02, 0x02, 0xeb}},
		{"Media_Eject_CD", {0x02, 0x02, 0xec}},
		{"Media_Volume_Up", {0x02, 0x02, 0xed}},
		{"Media_Volume_Down", {0x02, 0x02, 0xee}},
		{"Media_Mute", {0x02, 0x02, 0xef}},
		{"Media_WWW", {0x02, 0x02, 0xf0}},
		{"Media_Back", {0x02, 0x02, 0xf1}},
		{"Media_Forward", {0x02, 0x02, 0xf2}},
		{"Media_Stop", {0x02, 0x02, 0xf3}},
		{"Media_Find", {0x02, 0x02, 0xf4}},
		{"Media_Scroll_Up", {0x02, 0x02, 0xf5}},
		{"Media_Scroll_Down", {0x02, 0x02, 0xf6}},
		{"Media_Edit", {0x02, 0x02, 0xf7}},
		{"Media_Sleep", {0x02, 0x02, 0xf8}},
		{"Media_Screenlock", {0x02, 0x02, 0xf9}},
		{"Media_Refresh", {0x02, 0x02, 0xfa}},
		{"Media_Calc", {0x02, 0x02, 0xfb}},
		// Language specific keys
		{"Lang1", {0x02, 0x02, 0x90}},
		{"Lang2", {0x02, 0x02, 0x91}},
		{"Lang3", {0x02, 0x02, 0x92}},
		{"Lang4", {0x02, 0x02, 0x93}},
		{"Lang5", {0x02, 0x02, 0x94}},
		{"Lang6", {0x02, 0x02, 0x95}},
		{"Lang7", {0x02, 0x02, 0x96}},
		{"Lang8", {0x02, 0x02, 0x97}},
		{"Lang9", {0x02, 0x02, 0x98}},
		{"International1", {0x02, 0x02, 0x87}},
		{"International2", {0x02, 0x02, 0x88}},
		{"International3", {0x02, 0x02, 0x89}},
		{"International4", {0x02, 0x02, 0x8a}},
		{"International5", {0x02, 0x02, 0x8b}},
		{"International6", {0x02, 0x02, 0x8c}},
		{"International7", {0x02, 0x02, 0x8d}},
		{"International8", {0x02, 0x02, 0x8e}},
		{"International9", {0x02, 0x02, 0x8f}},
		// Additional function keys
		{"F13", {0x02, 0x02, 0x68}},
		{"F14", {0x02, 0x02, 0x69}},
		{"F15", {0x02, 0x02, 0x6a}},
		{"F16", {0x02, 0x02, 0x6b}},
		{"F17", {0x02, 0x02, 0x6c}},
		{"F18", {0x02, 0x02, 0x6d}},
		{"F19", {0x02, 0x02, 0x6e}},
		{"F20", {0x02, 0x02, 0x6f}},
		{"F21", {0x02, 0x02, 0x70}},
		{"F22", {0x02, 0x02, 0x71}},
		{"F23", {0x02, 0x02, 0x72}},
		{"F24", {0x02, 0x02, 0x73}}};

// usb data packets

uint8_t rgb_keyboard::keyboard::_data_start[] = {
	0x04, 0x01, 0x00, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};

uint8_t rgb_keyboard::keyboard::_data_end[] = {
	0x04, 0x02, 0x00, 0x02, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};

uint8_t rgb_keyboard::keyboard::_data_settings[] = {
	0x04, 0x00, 0x00, 0x06, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};

// key mapping data
uint8_t rgb_keyboard::keyboard::_data_remap_1[] = {
	0x04, 0x2a, 0x01, 0x0a, 0x10, 0x00, 0x00, 0x00, 0xaa, 0x55, 0x10,
	0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};

uint8_t rgb_keyboard::keyboard::_data_remap_2[] = {
	0x04, 0xcd, 0x07, 0x08, 0x38, 0x00, 0x00, 0x00, /* ....8... */
	0x05, 0xa2, 0xa2, 0x02, 0x02, 0x29, 0x02, 0x02, /* .....).. */
	0x3a, 0x02, 0x02, 0x3b, 0x02, 0x02, 0x3c, 0x02, /* :..;..<. */
	0x02, 0x3d, 0x02, 0x02, 0x3e, 0x02, 0x02, 0x3f, /* .=..>..? */
	0x02, 0x02, 0x40, 0x02, 0x02, 0x41, 0x02, 0x02, /* ..@..A.. */
	0x42, 0x02, 0x02, 0x43, 0x02, 0x02, 0x44, 0x02, /* B..C..D. */
	0x02, 0x45, 0x03, 0xb6, 0x00, 0x03, 0xcd, 0x00, /* .E...... */
	0x03, 0xb5, 0x00, 0x05, 0xa2, 0x01, 0x02, 0x02	/* ........ */
};

uint8_t rgb_keyboard::keyboard::_data_remap_3[] = {
	0x04, 0x8b, 0x04, 0x08, 0x38, 0x38, 0x00, 0x00, /* ....88.. */
	0x35, 0x02, 0x02, 0x1e, 0x02, 0x02, 0x1f, 0x02, /* 5....... */
	0x02, 0x20, 0x02, 0x02, 0x21, 0x02, 0x02, 0x22, /* . ..!.." */
	0x02, 0x02, 0x23, 0x02, 0x02, 0x24, 0x02, 0x02, /* ..#..$.. */
	0x25, 0x02, 0x02, 0x26, 0x02, 0x02, 0x27, 0x02, /* %..&..'. */
	0x02, 0x2d, 0x02, 0x02, 0x2e, 0x02, 0x02, 0x53, /* .-.....S */
	0x02, 0x02, 0x54, 0x02, 0x02, 0x55, 0x05, 0xa2, /* ..T..U.. */
	0x02, 0x02, 0x02, 0x2b, 0x02, 0x02, 0x14, 0x02	/* ...+.... */
};

uint8_t rgb_keyboard::keyboard::_data_remap_4[] = {
	0x04, 0x2c, 0x04, 0x08, 0x38, 0x70, 0x00, 0x00, /* .,..8p.. */
	0x02, 0x1a, 0x02, 0x02, 0x08, 0x02, 0x02, 0x15, /* ........ */
	0x02, 0x02, 0x17, 0x02, 0x02, 0x1c, 0x02, 0x02, /* ........ */
	0x18, 0x02, 0x02, 0x0c, 0x02, 0x02, 0x12, 0x02, /* ........ */
	0x02, 0x13, 0x02, 0x02, 0x2f, 0x02, 0x02, 0x30, /* ..../..0 */
	0x02, 0x02, 0x5f, 0x02, 0x02, 0x60, 0x02, 0x02, /* .._..`.. */
	0x61, 0x05, 0xa2, 0x03, 0x02, 0x02, 0x39, 0x02, /* a.....9. */
	0x02, 0x04, 0x02, 0x02, 0x16, 0x02, 0x02, 0x07	/* ........ */
};

uint8_t rgb_keyboard::keyboard::_data_remap_5[] = {
	0x04, 0x2a, 0x04, 0x08, 0x38, 0xa8, 0x00, 0x00, /* .*..8... */
	0x02, 0x02, 0x09, 0x02, 0x02, 0x0a, 0x02, 0x02, /* ........ */
	0x0b, 0x02, 0x02, 0x0d, 0x02, 0x02, 0x0e, 0x02, /* ........ */
	0x02, 0x0f, 0x02, 0x02, 0x33, 0x02, 0x02, 0x34, /* ....3..4 */
	0x02, 0x02, 0x31, 0x02, 0x02, 0x5c, 0x02, 0x02, /* ..1..\.. */
	0x5d, 0x02, 0x02, 0x5e, 0x05, 0xa2, 0x04, 0x02, /* ]..^.... */
	0x01, 0x02, 0x02, 0x02, 0x1d, 0x02, 0x02, 0x1b, /* ........ */
	0x02, 0x02, 0x06, 0x02, 0x02, 0x19, 0x02, 0x02	/* ........ */
};

uint8_t rgb_keyboard::keyboard::_data_remap_6[] = {
	0x04, 0x11, 0x05, 0x08, 0x38, 0xe0, 0x00, 0x00, /* ....8... */
	0x05, 0x02, 0x02, 0x11, 0x02, 0x02, 0x10, 0x02, /* ........ */
	0x02, 0x36, 0x02, 0x02, 0x37, 0x02, 0x02, 0x38, /* .6..7..8 */
	0x02, 0x01, 0x20, 0x02, 0x02, 0x28, 0x02, 0x02, /* .. ..(.. */
	0x59, 0x02, 0x02, 0x5a, 0x02, 0x02, 0x5b, 0x05, /* Y..Z..[. */
	0xa2, 0x05, 0x02, 0x01, 0x01, 0x02, 0x01, 0x08, /* ........ */
	0x02, 0x01, 0x04, 0x02, 0x02, 0x2c, 0x02, 0x01, /* .....,.. */
	0x40, 0x05, 0x02, 0x02, 0x02, 0x02, 0x65, 0x02	/* @.....e. */
};

uint8_t rgb_keyboard::keyboard::_data_remap_7[] = {
	0x04, 0xdf, 0x06, 0x08, 0x38, 0x18, 0x01, 0x00, /* ....8... */
	0x01, 0x10, 0x02, 0x02, 0x50, 0x02, 0x02, 0x51, /* ....P..Q */
	0x02, 0x02, 0x52, 0x02, 0x02, 0x4f, 0x02, 0x02, /* ..R..O.. */
	0x2a, 0x02, 0x02, 0x62, 0x02, 0x02, 0x63, 0x02, /* *..b..c. */
	0x02, 0x58, 0x02, 0x02, 0x91, 0x02, 0x02, 0x90, /* .X...... */
	0x02, 0x01, 0x80, 0x02, 0x02, 0x64, 0x02, 0x02, /* .....d.. */
	0x46, 0x02, 0x02, 0x47, 0x02, 0x02, 0x48, 0x02, /* F..G..H. */
	0x02, 0x38, 0x02, 0x02, 0x49, 0x02, 0x02, 0x4a	/* .8..I..J */
};

uint8_t rgb_keyboard::keyboard::_data_remap_8[] = {
	0x04, 0xd7, 0x07, 0x08, 0x15, 0x50, 0x01, 0x00, /* .....P.. */
	0x02, 0x02, 0x4b, 0x02, 0x02, 0x4c, 0x02, 0x02, /* ..K..L.. */
	0x4d, 0x02, 0x02, 0x4e, 0x02, 0x02, 0x56, 0x02, /* M..N..V. */
	0x02, 0x57, 0x03, 0xe2, 0x00, 0x02, 0x63, 0x02, /* .W....c. */
	0x02, 0x58, 0x02, 0x02, 0x91, 0x02, 0x02, 0x90, /* .X...... */
	0x02, 0x01, 0x80, 0x02, 0x02, 0x64, 0x02, 0x02, /* .....d.. */
	0x46, 0x02, 0x02, 0x47, 0x02, 0x02, 0x48, 0x02, /* F..G..H. */
	0x02, 0x38, 0x02, 0x02, 0x49, 0x02, 0x02, 0x4a	/* .8..I..J */
};

uint8_t rgb_keyboard::keyboard::_data_remap_iso[][64] = {
	{0x04, 0x2c, 0x01, 0x0a, 0x10, 0x00, 0x00, 0x00, 0xaa, 0x55, 0x10, 0x00, 0x00, 0x00, 0x01, 0x00, 0x02, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00},
	{0x04, 0xcd, 0x07, 0x08, 0x38, 0x00, 0x00, 0x00, 0x05, 0xa2, 0xa2, 0x02, 0x02, 0x29, 0x02, 0x02, 0x3a, 0x02, 0x02, 0x3b, 0x02, 0x02, 0x3c, 0x02, 0x02, 0x3d, 0x02, 0x02, 0x3e, 0x02, 0x02, 0x3f, 0x02, 0x02, 0x40, 0x02, 0x02, 0x41, 0x02, 0x02, 0x42, 0x02, 0x02, 0x43, 0x02, 0x02, 0x44, 0x02, 0x02, 0x45, 0x03, 0xb6, 0x00, 0x03, 0xcd, 0x00, 0x03, 0xb5, 0x00, 0x05, 0xa2, 0x01, 0x02, 0x02},
	{0x04, 0x8b, 0x04, 0x08, 0x38, 0x38, 0x00, 0x00, 0x35, 0x02, 0x02, 0x1e, 0x02, 0x02, 0x1f, 0x02, 0x02, 0x20, 0x02, 0x02, 0x21, 0x02, 0x02, 0x22, 0x02, 0x02, 0x23, 0x02, 0x02, 0x24, 0x02, 0x02, 0x25, 0x02, 0x02, 0x26, 0x02, 0x02, 0x27, 0x02, 0x02, 0x2d, 0x02, 0x02, 0x2e, 0x02, 0x02, 0x53, 0x02, 0x02, 0x54, 0x02, 0x02, 0x55, 0x05, 0xa2, 0x02, 0x02, 0x02, 0x2b, 0x02, 0x02, 0x14, 0x02},
	{0x04, 0x2c, 0x04, 0x08, 0x38, 0x70, 0x00, 0x00, 0x02, 0x1a, 0x02, 0x02, 0x08, 0x02, 0x02, 0x15, 0x02, 0x02, 0x17, 0x02, 0x02, 0x1c, 0x02, 0x02, 0x18, 0x02, 0x02, 0x0c, 0x02, 0x02, 0x12, 0x02, 0x02, 0x13, 0x02, 0x02, 0x2f, 0x02, 0x02, 0x30, 0x02, 0x02, 0x5f, 0x02, 0x02, 0x60, 0x02, 0x02, 0x61, 0x05, 0xa2, 0x03, 0x02, 0x02, 0x39, 0x02, 0x02, 0x04, 0x02, 0x02, 0x16, 0x02, 0x02, 0x07},
	{0x04, 0x2a, 0x04, 0x08, 0x38, 0xa8, 0x00, 0x00, 0x02, 0x02, 0x09, 0x02, 0x02, 0x0a, 0x02, 0x02, 0x0b, 0x02, 0x02, 0x0d, 0x02, 0x02, 0x0e, 0x02, 0x02, 0x0f, 0x02, 0x02, 0x33, 0x02, 0x02, 0x34, 0x02, 0x02, 0x31, 0x02, 0x02, 0x5c, 0x02, 0x02, 0x5d, 0x02, 0x02, 0x5e, 0x05, 0xa2, 0x04, 0x02, 0x01, 0x02, 0x02, 0x02, 0x1d, 0x02, 0x02, 0x1b, 0x02, 0x02, 0x06, 0x02, 0x02, 0x19, 0x02, 0x02},
	{0x04, 0x11, 0x05, 0x08, 0x38, 0xe0, 0x00, 0x00, 0x05, 0x02, 0x02, 0x11, 0x02, 0x02, 0x10, 0x02, 0x02, 0x36, 0x02, 0x02, 0x37, 0x02, 0x02, 0x38, 0x02, 0x01, 0x20, 0x02, 0x02, 0x28, 0x02, 0x02, 0x59, 0x02, 0x02, 0x5a, 0x02, 0x02, 0x5b, 0x05, 0xa2, 0x05, 0x02, 0x01, 0x01, 0x02, 0x01, 0x08, 0x02, 0x01, 0x04, 0x02, 0x02, 0x2c, 0x02, 0x01, 0x40, 0x05, 0x02, 0x02, 0x02, 0x02, 0x65, 0x02},
	{0x04, 0xdf, 0x06, 0x08, 0x38, 0x18, 0x01, 0x00, 0x01, 0x10, 0x02, 0x02, 0x50, 0x02, 0x02, 0x51, 0x02, 0x02, 0x52, 0x02, 0x02, 0x4f, 0x02, 0x02, 0x2a, 0x02, 0x02, 0x62, 0x02, 0x02, 0x63, 0x02, 0x02, 0x58, 0x02, 0x02, 0x91, 0x02, 0x02, 0x90, 0x02, 0x01, 0x80, 0x02, 0x02, 0x64, 0x02, 0x02, 0x46, 0x02, 0x02, 0x47, 0x02, 0x02, 0x48, 0x02, 0x02, 0x38, 0x02, 0x02, 0x49, 0x02, 0x02, 0x4a},
	{0x04, 0x47, 0x07, 0x08, 0x38, 0x50, 0x01, 0x00, 0x02, 0x02, 0x4b, 0x02, 0x02, 0x4c, 0x02, 0x02, 0x4d, 0x02, 0x02, 0x4e, 0x02, 0x02, 0x56, 0x02, 0x02, 0x57, 0x03, 0xe2, 0x00, 0x27, 0x11, 0x1d, 0x16, 0x06, 0x1b, 0x19, 0x09, 0x04, 0x55, 0xaa, 0xff, 0x02, 0x45, 0x0c, 0x2f, 0x65, 0x02, 0x01, 0x00, 0x08, 0x00, 0x00, 0x00, 0x00, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x08, 0x07, 0x09, 0x0b},
	{0x04, 0x50, 0x01, 0x08, 0x38, 0x88, 0x01, 0x00, 0x0a, 0x0c, 0x0d, 0x0f, 0x0e, 0x10, 0x12, 0x11, 0x14, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00},
	{0x04, 0x0c, 0x02, 0x08, 0x38, 0xc0, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x09, 0x02, 0x00, 0xff, 0x00, 0x00, 0x00, 0x00, 0x00},
	{0x04, 0x14, 0x02, 0x08, 0x08, 0xf8, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x09, 0x02, 0x00, 0xff, 0x00, 0x00, 0x00, 0x00, 0x00}
};

uint8_t rgb_keyboard::keyboard::_data_profile[] = {
	0x04, 0xe0, 0x03, 0x04, 0x2c, 0x00, 0x00, 0x00, /* ....,... */
	0x55, 0xaa, 0xff, 0x02, 0x45, 0x0c, 0x2f, 0x65, /* U...E./e */
	0x03, 0x01, 0x00, 0x08, 0x00, 0x00, 0x00, 0x00, /* ........ */
	0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x08, 0x07, /* ........ */
	0x09, 0x0b, 0x0a, 0x0c, 0x0d, 0x0f, 0x0e, 0x10, /* ........ */
	0x12, 0x11, 0x14, 0x00, 0x00, 0x00, 0x00, 0x00, /* ........ */
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, /* ........ */
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00	/* ........ */
};

uint8_t rgb_keyboard::keyboard::_data_read[] = {
	0x04, 0x2f, 0x00, 0x03, 0x2c, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};

#ifdef USE_MACROS
uint8_t rgb_keyboard::keyboard::_data_macros[] = {
	0x04, 0x5d, 0x06, 0x0a, 0x2a, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};
#endif
