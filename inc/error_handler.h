#ifndef _ERROR_HANDLER_H
#define _ERROR_HANDLER_H

#include <stdint.h>
#include <stdbool.h>


typedef enum error {
    ERROR_LTC6804_PEC,
    EEPROM_ERROR,
    ERROR_INVALID_SSM_STATE,
    ERROR_CONTACTORS_ERRONEOUS_STATE,
    ERROR_CELL_UNDER_VOLTAGE,
    ERROR_CELL_OVER_VOLTAGE,
    ERROR_CELL_OVER_TEMP,
    ERROR_OVER_CURRENT,
    ERROR_NUM_ERRORS
} ERROR_T;

typedef enum error_handler_status {
	HANDLER_FINE,
	HANDLER_HALT
} ERROR_HANDLER_STATUS_T;

typedef struct error_status {
	bool 		handling;
	bool		error;
	uint16_t 	count;
	uint32_t 	time_stamp;
} ERROR_STATUS_T;

typedef  ERROR_HANDLER_STATUS_T (*ERROR_HANDLER)(const char * const *);

void assert_error(ERROR_T er_t, uint32_t msTicks);
void pass_error(ERROR_T er_t, uint32_t msTicks);
ERROR_HANDLER_STATUS_T handle_errors(void);


#endif