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

#ifndef __SX_API_VLAN_H__
#define __SX_API_VLAN_H__


/************************************************
 *  API functions
 ***********************************************/
/**
 * This function sets the log verbosity level of vlan MODULE
 * @param[in]  verbosity_level  - vlan module verbosity level
 *
 * @return oes_status_t:
* @return OES_STATUS_SUCCESS - Operation completes successfully
 * @return OES_STATUS_ERROR - Unexpected SDK error
 * @return OES_STATUS_PARAM_ERROR - Unsupported verbosity_level
 */
oes_status_e
oes_api_vlan_log_verbosity_level_set(int   verbosity_level);

/**
 * This function gets the log verbosity level of vlan MODULE
 * @param[out]  verbosity_level_p  - vlan module verbosity level
 *
 * @return oes_status_e:
 * @return OES_STATUS_SUCCESS - Operation completes successfully
 * @return OES_STATUS_ERROR - Unexpected SDK error
 * @return OES_STATUS_PARAM_ERROR - Unsupported verbosity_level
 */
oes_status_e
oes_api_vlan_log_verbosity_level_get(int   * verbosity_level_p);

/**
 *  This function sets the VLAN member ports.
 *
 * @param[in] access_cmd - ADD / DELETE / DELETE_ALL
 * @param[in] br_id - virtual switch partition id
 * @param[in] vid - VLAN id
 * @param[in] port_num - number of ports in a port list
 * @param[in] vlan_port_list_p - a pointer to array of port list
 *       structure. Each port in the list has its logical port
 *       number and the egress filter mode (tagged/ untagged and
 *       priority tagged member). In case of "delete all" command,
 *       port_num = 0, vlan_port_list_p = NULL are applicable
 * @param[in.out] vlan_port_vs_ext - vlan port **** vendor 
 *       extension pointer*
 *
 * @return oes_status_e:
 * @return OES_STATUS_SUCCESS - Operation completes successfully
 * @return OES_STATUS_ERROR - Unexpected SDK error
 * @return OES_STATUS_PARAM_ERROR - Unsupported verbosity_level
 */
oes_status_e 
oes_api_vlan_ports_set(	
                       int br_id, 
                       enum oes_access_cmd access_cmd,
                       unsigned short vid,
                       unsigned short port_num,
                       struct oes_vlan_port_t * vlan_port_list_p,
                       void * vlan_port_vs_ext
                       );


/**
 *  This function gets the VLAN member ports.
 *
 * @param[in] br_id - virtual switch partition id
 * @param[in] vid - VLAN id
 * @param[in,out] port_num_p - number of ports in a list that you want to retrieve
 * @param[in,out] vlan_port_list_p - a pointer to array of vlan port list
 *       structure. If it is NULL, the port_num variable will be filled out
 *       with number
 * @param[in,out] vlan_port_vs_ext - vlan port **** vendor 
 *       extension pointer*
 *
* @return oes_status_e:
* @return OES_STATUS_SUCCESS if operation completes successfully
* @return OES_STATUS_PARAM_ERROR if any input parameter is invalid
* @return OES_STATUS_ERROR - Unexpected SDK error
 */
oes_status_e 
oes_api_vlan_ports_get(	
                        int br_id, 
                        unsigned short vid,
                        unsigned short * port_num_p,
                        struct oes_vlan_port_t * vlan_port_list_p,
                        void * vlan_port_vs_ext
                        );
/**
*  This function sets the VLANs list to a port in a single
*  command.
 * @param[in] br_id - virtual switch partition id
* @param[in] access_cmd -  OES_ACCESS_CMD_ADD - Add list of VLANs to port
*                          OES_ACCESS_CMD_DELETE - Remove a list VLANs from port
*
* @param[in] log_port - logical port
* @param[in] vlan_num - size of VLANs list
* @param[in] vlan_list_p - pointer to a list of VLAN,tagged 
*       value tuples
* @param[in,out] vlan_list_vs_ext - vlan list **** vendor 
*       extension pointer*
* @return oes_status_e:
* @return OES_STATUS_SUCCESS if operation completes successfully
* @return OES_STATUS_PARAM_ERROR if any input parameter is invalid
* @return OES_STATUS_ERROR - Unexpected SDK error
*/
oes_status_e 
oes_api_vlan_port_multi_vlan_set(    
                                  int br_id, 
                                  enum oes_access_cmd access_cmd,
                                  unsigned long	log_port,
                                  unsigned short vlan_num,
                                  struct oes_port_vlans_t * vlan_list_p,
                                  void * vlan_list_vs_ext
                                  );

