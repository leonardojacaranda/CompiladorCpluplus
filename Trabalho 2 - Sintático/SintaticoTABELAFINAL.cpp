//Leonardo Jacarandá Neves - 137570
//Paulo Henrique Gonçalves - 142575

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <iostream>
#include <list>

#define ACC 999
#define R1 1
#define R2 2
#define R3 3
#define R4 4
#define R5 5
#define R6 6
#define R7 7
#define R8 8
#define R9 9
#define R10 10
#define R11 11
#define R12 12
#define R13 13
#define R14 14
#define R15 15
#define R16 16
#define R17 17
#define R18 18
#define R19 19
#define R20 20
#define R21 21
#define R22 22
#define R23 23
#define R24 24
#define R25 25
#define R26 26
#define R27 27
#define R28 28
#define R29 29
#define R30 30

#define S1 101
#define S2 102
#define S3 103
#define S4 104
#define S5 105
#define S6 106
#define S7 107
#define S8 108
#define S9 109
#define S10 110
#define S11 111
#define S12 112
#define S13 113
#define S14 114
#define S15 115
#define S16 116
#define S17 117
#define S18 118
#define S19 119
#define S20 120
#define S21 121
#define S22 122
#define S23 123
#define S24 124
#define S25 125
#define S26 126
#define S27 127
#define S28 128
#define S29 129
#define S30 130
#define S31 131
#define S32 132
#define S33 133
#define S34 134
#define S35 135
#define S36 136
#define S37 137
#define S38 138
#define S39 139
#define S40 140
#define S41 141
#define S42 142
#define S43 143
#define S44 144
#define S45 145
#define S46 146
#define S47 147
#define S48 148
#define S49 149
#define S50 150
#define S51 151
#define S52 152
#define S53 153
#define S54 154
#define S55 155
#define S56 156
#define S57 157
#define S58 158

#define E0 -3
#define E1 -4
#define E2 -5
#define E3 -6
#define E4 -7
#define E6 -9
#define E7 -10
#define E8 -11
#define E10 -13
#define E11 -14
#define E12 -15
#define E13 -16
#define E14 -17
#define E16 -19
#define E17 -20
#define E18 -21
#define E22 -25
#define E23 -26
#define E27 -30
#define E29 -32
#define E30 -33
#define E31 -34
#define E33 -36
#define E36 -39
#define E42 -45
#define E43 -46
#define E49 -52
#define E50 -53
#define E52 -55
#define E53 -56
#define E54 -57

#define P2 2
#define P30 30
#define P3 3
#define P10 10
#define P16 16
#define P22 22
#define P13 13
#define P14 14
#define P15 15
#define P23 23
#define P29 29
#define P4 4
#define P5 5
#define P7 7
#define P8 8
#define P9 9
#define P11 11
#define P12 12
#define P20 20
#define P21 21
#define P26 26
#define P27 27
#define P28 28
#define P6 6
#define P18 18
#define P17 17
#define P24 24
#define P25 25

// E são os erros
// S são os empilhamentos
// R são as reduções
// P são as propagações das reduções

