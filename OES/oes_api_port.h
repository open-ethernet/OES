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

#ifndef __OES_API_PORT_H__
#define __OES_API_PORT_H__

#include <oes_types.h>

/************************************************
 *  API functions
 ***********************************************/
/**
 * This function sets the log verbosity level of port MODULE
 * @param[in]  verbosity_level  - port  module verbosity level
 *
 * @return OES_STATUS_SUCCESS - Operation completes successfully
 * @return OES_STATUS_PARAM_ERROR - Unsupported verbosity_level
 * @return OES_STATUS_ERROR general error. 
 */
oes_status_e
oes_api_port_log_verbosity_level_set(
                                    const int   verbosity_level
                                    );

/**
 * This function gets the log verbosity level of port MODULE
 * @param[out]  verbosity_level_p  port module verbosity level
 *
 * @return OES_STATUS_SUCCESS - Operation completes successfully
 * @return OES_STATUS_PARAM_ERROR - Unsupported verbosity_level
 * @return OES_STATUS_ERROR general error. 
 */
oes_status_e
oes_api_port_log_verbosity_level_get(
                                    int   * verbosity_level_p
                                    );

/**
 *  This function Sets the Port MTU size in the SDK.
 *
 * @param[in] br_id - Bridge id 
 * @param[in] log_port - Logical Port ID.
 * @param[in] mtu - New MTU payload size. SDK will add L2 header
 *       size bytes to this value
 * @param[in,out] sport_mtu_vs_ext - vendor specific extention 
 *  
 * @return OES_STATUS_SUCCESS - Operation completes successfully
 * @return OES_STATUS_PARAM_ERROR - Unsupported verbosity_level
 * @return OES_STATUS_ERROR general error. 
 */
oes_status_e
oes_api_port_mtu_set(
                    const int br_id,
                    const unsigned long log_port,
                    const unsigned int mtu,
                    void * port_mtu_vs_ext
                    );




/**
 *  This function Retrieves the Port MTU size from the SDK.
 *  
 * @param[in] br_id - Bridge id 
 * @param[in] log_port - Logical Port ID.
 * @param[out] mtu_p - port MTU payload size. 
 * @param[in,out] sport_mtu_vs_ext - vendor specific extention 
 *  
 * @return OES_STATUS_SUCCESS - Operation completes successfully
 * @return OES_STATUS_PARAM_ERROR - Unsupported verbosity_level
 * @return OES_STATUS_ERROR general error. 
 */
oes_status_e
oes_api_port_mtu_get(
                    const int br_id,
                    const unsigned long log_port,
                    unsigned int * mtu_p,
                    void * port_mtu_vs_ext
                    );



/**
 *  This function Sets the Port Type & Speed.It enables the 
 *  application to set the port enabled mode(s). When link is
 *  up, the current active protocol is retrieved (after SET).
 *  When link is down, the supported protocols are retrieved
 *  (after SET).
 *
 * @param[in] br_id - Bridge id 
 * @param[in] log_port - Logical Port ID.
 * @param[in] speed_cap_p-port speed capability 
 * @param[in,out]sport_mtu_vs_ext - vendor specific extention 
 *  
 * @return OES_STATUS_SUCCESS - Operation completes successfully
 * @return OES_STATUS_PARAM_ERROR - Unsupported verbosity_level
 * @return OES_STATUS_ERROR general error. 
 */
oes_status_e
oes_api_port_speed_capability_set(
                                 const int br_id,
                                 const unsigned long log_port,
                                 const struct oes_port_speed_capability * speed_cap_p,
                                 void * port_speed_vs_ext
                                 );


/**
 *  This function gets the Port Type & Speed. capability 
 *
 * @param[in] br_id - Bridge id 
 * @param[in] log_port - Logical Port ID.
 * @param[out] peed_cap_p-port speed capability 
 * @param[in,out]port_speed_capability_vs_ext - vendor specific 
 *       extention
 *  
 * @return OES_STATUS_SUCCESS - Operation completes successfully
 * @return OES_STATUS_PARAM_ERROR - Unsupported verbosity_level
 * @return OES_STATUS_ERROR general error. 
 */
oes_status_e
oes_api_port_speed_capability_get(
                                 const int br_id,
                                 const unsigned long log_port,
                                 struct oes_port_speed_capability * speed_cap_p,
                                 void * port_speed_capability_vs_ext
                                 );


