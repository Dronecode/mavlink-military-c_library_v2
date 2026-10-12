#pragma once
// MESSAGE SENSOR_TASKING PACKING

#include <stdint.h>

#define MAVLINK_MSG_ID_SENSOR_TASKING 53050


typedef struct __mavlink_sensor_tasking_t {
 uint64_t time_usec; /*< [us] Timestamp (UNIX epoch, microseconds UTC).*/
 int32_t poi_lat; /*< [degE7] Point-of-interest latitude to slew to, WGS84. INT32_MAX = not provided (0 is a valid coordinate).*/
 int32_t poi_lon; /*< [degE7] Point-of-interest longitude to slew to, WGS84. INT32_MAX = not provided (0 is a valid coordinate).*/
 float poi_alt; /*< [m] Point-of-interest altitude, MSL. NaN = not provided.*/
 uint16_t task_id; /*<  Tasking correlation id, chosen by the requester and echoed unchanged in every status response for that task. A sensor tells tasks apart by the requester's system and component IDs together with task_id.*/
 uint8_t target_system; /*<  System ID of the intended recipient: the sensor's system for a request, the requester's for a status response. Never 0, not even to cage every sensor: a STANDBY sent to every system would also cage a designator guiding a weapon already in flight. Receivers ignore a SENSOR_TASKING sent with 0.*/
 uint8_t target_component; /*<  Component ID of the intended recipient within target_system: the sensor or payload for a request, the requester for a status response. 0 = every component of that system. Ignored when target_system is 0.*/
 uint8_t sensor_mode; /*<  Commanded sensor/payload mode in a request; the mode in effect in a status response.*/
 uint8_t status; /*<  MAVLINK_M_TASKING_UNSPECIFIED in a request, any other value in a status response; this is how a receiver tells the two apart.*/
 uint8_t track_uid[16]; /*<  Track UID (see TRACK_IDENTITY) the sensor is to follow. When set, the sensor follows that track and the point of interest is only a starting cue; with sensor_mode MAVLINK_M_SENSOR_MODE_LASER_DESIGNATE or MAVLINK_M_SENSOR_MODE_IR_MARK the track only cues the sensor, which lases or marks what its own tracker holds. All-zero to point at the point of interest.*/
} mavlink_sensor_tasking_t;

#define MAVLINK_MSG_ID_SENSOR_TASKING_LEN 42
#define MAVLINK_MSG_ID_SENSOR_TASKING_MIN_LEN 42
#define MAVLINK_MSG_ID_53050_LEN 42
#define MAVLINK_MSG_ID_53050_MIN_LEN 42

#define MAVLINK_MSG_ID_SENSOR_TASKING_CRC 79
#define MAVLINK_MSG_ID_53050_CRC 79

#define MAVLINK_MSG_SENSOR_TASKING_FIELD_TRACK_UID_LEN 16

