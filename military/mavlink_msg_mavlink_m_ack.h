#pragma once
// MESSAGE MAVLINK_M_ACK PACKING

#include <stdint.h>

#define MAVLINK_MSG_ID_MAVLINK_M_ACK 53004


typedef struct __mavlink_mavlink_m_ack_t {
 uint64_t time_usec; /*< [us] Timestamp (UNIX epoch, microseconds UTC).*/
 uint64_t ack_time_usec; /*< [us] time_usec of the acknowledged message, copied unchanged. Tells apart acknowledgments of different messages with the same ack_msgid and ack_instance, such as a MAVLINK_M_ENGAGEMENT_DIRECTIVE_CHECK_FIRE and the MAVLINK_M_ENGAGEMENT_DIRECTIVE_RESUME of the same mission.*/
 uint32_t ack_msgid; /*<  MAVLink message ID being acknowledged (e.g. 53001 for TARGET_CUE).*/
 uint32_t ack_instance; /*<  Instance identifier of the acknowledged item (e.g. cue_id / target_set_id / sequence). 0 if not applicable.*/
 uint8_t target_system; /*<  System ID of the recipient: the source system ID in the frame header of the acknowledged message, not that message's own target_system. Never 0.*/
 uint8_t target_component; /*<  Component ID of the recipient: the source component ID in the frame header of the acknowledged message, not that message's own target_component. Never 0.*/
 uint8_t result; /*<  Result of receiving/processing the acknowledged message.*/
 char reason[50]; /*<  Optional human-readable reason, primarily for REJECTED/FAILED (null-terminated).*/
} mavlink_mavlink_m_ack_t;

#define MAVLINK_MSG_ID_MAVLINK_M_ACK_LEN 77
#define MAVLINK_MSG_ID_MAVLINK_M_ACK_MIN_LEN 77
#define MAVLINK_MSG_ID_53004_LEN 77
#define MAVLINK_MSG_ID_53004_MIN_LEN 77

#define MAVLINK_MSG_ID_MAVLINK_M_ACK_CRC 167
#define MAVLINK_MSG_ID_53004_CRC 167

#define MAVLINK_MSG_MAVLINK_M_ACK_FIELD_REASON_LEN 50