/**
 *  This function Retrieves the Port's Operational Speed
 *
 * @param[in] br_id - Bridge id 
 * @param[in] log_port - Logical Port ID.
 * @param[out] port_speed_p - port speed 
 * @param[in,out]sport_speed_vs_ext - vendor specific extention 
 *  
 * @return OES_STATUS_SUCCESS - Operation completes successfully
 * @return OES_STATUS_PARAM_ERROR - Unsupported verbosity_level
 * @return OES_STATUS_ERROR general error. 
 */

oes_status_e
oes_api_port_speed_get(
                      const int br_id,
                      const unsigned long log_port,
                      enum oes_port_speed  * port_speed_p,
                      void * port_speed_vs_ext
                      );
/**
 *  This function Sets the Port's (base) Physical Address (MAC)
 *
 * @param[in] br_id - Bridge id
 * @param[in] log_port - Logical Port ID
 * @param[in] mac_addr_p - port MAC address
 * @param[in,out]port_mac_addr_vs_ext - vendor specific 
 *       extention
 * 
 * @return OES_STATUS_SUCCESS if operation completes successfully
 * @return OES_STATUS_PARAM_ERROR: Input parameters error. 
 * @return OES_STATUS_ERROR general error.  
 */
oes_status_e
oes_api_port_mac_addr_set(
                         const int br_id,
                         const unsigned long log_port,
                         const struct ether_addr * mac_addr_p; 
                         void * port_mac_addr_vs_ext
                         );

/**
 *  This function gets the Port's Physical Address (MAC)
 *
 * @param[in] br_id - Bridge id
 * @param[in] log_port - Logical Port ID
 * @param[in] mac_addr_p - port MAC address
 * @param[in,out]port_mac_addr_vs_ext - vendor specific 
 *       extention
 *  
 * @return OES_STATUS_SUCCESS if operation completes successfully
 * @return OES_STATUS_PARAM_ERROR: Input parameters error. 
 * @return OES_STATUS_ERROR general error.  
 */
oes_status_e
oes_api_port_mac_addr_get(
                         const int br_id,
                         const unsigned long log_port,
                         struct ether_addr * mac_addr; 
                         void * port_mac_addr_vs_ext
                         );

/**
 * This function sets the port's physical loopback.
 * LAG port or LAG member port cannot be loopback.
 *
 * @param[in] br_id - Bridge id
 * @param[in] log_port - Logical port ID.
 * @param[in] phys_loopback - physical loopback type.
 * @param[in,out] port_phys_loopback_vs_ext - vendor 
 *       specific extention
 *  
 * @return OES_STATUS_SUCCESS if operation completes successfully
 * @return OES_STATUS_PARAM_ERROR: Input parameters error. 
 * @return OES_STATUS_ERROR general error.  
 */
oes_status_e
oes_api_port_phys_loopback_set(
                              const int br_ib,
                              const unsigned long log_port,
                              const enum oes_port_phys_loopback phys_loopback,
                              void * port_phys_loopback_vs_ext
                              );

/**
 * this function retrieves the port's physical 
 *  
 * @param[in] br_id - Bridge id
 * @param[in] log_port - Logical port ID.
 * @param[in] phys_loopback_p - physical loopback type.
 * @param[in,out] port_phys_loopback_vs_ext - vendor 
 *       specific extention
 *  
 * @return OES_STATUS_SUCCESS if operation completes successfully
 * @return OES_STATUS_PARAM_ERROR: Input parameters error. 
 * @return OES_STATUS_ERROR general error.  
 */
oes_status_e
oes_api_port_phys_loopback_get(
                              const int br_ib,
                              const unsigned long log_port,
                              enum oes_port_phys_loopback_* phys_loopback_p,
                              void * port_phys_loopback_vs_ext
                              );

/**
 *  This function Sets the Port Administrative State in the SDK.
 *  
 * @param[in] br_id - Bridge id
 * @param[in] log_port - Logical port ID.
 * @param[in] admin_state - port admin state.
 * @param[in,out] port_state_vs_ext - vendor specific extention
 *  
 * @return OES_STATUS_SUCCESS if operation completes successfully
 * @return OES_STATUS_PARAM_ERROR: Input parameters error. 
 * @return OES_STATUS_ERROR general error.  
 */
oes_status_e
oes_api_port_state_set(
                      const int br_id,
                      const unsigned long log_port,
                      const enum oes_port_admin_state admin_state,
                      void * port_state_vs_ext
                      );