#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_SENSOR_TASKING { \
    53050, \
    "SENSOR_TASKING", \
    10, \
    {  { "time_usec", NULL, MAVLINK_TYPE_UINT64_T, 0, 0, offsetof(mavlink_sensor_tasking_t, time_usec) }, \
         { "target_system", NULL, MAVLINK_TYPE_UINT8_T, 0, 22, offsetof(mavlink_sensor_tasking_t, target_system) }, \
         { "target_component", NULL, MAVLINK_TYPE_UINT8_T, 0, 23, offsetof(mavlink_sensor_tasking_t, target_component) }, \
         { "task_id", NULL, MAVLINK_TYPE_UINT16_T, 0, 20, offsetof(mavlink_sensor_tasking_t, task_id) }, \
         { "sensor_mode", NULL, MAVLINK_TYPE_UINT8_T, 0, 24, offsetof(mavlink_sensor_tasking_t, sensor_mode) }, \
         { "status", NULL, MAVLINK_TYPE_UINT8_T, 0, 25, offsetof(mavlink_sensor_tasking_t, status) }, \
         { "poi_lat", NULL, MAVLINK_TYPE_INT32_T, 0, 8, offsetof(mavlink_sensor_tasking_t, poi_lat) }, \
         { "poi_lon", NULL, MAVLINK_TYPE_INT32_T, 0, 12, offsetof(mavlink_sensor_tasking_t, poi_lon) }, \
         { "poi_alt", NULL, MAVLINK_TYPE_FLOAT, 0, 16, offsetof(mavlink_sensor_tasking_t, poi_alt) }, \
         { "track_uid", NULL, MAVLINK_TYPE_UINT8_T, 16, 26, offsetof(mavlink_sensor_tasking_t, track_uid) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_SENSOR_TASKING { \
    "SENSOR_TASKING", \
    10, \
    {  { "time_usec", NULL, MAVLINK_TYPE_UINT64_T, 0, 0, offsetof(mavlink_sensor_tasking_t, time_usec) }, \
         { "target_system", NULL, MAVLINK_TYPE_UINT8_T, 0, 22, offsetof(mavlink_sensor_tasking_t, target_system) }, \
         { "target_component", NULL, MAVLINK_TYPE_UINT8_T, 0, 23, offsetof(mavlink_sensor_tasking_t, target_component) }, \
         { "task_id", NULL, MAVLINK_TYPE_UINT16_T, 0, 20, offsetof(mavlink_sensor_tasking_t, task_id) }, \
         { "sensor_mode", NULL, MAVLINK_TYPE_UINT8_T, 0, 24, offsetof(mavlink_sensor_tasking_t, sensor_mode) }, \
         { "status", NULL, MAVLINK_TYPE_UINT8_T, 0, 25, offsetof(mavlink_sensor_tasking_t, status) }, \
         { "poi_lat", NULL, MAVLINK_TYPE_INT32_T, 0, 8, offsetof(mavlink_sensor_tasking_t, poi_lat) }, \
         { "poi_lon", NULL, MAVLINK_TYPE_INT32_T, 0, 12, offsetof(mavlink_sensor_tasking_t, poi_lon) }, \
         { "poi_alt", NULL, MAVLINK_TYPE_FLOAT, 0, 16, offsetof(mavlink_sensor_tasking_t, poi_alt) }, \
         { "track_uid", NULL, MAVLINK_TYPE_UINT8_T, 16, 26, offsetof(mavlink_sensor_tasking_t, track_uid) }, \
         } \
}
#endif

/**
 * @brief Pack a sensor_tasking message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param time_usec [us] Timestamp (UNIX epoch, microseconds UTC).
 * @param target_system  System ID of the intended recipient: the sensor's system for a request, the requester's for a status response. Never 0, not even to cage every sensor: a STANDBY sent to every system would also cage a designator guiding a weapon already in flight. Receivers ignore a SENSOR_TASKING sent with 0.
 * @param target_component  Component ID of the intended recipient within target_system: the sensor or payload for a request, the requester for a status response. 0 = every component of that system. Ignored when target_system is 0.
 * @param task_id  Tasking correlation id, chosen by the requester and echoed unchanged in every status response for that task. A sensor tells tasks apart by the requester's system and component IDs together with task_id.
 * @param sensor_mode  Commanded sensor/payload mode in a request; the mode in effect in a status response.
 * @param status  MAVLINK_M_TASKING_UNSPECIFIED in a request, any other value in a status response; this is how a receiver tells the two apart.
 * @param poi_lat [degE7] Point-of-interest latitude to slew to, WGS84. INT32_MAX = not provided (0 is a valid coordinate).
 * @param poi_lon [degE7] Point-of-interest longitude to slew to, WGS84. INT32_MAX = not provided (0 is a valid coordinate).
 * @param poi_alt [m] Point-of-interest altitude, MSL. NaN = not provided.
 * @param track_uid  Track UID (see TRACK_IDENTITY) the sensor is to follow. When set, the sensor follows that track and the point of interest is only a starting cue; with sensor_mode MAVLINK_M_SENSOR_MODE_LASER_DESIGNATE or MAVLINK_M_SENSOR_MODE_IR_MARK the track only cues the sensor, which lases or marks what its own tracker holds. All-zero to point at the point of interest.
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_sensor_tasking_pack(uint32_t system_id, uint8_t component_id, mavlink_message_t* msg,
                               uint64_t time_usec, uint32_t target_system, uint8_t target_component, uint16_t task_id, uint8_t sensor_mode, uint8_t status, int32_t poi_lat, int32_t poi_lon, float poi_alt, const uint8_t *track_uid)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_SENSOR_TASKING_LEN];
    _mav_put_uint64_t(buf, 0, time_usec);
    _mav_put_int32_t(buf, 8, poi_lat);
    _mav_put_int32_t(buf, 12, poi_lon);
    _mav_put_float(buf, 16, poi_alt);
    _mav_put_uint16_t(buf, 20, task_id);
    _mav_put_uint8_t(buf, 22, mavlink_msg_target_field(target_system));
    _mav_put_uint8_t(buf, 23, target_component);
    _mav_put_uint8_t(buf, 24, sensor_mode);
    _mav_put_uint8_t(buf, 25, status);
    _mav_put_uint8_t_array(buf, 26, track_uid, 16);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_SENSOR_TASKING_LEN);
#else
    mavlink_sensor_tasking_t packet;
    packet.time_usec = time_usec;
    packet.poi_lat = poi_lat;
    packet.poi_lon = poi_lon;
    packet.poi_alt = poi_alt;
    packet.task_id = task_id;
    packet.target_system = mavlink_msg_target_field(target_system);
    packet.target_component = target_component;
    packet.sensor_mode = sensor_mode;
    packet.status = status;
    mav_array_memcpy(packet.track_uid, track_uid, sizeof(uint8_t)*16);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_SENSOR_TASKING_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_SENSOR_TASKING;
    return mavlink_finalize_message_target(msg, system_id, component_id, MAVLINK_MSG_ID_SENSOR_TASKING_MIN_LEN, MAVLINK_MSG_ID_SENSOR_TASKING_LEN, MAVLINK_MSG_ID_SENSOR_TASKING_CRC, target_system);
}

/**
 * @brief Pack a sensor_tasking message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param status MAVLink status structure
 * @param msg The MAVLink message to compress the data into
 *
 * @param time_usec [us] Timestamp (UNIX epoch, microseconds UTC).
 * @param target_system  System ID of the intended recipient: the sensor's system for a request, the requester's for a status response. Never 0, not even to cage every sensor: a STANDBY sent to every system would also cage a designator guiding a weapon already in flight. Receivers ignore a SENSOR_TASKING sent with 0.
 * @param target_component  Component ID of the intended recipient within target_system: the sensor or payload for a request, the requester for a status response. 0 = every component of that system. Ignored when target_system is 0.
 * @param task_id  Tasking correlation id, chosen by the requester and echoed unchanged in every status response for that task. A sensor tells tasks apart by the requester's system and component IDs together with task_id.
 * @param sensor_mode  Commanded sensor/payload mode in a request; the mode in effect in a status response.
 * @param status  MAVLINK_M_TASKING_UNSPECIFIED in a request, any other value in a status response; this is how a receiver tells the two apart.
 * @param poi_lat [degE7] Point-of-interest latitude to slew to, WGS84. INT32_MAX = not provided (0 is a valid coordinate).
 * @param poi_lon [degE7] Point-of-interest longitude to slew to, WGS84. INT32_MAX = not provided (0 is a valid coordinate).
 * @param poi_alt [m] Point-of-interest altitude, MSL. NaN = not provided.
 * @param track_uid  Track UID (see TRACK_IDENTITY) the sensor is to follow. When set, the sensor follows that track and the point of interest is only a starting cue; with sensor_mode MAVLINK_M_SENSOR_MODE_LASER_DESIGNATE or MAVLINK_M_SENSOR_MODE_IR_MARK the track only cues the sensor, which lases or marks what its own tracker holds. All-zero to point at the point of interest.
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_sensor_tasking_pack_status(uint32_t system_id, uint8_t component_id, mavlink_status_t *_status, mavlink_message_t* msg,
                               uint64_t time_usec, uint32_t target_system, uint8_t target_component, uint16_t task_id, uint8_t sensor_mode, uint8_t status, int32_t poi_lat, int32_t poi_lon, float poi_alt, const uint8_t *track_uid)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_SENSOR_TASKING_LEN];
    _mav_put_uint64_t(buf, 0, time_usec);
    _mav_put_int32_t(buf, 8, poi_lat);
    _mav_put_int32_t(buf, 12, poi_lon);
    _mav_put_float(buf, 16, poi_alt);
    _mav_put_uint16_t(buf, 20, task_id);
    _mav_put_uint8_t(buf, 22, mavlink_msg_target_field(target_system));
    _mav_put_uint8_t(buf, 23, target_component);
    _mav_put_uint8_t(buf, 24, sensor_mode);
    _mav_put_uint8_t(buf, 25, status);
    _mav_put_uint8_t_array(buf, 26, track_uid, 16);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_SENSOR_TASKING_LEN);
#else
    mavlink_sensor_tasking_t packet;
    packet.time_usec = time_usec;
    packet.poi_lat = poi_lat;
    packet.poi_lon = poi_lon;
    packet.poi_alt = poi_alt;
    packet.task_id = task_id;
    packet.target_system = mavlink_msg_target_field(target_system);
    packet.target_component = target_component;
    packet.sensor_mode = sensor_mode;
    packet.status = status;
    mav_array_memcpy(packet.track_uid, track_uid, sizeof(uint8_t)*16);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_SENSOR_TASKING_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_SENSOR_TASKING;
#if MAVLINK_CRC_EXTRA
    return mavlink_finalize_message_buffer_target(msg, system_id, component_id, _status, MAVLINK_MSG_ID_SENSOR_TASKING_MIN_LEN, MAVLINK_MSG_ID_SENSOR_TASKING_LEN, MAVLINK_MSG_ID_SENSOR_TASKING_CRC, target_system);
#else
    return mavlink_finalize_message_buffer_target(msg, system_id, component_id, _status, MAVLINK_MSG_ID_SENSOR_TASKING_MIN_LEN, MAVLINK_MSG_ID_SENSOR_TASKING_LEN, 0, target_system);
#endif
}

/**
 * @brief Pack a sensor_tasking message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param time_usec [us] Timestamp (UNIX epoch, microseconds UTC).
 * @param target_system  System ID of the intended recipient: the sensor's system for a request, the requester's for a status response. Never 0, not even to cage every sensor: a STANDBY sent to every system would also cage a designator guiding a weapon already in flight. Receivers ignore a SENSOR_TASKING sent with 0.
 * @param target_component  Component ID of the intended recipient within target_system: the sensor or payload for a request, the requester for a status response. 0 = every component of that system. Ignored when target_system is 0.
 * @param task_id  Tasking correlation id, chosen by the requester and echoed unchanged in every status response for that task. A sensor tells tasks apart by the requester's system and component IDs together with task_id.
 * @param sensor_mode  Commanded sensor/payload mode in a request; the mode in effect in a status response.
 * @param status  MAVLINK_M_TASKING_UNSPECIFIED in a request, any other value in a status response; this is how a receiver tells the two apart.
 * @param poi_lat [degE7] Point-of-interest latitude to slew to, WGS84. INT32_MAX = not provided (0 is a valid coordinate).
 * @param poi_lon [degE7] Point-of-interest longitude to slew to, WGS84. INT32_MAX = not provided (0 is a valid coordinate).
 * @param poi_alt [m] Point-of-interest altitude, MSL. NaN = not provided.
 * @param track_uid  Track UID (see TRACK_IDENTITY) the sensor is to follow. When set, the sensor follows that track and the point of interest is only a starting cue; with sensor_mode MAVLINK_M_SENSOR_MODE_LASER_DESIGNATE or MAVLINK_M_SENSOR_MODE_IR_MARK the track only cues the sensor, which lases or marks what its own tracker holds. All-zero to point at the point of interest.
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_sensor_tasking_pack_chan(uint32_t system_id, uint8_t component_id, uint8_t chan,
                               mavlink_message_t* msg,
                                   uint64_t time_usec,uint32_t target_system,uint8_t target_component,uint16_t task_id,uint8_t sensor_mode,uint8_t status,int32_t poi_lat,int32_t poi_lon,float poi_alt,const uint8_t *track_uid)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_SENSOR_TASKING_LEN];
    _mav_put_uint64_t(buf, 0, time_usec);
    _mav_put_int32_t(buf, 8, poi_lat);
    _mav_put_int32_t(buf, 12, poi_lon);
    _mav_put_float(buf, 16, poi_alt);
    _mav_put_uint16_t(buf, 20, task_id);
    _mav_put_uint8_t(buf, 22, mavlink_msg_target_field(target_system));
    _mav_put_uint8_t(buf, 23, target_component);
    _mav_put_uint8_t(buf, 24, sensor_mode);
    _mav_put_uint8_t(buf, 25, status);
    _mav_put_uint8_t_array(buf, 26, track_uid, 16);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_SENSOR_TASKING_LEN);
#else
    mavlink_sensor_tasking_t packet;
    packet.time_usec = time_usec;
    packet.poi_lat = poi_lat;
    packet.poi_lon = poi_lon;
    packet.poi_alt = poi_alt;
    packet.task_id = task_id;
    packet.target_system = mavlink_msg_target_field(target_system);
    packet.target_component = target_component;
    packet.sensor_mode = sensor_mode;
    packet.status = status;
    mav_array_memcpy(packet.track_uid, track_uid, sizeof(uint8_t)*16);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_SENSOR_TASKING_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_SENSOR_TASKING;
    return mavlink_finalize_message_chan_target(msg, system_id, component_id, chan, MAVLINK_MSG_ID_SENSOR_TASKING_MIN_LEN, MAVLINK_MSG_ID_SENSOR_TASKING_LEN, MAVLINK_MSG_ID_SENSOR_TASKING_CRC, target_system);
}

/**
 * @brief Encode a sensor_tasking struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param sensor_tasking C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_sensor_tasking_encode(uint32_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_sensor_tasking_t* sensor_tasking)
{
    return mavlink_msg_sensor_tasking_pack(system_id, component_id, msg, sensor_tasking->time_usec, sensor_tasking->target_system, sensor_tasking->target_component, sensor_tasking->task_id, sensor_tasking->sensor_mode, sensor_tasking->status, sensor_tasking->poi_lat, sensor_tasking->poi_lon, sensor_tasking->poi_alt, sensor_tasking->track_uid);
}

/**
 * @brief Encode a sensor_tasking struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param sensor_tasking C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_sensor_tasking_encode_chan(uint32_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_sensor_tasking_t* sensor_tasking)
{
    return mavlink_msg_sensor_tasking_pack_chan(system_id, component_id, chan, msg, sensor_tasking->time_usec, sensor_tasking->target_system, sensor_tasking->target_component, sensor_tasking->task_id, sensor_tasking->sensor_mode, sensor_tasking->status, sensor_tasking->poi_lat, sensor_tasking->poi_lon, sensor_tasking->poi_alt, sensor_tasking->track_uid);
}

/**
 * @brief Encode a sensor_tasking struct with provided status structure
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param status MAVLink status structure
 * @param msg The MAVLink message to compress the data into
 * @param sensor_tasking C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_sensor_tasking_encode_status(uint32_t system_id, uint8_t component_id, mavlink_status_t* _status, mavlink_message_t* msg, const mavlink_sensor_tasking_t* sensor_tasking)
{
    return mavlink_msg_sensor_tasking_pack_status(system_id, component_id, _status, msg,  sensor_tasking->time_usec, sensor_tasking->target_system, sensor_tasking->target_component, sensor_tasking->task_id, sensor_tasking->sensor_mode, sensor_tasking->status, sensor_tasking->poi_lat, sensor_tasking->poi_lon, sensor_tasking->poi_alt, sensor_tasking->track_uid);
}

/**
 * @brief Send a sensor_tasking message
 * @param chan MAVLink channel to send the message
 *
 * @param time_usec [us] Timestamp (UNIX epoch, microseconds UTC).
 * @param target_system  System ID of the intended recipient: the sensor's system for a request, the requester's for a status response. Never 0, not even to cage every sensor: a STANDBY sent to every system would also cage a designator guiding a weapon already in flight. Receivers ignore a SENSOR_TASKING sent with 0.
 * @param target_component  Component ID of the intended recipient within target_system: the sensor or payload for a request, the requester for a status response. 0 = every component of that system. Ignored when target_system is 0.
 * @param task_id  Tasking correlation id, chosen by the requester and echoed unchanged in every status response for that task. A sensor tells tasks apart by the requester's system and component IDs together with task_id.
 * @param sensor_mode  Commanded sensor/payload mode in a request; the mode in effect in a status response.
 * @param status  MAVLINK_M_TASKING_UNSPECIFIED in a request, any other value in a status response; this is how a receiver tells the two apart.
 * @param poi_lat [degE7] Point-of-interest latitude to slew to, WGS84. INT32_MAX = not provided (0 is a valid coordinate).
 * @param poi_lon [degE7] Point-of-interest longitude to slew to, WGS84. INT32_MAX = not provided (0 is a valid coordinate).
 * @param poi_alt [m] Point-of-interest altitude, MSL. NaN = not provided.
 * @param track_uid  Track UID (see TRACK_IDENTITY) the sensor is to follow. When set, the sensor follows that track and the point of interest is only a starting cue; with sensor_mode MAVLINK_M_SENSOR_MODE_LASER_DESIGNATE or MAVLINK_M_SENSOR_MODE_IR_MARK the track only cues the sensor, which lases or marks what its own tracker holds. All-zero to point at the point of interest.
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_sensor_tasking_send(mavlink_channel_t chan, uint64_t time_usec, uint32_t target_system, uint8_t target_component, uint16_t task_id, uint8_t sensor_mode, uint8_t status, int32_t poi_lat, int32_t poi_lon, float poi_alt, const uint8_t *track_uid)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_SENSOR_TASKING_LEN];
    _mav_put_uint64_t(buf, 0, time_usec);
    _mav_put_int32_t(buf, 8, poi_lat);
    _mav_put_int32_t(buf, 12, poi_lon);
    _mav_put_float(buf, 16, poi_alt);
    _mav_put_uint16_t(buf, 20, task_id);
    _mav_put_uint8_t(buf, 22, mavlink_msg_target_field(target_system));
    _mav_put_uint8_t(buf, 23, target_component);
    _mav_put_uint8_t(buf, 24, sensor_mode);
    _mav_put_uint8_t(buf, 25, status);
    _mav_put_uint8_t_array(buf, 26, track_uid, 16);
    _mav_finalize_message_chan_send_target(chan, MAVLINK_MSG_ID_SENSOR_TASKING, buf, MAVLINK_MSG_ID_SENSOR_TASKING_MIN_LEN, MAVLINK_MSG_ID_SENSOR_TASKING_LEN, MAVLINK_MSG_ID_SENSOR_TASKING_CRC, target_system);
#else
    mavlink_sensor_tasking_t packet;
    packet.time_usec = time_usec;
    packet.poi_lat = poi_lat;
    packet.poi_lon = poi_lon;
    packet.poi_alt = poi_alt;
    packet.task_id = task_id;
    packet.target_system = mavlink_msg_target_field(target_system);
    packet.target_component = target_component;
    packet.sensor_mode = sensor_mode;
    packet.status = status;
    mav_array_memcpy(packet.track_uid, track_uid, sizeof(uint8_t)*16);
    _mav_finalize_message_chan_send_target(chan, MAVLINK_MSG_ID_SENSOR_TASKING, (const char *)&packet, MAVLINK_MSG_ID_SENSOR_TASKING_MIN_LEN, MAVLINK_MSG_ID_SENSOR_TASKING_LEN, MAVLINK_MSG_ID_SENSOR_TASKING_CRC, target_system);
#endif
}

/**
 * @brief Send a sensor_tasking message
 * @param chan MAVLink channel to send the message
 * @param struct The MAVLink struct to serialize
 */
static inline void mavlink_msg_sensor_tasking_send_struct(mavlink_channel_t chan, const mavlink_sensor_tasking_t* sensor_tasking)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    mavlink_msg_sensor_tasking_send(chan, sensor_tasking->time_usec, sensor_tasking->target_system, sensor_tasking->target_component, sensor_tasking->task_id, sensor_tasking->sensor_mode, sensor_tasking->status, sensor_tasking->poi_lat, sensor_tasking->poi_lon, sensor_tasking->poi_alt, sensor_tasking->track_uid);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_SENSOR_TASKING, (const char *)sensor_tasking, MAVLINK_MSG_ID_SENSOR_TASKING_MIN_LEN, MAVLINK_MSG_ID_SENSOR_TASKING_LEN, MAVLINK_MSG_ID_SENSOR_TASKING_CRC);
#endif
}

