/* current-bricklet
 * Copyright (C) 2011-2012 Olaf Lüke <olaf@tinkerforge.com>
 *
 * current.h: Implementation of Current Bricklet messages
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the
 * Free Software Foundation, Inc., 59 Temple Place - Suite 330,
 * Boston, MA 02111-1307, USA.
 */

#ifndef CURRENT_H
#define CURRENT_H

#include <stdint.h>
#include "bricklib/com/com_common.h"

#define FID_GET_CURRENT 1
#define FID_CALIBRATE 2
#define FID_IS_OVER_CURRENT 3
#define FID_GET_ANALOG_VALUE 4
#define FID_SET_CURRENT_CALLBACK_PERIOD 5
#define FID_GET_CURRENT_CALLBACK_PERIOD 6
#define FID_SET_ANALOG_VALUE_CALLBACK_PERIOD 7
#define FID_GET_ANALOG_VALUE_CALLBACK_PERIOD 8
#define FID_SET_CURRENT_CALLBACK_THRESHOLD 9
#define FID_GET_CURRENT_CALLBACK_THRESHOLD 10
#define FID_SET_ANALOG_VALUE_CALLBACK_THRESHOLD 11
#define FID_GET_ANALOG_VALUE_CALLBACK_THRESHOLD 12
#define FID_SET_DEBOUNCE_PERIOD 13
#define FID_GET_DEBOUNCE_PERIOD 14
#define FID_CURRENT 15
#define FID_ANALOG_VALUE 16
#define FID_CURRENT_REACHED 17
#define FID_ANALOG_VALUE_REACHED 18
#define FID_OVER_CURRENT 19

#define FID_LAST 19

typedef struct {
	MessageHeader header;
	bool value;
} __attribute__((__packed__)) BoolMessage;

typedef struct {
	MessageHeader header;
} __attribute__((__packed__)) StandardMessage;

void calibrate(void);
void is_over_current(const ComType com, const StandardMessage *sm);
int32_t analog_value_from_mc(const int32_t value);
int32_t current_from_analog_value(const int32_t value);

void invocation(const ComType com, const uint8_t *data);
void constructor(void);
void destructor(void);
void tick(const uint8_t tick_type);

#endif