/**
 *   This function enables/ disables ingress VLAN filtering on a
 *   port. The VLAN membership is defined in oes_vlan_ports_set
 *   API
 * @param[in] br_id - virtual switch partition id
 *  @param[in] log_port - logical port number
 *  @param[in] ingress_filter_state      - port ingress vlan
 *        filter state (enable/disable)
* @param[in,out] vlan_filter_vs_ext - vlan filter **** vendor 
*       extension pointer*
 *
* @return oes_status_e:
* @return OES_STATUS_SUCCESS if operation completes successfully
* @return OES_STATUS_PARAM_ERROR if any input parameter is invalid
* @return OES_STATUS_ERROR - Unexpected SDK error
 */
oes_status_e 
oes_api_vlan_ingr_filter_ports_set(	
                                    int br_id, 
                                    unsigned long log_port,
                                    enum oes_ingr_filter_mode ingress_filter_state,
                                    void * vlan_filter_vs_ext
                                    );

/**
 *   This function retrieves ingress VLAN filtering on a port.
 * @param[in] br_id - virtual switch partition id
 *  @param[in] log_port - logical port number
 *  @param[out] ingress_filter_state_p - a pointer to port
 *          ingress vlan filter state (enable/disable)
* @param[in,out] vlan_filter_vs_ext - vlan filter **** vendor 
*       extension pointer*
* @return oes_status_e:
* @return OES_STATUS_SUCCESS if operation completes successfully
* @return OES_STATUS_PARAM_ERROR if any input parameter is invalid
* @return OES_STATUS_ERROR - Unexpected SDK error
 */
oes_status_e 
oes_api_vlan_ingr_filter_ports_get(
                                    int br_id, 
                                    unsigned long log_port,
                                    enum oes_ingr_filter_mode * ingress_filter_state_p,
                                    void * vlan_filter_vs_ext
                                    );

/**
 *  This function sets port's default VLAN ID. The PVID is set
 *  to untagged packets that ingress on the port.
 *  Note: When the PVID is deleted from the port, it is assigned
 *  with the default VLAN ID
 *
 * @param[in] br_id - virtual switch partition id
 * @param[in] access_cmd - ADD / DELETE (return PVID to default)
 * @param[in] log_port - logical port number
 * @param[in] pvid - Port VLAN ID
* @param[in,out] port_pvid_vs_ext - vlan filter **** vendor 
*       extension pointer*
* @return oes_status_e:
* @return OES_STATUS_SUCCESS if operation completes successfully
* @return OES_STATUS_PARAM_ERROR if any input parameter is invalid
* @return OES_STATUS_ERROR - Unexpected SDK error
 */
oes_status_e 
oes_api_vlan_port_pvid_set(
                             int br_id, 
                             enum oes_access_cmd access_cmd,
                             unsigned long log_port,
                             unsigned short pvid,
                             void * port_pvid_vs_ext
                             );

/**
 *  This function retrieves port's default VLAN ID.
 *
 * @param[in] br_id - virtual switch partition id
 * @param[in] log_port - logical port number
 * @param[out] pvid_p - Port VLAN ID
* @param[in,out] port_pvid_vs_ext - vlan filter **** vendor 
*       extension pointer*
* @return oes_status_e:
* @return OES_STATUS_SUCCESS if operation completes successfully
* @return OES_STATUS_PARAM_ERROR if any input parameter is invalid
* @return OES_STATUS_ERROR - Unexpected SDK error
 */
oes_status_e 
oes_api_vlan_port_pvid_get(
                             int br_id, 
                             unsigned long log_port,
                             unsigned short * pvid_p,
                             void * port_pvid_vs_ext
                             );

/**
 *  This function sets port's accepted frame types.
 *  Note1: By default, all ports are configured to accept all
 *  frame types
 *  Note2: Priority tagged packets are considered as untagged
 *  packets
 *
 * @param[in] br_id - virtual switch partition id
 * @param[in] log_port - logical port number
 * @param[in] accptd_frm_types - enum defining the following 
*        values: allow_tagged, allow_untagged, allow_prio_tagged
* @param[in,out] accptd_frm_types_vs_ext - accepted frame types 
*       vendor extension pointer
* 
* @return oes_status_e:
* @return OES_STATUS_SUCCESS if operation completes successfully
* @return OES_STATUS_PARAM_ERROR if any input parameter is invalid
* @return OES_STATUS_ERROR - Unexpected SDK error
 */
oes_status_e 
oes_api_vlan_port_accptd_frm_types_set(
                                        int br_id, 
                                        unsigned long log_port,
                                        enum oes_vlan_frame_types      accptd_frm_types,
                                        void * accptd_frm_types_vs_ext
                                        );