#if MAVLINK_MSG_ID_SENSOR_TASKING_LEN <= MAVLINK_MAX_PAYLOAD_LEN
/*
  This variant of _send() can be used to save stack space by reusing
  memory from the receive buffer.  The caller provides a
  mavlink_message_t which is the size of a full mavlink message. This
  is usually the receive buffer for the channel, and allows a reply to an
  incoming message with minimum stack space usage.
 */
static inline void mavlink_msg_sensor_tasking_send_buf(mavlink_message_t *msgbuf, mavlink_channel_t chan,  uint64_t time_usec, uint32_t target_system, uint8_t target_component, uint16_t task_id, uint8_t sensor_mode, uint8_t status, int32_t poi_lat, int32_t poi_lon, float poi_alt, const uint8_t *track_uid)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char *buf = (char *)msgbuf;
    _mav_put_uint64_t(buf, 0, time_usec);
    _mav_put_int32_t(buf, 8, poi_lat);
    _mav_put_int32_t(buf, 12, poi_lon);
    _mav_put_float(buf, 16, poi_alt);
    _mav_put_uint16_t(buf, 20, task_id);
    _mav_put_uint8_t(buf, 22, mavlink_msg_target_field(target_system));
    _mav_put_uint8_t(buf, 23, target_component);
    _mav_put_uint8_t(buf, 24, sensor_mode);
    _mav_put_uint8_t(buf, 25, status);
    _mav_put_uint8_t_array(buf, 26, track_uid, 16);
    _mav_finalize_message_chan_send_target(chan, MAVLINK_MSG_ID_SENSOR_TASKING, buf, MAVLINK_MSG_ID_SENSOR_TASKING_MIN_LEN, MAVLINK_MSG_ID_SENSOR_TASKING_LEN, MAVLINK_MSG_ID_SENSOR_TASKING_CRC, target_system);