int tabela_acoes [59][22] =
{
//  0           1       2        3     4      5       6    7    8       9         10      11    12     13    14     15   16     17      18    19    20    21
// inicio  varinicio  varfim     ;     id     int   real  lit   leia  escreva   literal  num   rcb    opm    se     (     )    entao    opr   fim  fimse  $
    S2,        E0,      E0,     E0,    E0,    E0,    E0,   E0,   E0,    E0,       E0,     E0,   E0,    E0,   E0,    E0,   E0,    E0,    E0,   E0,   E0,   E0,   //est 0
    E1,        E1,      E1,     E1,    E1,    E2,    E1,   E1,   E1,    E1,       E1,     E1,   E1,    E1,   E1,    E1,   E1,    E1,    E1,   E1,   E1,   ACC,  //est 1
    E2,        S4,      E2,     E2,    E2,    E2,    E2,   E2,   E2,    E2,       E2,     E2,   E2,    E2,   E2,    E2,   E2,    E2,    E2,   E2,   E2,   E2,   //est 2
    E3,        E3,      E3,     E3,    S12,   E3,    E3,   E3,   S10,   S11,      E3,     E3,   E3,    E3,   S14,   E3,   E3,    E3,    E3,   S9,   E3,   E3,   //est 3
    E4,        E4,      S17,    E4,    S18,   E4,    E4,   E4,   E4,    E4,       E4,     E4,   E4,    E4,   E4,    E4,   E4,    E4,    E4,   E4,   E4,   E4,   //est 4
    P2,        P2,      P2,     P2,    P2,    P2,    P2,   P2,   P2,    P2,       P2,     P2,   P2,    P2,   P2,    P2,   P2,    P2,    P2,   P2,   P2,   R2,   //est 5
    E6,        E6,      E6,     E6,    S12,   E6,    E6,   E6,   S10,   S11,      E6,     E6,   E6,    E6,   S14,   E6,   E6,    E6,    E6,   S9,   E6,   E6,   //est 6
    E7,        E7,      E7,     E7,    S12,   E7,    E7,   E7,   S10,   S11,      E7,     E7,   E7,    E7,   S14,   E7,   E7,    E7,    E7,   S9,   E7,   E7,   //est 7
    E8,        E8,      E8,     E8,    S12,   E8,    E8,   E8,   S10,   S11,      E8,     E8,   E8,    E8,   S14,   E8,   E8,    E8,    E8,   S9,   E8,   E8,   //est 8
    P30,       P30,     P30,    P30,   P30,   P30,   P30,  P30,  P30,   P30,      P30,    P30,  P30,   P30,  P30,   P30,  P30,   P30,   P30,  P30,  P30,  R30,  //est 9
    E10,       E10,     E10,    E10,   S22,   E10,   E10,  E10,  E10,   E10,      E10,    E10,  E10,   E10,  E10,   E10,  E10,   E10,   E10,  E10,  E10,  E10,  //est 10
    E11,       E11,     E11,    E11,   S26,   E11,   E11,  E11,  E11,   E11,      S24,    S25,  E11,   E11,  E11,   E11,  E11,   E11,   E11,  E11,  E11,  E11,  //est 11
    E12,       E12,     E12,    E12,   E12,   E12,   E12,  E12,  E12,   E12,      E12,    E12,  S27,   E12,  E12,   E12,  E12,   E12,   E12,  E12,  E12,  E12,  //est 12
    E13,       E13,     E13,    E13,   S12,   E13,   E13,  E13,  S10,   S11,      E13,    E13,  E13,   E13,  S14,   E13,  E13,   E13,   E13,  E13,  S32,  E13,  //est 13
    E14,       E14,     E14,    E14,   E14,   E14,   E14,  E14,  E14,   E14,      E14,    E14,  E14,   E14,  E14,   S33,  E14,   E14,   E14,  E14,  E14,  E14,  //est 14
    P3,        P3,      P3,     P3,    R3,    P3,    P3,   P3,   R3,    R3,       P3,     P3,   P3,    P3,   R3,    P3,   P3,    P3,    P3,   R3,   P3,   P3,  //est 15
    E16,       E16,     S17,    E16,   S18,   E16,   E16,  E16,  E16,   E16,      E16,    E16,  E16,   E16,  E16,   E16,  E16,   E16,   E16,  E16,  E16,  E16,  //est 16
    E17,       E17,     E17,    S35,   E17,   E17,   E17,  E17,  E17,   E17,      E17,    E17,  E17,   E17,  E17,   E17,  E17,   E17,   E17,  E17,  E17,  E17,  //est 17
    E18,       E18,     E18,    E18,   E18,   S37,   S38,  S39,  E18,   E18,      E18,    E18,  E18,   E18,  E18,   E18,  E18,   E18,   E18,  E18,  E18,  E18,  //est 18
    P10,       P10,     P10,    P10,   P10,   P10,   P10,  P10,  P10,   P10,      P10,    P10,  P10,   P10,  P10,   P10,  P10,   P10,   P10,  P10,  P10,  R10, //est 19
    P16,       P16,     P16,    P16,   P16,   P16,   P16,  P16,  P16,   P16,      P16,    P16,  P16,   P16,  P16,   P16,  P16,   P16,   P16,  P16,  P16,  R16, //est 20
    P22,       P22,     P22,    P22,   P22,   P22,   P22,  P22,  P22,   P22,      P22,    P22,  P22,   P22,  P22,   P22,  P22,   P22,   P22,  P22,  P22,  R22, //est 21
    E22,       E22,     E22,    S40,   E22,   E22,   E22,  E22,  E22,   E22,      E22,    E22,  E22,   E22,  E22,   E22,  E22,   E22,   E22,  E22,  E22,  E22,  //est 22
    E23,       E23,     E23,    S41,   E23,   E23,   E23,  E23,  E23,   E23,      E23,    E23,  E23,   E23,  E23,   E23,  E23,   E23,   E23,  E23,  E23,  E23,  //est 23
    P13,       P13,     P13,    R13,   P13,   P13,   P13,  P13,  P13,   P13,      P13,    P13,  P13,   P13,  P13,   P13,  P13,   P13,   P13,  P13,  P13,  P13,  //est 24
    P14,       P14,     P14,    R14,   P14,   P14,   P14,  P14,  P14,   P14,      P14,    P14,  P14,   P14,  P14,   P14,  P14,   P14,   P14,  P14,  P14,  P14,  //est 25
    P15,       P15,     P15,    R15,   P15,   P15,   P15,  P15,  P15,   P15,      P15,    P15,  P15,   P15,  P15,   P15,  P15,   P15,   P15,  P15,  P15,  P15,  //est 26
    E27,       E27,     E27,    E27,   S44,   E27,   E27,  E27,  E27,   E27,      E27,    S45,  E27,   E27,  E27,   E27,  E27,   E27,   E27,  E27,  E27,  E27,  //est 27
    P23,       P23,     P23,    P23,   R23,   P23,   P23,  P23,  R23,   R23,      P23,    P23,  P23,   P23,  R23,   P23,  P23,   P23,   P23,  R23,  R23,  P23,  //est 28
    E29,       E29,     E29,    E29,   S12,   E29,   E29,  E29,  S10,   S11,      E29,    E29,  E29,   E29,  S14,   E29,  E29,   E29,   E29,  E29,  S32,  E29,  //est 29
    E30,       E30,     E30,    E30,   S12,   E30,   E30,  E30,  S10,   S11,      E30,    E30,  E30,   E30,  S14,   E30,  E30,   E30,   E30,  E30,  S32,  E30,  //est 30
    E31,       E31,     E31,    E31,   S12,   E31,   E31,  E31,  S10,   S11,      E31,    E31,  E31,   E31,  S14,   E31,  E31,   E31,   E31,  E31,  S32,  E31,  //est 31
    P29,       P29,     P29,    P29,   R29,   P29,   P29,  P29,  R29,   R29,      P29,    P29,  P29,   P29,  R29,   P29,  P29,   P29,   P29,  R29,  R29,  P29,  //est 32
    E33,       E33,     E33,    E33,   S44,   E33,   E33,  E33,  E33,   E33,      E33,    S45,  E33,   E33,  E33,   E33,  E33,   E33,   E33,  E33,  E33,  E33,  //est 33
    P4,        P4,      P4,     P4,    R4,    P4,    P4,   P4,   R4,    R4,       P4,     P4,   P4,    P4,   R4,    P4,   P4,    P4,    P4,   R4,   P4,   P4, //est 34
    P5,        P5,      P5,     P5,    R5,    P5,    P5,   P5,   R5,    R5,       P5,     P5,   P5,    P5,   R5,    P5,   P5,    P5,    P5,   R5,   P5,   P5,  //est 35
    E36,       E36,     E36,    S51,   E36,   E36,   E36,  E36,  E36,   E36,      E36,    E36,  E36,   E36,  E36,   E36,  E36,   E36,   E36,  E36,  E36,  E36,  //est 36
    P7,        P7,      P7,     R7,    P7,    P7,    P7,   P7,   P7,    P7,       P7,     P7,   P7,    P7,   P7,    P7,   P7,    P7,    P7,   P7,   P7,   P7,  //est 37
    P8,        P8,      P8,     R8,    P8,    P8,    P8,   P8,   P8,    P8,       P8,     P8,   P8,    P8,   P8,    P8,   P8,    P8,    P8,   P8,   P8,   P8,  //est 38
    P9,        P9,      P9,     R9,    P9,    P9,    P9,   P9,   P9,    P9,       P9,     P9,   P9,    P9,   P9,    P9,   P9,    P9,    P9,   P9,   P9,   P9,  //est 39
    P11,       P11,     P11,    P11,   R11,   P11,   P11,  P11,  R11,   R11,      P11,    P11,  P11,   P11,  R11,   P11,  P11,   P11,   P11,  R11,  R11,  P11,  //est 40
    P12,       P12,     P12,    P12,   R12,   P12,   P12,  P12,  R12,   R12,      P12,    P12,  P12,   P12,  R12,   P12,  P12,   P12,   P12,  R12,  R12,  P12,  //est 41
    E42,       E42,     E42,    S56,   E42,   E42,   E42,  E42,  E42,   E42,      E42,    E42,  E42,   E42,  E42,   E42,  E42,   E42,   E42,  E42,  E42,  E42,  //est 42
    E43,       E43,     E43,    R19,   E43,   E43,   E43,  E43,  E43,   E43,      E43,    E43,  E43,   S52,  E43,   E43,  E43,   E43,   E43,  E43,  E43,  E43,  //est 43
    P20,       P20,     P20,    R20,   P20,   P20,   P20,  P20,  P20,   P20,      P20,    P20,  P20,   R20,  P20,   P20,  R20,   P20,   R20,  P20,  P20,  P20,  //est 44
    P21,       P21,     P21,    R21,   P21,   P21,   P21,  P21,  P21,   P21,      P21,    P21,  P21,   R21,  P21,   P21,  R21,   P21,   R21,  P21,  P21,  P21,  //est 45
    P26,       P26,     P26,    P26,   R26,   P26,   P26,  P26,  R26,   R26,      P26,    P26,  P26,   P26,  R26,   P26,  P26,   P26,   P26,  R26,  R26,  P26,  //est 46
    P27,       P27,     P27,    P27,   R27,   P27,   P27,  P27,  R27,   R27,      P27,    P27,  P27,   P27,  R27,   P27,  P27,   P27,   P27,  R27,  R27,  P27, //est 47
    P28,       P28,     P28,    P28,   R28,   P28,   P28,  P28,  R28,   R28,      P28,    P28,  P28,   P28,  R28,   P28,  P28,   P28,   P28,  R28,  R28,  P28,  //est 48
    E49,       E49,     E49,    E49,   E49,   E49,   E49,  E49,  E49,   E49,      E49,    E49,  E49,   E49,  E49,   E49,  S53,   E49,   E49,  E49,  E49,  E49,  //est 49
    E50,       E50,     E50,    E50,   E50,   E50,   E50,  E50,  E50,   E50,      E50,    E50,  E50,   E50,  E50,   E50,  E50,   E50,   S54,  E50,  E50,  E50,  //est 50
    P6,        P6,      R6,     P6,    R6,    P6,    P6,   P6,   P6,    P6,       P6,     P6,   P6,    P6,   P6,    P6,   P6,    P6,    P6,   P6,   P6,   P6,  //est 51
    E52,       E52,     E52,    E52,   S44,   E52,   E52,  E52,  E52,   E52,      E52,    S45,  E52,   E52,  E52,   E52,  E52,   E52,   E52,  E52,  E52,  E52,  //est 52
    E53,       E53,     E53,    E53,   E53,   E53,   E53,  E53,  E53,   E53,      E53,    E53,  E53,   E53,  E53,   E53,  E53,   S57,   E53,  E53,  E53,  E53,  //est 53
    E54,       E54,     E54,    E54,   S44,   E54,   E54,  E54,  E54,   E54,      E54,    S45,  E54,   E54,  E54,   E54,  E54,   E54,   E54,  E54,  E54,  E54,  //est 54
    P18,       P18,     P18,    R18,   P18,   P18,   P18,  P18,  P18,   P18,      P18,    P18,  P18,   P18,  P18,   P18,  P18,   P18,   P18,  P18,  P18,  P18,  //est 55
    P17,       P17,     P17,    P17,   R17,   P17,   P17,  P17,  R17,   R17,      P17,    P17,  P17,   P17,  R17,   P17,  P17,   P17,   P17,  R17,  R17,  P17,  //est 56
    P24,       P24,     P24,    P24,   R24,   P24,   P24,  P24,  R24,   R24,      P24,    P24,  P24,   P24,  R24,   P24,  P24,   P24,   P24,  P24,  R24,  P24,  //est 57
    P25,       P25,     P25,    P25,   P25,   P25,   P25,  P25,  P25,   P25,      P25,    P25,  P25,   P25,  P25,   P25,  R25,   P25,   P25,  P25,  P25,  P25,  //est 58

};

