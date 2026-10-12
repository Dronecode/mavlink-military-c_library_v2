#pragma once
// MESSAGE ENGAGEMENT_DIRECTIVE PACKING

#include <stdint.h>

#define MAVLINK_MSG_ID_ENGAGEMENT_DIRECTIVE 53023


typedef struct __mavlink_engagement_directive_t {
 uint64_t time_usec; /*< [us] Timestamp (UNIX epoch, microseconds UTC).*/
 uint32_t effector_id; /*<  Effector the directive is addressed to. 0 = all assigned.*/
 int32_t retarget_lat; /*< [degE7] New target latitude for RETARGET, WGS84. INT32_MAX = not provided (0,0 is a valid coordinate). Ignored unless directive is RETARGET.*/
 int32_t retarget_lon; /*< [degE7] New target longitude for RETARGET, WGS84. INT32_MAX = not provided. Ignored unless directive is RETARGET.*/
 float retarget_alt; /*< [m] New target altitude for RETARGET, MSL. NaN = not provided. Ignored unless directive is RETARGET.*/
 uint16_t sequence; /*<  Fire mission sequence number the directive applies to. For MAVLINK_M_ENGAGEMENT_DIRECTIVE_ABORT and MAVLINK_M_ENGAGEMENT_DIRECTIVE_CHECK_FIRE, 0xFFFF means every fire mission the receiving system holds.*/
 uint8_t target_system; /*<  System ID of the intended recipient. 0 (every system) is valid only for MAVLINK_M_ENGAGEMENT_DIRECTIVE_ABORT and MAVLINK_M_ENGAGEMENT_DIRECTIVE_CHECK_FIRE; receivers ignore any other directive sent with 0.*/
 uint8_t target_component; /*<  Component ID of the intended recipient within target_system. 0 = every component of that system. Ignored when target_system is 0.*/
 uint8_t track_uid[16]; /*<  Track UID the directive applies to. All-zero if addressed by sequence only. A MAVLINK_M_ENGAGEMENT_DIRECTIVE_ABORT or MAVLINK_M_ENGAGEMENT_DIRECTIVE_CHECK_FIRE applies to every engagement that matches its sequence or its nonzero track_uid, whoever issued that engagement, and is never declined because one selector does not match. A MAVLINK_M_ENGAGEMENT_DIRECTIVE_RESUME or MAVLINK_M_ENGAGEMENT_DIRECTIVE_RETARGET applies only to an engagement that matches every selector it carries.*/
 uint8_t directive; /*<  Directive type.*/
 uint8_t origin_sysid; /*<  System ID of the system that first issued the directive. A system that passes the directive on as a message of its own keeps this value, so it can differ from the source system ID in the frame header; routers never change either. Not authenticated: for display and audit, never a reason to act or not to act on the directive.*/
} mavlink_engagement_directive_t;

#define MAVLINK_MSG_ID_ENGAGEMENT_DIRECTIVE_LEN 46
#define MAVLINK_MSG_ID_ENGAGEMENT_DIRECTIVE_MIN_LEN 46
#define MAVLINK_MSG_ID_53023_LEN 46
#define MAVLINK_MSG_ID_53023_MIN_LEN 46

#define MAVLINK_MSG_ID_ENGAGEMENT_DIRECTIVE_CRC 57
#define MAVLINK_MSG_ID_53023_CRC 57

#define MAVLINK_MSG_ENGAGEMENT_DIRECTIVE_FIELD_TRACK_UID_LEN 16