#else
    mavlink_sensor_tasking_t *packet = (mavlink_sensor_tasking_t *)msgbuf;
    packet->time_usec = time_usec;
    packet->poi_lat = poi_lat;
    packet->poi_lon = poi_lon;
    packet->poi_alt = poi_alt;
    packet->task_id = task_id;
    packet->target_system = mavlink_msg_target_field(target_system);
    packet->target_component = target_component;
    packet->sensor_mode = sensor_mode;
    packet->status = status;
    mav_array_memcpy(packet->track_uid, track_uid, sizeof(uint8_t)*16);
    _mav_finalize_message_chan_send_target(chan, MAVLINK_MSG_ID_SENSOR_TASKING, (const char *)packet, MAVLINK_MSG_ID_SENSOR_TASKING_MIN_LEN, MAVLINK_MSG_ID_SENSOR_TASKING_LEN, MAVLINK_MSG_ID_SENSOR_TASKING_CRC, target_system);
#endif
}
#endif

#endif

// MESSAGE SENSOR_TASKING UNPACKING


/**
 * @brief Get field time_usec from sensor_tasking message
 *
 * @return [us] Timestamp (UNIX epoch, microseconds UTC).
 */
static inline uint64_t mavlink_msg_sensor_tasking_get_time_usec(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint64_t(msg,  0);
}

