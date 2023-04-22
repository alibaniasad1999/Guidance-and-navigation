/*
 * part_n.c
 *
 * Code generation for model "part_n".
 *
 * Model version              : 1.65
 * Simulink Coder version : 9.8 (R2022b) 13-May-2022
 * C source code generated on : Sun Apr 23 01:40:11 2023
 *
 * Target selection: sldrt.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Intel->x86-64 (Linux 64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "part_n.h"
#include "rtwtypes.h"
#include <math.h>
#include "part_n_private.h"
#include <emmintrin.h>
#include "rt_nonfinite.h"
#include "rt_defines.h"
#include <string.h>
#include "part_n_dt.h"

/* list of Simulink Desktop Real-Time timers */
const int SLDRTTimerCount = 1;
const double SLDRTTimers[2] = {
  0.002, 0.0,
};

/* Block signals (default storage) */
B_part_n_T part_n_B;

/* Continuous states */
X_part_n_T part_n_X;

/* Block states (default storage) */
DW_part_n_T part_n_DW;

/* Real-time model */
static RT_MODEL_part_n_T part_n_M_;
RT_MODEL_part_n_T *const part_n_M = &part_n_M_;

/* Forward declaration for local functions */
static real_T part_n_norm(const real_T x[3]);

/*
 * This function updates continuous states using the ODE4 fixed-step
 * solver algorithm
 */
static void rt_ertODEUpdateContinuousStates(RTWSolverInfo *si )
{
  time_T t = rtsiGetT(si);
  time_T tnew = rtsiGetSolverStopTime(si);
  time_T h = rtsiGetStepSize(si);
  real_T *x = rtsiGetContStates(si);
  ODE4_IntgData *id = (ODE4_IntgData *)rtsiGetSolverData(si);
  real_T *y = id->y;
  real_T *f0 = id->f[0];
  real_T *f1 = id->f[1];
  real_T *f2 = id->f[2];
  real_T *f3 = id->f[3];
  real_T temp;
  int_T i;
  int_T nXc = 30;
  rtsiSetSimTimeStep(si,MINOR_TIME_STEP);

  /* Save the state values at time t in y, we'll use x as ynew. */
  (void) memcpy(y, x,
                (uint_T)nXc*sizeof(real_T));

  /* Assumes that rtsiSetT and ModelOutputs are up-to-date */
  /* f0 = f(t,y) */
  rtsiSetdX(si, f0);
  part_n_derivatives();

  /* f1 = f(t + (h/2), y + (h/2)*f0) */
  temp = 0.5 * h;
  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (temp*f0[i]);
  }

  rtsiSetT(si, t + temp);
  rtsiSetdX(si, f1);
  part_n_output();
  part_n_derivatives();

  /* f2 = f(t + (h/2), y + (h/2)*f1) */
  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (temp*f1[i]);
  }

  rtsiSetdX(si, f2);
  part_n_output();
  part_n_derivatives();

  /* f3 = f(t + h, y + h*f2) */
  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (h*f2[i]);
  }

  rtsiSetT(si, tnew);
  rtsiSetdX(si, f3);
  part_n_output();
  part_n_derivatives();

  /* tnew = t + h
     ynew = y + (h/6)*(f0 + 2*f1 + 2*f2 + 2*f3) */
  temp = h / 6.0;
  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + temp*(f0[i] + 2.0*f1[i] + 2.0*f2[i] + f3[i]);
  }

  rtsiSetSimTimeStep(si,MAJOR_TIME_STEP);
}

/* Function for MATLAB Function: '<S2>/MATLAB Function' */
static real_T part_n_norm(const real_T x[3])
{
  real_T absxk;
  real_T scale;
  real_T t;
  real_T y;
  scale = 3.3121686421112381E-170;
  absxk = fabs(x[0]);
  if (absxk > 3.3121686421112381E-170) {
    y = 1.0;
    scale = absxk;
  } else {
    t = absxk / 3.3121686421112381E-170;
    y = t * t;
  }

  absxk = fabs(x[1]);
  if (absxk > scale) {
    t = scale / absxk;
    y = y * t * t + 1.0;
    scale = absxk;
  } else {
    t = absxk / scale;
    y += t * t;
  }

  absxk = fabs(x[2]);
  if (absxk > scale) {
    t = scale / absxk;
    y = y * t * t + 1.0;
    scale = absxk;
  } else {
    t = absxk / scale;
    y += t * t;
  }

  return scale * sqrt(y);
}

real_T rt_atan2d_snf(real_T u0, real_T u1)
{
  real_T y;
  if (rtIsNaN(u0) || rtIsNaN(u1)) {
    y = (rtNaN);
  } else if (rtIsInf(u0) && rtIsInf(u1)) {
    int32_T tmp;
    int32_T tmp_0;
    if (u0 > 0.0) {
      tmp = 1;
    } else {
      tmp = -1;
    }

    if (u1 > 0.0) {
      tmp_0 = 1;
    } else {
      tmp_0 = -1;
    }

    y = atan2(tmp, tmp_0);
  } else if (u1 == 0.0) {
    if (u0 > 0.0) {
      y = RT_PI / 2.0;
    } else if (u0 < 0.0) {
      y = -(RT_PI / 2.0);
    } else {
      y = 0.0;
    }
  } else {
    y = atan2(u0, u1);
  }

  return y;
}

