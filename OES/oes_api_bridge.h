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

 
#ifndef __OES_API_BRIDGE_H__
#define __OES_API_BRIDGW_H__

#include <oes_types>

/************************************************
 *  API functions
 ***********************************************/
/**
 * This function sets the log verbosity level of bridge MODULE
 * @param[in]  verbosity_level  - bridge  module verbosity level
 *
 * @return OES_STATUS_SUCCESS - Operation completes successfully
 * @return OES_STATUS_PARAM_ERROR - Unsupported verbosity_level
 * @return OES_STATUS_ERROR general error. 
 */
oes_status_e
oes_api_bridge_log_verbosity_level_set(
                                      int   verbosity_level
                                      );

/**
 * This function gets the log verbosity level of bridge MODULE
 * @param[out]  verbosity_level_p  bridge  module verbosity 
 *       level
 *  
 * @return OES_STATUS_SUCCESS - Operation completes successfully
 * @return OES_STATUS_PARAM_ERROR - Unsupported verbosity_level
 * @return OES_STATUS_ERROR general error. 
 */
oes_status_e
oes_api_bridge_log_verbosity_level_get(
                                      int   * verbosity_level_p
                                      );

/**
 * This function Adds/Deletes bridge.
 * @param[in] cmd - CREATE/DELETE. 
 * @param[in,out] br_id- bridge id  
 * @param[in,out] bridge_vs_ext- vendor specific extention 
 *  
 * @return OES_STATUS_SUCCESS - Operation completes successfully
 * @return OES_STATUS_PARAM_ERROR - Unsupported verbosity_level
 * @return OES_STATUS_ERROR general error. 
 */
oes_status_e
oes_api_bridge_set(
		          enum oes_access_cmd cmd,
                  int * br_id,
                  void * bridge_vs_ext 
                  );

 /**
 * This function retrives all  bridge active.
 * @param[out] br_id_list - arry of bridge ID .
 * @param[in,out] br_cnt  brigde arry size .
 * @param[in,out] bridge_vs_ext- vendor specific extention 
 * 
 * @return OES_STATUS_SUCCESS if operation completes successfully
 * @return OES_STATUS_PARAM_NULL: Pointer is NULL.
 * @return OES_STATUS_PARAM_EXCEEDS_RANGE: Parameters exceeds range.
 */

oes_status_e
oes_api_bridge_get(  
                  int br_id_list[],
                  unsigned short   br_cnt,
                  void * bridge_vs_ext 
		          );

/**
 * This function adds ports to a bridge 
 *  
 * @param[in] br_id - bridge id 
 * @param[in] log_port_list - List of ports.
 * @param[in] port_cnt- port list size 
 * @param[in,out] bridge_port_vs_ext- vendor specific extention 
 * 
 * @return OES_STATUS_SUCCESS if operation completes successfully
 * @return OES_STATUS_PARAM_NULL: Pointer is NULL.
 * @return OES_STATUS_PARAM_EXCEEDS_RANGE: Parameters exceeds range.
 */
oes_status_e
oes_api_bridge_port_set(
                       int br_id,
                       enum oes_access_cmd cmd,
                       unsigned long log_port_list[],
		               unsigned short  port_cnt,
                       void * bridge_port_vs_ext
                       );

/**
 * This function get  ports allocated to a bridge 
 *
 * @param[in] br_id bridge id 
 * @param[i/out] log_port_list - List of ports.
 * @param[in,out] port_cnt- port list size 
 * @param[in,out] bridge_port_vs_ext- vendor specific extention
 * 
 * @return OES_STATUS_SUCCESS if operation completes successfully
 * @return OES_STATUS_PARAM_NULL: Pointer is NULL.
 * @return OES_STATUS_PARAM_EXCEEDS_RANGE: Parameters exceeds range.
 */
oes_status_e
oes_api_bridge_port_get(
                       int br_id,
                       unsigned long log_port_list[],
		               unsigned short  port_cnt,
                       void * bridge_port_vs_ext
                       );
    


#endif /* __OES_API_BRIDGE_H__ */                                   