/**
 * @brief Get field target_component from sensor_tasking message
 *
 * @return  Component ID of the intended recipient within target_system: the sensor or payload for a request, the requester for a status response. 0 = every component of that system. Ignored when target_system is 0.
 */
static inline uint8_t mavlink_msg_sensor_tasking_get_target_component(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  23);
}

/**
 * @brief Get field task_id from sensor_tasking message
 *
 * @return  Tasking correlation id, chosen by the requester and echoed unchanged in every status response for that task. A sensor tells tasks apart by the requester's system and component IDs together with task_id.
 */
static inline uint16_t mavlink_msg_sensor_tasking_get_task_id(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint16_t(msg,  20);
}

/**
 * @brief Get field sensor_mode from sensor_tasking message
 *
 * @return  Commanded sensor/payload mode in a request; the mode in effect in a status response.
 */
static inline uint8_t mavlink_msg_sensor_tasking_get_sensor_mode(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  24);
}

/**
 * @brief Get field status from sensor_tasking message
 *
 * @return  MAVLINK_M_TASKING_UNSPECIFIED in a request, any other value in a status response; this is how a receiver tells the two apart.
 */
static inline uint8_t mavlink_msg_sensor_tasking_get_status(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  25);
}

/**
 * @brief Get field poi_lat from sensor_tasking message
 *
 * @return [degE7] Point-of-interest latitude to slew to, WGS84. INT32_MAX = not provided (0 is a valid coordinate).
 */
