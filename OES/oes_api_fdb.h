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

#ifndef __OES_API_FDB_H__
#define __OES_API_FDB_H__

/***********************************************
 *  API functions
 ***********************************************/

/**
 * This function sets the log verbosity level of FDB MODULE
 * @param[in]  verbosity_level  - FDB module verbosity level
 *
 * @return OES_STATUS_SUCCESS - Operation completes successfully
 * @return OES_STATUS_PARAM_ERROR - Unsupported verbosity_level
 * @return OES_STATUS_ERROR general error. 
 */
oes_status_e
oes_fdb_log_verbosity_level_set(
                               const int   verbosity_level
                               );

/**
 * This function gets the log verbosity level of FDB MODULE
 * @param[out]  verbosity_level_p  - FDB module verbosity level
 *
 * @return OES_STATUS_SUCCESS - Operation completes successfully
 * @return OES_STATUS_PARAM_ERROR - Unsupported verbosity_level
 * @return OES_STATUS_ERROR general error. 
 */
oes_status_e
oes_api_fdb_log_verbosity_level_get(
                                   int   * verbosity_level_p
                                   );

/**
 * This function sets the FDB age time, in seconds. Age time is
 *  the time after which auto learned addresses are deleted from
 *  the FDB if they receive no traffic.
 *  
 * @param[in] br_id - Bridge id 
 * @param[out] age_time - Time in seconds.
 * @param[in,out] fdb_age_time_vs_ext - vendor specific 
 *       extention .
 * 
 * @return OES_STATUS_SUCCESS - Operation completes successfully
 * @return OES_STATUS_PARAM_ERROR if any input parameters is invalid. 
 * @return OES_STATUS_ERROR general error.
 */

oes_status_e 
oes_api_fdb_age_time_set(
                        const int br_id,
                        const unsigned int  age_time,
                        void * fdb_age_time_vs_ext
                        );

/**
 * This function gets the FDB age time, in seconds. Age time is
 *  the time after which auto learned addresses are deleted from
 *  the FDB if they receive no traffic.
 *  
 * @param[in] br_id - Bridge id 
 * @param[out] age_time_p - Time in seconds.
 * @param[in,out] fdb_age_time_vs_ext - vendor specific 
 *       extention .
 * @return OES_STATUS_SUCCESS - Operation completes successfully
 * @return OES_STATUS_PARAM_ERROR if any input parameters is invalid. 
 * @return OES_STATUS_ERROR general error. 
 */
oes_status_e 
oes_api_fdb_age_time_get(
                        const int br_id,
                        unsigned int  * age_time_p,
                        void * fdb_age_time_vs_ext
                        );

/**
 *  This function adds/deletes UC MAC and UC LAG MAC entries to the FDB.
 *  In case the operation failed on one entry (or more), an error will be
 *  returned, mac_entry_list_p will store those entries, and their quantity
 *  will be stored in mac_cnt.
 *  If the operation finished successfully: SUCCESS will be returned, and
 *  mac_cnt and mac_entry_list_p won't be changed.
 *
 * @param[in] access_cmd - add/ delete 
 * @param[in] br_id - Bridge id  
 * @param[in,out] mac_entry_list_p- mac record arry pointer . On
 *       deletion, entry_type is DONT_CARE
 * @param[in,out] mac_cnt - mac record arry size
 * @param[in] fdb_uc_mac_addr_vs_ext - vendor specific extention
 *
 *
 * @return OES_STATUS_SUCCESS - Operation completes successfully
 * @return OES_STATUS_PARAM_ERROR if any input parameters is invalid. 
 * @return OES_STATUS_NO_RESOURCES if no FDB resousces 
 *         available to create entry . 
 * @return OES_STATUS_ERROR general error.
 */
oes_status_e 
oes_api_fdb_uc_mac_addr_set(
                           const enum oes_access_cmd access_cmd,
                           const int br_id,
                           struct oes_fdb_uc_mac_addr_params * mac_entry_list_p,
                           unsigned short * mac_cnt,
                           void * fdb_uc_mac_addr_vs_ext
                           );

