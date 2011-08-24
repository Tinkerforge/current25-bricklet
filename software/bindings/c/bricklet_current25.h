/*************************************************************
 * This file was automatically generated on 23.08.2011.      *
 *                                                           *
 * If you have a bugfix for this file and want to commit it, *
 * please fix the bug in the generator. You can find a link  *
 * to the generator git on tinkerforge.com                   *
 *************************************************************/

#ifndef BRICKLET_CURRENT25_H
#define BRICKLET_CURRENT25_H

#include "ip_connection.h"

typedef Device Current25;

#define CURRENT25_CALLBACK_CURRENT 15
#define CURRENT25_CALLBACK_ANALOG_VALUE 16
#define CURRENT25_CALLBACK_CURRENT_REACHED 17
#define CURRENT25_CALLBACK_ANALOG_VALUE_REACHED 18
#define CURRENT25_CALLBACK_OVER_CURRENT 19

void current25_create(Current25 *current25, const char *uid);

int current25_get_current(Current25 *current25, int16_t *ret_current);
int current25_calibrate(Current25 *current25);
int current25_is_over_current(Current25 *current25, bool *ret_over);
int current25_get_analog_value(Current25 *current25, uint16_t *ret_value);
int current25_set_current_callback_period(Current25 *current25, uint32_t period);
int current25_get_current_callback_period(Current25 *current25, uint32_t *ret_period);
int current25_set_analog_value_callback_period(Current25 *current25, uint32_t period);
int current25_get_analog_value_callback_period(Current25 *current25, uint32_t *ret_period);
int current25_set_current_callback_threshold(Current25 *current25, char option, int16_t min, int16_t max);
int current25_get_current_callback_threshold(Current25 *current25, char *ret_option, int16_t *ret_min, int16_t *ret_max);
int current25_set_analog_value_callback_threshold(Current25 *current25, char option, uint16_t min, uint16_t max);
int current25_get_analog_value_callback_threshold(Current25 *current25, char *ret_option, uint16_t *ret_min, uint16_t *ret_max);
int current25_set_debounce_period(Current25 *current25, uint32_t debounce);
int current25_get_debounce_period(Current25 *current25, uint32_t *ret_debounce);
int current25_current(Current25 *current25, int16_t *ret_current);
int current25_analog_value(Current25 *current25, uint16_t *ret_value);
int current25_current_reached(Current25 *current25, int16_t *ret_current);
int current25_analog_value_reached(Current25 *current25, uint16_t *ret_value);
int current25_over_current(Current25 *current25);

void current25_register_callback(Current25 *current25, uint8_t cb, void *func);

#endif