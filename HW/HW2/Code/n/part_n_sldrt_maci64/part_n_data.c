/*
 * part_n_data.c
 *
 * Code generation for model "part_n".
 *
 * Model version              : 1.66
 * Simulink Coder version : 9.8 (R2022b) 13-May-2022
 * C source code generated on : Sun Apr 23 03:51:46 2023
 *
 * Target selection: sldrt.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Intel->x86-64 (Linux 64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "part_n.h"

/* Block parameters (default storage) */
P_part_n_T part_n_P = {
  /* Variable: attitude_m0
   * Referenced by: '<S4>/Integrator2'
   */
  { 0.3490658503988659, 0.0 },

  /* Variable: attitude_t0
   * Referenced by: '<S5>/Integrator2'
   */
  { 0.0, 3.1415926535897931 },

  /* Variable: d_state_m
   * Referenced by: '<S4>/Integrator'
   */
  { 93.969262078590845, 0.0, 34.202014332566868 },

  /* Variable: d_state_t
   * Referenced by: '<S5>/Integrator'
   */
  { -300.0, 3.6739403974420595E-14, 0.0 },

  /* Variable: k_epsilon_lead_angle
   * Referenced by: '<S10>/Gain1'
   */
  71.513378368178266,

  /* Variable: k_sigma_lead_angle
   * Referenced by: '<S9>/Gain'
   */
  50.0,

  /* Variable: state_m0
   * Referenced by: '<S4>/Integrator1'
   */
  { 0.0, 0.0, 0.0 },

  /* Variable: state_t0
   * Referenced by: '<S5>/Integrator1'
   */
  { 8000.0, 0.0, 3000.0 },

  /* Mask Parameter: MinMaxRunningResettable_vinit
   * Referenced by:
   *   '<S19>/Initial Condition'
   *   '<S19>/Memory'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S3>/Constant'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S17>/Constant3'
   */
  0.0,

  /* Expression: inf
   * Referenced by: '<S17>/Delay'
   */
  0.0,

  /* Expression: 1
   * Referenced by: '<S17>/Constant4'
   */
  1.0,

  /* Expression: 0
   * Referenced by: '<S17>/Switch'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S18>/Constant3'
   */
  0.0,

  /* Expression: inf
   * Referenced by: '<S18>/Delay'
   */
  0.0,

  /* Expression: 1
   * Referenced by: '<S18>/Constant4'
   */
  1.0,

  /* Expression: 0
   * Referenced by: '<S18>/Switch'
   */
  0.0,

  /* Expression: 1
   * Referenced by: '<S1>/Constant7'
   */
  1.0,

  /* Expression: [0; 0; -10]
   * Referenced by: '<S1>/Constant8'
   */
  { 0.0, 0.0, -10.0 },

  /* Expression: 0
   * Referenced by: '<S1>/Constant9'
   */
  0.0,

  /* Expression: 0.0
   * Referenced by: '<S11>/Delay1'
   */
  0.0,

  /* Computed Parameter: TransferFcn_A
   * Referenced by: '<S12>/Transfer Fcn'
   */
  -100.0,

  /* Computed Parameter: TransferFcn_C
   * Referenced by: '<S12>/Transfer Fcn'
   */
  -10000.0,

  /* Computed Parameter: TransferFcn_D
   * Referenced by: '<S12>/Transfer Fcn'
   */
  100.0,

  /* Computed Parameter: TransferFcn4_A
   * Referenced by: '<S12>/Transfer Fcn4'
   */
  -100.0,

  /* Computed Parameter: TransferFcn4_C
   * Referenced by: '<S12>/Transfer Fcn4'
   */
  -10000.0,

  /* Computed Parameter: TransferFcn4_D
   * Referenced by: '<S12>/Transfer Fcn4'
   */
  100.0,

  /* Expression: 0.0
   * Referenced by: '<S11>/Delay'
   */
  0.0,

  /* Computed Parameter: TransferFcn2_A
   * Referenced by: '<S12>/Transfer Fcn2'
   */
  -100.0,

  /* Computed Parameter: TransferFcn2_C
   * Referenced by: '<S12>/Transfer Fcn2'
   */
  -10000.0,

  /* Computed Parameter: TransferFcn2_D
   * Referenced by: '<S12>/Transfer Fcn2'
   */
  100.0,

  /* Computed Parameter: TransferFcn_A_a
   * Referenced by: '<S9>/Transfer Fcn'
   */
  -100.0,

  /* Computed Parameter: TransferFcn_C_i
   * Referenced by: '<S9>/Transfer Fcn'
   */
  -100000.0,

  /* Computed Parameter: TransferFcn_D_j
   * Referenced by: '<S9>/Transfer Fcn'
   */
  1000.0,

  /* Computed Parameter: TransferFcn_A_j
   * Referenced by: '<S10>/Transfer Fcn'
   */
  -100.0,

  /* Computed Parameter: TransferFcn_C_o
   * Referenced by: '<S10>/Transfer Fcn'
   */
  -100000.0,

  /* Computed Parameter: TransferFcn_D_c
   * Referenced by: '<S10>/Transfer Fcn'
   */
  1000.0,

  /* Computed Parameter: TransferFcn_A_jp
   * Referenced by: '<S13>/Transfer Fcn'
   */
  -100.0,

  /* Computed Parameter: TransferFcn_C_m
   * Referenced by: '<S13>/Transfer Fcn'
   */
  -10000.0,

  /* Computed Parameter: TransferFcn_D_f
   * Referenced by: '<S13>/Transfer Fcn'
   */
  100.0,

  /* Computed Parameter: TransferFcn1_A
   * Referenced by: '<S13>/Transfer Fcn1'
   */
  -100.0,

  /* Computed Parameter: TransferFcn1_C
   * Referenced by: '<S13>/Transfer Fcn1'
   */
  -10000.0,

  /* Computed Parameter: TransferFcn1_D
   * Referenced by: '<S13>/Transfer Fcn1'
   */
  100.0,

  /* Computed Parameter: TransferFcn4_A_p
   * Referenced by: '<S13>/Transfer Fcn4'
   */
  -100.0,

  /* Computed Parameter: TransferFcn4_C_a
   * Referenced by: '<S13>/Transfer Fcn4'
   */
  -10000.0,

  /* Computed Parameter: TransferFcn4_D_g
   * Referenced by: '<S13>/Transfer Fcn4'
   */
  100.0,

  /* Computed Parameter: TransferFcn2_A_a
   * Referenced by: '<S13>/Transfer Fcn2'
   */
  -100.0,

  /* Computed Parameter: TransferFcn2_C_b
   * Referenced by: '<S13>/Transfer Fcn2'
   */
  -10000.0,

  /* Computed Parameter: TransferFcn2_D_p
   * Referenced by: '<S13>/Transfer Fcn2'
   */
  100.0,

  /* Computed Parameter: TransferFcn3_A
   * Referenced by: '<S13>/Transfer Fcn3'
   */
  -100.0,

  /* Computed Parameter: TransferFcn3_C
   * Referenced by: '<S13>/Transfer Fcn3'
   */
  -10000.0,

  /* Computed Parameter: TransferFcn3_D
   * Referenced by: '<S13>/Transfer Fcn3'
   */
  100.0,

  /* Expression: 0
   * Referenced by: '<S13>/Constant'
   */
  0.0,

  /* Expression: 0.2
   * Referenced by: '<S13>/Switch'
   */
  0.2,

  /* Expression: 5*9.81
   * Referenced by: '<S2>/Saturation'
   */
  49.050000000000004,

  /* Expression: -5*9.81
   * Referenced by: '<S2>/Saturation'
   */
  -49.050000000000004,

  /* Expression: 3
   * Referenced by: '<S6>/Step'
   */
  3.0,

  /* Expression: 0
   * Referenced by: '<S6>/Step'
   */
  0.0,

  /* Expression: -1
   * Referenced by: '<S6>/Step'
   */
  -1.0,

  /* Expression: 0
   * Referenced by: '<S6>/Step1'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S6>/Step1'
   */
  0.0,

  /* Expression: 1
   * Referenced by: '<S6>/Step1'
   */
  1.0,

  /* Expression: 300
   * Referenced by: '<S6>/Gain'
   */
  300.0,

  /* Expression: 1.5e-4
   * Referenced by: '<S6>/Constant1'
   */
  0.00015,

  /* Computed Parameter: TransferFcn_A_l
   * Referenced by: '<S22>/Transfer Fcn'
   */
  { -30.0, -200.0 },

  /* Computed Parameter: TransferFcn_C_c
   * Referenced by: '<S22>/Transfer Fcn'
   */
  { 30.0, 200.0 },

  /* Computed Parameter: TransferFcn1_A_o
   * Referenced by: '<S22>/Transfer Fcn1'
   */
  { -30.0, -200.0 },

  /* Computed Parameter: TransferFcn1_C_e
   * Referenced by: '<S22>/Transfer Fcn1'
   */
  { 30.0, 200.0 }
};
