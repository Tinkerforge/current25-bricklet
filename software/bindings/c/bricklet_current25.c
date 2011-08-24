/*************************************************************
 * This file was automatically generated on 2011-08-23.      *
 *                                                           *
 * If you have a bugfix for this file and want to commit it, *
 * please fix the bug in the generator. You can find a link  *
 * to the generator git on tinkerforge.com                   *
 *************************************************************/

#include "bricklet_current25.h"

#include <string.h>

#define TYPE_GET_CURRENT 1
#define TYPE_CALIBRATE 2
#define TYPE_IS_OVER_CURRENT 3
#define TYPE_GET_ANALOG_VALUE 4
#define TYPE_SET_CURRENT_CALLBACK_PERIOD 5
#define TYPE_GET_CURRENT_CALLBACK_PERIOD 6
#define TYPE_SET_ANALOG_VALUE_CALLBACK_PERIOD 7
#define TYPE_GET_ANALOG_VALUE_CALLBACK_PERIOD 8
#define TYPE_SET_CURRENT_CALLBACK_THRESHOLD 9
#define TYPE_GET_CURRENT_CALLBACK_THRESHOLD 10
#define TYPE_SET_ANALOG_VALUE_CALLBACK_THRESHOLD 11
#define TYPE_GET_ANALOG_VALUE_CALLBACK_THRESHOLD 12
#define TYPE_SET_DEBOUNCE_PERIOD 13
#define TYPE_GET_DEBOUNCE_PERIOD 14
#define TYPE_CURRENT 15
#define TYPE_ANALOG_VALUE 16
#define TYPE_CURRENT_REACHED 17
#define TYPE_ANALOG_VALUE_REACHED 18
#define TYPE_OVER_CURRENT 19

typedef void (*current_func_t)(int16_t);
typedef void (*analog_value_func_t)(uint16_t);
typedef void (*current_reached_func_t)(int16_t);
typedef void (*analog_value_reached_func_t)(uint16_t);
typedef void (*over_current_func_t)();

#ifdef _MSC_VER
	#pragma pack(push)
	#pragma pack(1)

	#define PACKED
#else
	#define PACKED __attribute__((packed))
#endif

typedef struct {
	uint8_t stack_id;
	uint8_t type;
	uint16_t length;
} PACKED GetCurrent;

typedef struct {
	uint8_t stack_id;
	uint8_t type;
	uint16_t length;
	int16_t current;
} PACKED GetCurrentReturn;

typedef struct {
	uint8_t stack_id;
	uint8_t type;
	uint16_t length;
} PACKED Calibrate;

typedef struct {
	uint8_t stack_id;
	uint8_t type;
	uint16_t length;
} PACKED IsOverCurrent;

typedef struct {
	uint8_t stack_id;
	uint8_t type;
	uint16_t length;
	bool over;
} PACKED IsOverCurrentReturn;

typedef struct {
	uint8_t stack_id;
	uint8_t type;
	uint16_t length;
} PACKED GetAnalogValue;

typedef struct {
	uint8_t stack_id;
	uint8_t type;
	uint16_t length;
	uint16_t value;
} PACKED GetAnalogValueReturn;

typedef struct {
	uint8_t stack_id;
	uint8_t type;
	uint16_t length;
	uint32_t period;
} PACKED SetCurrentCallbackPeriod;

typedef struct {
	uint8_t stack_id;
	uint8_t type;
	uint16_t length;
} PACKED GetCurrentCallbackPeriod;

typedef struct {
	uint8_t stack_id;
	uint8_t type;
	uint16_t length;
	uint32_t period;
} PACKED GetCurrentCallbackPeriodReturn;

typedef struct {
	uint8_t stack_id;
	uint8_t type;
	uint16_t length;
	uint32_t period;
} PACKED SetAnalogValueCallbackPeriod;

typedef struct {
	uint8_t stack_id;
	uint8_t type;
	uint16_t length;
} PACKED GetAnalogValueCallbackPeriod;

typedef struct {
	uint8_t stack_id;
	uint8_t type;
	uint16_t length;
	uint32_t period;
} PACKED GetAnalogValueCallbackPeriodReturn;

typedef struct {
	uint8_t stack_id;
	uint8_t type;
	uint16_t length;
	char option;
	int16_t min;
	int16_t max;
} PACKED SetCurrentCallbackThreshold;

