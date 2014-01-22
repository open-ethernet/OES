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

#ifndef __OES_API_COS_H__
#define __OES_API_COS_H__

#include <oes_types.h>


/************************************************
 *  API functions
 ***********************************************/


/************************************************
 *  API functions
 ***********************************************/
/**
 * This function sets the log verbosity level of cos MODULE
 * @param[in]  verbosity_level  - cos module verbosity level
 *
 * @return OES_STATUS_SUCCESS - Operation completes successfully
 * @return OES_STATUS_PARAM_ERROR - Unsupported verbosity_level
 * @return OES_STATUS_ERROR general error. 
 */
oes_status_e
oes_api_cos_log_verbosity_level_set(
                                   const int   verbosity_level
                                   );

/**
 * This function gets the log verbosity level of cos MODULE
 * @param[out]  verbosity_level_p  - cos module verbosity level
 *
 * @return OES_STATUS_SUCCESS - Operation completes successfully
 * @return OES_STATUS_PARAM_ERROR - Unsupported verbosity_level
 * @return OES_STATUS_ERROR general error. 
 */
oes_status_e
oes_api_cos_log_verbosity_level_get(
                                   int   * verbosity_level_p
                                   );



/**
 * This function sets the port default priority value.
 * Packet which arrives to 'log_port' port without a priority
 * will be handled according to 'port_priority' value. 
 *  
 * @param[in] br_id - Bridge id
 * @param[in] log_port - Logical Port ID
 * @param[in] priority - port priority [0..7 , default is 0]
 * @param[in,out] cos_port_default_vs_ext - vendor specific 
 *       extention
 * 
 * @return OES_STATUS_SUCCESS if operation completes successfully
 * @return OES_STATUS_PARAM_ERROR: Input parameters error. 
 * @return OES_STATUS_ERROR general error. 
 */
oes_status_e
oes_api_cos_port_default_prio_set(
                                 const int br_id,
                                 const unsigned int log_port,
                                 const unsigned char priority
                                 void * cos_port_default_vs_ext;
                                 );


/**
 * This function get the port default priority value.
 *  
 * @param[in] br_id - Bridge id
 * @param[in] log_port - Logical Port ID
 * @param[out] priority_p - port priority [0..7 , default is 0]
 * @param[in,out] cos_port_default_vs_ext - vendor specific 
 *       extention
 * 
 * @return OES_STATUS_SUCCESS if operation completes successfully
 * @return OES_STATUS_PARAM_ERROR: Input parameters error. 
 * @return OES_STATUS_ERROR general error. 
 */
oes_status_e
oes_api_cos_port_default_prio_get(
                                 const int br_id,
                                 const unsigned int log_port,
                                 unsigned char * priority_p,
                                 void * cos_port_default_vs_ext
                                 );

/**
 * This function sets the port ingress priority map values.
 * Packet which arrives to 'log_port' with 'source_priority' priority
 * Will be handled according to 'mapped_priority' priority
 *
 * @param[in] br_id - Bridge id
 * @param[in] log_port - Logical Port ID
 * @param[in] orig_priority - original priority [0..7]
 * @param[in] regen_priority - regenerated priority [0..7]
 * @param[in,out] cos_port_prio_regen_vs_ext - vendor specific 
 *       extention
 *  
 * @return OES_STATUS_SUCCESS if operation completes successfully
 * @return OES_STATUS_PARAM_ERROR: Input parameters error. 
 * @return OES_STATUS_ERROR general error. 
 */
oes_status_e
oes_api_cos_port_prio_regen_set(
                               const int br_id,
                               const unsigned int log_port,
                               const unsigned char orig_priority,
                               const unsigned char regen_priority,
                               void * cos_port_prio_regen_vs_ext
                               );


/**
 * This function retrieves the port ingress priority regen 
 * values. 
 *
 * @param[in] br_id - Bridge id
 * @param[in] log_port - Logical Port ID
 * @param[in] orig_priority - original priority [0..7]
 * @param[out] regen_priority_p - regenerated priority [0..7]
 * @param[in,out] cos_port_prio_regen_vs_ext - vendor specific 
 *       extention
 *  
 * @return OES_STATUS_SUCCESS if operation completes successfully
 * @return OES_STATUS_PARAM_ERROR: Input parameters error. 
 * @return OES_STATUS_ERROR general error. 
 */