#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_MAVLINK_M_ACK { \
    53004, \
    "MAVLINK_M_ACK", \
    8, \
    {  { "time_usec", NULL, MAVLINK_TYPE_UINT64_T, 0, 0, offsetof(mavlink_mavlink_m_ack_t, time_usec) }, \
         { "ack_time_usec", NULL, MAVLINK_TYPE_UINT64_T, 0, 8, offsetof(mavlink_mavlink_m_ack_t, ack_time_usec) }, \
         { "target_system", NULL, MAVLINK_TYPE_UINT8_T, 0, 24, offsetof(mavlink_mavlink_m_ack_t, target_system) }, \
         { "target_component", NULL, MAVLINK_TYPE_UINT8_T, 0, 25, offsetof(mavlink_mavlink_m_ack_t, target_component) }, \
         { "ack_msgid", NULL, MAVLINK_TYPE_UINT32_T, 0, 16, offsetof(mavlink_mavlink_m_ack_t, ack_msgid) }, \
         { "ack_instance", NULL, MAVLINK_TYPE_UINT32_T, 0, 20, offsetof(mavlink_mavlink_m_ack_t, ack_instance) }, \
         { "result", NULL, MAVLINK_TYPE_UINT8_T, 0, 26, offsetof(mavlink_mavlink_m_ack_t, result) }, \
         { "reason", NULL, MAVLINK_TYPE_CHAR, 50, 27, offsetof(mavlink_mavlink_m_ack_t, reason) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_MAVLINK_M_ACK { \
    "MAVLINK_M_ACK", \
    8, \
    {  { "time_usec", NULL, MAVLINK_TYPE_UINT64_T, 0, 0, offsetof(mavlink_mavlink_m_ack_t, time_usec) }, \
         { "ack_time_usec", NULL, MAVLINK_TYPE_UINT64_T, 0, 8, offsetof(mavlink_mavlink_m_ack_t, ack_time_usec) }, \
         { "target_system", NULL, MAVLINK_TYPE_UINT8_T, 0, 24, offsetof(mavlink_mavlink_m_ack_t, target_system) }, \
         { "target_component", NULL, MAVLINK_TYPE_UINT8_T, 0, 25, offsetof(mavlink_mavlink_m_ack_t, target_component) }, \
         { "ack_msgid", NULL, MAVLINK_TYPE_UINT32_T, 0, 16, offsetof(mavlink_mavlink_m_ack_t, ack_msgid) }, \
         { "ack_instance", NULL, MAVLINK_TYPE_UINT32_T, 0, 20, offsetof(mavlink_mavlink_m_ack_t, ack_instance) }, \
         { "result", NULL, MAVLINK_TYPE_UINT8_T, 0, 26, offsetof(mavlink_mavlink_m_ack_t, result) }, \
         { "reason", NULL, MAVLINK_TYPE_CHAR, 50, 27, offsetof(mavlink_mavlink_m_ack_t, reason) }, \
         } \
}
#endif

/**
 * @brief Pack a mavlink_m_ack message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param time_usec [us] Timestamp (UNIX epoch, microseconds UTC).
 * @param ack_time_usec [us] time_usec of the acknowledged message, copied unchanged. Tells apart acknowledgments of different messages with the same ack_msgid and ack_instance, such as a MAVLINK_M_ENGAGEMENT_DIRECTIVE_CHECK_FIRE and the MAVLINK_M_ENGAGEMENT_DIRECTIVE_RESUME of the same mission.
 * @param target_system  System ID of the recipient: the source system ID in the frame header of the acknowledged message, not that message's own target_system. Never 0.
 * @param target_component  Component ID of the recipient: the source component ID in the frame header of the acknowledged message, not that message's own target_component. Never 0.
 * @param ack_msgid  MAVLink message ID being acknowledged (e.g. 53001 for TARGET_CUE).
 * @param ack_instance  Instance identifier of the acknowledged item (e.g. cue_id / target_set_id / sequence). 0 if not applicable.
 * @param result  Result of receiving/processing the acknowledged message.
 * @param reason  Optional human-readable reason, primarily for REJECTED/FAILED (null-terminated).
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_mavlink_m_ack_pack(uint32_t system_id, uint8_t component_id, mavlink_message_t* msg,
                               uint64_t time_usec, uint64_t ack_time_usec, uint32_t target_system, uint8_t target_component, uint32_t ack_msgid, uint32_t ack_instance, uint8_t result, const char *reason)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_MAVLINK_M_ACK_LEN];
    _mav_put_uint64_t(buf, 0, time_usec);
    _mav_put_uint64_t(buf, 8, ack_time_usec);
    _mav_put_uint32_t(buf, 16, ack_msgid);
    _mav_put_uint32_t(buf, 20, ack_instance);
    _mav_put_uint8_t(buf, 24, mavlink_msg_target_field(target_system));
    _mav_put_uint8_t(buf, 25, target_component);
    _mav_put_uint8_t(buf, 26, result);
    _mav_put_char_array(buf, 27, reason, 50);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_MAVLINK_M_ACK_LEN);
#else
    mavlink_mavlink_m_ack_t packet;
    packet.time_usec = time_usec;
    packet.ack_time_usec = ack_time_usec;
    packet.ack_msgid = ack_msgid;
    packet.ack_instance = ack_instance;
    packet.target_system = mavlink_msg_target_field(target_system);
    packet.target_component = target_component;
    packet.result = result;
    mav_array_memcpy(packet.reason, reason, sizeof(char)*50);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_MAVLINK_M_ACK_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_MAVLINK_M_ACK;
    return mavlink_finalize_message_target(msg, system_id, component_id, MAVLINK_MSG_ID_MAVLINK_M_ACK_MIN_LEN, MAVLINK_MSG_ID_MAVLINK_M_ACK_LEN, MAVLINK_MSG_ID_MAVLINK_M_ACK_CRC, target_system);
}

/**
 * @brief Pack a mavlink_m_ack message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param status MAVLink status structure
 * @param msg The MAVLink message to compress the data into
 *
 * @param time_usec [us] Timestamp (UNIX epoch, microseconds UTC).
 * @param ack_time_usec [us] time_usec of the acknowledged message, copied unchanged. Tells apart acknowledgments of different messages with the same ack_msgid and ack_instance, such as a MAVLINK_M_ENGAGEMENT_DIRECTIVE_CHECK_FIRE and the MAVLINK_M_ENGAGEMENT_DIRECTIVE_RESUME of the same mission.
 * @param target_system  System ID of the recipient: the source system ID in the frame header of the acknowledged message, not that message's own target_system. Never 0.
 * @param target_component  Component ID of the recipient: the source component ID in the frame header of the acknowledged message, not that message's own target_component. Never 0.
 * @param ack_msgid  MAVLink message ID being acknowledged (e.g. 53001 for TARGET_CUE).
 * @param ack_instance  Instance identifier of the acknowledged item (e.g. cue_id / target_set_id / sequence). 0 if not applicable.
 * @param result  Result of receiving/processing the acknowledged message.
 * @param reason  Optional human-readable reason, primarily for REJECTED/FAILED (null-terminated).
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_mavlink_m_ack_pack_status(uint32_t system_id, uint8_t component_id, mavlink_status_t *_status, mavlink_message_t* msg,
                               uint64_t time_usec, uint64_t ack_time_usec, uint32_t target_system, uint8_t target_component, uint32_t ack_msgid, uint32_t ack_instance, uint8_t result, const char *reason)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_MAVLINK_M_ACK_LEN];
    _mav_put_uint64_t(buf, 0, time_usec);
    _mav_put_uint64_t(buf, 8, ack_time_usec);
    _mav_put_uint32_t(buf, 16, ack_msgid);
    _mav_put_uint32_t(buf, 20, ack_instance);
    _mav_put_uint8_t(buf, 24, mavlink_msg_target_field(target_system));
    _mav_put_uint8_t(buf, 25, target_component);
    _mav_put_uint8_t(buf, 26, result);
    _mav_put_char_array(buf, 27, reason, 50);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_MAVLINK_M_ACK_LEN);
#else
    mavlink_mavlink_m_ack_t packet;
    packet.time_usec = time_usec;
    packet.ack_time_usec = ack_time_usec;
    packet.ack_msgid = ack_msgid;
    packet.ack_instance = ack_instance;
    packet.target_system = mavlink_msg_target_field(target_system);
    packet.target_component = target_component;
    packet.result = result;
    mav_array_memcpy(packet.reason, reason, sizeof(char)*50);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_MAVLINK_M_ACK_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_MAVLINK_M_ACK;
#if MAVLINK_CRC_EXTRA
    return mavlink_finalize_message_buffer_target(msg, system_id, component_id, _status, MAVLINK_MSG_ID_MAVLINK_M_ACK_MIN_LEN, MAVLINK_MSG_ID_MAVLINK_M_ACK_LEN, MAVLINK_MSG_ID_MAVLINK_M_ACK_CRC, target_system);
#else
    return mavlink_finalize_message_buffer_target(msg, system_id, component_id, _status, MAVLINK_MSG_ID_MAVLINK_M_ACK_MIN_LEN, MAVLINK_MSG_ID_MAVLINK_M_ACK_LEN, 0, target_system);
#endif
}

/**
 * @brief Pack a mavlink_m_ack message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param time_usec [us] Timestamp (UNIX epoch, microseconds UTC).
 * @param ack_time_usec [us] time_usec of the acknowledged message, copied unchanged. Tells apart acknowledgments of different messages with the same ack_msgid and ack_instance, such as a MAVLINK_M_ENGAGEMENT_DIRECTIVE_CHECK_FIRE and the MAVLINK_M_ENGAGEMENT_DIRECTIVE_RESUME of the same mission.
 * @param target_system  System ID of the recipient: the source system ID in the frame header of the acknowledged message, not that message's own target_system. Never 0.
 * @param target_component  Component ID of the recipient: the source component ID in the frame header of the acknowledged message, not that message's own target_component. Never 0.
 * @param ack_msgid  MAVLink message ID being acknowledged (e.g. 53001 for TARGET_CUE).
 * @param ack_instance  Instance identifier of the acknowledged item (e.g. cue_id / target_set_id / sequence). 0 if not applicable.
 * @param result  Result of receiving/processing the acknowledged message.
 * @param reason  Optional human-readable reason, primarily for REJECTED/FAILED (null-terminated).
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_mavlink_m_ack_pack_chan(uint32_t system_id, uint8_t component_id, uint8_t chan,
                               mavlink_message_t* msg,
                                   uint64_t time_usec,uint64_t ack_time_usec,uint32_t target_system,uint8_t target_component,uint32_t ack_msgid,uint32_t ack_instance,uint8_t result,const char *reason)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_MAVLINK_M_ACK_LEN];
    _mav_put_uint64_t(buf, 0, time_usec);
    _mav_put_uint64_t(buf, 8, ack_time_usec);
    _mav_put_uint32_t(buf, 16, ack_msgid);
    _mav_put_uint32_t(buf, 20, ack_instance);
    _mav_put_uint8_t(buf, 24, mavlink_msg_target_field(target_system));
    _mav_put_uint8_t(buf, 25, target_component);
    _mav_put_uint8_t(buf, 26, result);
    _mav_put_char_array(buf, 27, reason, 50);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_MAVLINK_M_ACK_LEN);
#else
    mavlink_mavlink_m_ack_t packet;
    packet.time_usec = time_usec;
    packet.ack_time_usec = ack_time_usec;
    packet.ack_msgid = ack_msgid;
    packet.ack_instance = ack_instance;
    packet.target_system = mavlink_msg_target_field(target_system);
    packet.target_component = target_component;
    packet.result = result;
    mav_array_memcpy(packet.reason, reason, sizeof(char)*50);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_MAVLINK_M_ACK_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_MAVLINK_M_ACK;
    return mavlink_finalize_message_chan_target(msg, system_id, component_id, chan, MAVLINK_MSG_ID_MAVLINK_M_ACK_MIN_LEN, MAVLINK_MSG_ID_MAVLINK_M_ACK_LEN, MAVLINK_MSG_ID_MAVLINK_M_ACK_CRC, target_system);
}

/**
 * @brief Encode a mavlink_m_ack struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param mavlink_m_ack C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_mavlink_m_ack_encode(uint32_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_mavlink_m_ack_t* mavlink_m_ack)
{
    return mavlink_msg_mavlink_m_ack_pack(system_id, component_id, msg, mavlink_m_ack->time_usec, mavlink_m_ack->ack_time_usec, mavlink_m_ack->target_system, mavlink_m_ack->target_component, mavlink_m_ack->ack_msgid, mavlink_m_ack->ack_instance, mavlink_m_ack->result, mavlink_m_ack->reason);
}

/**
 * @brief Encode a mavlink_m_ack struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param mavlink_m_ack C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_mavlink_m_ack_encode_chan(uint32_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_mavlink_m_ack_t* mavlink_m_ack)
{
    return mavlink_msg_mavlink_m_ack_pack_chan(system_id, component_id, chan, msg, mavlink_m_ack->time_usec, mavlink_m_ack->ack_time_usec, mavlink_m_ack->target_system, mavlink_m_ack->target_component, mavlink_m_ack->ack_msgid, mavlink_m_ack->ack_instance, mavlink_m_ack->result, mavlink_m_ack->reason);
}

/**
 * @brief Encode a mavlink_m_ack struct with provided status structure
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param status MAVLink status structure
 * @param msg The MAVLink message to compress the data into
 * @param mavlink_m_ack C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_mavlink_m_ack_encode_status(uint32_t system_id, uint8_t component_id, mavlink_status_t* _status, mavlink_message_t* msg, const mavlink_mavlink_m_ack_t* mavlink_m_ack)
{
    return mavlink_msg_mavlink_m_ack_pack_status(system_id, component_id, _status, msg,  mavlink_m_ack->time_usec, mavlink_m_ack->ack_time_usec, mavlink_m_ack->target_system, mavlink_m_ack->target_component, mavlink_m_ack->ack_msgid, mavlink_m_ack->ack_instance, mavlink_m_ack->result, mavlink_m_ack->reason);
}

/**
 * @brief Send a mavlink_m_ack message
 * @param chan MAVLink channel to send the message
 *
 * @param time_usec [us] Timestamp (UNIX epoch, microseconds UTC).
 * @param ack_time_usec [us] time_usec of the acknowledged message, copied unchanged. Tells apart acknowledgments of different messages with the same ack_msgid and ack_instance, such as a MAVLINK_M_ENGAGEMENT_DIRECTIVE_CHECK_FIRE and the MAVLINK_M_ENGAGEMENT_DIRECTIVE_RESUME of the same mission.
 * @param target_system  System ID of the recipient: the source system ID in the frame header of the acknowledged message, not that message's own target_system. Never 0.
 * @param target_component  Component ID of the recipient: the source component ID in the frame header of the acknowledged message, not that message's own target_component. Never 0.
 * @param ack_msgid  MAVLink message ID being acknowledged (e.g. 53001 for TARGET_CUE).
 * @param ack_instance  Instance identifier of the acknowledged item (e.g. cue_id / target_set_id / sequence). 0 if not applicable.
 * @param result  Result of receiving/processing the acknowledged message.
 * @param reason  Optional human-readable reason, primarily for REJECTED/FAILED (null-terminated).
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_mavlink_m_ack_send(mavlink_channel_t chan, uint64_t time_usec, uint64_t ack_time_usec, uint32_t target_system, uint8_t target_component, uint32_t ack_msgid, uint32_t ack_instance, uint8_t result, const char *reason)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_MAVLINK_M_ACK_LEN];
    _mav_put_uint64_t(buf, 0, time_usec);
    _mav_put_uint64_t(buf, 8, ack_time_usec);
    _mav_put_uint32_t(buf, 16, ack_msgid);
    _mav_put_uint32_t(buf, 20, ack_instance);
    _mav_put_uint8_t(buf, 24, mavlink_msg_target_field(target_system));
    _mav_put_uint8_t(buf, 25, target_component);
    _mav_put_uint8_t(buf, 26, result);
    _mav_put_char_array(buf, 27, reason, 50);
    _mav_finalize_message_chan_send_target(chan, MAVLINK_MSG_ID_MAVLINK_M_ACK, buf, MAVLINK_MSG_ID_MAVLINK_M_ACK_MIN_LEN, MAVLINK_MSG_ID_MAVLINK_M_ACK_LEN, MAVLINK_MSG_ID_MAVLINK_M_ACK_CRC, target_system);
#else
    mavlink_mavlink_m_ack_t packet;
    packet.time_usec = time_usec;
    packet.ack_time_usec = ack_time_usec;
    packet.ack_msgid = ack_msgid;
    packet.ack_instance = ack_instance;
    packet.target_system = mavlink_msg_target_field(target_system);
    packet.target_component = target_component;
    packet.result = result;
    mav_array_memcpy(packet.reason, reason, sizeof(char)*50);
    _mav_finalize_message_chan_send_target(chan, MAVLINK_MSG_ID_MAVLINK_M_ACK, (const char *)&packet, MAVLINK_MSG_ID_MAVLINK_M_ACK_MIN_LEN, MAVLINK_MSG_ID_MAVLINK_M_ACK_LEN, MAVLINK_MSG_ID_MAVLINK_M_ACK_CRC, target_system);
#endif
}

/**
 * @brief Send a mavlink_m_ack message
 * @param chan MAVLink channel to send the message
 * @param struct The MAVLink struct to serialize
 */
static inline void mavlink_msg_mavlink_m_ack_send_struct(mavlink_channel_t chan, const mavlink_mavlink_m_ack_t* mavlink_m_ack)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    mavlink_msg_mavlink_m_ack_send(chan, mavlink_m_ack->time_usec, mavlink_m_ack->ack_time_usec, mavlink_m_ack->target_system, mavlink_m_ack->target_component, mavlink_m_ack->ack_msgid, mavlink_m_ack->ack_instance, mavlink_m_ack->result, mavlink_m_ack->reason);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_MAVLINK_M_ACK, (const char *)mavlink_m_ack, MAVLINK_MSG_ID_MAVLINK_M_ACK_MIN_LEN, MAVLINK_MSG_ID_MAVLINK_M_ACK_LEN, MAVLINK_MSG_ID_MAVLINK_M_ACK_CRC);
#endif
}