/**
 * This function reads MAC entries from the SDK 
 * function can receive three types of input: 
 *     1) get information for specific mac address ,user
 *      should insert the certain mac address as the
 *      firstmac_entry_list  element in the mac_entry_list array
 *      ,mac_cnt should be equal to 1, access_cmd should be
 *      OES_ACCESS_CMD_GET
 *
 *   - 2) get a list of first n mac entries ,user
 *      should provide an empty  mac_entry_list  array mac_cnt
 *      should be equal to n,access_cmd should be
 *      OES_ACCESS_CMD_GET_FIRST
 *
 *   - 3) get a list of n  mac entries  which comes after
 *      given mac address(it does not have to exist) user should
 *      insert the specific  mac address  as the first
 *      mac_entry_list element in the mac_entry_list array ,
 *      mac_cnt should be equal to n, access_cmd should be
 *      OES_ACCESS_CMD_GET_NEXT
 *  
 * @param[in] access_cmd - GET/GET NEXT/GET FIRST. 
 * @param[in] br_id - Bridge id   
 * @param[out] mac_entry_list_p - mac record arry pointer . On 
 *       deletion, entry_type is DONT_CARE
 * @param[in] mac_cnt_p - mac record arry size  
 * @param[in,out] fdb_uc_mac_addr_vs_ext - vendor specific 
 *       extention
 * @return OES_STATUS_SUCCESS - Operation completes successfully
 * @return OES_STATUS_PARAM_ERROR if any input parameters is invalid..
 * @return OES_STATUS_ERROR general error. 
 */
oes_status_e 
oes_api_fdb_uc_mac_addr_get(
                           const enum oes_access_cmd access_cmd,
                           const int br_id,
                           struct oes_fdb_uc_mac_addr_params * mac_entry_list_p,
                           unsigned short  * mac_cnt_p,
                           void * fdb_uc_mac_addr_vs_ext
                           );

/**
 *  This function counts all MAC entries in SW FDB table (static + dynamic).
 * 
 * @param[in] br_id - Bridge id 
 * @param[out] mac_cnt_p- retrieved number of entries 
 * @param[in,out] fdb_uc_count_vs_ext - vendor specific 
 *       extention
 *  
 * @return OES_STATUS_SUCCESS - Operation completes successfully
 * @return OES_STATUS_PARAM_ERROR if any input parameters is invalid.
 * @return OES_STATUS_ERROR general error. 
 */
oes_status_e 
oes_api_fdb_uc_count(
                    const int br_id,
                    unsigned short  * mac_cnt_p,
                    void * fdb_uc_count_vs_ext
                    );

/**
 * This function sets/removes limit on the amount of dynamic MACs learned on port. 
 *  
 * @param[in] access_cmd - SET/DELETE
 * @param[in] br_id - Bridge id 
 * @param[in] log_port - logical port ID
 * @param[in] limit - When SET command is used, this is the new limit to set
 *                    (between 0 and OES_FDB_MAX_ENTRIES)
 * @param[in,out] fdb_uc_limit_port_vs_ext- vendor specific 
 *       extention
 *  
 * @return OES_STATUS_SUCCESS - Operation completes successfully
 * @return OES_STATUS_PARAM_ERROR if any input parameters is invalid.
 * @return OES_STATUS_ERROR general error. 
 */
oes_status_e
oes_api_fdb_uc_limit_port_set(
                             const enum oes_access_cmd   access_cmd,
                             const int br_id,
                             const unsigned long  log_port,
                             const unsigned int     limit,
                             void * fdb_uc_limit_port_vs_ext
                             );

/**
 * This function sets/removes limit on the amount of dynamic 
 * MACs learned on VID. 
 * 
 * @param[in] access_cmd - SET/DELETE 
 * @param[in] br_id - Bridge id 
 * @param[in] vid - vlan ID 
 * @param[in] limit - When SET command is used, this is the new limit to set
 *                    (between 0 and OES_FDB_MAX_ENTRIES)
 * @param[in,out] fdb_uc_limit_vlan_vs_ext- vendor specific 
 *       extention
 *  
 * @return OES_STATUS_SUCCESS - Operation completes successfully
 * @return OES_STATUS_PARAM_ERROR if any input parameters is invalid.
 * @return OES_STATUS_ERROR general error. 
 */
oes_status_e
oes_api_fdb_uc_limit_vlan_set(
                             const enum oes_access_cmd   access_cmd,
                             const int br_id,
                             const unsigned short     vid,
                             const unsigned int       limit,
                             void * fdb_uc_limit_port_vs_ext
                             );