/* Model output function */
void part_n_output(void)
{
  __m128d tmp;
  __m128d tmp_0;
  __m128d tmp_1;
  real_T rtb_dd_epsilon_0[9];
  real_T rtb_Product[3];
  real_T rtb_SquareRoot;
  real_T rtb_TransferFcn;
  real_T rtb_TransferFcn1;
  real_T rtb_TransferFcn_g;
  real_T rtb_d_R_m_p;
  real_T rtb_d_sigma;
  real_T rtb_epsilon_phi;
  real_T t_go;
  int32_T i;
  if (rtmIsMajorTimeStep(part_n_M)) {
    /* set solver stop time */
    if (!(part_n_M->Timing.clockTick0+1)) {
      rtsiSetSolverStopTime(&part_n_M->solverInfo,
                            ((part_n_M->Timing.clockTickH0 + 1) *
        part_n_M->Timing.stepSize0 * 4294967296.0));
    } else {
      rtsiSetSolverStopTime(&part_n_M->solverInfo, ((part_n_M->Timing.clockTick0
        + 1) * part_n_M->Timing.stepSize0 + part_n_M->Timing.clockTickH0 *
        part_n_M->Timing.stepSize0 * 4294967296.0));
    }
  }                                    /* end MajorTimeStep */

  /* Update absolute time of base rate at minor time step */
  if (rtmIsMinorTimeStep(part_n_M)) {
    part_n_M->Timing.t[0] = rtsiGetT(&part_n_M->solverInfo);
  }

  /* Sum: '<S3>/Add' incorporates:
   *  Integrator: '<S4>/Integrator1'
   *  Integrator: '<S5>/Integrator1'
   *  Sum: '<S11>/Add'
   */
  t_go = part_n_X.Integrator1_CSTATE[0] - part_n_X.Integrator1_CSTATE_k[0];

  /* Math: '<S3>/Square' */
  part_n_B.Square[0] = t_go * t_go;

  /* Sum: '<S3>/Add' incorporates:
   *  Integrator: '<S4>/Integrator1'
   *  Integrator: '<S5>/Integrator1'
   *  Sum: '<S11>/Add'
   */
  rtb_Product[0] = t_go;
  t_go = part_n_X.Integrator1_CSTATE[1] - part_n_X.Integrator1_CSTATE_k[1];

  /* Math: '<S3>/Square' */
  part_n_B.Square[1] = t_go * t_go;

  /* Sum: '<S3>/Add' incorporates:
   *  Integrator: '<S4>/Integrator1'
   *  Integrator: '<S5>/Integrator1'
   *  Sum: '<S11>/Add'
   */
  rtb_Product[1] = t_go;
  t_go = part_n_X.Integrator1_CSTATE[2] - part_n_X.Integrator1_CSTATE_k[2];

  /* Math: '<S3>/Square' incorporates:
   *  Product: '<S12>/Product'
   */
  t_go *= t_go;

  /* Math: '<S3>/Square' */
  part_n_B.Square[2] = t_go;
  if (rtmIsMajorTimeStep(part_n_M)) {
    /* Memory: '<S19>/Memory' */
    part_n_B.Memory = part_n_DW.Memory_PreviousInput;
  }

  /* Switch: '<S19>/Reset' incorporates:
   *  Constant: '<S3>/Constant'
   */
  if (part_n_P.Constant_Value != 0.0) {
    /* Switch: '<S19>/Reset' incorporates:
     *  Constant: '<S19>/Initial Condition'
     */
    part_n_B.Reset = part_n_P.MinMaxRunningResettable_vinit;
  } else {
    /* Switch: '<S19>/Reset' incorporates:
     *  Math: '<S3>/Square'
     *  MinMax: '<S16>/MinMax'
     *  Sqrt: '<S3>/Square Root'
     *  Sum: '<S3>/Sum of Elements'
     */
    part_n_B.Reset = fmin(sqrt((part_n_B.Square[0] + part_n_B.Square[1]) +
      part_n_B.Square[2]), part_n_B.Memory);
  }

  /* End of Switch: '<S19>/Reset' */
  if (rtmIsMajorTimeStep(part_n_M)) {
    /* Delay: '<S17>/Delay' */
    part_n_B.Delay = part_n_DW.Delay_DSTATE;

    /* Delay: '<S18>/Delay' */
    part_n_B.Delay_f = part_n_DW.Delay_DSTATE_f;
  }

  /* Switch: '<S17>/Switch' incorporates:
   *  Constant: '<S17>/Constant3'
   *  Constant: '<S17>/Constant4'
   *  Sum: '<S17>/Add1'
   */
  if (part_n_B.Delay - part_n_B.Square[0] > part_n_P.Switch_Threshold) {
    rtb_epsilon_phi = part_n_P.Constant3_Value;
  } else {
    rtb_epsilon_phi = part_n_P.Constant4_Value;
  }

  /* Switch: '<S18>/Switch' incorporates:
   *  Constant: '<S18>/Constant3'
   *  Constant: '<S18>/Constant4'
   *  Sum: '<S18>/Add1'
   */
  if (part_n_B.Delay_f - part_n_B.Square[2] > part_n_P.Switch_Threshold_i) {
    rtb_TransferFcn = part_n_P.Constant3_Value_i;
  } else {
    rtb_TransferFcn = part_n_P.Constant4_Value_c;
  }

  /* Logic: '<S3>/AND' incorporates:
   *  Switch: '<S17>/Switch'
   *  Switch: '<S18>/Switch'
   */
  part_n_B.AND = ((rtb_epsilon_phi != 0.0) && (rtb_TransferFcn != 0.0));
  if (rtmIsMajorTimeStep(part_n_M)) {
    /* Stop: '<Root>/Stop Simulation' */
    if (part_n_B.AND) {
      rtmSetStopRequested(part_n_M, 1);
    }

    /* End of Stop: '<Root>/Stop Simulation' */

    /* Delay: '<S11>/Delay1' */
    part_n_B.Delay1 = part_n_DW.Delay1_DSTATE;

    /* Delay: '<S11>/Delay' */
    part_n_B.Delay_k = part_n_DW.Delay_DSTATE_j;
  }

  /* Sqrt: '<S12>/Sqrt' incorporates:
   *  Product: '<S12>/Product'
   *  Sum: '<S11>/Add'
   */
  part_n_B.R_m = sqrt((rtb_Product[0] * rtb_Product[0] + rtb_Product[1] *
                       rtb_Product[1]) + t_go);

  /* MATLAB Function: '<S12>/MATLAB Function' incorporates:
   *  TransferFcn: '<S12>/Transfer Fcn2'
   *  TransferFcn: '<S12>/Transfer Fcn4'
   */
  t_go = -part_n_B.R_m / (part_n_P.TransferFcn4_C * part_n_X.TransferFcn4_CSTATE
    + part_n_P.TransferFcn4_D * part_n_B.R_m);
  rtb_epsilon_phi = (part_n_P.TransferFcn2_C * part_n_X.TransferFcn2_CSTATE +
                     part_n_P.TransferFcn2_D * part_n_B.Delay_k) * t_go;

  /* MATLAB Function: '<S2>/MATLAB Function' incorporates:
   *  Integrator: '<S4>/Integrator1'
   *  Integrator: '<S5>/Integrator1'
   *  MATLAB Function: '<S12>/MATLAB Function'
   *  MATLAB Function: '<S2>/MATLAB Function1'
   *  TransferFcn: '<S12>/Transfer Fcn'
   */
  rtb_d_sigma = part_n_norm(part_n_X.Integrator1_CSTATE);
  if (rtb_d_sigma == 0.0) {
    rtb_d_R_m_p = 0.0;
    rtb_SquareRoot = 0.0;
  } else {
    rtb_d_R_m_p = asin(part_n_X.Integrator1_CSTATE[2] / rtb_d_sigma);
    rtb_SquareRoot = rt_atan2d_snf(part_n_X.Integrator1_CSTATE[1],
      part_n_X.Integrator1_CSTATE[0]);
  }

  rtb_TransferFcn_g = part_n_norm(part_n_X.Integrator1_CSTATE_k);
  if (rtb_TransferFcn_g == 0.0) {
    rtb_TransferFcn1 = 0.0;
    rtb_TransferFcn = 0.0;
  } else {
    rtb_TransferFcn1 = asin(part_n_X.Integrator1_CSTATE_k[2] / rtb_TransferFcn_g);
    rtb_TransferFcn = rt_atan2d_snf(part_n_X.Integrator1_CSTATE_k[1],
      part_n_X.Integrator1_CSTATE_k[0]);
  }

  part_n_B.sigma_t = rtb_TransferFcn;
  part_n_B.epsilon_t = rtb_TransferFcn1;
  part_n_B.d_epsilon_n = ((rtb_TransferFcn1 - rtb_d_R_m_p) + rtb_epsilon_phi) *
    rtb_d_sigma;
  part_n_B.d_sigma_e = ((part_n_P.TransferFcn_C * part_n_X.TransferFcn_CSTATE +
    part_n_P.TransferFcn_D * part_n_B.Delay1) * t_go + (rtb_TransferFcn -
    rtb_SquareRoot)) * rtb_d_sigma * cos(rtb_TransferFcn1 + rtb_epsilon_phi);

  /* End of MATLAB Function: '<S2>/MATLAB Function' */

  /* MATLAB Function: '<S2>/MATLAB Function1' incorporates:
   *  Integrator: '<S5>/Integrator1'
   */
  if (rtb_TransferFcn_g == 0.0) {
    rtb_d_sigma = 0.0;
  } else {
    rtb_d_sigma = asin(part_n_X.Integrator1_CSTATE_k[2] / rtb_TransferFcn_g);
  }

  /* Sum: '<S9>/Sum' incorporates:
   *  Gain: '<S9>/Gain'
   *  TransferFcn: '<S9>/Transfer Fcn'
   */
  t_go = (part_n_P.TransferFcn_C_i * part_n_X.TransferFcn_CSTATE_a +
          part_n_P.TransferFcn_D_j * part_n_B.d_sigma_e) +
    part_n_P.k_sigma_lead_angle * part_n_B.d_sigma_e;

  /* TransferFcn: '<S13>/Transfer Fcn' */
  part_n_B.d_sigma = part_n_P.TransferFcn_C_m * part_n_X.TransferFcn_CSTATE_b;
  part_n_B.d_sigma += part_n_P.TransferFcn_D_f * part_n_B.sigma_t;

  /* Sqrt: '<S13>/Sqrt' incorporates:
   *  Integrator: '<S5>/Integrator1'
   *  Product: '<S13>/Product'
   */
  part_n_B.R_m_o = sqrt((part_n_X.Integrator1_CSTATE_k[0] *
    part_n_X.Integrator1_CSTATE_k[0] + part_n_X.Integrator1_CSTATE_k[1] *
    part_n_X.Integrator1_CSTATE_k[1]) + part_n_X.Integrator1_CSTATE_k[2] *
                        part_n_X.Integrator1_CSTATE_k[2]);

  /* TransferFcn: '<S13>/Transfer Fcn2' */
  part_n_B.d_epsilon = part_n_P.TransferFcn2_C_b *
    part_n_X.TransferFcn2_CSTATE_a;
  part_n_B.d_epsilon += part_n_P.TransferFcn2_D_p * part_n_B.epsilon_t;

  /* Sum: '<S2>/Sum' incorporates:
   *  Clock: '<S13>/Clock'
   *  Constant: '<S13>/Constant'
   *  MATLAB Function: '<S13>/MATLAB Function'
   *  Switch: '<S13>/Switch'
   *  TransferFcn: '<S13>/Transfer Fcn3'
   *  TransferFcn: '<S13>/Transfer Fcn4'
   */
  if (part_n_M->Timing.t[0] > part_n_P.Switch_Threshold_g) {
    rtb_epsilon_phi = ((part_n_P.TransferFcn4_C_a *
                        part_n_X.TransferFcn4_CSTATE_p +
                        part_n_P.TransferFcn4_D_g * part_n_B.R_m_o) * 2.0 *
                       part_n_B.d_epsilon + (part_n_P.TransferFcn3_C *
      part_n_X.TransferFcn3_CSTATE + part_n_P.TransferFcn3_D *
      part_n_B.d_epsilon) * part_n_B.R_m_o) + part_n_B.d_sigma *
      part_n_B.d_sigma * part_n_B.R_m_o * sin(part_n_B.epsilon_t) * cos
      (part_n_B.epsilon_t);
  } else {
    rtb_epsilon_phi = part_n_P.Constant_Value_p;
  }

  /* Saturate: '<S2>/Saturation' incorporates:
   *  Gain: '<S10>/Gain1'
   *  MATLAB Function: '<S2>/MATLAB Function1'
   *  Sum: '<S10>/Sum'
   *  Sum: '<S2>/Sum'
   *  Sum: '<S2>/Sum1'
   *  Switch: '<S13>/Switch'
   *  TransferFcn: '<S10>/Transfer Fcn'
   */
  rtb_epsilon_phi = ((part_n_P.TransferFcn_C_o * part_n_X.TransferFcn_CSTATE_l +
                      part_n_P.TransferFcn_D_c * part_n_B.d_epsilon_n) +
                     part_n_P.k_epsilon_lead_angle * part_n_B.d_epsilon_n) +
    (9.81 * cos(rtb_d_sigma) + rtb_epsilon_phi);
  if (t_go > part_n_P.Saturation_UpperSat) {
    /* Saturate: '<S2>/Saturation' */
    part_n_B.Saturation[0] = part_n_P.Saturation_UpperSat;
  } else if (t_go < part_n_P.Saturation_LowerSat) {
    /* Saturate: '<S2>/Saturation' */
    part_n_B.Saturation[0] = part_n_P.Saturation_LowerSat;
  } else {
    /* Saturate: '<S2>/Saturation' */
    part_n_B.Saturation[0] = t_go;
  }

  if (rtb_epsilon_phi > part_n_P.Saturation_UpperSat) {
    /* Saturate: '<S2>/Saturation' */
    part_n_B.Saturation[1] = part_n_P.Saturation_UpperSat;
  } else if (rtb_epsilon_phi < part_n_P.Saturation_LowerSat) {
    /* Saturate: '<S2>/Saturation' */
    part_n_B.Saturation[1] = part_n_P.Saturation_LowerSat;
  } else {
    /* Saturate: '<S2>/Saturation' */
    part_n_B.Saturation[1] = rtb_epsilon_phi;
  }

  /* End of Saturate: '<S2>/Saturation' */

  /* Integrator: '<S4>/Integrator' */
  part_n_B.d_state[0] = part_n_X.Integrator_CSTATE[0];
  part_n_B.d_state[1] = part_n_X.Integrator_CSTATE[1];
  part_n_B.d_state[2] = part_n_X.Integrator_CSTATE[2];

  /* MATLAB Function: '<S4>/Transformation Matrix' incorporates:
   *  Integrator: '<S4>/Integrator2'
   *  MATLAB Function: '<S4>/MATLAB Function'
   */
  rtb_d_sigma = cos(part_n_X.Integrator2_CSTATE[0]);
  rtb_d_R_m_p = sin(part_n_X.Integrator2_CSTATE[1]);
  rtb_SquareRoot = cos(part_n_X.Integrator2_CSTATE[1]);
  t_go = sin(part_n_X.Integrator2_CSTATE[0]);
  rtb_dd_epsilon_0[0] = rtb_d_sigma * rtb_SquareRoot;
  rtb_dd_epsilon_0[3] = rtb_d_sigma * rtb_d_R_m_p;
  rtb_dd_epsilon_0[6] = t_go;
  rtb_dd_epsilon_0[1] = -rtb_d_R_m_p;
  rtb_dd_epsilon_0[4] = rtb_SquareRoot;
  rtb_dd_epsilon_0[7] = 0.0;
  rtb_dd_epsilon_0[2] = -t_go * rtb_SquareRoot;
  rtb_dd_epsilon_0[5] = -sin(part_n_X.Integrator2_CSTATE[0]) * rtb_d_R_m_p;
  rtb_dd_epsilon_0[8] = rtb_d_sigma;
  for (i = 0; i <= 0; i += 2) {
    /* Product: '<S4>/Product' */
    tmp = _mm_loadu_pd(&rtb_dd_epsilon_0[i]);
    tmp_0 = _mm_loadu_pd(&rtb_dd_epsilon_0[i + 3]);
    tmp_1 = _mm_loadu_pd(&rtb_dd_epsilon_0[i + 6]);
    _mm_storeu_pd(&rtb_Product[i], _mm_add_pd(_mm_mul_pd(tmp_1, _mm_set1_pd
      (part_n_B.d_state[2])), _mm_add_pd(_mm_mul_pd(tmp_0, _mm_set1_pd
      (part_n_B.d_state[1])), _mm_add_pd(_mm_mul_pd(tmp, _mm_set1_pd
      (part_n_B.d_state[0])), _mm_set1_pd(0.0)))));
  }

  /* Product: '<S4>/Product' */
  for (i = 2; i < 3; i++) {
    rtb_Product[i] = (rtb_dd_epsilon_0[i + 3] * part_n_B.d_state[1] +
                      rtb_dd_epsilon_0[i] * part_n_B.d_state[0]) +
      rtb_dd_epsilon_0[i + 6] * part_n_B.d_state[2];
  }

  /* TransferFcn: '<S22>/Transfer Fcn' */
  rtb_TransferFcn_g = part_n_P.TransferFcn_C_c[0] *
    part_n_X.TransferFcn_CSTATE_c[0] + part_n_P.TransferFcn_C_c[1] *
    part_n_X.TransferFcn_CSTATE_c[1];

  /* TransferFcn: '<S22>/Transfer Fcn1' */
  rtb_TransferFcn1 = part_n_P.TransferFcn1_C_e[0] *
    part_n_X.TransferFcn1_CSTATE_n[0] + part_n_P.TransferFcn1_C_e[1] *
    part_n_X.TransferFcn1_CSTATE_n[1];

  /* Step: '<S6>/Step' incorporates:
   *  Step: '<S6>/Step1'
   */
  rtb_epsilon_phi = part_n_M->Timing.t[0];

  /* Sum: '<S6>/Add1' incorporates:
   *  Step: '<S6>/Step'
   *  Step: '<S6>/Step1'
   */
  if (rtb_epsilon_phi < part_n_P.Step_Time) {
    rtb_TransferFcn = part_n_P.Step_Y0;
  } else {
    rtb_TransferFcn = part_n_P.Step_YFinal;
  }

  if (rtb_epsilon_phi < part_n_P.Step1_Time) {
    rtb_epsilon_phi = part_n_P.Step1_Y0;
  } else {
    rtb_epsilon_phi = part_n_P.Step1_YFinal;
  }

  /* SignalConversion generated from: '<S20>/ SFunction ' incorporates:
   *  Constant: '<S6>/Constant1'
   *  Gain: '<S6>/Gain'
   *  MATLAB Function: '<S4>/MATLAB Function'
   *  Math: '<S6>/Square'
   *  Product: '<S6>/Product'
   *  Step: '<S6>/Step'
   *  Step: '<S6>/Step1'
   *  Sum: '<S6>/Add'
   *  Sum: '<S6>/Add1'
   */
  rtb_epsilon_phi = (rtb_TransferFcn + rtb_epsilon_phi) * part_n_P.Gain_Gain -
    rtb_Product[0] * rtb_Product[0] * part_n_P.Constant1_Value;

  /* MATLAB Function: '<S4>/MATLAB Function' incorporates:
   *  Constant: '<S1>/Constant7'
   *  Integrator: '<S4>/Integrator2'
   *  SignalConversion generated from: '<S20>/ SFunction '
   */
  rtb_TransferFcn = 9.81 * part_n_P.Constant7_Value;
  part_n_B.dd_state_o[0] = (rtb_epsilon_phi * rtb_d_sigma * rtb_SquareRoot -
    rtb_TransferFcn_g * rtb_d_R_m_p) - rtb_TransferFcn1 * t_go * rtb_SquareRoot;
  part_n_B.dd_state_o[1] = (rtb_epsilon_phi * cos(part_n_X.Integrator2_CSTATE[0])
    * rtb_d_R_m_p + rtb_TransferFcn_g * rtb_SquareRoot) - rtb_TransferFcn1 * sin
    (part_n_X.Integrator2_CSTATE[0]) * rtb_d_R_m_p;
  part_n_B.dd_state_o[2] = (rtb_epsilon_phi * t_go + rtb_TransferFcn1 *
    rtb_d_sigma) - rtb_TransferFcn;
  part_n_B.dot_attitude_j[0] = (rtb_TransferFcn1 - rtb_TransferFcn * rtb_d_sigma)
    / rtb_Product[0];
  part_n_B.dot_attitude_j[1] = rtb_TransferFcn_g / (rtb_Product[0] * rtb_d_sigma);

  /* Integrator: '<S5>/Integrator' */
  part_n_B.d_state_j[0] = part_n_X.Integrator_CSTATE_b[0];
  part_n_B.d_state_j[1] = part_n_X.Integrator_CSTATE_b[1];
  part_n_B.d_state_j[2] = part_n_X.Integrator_CSTATE_b[2];

  /* MATLAB Function: '<S5>/Transformation Matrix' incorporates:
   *  Integrator: '<S5>/Integrator2'
   *  MATLAB Function: '<S5>/MATLAB Function'
   */
  rtb_TransferFcn = cos(part_n_X.Integrator2_CSTATE_j[0]);
  rtb_TransferFcn1 = sin(part_n_X.Integrator2_CSTATE_j[1]);
  rtb_d_sigma = cos(part_n_X.Integrator2_CSTATE_j[1]);
  rtb_d_R_m_p = sin(part_n_X.Integrator2_CSTATE_j[0]);
  rtb_dd_epsilon_0[0] = rtb_TransferFcn * rtb_d_sigma;
  rtb_dd_epsilon_0[3] = rtb_TransferFcn * rtb_TransferFcn1;
  rtb_dd_epsilon_0[6] = rtb_d_R_m_p;
  rtb_dd_epsilon_0[1] = -rtb_TransferFcn1;
  rtb_dd_epsilon_0[4] = rtb_d_sigma;
  rtb_dd_epsilon_0[7] = 0.0;
  rtb_dd_epsilon_0[2] = -rtb_d_R_m_p * rtb_d_sigma;
  rtb_dd_epsilon_0[5] = -sin(part_n_X.Integrator2_CSTATE_j[0]) *
    rtb_TransferFcn1;
  rtb_dd_epsilon_0[8] = rtb_TransferFcn;
  for (i = 0; i <= 0; i += 2) {
    /* Product: '<S5>/Product' incorporates:
     *  Integrator: '<S5>/Integrator'
     */
    tmp = _mm_loadu_pd(&rtb_dd_epsilon_0[i]);
    tmp_0 = _mm_loadu_pd(&rtb_dd_epsilon_0[i + 3]);
    tmp_1 = _mm_loadu_pd(&rtb_dd_epsilon_0[i + 6]);
    _mm_storeu_pd(&rtb_Product[i], _mm_add_pd(_mm_mul_pd(tmp_1, _mm_set1_pd
      (part_n_B.d_state_j[2])), _mm_add_pd(_mm_mul_pd(tmp_0, _mm_set1_pd
      (part_n_B.d_state_j[1])), _mm_add_pd(_mm_mul_pd(tmp, _mm_set1_pd
      (part_n_B.d_state_j[0])), _mm_set1_pd(0.0)))));
  }

  /* Product: '<S5>/Product' incorporates:
   *  Integrator: '<S5>/Integrator'
   */
  for (i = 2; i < 3; i++) {
    rtb_Product[i] = (rtb_dd_epsilon_0[i + 3] * part_n_B.d_state_j[1] +
                      rtb_dd_epsilon_0[i] * part_n_B.d_state_j[0]) +
      rtb_dd_epsilon_0[i + 6] * part_n_B.d_state_j[2];
  }

  /* MATLAB Function: '<S5>/MATLAB Function' incorporates:
   *  Constant: '<S1>/Constant8'
   *  Constant: '<S1>/Constant9'
   *  Integrator: '<S5>/Integrator2'
   */
  part_n_B.dd_state[0] = (part_n_P.Constant8_Value[0] * rtb_TransferFcn *
    rtb_d_sigma - part_n_P.Constant8_Value[1] * rtb_TransferFcn1) -
    part_n_P.Constant8_Value[2] * rtb_d_R_m_p * rtb_d_sigma;
  part_n_B.dd_state[1] = (part_n_P.Constant8_Value[0] * cos
    (part_n_X.Integrator2_CSTATE_j[0]) * rtb_TransferFcn1 +
    part_n_P.Constant8_Value[1] * rtb_d_sigma) - part_n_P.Constant8_Value[2] *
    sin(part_n_X.Integrator2_CSTATE_j[0]) * rtb_TransferFcn1;
  part_n_B.dd_state[2] = (part_n_P.Constant8_Value[0] * rtb_d_R_m_p +
    part_n_P.Constant8_Value[2] * rtb_TransferFcn) - 9.81 *
    part_n_P.Constant9_Value;
  part_n_B.dot_attitude[0] = (part_n_P.Constant8_Value[2] - 9.81 *
    rtb_TransferFcn) / rtb_Product[0];
  part_n_B.dot_attitude[1] = part_n_P.Constant8_Value[1] / (rtb_Product[0] *
    rtb_TransferFcn);
}