#if MAVLINK_MSG_ID_MAVLINK_M_ACK_LEN <= MAVLINK_MAX_PAYLOAD_LEN
/*
  This variant of _send() can be used to save stack space by reusing
  memory from the receive buffer.  The caller provides a
  mavlink_message_t which is the size of a full mavlink message. This
  is usually the receive buffer for the channel, and allows a reply to an
  incoming message with minimum stack space usage.
 */
static inline void mavlink_msg_mavlink_m_ack_send_buf(mavlink_message_t *msgbuf, mavlink_channel_t chan,  uint64_t time_usec, uint64_t ack_time_usec, uint32_t target_system, uint8_t target_component, uint32_t ack_msgid, uint32_t ack_instance, uint8_t result, const char *reason)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char *buf = (char *)msgbuf;
    _mav_put_uint64_t(buf, 0, time_usec);
    _mav_put_uint64_t(buf, 8, ack_time_usec);
    _mav_put_uint32_t(buf, 16, ack_msgid);
    _mav_put_uint32_t(buf, 20, ack_instance);
    _mav_put_uint8_t(buf, 24, mavlink_msg_target_field(target_system));
    _mav_put_uint8_t(buf, 25, target_component);
    _mav_put_uint8_t(buf, 26, result);
    _mav_put_char_array(buf, 27, reason, 50);
    _mav_finalize_message_chan_send_target(chan, MAVLINK_MSG_ID_MAVLINK_M_ACK, buf, MAVLINK_MSG_ID_MAVLINK_M_ACK_MIN_LEN, MAVLINK_MSG_ID_MAVLINK_M_ACK_LEN, MAVLINK_MSG_ID_MAVLINK_M_ACK_CRC, target_system);