typedef struct {
	uint8_t stack_id;
	uint8_t type;
	uint16_t length;
} PACKED GetCurrentCallbackThreshold;

typedef struct {
	uint8_t stack_id;
	uint8_t type;
	uint16_t length;
	char option;
	int16_t min;
	int16_t max;
} PACKED GetCurrentCallbackThresholdReturn;

typedef struct {
	uint8_t stack_id;
	uint8_t type;
	uint16_t length;
	char option;
	uint16_t min;
	uint16_t max;
} PACKED SetAnalogValueCallbackThreshold;

typedef struct {
	uint8_t stack_id;
	uint8_t type;
	uint16_t length;
} PACKED GetAnalogValueCallbackThreshold;

typedef struct {
	uint8_t stack_id;
	uint8_t type;
	uint16_t length;
	char option;
	uint16_t min;
	uint16_t max;
} PACKED GetAnalogValueCallbackThresholdReturn;

typedef struct {
	uint8_t stack_id;
	uint8_t type;
	uint16_t length;
	uint32_t debounce;
} PACKED SetDebouncePeriod;

typedef struct {
	uint8_t stack_id;
	uint8_t type;
	uint16_t length;
} PACKED GetDebouncePeriod;

typedef struct {
	uint8_t stack_id;
	uint8_t type;
	uint16_t length;
	uint32_t debounce;
} PACKED GetDebouncePeriodReturn;

typedef struct {
	uint8_t stack_id;
	uint8_t type;
	uint16_t length;
	int16_t current;
} PACKED CurrentCallback;

typedef struct {
	uint8_t stack_id;
	uint8_t type;
	uint16_t length;
	uint16_t value;
} PACKED AnalogValueCallback;

typedef struct {
	uint8_t stack_id;
	uint8_t type;
	uint16_t length;
	int16_t current;
} PACKED CurrentReachedCallback;

typedef struct {
	uint8_t stack_id;
	uint8_t type;
	uint16_t length;
	uint16_t value;
} PACKED AnalogValueReachedCallback;

typedef struct {
	uint8_t stack_id;
	uint8_t type;
	uint16_t length;
} PACKED OverCurrentCallback;

#ifdef _MSC_VER
	#pragma pack(pop)
#endif

int current25_get_current(Current25 *current25, int16_t *ret_current) {
	if(current25->ipcon == NULL) {
		return E_NOT_ADDED;
	}

	ipcon_sem_wait_write(current25);

	current25->answer.type = TYPE_GET_CURRENT;
	current25->answer.length = sizeof(GetCurrentReturn);
	GetCurrent gc;
	gc.stack_id = current25->stack_id;
	gc.type = TYPE_GET_CURRENT;
	gc.length = sizeof(GetCurrent);

	ipcon_device_write(current25, (char *)&gc, sizeof(GetCurrent));

	if(ipcon_answer_sem_wait_timeout(current25) != 0) {
		ipcon_sem_post_write(current25);
		return E_TIMEOUT;
	}

	GetCurrentReturn *gcr = (GetCurrentReturn *)current25->answer.buffer;
	*ret_current = gcr->current;

	ipcon_sem_post_write(current25);

	return E_OK;
}

int current25_calibrate(Current25 *current25) {
	if(current25->ipcon == NULL) {
		return E_NOT_ADDED;
	}

	ipcon_sem_wait_write(current25);

	Calibrate c;
	c.stack_id = current25->stack_id;
	c.type = TYPE_CALIBRATE;
	c.length = sizeof(Calibrate);

	ipcon_device_write(current25, (char *)&c, sizeof(Calibrate));

	ipcon_sem_post_write(current25);

	return E_OK;
}

int current25_is_over_current(Current25 *current25, bool *ret_over) {
	if(current25->ipcon == NULL) {
		return E_NOT_ADDED;
	}

	ipcon_sem_wait_write(current25);

	current25->answer.type = TYPE_IS_OVER_CURRENT;
	current25->answer.length = sizeof(IsOverCurrentReturn);
	IsOverCurrent ioc;
	ioc.stack_id = current25->stack_id;
	ioc.type = TYPE_IS_OVER_CURRENT;
	ioc.length = sizeof(IsOverCurrent);

	ipcon_device_write(current25, (char *)&ioc, sizeof(IsOverCurrent));

	if(ipcon_answer_sem_wait_timeout(current25) != 0) {
		ipcon_sem_post_write(current25);
		return E_TIMEOUT;
	}

	IsOverCurrentReturn *iocr = (IsOverCurrentReturn *)current25->answer.buffer;
	*ret_over = iocr->over;

	ipcon_sem_post_write(current25);

	return E_OK;
}

