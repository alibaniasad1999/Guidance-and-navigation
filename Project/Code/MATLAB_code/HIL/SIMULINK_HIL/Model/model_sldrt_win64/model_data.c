/*
 * model_data.c
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

#include "model.h"

/* Block parameters (default storage) */
P_model_T model_P = {
  /* Mask Parameter: PacketOutput_MaxMissedTicks
   * Referenced by: '<S2>/Packet Output'
   */
  10.0,

  /* Mask Parameter: PacketInput_MaxMissedTicks
   * Referenced by: '<Root>/Packet Input'
   */
  10.0,

  /* Mask Parameter: PacketOutput_YieldWhenWaiting
   * Referenced by: '<S2>/Packet Output'
   */
  0.0,

  /* Mask Parameter: PacketInput_YieldWhenWaiting
   * Referenced by: '<Root>/Packet Input'
   */
  0.0,

  /* Mask Parameter: PacketOutput_PacketID
   * Referenced by: '<S2>/Packet Output'
   */
  1,

  /* Mask Parameter: PacketInput_PacketID
   * Referenced by: '<Root>/Packet Input'
   */
  1,

  /* Computed Parameter: Constant4_Value
   * Referenced by: '<S2>/Constant4'
   */
  85U,

  /* Computed Parameter: Constant5_Value
   * Referenced by: '<S2>/Constant5'
   */
  100U
};
