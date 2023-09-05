/*
 * UAVCAN data structure definition for libcanard.
 *
 * Autogenerated, do not edit.
 *
 * Source file: i:\BlackBox\aircraft_h7\module\canard\dsdl\uavcan\equipment\local_position\1100.Location.uavcan
 */

#ifndef __UAVCAN_EQUIPMENT_LOCAL_POSITION_LOCATION
#define __UAVCAN_EQUIPMENT_LOCAL_POSITION_LOCATION

#include <stdint.h>
#include "canard_scalar.h"

#ifdef __cplusplus
extern "C"
{
#endif

#include <uavcan\Timestamp.h>

/******************************* Source text **********************************
# 1080
# UWB info.
#
# Typical publishing rate should be around 10 Hz.
#

uavcan.Timestamp timestamp

uint8      base_id
bool       healthy
bool       fixed
float32    distance
float32[3] base_position
float16    accuracy
uint8      N_beacons

float16[3] pos_offset
******************************************************************************/

/********************* DSDL signature source definition ***********************
uavcan.equipment.local_position.Location
uavcan.Timestamp timestamp
saturated uint8 base_id
saturated bool healthy
saturated bool fixed
saturated float32 distance
saturated float32[3] base_position
saturated float16 accuracy
saturated uint8 N_beacons
saturated float16[3] pos_offset
******************************************************************************/

#define UAVCAN_EQUIPMENT_LOCAL_POSITION_LOCATION_ID        1100
#define UAVCAN_EQUIPMENT_LOCAL_POSITION_LOCATION_NAME      "uavcan.equipment.local_position.Location"
#define UAVCAN_EQUIPMENT_LOCAL_POSITION_LOCATION_SIGNATURE (0x42381DAF5EBDA755ULL)

#define UAVCAN_EQUIPMENT_LOCAL_POSITION_LOCATION_MAX_SIZE  ((266 + 7)/8)

// Constants

#define UAVCAN_EQUIPMENT_LOCAL_POSITION_LOCATION_BASE_POSITION_LENGTH                    3
#define UAVCAN_EQUIPMENT_LOCAL_POSITION_LOCATION_POS_OFFSET_LENGTH                       3

typedef struct
{
    // FieldTypes
    uavcan_Timestamp timestamp;                     //
    uint8_t    base_id;                       // bit len 8
    bool       healthy;                       // bit len 1
    bool       fixed;                         // bit len 1
    float      distance;                      // float32 Saturate
    float      base_position[3];              // Static Array 32bit[3] max items
    float      accuracy;                      // float16 Saturate
    uint8_t    N_beacons;                     // bit len 8
    float      pos_offset[3];                 // Static Array 16bit[3] max items

} uavcan_equipment_local_position_Location;

static inline
uint32_t uavcan_equipment_local_position_Location_encode(uavcan_equipment_local_position_Location* source, void* msg_buf);

static inline
int32_t uavcan_equipment_local_position_Location_decode(const CanardTransfer* transfer, uint16_t payload_len, uavcan_equipment_local_position_Location* dest, uint8_t** dyn_arr_buf);

static inline
uint32_t uavcan_equipment_local_position_Location_encode_internal(uavcan_equipment_local_position_Location* source, void* msg_buf, uint32_t offset, uint8_t root_item);

static inline
int32_t uavcan_equipment_local_position_Location_decode_internal(const CanardTransfer* transfer, uint16_t payload_len, uavcan_equipment_local_position_Location* dest, uint8_t** dyn_arr_buf, int32_t offset);

/*
 * UAVCAN data structure definition for libcanard.
 *
 * Autogenerated, do not edit.
 *
 * Source file: i:\BlackBox\aircraft_h7\module\canard\dsdl\uavcan\equipment\local_position\1100.Location.uavcan
 */

#ifndef CANARD_INTERNAL_SATURATE
#define CANARD_INTERNAL_SATURATE(x, max) ( ((x) > max) ? max : ( (-(x) > max) ? (-max) : (x) ) );
#endif

#ifndef CANARD_INTERNAL_SATURATE_UNSIGNED
#define CANARD_INTERNAL_SATURATE_UNSIGNED(x, max) ( ((x) > max) ? max : (x) );
#endif

#if defined(__GNUC__)
# define CANARD_MAYBE_UNUSED(x) x __attribute__((unused))
#else
# define CANARD_MAYBE_UNUSED(x) x
#endif

/**
  * @brief uavcan_equipment_local_position_Location_encode_internal
  * @param source : pointer to source data struct
  * @param msg_buf: pointer to msg storage
  * @param offset: bit offset to msg storage
  * @param root_item: for detecting if TAO should be used
  * @retval returns offset
  */
uint32_t uavcan_equipment_local_position_Location_encode_internal(uavcan_equipment_local_position_Location* source,
  void* msg_buf,
  uint32_t offset,
  uint8_t CANARD_MAYBE_UNUSED(root_item))
{
    uint32_t c = 0;
#ifndef CANARD_USE_FLOAT16_CAST
    uint16_t tmp_float = 0;
#else
    CANARD_USE_FLOAT16_CAST tmp_float = 0;
#endif

    // Compound
    offset = uavcan_Timestamp_encode_internal(&source->timestamp, msg_buf, offset, 0);
    canardEncodeScalar(msg_buf, offset, 8, (void*)&source->base_id); // 255
    offset += 8;

    source->healthy = CANARD_INTERNAL_SATURATE_UNSIGNED(source->healthy, 0)
    canardEncodeScalar(msg_buf, offset, 1, (void*)&source->healthy); // 0
    offset += 1;

    source->fixed = CANARD_INTERNAL_SATURATE_UNSIGNED(source->fixed, 0)
    canardEncodeScalar(msg_buf, offset, 1, (void*)&source->fixed); // 0
    offset += 1;

    canardEncodeScalar(msg_buf, offset, 32, (void*)&source->distance); // 2147483647
    offset += 32;

    // Static array (base_position)
    for (c = 0; c < 3; c++)
    {
        canardEncodeScalar(msg_buf, offset, 32, (void*)(source->base_position + c)); // 2147483647
        offset += 32;
    }

    // float16 special handling
#ifndef CANARD_USE_FLOAT16_CAST
    tmp_float = canardConvertNativeFloatToFloat16(source->accuracy);
#else
    tmp_float = (CANARD_USE_FLOAT16_CAST)source->accuracy;
#endif
    canardEncodeScalar(msg_buf, offset, 16, (void*)&tmp_float); // 32767
    offset += 16;
    canardEncodeScalar(msg_buf, offset, 8, (void*)&source->N_beacons); // 255
    offset += 8;

    // Static array (pos_offset)
    for (c = 0; c < 3; c++)
    {
#ifndef CANARD_USE_FLOAT16_CAST
        uint16_t tmpe_float = canardConvertNativeFloatToFloat16(source->pos_offset[c]);
#else
        CANARD_USE_FLOAT16_CAST tmpe_float = (CANARD_USE_FLOAT16_CAST)source->pos_offset[c];
#endif
        canardEncodeScalar(msg_buf, offset, 16, (void*)&tmpe_float); // 32767
        offset += 16;
    }

    return offset;
}

/**
  * @brief uavcan_equipment_local_position_Location_encode
  * @param source : Pointer to source data struct
  * @param msg_buf: Pointer to msg storage
  * @retval returns message length as bytes
  */
uint32_t uavcan_equipment_local_position_Location_encode(uavcan_equipment_local_position_Location* source, void* msg_buf)
{
    uint32_t offset = 0;

    offset = uavcan_equipment_local_position_Location_encode_internal(source, msg_buf, offset, 0);

    return (offset + 7 ) / 8;
}

/**
  * @brief uavcan_equipment_local_position_Location_decode_internal
  * @param transfer: Pointer to CanardTransfer transfer
  * @param payload_len: Payload message length
  * @param dest: Pointer to destination struct
  * @param dyn_arr_buf: NULL or Pointer to memory storage to be used for dynamic arrays
  *                     uavcan_equipment_local_position_Location dyn memory will point to dyn_arr_buf memory.
  *                     NULL will ignore dynamic arrays decoding.
  * @param offset: Call with 0, bit offset to msg storage
  * @retval offset or ERROR value if < 0
  */
int32_t uavcan_equipment_local_position_Location_decode_internal(
  const CanardTransfer* transfer,
  uint16_t CANARD_MAYBE_UNUSED(payload_len),
  uavcan_equipment_local_position_Location* dest,
  uint8_t** CANARD_MAYBE_UNUSED(dyn_arr_buf),
  int32_t offset)
{
    int32_t ret = 0;
    uint32_t c = 0;
#ifndef CANARD_USE_FLOAT16_CAST
    uint16_t tmp_float = 0;
#else
    CANARD_USE_FLOAT16_CAST tmp_float = 0;
#endif

    // Compound
    offset = uavcan_Timestamp_decode_internal(transfer, 0, &dest->timestamp, dyn_arr_buf, offset);
    if (offset < 0)
    {
        ret = offset;
        goto uavcan_equipment_local_position_Location_error_exit;
    }

    ret = canardDecodeScalar(transfer, offset, 8, false, (void*)&dest->base_id);
    if (ret != 8)
    {
        goto uavcan_equipment_local_position_Location_error_exit;
    }
    offset += 8;

    ret = canardDecodeScalar(transfer, offset, 1, false, (void*)&dest->healthy);
    if (ret != 1)
    {
        goto uavcan_equipment_local_position_Location_error_exit;
    }
    offset += 1;

    ret = canardDecodeScalar(transfer, offset, 1, false, (void*)&dest->fixed);
    if (ret != 1)
    {
        goto uavcan_equipment_local_position_Location_error_exit;
    }
    offset += 1;

    ret = canardDecodeScalar(transfer, offset, 32, false, (void*)&dest->distance);
    if (ret != 32)
    {
        goto uavcan_equipment_local_position_Location_error_exit;
    }
    offset += 32;

    // Static array (base_position)
    for (c = 0; c < 3; c++)
    {
        ret = canardDecodeScalar(transfer, offset, 32, false, (void*)(dest->base_position + c));
        if (ret != 32)
        {
            goto uavcan_equipment_local_position_Location_error_exit;
        }
        offset += 32;
    }

    // float16 special handling
    ret = canardDecodeScalar(transfer, offset, 16, false, (void*)&tmp_float);

    if (ret != 16)
    {
        goto uavcan_equipment_local_position_Location_error_exit;
    }
#ifndef CANARD_USE_FLOAT16_CAST
    dest->accuracy = canardConvertFloat16ToNativeFloat(tmp_float);
#else
    dest->accuracy = (float)tmp_float;
#endif
    offset += 16;

    ret = canardDecodeScalar(transfer, offset, 8, false, (void*)&dest->N_beacons);
    if (ret != 8)
    {
        goto uavcan_equipment_local_position_Location_error_exit;
    }
    offset += 8;

    // Static array (pos_offset)
    for (c = 0; c < 3; c++)
    {
#ifndef CANARD_USE_FLOAT16_CAST
        uint16_t tmpe_float = 0;
#else
        CANARD_USE_FLOAT16_CAST tmpe_float = 0;
#endif
        ret = canardDecodeScalar(transfer, offset, 16, false, (void*)&tmpe_float);
        if (ret != 16)
        {
            goto uavcan_equipment_local_position_Location_error_exit;
        }
#ifndef CANARD_USE_FLOAT16_CAST
        dest->pos_offset[c] = canardConvertFloat16ToNativeFloat(tmpe_float);
#else
        dest->pos_offset[c] = (float)tmpe_float;
#endif
        offset += 16;
    }
    return offset;

uavcan_equipment_local_position_Location_error_exit:
    if (ret < 0)
    {
        return ret;
    }
    else
    {
        return -CANARD_ERROR_INTERNAL;
    }
}

/**
  * @brief uavcan_equipment_local_position_Location_decode
  * @param transfer: Pointer to CanardTransfer transfer
  * @param payload_len: Payload message length
  * @param dest: Pointer to destination struct
  * @param dyn_arr_buf: NULL or Pointer to memory storage to be used for dynamic arrays
  *                     uavcan_equipment_local_position_Location dyn memory will point to dyn_arr_buf memory.
  *                     NULL will ignore dynamic arrays decoding.
  * @retval offset or ERROR value if < 0
  */
int32_t uavcan_equipment_local_position_Location_decode(const CanardTransfer* transfer,
  uint16_t payload_len,
  uavcan_equipment_local_position_Location* dest,
  uint8_t** dyn_arr_buf)
{
    const int32_t offset = 0;
    int32_t ret = 0;

    // Clear the destination struct
    for (uint32_t c = 0; c < sizeof(uavcan_equipment_local_position_Location); c++)
    {
        ((uint8_t*)dest)[c] = 0x00;
    }

    ret = uavcan_equipment_local_position_Location_decode_internal(transfer, payload_len, dest, dyn_arr_buf, offset);

    return ret;
}

#ifdef __cplusplus
} // extern "C"
#endif
#endif // __UAVCAN_EQUIPMENT_LOCAL_POSITION_LOCATION