#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_ENGAGEMENT_DIRECTIVE { \
    53023, \
    "ENGAGEMENT_DIRECTIVE", \
    11, \
    {  { "time_usec", NULL, MAVLINK_TYPE_UINT64_T, 0, 0, offsetof(mavlink_engagement_directive_t, time_usec) }, \
         { "target_system", NULL, MAVLINK_TYPE_UINT8_T, 0, 26, offsetof(mavlink_engagement_directive_t, target_system) }, \
         { "target_component", NULL, MAVLINK_TYPE_UINT8_T, 0, 27, offsetof(mavlink_engagement_directive_t, target_component) }, \
         { "track_uid", NULL, MAVLINK_TYPE_UINT8_T, 16, 28, offsetof(mavlink_engagement_directive_t, track_uid) }, \
         { "sequence", NULL, MAVLINK_TYPE_UINT16_T, 0, 24, offsetof(mavlink_engagement_directive_t, sequence) }, \
         { "effector_id", NULL, MAVLINK_TYPE_UINT32_T, 0, 8, offsetof(mavlink_engagement_directive_t, effector_id) }, \
         { "retarget_lat", NULL, MAVLINK_TYPE_INT32_T, 0, 12, offsetof(mavlink_engagement_directive_t, retarget_lat) }, \
         { "retarget_lon", NULL, MAVLINK_TYPE_INT32_T, 0, 16, offsetof(mavlink_engagement_directive_t, retarget_lon) }, \
         { "retarget_alt", NULL, MAVLINK_TYPE_FLOAT, 0, 20, offsetof(mavlink_engagement_directive_t, retarget_alt) }, \
         { "directive", NULL, MAVLINK_TYPE_UINT8_T, 0, 44, offsetof(mavlink_engagement_directive_t, directive) }, \
         { "origin_sysid", NULL, MAVLINK_TYPE_UINT8_T, 0, 45, offsetof(mavlink_engagement_directive_t, origin_sysid) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_ENGAGEMENT_DIRECTIVE { \
    "ENGAGEMENT_DIRECTIVE", \
    11, \
    {  { "time_usec", NULL, MAVLINK_TYPE_UINT64_T, 0, 0, offsetof(mavlink_engagement_directive_t, time_usec) }, \
         { "target_system", NULL, MAVLINK_TYPE_UINT8_T, 0, 26, offsetof(mavlink_engagement_directive_t, target_system) }, \
         { "target_component", NULL, MAVLINK_TYPE_UINT8_T, 0, 27, offsetof(mavlink_engagement_directive_t, target_component) }, \
         { "track_uid", NULL, MAVLINK_TYPE_UINT8_T, 16, 28, offsetof(mavlink_engagement_directive_t, track_uid) }, \
         { "sequence", NULL, MAVLINK_TYPE_UINT16_T, 0, 24, offsetof(mavlink_engagement_directive_t, sequence) }, \
         { "effector_id", NULL, MAVLINK_TYPE_UINT32_T, 0, 8, offsetof(mavlink_engagement_directive_t, effector_id) }, \
         { "retarget_lat", NULL, MAVLINK_TYPE_INT32_T, 0, 12, offsetof(mavlink_engagement_directive_t, retarget_lat) }, \
         { "retarget_lon", NULL, MAVLINK_TYPE_INT32_T, 0, 16, offsetof(mavlink_engagement_directive_t, retarget_lon) }, \
         { "retarget_alt", NULL, MAVLINK_TYPE_FLOAT, 0, 20, offsetof(mavlink_engagement_directive_t, retarget_alt) }, \
         { "directive", NULL, MAVLINK_TYPE_UINT8_T, 0, 44, offsetof(mavlink_engagement_directive_t, directive) }, \
         { "origin_sysid", NULL, MAVLINK_TYPE_UINT8_T, 0, 45, offsetof(mavlink_engagement_directive_t, origin_sysid) }, \
         } \
}
#endif

/**
 * @brief Pack a engagement_directive message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param time_usec [us] Timestamp (UNIX epoch, microseconds UTC).
 * @param target_system  System ID of the intended recipient. 0 (every system) is valid only for MAVLINK_M_ENGAGEMENT_DIRECTIVE_ABORT and MAVLINK_M_ENGAGEMENT_DIRECTIVE_CHECK_FIRE; receivers ignore any other directive sent with 0.
 * @param target_component  Component ID of the intended recipient within target_system. 0 = every component of that system. Ignored when target_system is 0.
 * @param track_uid  Track UID the directive applies to. All-zero if addressed by sequence only. A MAVLINK_M_ENGAGEMENT_DIRECTIVE_ABORT or MAVLINK_M_ENGAGEMENT_DIRECTIVE_CHECK_FIRE applies to every engagement that matches its sequence or its nonzero track_uid, whoever issued that engagement, and is never declined because one selector does not match. A MAVLINK_M_ENGAGEMENT_DIRECTIVE_RESUME or MAVLINK_M_ENGAGEMENT_DIRECTIVE_RETARGET applies only to an engagement that matches every selector it carries.
 * @param sequence  Fire mission sequence number the directive applies to. For MAVLINK_M_ENGAGEMENT_DIRECTIVE_ABORT and MAVLINK_M_ENGAGEMENT_DIRECTIVE_CHECK_FIRE, 0xFFFF means every fire mission the receiving system holds.
 * @param effector_id  Effector the directive is addressed to. 0 = all assigned.
 * @param retarget_lat [degE7] New target latitude for RETARGET, WGS84. INT32_MAX = not provided (0,0 is a valid coordinate). Ignored unless directive is RETARGET.
 * @param retarget_lon [degE7] New target longitude for RETARGET, WGS84. INT32_MAX = not provided. Ignored unless directive is RETARGET.
 * @param retarget_alt [m] New target altitude for RETARGET, MSL. NaN = not provided. Ignored unless directive is RETARGET.
 * @param directive  Directive type.
 * @param origin_sysid  System ID of the system that first issued the directive. A system that passes the directive on as a message of its own keeps this value, so it can differ from the source system ID in the frame header; routers never change either. Not authenticated: for display and audit, never a reason to act or not to act on the directive.
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_engagement_directive_pack(uint32_t system_id, uint8_t component_id, mavlink_message_t* msg,
                               uint64_t time_usec, uint32_t target_system, uint8_t target_component, const uint8_t *track_uid, uint16_t sequence, uint32_t effector_id, int32_t retarget_lat, int32_t retarget_lon, float retarget_alt, uint8_t directive, uint8_t origin_sysid)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_ENGAGEMENT_DIRECTIVE_LEN];
    _mav_put_uint64_t(buf, 0, time_usec);
    _mav_put_uint32_t(buf, 8, effector_id);
    _mav_put_int32_t(buf, 12, retarget_lat);
    _mav_put_int32_t(buf, 16, retarget_lon);
    _mav_put_float(buf, 20, retarget_alt);
    _mav_put_uint16_t(buf, 24, sequence);
    _mav_put_uint8_t(buf, 26, mavlink_msg_target_field(target_system));
    _mav_put_uint8_t(buf, 27, target_component);
    _mav_put_uint8_t(buf, 44, directive);
    _mav_put_uint8_t(buf, 45, origin_sysid);
    _mav_put_uint8_t_array(buf, 28, track_uid, 16);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_ENGAGEMENT_DIRECTIVE_LEN);
#else
    mavlink_engagement_directive_t packet;
    packet.time_usec = time_usec;
    packet.effector_id = effector_id;
    packet.retarget_lat = retarget_lat;
    packet.retarget_lon = retarget_lon;
    packet.retarget_alt = retarget_alt;
    packet.sequence = sequence;
    packet.target_system = mavlink_msg_target_field(target_system);
    packet.target_component = target_component;
    packet.directive = directive;
    packet.origin_sysid = origin_sysid;
    mav_array_memcpy(packet.track_uid, track_uid, sizeof(uint8_t)*16);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_ENGAGEMENT_DIRECTIVE_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_ENGAGEMENT_DIRECTIVE;
    return mavlink_finalize_message_target(msg, system_id, component_id, MAVLINK_MSG_ID_ENGAGEMENT_DIRECTIVE_MIN_LEN, MAVLINK_MSG_ID_ENGAGEMENT_DIRECTIVE_LEN, MAVLINK_MSG_ID_ENGAGEMENT_DIRECTIVE_CRC, target_system);
}

/**
 * @brief Pack a engagement_directive message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param status MAVLink status structure
 * @param msg The MAVLink message to compress the data into
 *
 * @param time_usec [us] Timestamp (UNIX epoch, microseconds UTC).
 * @param target_system  System ID of the intended recipient. 0 (every system) is valid only for MAVLINK_M_ENGAGEMENT_DIRECTIVE_ABORT and MAVLINK_M_ENGAGEMENT_DIRECTIVE_CHECK_FIRE; receivers ignore any other directive sent with 0.
 * @param target_component  Component ID of the intended recipient within target_system. 0 = every component of that system. Ignored when target_system is 0.
 * @param track_uid  Track UID the directive applies to. All-zero if addressed by sequence only. A MAVLINK_M_ENGAGEMENT_DIRECTIVE_ABORT or MAVLINK_M_ENGAGEMENT_DIRECTIVE_CHECK_FIRE applies to every engagement that matches its sequence or its nonzero track_uid, whoever issued that engagement, and is never declined because one selector does not match. A MAVLINK_M_ENGAGEMENT_DIRECTIVE_RESUME or MAVLINK_M_ENGAGEMENT_DIRECTIVE_RETARGET applies only to an engagement that matches every selector it carries.
 * @param sequence  Fire mission sequence number the directive applies to. For MAVLINK_M_ENGAGEMENT_DIRECTIVE_ABORT and MAVLINK_M_ENGAGEMENT_DIRECTIVE_CHECK_FIRE, 0xFFFF means every fire mission the receiving system holds.
 * @param effector_id  Effector the directive is addressed to. 0 = all assigned.
 * @param retarget_lat [degE7] New target latitude for RETARGET, WGS84. INT32_MAX = not provided (0,0 is a valid coordinate). Ignored unless directive is RETARGET.
 * @param retarget_lon [degE7] New target longitude for RETARGET, WGS84. INT32_MAX = not provided. Ignored unless directive is RETARGET.
 * @param retarget_alt [m] New target altitude for RETARGET, MSL. NaN = not provided. Ignored unless directive is RETARGET.
 * @param directive  Directive type.
 * @param origin_sysid  System ID of the system that first issued the directive. A system that passes the directive on as a message of its own keeps this value, so it can differ from the source system ID in the frame header; routers never change either. Not authenticated: for display and audit, never a reason to act or not to act on the directive.
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_engagement_directive_pack_status(uint32_t system_id, uint8_t component_id, mavlink_status_t *_status, mavlink_message_t* msg,
                               uint64_t time_usec, uint32_t target_system, uint8_t target_component, const uint8_t *track_uid, uint16_t sequence, uint32_t effector_id, int32_t retarget_lat, int32_t retarget_lon, float retarget_alt, uint8_t directive, uint8_t origin_sysid)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_ENGAGEMENT_DIRECTIVE_LEN];
    _mav_put_uint64_t(buf, 0, time_usec);
    _mav_put_uint32_t(buf, 8, effector_id);
    _mav_put_int32_t(buf, 12, retarget_lat);
    _mav_put_int32_t(buf, 16, retarget_lon);
    _mav_put_float(buf, 20, retarget_alt);
    _mav_put_uint16_t(buf, 24, sequence);
    _mav_put_uint8_t(buf, 26, mavlink_msg_target_field(target_system));
    _mav_put_uint8_t(buf, 27, target_component);
    _mav_put_uint8_t(buf, 44, directive);
    _mav_put_uint8_t(buf, 45, origin_sysid);
    _mav_put_uint8_t_array(buf, 28, track_uid, 16);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_ENGAGEMENT_DIRECTIVE_LEN);
#else
    mavlink_engagement_directive_t packet;
    packet.time_usec = time_usec;
    packet.effector_id = effector_id;
    packet.retarget_lat = retarget_lat;
    packet.retarget_lon = retarget_lon;
    packet.retarget_alt = retarget_alt;
    packet.sequence = sequence;
    packet.target_system = mavlink_msg_target_field(target_system);
    packet.target_component = target_component;
    packet.directive = directive;
    packet.origin_sysid = origin_sysid;
    mav_array_memcpy(packet.track_uid, track_uid, sizeof(uint8_t)*16);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_ENGAGEMENT_DIRECTIVE_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_ENGAGEMENT_DIRECTIVE;
#if MAVLINK_CRC_EXTRA
    return mavlink_finalize_message_buffer_target(msg, system_id, component_id, _status, MAVLINK_MSG_ID_ENGAGEMENT_DIRECTIVE_MIN_LEN, MAVLINK_MSG_ID_ENGAGEMENT_DIRECTIVE_LEN, MAVLINK_MSG_ID_ENGAGEMENT_DIRECTIVE_CRC, target_system);
#else
    return mavlink_finalize_message_buffer_target(msg, system_id, component_id, _status, MAVLINK_MSG_ID_ENGAGEMENT_DIRECTIVE_MIN_LEN, MAVLINK_MSG_ID_ENGAGEMENT_DIRECTIVE_LEN, 0, target_system);
#endif
}

/**
 * @brief Pack a engagement_directive message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param time_usec [us] Timestamp (UNIX epoch, microseconds UTC).
 * @param target_system  System ID of the intended recipient. 0 (every system) is valid only for MAVLINK_M_ENGAGEMENT_DIRECTIVE_ABORT and MAVLINK_M_ENGAGEMENT_DIRECTIVE_CHECK_FIRE; receivers ignore any other directive sent with 0.
 * @param target_component  Component ID of the intended recipient within target_system. 0 = every component of that system. Ignored when target_system is 0.
 * @param track_uid  Track UID the directive applies to. All-zero if addressed by sequence only. A MAVLINK_M_ENGAGEMENT_DIRECTIVE_ABORT or MAVLINK_M_ENGAGEMENT_DIRECTIVE_CHECK_FIRE applies to every engagement that matches its sequence or its nonzero track_uid, whoever issued that engagement, and is never declined because one selector does not match. A MAVLINK_M_ENGAGEMENT_DIRECTIVE_RESUME or MAVLINK_M_ENGAGEMENT_DIRECTIVE_RETARGET applies only to an engagement that matches every selector it carries.
 * @param sequence  Fire mission sequence number the directive applies to. For MAVLINK_M_ENGAGEMENT_DIRECTIVE_ABORT and MAVLINK_M_ENGAGEMENT_DIRECTIVE_CHECK_FIRE, 0xFFFF means every fire mission the receiving system holds.
 * @param effector_id  Effector the directive is addressed to. 0 = all assigned.
 * @param retarget_lat [degE7] New target latitude for RETARGET, WGS84. INT32_MAX = not provided (0,0 is a valid coordinate). Ignored unless directive is RETARGET.
 * @param retarget_lon [degE7] New target longitude for RETARGET, WGS84. INT32_MAX = not provided. Ignored unless directive is RETARGET.
 * @param retarget_alt [m] New target altitude for RETARGET, MSL. NaN = not provided. Ignored unless directive is RETARGET.
 * @param directive  Directive type.
 * @param origin_sysid  System ID of the system that first issued the directive. A system that passes the directive on as a message of its own keeps this value, so it can differ from the source system ID in the frame header; routers never change either. Not authenticated: for display and audit, never a reason to act or not to act on the directive.
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_engagement_directive_pack_chan(uint32_t system_id, uint8_t component_id, uint8_t chan,
                               mavlink_message_t* msg,
                                   uint64_t time_usec,uint32_t target_system,uint8_t target_component,const uint8_t *track_uid,uint16_t sequence,uint32_t effector_id,int32_t retarget_lat,int32_t retarget_lon,float retarget_alt,uint8_t directive,uint8_t origin_sysid)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_ENGAGEMENT_DIRECTIVE_LEN];
    _mav_put_uint64_t(buf, 0, time_usec);
    _mav_put_uint32_t(buf, 8, effector_id);
    _mav_put_int32_t(buf, 12, retarget_lat);
    _mav_put_int32_t(buf, 16, retarget_lon);
    _mav_put_float(buf, 20, retarget_alt);
    _mav_put_uint16_t(buf, 24, sequence);
    _mav_put_uint8_t(buf, 26, mavlink_msg_target_field(target_system));
    _mav_put_uint8_t(buf, 27, target_component);
    _mav_put_uint8_t(buf, 44, directive);
    _mav_put_uint8_t(buf, 45, origin_sysid);
    _mav_put_uint8_t_array(buf, 28, track_uid, 16);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_ENGAGEMENT_DIRECTIVE_LEN);
#else
    mavlink_engagement_directive_t packet;
    packet.time_usec = time_usec;
    packet.effector_id = effector_id;
    packet.retarget_lat = retarget_lat;
    packet.retarget_lon = retarget_lon;
    packet.retarget_alt = retarget_alt;
    packet.sequence = sequence;
    packet.target_system = mavlink_msg_target_field(target_system);
    packet.target_component = target_component;
    packet.directive = directive;
    packet.origin_sysid = origin_sysid;
    mav_array_memcpy(packet.track_uid, track_uid, sizeof(uint8_t)*16);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_ENGAGEMENT_DIRECTIVE_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_ENGAGEMENT_DIRECTIVE;
    return mavlink_finalize_message_chan_target(msg, system_id, component_id, chan, MAVLINK_MSG_ID_ENGAGEMENT_DIRECTIVE_MIN_LEN, MAVLINK_MSG_ID_ENGAGEMENT_DIRECTIVE_LEN, MAVLINK_MSG_ID_ENGAGEMENT_DIRECTIVE_CRC, target_system);
}

/**
 * @brief Encode a engagement_directive struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param engagement_directive C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_engagement_directive_encode(uint32_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_engagement_directive_t* engagement_directive)
{
    return mavlink_msg_engagement_directive_pack(system_id, component_id, msg, engagement_directive->time_usec, engagement_directive->target_system, engagement_directive->target_component, engagement_directive->track_uid, engagement_directive->sequence, engagement_directive->effector_id, engagement_directive->retarget_lat, engagement_directive->retarget_lon, engagement_directive->retarget_alt, engagement_directive->directive, engagement_directive->origin_sysid);
}

/**
 * @brief Encode a engagement_directive struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param engagement_directive C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_engagement_directive_encode_chan(uint32_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_engagement_directive_t* engagement_directive)
{
    return mavlink_msg_engagement_directive_pack_chan(system_id, component_id, chan, msg, engagement_directive->time_usec, engagement_directive->target_system, engagement_directive->target_component, engagement_directive->track_uid, engagement_directive->sequence, engagement_directive->effector_id, engagement_directive->retarget_lat, engagement_directive->retarget_lon, engagement_directive->retarget_alt, engagement_directive->directive, engagement_directive->origin_sysid);
}

/**
 * @brief Encode a engagement_directive struct with provided status structure
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param status MAVLink status structure
 * @param msg The MAVLink message to compress the data into
 * @param engagement_directive C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_engagement_directive_encode_status(uint32_t system_id, uint8_t component_id, mavlink_status_t* _status, mavlink_message_t* msg, const mavlink_engagement_directive_t* engagement_directive)
{
    return mavlink_msg_engagement_directive_pack_status(system_id, component_id, _status, msg,  engagement_directive->time_usec, engagement_directive->target_system, engagement_directive->target_component, engagement_directive->track_uid, engagement_directive->sequence, engagement_directive->effector_id, engagement_directive->retarget_lat, engagement_directive->retarget_lon, engagement_directive->retarget_alt, engagement_directive->directive, engagement_directive->origin_sysid);
}

/**
 * @brief Send a engagement_directive message
 * @param chan MAVLink channel to send the message
 *
 * @param time_usec [us] Timestamp (UNIX epoch, microseconds UTC).
 * @param target_system  System ID of the intended recipient. 0 (every system) is valid only for MAVLINK_M_ENGAGEMENT_DIRECTIVE_ABORT and MAVLINK_M_ENGAGEMENT_DIRECTIVE_CHECK_FIRE; receivers ignore any other directive sent with 0.
 * @param target_component  Component ID of the intended recipient within target_system. 0 = every component of that system. Ignored when target_system is 0.
 * @param track_uid  Track UID the directive applies to. All-zero if addressed by sequence only. A MAVLINK_M_ENGAGEMENT_DIRECTIVE_ABORT or MAVLINK_M_ENGAGEMENT_DIRECTIVE_CHECK_FIRE applies to every engagement that matches its sequence or its nonzero track_uid, whoever issued that engagement, and is never declined because one selector does not match. A MAVLINK_M_ENGAGEMENT_DIRECTIVE_RESUME or MAVLINK_M_ENGAGEMENT_DIRECTIVE_RETARGET applies only to an engagement that matches every selector it carries.
 * @param sequence  Fire mission sequence number the directive applies to. For MAVLINK_M_ENGAGEMENT_DIRECTIVE_ABORT and MAVLINK_M_ENGAGEMENT_DIRECTIVE_CHECK_FIRE, 0xFFFF means every fire mission the receiving system holds.
 * @param effector_id  Effector the directive is addressed to. 0 = all assigned.
 * @param retarget_lat [degE7] New target latitude for RETARGET, WGS84. INT32_MAX = not provided (0,0 is a valid coordinate). Ignored unless directive is RETARGET.
 * @param retarget_lon [degE7] New target longitude for RETARGET, WGS84. INT32_MAX = not provided. Ignored unless directive is RETARGET.
 * @param retarget_alt [m] New target altitude for RETARGET, MSL. NaN = not provided. Ignored unless directive is RETARGET.
 * @param directive  Directive type.
 * @param origin_sysid  System ID of the system that first issued the directive. A system that passes the directive on as a message of its own keeps this value, so it can differ from the source system ID in the frame header; routers never change either. Not authenticated: for display and audit, never a reason to act or not to act on the directive.
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_engagement_directive_send(mavlink_channel_t chan, uint64_t time_usec, uint32_t target_system, uint8_t target_component, const uint8_t *track_uid, uint16_t sequence, uint32_t effector_id, int32_t retarget_lat, int32_t retarget_lon, float retarget_alt, uint8_t directive, uint8_t origin_sysid)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_ENGAGEMENT_DIRECTIVE_LEN];
    _mav_put_uint64_t(buf, 0, time_usec);
    _mav_put_uint32_t(buf, 8, effector_id);
    _mav_put_int32_t(buf, 12, retarget_lat);
    _mav_put_int32_t(buf, 16, retarget_lon);
    _mav_put_float(buf, 20, retarget_alt);
    _mav_put_uint16_t(buf, 24, sequence);
    _mav_put_uint8_t(buf, 26, mavlink_msg_target_field(target_system));
    _mav_put_uint8_t(buf, 27, target_component);
    _mav_put_uint8_t(buf, 44, directive);
    _mav_put_uint8_t(buf, 45, origin_sysid);
    _mav_put_uint8_t_array(buf, 28, track_uid, 16);
    _mav_finalize_message_chan_send_target(chan, MAVLINK_MSG_ID_ENGAGEMENT_DIRECTIVE, buf, MAVLINK_MSG_ID_ENGAGEMENT_DIRECTIVE_MIN_LEN, MAVLINK_MSG_ID_ENGAGEMENT_DIRECTIVE_LEN, MAVLINK_MSG_ID_ENGAGEMENT_DIRECTIVE_CRC, target_system);
#else
    mavlink_engagement_directive_t packet;
    packet.time_usec = time_usec;
    packet.effector_id = effector_id;
    packet.retarget_lat = retarget_lat;
    packet.retarget_lon = retarget_lon;
    packet.retarget_alt = retarget_alt;
    packet.sequence = sequence;
    packet.target_system = mavlink_msg_target_field(target_system);
    packet.target_component = target_component;
    packet.directive = directive;
    packet.origin_sysid = origin_sysid;
    mav_array_memcpy(packet.track_uid, track_uid, sizeof(uint8_t)*16);
    _mav_finalize_message_chan_send_target(chan, MAVLINK_MSG_ID_ENGAGEMENT_DIRECTIVE, (const char *)&packet, MAVLINK_MSG_ID_ENGAGEMENT_DIRECTIVE_MIN_LEN, MAVLINK_MSG_ID_ENGAGEMENT_DIRECTIVE_LEN, MAVLINK_MSG_ID_ENGAGEMENT_DIRECTIVE_CRC, target_system);
#endif
}

/**
 * @brief Send a engagement_directive message
 * @param chan MAVLink channel to send the message
 * @param struct The MAVLink struct to serialize
 */
static inline void mavlink_msg_engagement_directive_send_struct(mavlink_channel_t chan, const mavlink_engagement_directive_t* engagement_directive)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    mavlink_msg_engagement_directive_send(chan, engagement_directive->time_usec, engagement_directive->target_system, engagement_directive->target_component, engagement_directive->track_uid, engagement_directive->sequence, engagement_directive->effector_id, engagement_directive->retarget_lat, engagement_directive->retarget_lon, engagement_directive->retarget_alt, engagement_directive->directive, engagement_directive->origin_sysid);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_ENGAGEMENT_DIRECTIVE, (const char *)engagement_directive, MAVLINK_MSG_ID_ENGAGEMENT_DIRECTIVE_MIN_LEN, MAVLINK_MSG_ID_ENGAGEMENT_DIRECTIVE_LEN, MAVLINK_MSG_ID_ENGAGEMENT_DIRECTIVE_CRC);
#endif
}

