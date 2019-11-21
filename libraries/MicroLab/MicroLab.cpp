/* Arduino Microlab AH500 Controller Library
 * Copyright (C) 2019 by Yury Shvedov <mestofel13@gmail.com>
 *
 * This Library is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This Library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * <http://www.gnu.org/licenses/>.
 */

#include <Arduino.h>
#include "MicroLab.h"

#define SBMODE 4
#define INCHAN 7

int AH500::init(void)
{
    int ret = PT2322::init();
    if (ret) {
        return ret;
    }
    pinMode(SBMODE, OUTPUT);
    pinMode(INCHAN, OUTPUT);
    standBy(true);
    select6ch();
    return 0;
}

void AH500::standBy(bool sb)
{
    digitalWrite(SBMODE, sb ? HIGH : LOW);
}

void AH500::selectInput(AH500::ChannelInput ch)
{
    char value;
    switch (ch) {
    case in2ch:
        value = LOW;
        break;
    case in6ch:
        value = HIGH;
        break;
    default:
        return;
    }
    digitalWrite(INCHAN, value);
}
void AH500::select2ch()
{
    selectInput(in2ch);
}
void AH500::select6ch()
{
    selectInput(in6ch);
}