#else
    mavlink_mavlink_m_ack_t *packet = (mavlink_mavlink_m_ack_t *)msgbuf;
    packet->time_usec = time_usec;
    packet->ack_time_usec = ack_time_usec;
    packet->ack_msgid = ack_msgid;
    packet->ack_instance = ack_instance;
    packet->target_system = mavlink_msg_target_field(target_system);
    packet->target_component = target_component;
    packet->result = result;
    mav_array_memcpy(packet->reason, reason, sizeof(char)*50);
    _mav_finalize_message_chan_send_target(chan, MAVLINK_MSG_ID_MAVLINK_M_ACK, (const char *)packet, MAVLINK_MSG_ID_MAVLINK_M_ACK_MIN_LEN, MAVLINK_MSG_ID_MAVLINK_M_ACK_LEN, MAVLINK_MSG_ID_MAVLINK_M_ACK_CRC, target_system);
#endif
}
#endif

#endif

// MESSAGE MAVLINK_M_ACK UNPACKING


/**
 * @brief Get field time_usec from mavlink_m_ack message
 *
 * @return [us] Timestamp (UNIX epoch, microseconds UTC).
 */
static inline uint64_t mavlink_msg_mavlink_m_ack_get_time_usec(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint64_t(msg,  0);
}

/**
 * @brief Get field ack_time_usec from mavlink_m_ack message
 *
 * @return [us] time_usec of the acknowledged message, copied unchanged. Tells apart acknowledgments of different messages with the same ack_msgid and ack_instance, such as a MAVLINK_M_ENGAGEMENT_DIRECTIVE_CHECK_FIRE and the MAVLINK_M_ENGAGEMENT_DIRECTIVE_RESUME of the same mission.
 */