/**
 * This function returns the maximum amount of dynamic MACs that can be learned on port.
 *
 * @param[in] br_id - Bridge id 
 * @param[in] log_port - logical port ID
 * @param[out] limit_p- the limit configure on the port 
 * @param[in,out] ffdb_uc_limit_port_vs_ext- vendor specific 
 *       extention
 * 
 * @return OES_STATUS_SUCCESS - Operation completes successfully
 * @return OES_STATUS_PARAM_ERROR if any input parameters is invalid.
 * @return OES_STATUS_ERROR general error. 
 */
oes_status_e
oes_api_fdb_uc_limit_port_get(
                             const int br_id,
                             const unsigned long  log_port,
                             unsigned int   *   limit_p,
                             void * fdb_uc_limit_port_vs_ext
                             );

/**
 * This function returns the maximum amount of dynamic MACs that 
 * can be learned on VID. 
 *  
 * @param[in] br_id - Bridge id  
 * @param[in]  vid- Vlan ID 
 * @param[out] limit_p - the limit configure on the port 
 * @param[in,out] fdb_uc_limit_vlan_vs_ext- vendor specific 
 *       extention
 *  
 * @return OES_STATUS_SUCCESS - Operation completes successfully
 * @return OES_STATUS_PARAM_ERROR if any input parameters is invalid.
 * @return OES_STATUS_ERROR general error. 
 */
oes_status_e
oes_api_fdb_uc_limit_vid_get(
                            const int br_id,
                            const unsigned short  vid,
                            unsigned int    * limit_p,
                            void * fdb_uc_limit_vid_vs_ext
                            );

/**
 * This function adds, deletes MC MAC entries from the FDB. 
 *  
 * @param[in] access_cmd - ADD/DELETE (
 * @param[in] br_id - bridge id 
 * @param[in] vid - vlan ID 
 * @param[in] mac_addr - multicast group  MAC address 
 * @param[in] log_port_list_p- a pointer to a port list arry
 * @param[in] port_cnt - sizeof port list
 * @param[in,out] fdb_mc_mac_addr_vs_ext- vendor specific 
 *       extention
 *  
 * @return OES_STATUS_SUCCESS - Operation completes successfully
 * @return OES_STATUS_PARAM_ERROR if any input parameters is invalid. 
 * @return OES_STATUS_NO_RESOURCES if no FDB resousces 
 *         available to create entry .
 * @return OES_STATUS_ERROR general error.
 */
oes_status_e 
oes_api_fdb_mc_mac_addr_set(
                           const enum oes_access_cmd access_cmd,
                           const int br_id,
                           const unsigned short vid,
                           const struct ether_addr  mc_addr,
                           const unsigned long * log_port_list_p,
                           const unsigned short port_cnt,
                           void * fdb_mc_mac_addr_vs_ext
                           );


/**
*  This function returns MC MAC entries data.
*  
 * @param[in] br_id - bridge id
 * @param[in] vid - vlan ID 
 * @param[in] mac_addr - multicast group  MAC address 
 * @param[out] log_port_list_p- a pointer to a port list arry
*  @param[out] port_cnt_p - sizeof port list
*  @param[in,out] fdb_mc_mac_addr_vs_ext- vendor specific 
*        extention
*  
 * @return OES_STATUS_SUCCESS - Operation completes successfully
 * @return OES_STATUS_PARAM_ERROR if any input parameters is invalid.
 * @return OES_STATUS_ERROR general error.
 */

oes_status_e 
oes_api_fdb_mc_mac_addr_get(
                           const int br_id,
                           const unsigned short vid,
                           const struct ether_addr mc_addr,
                           unsigned long * log_port_list_p,
                           unsigned short  *    port_cnt_p,
                           void * fdb_mc_mac_addr_vs_ext
                           );


/**
 * This function deletes all FDB table on a switch partition. 
 *  
 * @param[in] br_id - bridge id 
 * @param[in,out] fdb_uc_flush_vs_ext- vendor specific 
 *       extention
 *  
 * @return OES_STATUS_SUCCESS if operation completes successfully. 
 * @return OES_STATUS_PARAM_ERROR if parameters exceed range. 
 * @return OES_STATUS_ERROR general error.
 */
oes_status_e 
oes_api_fdb_uc_flush_set(
                        const int br_id,
                        void * fdb_uc_flush_vs_ext
                        );