int tabela_GOTO [59][15] =
{
//  0    1     2     3      4      5     6      7     8      9       10        11        12       13      14
//  P    V     LV    D     TIPO   A      ES     ARG   CMD    LD     OPRD      COND    CABEÇALO   EXP_R   CORPO
    1,   -1 ,  -1,    -1,    -1,   -1,    -1,    -1,   -1,    -1,     -1,       -1,       -1,       -1,    -1, //estado 0
    -1,  -1 ,  -1,    -1,    -1,   -1,    -1,    -1,   -1,    -1,     -1,       -1,       -1,       -1,    -1, //estado 1
    -1,   3 ,  -1,    -1,    -1,   -1,    -1,    -1,   -1,    -1,     -1,       -1,       -1,       -1,    -1, //estado 2
    -1,  -1 ,  -1,    -1,    -1,    5,     6,    -1,    7,    -1,     -1,        8,       13,       -1,    -1, //estado 3
    -1,  -1 ,  15,    16,    -1,   -1,    -1,    -1,   -1,    -1,     -1,       -1,       -1,       -1,    -1, //estado 4
    -1,  -1 ,  -1,    -1,    -1,   -1,    -1,    -1,   -1,    -1,     -1,       -1,       -1,       -1,    -1, //estado 5
    -1,  -1 ,  -1,    -1,    -1,   19,     6,    -1,    7,    -1,     -1,        8,       13,       -1,    -1, //estado 6
    -1,  -1 ,  -1,    -1,    -1,   20,     6,    -1,    7,    -1,     -1,        8,       13,       -1,    -1, //estado 7
    -1,  -1 ,  -1,    -1,    -1,   21,     6,    -1,    7,    -1,     -1,        8,       13,       -1,    -1, //estado 8
    -1,  -1 ,  -1,    -1,    -1,   -1,    -1,    -1,   -1,    -1,     -1,       -1,       -1,       -1,    -1, //estado 9
    -1,  -1 ,  -1,    -1,    -1,   -1,    -1,    -1,   -1,    -1,     -1,       -1,       -1,       -1,    -1, //estado 10
    -1,  -1 ,  -1,    -1,    -1,   -1,    -1,    23,   -1,    -1,     -1,       -1,       -1,       -1,    -1, //estado 11
    -1,  -1 ,  -1,    -1,    -1,   -1,    -1,    -1,   -1,    -1,     -1,       -1,       -1,       -1,    -1, //estado 12
    -1,  -1 ,  -1,    -1,    -1,   -1,    29,    -1,   30,    -1,     -1,       31,       13,       -1,    28, //estado 13
    -1,  -1 ,  -1,    -1,    -1,   -1,    -1,    -1,   -1,    -1,     -1,       -1,       -1,       -1,    -1, //estado 14
    -1,  -1 ,  -1,    -1,    -1,   -1,    -1,    -1,   -1,    -1,     -1,       -1,       -1,       -1,    -1, //estado 15
    -1,  -1 ,  34,    16,    -1,   -1,    -1,    -1,   -1,    -1,     -1,       -1,       -1,       -1,    -1, //estado 16
    -1,  -1 ,  -1,    -1,    -1,   -1,    -1,    -1,   -1,    -1,     -1,       -1,       -1,       -1,    -1, //estado 17
    -1,  -1 ,  -1,    -1,    36,   -1,    -1,    -1,   -1,    -1,     -1,       -1,       -1,       -1,    -1, //estado 18
    -1,  -1 ,  -1,    -1,    -1,   -1,    -1,    -1,   -1,    -1,     -1,       -1,       -1,       -1,    -1, //estado 19
    -1,  -1 ,  -1,    -1,    -1,   -1,    -1,    -1,   -1,    -1,     -1,       -1,       -1,       -1,    -1, //estado 20
    -1,  -1 ,  -1,    -1,    -1,   -1,    -1,    -1,   -1,    -1,     -1,       -1,       -1,       -1,    -1, //estado 21
    -1,  -1 ,  -1,    -1,    -1,   -1,    -1,    -1,   -1,    -1,     -1,       -1,       -1,       -1,    -1, //estado 22
    -1,  -1 ,  -1,    -1,    -1,   -1,    -1,    -1,   -1,    -1,     -1,       -1,       -1,       -1,    -1, //estado 23
    -1,  -1 ,  -1,    -1,    -1,   -1,    -1,    -1,   -1,    -1,     -1,       -1,       -1,       -1,    -1, //estado 24
    -1,  -1 ,  -1,    -1,    -1,   -1,    -1,    -1,   -1,    -1,     -1,       -1,       -1,       -1,    -1, //estado 25
    -1,  -1 ,  -1,    -1,    -1,   -1,    -1,    -1,   -1,    -1,     -1,       -1,       -1,       -1,    -1, //estado 26
    -1,  -1 ,  -1,    -1,    -1,   -1,    -1,    -1,   -1,    42,     43,       -1,       -1,       -1,    -1, //estado 27
    -1,  -1 ,  -1,    -1,    -1,   -1,    -1,    -1,   -1,    -1,     -1,       -1,       -1,       -1,    -1, //estado 28
    -1,  -1 ,  -1,    -1,    -1,   -1,    29,    -1,   30,    -1,     -1,       31,       13,       -1,    46, //estado 29
    -1,  -1 ,  -1,    -1,    -1,   -1,    29,    -1,   30,    -1,     -1,       31,       13,       -1,    47, //estado 30
    -1,  -1 ,  -1,    -1,    -1,   -1,    29,    -1,   30,    -1,     -1,       31,       13,       -1,    48, //estado 31
    -1,  -1 ,  -1,    -1,    -1,   -1,    -1,    -1,   -1,    -1,     -1,       -1,       -1,       -1,    -1, //estado 32
    -1,  -1 ,  -1,    -1,    -1,   -1,    -1,    -1,   -1,    -1,     50,       -1,       -1,       49,    -1, //estado 33
    -1,  -1 ,  -1,    -1,    -1,   -1,    -1,    -1,   -1,    -1,     -1,       -1,       -1,       -1,    -1, //estado 34
    -1,  -1 ,  -1,    -1,    -1,   -1,    -1,    -1,   -1,    -1,     -1,       -1,       -1,       -1,    -1, //estado 35
    -1,  -1 ,  -1,    -1,    -1,   -1,    -1,    -1,   -1,    -1,     -1,       -1,       -1,       -1,    -1, //estado 36
    -1,  -1 ,  -1,    -1,    -1,   -1,    -1,    -1,   -1,    -1,     -1,       -1,       -1,       -1,    -1, //estado 37
    -1,  -1 ,  -1,    -1,    -1,   -1,    -1,    -1,   -1,    -1,     -1,       -1,       -1,       -1,    -1, //estado 38
    -1,  -1 ,  -1,    -1,    -1,   -1,    -1,    -1,   -1,    -1,     -1,       -1,       -1,       -1,    -1, //estado 39
    -1,  -1 ,  -1,    -1,    -1,   -1,    -1,    -1,   -1,    -1,     -1,       -1,       -1,       -1,    -1, //estado 40
    -1,  -1 ,  -1,    -1,    -1,   -1,    -1,    -1,   -1,    -1,     -1,       -1,       -1,       -1,    -1, //estado 41
    -1,  -1 ,  -1,    -1,    -1,   -1,    -1,    -1,   -1,    -1,     -1,       -1,       -1,       -1,    -1, //estado 42
    -1,  -1 ,  -1,    -1,    -1,   -1,    -1,    -1,   -1,    -1,     -1,       -1,       -1,       -1,    -1, //estado 43
    -1,  -1 ,  -1,    -1,    -1,   -1,    -1,    -1,   -1,    -1,     -1,       -1,       -1,       -1,    -1, //estado 44
    -1,  -1 ,  -1,    -1,    -1,   -1,    -1,    -1,   -1,    -1,     -1,       -1,       -1,       -1,    -1, //estado 45
    -1,  -1 ,  -1,    -1,    -1,   -1,    -1,    -1,   -1,    -1,     -1,       -1,       -1,       -1,    -1, //estado 46
    -1,  -1 ,  -1,    -1,    -1,   -1,    -1,    -1,   -1,    -1,     -1,       -1,       -1,       -1,    -1, //estado 47
    -1,  -1 ,  -1,    -1,    -1,   -1,    -1,    -1,   -1,    -1,     -1,       -1,       -1,       -1,    -1, //estado 48
    -1,  -1 ,  -1,    -1,    -1,   -1,    -1,    -1,   -1,    -1,     -1,       -1,       -1,       -1,    -1, //estado 49
    -1,  -1 ,  -1,    -1,    -1,   -1,    -1,    -1,   -1,    -1,     -1,       -1,       -1,       -1,    -1, //estado 50
    -1,  -1 ,  -1,    -1,    -1,   -1,    -1,    -1,   -1,    -1,     -1,       -1,       -1,       -1,    -1, //estado 51
    -1,  -1 ,  -1,    -1,    -1,   -1,    -1,    -1,   -1,    -1,     55,       -1,       -1,       -1,    -1, //estado 52
    -1,  -1 ,  -1,    -1,    -1,   -1,    -1,    -1,   -1,    -1,     -1,       -1,       -1,       -1,    -1, //estado 53
    -1,  -1 ,  -1,    -1,    -1,   -1,    -1,    -1,   -1,    -1,     58,       -1,       -1,       -1,    -1, //estado 54
    -1,  -1 ,  -1,    -1,    -1,   -1,    -1,    -1,   -1,    -1,     -1,       -1,       -1,       -1,    -1, //estado 55
    -1,  -1 ,  -1,    -1,    -1,   -1,    -1,    -1,   -1,    -1,     -1,       -1,       -1,       -1,    -1, //estado 56
    -1,  -1 ,  -1,    -1,    -1,   -1,    -1,    -1,   -1,    -1,     -1,       -1,       -1,       -1,    -1, //estado 57
    -1,  -1 ,  -1,    -1,    -1,   -1,    -1,    -1,   -1,    -1,     -1,       -1,       -1,       -1,    -1, //estado 58

};