int current25_get_analog_value(Current25 *current25, uint16_t *ret_value) {
	if(current25->ipcon == NULL) {
		return E_NOT_ADDED;
	}

	ipcon_sem_wait_write(current25);

	current25->answer.type = TYPE_GET_ANALOG_VALUE;
	current25->answer.length = sizeof(GetAnalogValueReturn);
	GetAnalogValue gav;
	gav.stack_id = current25->stack_id;
	gav.type = TYPE_GET_ANALOG_VALUE;
	gav.length = sizeof(GetAnalogValue);

	ipcon_device_write(current25, (char *)&gav, sizeof(GetAnalogValue));

	if(ipcon_answer_sem_wait_timeout(current25) != 0) {
		ipcon_sem_post_write(current25);
		return E_TIMEOUT;
	}

	GetAnalogValueReturn *gavr = (GetAnalogValueReturn *)current25->answer.buffer;
	*ret_value = gavr->value;

	ipcon_sem_post_write(current25);

	return E_OK;
}

int current25_set_current_callback_period(Current25 *current25, uint32_t period) {
	if(current25->ipcon == NULL) {
		return E_NOT_ADDED;
	}

	ipcon_sem_wait_write(current25);

	SetCurrentCallbackPeriod sccp;
	sccp.stack_id = current25->stack_id;
	sccp.type = TYPE_SET_CURRENT_CALLBACK_PERIOD;
	sccp.length = sizeof(SetCurrentCallbackPeriod);
	sccp.period = period;

	ipcon_device_write(current25, (char *)&sccp, sizeof(SetCurrentCallbackPeriod));

	ipcon_sem_post_write(current25);

	return E_OK;
}

int current25_get_current_callback_period(Current25 *current25, uint32_t *ret_period) {
	if(current25->ipcon == NULL) {
		return E_NOT_ADDED;
	}

	ipcon_sem_wait_write(current25);

	current25->answer.type = TYPE_GET_CURRENT_CALLBACK_PERIOD;
	current25->answer.length = sizeof(GetCurrentCallbackPeriodReturn);
	GetCurrentCallbackPeriod gccp;
	gccp.stack_id = current25->stack_id;
	gccp.type = TYPE_GET_CURRENT_CALLBACK_PERIOD;
	gccp.length = sizeof(GetCurrentCallbackPeriod);

	ipcon_device_write(current25, (char *)&gccp, sizeof(GetCurrentCallbackPeriod));

	if(ipcon_answer_sem_wait_timeout(current25) != 0) {
		ipcon_sem_post_write(current25);
		return E_TIMEOUT;
	}

	GetCurrentCallbackPeriodReturn *gccpr = (GetCurrentCallbackPeriodReturn *)current25->answer.buffer;
	*ret_period = gccpr->period;

	ipcon_sem_post_write(current25);

	return E_OK;
}

int current25_set_analog_value_callback_period(Current25 *current25, uint32_t period) {
	if(current25->ipcon == NULL) {
		return E_NOT_ADDED;
	}

	ipcon_sem_wait_write(current25);

	SetAnalogValueCallbackPeriod savcp;
	savcp.stack_id = current25->stack_id;
	savcp.type = TYPE_SET_ANALOG_VALUE_CALLBACK_PERIOD;
	savcp.length = sizeof(SetAnalogValueCallbackPeriod);
	savcp.period = period;

	ipcon_device_write(current25, (char *)&savcp, sizeof(SetAnalogValueCallbackPeriod));

	ipcon_sem_post_write(current25);

	return E_OK;
}