static inline uint64_t mavlink_msg_mavlink_m_ack_get_ack_time_usec(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint64_t(msg,  8);
}

/**
 * @brief Get field target_component from mavlink_m_ack message
 *
 * @return  Component ID of the recipient: the source component ID in the frame header of the acknowledged message, not that message's own target_component. Never 0.
 */
static inline uint8_t mavlink_msg_mavlink_m_ack_get_target_component(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  25);
}

/**
 * @brief Get field ack_msgid from mavlink_m_ack message
 *
 * @return  MAVLink message ID being acknowledged (e.g. 53001 for TARGET_CUE).
 */
static inline uint32_t mavlink_msg_mavlink_m_ack_get_ack_msgid(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint32_t(msg,  16);
}

/**
 * @brief Get field ack_instance from mavlink_m_ack message
 *
 * @return  Instance identifier of the acknowledged item (e.g. cue_id / target_set_id / sequence). 0 if not applicable.
 */
static inline uint32_t mavlink_msg_mavlink_m_ack_get_ack_instance(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint32_t(msg,  20);
}

/**
 * @brief Get field result from mavlink_m_ack message
 *
 * @return  Result of receiving/processing the acknowledged message.
 */
static inline uint8_t mavlink_msg_mavlink_m_ack_get_result(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  26);
}