/**
 *  This function deletes the FDB table entries that are related
 *  to a flushed port.
 *  
 * @param[in] br_id - bridge id 
 * @param[in] log_port- logical port ID
 * @param[in,out] fdb_uc_flush_port_vs_ext- vendor specific 
 *       extention
 *  
 * @return OES_STATUS_SUCCESS if operation completes successfully. 
 * @return OES_STATUS_PARAM_ERROR if parameters exceed range. 
 * @return OES_STATUS_ERROR general error.
 *
 */
oes_status_e 
oes_api_fdb_uc_flush_port_set(
                             const int br_id,
                             const unsigned long log_port,
                             void * fdb_uc_flush_port_vs_ext
                             );

/**
 * This function deletes all FDB table entries that were 
 * learnedon the flushed VID
 *  
 * @param[in] br_id - bridge id 
 * @param[in] vid- vlan ID
 * @param[in,out] fdb_uc_flush_vid_vs_ext- vendor specific 
 *       extention
 *  
 * @return OES_STATUS_SUCCESS if operation completes successfully. 
 * @return OES_STATUS_PARAM_ERROR if any input parameters is invalid.
 * @return OES_STATUS_ERROR general error.
 *
 */
oes_status_e 
oes_api_fdb_uc_flush_vid_set(
                            const int br_id,
                            const unsigned short vid,
                            void * fdb_uc_flush_vid_vs_ext
                            );

/**
 * This function deletes all FDB table entries that were 
 * learnedon the flushed VID and port. 
 *  
 * @param[in] br_id - bridge id 
 * @param[in] vid- vlan ID 
 * @param[in] log_port- logical port ID 
 * @param[in,out] fdb_uc_flush_port_vid_vs_ext- vendor specific 
 *       extention
 *  
 * @return OES_STATUS_SUCCESS if operation completes successfully. 
 * @return OES_STATUS_PARAM_ERROR if any input parameters is invalid.
 * @return OES_STATUS_ERROR general error.
 */
oes_status_e 
oes_api_fdb_uc_flush_port_vid_set(
                                 const int br_id,
                                 const unsigned short vid,
                                 const unsigned long log_port,
                                 void * fdb_uc_flush_port_vid_vs_ext
                                 );


/**
 * This function deletes all FDB MC tables on a switch
 *  partition.
 *  
 * @param[in] br_id - bridge id  
 * @param[in,out] fdb_mc_flush_vs_ext- vendor specific extention 
 *  
 * @return OES_STATUS_SUCCESS if operation completes successfully. 
 * @return OES_STATUS_PARAM_ERROR if any input parameters is invalid.
 * @return OES_STATUS_ERROR general error.
 */
oes_status_e 
oes_api_fdb_mc_flush_all_set(
                            const int br_id,
                            void * fdb_mc_flush_vs_ext
                            );

/**
 * This function deletes all FDB MC table entries that 
 * werelearned on the flushed VID, on a switch partition. 
 *  
 * @param[in] br_id - bridge id 
 * @param[in] vid - Vlan ID 
 * @param[in,out] fdb_mc_vid_flush_vs_ext- vendor specific 
 *       extention
 *  
 * @return OES_STATUS_SUCCESS if operation completes successfully. 
 * @return OES_STATUS_PARAM_ERROR if any input parameters is invalid.
 * @return OES_STATUS_ERROR general error.
*/
oes_status_e 
oes_api_fdb_mc_flush_vid_set(
                            const int br_id,
                            const unsigned short vid,
                            void * fdb_mc_vid_flush_vs_ext
                            );
/**
 *  This function sets the FDB learning mode 
 *  to disable learning or enable controlled,automatic  learning
 *  
 *  @param[in] br_id  - bridge id
 *  @param[in] learn_mode - enumerator for the following values:
 *       dont_learn, automatic_learnin, controled_learn,
 * @param[in,out] fdb_learn_mode_set_vs_ext- vendor specific 
 *       extention
 *  
 * @return OES_STATUS_SUCCESS if operation completes successfully. 
 * @return OES_STATUS_PARAM_ERROR if any input parameters is invalid.
 * @return OES_STATUS_ERROR general error.
 */
oes_status_e 
oes_api_fdb_learn_mode_set(
                          const int br_id,
                          const enum oes_fdb_learn_mode learn_mode,
                          void * fdb_learn_mode_set_vs_ext
                          );

