/*
 * UAVCAN data structure definition for libcanard.
 *
 * Autogenerated, do not edit.
 *
 * Source file: i:\BlackBox\aircraft_h7\module\canard\dsdl\uavcan\equipment\air_data\1028.StaticPressure.uavcan
 */

#ifndef __UAVCAN_EQUIPMENT_AIR_DATA_STATICPRESSURE
#define __UAVCAN_EQUIPMENT_AIR_DATA_STATICPRESSURE

#include <stdint.h>
#include "canard_scalar.h"

#ifdef __cplusplus
extern "C"
{
#endif

/******************************* Source text **********************************
# 1028
# Static pressure.
#

float32 static_pressure                 # Pascal
float16 static_pressure_variance        # Pascal^2
******************************************************************************/

/********************* DSDL signature source definition ***********************
uavcan.equipment.air_data.StaticPressure
saturated float32 static_pressure
saturated float16 static_pressure_variance
******************************************************************************/

#define UAVCAN_EQUIPMENT_AIR_DATA_STATICPRESSURE_ID        1028
#define UAVCAN_EQUIPMENT_AIR_DATA_STATICPRESSURE_NAME      "uavcan.equipment.air_data.StaticPressure"
#define UAVCAN_EQUIPMENT_AIR_DATA_STATICPRESSURE_SIGNATURE (0xCDC7C43412BDC89AULL)

#define UAVCAN_EQUIPMENT_AIR_DATA_STATICPRESSURE_MAX_SIZE  ((48 + 7)/8)

// Constants

typedef struct
{
    // FieldTypes
    float      static_pressure;               // float32 Saturate
    float      static_pressure_variance;      // float16 Saturate

} uavcan_equipment_air_data_StaticPressure;

static inline
uint32_t uavcan_equipment_air_data_StaticPressure_encode(uavcan_equipment_air_data_StaticPressure* source, void* msg_buf);

static inline
int32_t uavcan_equipment_air_data_StaticPressure_decode(const CanardTransfer* transfer, uint16_t payload_len, uavcan_equipment_air_data_StaticPressure* dest, uint8_t** dyn_arr_buf);

static inline
uint32_t uavcan_equipment_air_data_StaticPressure_encode_internal(uavcan_equipment_air_data_StaticPressure* source, void* msg_buf, uint32_t offset, uint8_t root_item);

static inline
int32_t uavcan_equipment_air_data_StaticPressure_decode_internal(const CanardTransfer* transfer, uint16_t payload_len, uavcan_equipment_air_data_StaticPressure* dest, uint8_t** dyn_arr_buf, int32_t offset);

/*
 * UAVCAN data structure definition for libcanard.
 *
 * Autogenerated, do not edit.
 *
 * Source file: i:\BlackBox\aircraft_h7\module\canard\dsdl\uavcan\equipment\air_data\1028.StaticPressure.uavcan
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
  * @brief uavcan_equipment_air_data_StaticPressure_encode_internal
  * @param source : pointer to source data struct
  * @param msg_buf: pointer to msg storage
  * @param offset: bit offset to msg storage
  * @param root_item: for detecting if TAO should be used
  * @retval returns offset
  */
uint32_t uavcan_equipment_air_data_StaticPressure_encode_internal(uavcan_equipment_air_data_StaticPressure* source,
  void* msg_buf,
  uint32_t offset,
  uint8_t CANARD_MAYBE_UNUSED(root_item))
{
#ifndef CANARD_USE_FLOAT16_CAST
    uint16_t tmp_float = 0;
#else
    CANARD_USE_FLOAT16_CAST tmp_float = 0;
#endif

    canardEncodeScalar(msg_buf, offset, 32, (void*)&source->static_pressure); // 2147483647
    offset += 32;

    // float16 special handling
#ifndef CANARD_USE_FLOAT16_CAST
    tmp_float = canardConvertNativeFloatToFloat16(source->static_pressure_variance);
#else
    tmp_float = (CANARD_USE_FLOAT16_CAST)source->static_pressure_variance;
#endif
    canardEncodeScalar(msg_buf, offset, 16, (void*)&tmp_float); // 32767
    offset += 16;

    return offset;
}

/**
  * @brief uavcan_equipment_air_data_StaticPressure_encode
  * @param source : Pointer to source data struct
  * @param msg_buf: Pointer to msg storage
  * @retval returns message length as bytes
  */
uint32_t uavcan_equipment_air_data_StaticPressure_encode(uavcan_equipment_air_data_StaticPressure* source, void* msg_buf)
{
    uint32_t offset = 0;

    offset = uavcan_equipment_air_data_StaticPressure_encode_internal(source, msg_buf, offset, 0);

    return (offset + 7 ) / 8;
}

/**
  * @brief uavcan_equipment_air_data_StaticPressure_decode_internal
  * @param transfer: Pointer to CanardTransfer transfer
  * @param payload_len: Payload message length
  * @param dest: Pointer to destination struct
  * @param dyn_arr_buf: NULL or Pointer to memory storage to be used for dynamic arrays
  *                     uavcan_equipment_air_data_StaticPressure dyn memory will point to dyn_arr_buf memory.
  *                     NULL will ignore dynamic arrays decoding.
  * @param offset: Call with 0, bit offset to msg storage
  * @retval offset or ERROR value if < 0
  */
int32_t uavcan_equipment_air_data_StaticPressure_decode_internal(
  const CanardTransfer* transfer,
  uint16_t CANARD_MAYBE_UNUSED(payload_len),
  uavcan_equipment_air_data_StaticPressure* dest,
  uint8_t** CANARD_MAYBE_UNUSED(dyn_arr_buf),
  int32_t offset)
{
    int32_t ret = 0;
#ifndef CANARD_USE_FLOAT16_CAST
    uint16_t tmp_float = 0;
#else
    CANARD_USE_FLOAT16_CAST tmp_float = 0;
#endif

    ret = canardDecodeScalar(transfer, offset, 32, false, (void*)&dest->static_pressure);
    if (ret != 32)
    {
        goto uavcan_equipment_air_data_StaticPressure_error_exit;
    }
    offset += 32;

    // float16 special handling
    ret = canardDecodeScalar(transfer, offset, 16, false, (void*)&tmp_float);

    if (ret != 16)
    {
        goto uavcan_equipment_air_data_StaticPressure_error_exit;
    }
#ifndef CANARD_USE_FLOAT16_CAST
    dest->static_pressure_variance = canardConvertFloat16ToNativeFloat(tmp_float);
#else
    dest->static_pressure_variance = (float)tmp_float;
#endif
    offset += 16;
    return offset;

uavcan_equipment_air_data_StaticPressure_error_exit:
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
  * @brief uavcan_equipment_air_data_StaticPressure_decode
  * @param transfer: Pointer to CanardTransfer transfer
  * @param payload_len: Payload message length
  * @param dest: Pointer to destination struct
  * @param dyn_arr_buf: NULL or Pointer to memory storage to be used for dynamic arrays
  *                     uavcan_equipment_air_data_StaticPressure dyn memory will point to dyn_arr_buf memory.
  *                     NULL will ignore dynamic arrays decoding.
  * @retval offset or ERROR value if < 0
  */
int32_t uavcan_equipment_air_data_StaticPressure_decode(const CanardTransfer* transfer,
  uint16_t payload_len,
  uavcan_equipment_air_data_StaticPressure* dest,
  uint8_t** dyn_arr_buf)
{
    const int32_t offset = 0;
    int32_t ret = 0;

    // Clear the destination struct
    for (uint32_t c = 0; c < sizeof(uavcan_equipment_air_data_StaticPressure); c++)
    {
        ((uint8_t*)dest)[c] = 0x00;
    }

    ret = uavcan_equipment_air_data_StaticPressure_decode_internal(transfer, payload_len, dest, dyn_arr_buf, offset);

    return ret;
}

#ifdef __cplusplus
} // extern "C"
#endif
#endif // __UAVCAN_EQUIPMENT_AIR_DATA_STATICPRESSURE