/**
 *  This function Retrieves the Port's Administrative,
 *  Operationa State 
 *  
 * @param[in] br_id - Bridge id
 * @param[in] log_port - Logical port ID.
 * @param[out] admin_state_p - port admin state. 
 * @param[out] oper_state_p - port oper state. 
 * @param[in,out] port_state_vs_ext - vendor specific extention
 *  
 * @return OES_STATUS_SUCCESS if operation completes successfully
 * @return OES_STATUS_PARAM_ERROR: Input parameters error. 
 * @return OES_STATUS_ERROR general error.  
 */
oes_status_e
oes_api_port_state_get(
                      const int br_id,
                      const unsigned long log_port,
                      enum oes_port_admin_state * admin_state_p,
                      enum oes_port_oper_state * oper_state_p,
                      void * port_state_vs_ext
                      );

/**
 *  This function Sets the Port Flow Control Pause
 *     Configuration
 *  
 * @param[in] br_id - Bridge id
 * @param[in] log_port - Logical Port ID (whose flow control configuration to set) 
 * @param[in] fc_param_- flow control parameter - global 
 *       pause/pfc ,prio,en/dis 
 * @param[in,out] port_port_flow_ctrl_vs_ext - vendor specific 
 *       extention
 *  
 * @return OES_STATUS_SUCCESS if operation completes successfully
 * @return OES_STATUS_PARAM_ERROR: Input parameters error. 
 * @return OES_STATUS_ERROR general error.  
 */
oes_status_e
oes_api_port_flow_ctrl_set(
                          const int br_id,
                          const unsigned long log_port,
                          struct oes_port_flow_control_param * fc_param_p,
                          void * port_flow_ctrl_vs_ext
                          );


/**
 * This function Retrieves the Port Flow Control Pause
 *   Configuration
 *  
 * @param[in] br_id - Bridge id
 * @param[in] log_port - Logical Port ID (whose flow control configuration to set) 
 * @param[in] fc_param - flow control parameter - global 
 *       pause/pfc ,prio
 * @param[in,out] port_port_flow_ctrl_vs_ext - vendor specific 
 *       extention
 *  
 * @return OES_STATUS_SUCCESS if operation completes successfully
 * @return OES_STATUS_PARAM_ERROR: Input parameters error. 
 * @return OES_STATUS_ERROR general error.  
 */
oes_status_e
oes_api_port_flow_ctrl_get(
                          const int br_id,
                          const unsigned long log_port,
                          struct oes_port_flow_control_param * fc_param_p,
                          void * port_flow_ctrl_vs_ext
                          );

/**
 * This function Retrieves the Port IEEE 802.3 Counters 
 * 
 * @param[in] access_cmd -  READ/READ CLEAR 
 * @param[in] br_id - Bridge id  
 * @param[in] log_port - Logical Port ID.
 * @param[out] cntr_ieee_802_dot_3_p - IEEE 802.3 counters entry.
 * @param[in,out] port_cntr_ieee_802_dot_3_vs_ext - vendor 
 *       specific extention
 * @return OES_STATUS_SUCCESS if operation completes successfully
 * @return OES_STATUS_PARAM_ERROR: Input parameters error. 
 * @return OES_STATUS_ERROR general error. 
 */
oes_status_e
oes_api_port_cntr_ieee_802_dot_3_get(
                                    const enum oes_access_cmd access_cmd,
                                    const int br_id,
                                    const unsigned long log_port,
                                    struct oes_port_cntr_ieee_802_dot_3 * cntr_ieee_802_dot_3_p
                                    void * port_cntr_ieee_802_dot_3_vs_ext
                                    );


/**
 * This function Retrieves the Port RFC 2863 Counters 
 *  
 * @param[in] access_cmd -  READ/READ CLEAR 
 * @param[in] br_id - Bridge id  
 * @param[in] log_port - Logical Port ID.
 * @param[out] cntr_rfc_2863_p - RFC 2863 counters entry.
 * @param[in,out] port_cntr_rfc_2863_vs_ext - vendor specific 
 *       extention
 * @return OES_STATUS_SUCCESS if operation completes successfully
 * @return OES_STATUS_PARAM_ERROR: Input parameters error. 
 * @return OES_STATUS_ERROR general error. 
 */
oes_status_e
oes_api_port_cntr_rfc_2863_get(
                              const enum oes_access_cmd access_cmd,
                              const int br_id,
                              const  unsigned long log_port,
                              struct oes_port_cntr_rfc_2863 * cntr_rfc_2863_p,
                              void * port_cntr_rfc_2863_vs_ext
                              );