/* Model update function */
void part_n_update(void)
{
  if (rtmIsMajorTimeStep(part_n_M)) {
    /* Update for Memory: '<S19>/Memory' */
    part_n_DW.Memory_PreviousInput = part_n_B.Reset;

    /* Update for Delay: '<S17>/Delay' */
    part_n_DW.Delay_DSTATE = part_n_B.Square[0];

    /* Update for Delay: '<S18>/Delay' */
    part_n_DW.Delay_DSTATE_f = part_n_B.Square[2];

    /* Update for Delay: '<S11>/Delay1' */
    part_n_DW.Delay1_DSTATE = part_n_B.sigma_t;

    /* Update for Delay: '<S11>/Delay' */
    part_n_DW.Delay_DSTATE_j = part_n_B.epsilon_t;
  }

  if (rtmIsMajorTimeStep(part_n_M)) {
    rt_ertODEUpdateContinuousStates(&part_n_M->solverInfo);
  }

  /* Update absolute time for base rate */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick0"
   * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
   * overflow during the application lifespan selected.
   * Timer of this task consists of two 32 bit unsigned integers.
   * The two integers represent the low bits Timing.clockTick0 and the high bits
   * Timing.clockTickH0. When the low bit overflows to 0, the high bits increment.
   */
  if (!(++part_n_M->Timing.clockTick0)) {
    ++part_n_M->Timing.clockTickH0;
  }

  part_n_M->Timing.t[0] = rtsiGetSolverStopTime(&part_n_M->solverInfo);

  {
    /* Update absolute timer for sample time: [0.002s, 0.0s] */
    /* The "clockTick1" counts the number of times the code of this task has
     * been executed. The absolute time is the multiplication of "clockTick1"
     * and "Timing.stepSize1". Size of "clockTick1" ensures timer will not
     * overflow during the application lifespan selected.
     * Timer of this task consists of two 32 bit unsigned integers.
     * The two integers represent the low bits Timing.clockTick1 and the high bits
     * Timing.clockTickH1. When the low bit overflows to 0, the high bits increment.
     */
    if (!(++part_n_M->Timing.clockTick1)) {
      ++part_n_M->Timing.clockTickH1;
    }

    part_n_M->Timing.t[1] = part_n_M->Timing.clockTick1 *
      part_n_M->Timing.stepSize1 + part_n_M->Timing.clockTickH1 *
      part_n_M->Timing.stepSize1 * 4294967296.0;
  }
}