#if MAVLINK_MSG_ID_ENGAGEMENT_DIRECTIVE_LEN <= MAVLINK_MAX_PAYLOAD_LEN
/*
  This variant of _send() can be used to save stack space by reusing
  memory from the receive buffer.  The caller provides a
  mavlink_message_t which is the size of a full mavlink message. This
  is usually the receive buffer for the channel, and allows a reply to an
  incoming message with minimum stack space usage.
 */
static inline void mavlink_msg_engagement_directive_send_buf(mavlink_message_t *msgbuf, mavlink_channel_t chan,  uint64_t time_usec, uint32_t target_system, uint8_t target_component, const uint8_t *track_uid, uint16_t sequence, uint32_t effector_id, int32_t retarget_lat, int32_t retarget_lon, float retarget_alt, uint8_t directive, uint8_t origin_sysid)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char *buf = (char *)msgbuf;
    _mav_put_uint64_t(buf, 0, time_usec);
    _mav_put_uint32_t(buf, 8, effector_id);
    _mav_put_int32_t(buf, 12, retarget_lat);
    _mav_put_int32_t(buf, 16, retarget_lon);
    _mav_put_float(buf, 20, retarget_alt);
    _mav_put_uint16_t(buf, 24, sequence);
    _mav_put_uint8_t(buf, 26, mavlink_msg_target_field(target_system));
    _mav_put_uint8_t(buf, 27, target_component);
    _mav_put_uint8_t(buf, 44, directive);
    _mav_put_uint8_t(buf, 45, origin_sysid);
    _mav_put_uint8_t_array(buf, 28, track_uid, 16);
    _mav_finalize_message_chan_send_target(chan, MAVLINK_MSG_ID_ENGAGEMENT_DIRECTIVE, buf, MAVLINK_MSG_ID_ENGAGEMENT_DIRECTIVE_MIN_LEN, MAVLINK_MSG_ID_ENGAGEMENT_DIRECTIVE_LEN, MAVLINK_MSG_ID_ENGAGEMENT_DIRECTIVE_CRC, target_system);
