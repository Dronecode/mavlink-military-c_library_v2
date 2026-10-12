#pragma once
// MESSAGE ESAD_ARMING PACKING

#include <stdint.h>

#define MAVLINK_MSG_ID_ESAD_ARMING 53031


typedef struct __mavlink_esad_arming_t {
 uint64_t time_usec; /*< [us] Timestamp (UNIX epoch, microseconds UTC).*/
 uint32_t arming_challenge_hash; /*<  Challenge hash the selected ESAD advertises in ESAD_STATE. Checked for an ARM, where with esad_id = 0 every selected local ESAD must advertise it; not checked for a DISARM.*/
 uint8_t target_system; /*<  System ID of the intended recipient. 0 (every system) is valid only for MAVLINK_M_ESAD_REQUEST_DISARM, which each receiving system applies to its own ESADs; receivers ignore an arm request sent with 0.*/
 uint8_t target_component; /*<  Component ID of the intended recipient within target_system. 0 = every component of that system. Ignored when target_system is 0.*/
 uint8_t esad_id; /*<  Vehicle-local ESAD instance identifier to arm or disarm. 0 = every local ESAD selected by store_id, 1-254 = specific ESAD instance, 255 = reserved.*/
 uint8_t arming_request; /*<  Requested arming state change.*/
 uint8_t store_id; /*<  Target store instance identifier. 0 = every store on the receiving system.*/
 uint8_t track_uid[16]; /*<  Track UID (see TRACK_IDENTITY) of the engagement an ARM is for, reported back in ESAD_STATE.track_uid. All-zero if the arming is not tied to a track. Ignored for DISARM.*/
} mavlink_esad_arming_t;

#define MAVLINK_MSG_ID_ESAD_ARMING_LEN 33
#define MAVLINK_MSG_ID_ESAD_ARMING_MIN_LEN 33
#define MAVLINK_MSG_ID_53031_LEN 33
#define MAVLINK_MSG_ID_53031_MIN_LEN 33

#define MAVLINK_MSG_ID_ESAD_ARMING_CRC 3
#define MAVLINK_MSG_ID_53031_CRC 3

#define MAVLINK_MSG_ESAD_ARMING_FIELD_TRACK_UID_LEN 16

