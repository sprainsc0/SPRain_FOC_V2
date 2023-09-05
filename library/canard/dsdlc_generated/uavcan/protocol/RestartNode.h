/*
 * UAVCAN data structure definition for libcanard.
 *
 * Autogenerated, do not edit.
 *
 * Source file: i:\BlackBox\aircraft_h7\module\canard\dsdl\uavcan\protocol\5.RestartNode.uavcan
 */

#ifndef __UAVCAN_PROTOCOL_RESTARTNODE
#define __UAVCAN_PROTOCOL_RESTARTNODE

#include <stdint.h>
#include "canard_scalar.h"

#ifdef __cplusplus
extern "C"
{
#endif

/******************************* Source text **********************************
#
# Restart the node.
#
# Some nodes may require restart before the new configuration will be applied.
#
# The request should be rejected if magic_number does not equal MAGIC_NUMBER.
#

uint40 MAGIC_NUMBER = 0xACCE551B1E
uint40 magic_number

---

bool ok
******************************************************************************/

/********************* DSDL signature source definition ***********************
uavcan.protocol.RestartNode
saturated uint40 magic_number
---
saturated bool ok
******************************************************************************/

#define UAVCAN_PROTOCOL_RESTARTNODE_ID                     5
#define UAVCAN_PROTOCOL_RESTARTNODE_NAME                   "uavcan.protocol.RestartNode"
#define UAVCAN_PROTOCOL_RESTARTNODE_SIGNATURE              (0x569E05394A3017F0ULL)

#define UAVCAN_PROTOCOL_RESTARTNODE_REQUEST_MAX_SIZE       ((40 + 7)/8)

// Constants
#define UAVCAN_PROTOCOL_RESTARTNODE_REQUEST_MAGIC_NUMBER             0xACCE551B1E // 0xACCE551B1E

typedef struct
{
    // FieldTypes
    uint64_t   magic_number;                  // bit len 40

} uavcan_protocol_RestartNodeRequest;

static inline
uint32_t uavcan_protocol_RestartNodeRequest_encode(uavcan_protocol_RestartNodeRequest* source, void* msg_buf);

static inline
int32_t uavcan_protocol_RestartNodeRequest_decode(const CanardTransfer* transfer, uint16_t payload_len, uavcan_protocol_RestartNodeRequest* dest, uint8_t** dyn_arr_buf);

static inline
uint32_t uavcan_protocol_RestartNodeRequest_encode_internal(uavcan_protocol_RestartNodeRequest* source, void* msg_buf, uint32_t offset, uint8_t root_item);

static inline
int32_t uavcan_protocol_RestartNodeRequest_decode_internal(const CanardTransfer* transfer, uint16_t payload_len, uavcan_protocol_RestartNodeRequest* dest, uint8_t** dyn_arr_buf, int32_t offset);

#define UAVCAN_PROTOCOL_RESTARTNODE_RESPONSE_MAX_SIZE      ((1 + 7)/8)

// Constants

typedef struct
{
    // FieldTypes
    bool       ok;                            // bit len 1

} uavcan_protocol_RestartNodeResponse;

static inline
uint32_t uavcan_protocol_RestartNodeResponse_encode(uavcan_protocol_RestartNodeResponse* source, void* msg_buf);

static inline
int32_t uavcan_protocol_RestartNodeResponse_decode(const CanardTransfer* transfer, uint16_t payload_len, uavcan_protocol_RestartNodeResponse* dest, uint8_t** dyn_arr_buf);

static inline
uint32_t uavcan_protocol_RestartNodeResponse_encode_internal(uavcan_protocol_RestartNodeResponse* source, void* msg_buf, uint32_t offset, uint8_t root_item);

static inline
int32_t uavcan_protocol_RestartNodeResponse_decode_internal(const CanardTransfer* transfer, uint16_t payload_len, uavcan_protocol_RestartNodeResponse* dest, uint8_t** dyn_arr_buf, int32_t offset);

/*
 * UAVCAN data structure definition for libcanard.
 *
 * Autogenerated, do not edit.
 *
 * Source file: i:\BlackBox\aircraft_h7\module\canard\dsdl\uavcan\protocol\5.RestartNode.uavcan
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
  * @brief uavcan_protocol_RestartNodeRequest_encode_internal
  * @param source : pointer to source data struct
  * @param msg_buf: pointer to msg storage
  * @param offset: bit offset to msg storage
  * @param root_item: for detecting if TAO should be used
  * @retval returns offset
  */
uint32_t uavcan_protocol_RestartNodeRequest_encode_internal(uavcan_protocol_RestartNodeRequest* source,
  void* msg_buf,
  uint32_t offset,
  uint8_t CANARD_MAYBE_UNUSED(root_item))
{
    source->magic_number = CANARD_INTERNAL_SATURATE_UNSIGNED(source->magic_number, 1099511627775)
    canardEncodeScalar(msg_buf, offset, 40, (void*)&source->magic_number); // 1099511627775
    offset += 40;

    return offset;
}

/**
  * @brief uavcan_protocol_RestartNodeRequest_encode
  * @param source : Pointer to source data struct
  * @param msg_buf: Pointer to msg storage
  * @retval returns message length as bytes
  */
uint32_t uavcan_protocol_RestartNodeRequest_encode(uavcan_protocol_RestartNodeRequest* source, void* msg_buf)
{
    uint32_t offset = 0;

    offset = uavcan_protocol_RestartNodeRequest_encode_internal(source, msg_buf, offset, 0);

    return (offset + 7 ) / 8;
}

/**
  * @brief uavcan_protocol_RestartNodeRequest_decode_internal
  * @param transfer: Pointer to CanardTransfer transfer
  * @param payload_len: Payload message length
  * @param dest: Pointer to destination struct
  * @param dyn_arr_buf: NULL or Pointer to memory storage to be used for dynamic arrays
  *                     uavcan_protocol_RestartNodeRequest dyn memory will point to dyn_arr_buf memory.
  *                     NULL will ignore dynamic arrays decoding.
  * @param offset: Call with 0, bit offset to msg storage
  * @retval offset or ERROR value if < 0
  */
int32_t uavcan_protocol_RestartNodeRequest_decode_internal(
  const CanardTransfer* transfer,
  uint16_t CANARD_MAYBE_UNUSED(payload_len),
  uavcan_protocol_RestartNodeRequest* dest,
  uint8_t** CANARD_MAYBE_UNUSED(dyn_arr_buf),
  int32_t offset)
{
    int32_t ret = 0;

    ret = canardDecodeScalar(transfer, offset, 40, false, (void*)&dest->magic_number);
    if (ret != 40)
    {
        goto uavcan_protocol_RestartNodeRequest_error_exit;
    }
    offset += 40;
    return offset;

uavcan_protocol_RestartNodeRequest_error_exit:
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
  * @brief uavcan_protocol_RestartNodeRequest_decode
  * @param transfer: Pointer to CanardTransfer transfer
  * @param payload_len: Payload message length
  * @param dest: Pointer to destination struct
  * @param dyn_arr_buf: NULL or Pointer to memory storage to be used for dynamic arrays
  *                     uavcan_protocol_RestartNodeRequest dyn memory will point to dyn_arr_buf memory.
  *                     NULL will ignore dynamic arrays decoding.
  * @retval offset or ERROR value if < 0
  */
int32_t uavcan_protocol_RestartNodeRequest_decode(const CanardTransfer* transfer,
  uint16_t payload_len,
  uavcan_protocol_RestartNodeRequest* dest,
  uint8_t** dyn_arr_buf)
{
    const int32_t offset = 0;
    int32_t ret = 0;

    // Clear the destination struct
    for (uint32_t c = 0; c < sizeof(uavcan_protocol_RestartNodeRequest); c++)
    {
        ((uint8_t*)dest)[c] = 0x00;
    }

    ret = uavcan_protocol_RestartNodeRequest_decode_internal(transfer, payload_len, dest, dyn_arr_buf, offset);

    return ret;
}

/**
  * @brief uavcan_protocol_RestartNodeResponse_encode_internal
  * @param source : pointer to source data struct
  * @param msg_buf: pointer to msg storage
  * @param offset: bit offset to msg storage
  * @param root_item: for detecting if TAO should be used
  * @retval returns offset
  */
uint32_t uavcan_protocol_RestartNodeResponse_encode_internal(uavcan_protocol_RestartNodeResponse* source,
  void* msg_buf,
  uint32_t offset,
  uint8_t CANARD_MAYBE_UNUSED(root_item))
{
    source->ok = CANARD_INTERNAL_SATURATE_UNSIGNED(source->ok, 0)
    canardEncodeScalar(msg_buf, offset, 1, (void*)&source->ok); // 0
    offset += 1;

    return offset;
}

/**
  * @brief uavcan_protocol_RestartNodeResponse_encode
  * @param source : Pointer to source data struct
  * @param msg_buf: Pointer to msg storage
  * @retval returns message length as bytes
  */
uint32_t uavcan_protocol_RestartNodeResponse_encode(uavcan_protocol_RestartNodeResponse* source, void* msg_buf)
{
    uint32_t offset = 0;

    offset = uavcan_protocol_RestartNodeResponse_encode_internal(source, msg_buf, offset, 0);

    return (offset + 7 ) / 8;
}

/**
  * @brief uavcan_protocol_RestartNodeResponse_decode_internal
  * @param transfer: Pointer to CanardTransfer transfer
  * @param payload_len: Payload message length
  * @param dest: Pointer to destination struct
  * @param dyn_arr_buf: NULL or Pointer to memory storage to be used for dynamic arrays
  *                     uavcan_protocol_RestartNodeResponse dyn memory will point to dyn_arr_buf memory.
  *                     NULL will ignore dynamic arrays decoding.
  * @param offset: Call with 0, bit offset to msg storage
  * @retval offset or ERROR value if < 0
  */
int32_t uavcan_protocol_RestartNodeResponse_decode_internal(
  const CanardTransfer* transfer,
  uint16_t CANARD_MAYBE_UNUSED(payload_len),
  uavcan_protocol_RestartNodeResponse* dest,
  uint8_t** CANARD_MAYBE_UNUSED(dyn_arr_buf),
  int32_t offset)
{
    int32_t ret = 0;

    ret = canardDecodeScalar(transfer, offset, 1, false, (void*)&dest->ok);
    if (ret != 1)
    {
        goto uavcan_protocol_RestartNodeResponse_error_exit;
    }
    offset += 1;
    return offset;

uavcan_protocol_RestartNodeResponse_error_exit:
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
  * @brief uavcan_protocol_RestartNodeResponse_decode
  * @param transfer: Pointer to CanardTransfer transfer
  * @param payload_len: Payload message length
  * @param dest: Pointer to destination struct
  * @param dyn_arr_buf: NULL or Pointer to memory storage to be used for dynamic arrays
  *                     uavcan_protocol_RestartNodeResponse dyn memory will point to dyn_arr_buf memory.
  *                     NULL will ignore dynamic arrays decoding.
  * @retval offset or ERROR value if < 0
  */
int32_t uavcan_protocol_RestartNodeResponse_decode(const CanardTransfer* transfer,
  uint16_t payload_len,
  uavcan_protocol_RestartNodeResponse* dest,
  uint8_t** dyn_arr_buf)
{
    const int32_t offset = 0;
    int32_t ret = 0;

    // Clear the destination struct
    for (uint32_t c = 0; c < sizeof(uavcan_protocol_RestartNodeResponse); c++)
    {
        ((uint8_t*)dest)[c] = 0x00;
    }

    ret = uavcan_protocol_RestartNodeResponse_decode_internal(transfer, payload_len, dest, dyn_arr_buf, offset);

    return ret;
}

#ifdef __cplusplus
} // extern "C"
#endif
#endif // __UAVCAN_PROTOCOL_RESTARTNODE