#else
    mavlink_engagement_directive_t *packet = (mavlink_engagement_directive_t *)msgbuf;
    packet->time_usec = time_usec;
    packet->effector_id = effector_id;
    packet->retarget_lat = retarget_lat;
    packet->retarget_lon = retarget_lon;
    packet->retarget_alt = retarget_alt;
    packet->sequence = sequence;
    packet->target_system = mavlink_msg_target_field(target_system);
    packet->target_component = target_component;
    packet->directive = directive;
    packet->origin_sysid = origin_sysid;
    mav_array_memcpy(packet->track_uid, track_uid, sizeof(uint8_t)*16);
    _mav_finalize_message_chan_send_target(chan, MAVLINK_MSG_ID_ENGAGEMENT_DIRECTIVE, (const char *)packet, MAVLINK_MSG_ID_ENGAGEMENT_DIRECTIVE_MIN_LEN, MAVLINK_MSG_ID_ENGAGEMENT_DIRECTIVE_LEN, MAVLINK_MSG_ID_ENGAGEMENT_DIRECTIVE_CRC, target_system);
#endif
}
#endif

#endif

// MESSAGE ENGAGEMENT_DIRECTIVE UNPACKING


/**
 * @brief Get field time_usec from engagement_directive message
 *
 * @return [us] Timestamp (UNIX epoch, microseconds UTC).
 */
