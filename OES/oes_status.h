/* This software is available to you under a choice of one of two
* licenses.  You may choose to be licensed under the terms of the GNU
* General Public License (GPL) Version 2, available from the file
* COPYING, or the Open Ethernet BSD license below:
*
*     Redistribution and use in source and binary forms, with or
*     without modification, are permitted provided that the following
*     conditions are met:
*
*      - Redistributions of source code must retain the above
*        copyright notice, this list of conditions and the following
*        disclaimer.
*
*      - Redistributions in binary form must reproduce the above
*        copyright notice, this list of conditions and the following
*        disclaimer in the documentation and/or other materials
*        provided with the distribution.
*
* THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
* EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
* MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
* NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS
* BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN
* ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
* CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
* SOFTWARE. 
*/

#ifndef __HAL_STATUS_H__
#define __HAL_STATUS_H__



/************************************************
 *  Type definitions
 ***********************************************/

/**
 * sx_status_t
 * Enumerated type - Provides functions' return values.
 */
typedef enum hal_status {
	HAL_STATUS_SUCCESS				= 0,
	HAL_STATUS_ERROR					= 1,
    HAL_STATUS_CMD_UNSUPPORTED				= 8,
    HAL_STATUS_PARAM_ERROR				= 13,
    HAL_STATUS_PARAM_EXCEEDS_RANGE			= 14,
    HAL_STATUS_NO_MEMORY				= 6,
	HAL_STATUS_HAL_NOT_INITIALIZED			= 2,
	HAL_STATUS_ENTRY_NOT_FOUND			= 21,
	HAL_STATUS_ENTRY_ALREADY_EXISTS			= 22,
	
	HAL_STATUS_MIN   				= HAL_STATUS_SUCCESS,
	HAL_STATUS_MAX   				= 
} hal_status_e;



#endif /* __SX_STATUS_H__ */