/**
 *  This function Retrieves the Port RFC 2819 Counters from the
 *  SDK.
 *  
 * @param[in] access_cmd -READ/READ CLEAR 
 * @param[in] br_id - Bridge id  
 * @param[in] log_port - Logical Port ID.
 * @param[out] cntr_rfc_2819_p - RFC 2819 counters entry.
 * @param[in,out] port_cntr_rfc_2819_vs_ext - vendor specific 
 *       extention
 *  
 * @return OES_STATUS_SUCCESS if operation completes successfully
 * @return OES_STATUS_PARAM_ERROR: Input parameters error. 
 * @return OES_STATUS_ERROR general error. 
 */
oes_status_e
oes_api_port_cntr_rfc_2819_get(
                              const enum oes_access_cmd access_cmd,
                              const int br_ib,
                              const unsigned long log_port,
                              struct oes_port_cntr_rfc_2819 *cntr_rfc_2819_p,
                              void * port_cntr_rfc_2819_vs_ext
                              );

/**
 *  This function Retrieves the Port RFC 3635 Counters from the
 *  SDK.
 * 
 * @param[in] access_cmd -READ/READ CLEAR  
 * @param[in] br_id - Bridge id  
 * @param[in] log_port - Logical Port ID.
 * @param[out] cntr_rfc_3635_p - RFC 3635 counters entry.
 * @param[in,out] port_cntr_rfc_3635_vs_ext - vendor specific 
 *       extention
 *  
 * @return OES_STATUS_SUCCESS if operation completes successfully
 * @return OES_STATUS_PARAM_ERROR: Input parameters error. 
 * @return OES_STATUS_ERROR general error. 
 */
oes_status_e
oes_api_port_cntr_rfc_3635_get(
                              const enum oes_access_cmd access_cmd,
                              const int br_ib,
                              const unsigned long log_port,
                              struct oes_port_cntr_rfc_3635 *cntr_rfc_3635_p,
                              void * port_cntr_rfc_3635_vs_ext
                              );




/**
 * This function Binds / Un-binds a policer to / from a port
 * Cannot bind policer to LAG member port
 *  
 * @param[in] access_cmd -BIND/UNBIND 
 * @param[in] br_id - Bridge id 
 * @param[in] log_port - Logical Port ID
 * @param[in] policer_id - Policer ID 
 * @param[in,out] port_policer_bind_vs_ext - vendor specific 
 *       extention
 *  
 * @return OES_STATUS_SUCCESS if operation completes successfully
 * @return OES_STATUS_PARAM_ERROR: Input parameters error. 
 * @return OES_STATUS_ERROR general error. 
 */
oes_status_e
oes_api_port_policer_bind_set(
                             const enum oes_access_cmd access_cmd,
                             const int br_id,
                             const unsigned long log_port,
                             const unsigned int policer_id,
                             void *  port_policer_bind_vs_ext
                             );

/**
 * This function controls sFlow state of the port. Using access cmd 
 * CREATE a sFlow sampling is defined on port, then after it is 
 * set user may EDIT the sflow parameters  
 * of a configured port. In order to remove sFlow 
 * sampling from the port use access cmd DESTROY. 
 *  
 * @param[in] access_cmd -CREATE/DESTROY/EDIT  
 * @param[in] br_id - Bridge id 
 * @param[in] log_port - Logical Port ID. 
 * @param[in] sflow_params - sFlow related configuration 
 * params(Deviation>0); ignored when CMD=DESTROY. 
 * @param[in,out] port_sflow_vs_ext - vendor specific extention
 *
 * @return OES_STATUS_SUCCESS if operation completes successfully
 * @return OES_STATUS_PARAM_ERROR: Input parameters error. 
 * @return OES_STATUS_NO_RESOURCES if out of resources for sFlow 
 *         policer
 * @return OES_STATUS_ERROR general error. 
 */
oes_status_e
oes_api_port_sflow_set(
                      const enum oes_access_cmd access_cmd,
                      const int br_id,     
                      const unsigned long log_port,
                      const struct oes_port_sflow_params *  sflow_params,
                      void *  port_sflow_vs_ext
                      );