static inline uint64_t mavlink_msg_engagement_directive_get_time_usec(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint64_t(msg,  0);
}

/**
 * @brief Get field target_component from engagement_directive message
 *
 * @return  Component ID of the intended recipient within target_system. 0 = every component of that system. Ignored when target_system is 0.
 */
static inline uint8_t mavlink_msg_engagement_directive_get_target_component(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  27);
}

/**
 * @brief Get field track_uid from engagement_directive message
 *
 * @return  Track UID the directive applies to. All-zero if addressed by sequence only. A MAVLINK_M_ENGAGEMENT_DIRECTIVE_ABORT or MAVLINK_M_ENGAGEMENT_DIRECTIVE_CHECK_FIRE applies to every engagement that matches its sequence or its nonzero track_uid, whoever issued that engagement, and is never declined because one selector does not match. A MAVLINK_M_ENGAGEMENT_DIRECTIVE_RESUME or MAVLINK_M_ENGAGEMENT_DIRECTIVE_RETARGET applies only to an engagement that matches every selector it carries.
 */
static inline uint16_t mavlink_msg_engagement_directive_get_track_uid(const mavlink_message_t* msg, uint8_t *track_uid)
{
    return _MAV_RETURN_uint8_t_array(msg, track_uid, 16,  28);
}