/* Criar uma estrutura que printará os seguintes erros quando for invocado

E0 ==Erro! Esperava-se ler 'inicio'
E1 == expressao nao aceita
E2 == Erro! Esperava-se ler 'varinicio'
E3 == Erro! Esperava-se ler 'fim'
E4 == Erro! Esperava-se ler 'id' ou 'varfim'
E6 == Erro! Esperava-se ler 'leia ', 'fim', 'se' ,'escreva' ou 'id'
E7 == Erro! Esperava-se ler 'leia ', 'fim', 'se' ,'escreva' ou 'id'
E8 == Erro! Esperava-se ler 'leia ', 'fim', 'se' ,'escreva' ou 'id'
E10 == Erro! Esperava-se ler 'id'
E11 == Erro! Esperava-se ler 'literal', 'num' ou 'id'
E12 == Erro! Esperava-se ler 'rcb'
E13 == Erro! Esperava-se ler 'leia ', 'fimse', 'se' ,'escreva' ou 'id'
E14 == Erro! Esperava-se ler '('
E16 == Erro! Esperava-se ler 'varfim', 'id'
E17 == Erro! Esperava-se ler ';'
E18 == Erro! Esperava-se ler 'int', 'real','lit'
E22 == Erro! Esperava-se ler ';'
E23 == Erro! Esperava-se ler ';'
E27 == Erro! Esperava-se ler 'id' ou 'num'
E29 == Erro! Esperava-se ler 'fimse', 'leia', 'escreva' , 'id' ou 'se'
E30 == Erro! Esperava-se ler 'fimse', 'leia', 'escreva' , 'id' ou 'se'
E31 == Erro! Esperava-se ler 'fimse', 'leia', 'escreva' , 'id' ou 'se'
E33 == Erro! Esperava-se ler 'id', 'num'
E36 == Erro! Esperava-se ler ';'
E42 == Erro! Esperava-se ler ';'
E43 == Erro! Esperava-se ler 'opm'
E49 == Erro! Esperava-se ler ')'
E50 == Erro! Esperava-se ler 'opr'
E52 == Erro! Esperava-se ler 'id', 'num'
E53 == Erro! Esperava-se ler 'entao'
E54 == Erro! Esperava-se ler 'id' , 'num'
/*

/* Criar uma estrutura de dados com os seguintes campos
1 - Número da regra
2 - Váriavel do lado esquerdo
3 - Produções do lado direito da regra
4 - Tamanho do lado direito

A estrutura é necessaria pois o while principal do programa precisa dessas informações.
Exemplo para a primeira regra:

2 P -> inicio V A

Numero da regra = 2
Varíavel do lado esquerdo = P
Produções do lado direito da regra = inicio V A
Tamanho do lado direto = 3

A gramática ta na pasta do trabalho.
*/