/* Derivatives for root system: '<Root>' */
void part_n_derivatives(void)
{
  XDot_part_n_T *_rtXdot;
  _rtXdot = ((XDot_part_n_T *) part_n_M->derivs);

  /* Derivatives for TransferFcn: '<S12>/Transfer Fcn' */
  _rtXdot->TransferFcn_CSTATE = part_n_P.TransferFcn_A *
    part_n_X.TransferFcn_CSTATE;
  _rtXdot->TransferFcn_CSTATE += part_n_B.Delay1;

  /* Derivatives for TransferFcn: '<S12>/Transfer Fcn4' */
  _rtXdot->TransferFcn4_CSTATE = part_n_P.TransferFcn4_A *
    part_n_X.TransferFcn4_CSTATE;
  _rtXdot->TransferFcn4_CSTATE += part_n_B.R_m;

  /* Derivatives for TransferFcn: '<S12>/Transfer Fcn2' */
  _rtXdot->TransferFcn2_CSTATE = part_n_P.TransferFcn2_A *
    part_n_X.TransferFcn2_CSTATE;
  _rtXdot->TransferFcn2_CSTATE += part_n_B.Delay_k;

  /* Derivatives for TransferFcn: '<S9>/Transfer Fcn' */
  _rtXdot->TransferFcn_CSTATE_a = part_n_P.TransferFcn_A_a *
    part_n_X.TransferFcn_CSTATE_a;
  _rtXdot->TransferFcn_CSTATE_a += part_n_B.d_sigma_e;

  /* Derivatives for TransferFcn: '<S10>/Transfer Fcn' */
  _rtXdot->TransferFcn_CSTATE_l = part_n_P.TransferFcn_A_j *
    part_n_X.TransferFcn_CSTATE_l;
  _rtXdot->TransferFcn_CSTATE_l += part_n_B.d_epsilon_n;

  /* Derivatives for TransferFcn: '<S13>/Transfer Fcn' */
  _rtXdot->TransferFcn_CSTATE_b = part_n_P.TransferFcn_A_jp *
    part_n_X.TransferFcn_CSTATE_b;
  _rtXdot->TransferFcn_CSTATE_b += part_n_B.sigma_t;

  /* Derivatives for TransferFcn: '<S13>/Transfer Fcn1' */
  _rtXdot->TransferFcn1_CSTATE = part_n_P.TransferFcn1_A *
    part_n_X.TransferFcn1_CSTATE;
  _rtXdot->TransferFcn1_CSTATE += part_n_B.d_sigma;

  /* Derivatives for TransferFcn: '<S13>/Transfer Fcn4' */
  _rtXdot->TransferFcn4_CSTATE_p = part_n_P.TransferFcn4_A_p *
    part_n_X.TransferFcn4_CSTATE_p;
  _rtXdot->TransferFcn4_CSTATE_p += part_n_B.R_m_o;

  /* Derivatives for TransferFcn: '<S13>/Transfer Fcn2' */
  _rtXdot->TransferFcn2_CSTATE_a = part_n_P.TransferFcn2_A_a *
    part_n_X.TransferFcn2_CSTATE_a;
  _rtXdot->TransferFcn2_CSTATE_a += part_n_B.epsilon_t;

  /* Derivatives for TransferFcn: '<S13>/Transfer Fcn3' */
  _rtXdot->TransferFcn3_CSTATE = part_n_P.TransferFcn3_A *
    part_n_X.TransferFcn3_CSTATE;
  _rtXdot->TransferFcn3_CSTATE += part_n_B.d_epsilon;

  /* Derivatives for Integrator: '<S4>/Integrator1' */
  _rtXdot->Integrator1_CSTATE[0] = part_n_B.d_state[0];

  /* Derivatives for Integrator: '<S5>/Integrator1' incorporates:
   *  Integrator: '<S5>/Integrator'
   */
  _rtXdot->Integrator1_CSTATE_k[0] = part_n_B.d_state_j[0];

  /* Derivatives for Integrator: '<S4>/Integrator' */
  _rtXdot->Integrator_CSTATE[0] = part_n_B.dd_state_o[0];

  /* Derivatives for Integrator: '<S4>/Integrator1' */
  _rtXdot->Integrator1_CSTATE[1] = part_n_B.d_state[1];

  /* Derivatives for Integrator: '<S5>/Integrator1' incorporates:
   *  Integrator: '<S5>/Integrator'
   */
  _rtXdot->Integrator1_CSTATE_k[1] = part_n_B.d_state_j[1];

  /* Derivatives for Integrator: '<S4>/Integrator' */
  _rtXdot->Integrator_CSTATE[1] = part_n_B.dd_state_o[1];

  /* Derivatives for Integrator: '<S4>/Integrator1' */
  _rtXdot->Integrator1_CSTATE[2] = part_n_B.d_state[2];

  /* Derivatives for Integrator: '<S5>/Integrator1' incorporates:
   *  Integrator: '<S5>/Integrator'
   */
  _rtXdot->Integrator1_CSTATE_k[2] = part_n_B.d_state_j[2];

  /* Derivatives for Integrator: '<S4>/Integrator' */
  _rtXdot->Integrator_CSTATE[2] = part_n_B.dd_state_o[2];

  /* Derivatives for Integrator: '<S4>/Integrator2' */
  _rtXdot->Integrator2_CSTATE[0] = part_n_B.dot_attitude_j[0];

  /* Derivatives for TransferFcn: '<S22>/Transfer Fcn' */
  _rtXdot->TransferFcn_CSTATE_c[0] = part_n_P.TransferFcn_A_l[0] *
    part_n_X.TransferFcn_CSTATE_c[0];

  /* Derivatives for Integrator: '<S4>/Integrator2' */
  _rtXdot->Integrator2_CSTATE[1] = part_n_B.dot_attitude_j[1];

  /* Derivatives for TransferFcn: '<S22>/Transfer Fcn' */
  _rtXdot->TransferFcn_CSTATE_c[0] += part_n_P.TransferFcn_A_l[1] *
    part_n_X.TransferFcn_CSTATE_c[1];
  _rtXdot->TransferFcn_CSTATE_c[1] = part_n_X.TransferFcn_CSTATE_c[0];
  _rtXdot->TransferFcn_CSTATE_c[0] += part_n_B.Saturation[0];

  /* Derivatives for TransferFcn: '<S22>/Transfer Fcn1' */
  _rtXdot->TransferFcn1_CSTATE_n[0] = part_n_P.TransferFcn1_A_o[0] *
    part_n_X.TransferFcn1_CSTATE_n[0];
  _rtXdot->TransferFcn1_CSTATE_n[0] += part_n_P.TransferFcn1_A_o[1] *
    part_n_X.TransferFcn1_CSTATE_n[1];
  _rtXdot->TransferFcn1_CSTATE_n[1] = part_n_X.TransferFcn1_CSTATE_n[0];
  _rtXdot->TransferFcn1_CSTATE_n[0] += part_n_B.Saturation[1];

  /* Derivatives for Integrator: '<S5>/Integrator' */
  _rtXdot->Integrator_CSTATE_b[0] = part_n_B.dd_state[0];
  _rtXdot->Integrator_CSTATE_b[1] = part_n_B.dd_state[1];
  _rtXdot->Integrator_CSTATE_b[2] = part_n_B.dd_state[2];

  /* Derivatives for Integrator: '<S5>/Integrator2' */
  _rtXdot->Integrator2_CSTATE_j[0] = part_n_B.dot_attitude[0];
  _rtXdot->Integrator2_CSTATE_j[1] = part_n_B.dot_attitude[1];
}

