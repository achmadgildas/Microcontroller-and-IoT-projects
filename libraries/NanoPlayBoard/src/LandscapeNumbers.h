/*
  LandScapeNumbers.h - Library for the Arduino NanoPlayBoard
  Created by José Juan Sánchez, September, 2016.
  Released under GNU GPL v3.
*/

#ifndef LandScapeNumbers_h
#define LandScapeNumbers_h

#include <avr/pgmspace.h>

const byte landscape_numbers[181][5] PROGMEM = {
  {0xe0,0xa0,0xa0,0xa0,0xe0},     // 0
  {0x40,0x40,0x40,0x40,0x40},     // 1
  {0xe0,0x80,0xe0,0x20,0xe0},     // 2
  {0xe0,0x80,0xe0,0x80,0xe0},     // 3
  {0xa0,0xa0,0xe0,0x80,0x80},     // 4
  {0xe0,0x20,0xe0,0x80,0xe0},     // 5
  {0xe0,0x20,0xe0,0xa0,0xe0},     // 6
  {0xe0,0x80,0x80,0x80,0x80},     // 7
  {0xe0,0xa0,0xe0,0xa0,0xe0},     // 8
  {0xe0,0xa0,0xe0,0x80,0x80},     // 9
  {0xe4,0xa4,0xa4,0xa4,0xe4},     // 10
  {0x44,0x44,0x44,0x44,0x44},     // 11
  {0xe4,0x84,0xe4,0x24,0xe4},     // 12
  {0xe4,0x84,0xe4,0x84,0xe4},     // 13
  {0xa4,0xa4,0xe4,0x84,0x84},     // 14
  {0xe4,0x24,0xe4,0x84,0xe4},     // 15
  {0xe4,0x24,0xe4,0xa4,0xe4},     // 16
  {0xe4,0x84,0x84,0x84,0x84},     // 17
  {0xe4,0xa4,0xe4,0xa4,0xe4},     // 18
  {0xe4,0xa4,0xe4,0x84,0x84},     // 19
  {0xee,0xa8,0xae,0xa2,0xee},     // 20
  {0x4e,0x48,0x4e,0x42,0x4e},     // 21
  {0xee,0x88,0xee,0x22,0xee},     // 22
  {0xee,0x88,0xee,0x82,0xee},     // 23
  {0xae,0xa8,0xee,0x82,0x8e},     // 24
  {0xee,0x28,0xee,0x82,0xee},     // 25
  {0xee,0x28,0xee,0xa2,0xee},     // 26
  {0xee,0x88,0x8e,0x82,0x8e},     // 27
  {0xee,0xa8,0xee,0xa2,0xee},     // 28
  {0xee,0xa8,0xee,0x82,0x8e},     // 29
  {0xee,0xa8,0xae,0xa8,0xee},     // 30
  {0x4e,0x48,0x4e,0x48,0x4e},     // 31
  {0xee,0x88,0xee,0x28,0xee},     // 32
  {0xee,0x88,0xee,0x88,0xee},     // 33
  {0xae,0xa8,0xee,0x88,0x8e},     // 34
  {0xee,0x28,0xee,0x88,0xee},     // 35
  {0xee,0x28,0xee,0xa8,0xee},     // 36
  {0xee,0x88,0x8e,0x88,0x8e},     // 37
  {0xee,0xa8,0xee,0xa8,0xee},     // 38
  {0xee,0xa8,0xee,0x88,0x8e},     // 39
  {0xea,0xaa,0xae,0xa8,0xe8},     // 40
  {0x4a,0x4a,0x4e,0x48,0x48},     // 41
  {0xea,0x8a,0xee,0x28,0xe8},     // 42
  {0xea,0x8a,0xee,0x88,0xe8},     // 43
  {0xaa,0xaa,0xee,0x88,0x88},     // 44
  {0xea,0x2a,0xee,0x88,0xe8},     // 45
  {0xea,0x2a,0xee,0xa8,0xe8},     // 46
  {0xea,0x8a,0x8e,0x88,0x88},     // 47
  {0xea,0xaa,0xee,0xa8,0xe8},     // 48
  {0xea,0xaa,0xee,0x88,0x88},     // 49
  {0xee,0xa2,0xae,0xa8,0xee},     // 50
  {0x4e,0x42,0x4e,0x48,0x4e},     // 51
  {0xee,0x82,0xee,0x28,0xee},     // 52
  {0xee,0x82,0xee,0x88,0xee},     // 53
  {0xae,0xa2,0xee,0x88,0x8e},     // 54
  {0xee,0x22,0xee,0x88,0xee},     // 55
  {0xee,0x22,0xee,0xa8,0xee},     // 56
  {0xee,0x82,0x8e,0x88,0x8e},     // 57
  {0xee,0xa2,0xee,0xa8,0xee},     // 58
  {0xee,0xa2,0xee,0x88,0x8e},     // 59
  {0xee,0xa2,0xae,0xaa,0xee},     // 60
  {0x4e,0x42,0x4e,0x4a,0x4e},     // 61
  {0xee,0x82,0xee,0x2a,0xee},     // 62
  {0xee,0x82,0xee,0x8a,0xee},     // 63
  {0xae,0xa2,0xee,0x8a,0x8e},     // 64
  {0xee,0x22,0xee,0x8a,0xee},     // 65
  {0xee,0x22,0xee,0xaa,0xee},     // 66
  {0xee,0x82,0x8e,0x8a,0x8e},     // 67
  {0xee,0xa2,0xee,0xaa,0xee},     // 68
  {0xee,0xa2,0xee,0x8a,0x8e},     // 69
  {0xee,0xa8,0xa8,0xa8,0xe8},     // 70
  {0x4e,0x48,0x48,0x48,0x48},     // 71
  {0xee,0x88,0xe8,0x28,0xe8},     // 72
  {0xee,0x88,0xe8,0x88,0xe8},     // 73
  {0xae,0xa8,0xe8,0x88,0x88},     // 74
  {0xee,0x28,0xe8,0x88,0xe8},     // 75
  {0xee,0x28,0xe8,0xa8,0xe8},     // 76
  {0xee,0x88,0x88,0x88,0x88},     // 77
  {0xee,0xa8,0xe8,0xa8,0xe8},     // 78
  {0xee,0xa8,0xe8,0x88,0x88},     // 79
  {0xee,0xaa,0xae,0xaa,0xee},     // 80
  {0x4e,0x4a,0x4e,0x4a,0x4e},     // 81
  {0xee,0x8a,0xee,0x2a,0xee},     // 82
  {0xee,0x8a,0xee,0x8a,0xee},     // 83
  {0xae,0xaa,0xee,0x8a,0x8e},     // 84
  {0xee,0x2a,0xee,0x8a,0xee},     // 85
  {0xee,0x2a,0xee,0xaa,0xee},     // 86
  {0xee,0x8a,0x8e,0x8a,0x8e},     // 87
  {0xee,0xaa,0xee,0xaa,0xee},     // 88
  {0xee,0xaa,0xee,0x8a,0x8e},     // 89
  {0xee,0xaa,0xae,0xa8,0xe8},     // 90
  {0x4e,0x4a,0x4e,0x48,0x48},     // 91
  {0xee,0x8a,0xee,0x28,0xe8},     // 92
  {0xee,0x8a,0xee,0x88,0xe8},     // 93
  {0xae,0xaa,0xee,0x88,0x88},     // 94
  {0xee,0x2a,0xee,0x88,0xe8},     // 95
  {0xee,0x2a,0xee,0xa8,0xe8},     // 96
  {0xee,0x8a,0x8e,0x88,0x88},     // 97
  {0xee,0xaa,0xee,0xa8,0xe8},     // 98
  {0xee,0xaa,0xee,0x88,0x88},     // 99
  {0xda,0xda,0xda,0xda,0xda},     // 100
  {0x9a,0x9a,0x9a,0x9a,0x9a},     // 101
  {0xda,0x9a,0xda,0x5a,0xda},     // 102
  {0xda,0x9a,0xda,0x9a,0xda},     // 103
  {0x1a,0x5a,0xda,0x9a,0x9a},     // 104
  {0xda,0x5a,0xda,0x9a,0xda},     // 105
  {0x5a,0x5a,0x5a,0xda,0xda},     // 106
  {0xda,0x9a,0x9a,0x9a,0x9a},     // 107
  {0xda,0xda,0x1a,0xda,0xda},     // 108
  {0xda,0xda,0x9a,0x9a,0x9a},     // 109
  {0xd2,0xd2,0xd2,0xd2,0xd2},     // 110
  {0x92,0x92,0x92,0x92,0x92},     // 111
  {0xd2,0x92,0xd2,0x52,0xd2},     // 112
  {0xd2,0x92,0xd2,0x92,0xd2},     // 113
  {0x12,0x52,0xd2,0x92,0x92},     // 114
  {0xd2,0x52,0xd2,0x92,0xd2},     // 115
  {0x52,0x52,0x52,0xd2,0xd2},     // 116
  {0xd2,0x92,0x92,0x92,0x92},     // 117
  {0xd2,0xd2,0x12,0xd2,0xd2},     // 118
  {0xd2,0xd2,0x92,0x92,0x92},     // 119
  {0xda,0xd2,0xda,0xca,0xda},     // 120
  {0x9a,0x92,0x9a,0x8a,0x9a},     // 121
  {0xda,0x92,0xda,0x4a,0xda},     // 122
  {0xda,0x92,0xda,0x8a,0xda},     // 123
  {0x1a,0x52,0xda,0x8a,0x9a},     // 124
  {0xda,0x52,0xda,0x8a,0xda},     // 125
  {0x5a,0x52,0x5a,0xca,0xda},     // 126
  {0xda,0x92,0x9a,0x8a,0x9a},     // 127
  {0xda,0xd2,0x1a,0xca,0xda},     // 128
  {0xda,0xd2,0x9a,0x8a,0x9a},     // 129
  {0xda,0xd2,0xda,0xd2,0xda},     // 130
  {0x9a,0x92,0x9a,0x92,0x9a},     // 131
  {0xda,0x92,0xda,0x52,0xda},     // 132
  {0xda,0x92,0xda,0x92,0xda},     // 133
  {0x1a,0x52,0xda,0x92,0x9a},     // 134
  {0xda,0x52,0xda,0x92,0xda},     // 135
  {0x5a,0x52,0x5a,0xd2,0xda},     // 136
  {0xda,0x92,0x9a,0x92,0x9a},     // 137
  {0xda,0xd2,0x1a,0xd2,0xda},     // 138
  {0xda,0xd2,0x9a,0x92,0x9a},     // 139
  {0xc2,0xca,0xda,0xd2,0xd2},     // 140
  {0x82,0x8a,0x9a,0x92,0x92},     // 141
  {0xc2,0x8a,0xda,0x52,0xd2},     // 142
  {0xc2,0x8a,0xda,0x92,0xd2},     // 143
  {0x02,0x4a,0xda,0x92,0x92},     // 144
  {0xc2,0x4a,0xda,0x92,0xd2},     // 145
  {0x42,0x4a,0x5a,0xd2,0xd2},     // 146
  {0xc2,0x8a,0x9a,0x92,0x92},     // 147
  {0xc2,0xca,0x1a,0xd2,0xd2},     // 148
  {0xc2,0xca,0x9a,0x92,0x92},     // 149
  {0xda,0xca,0xda,0xd2,0xda},     // 150
  {0x9a,0x8a,0x9a,0x92,0x9a},     // 151
  {0xda,0x8a,0xda,0x52,0xda},     // 152
  {0xda,0x8a,0xda,0x92,0xda},     // 153
  {0x1a,0x4a,0xda,0x92,0x9a},     // 154
  {0xda,0x4a,0xda,0x92,0xda},     // 155
  {0x5a,0x4a,0x5a,0xd2,0xda},     // 156
  {0xda,0x8a,0x9a,0x92,0x9a},     // 157
  {0xda,0xca,0x1a,0xd2,0xda},     // 158
  {0xda,0xca,0x9a,0x92,0x9a},     // 159
  {0xca,0xca,0xca,0xda,0xda},     // 160
  {0x8a,0x8a,0x8a,0x9a,0x9a},     // 161
  {0xca,0x8a,0xca,0x5a,0xda},     // 162
  {0xca,0x8a,0xca,0x9a,0xda},     // 163
  {0x0a,0x4a,0xca,0x9a,0x9a},     // 164
  {0xca,0x4a,0xca,0x9a,0xda},     // 165
  {0x4a,0x4a,0x4a,0xda,0xda},     // 166
  {0xca,0x8a,0x8a,0x9a,0x9a},     // 167
  {0xca,0xca,0x0a,0xda,0xda},     // 168
  {0xca,0xca,0x8a,0x9a,0x9a},     // 169
  {0xda,0xd2,0xd2,0xd2,0xd2},     // 170
  {0x9a,0x92,0x92,0x92,0x92},     // 171
  {0xda,0x92,0xd2,0x52,0xd2},     // 172
  {0xda,0x92,0xd2,0x92,0xd2},     // 173
  {0x1a,0x52,0xd2,0x92,0x92},     // 174
  {0xda,0x52,0xd2,0x92,0xd2},     // 175
  {0x5a,0x52,0x52,0xd2,0xd2},     // 176
  {0xda,0x92,0x92,0x92,0x92},     // 177
  {0xda,0xd2,0x12,0xd2,0xd2},     // 178
  {0xda,0xd2,0x92,0x92,0x92},     // 179
  {0xda,0xda,0xc2,0xda,0xda},     // 180
};

#endif