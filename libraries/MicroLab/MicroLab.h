/* Arduino Microlab A-H500 Controller Library
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


/*
 * This is based on PT2322 Library and widen it with controlling of standBy mode
 * port and input selection port. It uses 4 and 7 ports (PD4 and PD7)
 * respectively to those.
 */

#include <PT2322.h>

class AH500 : public PT2322
{
public:
    enum ChannelInput {
        in2ch = 0,
        in6ch = 1,
    };
public:
    int init(void);
    void standBy(bool sb);
    void selectInput(ChannelInput ch);
    void select2ch();
    void select6ch();
};