/**
 * @brief Get field sequence from engagement_directive message
 *
 * @return  Fire mission sequence number the directive applies to. For MAVLINK_M_ENGAGEMENT_DIRECTIVE_ABORT and MAVLINK_M_ENGAGEMENT_DIRECTIVE_CHECK_FIRE, 0xFFFF means every fire mission the receiving system holds.
 */
static inline uint16_t mavlink_msg_engagement_directive_get_sequence(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint16_t(msg,  24);
}

/**
 * @brief Get field effector_id from engagement_directive message
 *
 * @return  Effector the directive is addressed to. 0 = all assigned.
 */
static inline uint32_t mavlink_msg_engagement_directive_get_effector_id(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint32_t(msg,  8);
}

/**
 * @brief Get field retarget_lat from engagement_directive message
 *
 * @return [degE7] New target latitude for RETARGET, WGS84. INT32_MAX = not provided (0,0 is a valid coordinate). Ignored unless directive is RETARGET.
 */
static inline int32_t mavlink_msg_engagement_directive_get_retarget_lat(const mavlink_message_t* msg)
{
    return _MAV_RETURN_int32_t(msg,  12);
}

/**
 * @brief Get field retarget_lon from engagement_directive message
 *
 * @return [degE7] New target longitude for RETARGET, WGS84. INT32_MAX = not provided. Ignored unless directive is RETARGET.
 */