#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_ESAD_ARMING { \
    53031, \
    "ESAD_ARMING", \
    8, \
    {  { "time_usec", NULL, MAVLINK_TYPE_UINT64_T, 0, 0, offsetof(mavlink_esad_arming_t, time_usec) }, \
         { "target_system", NULL, MAVLINK_TYPE_UINT8_T, 0, 12, offsetof(mavlink_esad_arming_t, target_system) }, \
         { "target_component", NULL, MAVLINK_TYPE_UINT8_T, 0, 13, offsetof(mavlink_esad_arming_t, target_component) }, \
         { "esad_id", NULL, MAVLINK_TYPE_UINT8_T, 0, 14, offsetof(mavlink_esad_arming_t, esad_id) }, \
         { "arming_challenge_hash", NULL, MAVLINK_TYPE_UINT32_T, 0, 8, offsetof(mavlink_esad_arming_t, arming_challenge_hash) }, \
         { "arming_request", NULL, MAVLINK_TYPE_UINT8_T, 0, 15, offsetof(mavlink_esad_arming_t, arming_request) }, \
         { "store_id", NULL, MAVLINK_TYPE_UINT8_T, 0, 16, offsetof(mavlink_esad_arming_t, store_id) }, \
         { "track_uid", NULL, MAVLINK_TYPE_UINT8_T, 16, 17, offsetof(mavlink_esad_arming_t, track_uid) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_ESAD_ARMING { \
    "ESAD_ARMING", \
    8, \
    {  { "time_usec", NULL, MAVLINK_TYPE_UINT64_T, 0, 0, offsetof(mavlink_esad_arming_t, time_usec) }, \
         { "target_system", NULL, MAVLINK_TYPE_UINT8_T, 0, 12, offsetof(mavlink_esad_arming_t, target_system) }, \
         { "target_component", NULL, MAVLINK_TYPE_UINT8_T, 0, 13, offsetof(mavlink_esad_arming_t, target_component) }, \
         { "esad_id", NULL, MAVLINK_TYPE_UINT8_T, 0, 14, offsetof(mavlink_esad_arming_t, esad_id) }, \
         { "arming_challenge_hash", NULL, MAVLINK_TYPE_UINT32_T, 0, 8, offsetof(mavlink_esad_arming_t, arming_challenge_hash) }, \
         { "arming_request", NULL, MAVLINK_TYPE_UINT8_T, 0, 15, offsetof(mavlink_esad_arming_t, arming_request) }, \
         { "store_id", NULL, MAVLINK_TYPE_UINT8_T, 0, 16, offsetof(mavlink_esad_arming_t, store_id) }, \
         { "track_uid", NULL, MAVLINK_TYPE_UINT8_T, 16, 17, offsetof(mavlink_esad_arming_t, track_uid) }, \
         } \
}
#endif

/**
 * @brief Pack a esad_arming message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param time_usec [us] Timestamp (UNIX epoch, microseconds UTC).
 * @param target_system  System ID of the intended recipient. 0 (every system) is valid only for MAVLINK_M_ESAD_REQUEST_DISARM, which each receiving system applies to its own ESADs; receivers ignore an arm request sent with 0.
 * @param target_component  Component ID of the intended recipient within target_system. 0 = every component of that system. Ignored when target_system is 0.
 * @param esad_id  Vehicle-local ESAD instance identifier to arm or disarm. 0 = every local ESAD selected by store_id, 1-254 = specific ESAD instance, 255 = reserved.
 * @param arming_challenge_hash  Challenge hash the selected ESAD advertises in ESAD_STATE. Checked for an ARM, where with esad_id = 0 every selected local ESAD must advertise it; not checked for a DISARM.
 * @param arming_request  Requested arming state change.
 * @param store_id  Target store instance identifier. 0 = every store on the receiving system.
 * @param track_uid  Track UID (see TRACK_IDENTITY) of the engagement an ARM is for, reported back in ESAD_STATE.track_uid. All-zero if the arming is not tied to a track. Ignored for DISARM.
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_esad_arming_pack(uint32_t system_id, uint8_t component_id, mavlink_message_t* msg,
                               uint64_t time_usec, uint32_t target_system, uint8_t target_component, uint8_t esad_id, uint32_t arming_challenge_hash, uint8_t arming_request, uint8_t store_id, const uint8_t *track_uid)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_ESAD_ARMING_LEN];
    _mav_put_uint64_t(buf, 0, time_usec);
    _mav_put_uint32_t(buf, 8, arming_challenge_hash);
    _mav_put_uint8_t(buf, 12, mavlink_msg_target_field(target_system));
    _mav_put_uint8_t(buf, 13, target_component);
    _mav_put_uint8_t(buf, 14, esad_id);
    _mav_put_uint8_t(buf, 15, arming_request);
    _mav_put_uint8_t(buf, 16, store_id);
    _mav_put_uint8_t_array(buf, 17, track_uid, 16);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_ESAD_ARMING_LEN);
#else
    mavlink_esad_arming_t packet;
    packet.time_usec = time_usec;
    packet.arming_challenge_hash = arming_challenge_hash;
    packet.target_system = mavlink_msg_target_field(target_system);
    packet.target_component = target_component;
    packet.esad_id = esad_id;
    packet.arming_request = arming_request;
    packet.store_id = store_id;
    mav_array_memcpy(packet.track_uid, track_uid, sizeof(uint8_t)*16);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_ESAD_ARMING_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_ESAD_ARMING;
    return mavlink_finalize_message_target(msg, system_id, component_id, MAVLINK_MSG_ID_ESAD_ARMING_MIN_LEN, MAVLINK_MSG_ID_ESAD_ARMING_LEN, MAVLINK_MSG_ID_ESAD_ARMING_CRC, target_system);
}

/**
 * @brief Pack a esad_arming message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param status MAVLink status structure
 * @param msg The MAVLink message to compress the data into
 *
 * @param time_usec [us] Timestamp (UNIX epoch, microseconds UTC).
 * @param target_system  System ID of the intended recipient. 0 (every system) is valid only for MAVLINK_M_ESAD_REQUEST_DISARM, which each receiving system applies to its own ESADs; receivers ignore an arm request sent with 0.
 * @param target_component  Component ID of the intended recipient within target_system. 0 = every component of that system. Ignored when target_system is 0.
 * @param esad_id  Vehicle-local ESAD instance identifier to arm or disarm. 0 = every local ESAD selected by store_id, 1-254 = specific ESAD instance, 255 = reserved.
 * @param arming_challenge_hash  Challenge hash the selected ESAD advertises in ESAD_STATE. Checked for an ARM, where with esad_id = 0 every selected local ESAD must advertise it; not checked for a DISARM.
 * @param arming_request  Requested arming state change.
 * @param store_id  Target store instance identifier. 0 = every store on the receiving system.
 * @param track_uid  Track UID (see TRACK_IDENTITY) of the engagement an ARM is for, reported back in ESAD_STATE.track_uid. All-zero if the arming is not tied to a track. Ignored for DISARM.
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_esad_arming_pack_status(uint32_t system_id, uint8_t component_id, mavlink_status_t *_status, mavlink_message_t* msg,
                               uint64_t time_usec, uint32_t target_system, uint8_t target_component, uint8_t esad_id, uint32_t arming_challenge_hash, uint8_t arming_request, uint8_t store_id, const uint8_t *track_uid)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_ESAD_ARMING_LEN];
    _mav_put_uint64_t(buf, 0, time_usec);
    _mav_put_uint32_t(buf, 8, arming_challenge_hash);
    _mav_put_uint8_t(buf, 12, mavlink_msg_target_field(target_system));
    _mav_put_uint8_t(buf, 13, target_component);
    _mav_put_uint8_t(buf, 14, esad_id);
    _mav_put_uint8_t(buf, 15, arming_request);
    _mav_put_uint8_t(buf, 16, store_id);
    _mav_put_uint8_t_array(buf, 17, track_uid, 16);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_ESAD_ARMING_LEN);
#else
    mavlink_esad_arming_t packet;
    packet.time_usec = time_usec;
    packet.arming_challenge_hash = arming_challenge_hash;
    packet.target_system = mavlink_msg_target_field(target_system);
    packet.target_component = target_component;
    packet.esad_id = esad_id;
    packet.arming_request = arming_request;
    packet.store_id = store_id;
    mav_array_memcpy(packet.track_uid, track_uid, sizeof(uint8_t)*16);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_ESAD_ARMING_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_ESAD_ARMING;
#if MAVLINK_CRC_EXTRA
    return mavlink_finalize_message_buffer_target(msg, system_id, component_id, _status, MAVLINK_MSG_ID_ESAD_ARMING_MIN_LEN, MAVLINK_MSG_ID_ESAD_ARMING_LEN, MAVLINK_MSG_ID_ESAD_ARMING_CRC, target_system);
#else
    return mavlink_finalize_message_buffer_target(msg, system_id, component_id, _status, MAVLINK_MSG_ID_ESAD_ARMING_MIN_LEN, MAVLINK_MSG_ID_ESAD_ARMING_LEN, 0, target_system);
#endif
}

/**
 * @brief Pack a esad_arming message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param time_usec [us] Timestamp (UNIX epoch, microseconds UTC).
 * @param target_system  System ID of the intended recipient. 0 (every system) is valid only for MAVLINK_M_ESAD_REQUEST_DISARM, which each receiving system applies to its own ESADs; receivers ignore an arm request sent with 0.
 * @param target_component  Component ID of the intended recipient within target_system. 0 = every component of that system. Ignored when target_system is 0.
 * @param esad_id  Vehicle-local ESAD instance identifier to arm or disarm. 0 = every local ESAD selected by store_id, 1-254 = specific ESAD instance, 255 = reserved.
 * @param arming_challenge_hash  Challenge hash the selected ESAD advertises in ESAD_STATE. Checked for an ARM, where with esad_id = 0 every selected local ESAD must advertise it; not checked for a DISARM.
 * @param arming_request  Requested arming state change.
 * @param store_id  Target store instance identifier. 0 = every store on the receiving system.
 * @param track_uid  Track UID (see TRACK_IDENTITY) of the engagement an ARM is for, reported back in ESAD_STATE.track_uid. All-zero if the arming is not tied to a track. Ignored for DISARM.
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_esad_arming_pack_chan(uint32_t system_id, uint8_t component_id, uint8_t chan,
                               mavlink_message_t* msg,
                                   uint64_t time_usec,uint32_t target_system,uint8_t target_component,uint8_t esad_id,uint32_t arming_challenge_hash,uint8_t arming_request,uint8_t store_id,const uint8_t *track_uid)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_ESAD_ARMING_LEN];
    _mav_put_uint64_t(buf, 0, time_usec);
    _mav_put_uint32_t(buf, 8, arming_challenge_hash);
    _mav_put_uint8_t(buf, 12, mavlink_msg_target_field(target_system));
    _mav_put_uint8_t(buf, 13, target_component);
    _mav_put_uint8_t(buf, 14, esad_id);
    _mav_put_uint8_t(buf, 15, arming_request);
    _mav_put_uint8_t(buf, 16, store_id);
    _mav_put_uint8_t_array(buf, 17, track_uid, 16);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_ESAD_ARMING_LEN);
#else
    mavlink_esad_arming_t packet;
    packet.time_usec = time_usec;
    packet.arming_challenge_hash = arming_challenge_hash;
    packet.target_system = mavlink_msg_target_field(target_system);
    packet.target_component = target_component;
    packet.esad_id = esad_id;
    packet.arming_request = arming_request;
    packet.store_id = store_id;
    mav_array_memcpy(packet.track_uid, track_uid, sizeof(uint8_t)*16);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_ESAD_ARMING_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_ESAD_ARMING;
    return mavlink_finalize_message_chan_target(msg, system_id, component_id, chan, MAVLINK_MSG_ID_ESAD_ARMING_MIN_LEN, MAVLINK_MSG_ID_ESAD_ARMING_LEN, MAVLINK_MSG_ID_ESAD_ARMING_CRC, target_system);
}

/**
 * @brief Encode a esad_arming struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param esad_arming C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_esad_arming_encode(uint32_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_esad_arming_t* esad_arming)
{
    return mavlink_msg_esad_arming_pack(system_id, component_id, msg, esad_arming->time_usec, esad_arming->target_system, esad_arming->target_component, esad_arming->esad_id, esad_arming->arming_challenge_hash, esad_arming->arming_request, esad_arming->store_id, esad_arming->track_uid);
}

/**
 * @brief Encode a esad_arming struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param esad_arming C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_esad_arming_encode_chan(uint32_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_esad_arming_t* esad_arming)
{
    return mavlink_msg_esad_arming_pack_chan(system_id, component_id, chan, msg, esad_arming->time_usec, esad_arming->target_system, esad_arming->target_component, esad_arming->esad_id, esad_arming->arming_challenge_hash, esad_arming->arming_request, esad_arming->store_id, esad_arming->track_uid);
}

/**
 * @brief Encode a esad_arming struct with provided status structure
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param status MAVLink status structure
 * @param msg The MAVLink message to compress the data into
 * @param esad_arming C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_esad_arming_encode_status(uint32_t system_id, uint8_t component_id, mavlink_status_t* _status, mavlink_message_t* msg, const mavlink_esad_arming_t* esad_arming)
{
    return mavlink_msg_esad_arming_pack_status(system_id, component_id, _status, msg,  esad_arming->time_usec, esad_arming->target_system, esad_arming->target_component, esad_arming->esad_id, esad_arming->arming_challenge_hash, esad_arming->arming_request, esad_arming->store_id, esad_arming->track_uid);
}

/**
 * @brief Send a esad_arming message
 * @param chan MAVLink channel to send the message
 *
 * @param time_usec [us] Timestamp (UNIX epoch, microseconds UTC).
 * @param target_system  System ID of the intended recipient. 0 (every system) is valid only for MAVLINK_M_ESAD_REQUEST_DISARM, which each receiving system applies to its own ESADs; receivers ignore an arm request sent with 0.
 * @param target_component  Component ID of the intended recipient within target_system. 0 = every component of that system. Ignored when target_system is 0.
 * @param esad_id  Vehicle-local ESAD instance identifier to arm or disarm. 0 = every local ESAD selected by store_id, 1-254 = specific ESAD instance, 255 = reserved.
 * @param arming_challenge_hash  Challenge hash the selected ESAD advertises in ESAD_STATE. Checked for an ARM, where with esad_id = 0 every selected local ESAD must advertise it; not checked for a DISARM.
 * @param arming_request  Requested arming state change.
 * @param store_id  Target store instance identifier. 0 = every store on the receiving system.
 * @param track_uid  Track UID (see TRACK_IDENTITY) of the engagement an ARM is for, reported back in ESAD_STATE.track_uid. All-zero if the arming is not tied to a track. Ignored for DISARM.
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_esad_arming_send(mavlink_channel_t chan, uint64_t time_usec, uint32_t target_system, uint8_t target_component, uint8_t esad_id, uint32_t arming_challenge_hash, uint8_t arming_request, uint8_t store_id, const uint8_t *track_uid)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_ESAD_ARMING_LEN];
    _mav_put_uint64_t(buf, 0, time_usec);
    _mav_put_uint32_t(buf, 8, arming_challenge_hash);
    _mav_put_uint8_t(buf, 12, mavlink_msg_target_field(target_system));
    _mav_put_uint8_t(buf, 13, target_component);
    _mav_put_uint8_t(buf, 14, esad_id);
    _mav_put_uint8_t(buf, 15, arming_request);
    _mav_put_uint8_t(buf, 16, store_id);
    _mav_put_uint8_t_array(buf, 17, track_uid, 16);
    _mav_finalize_message_chan_send_target(chan, MAVLINK_MSG_ID_ESAD_ARMING, buf, MAVLINK_MSG_ID_ESAD_ARMING_MIN_LEN, MAVLINK_MSG_ID_ESAD_ARMING_LEN, MAVLINK_MSG_ID_ESAD_ARMING_CRC, target_system);
#else
    mavlink_esad_arming_t packet;
    packet.time_usec = time_usec;
    packet.arming_challenge_hash = arming_challenge_hash;
    packet.target_system = mavlink_msg_target_field(target_system);
    packet.target_component = target_component;
    packet.esad_id = esad_id;
    packet.arming_request = arming_request;
    packet.store_id = store_id;
    mav_array_memcpy(packet.track_uid, track_uid, sizeof(uint8_t)*16);
    _mav_finalize_message_chan_send_target(chan, MAVLINK_MSG_ID_ESAD_ARMING, (const char *)&packet, MAVLINK_MSG_ID_ESAD_ARMING_MIN_LEN, MAVLINK_MSG_ID_ESAD_ARMING_LEN, MAVLINK_MSG_ID_ESAD_ARMING_CRC, target_system);
#endif
}

/**
 * @brief Send a esad_arming message
 * @param chan MAVLink channel to send the message
 * @param struct The MAVLink struct to serialize
 */
static inline void mavlink_msg_esad_arming_send_struct(mavlink_channel_t chan, const mavlink_esad_arming_t* esad_arming)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    mavlink_msg_esad_arming_send(chan, esad_arming->time_usec, esad_arming->target_system, esad_arming->target_component, esad_arming->esad_id, esad_arming->arming_challenge_hash, esad_arming->arming_request, esad_arming->store_id, esad_arming->track_uid);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_ESAD_ARMING, (const char *)esad_arming, MAVLINK_MSG_ID_ESAD_ARMING_MIN_LEN, MAVLINK_MSG_ID_ESAD_ARMING_LEN, MAVLINK_MSG_ID_ESAD_ARMING_CRC);
#endif
}

