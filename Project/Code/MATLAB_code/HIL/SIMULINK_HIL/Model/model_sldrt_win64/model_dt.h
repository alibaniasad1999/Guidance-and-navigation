/*
 * model_dt.h
 *
 * Code generation for model "model".
 *
 * Model version              : 1.5
 * Simulink Coder version : 9.7 (R2022a) 13-Nov-2021
 * C source code generated on : Sat Jul  8 12:43:32 2023
 *
 * Target selection: sldrt.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Intel->x86-64 (Linux 64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "ext_types.h"

/* data type size table */
static uint_T rtDataTypeSizes[] = {
  sizeof(real_T),
  sizeof(real32_T),
  sizeof(int8_T),
  sizeof(uint8_T),
  sizeof(int16_T),
  sizeof(uint16_T),
  sizeof(int32_T),
  sizeof(uint32_T),
  sizeof(boolean_T),
  sizeof(fcn_call_T),
  sizeof(int_T),
  sizeof(pointer_T),
  sizeof(action_T),
  2*sizeof(uint32_T),
  sizeof(int32_T),
  sizeof(int64_T),
  sizeof(uint64_T),
  sizeof(uint64_T),
  sizeof(int64_T),
  sizeof(char_T),
  sizeof(uchar_T),
  sizeof(time_T)
};

/* data type name table */
static const char_T * rtDataTypeNames[] = {
  "real_T",
  "real32_T",
  "int8_T",
  "uint8_T",
  "int16_T",
  "uint16_T",
  "int32_T",
  "uint32_T",
  "boolean_T",
  "fcn_call_T",
  "int_T",
  "pointer_T",
  "action_T",
  "timer_uint32_pair_T",
  "physical_connection",
  "int64_T",
  "uint64_T",
  "uint64_T",
  "int64_T",
  "char_T",
  "uchar_T",
  "time_T"
};

/* data type transitions for block I/O structure */
static DataTypeTransition rtBTransitions[] = {
  { (char_T *)(&model_B.position_out[0]), 0, 0, 40 },

  { (char_T *)(&model_B.SumofElements), 7, 0, 1 },

  { (char_T *)(&model_B.ByteUnpack[0]), 1, 0, 8 },

  { (char_T *)(&model_B.PacketInput[0]), 3, 0, 36 }
  ,

  { (char_T *)(&model_DW.iteration), 0, 0, 81 },

  { (char_T *)(&model_DW.PacketOutput_PWORK[0]), 11, 0, 4 },

  { (char_T *)(&model_DW.state[0]), 7, 0, 625 },

  { (char_T *)(&model_DW.velocity_not_empty), 8, 0, 1 }
};

/* data type transition table for block I/O structure */
static DataTypeTransitionTable rtBTransTable = {
  8U,
  rtBTransitions
};

/* data type transitions for Parameters structure */
static DataTypeTransition rtPTransitions[] = {
  { (char_T *)(&model_P.PacketOutput_MaxMissedTicks), 0, 0, 4 },

  { (char_T *)(&model_P.PacketOutput_PacketID), 6, 0, 2 },

  { (char_T *)(&model_P.Constant4_Value), 3, 0, 2 }
};

/* data type transition table for Parameters structure */
static DataTypeTransitionTable rtPTransTable = {
  3U,
  rtPTransitions
};

/* [EOF] model_dt.h */