oes_status_e
oes_api_cos_port_prio_regen_set(
                               const int br_id,
                               const unsigned int log_port,
                               const unsigned char orig_priority,
                               unsigned char * regen_priority_p,
                               void * cos_port_prio_regen_vs_ext
                               );

/**
 *  This function adds or deletes a priority from a Traffic
 *  Class. When a priority is added to a TC , it is automatically
 *  re-mapped from its previous allocation. 
 *  Each packet has an assign priority. The priority of the packet
 *  is mapped to one of eight traffic classes
 * (egress queue) according to prio -> traffic class map
 *  Each packet is dequeued on the egress port based on its
 *  traffic class
 *  
 * @param[in] access_cmd    - Add/ Delete
 * @param[in] br_id - Bridge id 
 * @param[in] log_port - Logical Port ID
 * @param[in] priority      - priority
 * @param[in] traffic_class - traffic class 
 * @param[in,out] cos_port_tc_prio_map_vs_ext - vendor specific 
 *       extention
 *  
 * @return OES_STATUS_SUCCESS if operation completes successfully
 * @return OES_STATUS_PARAM_ERROR: Input parameters error. 
 * @return OES_STATUS_ERROR general error. 
 */
oes_status_e
oes_api_cos_port_tc_prio_map_set(
                                const enum oes_access_cmd access_cmd,
                                const int br_id,

                                const unsigned int log_port,
                                const unsigned char priority,
                                const unsigned char traffic_class,
                                void * cos_port_tc_prio_map_vs_ext
                                );
/**
 *  This function retrieves the Traffic class of a specific
 *  priority.
 *  
 * @param[in] br_id - Bridge id
 * @param[in] log_port - Logical Port ID 
 * @param[in] priority      - priority
 * @param[out] traffic_class_p - traffic class 
 * @param[in,out] cos_port_tc_prio_map_vs_ext - vendor specific 
 *       extention
 *  
 * @return OES_STATUS_SUCCESS if operation completes successfully
 * @return OES_STATUS_PARAM_ERROR: Input parameters error. 
 * @return OES_STATUS_ERROR general error. 
 */
oes_status_e
oes_api_cos_port_tc_prio_map_get(
                                const int br_id,
                                const unsigned int log_port,
                                const unsigned char priority,
                                unsigned char * traffic_class_p,
                                void * cos_port_tc_prio_map_vs_ext
                                );


/**
 * This function sets the port trust level value. 
 * Trust port user priority - ignore packets priority and assign
 * priority based on the port configuration Trust packet user p 
 * Trust PCP - tagged L2 packets are assigned with packets 
 * priority, untagged packets are assigned with port's priority
 * Trust DSCP - IP packets are assigned with a priority based on
 * the DSCP to UP mapping, Non IP packets are assigned with
 * port's priority 
 * Trust both - IP packets are assigned with a priority based on 
 * the DSCP to UP mapping, else tagged L2 packets are assigned 
 * with packets priority, untagged packets are assigned with 
 * port's priority 
 *
 * @param[in] br_id - Bridge id
 * @param[in] log_port - logical port id
 * @param[in] trust_level - trust level  [0 - trust port user priority,
 *                                        1 - trust PCP ,
 *                                        2 - trust DSCP ,
 *                                        3 - trust both]
 * @param[in,out] cos_port_tc_port_trust_vs_ext  - vendor 
 *       specific extention
 *  
 * @return OES_STATUS_SUCCESS if operation completes successfully
 * @return OES_STATUS_PARAM_ERROR: Input parameters error. 
 * @return OES_STATUS_ERROR general error. 
 */
oes_status_e
oes_api_cos_port_trust_set(
                          const  int br_id,
                          const unsigned int log_port,
                          const enum oes_cos_trust_leve trust_level,
                          void * cos_port_tc_port_trust_vs_ext
                          );