/**
 *  This function retrieves port's accepted frame types.
 *
 * @param[in] br_id - virtual switch partition id
 * @param[in] log_port - logical port number
 * @param[in] accptd_frm_types_p - a pointer to enum holding
 *  	 the following values: allow_tagged, allow_untagged,
 *  	 allow_prio_tagged
* @param[in,out] accptd_frm_types_vs_ext - accepted frame types 
*       vendor extension pointer
* @return oes_status_e:
* @return OES_STATUS_SUCCESS if operation completes successfully
* @return OES_STATUS_PARAM_ERROR if any input parameter is invalid
* @return OES_STATUS_ERROR - Unexpected SDK error
 */
oes_status_e 
oes_api_vlan_port_accptd_frm_types_get(
                                        int br_id, 
                                        unsigned long log_port,
                                        enum oes_vlan_frame_types * accptd_frm_types_p,
                                        void * accptd_frm_types_vs_ext
                                        );

/**
 *  This function sets the virtual switch default VLAN ID. This
 *  VID is set by default as the PVID of all switch ports. If
 *  not called, the default VID for all virtual switches is 1.
 *
 * @param[in] br_id - virtual switch partition id
 * @param[in] vid - switch default VLAN id
* @param[in,out] default_vid_vs_ext - default VID 
*        vendor extension pointer
* @return oes_status_e:
* @return OES_STATUS_SUCCESS if operation completes successfully
* @return OES_STATUS_PARAM_ERROR if any input parameter is invalid
* @return OES_STATUS_ERROR - Unexpected SDK error
 */
oes_status_e 
oes_api_vlan_default_vid_set(
                             int br_id, 
                             unsigned short default_vid,
                             void * default_vid_vs_ext
                             );


/**
 *  This function reads the virtual switch default VLAN ID. 
 *
 * @param[in] br_id - virtual switch partition id
 * @param[in] deffault_vid_p - switch default VLAN id
* @param[in,out] default_vid_vs_ext - default VID 
*        vendor extension pointer
* @return oes_status_e:
* @return OES_STATUS_SUCCESS if operation completes successfully
* @return OES_STATUS_PARAM_ERROR if any input parameter is invalid
* @return OES_STATUS_ERROR - Unexpected SDK error
 */