int current25_get_analog_value_callback_period(Current25 *current25, uint32_t *ret_period) {
	if(current25->ipcon == NULL) {
		return E_NOT_ADDED;
	}

	ipcon_sem_wait_write(current25);

	current25->answer.type = TYPE_GET_ANALOG_VALUE_CALLBACK_PERIOD;
	current25->answer.length = sizeof(GetAnalogValueCallbackPeriodReturn);
	GetAnalogValueCallbackPeriod gavcp;
	gavcp.stack_id = current25->stack_id;
	gavcp.type = TYPE_GET_ANALOG_VALUE_CALLBACK_PERIOD;
	gavcp.length = sizeof(GetAnalogValueCallbackPeriod);

	ipcon_device_write(current25, (char *)&gavcp, sizeof(GetAnalogValueCallbackPeriod));

	if(ipcon_answer_sem_wait_timeout(current25) != 0) {
		ipcon_sem_post_write(current25);
		return E_TIMEOUT;
	}

	GetAnalogValueCallbackPeriodReturn *gavcpr = (GetAnalogValueCallbackPeriodReturn *)current25->answer.buffer;
	*ret_period = gavcpr->period;

	ipcon_sem_post_write(current25);

	return E_OK;
}

int current25_set_current_callback_threshold(Current25 *current25, char option, int16_t min, int16_t max) {
	if(current25->ipcon == NULL) {
		return E_NOT_ADDED;
	}

	ipcon_sem_wait_write(current25);

	SetCurrentCallbackThreshold scct;
	scct.stack_id = current25->stack_id;
	scct.type = TYPE_SET_CURRENT_CALLBACK_THRESHOLD;
	scct.length = sizeof(SetCurrentCallbackThreshold);
	scct.option = option;
	scct.min = min;
	scct.max = max;

	ipcon_device_write(current25, (char *)&scct, sizeof(SetCurrentCallbackThreshold));

	ipcon_sem_post_write(current25);

	return E_OK;
}

int current25_get_current_callback_threshold(Current25 *current25, char *ret_option, int16_t *ret_min, int16_t *ret_max) {
	if(current25->ipcon == NULL) {
		return E_NOT_ADDED;
	}

	ipcon_sem_wait_write(current25);

	current25->answer.type = TYPE_GET_CURRENT_CALLBACK_THRESHOLD;
	current25->answer.length = sizeof(GetCurrentCallbackThresholdReturn);
	GetCurrentCallbackThreshold gcct;
	gcct.stack_id = current25->stack_id;
	gcct.type = TYPE_GET_CURRENT_CALLBACK_THRESHOLD;
	gcct.length = sizeof(GetCurrentCallbackThreshold);

	ipcon_device_write(current25, (char *)&gcct, sizeof(GetCurrentCallbackThreshold));

	if(ipcon_answer_sem_wait_timeout(current25) != 0) {
		ipcon_sem_post_write(current25);
		return E_TIMEOUT;
	}

	GetCurrentCallbackThresholdReturn *gcctr = (GetCurrentCallbackThresholdReturn *)current25->answer.buffer;
	*ret_option = gcctr->option;
	*ret_min = gcctr->min;
	*ret_max = gcctr->max;

	ipcon_sem_post_write(current25);

	return E_OK;
}

int current25_set_analog_value_callback_threshold(Current25 *current25, char option, uint16_t min, uint16_t max) {
	if(current25->ipcon == NULL) {
		return E_NOT_ADDED;
	}

	ipcon_sem_wait_write(current25);

	SetAnalogValueCallbackThreshold savct;
	savct.stack_id = current25->stack_id;
	savct.type = TYPE_SET_ANALOG_VALUE_CALLBACK_THRESHOLD;
	savct.length = sizeof(SetAnalogValueCallbackThreshold);
	savct.option = option;
	savct.min = min;
	savct.max = max;

	ipcon_device_write(current25, (char *)&savct, sizeof(SetAnalogValueCallbackThreshold));

	ipcon_sem_post_write(current25);

	return E_OK;
}

int current25_get_analog_value_callback_threshold(Current25 *current25, char *ret_option, uint16_t *ret_min, uint16_t *ret_max) {
	if(current25->ipcon == NULL) {
		return E_NOT_ADDED;
	}

	ipcon_sem_wait_write(current25);

	current25->answer.type = TYPE_GET_ANALOG_VALUE_CALLBACK_THRESHOLD;
	current25->answer.length = sizeof(GetAnalogValueCallbackThresholdReturn);
	GetAnalogValueCallbackThreshold gavct;
	gavct.stack_id = current25->stack_id;
	gavct.type = TYPE_GET_ANALOG_VALUE_CALLBACK_THRESHOLD;
	gavct.length = sizeof(GetAnalogValueCallbackThreshold);

	ipcon_device_write(current25, (char *)&gavct, sizeof(GetAnalogValueCallbackThreshold));

	if(ipcon_answer_sem_wait_timeout(current25) != 0) {
		ipcon_sem_post_write(current25);
		return E_TIMEOUT;
	}

	GetAnalogValueCallbackThresholdReturn *gavctr = (GetAnalogValueCallbackThresholdReturn *)current25->answer.buffer;
	*ret_option = gavctr->option;
	*ret_min = gavctr->min;
	*ret_max = gavctr->max;

	ipcon_sem_post_write(current25);

	return E_OK;
}