/* Model initialize function */
void part_n_initialize(void)
{
  /* InitializeConditions for Memory: '<S19>/Memory' */
  part_n_DW.Memory_PreviousInput = part_n_P.MinMaxRunningResettable_vinit;

  /* InitializeConditions for Delay: '<S17>/Delay' */
  part_n_DW.Delay_DSTATE = part_n_P.Delay_InitialCondition;

  /* InitializeConditions for Delay: '<S18>/Delay' */
  part_n_DW.Delay_DSTATE_f = part_n_P.Delay_InitialCondition_k;

  /* InitializeConditions for Delay: '<S11>/Delay1' */
  part_n_DW.Delay1_DSTATE = part_n_P.Delay1_InitialCondition;

  /* InitializeConditions for TransferFcn: '<S12>/Transfer Fcn' */
  part_n_X.TransferFcn_CSTATE = 0.0;

  /* InitializeConditions for TransferFcn: '<S12>/Transfer Fcn4' */
  part_n_X.TransferFcn4_CSTATE = 0.0;

  /* InitializeConditions for Delay: '<S11>/Delay' */
  part_n_DW.Delay_DSTATE_j = part_n_P.Delay_InitialCondition_i;

  /* InitializeConditions for TransferFcn: '<S12>/Transfer Fcn2' */
  part_n_X.TransferFcn2_CSTATE = 0.0;

  /* InitializeConditions for TransferFcn: '<S9>/Transfer Fcn' */
  part_n_X.TransferFcn_CSTATE_a = 0.0;

  /* InitializeConditions for TransferFcn: '<S10>/Transfer Fcn' */
  part_n_X.TransferFcn_CSTATE_l = 0.0;

  /* InitializeConditions for TransferFcn: '<S13>/Transfer Fcn' */
  part_n_X.TransferFcn_CSTATE_b = 0.0;

  /* InitializeConditions for TransferFcn: '<S13>/Transfer Fcn1' */
  part_n_X.TransferFcn1_CSTATE = 0.0;

  /* InitializeConditions for TransferFcn: '<S13>/Transfer Fcn4' */
  part_n_X.TransferFcn4_CSTATE_p = 0.0;

  /* InitializeConditions for TransferFcn: '<S13>/Transfer Fcn2' */
  part_n_X.TransferFcn2_CSTATE_a = 0.0;

  /* InitializeConditions for TransferFcn: '<S13>/Transfer Fcn3' */
  part_n_X.TransferFcn3_CSTATE = 0.0;

  /* InitializeConditions for Integrator: '<S4>/Integrator1' */
  part_n_X.Integrator1_CSTATE[0] = part_n_P.state_m0[0];

  /* InitializeConditions for Integrator: '<S5>/Integrator1' */
  part_n_X.Integrator1_CSTATE_k[0] = part_n_P.state_t0[0];

  /* InitializeConditions for Integrator: '<S4>/Integrator' */
  part_n_X.Integrator_CSTATE[0] = part_n_P.d_state_m[0];

  /* InitializeConditions for Integrator: '<S4>/Integrator1' */
  part_n_X.Integrator1_CSTATE[1] = part_n_P.state_m0[1];

  /* InitializeConditions for Integrator: '<S5>/Integrator1' */
  part_n_X.Integrator1_CSTATE_k[1] = part_n_P.state_t0[1];

  /* InitializeConditions for Integrator: '<S4>/Integrator' */
  part_n_X.Integrator_CSTATE[1] = part_n_P.d_state_m[1];

  /* InitializeConditions for Integrator: '<S4>/Integrator1' */
  part_n_X.Integrator1_CSTATE[2] = part_n_P.state_m0[2];

  /* InitializeConditions for Integrator: '<S5>/Integrator1' */
  part_n_X.Integrator1_CSTATE_k[2] = part_n_P.state_t0[2];

  /* InitializeConditions for Integrator: '<S4>/Integrator' */
  part_n_X.Integrator_CSTATE[2] = part_n_P.d_state_m[2];

  /* InitializeConditions for Integrator: '<S4>/Integrator2' */
  part_n_X.Integrator2_CSTATE[0] = part_n_P.attitude_m0[0];

  /* InitializeConditions for TransferFcn: '<S22>/Transfer Fcn' */
  part_n_X.TransferFcn_CSTATE_c[0] = 0.0;

  /* InitializeConditions for TransferFcn: '<S22>/Transfer Fcn1' */
  part_n_X.TransferFcn1_CSTATE_n[0] = 0.0;

  /* InitializeConditions for Integrator: '<S4>/Integrator2' */
  part_n_X.Integrator2_CSTATE[1] = part_n_P.attitude_m0[1];

  /* InitializeConditions for TransferFcn: '<S22>/Transfer Fcn' */
  part_n_X.TransferFcn_CSTATE_c[1] = 0.0;

  /* InitializeConditions for TransferFcn: '<S22>/Transfer Fcn1' */
  part_n_X.TransferFcn1_CSTATE_n[1] = 0.0;

  /* InitializeConditions for Integrator: '<S5>/Integrator' */
  part_n_X.Integrator_CSTATE_b[0] = part_n_P.d_state_t[0];
  part_n_X.Integrator_CSTATE_b[1] = part_n_P.d_state_t[1];
  part_n_X.Integrator_CSTATE_b[2] = part_n_P.d_state_t[2];

  /* InitializeConditions for Integrator: '<S5>/Integrator2' */
  part_n_X.Integrator2_CSTATE_j[0] = part_n_P.attitude_t0[0];
  part_n_X.Integrator2_CSTATE_j[1] = part_n_P.attitude_t0[1];
}