/**
 * This function get the port trust level value. 
 *  
 * @param[in] br_id - Bridge id
 * @param[in] log_port - logical port id
 * @param[out] trust_level_p - trust level  
 * @param[in,out] cos_port_tc_port_trust_vs_ext  - vendor 
 *       specific extention
 *  
 * @return OES_STATUS_SUCCESS if operation completes successfully
 * @return OES_STATUS_PARAM_ERROR: Input parameters error. 
 * @return OES_STATUS_ERROR general error. 
 */
oes_status_e
oes_api_cos_port_trust_get(
                          const int br_id,
                          const unsigned int log_port,
                          enum oes_cos_trust_level * trust_level_p,
                          void * cos_port_tc_port_trust_vs_ext
                          );




/**
 * This function sets the map between dscp and port priority.
 * This table is used when the port trust mode is set to 'trust DSCP'
 *
 * @param[in] br_id - Bridge id
 * @param[in] log_port - logical port id
 * @param[in] priority  priority 
 * @param[in] dscp - ip packet DSCP fied value  
 * @param[in,out] cos_port_cos_dscp_to_prio_vs_ext - vendor 
 *       specific extention
 *
 * @return OES_STATUS_SUCCESS if operation completes 
 *         successfully
 * @return OES_STATUS_PARAM_ERROR: Input parameters error. 
 * @return OES_STATUS_ERROR general error. 
 */
oes_status_e
oes_api_cos_dscp_to_prio_set(
                            const int br_id,
                            const unsigned char priority,
                            const unsigned char dscp,
                            void * cos_port_cos_dscp_to_prio_vs_ext
                            );


/**
 * This function get the map between DSCP and priority T DSCP' 
 *
 * @param[in] br_id - Bridge id
 * @param[in] log_port - logical port id
 * @param[in] priority  priority 
 * @param[out] dscp_p - ip packet DSCP fied value  
 * @param[in,out] cos_port_cos_dscp_to_prio_vs_ext - vendor 
 *       specific extention
 *
 * @return OES_STATUS_SUCCESS if operation completes 
 *         successfully
 * @return OES_STATUS_PARAM_ERROR: Input parameters error. 
 * @return OES_STATUS_ERROR general error. 
 */
oes_status_e
oes_api_cos_dscp_to_prio_get(
                            const int br_id,
                            const unsigned char priority,
                            unsigned char * dscp_p,
                            void * cos_port_cos_dscp_to_prio_vs_ext
                            );




/**
 * This function sets the  ETS port cionfiguration 
 *
 * @param[in] br_id - Bridge id
 * @param[in] log_port - logical port id 
 * @param[in] tc_ets_list_p - traffic class ETS configuration 
 * @param[in] tc_cnt - number of tc ETS configuration  in the 
 *       list
 * @param[in,out] cos_tc_ets_vs_ext - vendor specific extention 
 *
 * @return OES_STATUS_SUCCESS if operation completes 
 *         successfully
 * @return OES_STATUS_PARAM_ERROR: Input parameters error. 
 * @return OES_STATUS_ERROR general error. 
 */
oes_status_e
oes_api_cos_tc_ets_set(
                      const int br_id,
                      const unsigned int log_port,
                      const struct oes_cos_tc_ets_config_params * tc_ets_list_p,
                      const unsigned short tc_cnt,
                      void * cos_tc_ets_set_vs_ext
                      );


/**
 * this function retrieve the traffic class group for traffic 
 * class. 
 *
 * @param[in] br_id - Bridge id
 * @param[in] log_port - logical port id 
 * @param[out] tc_ets_list_p - traffic class ETS configuration 
 * @param[in,out] tc_cnt - number of tc ETS configuration  in 
 *       the list
 * @param[in,out] cos_tc_ets_vs_ext - vendor specific extention 
 *
 * @return OES_STATUS_SUCCESS if operation completes 
 *         successfully
 * @return OES_STATUS_PARAM_ERROR: Input parameters error. 
 * @return OES_STATUS_ERROR general error. 
 */