/**
 * This function gets  the FDB learning mode to disable learning
 * or enable controlled,automatic  learning 
 *  
 * @param[in] br_id - bridge id
 * @param[out] learn_mode- enumerator for the following
 *       values: dont_learn, automatic_learnin, controled_learn,
 * @param[in,out] fdb_learn_mode_set_vs_ext- vendor specific 
 *       extention
 *  
 * @return OES_STATUS_SUCCESS if operation completes successfully. 
 * @return OES_STATUS_PARAM_ERROR if any input parameters is invalid.
 * @return OES_STATUS_ERROR general error.
 */
oes_status_e 
oes_api_fdb_learn_mode_get(
                          const int br_id,
                          const enum oes_fdb_learn_mode *learn_mode_p,
                          void * fdb_learn_mode_set_vs_ext
                          );



/**
 *  This function sets the FDB learning mode 
 *  to disable learning or enable controlled,automatic  learning
 *  
 *  @param[in] br_id - bridge id
 *  @param[in] vid - vlan ID 
 *  @param[in] learn_mode - enumerator for the following values:
 *       dont_learn, automatic_learnin, controled_learn,
 * @param[in,out] fdb_learn_mode_set_vs_ext- vendor specific 
 *       extention
 *  
 * @return OES_STATUS_SUCCESS if operation completes successfully. 
 * @return OES_STATUS_PARAM_ERROR if any input parameters is invalid.
 * @return OES_STATUS_ERROR general error.
 */
oes_status_e 
oes_api_fdb_vid_learn_mode_set(
                              const int br_id,
                              const unsigned long vid,
                              const enum oes_fdb_learn_mode learn_mode,
                              void * fdb_vid_learn_mode_set_vs_ext
                              );

/**
 *  This function gets  the FDB learning mode to disable
 *  learning or enable controlled,automatic  learning
 *  
 *  @param[in] br_id  - bridge id
 *  @param[in] vid   - vlan ID 
 *  @param[out] learn_mode_p- enumerator for the following
 *       values: dont_learn, automatic_learnin, controled_learn,
 * @param[in,out] fdb_learn_mode_set_vs_ext- vendor specific 
 *       extention
 *  
 * @return OES_STATUS_SUCCESS if operation completes successfully. 
 * @return OES_STATUS_PARAM_ERROR if any input parameters is invalid.
 * @return OES_STATUS_ERROR general error.
 */
oes_status_e 
oes_api_fdb_vid_learn_mode_get(
                              const int br_id,
                              const unsigned long vid,
                              enum oes_fdb_learn_mode * learn_mode_p,
                              void * fdb_vid_learn_mode_set_vs_ext
                              );


/**
 * This function sets the FDB learning mode to disable learning 
 * or enable controlled,automatic  learning 
 *  
 * @param[in] br_id  - bridge id
 * @param[in] log_port  - logical port ID 
 * @param[in] learn_mode - enumerator for the following values:
 *       dont_learn, automatic_learnin, controled_learn,
 * @param[in,out] fdb_port_learn_mode_set_vs_ext- vendor 
 *       specific extention
 *  
 * @return OES_STATUS_SUCCESS if operation completes successfully. 
 * @return OES_STATUS_PARAM_ERROR if any input parameters is invalid.
 * @return OES_STATUS_ERROR general error.
 */
oes_status_e 
oes_api_fdb_port_learn_mode_set(
                               const int br_id,
                               const unsigned long log_port,
                               const enum oes_fdb_learn_mode learn_mode,
                               void * fdb_port_learn_mode_set_vs_ext
                               );

/**
 * This function gets  the FDB learning mode to disable learning
 * or enable controlled,automatic  learning 
 *  
 * @param[in] br_id  - bridge id
 * @param[in] log_port  - logical port ID 
 * @param[out] learn_mode_p- enumerator for the following
 *       values: dont_learn, automatic_learnin, controled_learn,
 * @param[in,out] fdb_port_learn_mode_set_vs_ext- vendor 
 *       specific extention
 *  
 * @return OES_STATUS_SUCCESS if operation completes successfully. 
 * @return OES_STATUS_PARAM_ERROR if any input parameters is invalid.
 * @return OES_STATUS_ERROR general error.
 */
oes_status_e 
oes_api_fdb_port_learn_mode_get(
                               const int br_id,
                               const unsigned long log_port,
                               enum oes_fdb_learn_mode * learn_mode_p,
                               void * fdb_port_learn_mode_set_vs_ext
                               );

#endif /* __OES_API_FDB_H__ */
