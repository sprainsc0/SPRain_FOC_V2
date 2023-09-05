/*
 * UAVCAN data structure definition for libcanard.
 *
 * Autogenerated, do not edit.
 *
 * Source file: i:\BlackBox\aircraft_h7\module\canard\dsdl\uavcan\equipment\ahrs\1002.MagneticFieldStrength2.uavcan
 */

#ifndef __UAVCAN_EQUIPMENT_AHRS_MAGNETICFIELDSTRENGTH2
#define __UAVCAN_EQUIPMENT_AHRS_MAGNETICFIELDSTRENGTH2

#include <stdint.h>
#include "canard_scalar.h"

#ifdef __cplusplus
extern "C"
{
#endif

#include <uavcan\Timestamp.h>

/******************************* Source text **********************************
# 1002
# Magnetic field readings, in Gauss, in body frame.
# SI units are avoided because of float16 range limitations.
#
uavcan.Timestamp timestamp

uint8 sensor_id

float32[3] magnetic_field_ga
float16 magnetic_field_covariance
******************************************************************************/

/********************* DSDL signature source definition ***********************
uavcan.equipment.ahrs.MagneticFieldStrength2
uavcan.Timestamp timestamp
saturated uint8 sensor_id
saturated float32[3] magnetic_field_ga
saturated float16 magnetic_field_covariance
******************************************************************************/

#define UAVCAN_EQUIPMENT_AHRS_MAGNETICFIELDSTRENGTH2_ID    1002
#define UAVCAN_EQUIPMENT_AHRS_MAGNETICFIELDSTRENGTH2_NAME  "uavcan.equipment.ahrs.MagneticFieldStrength2"
#define UAVCAN_EQUIPMENT_AHRS_MAGNETICFIELDSTRENGTH2_SIGNATURE (0xD2B8AAA5585B5C9EULL)

#define UAVCAN_EQUIPMENT_AHRS_MAGNETICFIELDSTRENGTH2_MAX_SIZE ((176 + 7)/8)

// Constants

#define UAVCAN_EQUIPMENT_AHRS_MAGNETICFIELDSTRENGTH2_MAGNETIC_FIELD_GA_LENGTH            3

typedef struct
{
    // FieldTypes
    uavcan_Timestamp timestamp;                     //
    uint8_t    sensor_id;                     // bit len 8
    float      magnetic_field_ga[3];          // Static Array 32bit[3] max items
    float      magnetic_field_covariance;     // float16 Saturate

} uavcan_equipment_ahrs_MagneticFieldStrength2;

static inline
uint32_t uavcan_equipment_ahrs_MagneticFieldStrength2_encode(uavcan_equipment_ahrs_MagneticFieldStrength2* source, void* msg_buf);

static inline
int32_t uavcan_equipment_ahrs_MagneticFieldStrength2_decode(const CanardTransfer* transfer, uint16_t payload_len, uavcan_equipment_ahrs_MagneticFieldStrength2* dest, uint8_t** dyn_arr_buf);

static inline
uint32_t uavcan_equipment_ahrs_MagneticFieldStrength2_encode_internal(uavcan_equipment_ahrs_MagneticFieldStrength2* source, void* msg_buf, uint32_t offset, uint8_t root_item);

static inline
int32_t uavcan_equipment_ahrs_MagneticFieldStrength2_decode_internal(const CanardTransfer* transfer, uint16_t payload_len, uavcan_equipment_ahrs_MagneticFieldStrength2* dest, uint8_t** dyn_arr_buf, int32_t offset);

/*
 * UAVCAN data structure definition for libcanard.
 *
 * Autogenerated, do not edit.
 *
 * Source file: i:\BlackBox\aircraft_h7\module\canard\dsdl\uavcan\equipment\ahrs\1002.MagneticFieldStrength2.uavcan
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
  * @brief uavcan_equipment_ahrs_MagneticFieldStrength2_encode_internal
  * @param source : pointer to source data struct
  * @param msg_buf: pointer to msg storage
  * @param offset: bit offset to msg storage
  * @param root_item: for detecting if TAO should be used
  * @retval returns offset
  */
uint32_t uavcan_equipment_ahrs_MagneticFieldStrength2_encode_internal(uavcan_equipment_ahrs_MagneticFieldStrength2* source,
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
    canardEncodeScalar(msg_buf, offset, 8, (void*)&source->sensor_id); // 255
    offset += 8;

    // Static array (magnetic_field_ga)
    for (c = 0; c < 3; c++)
    {
        canardEncodeScalar(msg_buf, offset, 32, (void*)(source->magnetic_field_ga + c)); // 2147483647
        offset += 32;
    }

    // float16 special handling
#ifndef CANARD_USE_FLOAT16_CAST
    tmp_float = canardConvertNativeFloatToFloat16(source->magnetic_field_covariance);
#else
    tmp_float = (CANARD_USE_FLOAT16_CAST)source->magnetic_field_covariance;
#endif
    canardEncodeScalar(msg_buf, offset, 16, (void*)&tmp_float); // 32767
    offset += 16;

    return offset;
}

/**
  * @brief uavcan_equipment_ahrs_MagneticFieldStrength2_encode
  * @param source : Pointer to source data struct
  * @param msg_buf: Pointer to msg storage
  * @retval returns message length as bytes
  */
uint32_t uavcan_equipment_ahrs_MagneticFieldStrength2_encode(uavcan_equipment_ahrs_MagneticFieldStrength2* source, void* msg_buf)
{
    uint32_t offset = 0;

    offset = uavcan_equipment_ahrs_MagneticFieldStrength2_encode_internal(source, msg_buf, offset, 0);

    return (offset + 7 ) / 8;
}

/**
  * @brief uavcan_equipment_ahrs_MagneticFieldStrength2_decode_internal
  * @param transfer: Pointer to CanardTransfer transfer
  * @param payload_len: Payload message length
  * @param dest: Pointer to destination struct
  * @param dyn_arr_buf: NULL or Pointer to memory storage to be used for dynamic arrays
  *                     uavcan_equipment_ahrs_MagneticFieldStrength2 dyn memory will point to dyn_arr_buf memory.
  *                     NULL will ignore dynamic arrays decoding.
  * @param offset: Call with 0, bit offset to msg storage
  * @retval offset or ERROR value if < 0
  */
int32_t uavcan_equipment_ahrs_MagneticFieldStrength2_decode_internal(
  const CanardTransfer* transfer,
  uint16_t CANARD_MAYBE_UNUSED(payload_len),
  uavcan_equipment_ahrs_MagneticFieldStrength2* dest,
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
        goto uavcan_equipment_ahrs_MagneticFieldStrength2_error_exit;
    }

    ret = canardDecodeScalar(transfer, offset, 8, false, (void*)&dest->sensor_id);
    if (ret != 8)
    {
        goto uavcan_equipment_ahrs_MagneticFieldStrength2_error_exit;
    }
    offset += 8;

    // Static array (magnetic_field_ga)
    for (c = 0; c < 3; c++)
    {
        ret = canardDecodeScalar(transfer, offset, 32, false, (void*)(dest->magnetic_field_ga + c));
        if (ret != 32)
        {
            goto uavcan_equipment_ahrs_MagneticFieldStrength2_error_exit;
        }
        offset += 32;
    }

    // float16 special handling
    ret = canardDecodeScalar(transfer, offset, 16, false, (void*)&tmp_float);

    if (ret != 16)
    {
        goto uavcan_equipment_ahrs_MagneticFieldStrength2_error_exit;
    }
#ifndef CANARD_USE_FLOAT16_CAST
    dest->magnetic_field_covariance = canardConvertFloat16ToNativeFloat(tmp_float);
#else
    dest->magnetic_field_covariance = (float)tmp_float;
#endif
    offset += 16;
    return offset;

uavcan_equipment_ahrs_MagneticFieldStrength2_error_exit:
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
  * @brief uavcan_equipment_ahrs_MagneticFieldStrength2_decode
  * @param transfer: Pointer to CanardTransfer transfer
  * @param payload_len: Payload message length
  * @param dest: Pointer to destination struct
  * @param dyn_arr_buf: NULL or Pointer to memory storage to be used for dynamic arrays
  *                     uavcan_equipment_ahrs_MagneticFieldStrength2 dyn memory will point to dyn_arr_buf memory.
  *                     NULL will ignore dynamic arrays decoding.
  * @retval offset or ERROR value if < 0
  */
int32_t uavcan_equipment_ahrs_MagneticFieldStrength2_decode(const CanardTransfer* transfer,
  uint16_t payload_len,
  uavcan_equipment_ahrs_MagneticFieldStrength2* dest,
  uint8_t** dyn_arr_buf)
{
    const int32_t offset = 0;
    int32_t ret = 0;

    // Clear the destination struct
    for (uint32_t c = 0; c < sizeof(uavcan_equipment_ahrs_MagneticFieldStrength2); c++)
    {
        ((uint8_t*)dest)[c] = 0x00;
    }

    ret = uavcan_equipment_ahrs_MagneticFieldStrength2_decode_internal(transfer, payload_len, dest, dyn_arr_buf, offset);

    return ret;
}

#ifdef __cplusplus
} // extern "C"
#endif
#endif // __UAVCAN_EQUIPMENT_AHRS_MAGNETICFIELDSTRENGTH2