oes_status_e
oes_api_cos_tc_ets_get(
                      const int br_id,
                      const unsigned int log_port,
                      const struct oes_cos_tc_ets_config_params  tc_ets_list_p,
                      unsigned short * tc_cnt,
                      void * cos_tc_ets_set_vs_ext
                      );


/**
* This function sets the ETS  per port  configuration 
*  
*  @param[in] br_id - Bridge id
 * @param[in] log_port - logical port id 
 * @param[in] port_ets_p - port ETS configuration 
*  @param[in,out] cos_port_ets_vs_ext - vendor specific
*        extention
 *
 * @return OES_STATUS_SUCCESS if operation completes 
 *         successfully
 * @return OES_STATUS_PARAM_ERROR: Input parameters error. 
 * @return OES_STATUS_ERROR general error. 
 */
oes_status_e
oes_api_cos_port_ets_set(
                        const int br_id,
                        const unsigned int log_port,
                        const struct oes_cos_port_ets_config_params  * port_ets_p,
                        void * cos_port_ets_set_vs_ext
                        );


/**
* This function retrieves the ETS port configuration 
*  
*  @param[in] br_id - Bridge id
 * @param[in] log_port - logical port id 
 * @param[out] port_ets_p - port ETS configuration 
*  @param[in,out] cos_port_ets_vs_ext - vendor specific
*        extention
 *
 * @return OES_STATUS_SUCCESS if operation completes 
 *         successfully
 * @return OES_STATUS_PARAM_ERROR: Input parameters error. 
 * @return OES_STATUS_ERROR general error. 
 */
oes_status_e
oes_api_cos_port_ets_get(
                        const int br_id,
                        const unsigned int log_port,
                        struct oes_cos_port_ets_config_params  * port_ets_p,
                        void * cos_port_ets_set_vs_ext
                        );

/**
 * This function Sets the Port's Buffer size and pause threshold 
 * holds. 
 *
 * @param[in] br_id - Bridge id 
 * @param[in] log_port - Logical Port ID.
 * @param[in] xof_timer_value - Pause frame: Pause timer .
 * @param[in] xof_refresh - send pause frame interval.
 * @param[in] buffer_list_p - Array of 9 threshold structures. 
 * @param[in] buffer_cnt - Array size.
 * @param[in,out] cos_port_buff_vs_ext - vendor specific 
 *       extention
 *  
 * @return OES_STATUS_SUCCESS - Operation completes successfully
 * @return OES_STATUS_PARAM_ERROR - Unsupported verbosity_level
 * @return OES_STATUS_ERROR general error. 
 */
oes_status_e
oes_api_cos_port_buff_set(
                         const int br_id,
                         const unsigned int log_port,
                         const unsigned int xof_timer_value,
                         const unsigned int xof_refresh,
                         const struct oes_cos_port_buff_buffer buffer_list_p,
                         const unsigned short  buff_cnt, 
                         void * cos_port_buff_vs_ext
                         );

/**
 * his function Retrieves the Port's Buffe size and pause 
 * threshold holds . 
 *
 * @param[in] br_id - Bridge id 
 * @param[in] log_port - Logical Port ID.
 * @param[out] xof_timer_value - Pause frame: Pause timer .
 * @param[out] xof_refresh - send pause frame interval.
 * @param[out] buffer_list_p - Array of 9 threshold structures. 
 * @param[in,out] buffer_cnt_p - Array size. 
 * @param[in,out] cos_port_buff_vs_ext - vendor specific 
 *       extention
 * @return OES_STATUS_SUCCESS - Operation completes successfully
 * @return OES_STATUS_PARAM_ERROR - Unsupported verbosity_level
 * @return OES_STATUS_ERROR general error. 
 */
oes_status_e
oes_api_cos_port_buff_get(
                         const int br_id,
                         const unsigned int log_port,
                         unsigned int * xof_timer_value,
                         unsigned int * xof_refresh,
                         struct oes_cos_port_buff_buffer buffer_list_p,
                         unsigned short * buff_cnt_p, 
                         void * cos_port_buff_vs_ext
                         );

#endif /* __OES_API_COS_H__ */