#if MAVLINK_MSG_ID_ESAD_ARMING_LEN <= MAVLINK_MAX_PAYLOAD_LEN
/*
  This variant of _send() can be used to save stack space by reusing
  memory from the receive buffer.  The caller provides a
  mavlink_message_t which is the size of a full mavlink message. This
  is usually the receive buffer for the channel, and allows a reply to an
  incoming message with minimum stack space usage.
 */
static inline void mavlink_msg_esad_arming_send_buf(mavlink_message_t *msgbuf, mavlink_channel_t chan,  uint64_t time_usec, uint32_t target_system, uint8_t target_component, uint8_t esad_id, uint32_t arming_challenge_hash, uint8_t arming_request, uint8_t store_id, const uint8_t *track_uid)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char *buf = (char *)msgbuf;
    _mav_put_uint64_t(buf, 0, time_usec);
    _mav_put_uint32_t(buf, 8, arming_challenge_hash);
    _mav_put_uint8_t(buf, 12, mavlink_msg_target_field(target_system));
    _mav_put_uint8_t(buf, 13, target_component);
    _mav_put_uint8_t(buf, 14, esad_id);
    _mav_put_uint8_t(buf, 15, arming_request);
    _mav_put_uint8_t(buf, 16, store_id);
    _mav_put_uint8_t_array(buf, 17, track_uid, 16);
    _mav_finalize_message_chan_send_target(chan, MAVLINK_MSG_ID_ESAD_ARMING, buf, MAVLINK_MSG_ID_ESAD_ARMING_MIN_LEN, MAVLINK_MSG_ID_ESAD_ARMING_LEN, MAVLINK_MSG_ID_ESAD_ARMING_CRC, target_system);
