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

#ifndef __OES_API_LAG_H__
#define __OES_API_LAG_H__

#include <oes_types.h>

/************************************************
 *  API functions
 ***********************************************/
/**
 * This function sets the log verbosity level of LAG MODULE
 * @param[in]  verbosity_level  - LAG module verbosity level
 *
 * @return OES_STATUS_SUCCESS - Operation completes successfully
 * @return OES_STATUS_PARAM_ERROR - Unsupported verbosity_level
 * @return OES_STATUS_ERROR general error. 
 */
oes_status_e
oes_api_lag_log_verbosity_level_set(
                               const int   verbosity_level
                               );

/**
 * This function gets the log verbosity level of LAG MODULE
 * @param[out]  verbosity_level_p  - LAG module verbosity level
 *
 * @return OES_STATUS_SUCCESS - Operation completes successfully
 * @return OES_STATUS_PARAM_ERROR - Unsupported verbosity_level
 * @return OES_STATUS_ERROR general error. 
 */
oes_status_e
oes_api_lag_log_verbosity_level_get(
                                   int   * verbosity_level_p
                                   );


/**
 *  This function CREATEs/DESTROYs a new/existing LAG ports group in the SDK.
 *  Plus, it ADDs/DELETEs ports to/from an existing LAG ports group in the SDK.
 *
 *  Note:
 *  - All ports must be DELETEd from LAG ports group before the group is DESTROYed.
 *  - Cannot create a lag group and add ports to it in the same api call.
 * 
 * @param[in] access_cmd - CREATE/DESTROY/ADD/DELETE. 
 * @param[in] br_id - Bridge id  
 * @param[in,out] lag_port_p -	In: Already created LAG ports group ID.
 * 				Out: Newly created LAG ports group ID.
 * @param[in] log_port_list_p - List of Logical Ports to 
 *       ADD/DELETE to/from a LAG ports group.
 * @param[in] port_cnt - Number of Logical Ports to ADD/DELETE 
 *       to/from a LAG ports group.
 * @param[in,out] lag_port_group_vs_ext - vendor specific 
 *       extention
 * @return OES_STATUS_SUCCESS - Operation completes successfully.
 * @return OES_STATUS_PARAM_ERROR - Parameter is invalid.
 * @return OES_STATUS_ERROR general error.
 */
oes_status_e
oes_api_lag_port_group_set(
                          const enum oes_access_cmd access_cmd,
                          const int br_id,
                          unsigned long *lag_port_p,
                          const unsigned long  log_port_list_p,
                          const unsigned short     port_cnt,
                          void * lag_port_group_vs_ext
                          );

/**
 *  This function retrieves an existing LAG's ports group from the SDK.
 *  Note:
 *  If the output ports list is NULL, only the number of ports in the LAG's retrieved.
 *  
 * @param[in] access_cmd - CREATE/DESTROY/ADD/DELETE. 
 * @param[in] br_id - Bridge id  
 * @param[in] lag_port -	In: Already created LAG ports 
 *              group ID. Out: Newly created LAG ports group ID.
 * @param[out] log_port_list_p - List of Logical Ports to 
 *       ADD/DELETE to/from a LAG ports group.
 * @param[out] port_cnt_p - Number of Logical Ports to 
 *       ADD/DELETE to/from a LAG ports group.
 * @param[in,out] lag_port_group_vs_ext - vendor specific 
 *       extention
 *  
 * @return OES_STATUS_SUCCESS - Operation completes successfully.
 * @return OES_STATUS_PARAM_ERROR - Parameter is invalid.
 * @return OES_STATUS_ERROR general error.
 */
oes_status_e
oes_api_lag_port_group_get(
                          const enum oes_access_cmd access_cmd,
                          const int br_id,
                          const unsigned long  lag_port,
                          unsigned long  log_port_list_p,
                          unsigned short   * port_cnt_p,
                          void * lag_port_group_vs_ext
                          );

/**
 *  This function enables/disables collection on a specific LAG port.
 *
 * @param[in] br_id - Bridge id 
 * @param[in] lag_log_port - A logical port number representing
 *       the LAG ports group
 * @param[in] log_port - logical port number
 * @param[in] collector_mode collector mode
 * @param[in,out] lag_port_collector_vs_ext - vendor specific 
 *       extention
 * @return OES_STATUS_SUCCESS - Operation completes successfully.
 * @return OES_STATUS_PARAM_ERROR - Parameter is invalid.
 * @return OES_STATUS_ERROR general error.
 */

oes_status_e 
oes_api_lag_port_collector_set(
                              const int br_id,
	                          const unsigned long lag_log_port,
	                          const unsigned long log_port,
	                          const enum oes_collector_mode collector_mode,
                              void * lag_port_collector_vs_ext
                              );

/**
 *  This function enables/disables distribution on a specific LAG port.
 *
 * @param[in] br_id - Bridge id 
 * @param[in] lag_log_port - A logical port number representing
 *       the LAG ports group
 * @param[in] log_port - logical port number
 * @param[in]distributor _mode  distributor mode
 * @param[in,out] lag_port_collector_vs_ext - vendor specific 
 *       extention
 * @return OES_STATUS_SUCCESS - Operation completes successfully.
 * @return OES_STATUS_PARAM_ERROR - Parameter is invalid.
 * @return OES_STATUS_ERROR general error.
 */

oes_status_e 
oes_api_lag_port_distributor_set(
                                const int br_id,
	                            const unsigned long lag_log_port,
	                            const unsigned long log_port,
	                            const enum oes_collector_mode  distributor_mode,
                                void * lag_port_distributor_vs_ext
                                );

/**
 *  This function configures the flow indicators that impact the
 *  LAG hash distribution function.
 *  @param[in] br_id - Bridge id
 *  @param[in] oes_lag_hash_param_p - Hash parameters
 *  @param[in,out] lag_hash_vs_ext - vendor specific 
 *       extention
 * @return OES_STATUS_SUCCESS - Operation completes successfully.
 * @return OES_STATUS_PARAM_ERROR - Parameter is invalid.
 * @return OES_STATUS_ERROR general error.
 */
oes_status_e 
oes_api_lag_hash_set(
                    const int br_id, 
			        const struct eos_lag_hash_param * lag_hash_param_p,
                    void * lag_hash_vs_ext
                    );




/**
 *  This function retrieves the flow indicators that impact the
 *  LAG hash distribution function.
 *  @param[in] br_id - Bridge id
 *  @param[out] oes_lag_hash_param_p - Hash parameters
 *  @param[in,out] lag_hash_vs_ext - vendor specific 
 *       extention
 * @return OES_STATUS_SUCCESS - Operation completes successfully.
 * @return OES_STATUS_PARAM_ERROR - Parameter is invalid.
 * @return OES_STATUS_ERROR general error.
 */
oes_status_e 
oes_api_lag_hash_get(
                    const int br_id, 
                    struct oes_lag_hash_param * lag_hash_param_p,
                    void * lag_hash_vs_ext
                    );


#endif /* __OES_API_LAG_H__ */
