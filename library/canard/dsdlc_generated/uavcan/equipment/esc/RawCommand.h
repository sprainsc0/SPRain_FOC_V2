/*
 * UAVCAN data structure definition for libcanard.
 *
 * Autogenerated, do not edit.
 *
 * Source file: i:\BlackBox\aircraft_h7\module\canard\dsdl\uavcan\equipment\esc\1030.RawCommand.uavcan
 */

#ifndef __UAVCAN_EQUIPMENT_ESC_RAWCOMMAND
#define __UAVCAN_EQUIPMENT_ESC_RAWCOMMAND

#include <stdint.h>
#include "canard_scalar.h"

#ifdef __cplusplus
extern "C"
{
#endif

/******************************* Source text **********************************
#
# Raw ESC command normalized into [-8192, 8191]; negative values indicate reverse rotation.
# The ESC should normalize the setpoint into its effective input range.
# Non-zero setpoint value below minimum should be interpreted as min valid setpoint for the given motor.
#

int14[<=20] cmd
******************************************************************************/

/********************* DSDL signature source definition ***********************
uavcan.equipment.esc.RawCommand
saturated int14[<=20] cmd
******************************************************************************/

#define UAVCAN_EQUIPMENT_ESC_RAWCOMMAND_ID                 1030
#define UAVCAN_EQUIPMENT_ESC_RAWCOMMAND_NAME               "uavcan.equipment.esc.RawCommand"
#define UAVCAN_EQUIPMENT_ESC_RAWCOMMAND_SIGNATURE          (0x217F5C87D7EC951DULL)

#define UAVCAN_EQUIPMENT_ESC_RAWCOMMAND_MAX_SIZE           ((285 + 7)/8)

// Constants

#define UAVCAN_EQUIPMENT_ESC_RAWCOMMAND_CMD_MAX_LENGTH                                   20

typedef struct
{
    // FieldTypes
    struct
    {
        uint8_t    len;                       // Dynamic array length
        int16_t*   data;                      // Dynamic Array 14bit[20] max items
    } cmd;

} uavcan_equipment_esc_RawCommand;

static inline
uint32_t uavcan_equipment_esc_RawCommand_encode(uavcan_equipment_esc_RawCommand* source, void* msg_buf);

static inline
int32_t uavcan_equipment_esc_RawCommand_decode(const CanardTransfer* transfer, uint16_t payload_len, uavcan_equipment_esc_RawCommand* dest, uint8_t** dyn_arr_buf);

static inline
uint32_t uavcan_equipment_esc_RawCommand_encode_internal(uavcan_equipment_esc_RawCommand* source, void* msg_buf, uint32_t offset, uint8_t root_item);

static inline
int32_t uavcan_equipment_esc_RawCommand_decode_internal(const CanardTransfer* transfer, uint16_t payload_len, uavcan_equipment_esc_RawCommand* dest, uint8_t** dyn_arr_buf, int32_t offset);

/*
 * UAVCAN data structure definition for libcanard.
 *
 * Autogenerated, do not edit.
 *
 * Source file: i:\BlackBox\aircraft_h7\module\canard\dsdl\uavcan\equipment\esc\1030.RawCommand.uavcan
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
  * @brief uavcan_equipment_esc_RawCommand_encode_internal
  * @param source : pointer to source data struct
  * @param msg_buf: pointer to msg storage
  * @param offset: bit offset to msg storage
  * @param root_item: for detecting if TAO should be used
  * @retval returns offset
  */
uint32_t uavcan_equipment_esc_RawCommand_encode_internal(uavcan_equipment_esc_RawCommand* source,
  void* msg_buf,
  uint32_t offset,
  uint8_t CANARD_MAYBE_UNUSED(root_item))
{
    uint32_t c = 0;

    // Dynamic Array (cmd)
    if (! root_item)
    {
        // - Add array length
        canardEncodeScalar(msg_buf, offset, 5, (void*)&source->cmd.len);
        offset += 5;
    }

    // - Add array items
    for (c = 0; c < source->cmd.len; c++)
    {
        canardEncodeScalar(msg_buf,
                           offset,
                           14,
                           (void*)(source->cmd.data + c));// 8191
        offset += 14;
    }

    return offset;
}

/**
  * @brief uavcan_equipment_esc_RawCommand_encode
  * @param source : Pointer to source data struct
  * @param msg_buf: Pointer to msg storage
  * @retval returns message length as bytes
  */
uint32_t uavcan_equipment_esc_RawCommand_encode(uavcan_equipment_esc_RawCommand* source, void* msg_buf)
{
    uint32_t offset = 0;

    offset = uavcan_equipment_esc_RawCommand_encode_internal(source, msg_buf, offset, 0);

    return (offset + 7 ) / 8;
}

/**
  * @brief uavcan_equipment_esc_RawCommand_decode_internal
  * @param transfer: Pointer to CanardTransfer transfer
  * @param payload_len: Payload message length
  * @param dest: Pointer to destination struct
  * @param dyn_arr_buf: NULL or Pointer to memory storage to be used for dynamic arrays
  *                     uavcan_equipment_esc_RawCommand dyn memory will point to dyn_arr_buf memory.
  *                     NULL will ignore dynamic arrays decoding.
  * @param offset: Call with 0, bit offset to msg storage
  * @retval offset or ERROR value if < 0
  */
int32_t uavcan_equipment_esc_RawCommand_decode_internal(
  const CanardTransfer* transfer,
  uint16_t CANARD_MAYBE_UNUSED(payload_len),
  uavcan_equipment_esc_RawCommand* dest,
  uint8_t** CANARD_MAYBE_UNUSED(dyn_arr_buf),
  int32_t offset)
{
    int32_t ret = 0;
    uint32_t c = 0;

    // Dynamic Array (cmd)
    //  - Last item in struct & Root item & (Array Size > 8 bit), tail array optimization
    if (payload_len)
    {
        //  - Calculate Array length from MSG length
        dest->cmd.len = ((payload_len * 8) - offset ) / 14; // 14 bit array item size
    }
    else
    {
        // - Array length 5 bits
        ret = canardDecodeScalar(transfer,
                                 offset,
                                 5,
                                 false,
                                 (void*)&dest->cmd.len); // 8191
        if (ret != 5)
        {
            goto uavcan_equipment_esc_RawCommand_error_exit;
        }
        offset += 5;
    }

    //  - Get Array
    if (dyn_arr_buf)
    {
        dest->cmd.data = (int16_t*)*dyn_arr_buf;
    }

    for (c = 0; c < dest->cmd.len; c++)
    {
        if (dyn_arr_buf)
        {
            ret = canardDecodeScalar(transfer,
                                     offset,
                                     14,
                                     true,
                                     (void*)*dyn_arr_buf); // 8191
            if (ret != 14)
            {
                goto uavcan_equipment_esc_RawCommand_error_exit;
            }
            *dyn_arr_buf = (uint8_t*)(((int16_t*)*dyn_arr_buf) + 1);

        }
        offset += 14;
    }
    return offset;

uavcan_equipment_esc_RawCommand_error_exit:
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
  * @brief uavcan_equipment_esc_RawCommand_decode
  * @param transfer: Pointer to CanardTransfer transfer
  * @param payload_len: Payload message length
  * @param dest: Pointer to destination struct
  * @param dyn_arr_buf: NULL or Pointer to memory storage to be used for dynamic arrays
  *                     uavcan_equipment_esc_RawCommand dyn memory will point to dyn_arr_buf memory.
  *                     NULL will ignore dynamic arrays decoding.
  * @retval offset or ERROR value if < 0
  */
int32_t uavcan_equipment_esc_RawCommand_decode(const CanardTransfer* transfer,
  uint16_t payload_len,
  uavcan_equipment_esc_RawCommand* dest,
  uint8_t** dyn_arr_buf)
{
    const int32_t offset = 0;
    int32_t ret = 0;

    // Clear the destination struct
    for (uint32_t c = 0; c < sizeof(uavcan_equipment_esc_RawCommand); c++)
    {
        ((uint8_t*)dest)[c] = 0x00;
    }

    ret = uavcan_equipment_esc_RawCommand_decode_internal(transfer, payload_len, dest, dyn_arr_buf, offset);

    return ret;
}

#ifdef __cplusplus
} // extern "C"
#endif
#endif // __UAVCAN_EQUIPMENT_ESC_RAWCOMMAND