#else
    mavlink_esad_arming_t *packet = (mavlink_esad_arming_t *)msgbuf;
    packet->time_usec = time_usec;
    packet->arming_challenge_hash = arming_challenge_hash;
    packet->target_system = mavlink_msg_target_field(target_system);
    packet->target_component = target_component;
    packet->esad_id = esad_id;
    packet->arming_request = arming_request;
    packet->store_id = store_id;
    mav_array_memcpy(packet->track_uid, track_uid, sizeof(uint8_t)*16);
    _mav_finalize_message_chan_send_target(chan, MAVLINK_MSG_ID_ESAD_ARMING, (const char *)packet, MAVLINK_MSG_ID_ESAD_ARMING_MIN_LEN, MAVLINK_MSG_ID_ESAD_ARMING_LEN, MAVLINK_MSG_ID_ESAD_ARMING_CRC, target_system);
#endif
}
#endif

#endif

// MESSAGE ESAD_ARMING UNPACKING


/**
 * @brief Get field time_usec from esad_arming message
 *
 * @return [us] Timestamp (UNIX epoch, microseconds UTC).
 */
static inline uint64_t mavlink_msg_esad_arming_get_time_usec(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint64_t(msg,  0);
}

/**
 * @brief Get field target_component from esad_arming message
 *
 * @return  Component ID of the intended recipient within target_system. 0 = every component of that system. Ignored when target_system is 0.
 */