int current25_set_debounce_period(Current25 *current25, uint32_t debounce) {
	if(current25->ipcon == NULL) {
		return E_NOT_ADDED;
	}

	ipcon_sem_wait_write(current25);

	SetDebouncePeriod sdp;
	sdp.stack_id = current25->stack_id;
	sdp.type = TYPE_SET_DEBOUNCE_PERIOD;
	sdp.length = sizeof(SetDebouncePeriod);
	sdp.debounce = debounce;

	ipcon_device_write(current25, (char *)&sdp, sizeof(SetDebouncePeriod));

	ipcon_sem_post_write(current25);

	return E_OK;
}

int current25_get_debounce_period(Current25 *current25, uint32_t *ret_debounce) {
	if(current25->ipcon == NULL) {
		return E_NOT_ADDED;
	}

	ipcon_sem_wait_write(current25);

	current25->answer.type = TYPE_GET_DEBOUNCE_PERIOD;
	current25->answer.length = sizeof(GetDebouncePeriodReturn);
	GetDebouncePeriod gdp;
	gdp.stack_id = current25->stack_id;
	gdp.type = TYPE_GET_DEBOUNCE_PERIOD;
	gdp.length = sizeof(GetDebouncePeriod);

	ipcon_device_write(current25, (char *)&gdp, sizeof(GetDebouncePeriod));

	if(ipcon_answer_sem_wait_timeout(current25) != 0) {
		ipcon_sem_post_write(current25);
		return E_TIMEOUT;
	}

	GetDebouncePeriodReturn *gdpr = (GetDebouncePeriodReturn *)current25->answer.buffer;
	*ret_debounce = gdpr->debounce;

	ipcon_sem_post_write(current25);

	return E_OK;
}

int current25_callback_current(Current25 *current25, const unsigned char *buffer) {
	CurrentCallback *cc = (CurrentCallback *)buffer;
	((current_func_t)current25->callbacks[cc->type])(cc->current);
	return sizeof(CurrentCallback);
}

int current25_callback_analog_value(Current25 *current25, const unsigned char *buffer) {
	AnalogValueCallback *avc = (AnalogValueCallback *)buffer;
	((analog_value_func_t)current25->callbacks[avc->type])(avc->value);
	return sizeof(AnalogValueCallback);
}

int current25_callback_current_reached(Current25 *current25, const unsigned char *buffer) {
	CurrentReachedCallback *crc = (CurrentReachedCallback *)buffer;
	((current_reached_func_t)current25->callbacks[crc->type])(crc->current);
	return sizeof(CurrentReachedCallback);
}

int current25_callback_analog_value_reached(Current25 *current25, const unsigned char *buffer) {
	AnalogValueReachedCallback *avrc = (AnalogValueReachedCallback *)buffer;
	((analog_value_reached_func_t)current25->callbacks[avrc->type])(avrc->value);
	return sizeof(AnalogValueReachedCallback);
}

int current25_callback_over_current(Current25 *current25, const unsigned char *buffer) {
	OverCurrentCallback *occ = (OverCurrentCallback *)buffer;
	((over_current_func_t)current25->callbacks[occ->type])();
	return sizeof(OverCurrentCallback);
}

void current25_register_callback(Current25 *current25, uint8_t cb, void *func) {
    current25->callbacks[cb] = func;
}

void current25_create(Current25 *current25, const char *uid) {
	ipcon_device_create(current25, uid);

	current25->device_callbacks[TYPE_CURRENT] = current25_callback_current;
	current25->device_callbacks[TYPE_ANALOG_VALUE] = current25_callback_analog_value;
	current25->device_callbacks[TYPE_CURRENT_REACHED] = current25_callback_current_reached;
	current25->device_callbacks[TYPE_ANALOG_VALUE_REACHED] = current25_callback_analog_value_reached;
	current25->device_callbacks[TYPE_OVER_CURRENT] = current25_callback_over_current;
}
