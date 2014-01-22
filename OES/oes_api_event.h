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

#ifndef __OES_API_EVENT_H__
#define __OES_API_EVENT_H__

#include <oes_types.h>

/************************************************
 *  API functions
 ***********************************************/


/**
 * This function sets the log verbosity level of EVENT  MODULE
 * @param[in]  verbosity_level  - EVENT module verbosity level
 *
 * @return OES_STATUS_SUCCESS - Operation completes successfully
 * @return OES_STATUS_PARAM_ERROR - Unsupported verbosity_level
 * @return OES_STATUS_ERROR general error. 
 */
oes_status_e
oes_api_event_log_verbosity_level_set(
                                     const int   verbosity_level
                                     );

/**
 * This function gets the log verbosity level of EVENT MODULE
 * @param[out]  verbosity_level_p  - EVENT module verbosity 
 *       level
 *
 * @return OES_STATUS_SUCCESS - Operation completes successfully
 * @return OES_STATUS_PARAM_ERROR - Unsupported verbosity_level
 * @return OES_STATUS_ERROR general error. 
 */
oes_status_e
oes_api_event_log_verbosity_level_get(
                                     int   * verbosity_level_p
                                     );

/**
* This function retrieves the file descriptor of the current open channel
* used for receiving a event 
*  
* @param[in] access_cmd - CREATE/DESTROY
* @param[out] fd_p - file descriptor 
* @param[in,out] event_fd_vs_ext - vendor specific 
 *       extention 
*
* @return OES_STATUS_SUCCESS if operation completes successfully
* @return OES_STATUS_PARAM_ERROR if any input parameters invalid 
* @return OES_STATUS_ERROR general error
*/

oes_status_e
oes_api_event_fd_set(
                    const enum oes_access_cmd access_cmd,
                    int * fd_p,
                    void * event_fd_vs_ext
                    );


/**
* Register/DeRegister Events  (Port up /down , FDB event)
*
* @param[in] access_cmd - ADD/DELETE    - 
* @param[in] br_id - Bridge id 
* @param[in] event_id - Event ID.
* @param[in] fd - The file descriptor for the events to be send.
* @param[in,out] event_register_vs_ext - vendor specific
*       extention
* 
* @return OES_STATUS_SUCCESS if operation completes successfully
* @return OES_STATUS_PARAM_ERROR if any input parameters is 
*         invalid
* @return OES_STATUS_ERROR general error 
*/
oes_status_e
oes_api_event_register_set(
                          const enum oes_access_cmd access_cmd,
                          const int  br_id,
                          const enum oes_event event_id,
                          const int  fd,
                          void * event_register_vs_ext
                          );


/**
* This API enables the user to receive   Events. 
*
*@param[in] fd - File descriptor to listen on.
*@param[out]oes_event_info_p  - event information 
*@param[in,out] event_rcv_vs_ext - vendor specific
*       extention
*@return OES_STATUS_SUCCESS if operation completes successfully 
*@return OES_STATUS_PARAM_ERROR if any input parameters is 
*         invalid
*@return OES_STATUS_ERROR general error  
*/

oes_status_e
oes_api_event_recv(
                  const int  fd,            
                  struct oes_event_info * event_info_p,
                  void * event_recv_vs_ext
                  );

#endif /* __OES_API_EVENT_H__ */