static inline uint8_t mavlink_msg_esad_arming_get_target_component(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  13);
}

/**
 * @brief Get field esad_id from esad_arming message
 *
 * @return  Vehicle-local ESAD instance identifier to arm or disarm. 0 = every local ESAD selected by store_id, 1-254 = specific ESAD instance, 255 = reserved.
 */
static inline uint8_t mavlink_msg_esad_arming_get_esad_id(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  14);
}

/**
 * @brief Get field arming_challenge_hash from esad_arming message
 *
 * @return  Challenge hash the selected ESAD advertises in ESAD_STATE. Checked for an ARM, where with esad_id = 0 every selected local ESAD must advertise it; not checked for a DISARM.
 */
static inline uint32_t mavlink_msg_esad_arming_get_arming_challenge_hash(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint32_t(msg,  8);
}

/**
 * @brief Get field arming_request from esad_arming message
 *
 * @return  Requested arming state change.
 */
static inline uint8_t mavlink_msg_esad_arming_get_arming_request(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  15);
}

/**
 * @brief Get field store_id from esad_arming message
 *
 * @return  Target store instance identifier. 0 = every store on the receiving system.
 */
static inline uint8_t mavlink_msg_esad_arming_get_store_id(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  16);
}

/**
 * @brief Get field track_uid from esad_arming message
 *
 * @return  Track UID (see TRACK_IDENTITY) of the engagement an ARM is for, reported back in ESAD_STATE.track_uid. All-zero if the arming is not tied to a track. Ignored for DISARM.
 */