static inline int32_t mavlink_msg_sensor_tasking_get_poi_lat(const mavlink_message_t* msg)
{
    return _MAV_RETURN_int32_t(msg,  8);
}

/**
 * @brief Get field poi_lon from sensor_tasking message
 *
 * @return [degE7] Point-of-interest longitude to slew to, WGS84. INT32_MAX = not provided (0 is a valid coordinate).
 */
static inline int32_t mavlink_msg_sensor_tasking_get_poi_lon(const mavlink_message_t* msg)
{
    return _MAV_RETURN_int32_t(msg,  12);
}

/**
 * @brief Get field poi_alt from sensor_tasking message
 *
 * @return [m] Point-of-interest altitude, MSL. NaN = not provided.
 */
static inline float mavlink_msg_sensor_tasking_get_poi_alt(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  16);
}

/**
 * @brief Get field track_uid from sensor_tasking message
 *
 * @return  Track UID (see TRACK_IDENTITY) the sensor is to follow. When set, the sensor follows that track and the point of interest is only a starting cue; with sensor_mode MAVLINK_M_SENSOR_MODE_LASER_DESIGNATE or MAVLINK_M_SENSOR_MODE_IR_MARK the track only cues the sensor, which lases or marks what its own tracker holds. All-zero to point at the point of interest.
 */