/* Model terminate function */
void part_n_terminate(void)
{
  /* (no terminate code required) */
}

/*========================================================================*
 * Start of Classic call interface                                        *
 *========================================================================*/

/* Solver interface called by GRT_Main */
#ifndef USE_GENERATED_SOLVER

void rt_ODECreateIntegrationData(RTWSolverInfo *si)
{
  UNUSED_PARAMETER(si);
  return;
}                                      /* do nothing */

void rt_ODEDestroyIntegrationData(RTWSolverInfo *si)
{
  UNUSED_PARAMETER(si);
  return;
}                                      /* do nothing */

void rt_ODEUpdateContinuousStates(RTWSolverInfo *si)
{
  UNUSED_PARAMETER(si);
  return;
}                                      /* do nothing */

#endif

void MdlOutputs(int_T tid)
{
  part_n_output();
  UNUSED_PARAMETER(tid);
}

void MdlUpdate(int_T tid)
{
  part_n_update();
  UNUSED_PARAMETER(tid);
}

void MdlInitializeSizes(void)
{
}

void MdlInitializeSampleTimes(void)
{
}

void MdlInitialize(void)
{
}

void MdlStart(void)
{
  part_n_initialize();
}

void MdlTerminate(void)
{
  part_n_terminate();
}

/* Registration function */
RT_MODEL_part_n_T *part_n(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* non-finite (run-time) assignments */
  part_n_P.MinMaxRunningResettable_vinit = rtInf;
  part_n_P.Delay_InitialCondition = rtInf;
  part_n_P.Delay_InitialCondition_k = rtInf;

  /* initialize real-time model */
  (void) memset((void *)part_n_M, 0,
                sizeof(RT_MODEL_part_n_T));

  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr(&part_n_M->solverInfo, &part_n_M->Timing.simTimeStep);
    rtsiSetTPtr(&part_n_M->solverInfo, &rtmGetTPtr(part_n_M));
    rtsiSetStepSizePtr(&part_n_M->solverInfo, &part_n_M->Timing.stepSize0);
    rtsiSetdXPtr(&part_n_M->solverInfo, &part_n_M->derivs);
    rtsiSetContStatesPtr(&part_n_M->solverInfo, (real_T **)
                         &part_n_M->contStates);
    rtsiSetNumContStatesPtr(&part_n_M->solverInfo,
      &part_n_M->Sizes.numContStates);
    rtsiSetNumPeriodicContStatesPtr(&part_n_M->solverInfo,
      &part_n_M->Sizes.numPeriodicContStates);
    rtsiSetPeriodicContStateIndicesPtr(&part_n_M->solverInfo,
      &part_n_M->periodicContStateIndices);
    rtsiSetPeriodicContStateRangesPtr(&part_n_M->solverInfo,
      &part_n_M->periodicContStateRanges);
    rtsiSetErrorStatusPtr(&part_n_M->solverInfo, (&rtmGetErrorStatus(part_n_M)));
    rtsiSetRTModelPtr(&part_n_M->solverInfo, part_n_M);
  }

  rtsiSetSimTimeStep(&part_n_M->solverInfo, MAJOR_TIME_STEP);
  part_n_M->intgData.y = part_n_M->odeY;
  part_n_M->intgData.f[0] = part_n_M->odeF[0];
  part_n_M->intgData.f[1] = part_n_M->odeF[1];
  part_n_M->intgData.f[2] = part_n_M->odeF[2];
  part_n_M->intgData.f[3] = part_n_M->odeF[3];
  part_n_M->contStates = ((real_T *) &part_n_X);
  rtsiSetSolverData(&part_n_M->solverInfo, (void *)&part_n_M->intgData);
  rtsiSetIsMinorTimeStepWithModeChange(&part_n_M->solverInfo, false);
  rtsiSetSolverName(&part_n_M->solverInfo,"ode4");

  /* Initialize timing info */
  {
    int_T *mdlTsMap = part_n_M->Timing.sampleTimeTaskIDArray;
    mdlTsMap[0] = 0;
    mdlTsMap[1] = 1;

    /* polyspace +2 MISRA2012:D4.1 [Justified:Low] "part_n_M points to
       static memory which is guaranteed to be non-NULL" */
    part_n_M->Timing.sampleTimeTaskIDPtr = (&mdlTsMap[0]);
    part_n_M->Timing.sampleTimes = (&part_n_M->Timing.sampleTimesArray[0]);
    part_n_M->Timing.offsetTimes = (&part_n_M->Timing.offsetTimesArray[0]);

    /* task periods */
    part_n_M->Timing.sampleTimes[0] = (0.0);
    part_n_M->Timing.sampleTimes[1] = (0.002);

    /* task offsets */
    part_n_M->Timing.offsetTimes[0] = (0.0);
    part_n_M->Timing.offsetTimes[1] = (0.0);
  }

  rtmSetTPtr(part_n_M, &part_n_M->Timing.tArray[0]);

  {
    int_T *mdlSampleHits = part_n_M->Timing.sampleHitArray;
    mdlSampleHits[0] = 1;
    mdlSampleHits[1] = 1;
    part_n_M->Timing.sampleHits = (&mdlSampleHits[0]);
  }

  rtmSetTFinal(part_n_M, -1);
  part_n_M->Timing.stepSize0 = 0.002;
  part_n_M->Timing.stepSize1 = 0.002;

  /* External mode info */
  part_n_M->Sizes.checksums[0] = (1424759244U);
  part_n_M->Sizes.checksums[1] = (3191622454U);
  part_n_M->Sizes.checksums[2] = (1751504332U);
  part_n_M->Sizes.checksums[3] = (572030179U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[10];
    part_n_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    systemRan[1] = &rtAlwaysEnabled;
    systemRan[2] = &rtAlwaysEnabled;
    systemRan[3] = &rtAlwaysEnabled;
    systemRan[4] = &rtAlwaysEnabled;
    systemRan[5] = &rtAlwaysEnabled;
    systemRan[6] = &rtAlwaysEnabled;
    systemRan[7] = &rtAlwaysEnabled;
    systemRan[8] = &rtAlwaysEnabled;
    systemRan[9] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(part_n_M->extModeInfo,
      &part_n_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(part_n_M->extModeInfo, part_n_M->Sizes.checksums);
    rteiSetTPtr(part_n_M->extModeInfo, rtmGetTPtr(part_n_M));
  }

  part_n_M->solverInfoPtr = (&part_n_M->solverInfo);
  part_n_M->Timing.stepSize = (0.002);
  rtsiSetFixedStepSize(&part_n_M->solverInfo, 0.002);
  rtsiSetSolverMode(&part_n_M->solverInfo, SOLVER_MODE_SINGLETASKING);

  /* block I/O */
  part_n_M->blockIO = ((void *) &part_n_B);
  (void) memset(((void *) &part_n_B), 0,
                sizeof(B_part_n_T));

  /* parameters */
  part_n_M->defaultParam = ((real_T *)&part_n_P);

  /* states (continuous) */
  {
    real_T *x = (real_T *) &part_n_X;
    part_n_M->contStates = (x);
    (void) memset((void *)&part_n_X, 0,
                  sizeof(X_part_n_T));
  }

  /* states (dwork) */
  part_n_M->dwork = ((void *) &part_n_DW);
  (void) memset((void *)&part_n_DW, 0,
                sizeof(DW_part_n_T));

  /* data type transition information */
  {
    static DataTypeTransInfo dtInfo;
    (void) memset((char_T *) &dtInfo, 0,
                  sizeof(dtInfo));
    part_n_M->SpecialInfo.mappingInfo = (&dtInfo);
    dtInfo.numDataTypes = 23;
    dtInfo.dataTypeSizes = &rtDataTypeSizes[0];
    dtInfo.dataTypeNames = &rtDataTypeNames[0];

    /* Block I/O transition table */
    dtInfo.BTransTable = &rtBTransTable;

    /* Parameters transition table */
    dtInfo.PTransTable = &rtPTransTable;
  }

  /* Initialize Sizes */
  part_n_M->Sizes.numContStates = (30);/* Number of continuous states */
  part_n_M->Sizes.numPeriodicContStates = (0);
                                      /* Number of periodic continuous states */
  part_n_M->Sizes.numY = (0);          /* Number of model outputs */
  part_n_M->Sizes.numU = (0);          /* Number of model inputs */
  part_n_M->Sizes.sysDirFeedThru = (0);/* The model is not direct feedthrough */
  part_n_M->Sizes.numSampTimes = (2);  /* Number of sample times */
  part_n_M->Sizes.numBlocks = (114);   /* Number of blocks */
  part_n_M->Sizes.numBlockIO = (23);   /* Number of block outputs */
  part_n_M->Sizes.numBlockPrms = (85); /* Sum of parameter "widths" */
  return part_n_M;
}

/*========================================================================*
 * End of Classic call interface                                          *
 *========================================================================*/