/**
 * This function gets the ports sFlow state.
 *  
 * @param[in] br_id - Bridge id 
 * @param[in] cmd - access cmd (CREATE/DESTROY/EDIT) 
 * @param[in] log_port - Logical Port ID. 
 * @param[out] sflow_params - sFlow related configuration 
 * params(Deviation>0); ignored when CMD=DESTROY. 
 * @param[in,out] port_sflow_vs_ext - vendor specific extention
 *
 * @return OES_STATUS_SUCCESS if operation completes successfully
 * @return OES_STATUS_PARAM_ERROR: Input parameters error. 
 * @return OES_STATUS_ERROR general error. 
 */
oes_status_e
oes_api_port_sflow_get(
                      const int br_ib,
                      const unsigned long log_port,
                      struct oes_port_sflow_params *  sflow_params,
                      void * port_sflow_vs_ext
                      );

/**
 * This function controls loopback filter state of the port  
 * @param[in] br_id - Bridge id 
 * @param[in] log_port - Logical Port ID. 
 * @param[in] lbf_mode - loopback filter mode
 * @param[in,out] port_loopback_filter_vs_ext - vendor specific 
 *       extention
 *  
 * @return OES_STATUS_SUCCESS if operation completes successfully
 * @return OES_STATUS_PARAM_ERROR if Invalid parameter was supplied
 * @return OES_STATUS_ERROR otherwise 
 */
oes_status_e
oes_api_port_loopback_filter_set(
                                const int br_ib,
                                const unsigned long log_port,
                                const enum oes_port_loopback_filter_mode lbf_mode,
                                void * port_loopback_filter_vs_ext
                                );


/**
 * This function gets the loopback filter state of the port  
 * @param[in] br_id - Bridge id 
 * @param[in] log_port - Logical Port ID. 
 * @param[out] lbf_mode - loopback filter mode
 * @param[in,out] port_loopback_filter_vs_ext - vendor specific 
 *       extention
 *  
 * @return OES_STATUS_SUCCESS if operation completes successfully
 * @return OES_STATUS_PARAM_ERROR if Invalid parameter was supplied
 * @return OES_STATUS_ERROR otherwise 
 */
oes_status_e
oes_api_port_loopback_filter_get(
                                const int br_ib,
                                const unsigned long log_port,
                                enum oes_port_loopback_filter_mode  * lbf_mode,
                                void * port_loopback_filter_vs_ext
                                );

/**
 * This function sets the isolation group of the port (a list of ports from which
 * traffic should not be transmitted to log_port). 
 * Set - add ports to isolation group (overwrites previous configuration)
 * Add - add ports to isolation group (additionally to previous configuration)
 * Delete - remove ports from isolation group
 * Delete All - empty isolation group
 * 
 * @param[in] access_cmd - CREATE/ADD/DELETE/DESTROY 
 * @param[in] br_id -bridge ID  
 * @param[in] log_port - Logical Port ID.
 * @param[in] isolated_port_list_p - list of logical ports
 * @param[in] port_cnt - number of logical ports in the list
 * @param[in,out] port_isolation_vs_ext - vendor specific 
 *       extention
 *  
 * @return OES_STATUS_SUCCESS - Operation completes successfully. 
 * @return OES_STATUS_PARAM_ERROR - Parameter is invalid.
 * @return OES_STATUS_ERROR general error. 
 */
oes_status_e
oes_api_port_isolation_set(
                          const enum oes_access_cmd   access_cmd,
                          const int br_id,
                          const unsigned long  log_port,
                          const unsigned long  * isolated_port_list_p,
                          const unsigned short port_cnt,
                          void * port_isolation_vs_ext
                          );

/**
 * This function retrieves the isolation group of the port (a list of ports from which
 * traffic should not be transmitted to log_port). 
 * 
 * @param[in] log_port - Logical Port ID. 
 * param[in] br_id - Bridge id 
 * @param[out] log_port_list_p - list of logical ports
 * @param[in,out] port_cnt - In: arry size Out: Number of 
 * Logical Ports in the isolation group.
 *
 * @return OES_STATUS_SUCCESS - Operation completes successfully. 
 * @return OES_STATUS_PARAM_ERROR - Parameter is invalid.
 * @return OES_STATUS_ERROR general error.
 */

oes_status_e
oes_api_port_isolation_get(
                          const int br_id,
                          const unsigned long  log_port,
                          unsigned long  * isolated_port_list_p,
                          unsigned short * port_cnt,
                          void * port_isolation_vs_ext
                          );

#endif /* __OES_API_PORT_H__ */