static inline uint16_t mavlink_msg_sensor_tasking_get_track_uid(const mavlink_message_t* msg, uint8_t *track_uid)
{
    return _MAV_RETURN_uint8_t_array(msg, track_uid, 16,  26);
}

/**
 * @brief Decode a sensor_tasking message into a struct
 *
 * @param msg The message to decode
 * @param sensor_tasking C-struct to decode the message contents into
 */
static inline void mavlink_msg_sensor_tasking_decode(const mavlink_message_t* msg, mavlink_sensor_tasking_t* sensor_tasking)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    sensor_tasking->time_usec = mavlink_msg_sensor_tasking_get_time_usec(msg);
    sensor_tasking->poi_lat = mavlink_msg_sensor_tasking_get_poi_lat(msg);
    sensor_tasking->poi_lon = mavlink_msg_sensor_tasking_get_poi_lon(msg);
    sensor_tasking->poi_alt = mavlink_msg_sensor_tasking_get_poi_alt(msg);
    sensor_tasking->task_id = mavlink_msg_sensor_tasking_get_task_id(msg);
    sensor_tasking->target_system = _MAV_RETURN_uint8_t(msg, 22);
    sensor_tasking->target_component = mavlink_msg_sensor_tasking_get_target_component(msg);
    sensor_tasking->sensor_mode = mavlink_msg_sensor_tasking_get_sensor_mode(msg);
    sensor_tasking->status = mavlink_msg_sensor_tasking_get_status(msg);
    mavlink_msg_sensor_tasking_get_track_uid(msg, sensor_tasking->track_uid);
#else
        uint8_t len = msg->len < MAVLINK_MSG_ID_SENSOR_TASKING_LEN? msg->len : MAVLINK_MSG_ID_SENSOR_TASKING_LEN;
        memset(sensor_tasking, 0, MAVLINK_MSG_ID_SENSOR_TASKING_LEN);
    memcpy(sensor_tasking, _MAV_PAYLOAD(msg), len);
#endif
    if (msg->incompat_flags & MAVLINK_IFLAG_TARGET32) {
        // This uint8_t field cannot retain a wide target. The sentinel is NOT reserved.
        // For routing use mavlink_msg_get_target_sysid(msg, mavlink_get_msg_entry(msg->msgid)).
        // To relay after edits, pass that full target to _pack*(); _encode*() loses it.
        sensor_tasking->target_system = mavlink_msg_target_field(msg->target_sysid);
    }

}