/**
 * @brief Get field reason from mavlink_m_ack message
 *
 * @return  Optional human-readable reason, primarily for REJECTED/FAILED (null-terminated).
 */
static inline uint16_t mavlink_msg_mavlink_m_ack_get_reason(const mavlink_message_t* msg, char *reason)
{
    return _MAV_RETURN_char_array(msg, reason, 50,  27);
}

/**
 * @brief Decode a mavlink_m_ack message into a struct
 *
 * @param msg The message to decode
 * @param mavlink_m_ack C-struct to decode the message contents into
 */
static inline void mavlink_msg_mavlink_m_ack_decode(const mavlink_message_t* msg, mavlink_mavlink_m_ack_t* mavlink_m_ack)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    mavlink_m_ack->time_usec = mavlink_msg_mavlink_m_ack_get_time_usec(msg);
    mavlink_m_ack->ack_time_usec = mavlink_msg_mavlink_m_ack_get_ack_time_usec(msg);
    mavlink_m_ack->ack_msgid = mavlink_msg_mavlink_m_ack_get_ack_msgid(msg);
    mavlink_m_ack->ack_instance = mavlink_msg_mavlink_m_ack_get_ack_instance(msg);
    mavlink_m_ack->target_system = _MAV_RETURN_uint8_t(msg, 24);
    mavlink_m_ack->target_component = mavlink_msg_mavlink_m_ack_get_target_component(msg);
    mavlink_m_ack->result = mavlink_msg_mavlink_m_ack_get_result(msg);
    mavlink_msg_mavlink_m_ack_get_reason(msg, mavlink_m_ack->reason);
#else
        uint8_t len = msg->len < MAVLINK_MSG_ID_MAVLINK_M_ACK_LEN? msg->len : MAVLINK_MSG_ID_MAVLINK_M_ACK_LEN;
        memset(mavlink_m_ack, 0, MAVLINK_MSG_ID_MAVLINK_M_ACK_LEN);
    memcpy(mavlink_m_ack, _MAV_PAYLOAD(msg), len);
#endif
    if (msg->incompat_flags & MAVLINK_IFLAG_TARGET32) {
        // This uint8_t field cannot retain a wide target. The sentinel is NOT reserved.
        // For routing use mavlink_msg_get_target_sysid(msg, mavlink_get_msg_entry(msg->msgid)).
        // To relay after edits, pass that full target to _pack*(); _encode*() loses it.
        mavlink_m_ack->target_system = mavlink_msg_target_field(msg->target_sysid);
    }

}