static inline int32_t mavlink_msg_engagement_directive_get_retarget_lon(const mavlink_message_t* msg)
{
    return _MAV_RETURN_int32_t(msg,  16);
}

/**
 * @brief Get field retarget_alt from engagement_directive message
 *
 * @return [m] New target altitude for RETARGET, MSL. NaN = not provided. Ignored unless directive is RETARGET.
 */
static inline float mavlink_msg_engagement_directive_get_retarget_alt(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  20);
}

/**
 * @brief Get field directive from engagement_directive message
 *
 * @return  Directive type.
 */
static inline uint8_t mavlink_msg_engagement_directive_get_directive(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  44);
}

/**
 * @brief Get field origin_sysid from engagement_directive message
 *
 * @return  System ID of the system that first issued the directive. A system that passes the directive on as a message of its own keeps this value, so it can differ from the source system ID in the frame header; routers never change either. Not authenticated: for display and audit, never a reason to act or not to act on the directive.
 */
static inline uint8_t mavlink_msg_engagement_directive_get_origin_sysid(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  45);
}

/**
 * @brief Decode a engagement_directive message into a struct
 *
 * @param msg The message to decode
 * @param engagement_directive C-struct to decode the message contents into
 */
static inline void mavlink_msg_engagement_directive_decode(const mavlink_message_t* msg, mavlink_engagement_directive_t* engagement_directive)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    engagement_directive->time_usec = mavlink_msg_engagement_directive_get_time_usec(msg);
    engagement_directive->effector_id = mavlink_msg_engagement_directive_get_effector_id(msg);
    engagement_directive->retarget_lat = mavlink_msg_engagement_directive_get_retarget_lat(msg);
    engagement_directive->retarget_lon = mavlink_msg_engagement_directive_get_retarget_lon(msg);
    engagement_directive->retarget_alt = mavlink_msg_engagement_directive_get_retarget_alt(msg);
    engagement_directive->sequence = mavlink_msg_engagement_directive_get_sequence(msg);
    engagement_directive->target_system = _MAV_RETURN_uint8_t(msg, 26);
    engagement_directive->target_component = mavlink_msg_engagement_directive_get_target_component(msg);
    mavlink_msg_engagement_directive_get_track_uid(msg, engagement_directive->track_uid);
    engagement_directive->directive = mavlink_msg_engagement_directive_get_directive(msg);
    engagement_directive->origin_sysid = mavlink_msg_engagement_directive_get_origin_sysid(msg);
#else
        uint8_t len = msg->len < MAVLINK_MSG_ID_ENGAGEMENT_DIRECTIVE_LEN? msg->len : MAVLINK_MSG_ID_ENGAGEMENT_DIRECTIVE_LEN;
        memset(engagement_directive, 0, MAVLINK_MSG_ID_ENGAGEMENT_DIRECTIVE_LEN);
    memcpy(engagement_directive, _MAV_PAYLOAD(msg), len);
#endif
    if (msg->incompat_flags & MAVLINK_IFLAG_TARGET32) {
        // This uint8_t field cannot retain a wide target. The sentinel is NOT reserved.
        // For routing use mavlink_msg_get_target_sysid(msg, mavlink_get_msg_entry(msg->msgid)).
        // To relay after edits, pass that full target to _pack*(); _encode*() loses it.
        engagement_directive->target_system = mavlink_msg_target_field(msg->target_sysid);
    }

}