oes_status_e 
oes_api_vlan_default_vid_get(
                             int br_id, 
                             unsigned short * default_vid_p,
                             void * default_vid_vs_ext

/**
 *  This function set flood mode to flood or proon
 *  bridged packets
 *  
 * @param[in] br_id - virtual switch partition id
 * @param[in] vid 	- filtering DB id
 * @param[in] flood_type - unknown_uc/ unreg_mc/broadcast
 * @param[in] flood_cmd - flood/ proon 
* @param[in,out] vlan_flood_vs_ext - vlan flood 
*        vendor extension pointer
*
* @return oes_status_e:
* @return OES_STATUS_SUCCESS if operation completes successfully
* @return OES_STATUS_PARAM_ERROR if any input parameter is invalid
* @return OES_STATUS_ERROR - Unexpected SDK error
 */
oes_status_e
oes_api_vlan_flood_mode_set(
                             int br_id, 
                             unsigned short vid,
                             enum oes_vlan_flood_type flood_type, 
                             enum oes_vlan_flood_cmd flood_cmd, 
                             void * vlan_flood_vs_ext
                             );

/**
 *  This function get the vlan flood mode
 *  
 * @param[in] br_id - virtual switch partition id
 * @param[in] vid 	- filtering DB id
 * @param[in] flood_type - unknown_uc/ unreg_mc/broadcast
*  @param[in] flood_cmd_p - pointer to return the command
*        (flood/ proon)
* @param[in,out] vlan_flood_vs_ext - vlan flood 
*        vendor extension pointer
* @return oes_status_e:
* @return OES_STATUS_SUCCESS if operation completes successfully
* @return OES_STATUS_PARAM_ERROR if any input parameter is invalid
* @return OES_STATUS_ERROR - Unexpected SDK error
 */
oes_status_e
oes_api_vlan_flood_mode_get(
                            int br_id, 
                            unsigned short vid,
                            enum oes_vlan_flood_type flood_type, 
                            enum oes_vlan_flood_cmd * flood_cmd_p, 
                            void * vlan_flood_vs_ext
                            );

/**
*   This function set per vlan flood ports for unregistered MC
*   broadcast and unknown unicast
 *  
 * @param[in] br_id - virtual switch partition id
 * @param[in] vid 	- filtering DB id
 * @param[in] port_num - sizeof port list
 * @param[in] log_port_list_p - a pointer to a port list, port can be LAG or physical port.
* @param[in,out] vlan_flood_vs_ext - vlan flood 
*        vendor extension pointer
* @return oes_status_e:
* @return OES_STATUS_SUCCESS if operation completes successfully
* @return OES_STATUS_PARAM_ERROR if any input parameter is invalid
* @return OES_STATUS_ERROR - Unexpected SDK error
 */
oes_status_e
oes_api_vlan_flood_ports_set(
                             int br_id, 
                             unsigned short vid,
                             unsigned short port_num,
                             unsigned long * log_port_list_p,	
                             void * vlan_flood_vs_ext
                             );

/**
 *  This function get per vlan flood ports
 *  
 * @param[in] br_id - virtual switch partition id
 * @param[in] vid 	- filtering DB id
 * @param[in,out] port_num - sizeof port list
 * @param[out] dist_log_port_list_p - a pointer to a port list, port can be LAG or physical port.
* @param[in,out] vlan_flood_vs_ext - vlan flood 
*        vendor extension pointer
* @return oes_status_e:
* @return OES_STATUS_SUCCESS if operation completes successfully
* @return OES_STATUS_PARAM_ERROR if any input parameter is invalid
* @return OES_STATUS_ERROR - Unexpected SDK error
 */ 
oes_status_e
oes_api_vlan_flood_ports_get(
                             int br_id, 
                             unsigned short vid,
                             unsigned short port_num,
                             unsigned long * log_port_list_p,	
                             void * vlan_flood_vs_ext
                             );

/**
 *  This function set Q-in-Q mode of port
 *
 * @param[in] br_id - virtual switch partition id
 * @param[in] log_port  - logical port id
 * @param[in] quiq_mode - mode: Q-in-Q enabled/disabled
* @param[in,out] qinq_mode_vs_ext - qinq mode 
*        vendor extension pointer
* @return oes_status_e:
* @return OES_STATUS_SUCCESS if operation completes successfully
* @return OES_STATUS_PARAM_ERROR if any input parameter is invalid
* @return OES_STATUS_ERROR - Unexpected SDK error
 */
oes_status_e
oes_api_vlan_qinq_mode_set(
                            int br_id, 
                            unsigned long log_port,	
                            enum oes_qinq_mode qinq_mode,
                            void * qinq_mode_vs_ext
                            );

/**
 *  This function retrieves Q-in-Q mode of port
 *
 * @param[in] br_id - virtual switch partition id
 * @param[in] log_port   - logical port id
 * @param[out] quiq_mode_p - the retrieved mode
* @param[in,out] qinq_mode_vs_ext - qinq mode 
*        vendor extension pointer
* @return oes_status_e:
* @return OES_STATUS_SUCCESS if operation completes successfully
* @return OES_STATUS_PARAM_ERROR if any input parameter is invalid
* @return OES_STATUS_ERROR - Unexpected SDK error
 */
oes_status_e
oes_api_vlan_qinq_mode_get(
                            int br_id, 
                            unsigned long log_port,	
                            enum oes_qinq_mode * qinq_mode_p,
                            void * qinq_mode_vs_ext
                            );

/**
 * The function sets which priority should be taken for the outer tag (when Q-in-Q is enabled):
 * The port's default priority, or the inner tag's priority
 *
 * @param[in] br_id - virtual switch partition id
 * @param[in] log_port  - logical port id
 * @param[in] prio_mode - mode: default/inner priority
* @param[in,out] qinq_prio_mode_vs_ext - qinq prio mode 
*        vendor extension pointer
* @return oes_status_e:
* @return OES_STATUS_SUCCESS if operation completes successfully
* @return OES_STATUS_PARAM_ERROR if any input parameter is invalid
* @return OES_STATUS_ERROR - Unexpected SDK error
 */
oes_status_e
oes_api_vlan_qinq_outer_prio_mode_set(
                                      int br_id, 
                                      unsigned long log_port,	
                                      enum oes_qinq_outer_prio_mode prio_mode,
                                      void * qinq_prio_mode_vs_ext
                                      );

/**
 * This function retrieves port's Q-in-Q outer tag priority mode
 *
 * @param[in] br_id - virtual switch partition id
 * @param[in] log_port  - logical port id
 * @param[out] qinq_prio_mode_p - the retrieved mode
* @param[in,out] qinq_prio_mode_vs_ext - qinq prio mode 
*        vendor extension pointer
* @return oes_status_e:
* @return OES_STATUS_SUCCESS if operation completes successfully
* @return OES_STATUS_PARAM_ERROR if any input parameter is invalid
* @return OES_STATUS_ERROR - Unexpected SDK error
 */
oes_status_e
oes_api_vlan_qinq_outer_prio_mode_get(
                                      int br_id, 
                                      unsigned long log_port,	
                                      enum oes_qinq_outer_prio_mode * qinq_prio_mode_p,
                                      void * qinq_prio_mode_vs_ext
                                      );


#endif /* __OES_API_VLAN_H__ */