static inline uint16_t mavlink_msg_esad_arming_get_track_uid(const mavlink_message_t* msg, uint8_t *track_uid)
{
    return _MAV_RETURN_uint8_t_array(msg, track_uid, 16,  17);
}

/**
 * @brief Decode a esad_arming message into a struct
 *
 * @param msg The message to decode
 * @param esad_arming C-struct to decode the message contents into
 */
static inline void mavlink_msg_esad_arming_decode(const mavlink_message_t* msg, mavlink_esad_arming_t* esad_arming)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    esad_arming->time_usec = mavlink_msg_esad_arming_get_time_usec(msg);
    esad_arming->arming_challenge_hash = mavlink_msg_esad_arming_get_arming_challenge_hash(msg);
    esad_arming->target_system = _MAV_RETURN_uint8_t(msg, 12);
    esad_arming->target_component = mavlink_msg_esad_arming_get_target_component(msg);
    esad_arming->esad_id = mavlink_msg_esad_arming_get_esad_id(msg);
    esad_arming->arming_request = mavlink_msg_esad_arming_get_arming_request(msg);
    esad_arming->store_id = mavlink_msg_esad_arming_get_store_id(msg);
    mavlink_msg_esad_arming_get_track_uid(msg, esad_arming->track_uid);
#else
        uint8_t len = msg->len < MAVLINK_MSG_ID_ESAD_ARMING_LEN? msg->len : MAVLINK_MSG_ID_ESAD_ARMING_LEN;
        memset(esad_arming, 0, MAVLINK_MSG_ID_ESAD_ARMING_LEN);
    memcpy(esad_arming, _MAV_PAYLOAD(msg), len);
#endif
    if (msg->incompat_flags & MAVLINK_IFLAG_TARGET32) {
        // This uint8_t field cannot retain a wide target. The sentinel is NOT reserved.
        // For routing use mavlink_msg_get_target_sysid(msg, mavlink_get_msg_entry(msg->msgid)).
        // To relay after edits, pass that full target to _pack*(); _encode*() loses it.
        esad_arming->target_system = mavlink_msg_target_field(msg->target_sysid);
    }

}
