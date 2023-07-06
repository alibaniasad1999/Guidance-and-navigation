/*
 * model_data.c
 *
 * Code generation for model "model".
 *
 * Model version              : 1.4
 * Simulink Coder version : 9.9 (R2023a) 19-Nov-2022
 * C source code generated on : Thu Jul  6 14:21:00 2023
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
   * Referenced by: '<Root>/Packet Output'
   */
  10.0,

  /* Mask Parameter: PacketInput_MaxMissedTicks
   * Referenced by: '<Root>/Packet Input'
   */
  10.0,

  /* Mask Parameter: PacketOutput_YieldWhenWaiting
   * Referenced by: '<Root>/Packet Output'
   */
  0.0,

  /* Mask Parameter: PacketInput_YieldWhenWaiting
   * Referenced by: '<Root>/Packet Input'
   */
  0.0,

  /* Mask Parameter: PacketOutput_PacketID
   * Referenced by: '<Root>/Packet Output'
   */
  1,

  /* Mask Parameter: PacketInput_PacketID
   * Referenced by: '<Root>/Packet Input'
   */
  1,

  /* Expression: 1
   * Referenced by: '<Root>/Constant'
   */
  1.0
};
