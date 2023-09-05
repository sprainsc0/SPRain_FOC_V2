/*
 * UAVCAN data structure definition for libcanard.
 *
 * Autogenerated, do not edit.
 *
 * Source file: i:\BlackBox\aircraft_h7\module\canard\dsdl\uavcan\equipment\air_data\1025.AngleOfAttack.uavcan
 */

#ifndef __UAVCAN_EQUIPMENT_AIR_DATA_ANGLEOFATTACK
#define __UAVCAN_EQUIPMENT_AIR_DATA_ANGLEOFATTACK

#include <stdint.h>
#include "canard_scalar.h"

#ifdef __cplusplus
extern "C"
{
#endif

/******************************* Source text **********************************
# 1025
# Angle of attack.
#

uint8 SENSOR_ID_LEFT = 254
uint8 SENSOR_ID_RIGHT = 255
uint8 sensor_id

float16 aoa             # Radians
float16 aoa_variance    # Radians^2
******************************************************************************/

/********************* DSDL signature source definition ***********************
uavcan.equipment.air_data.AngleOfAttack
saturated uint8 sensor_id
saturated float16 aoa
saturated float16 aoa_variance
******************************************************************************/

#define UAVCAN_EQUIPMENT_AIR_DATA_ANGLEOFATTACK_ID         1025
#define UAVCAN_EQUIPMENT_AIR_DATA_ANGLEOFATTACK_NAME       "uavcan.equipment.air_data.AngleOfAttack"
#define UAVCAN_EQUIPMENT_AIR_DATA_ANGLEOFATTACK_SIGNATURE  (0xD5513C3F7AFAC74EULL)

#define UAVCAN_EQUIPMENT_AIR_DATA_ANGLEOFATTACK_MAX_SIZE   ((40 + 7)/8)

// Constants
#define UAVCAN_EQUIPMENT_AIR_DATA_ANGLEOFATTACK_SENSOR_ID_LEFT              254 // 254
#define UAVCAN_EQUIPMENT_AIR_DATA_ANGLEOFATTACK_SENSOR_ID_RIGHT             255 // 255

typedef struct
{
    // FieldTypes
    uint8_t    sensor_id;                     // bit len 8
    float      aoa;                           // float16 Saturate
    float      aoa_variance;                  // float16 Saturate

} uavcan_equipment_air_data_AngleOfAttack;

static inline
uint32_t uavcan_equipment_air_data_AngleOfAttack_encode(uavcan_equipment_air_data_AngleOfAttack* source, void* msg_buf);

static inline
int32_t uavcan_equipment_air_data_AngleOfAttack_decode(const CanardTransfer* transfer, uint16_t payload_len, uavcan_equipment_air_data_AngleOfAttack* dest, uint8_t** dyn_arr_buf);

static inline
uint32_t uavcan_equipment_air_data_AngleOfAttack_encode_internal(uavcan_equipment_air_data_AngleOfAttack* source, void* msg_buf, uint32_t offset, uint8_t root_item);

static inline
int32_t uavcan_equipment_air_data_AngleOfAttack_decode_internal(const CanardTransfer* transfer, uint16_t payload_len, uavcan_equipment_air_data_AngleOfAttack* dest, uint8_t** dyn_arr_buf, int32_t offset);

/*
 * UAVCAN data structure definition for libcanard.
 *
 * Autogenerated, do not edit.
 *
 * Source file: i:\BlackBox\aircraft_h7\module\canard\dsdl\uavcan\equipment\air_data\1025.AngleOfAttack.uavcan
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
  * @brief uavcan_equipment_air_data_AngleOfAttack_encode_internal
  * @param source : pointer to source data struct
  * @param msg_buf: pointer to msg storage
  * @param offset: bit offset to msg storage
  * @param root_item: for detecting if TAO should be used
  * @retval returns offset
  */
uint32_t uavcan_equipment_air_data_AngleOfAttack_encode_internal(uavcan_equipment_air_data_AngleOfAttack* source,
  void* msg_buf,
  uint32_t offset,
  uint8_t CANARD_MAYBE_UNUSED(root_item))
{
#ifndef CANARD_USE_FLOAT16_CAST
    uint16_t tmp_float = 0;
#else
    CANARD_USE_FLOAT16_CAST tmp_float = 0;
#endif

    canardEncodeScalar(msg_buf, offset, 8, (void*)&source->sensor_id); // 255
    offset += 8;

    // float16 special handling
#ifndef CANARD_USE_FLOAT16_CAST
    tmp_float = canardConvertNativeFloatToFloat16(source->aoa);
#else
    tmp_float = (CANARD_USE_FLOAT16_CAST)source->aoa;
#endif
    canardEncodeScalar(msg_buf, offset, 16, (void*)&tmp_float); // 32767
    offset += 16;

    // float16 special handling
#ifndef CANARD_USE_FLOAT16_CAST
    tmp_float = canardConvertNativeFloatToFloat16(source->aoa_variance);
#else
    tmp_float = (CANARD_USE_FLOAT16_CAST)source->aoa_variance;
#endif
    canardEncodeScalar(msg_buf, offset, 16, (void*)&tmp_float); // 32767
    offset += 16;

    return offset;
}

/**
  * @brief uavcan_equipment_air_data_AngleOfAttack_encode
  * @param source : Pointer to source data struct
  * @param msg_buf: Pointer to msg storage
  * @retval returns message length as bytes
  */
uint32_t uavcan_equipment_air_data_AngleOfAttack_encode(uavcan_equipment_air_data_AngleOfAttack* source, void* msg_buf)
{
    uint32_t offset = 0;

    offset = uavcan_equipment_air_data_AngleOfAttack_encode_internal(source, msg_buf, offset, 0);

    return (offset + 7 ) / 8;
}

/**
  * @brief uavcan_equipment_air_data_AngleOfAttack_decode_internal
  * @param transfer: Pointer to CanardTransfer transfer
  * @param payload_len: Payload message length
  * @param dest: Pointer to destination struct
  * @param dyn_arr_buf: NULL or Pointer to memory storage to be used for dynamic arrays
  *                     uavcan_equipment_air_data_AngleOfAttack dyn memory will point to dyn_arr_buf memory.
  *                     NULL will ignore dynamic arrays decoding.
  * @param offset: Call with 0, bit offset to msg storage
  * @retval offset or ERROR value if < 0
  */
int32_t uavcan_equipment_air_data_AngleOfAttack_decode_internal(
  const CanardTransfer* transfer,
  uint16_t CANARD_MAYBE_UNUSED(payload_len),
  uavcan_equipment_air_data_AngleOfAttack* dest,
  uint8_t** CANARD_MAYBE_UNUSED(dyn_arr_buf),
  int32_t offset)
{
    int32_t ret = 0;
#ifndef CANARD_USE_FLOAT16_CAST
    uint16_t tmp_float = 0;
#else
    CANARD_USE_FLOAT16_CAST tmp_float = 0;
#endif

    ret = canardDecodeScalar(transfer, offset, 8, false, (void*)&dest->sensor_id);
    if (ret != 8)
    {
        goto uavcan_equipment_air_data_AngleOfAttack_error_exit;
    }
    offset += 8;

    // float16 special handling
    ret = canardDecodeScalar(transfer, offset, 16, false, (void*)&tmp_float);

    if (ret != 16)
    {
        goto uavcan_equipment_air_data_AngleOfAttack_error_exit;
    }
#ifndef CANARD_USE_FLOAT16_CAST
    dest->aoa = canardConvertFloat16ToNativeFloat(tmp_float);
#else
    dest->aoa = (float)tmp_float;
#endif
    offset += 16;

    // float16 special handling
    ret = canardDecodeScalar(transfer, offset, 16, false, (void*)&tmp_float);

    if (ret != 16)
    {
        goto uavcan_equipment_air_data_AngleOfAttack_error_exit;
    }
#ifndef CANARD_USE_FLOAT16_CAST
    dest->aoa_variance = canardConvertFloat16ToNativeFloat(tmp_float);
#else
    dest->aoa_variance = (float)tmp_float;
#endif
    offset += 16;
    return offset;

uavcan_equipment_air_data_AngleOfAttack_error_exit:
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
  * @brief uavcan_equipment_air_data_AngleOfAttack_decode
  * @param transfer: Pointer to CanardTransfer transfer
  * @param payload_len: Payload message length
  * @param dest: Pointer to destination struct
  * @param dyn_arr_buf: NULL or Pointer to memory storage to be used for dynamic arrays
  *                     uavcan_equipment_air_data_AngleOfAttack dyn memory will point to dyn_arr_buf memory.
  *                     NULL will ignore dynamic arrays decoding.
  * @retval offset or ERROR value if < 0
  */
int32_t uavcan_equipment_air_data_AngleOfAttack_decode(const CanardTransfer* transfer,
  uint16_t payload_len,
  uavcan_equipment_air_data_AngleOfAttack* dest,
  uint8_t** dyn_arr_buf)
{
    const int32_t offset = 0;
    int32_t ret = 0;

    // Clear the destination struct
    for (uint32_t c = 0; c < sizeof(uavcan_equipment_air_data_AngleOfAttack); c++)
    {
        ((uint8_t*)dest)[c] = 0x00;
    }

    ret = uavcan_equipment_air_data_AngleOfAttack_decode_internal(transfer, payload_len, dest, dyn_arr_buf, offset);

    return ret;
}

#ifdef __cplusplus
} // extern "C"
#endif
#endif // __UAVCAN_EQUIPMENT_AIR_DATA_ANGLEOFATTACK