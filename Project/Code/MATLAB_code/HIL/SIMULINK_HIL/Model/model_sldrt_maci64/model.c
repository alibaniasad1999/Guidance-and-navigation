/*
 * model.c
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
#include <string.h>
#include "rt_nonfinite.h"
#include "model_dt.h"

/* options for Simulink Desktop Real-Time board 0 */
static double SLDRTBoardOptions0[] = {
  115200.0,
  8.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  116.0,
  116.0,
  121.0,
  46.0,
  117.0,
  115.0,
  98.0,
  109.0,
  111.0,
  100.0,
  101.0,
  109.0,
  49.0,
  52.0,
  51.0,
  48.0,
  49.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
  0.0,
};

/* list of Simulink Desktop Real-Time timers */
const int SLDRTTimerCount = 1;
const double SLDRTTimers[2] = {
  0.01, 0.0,
};

/* list of Simulink Desktop Real-Time boards */
const int SLDRTBoardCount = 1;
SLDRTBOARD SLDRTBoards[1] = {
  { "Standard_Devices/Serial_Port", 1U, 256, SLDRTBoardOptions0 },
};

/* Block signals (default storage) */
B_model_T model_B;

/* Block states (default storage) */
DW_model_T model_DW;

/* Real-time model */
static RT_MODEL_model_T model_M_;
RT_MODEL_model_T *const model_M = &model_M_;
static void rate_scheduler(void);

/*
 *         This function updates active task flag for each subrate.
 *         The function is called at model base rate, hence the
 *         generated code self-manages all its subrates.
 */
static void rate_scheduler(void)
{
  /* Compute which subrates run during the next base time step.  Subrates
   * are an integer multiple of the base rate counter.  Therefore, the subtask
   * counter is reset when it reaches its limit (zero means run).
   */
  (model_M->Timing.TaskCounters.TID[1])++;
  if ((model_M->Timing.TaskCounters.TID[1]) > 9) {/* Sample time: [0.1s, 0.0s] */
    model_M->Timing.TaskCounters.TID[1] = 0;
  }

  model_M->Timing.sampleHits[1] = (model_M->Timing.TaskCounters.TID[1] == 0) ? 1
    : 0;
}

/* Model output function */
void model_output(void)
{
  if (model_M->Timing.TaskCounters.TID[1] == 0) {
    /* S-Function (sldrtpo): '<Root>/Packet Output' incorporates:
     *  Constant: '<Root>/Constant'
     */
    /* S-Function Block: <Root>/Packet Output */

    /* no code required */

    /* S-Function (sldrtpi): '<Root>/Packet Input' */
    /* S-Function Block: <Root>/Packet Input */
    {
      uint8_T indata[8U];
      int status = RTBIO_DriverIO(0, STREAMINPUT, IOREAD, 8U,
        &model_P.PacketInput_PacketID, (double*) indata, NULL);
      if (status & 0x1) {
        RTWin_ANYTYPEPTR indp;
        indp.p_uint8_T = indata;
        model_B.PacketInput = *indp.p_real_T++;
      }
    }
  }
}

/* Model update function */
void model_update(void)
{
  if (model_M->Timing.TaskCounters.TID[1] == 0) {
    /* Update for S-Function (sldrtpo): '<Root>/Packet Output' incorporates:
     *  Constant: '<Root>/Constant'
     */

    /* S-Function Block: <Root>/Packet Output */
    {
      uint8_T outdata[8U];
      RTWin_ANYTYPEPTR outdp;
      outdp.p_uint8_T = outdata;

      {
        *outdp.p_real_T++ = model_P.Constant_Value;
      }

      RTBIO_DriverIO(0, STREAMOUTPUT, IOWRITE, 8U,
                     &model_P.PacketOutput_PacketID, (double*) outdata, NULL);
    }
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
  if (!(++model_M->Timing.clockTick0)) {
    ++model_M->Timing.clockTickH0;
  }

  model_M->Timing.t[0] = model_M->Timing.clockTick0 * model_M->Timing.stepSize0
    + model_M->Timing.clockTickH0 * model_M->Timing.stepSize0 * 4294967296.0;
  if (model_M->Timing.TaskCounters.TID[1] == 0) {
    /* Update absolute timer for sample time: [0.1s, 0.0s] */
    /* The "clockTick1" counts the number of times the code of this task has
     * been executed. The absolute time is the multiplication of "clockTick1"
     * and "Timing.stepSize1". Size of "clockTick1" ensures timer will not
     * overflow during the application lifespan selected.
     * Timer of this task consists of two 32 bit unsigned integers.
     * The two integers represent the low bits Timing.clockTick1 and the high bits
     * Timing.clockTickH1. When the low bit overflows to 0, the high bits increment.
     */
    if (!(++model_M->Timing.clockTick1)) {
      ++model_M->Timing.clockTickH1;
    }

    model_M->Timing.t[1] = model_M->Timing.clockTick1 *
      model_M->Timing.stepSize1 + model_M->Timing.clockTickH1 *
      model_M->Timing.stepSize1 * 4294967296.0;
  }

  rate_scheduler();
}

/* Model initialize function */
void model_initialize(void)
{
  /* Start for S-Function (sldrtpo): '<Root>/Packet Output' incorporates:
   *  Constant: '<Root>/Constant'
   */

  /* S-Function Block: <Root>/Packet Output */
  /* no initial value should be set */
}

/* Model terminate function */
void model_terminate(void)
{
  /* Terminate for S-Function (sldrtpo): '<Root>/Packet Output' incorporates:
   *  Constant: '<Root>/Constant'
   */

  /* S-Function Block: <Root>/Packet Output */
  /* no initial value should be set */
}

/*========================================================================*
 * Start of Classic call interface                                        *
 *========================================================================*/
void MdlOutputs(int_T tid)
{
  model_output();
  UNUSED_PARAMETER(tid);
}

void MdlUpdate(int_T tid)
{
  model_update();
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
  model_initialize();
}

void MdlTerminate(void)
{
  model_terminate();
}

/* Registration function */
RT_MODEL_model_T *model(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize real-time model */
  (void) memset((void *)model_M, 0,
                sizeof(RT_MODEL_model_T));

  /* Initialize timing info */
  {
    int_T *mdlTsMap = model_M->Timing.sampleTimeTaskIDArray;
    mdlTsMap[0] = 0;
    mdlTsMap[1] = 1;

    /* polyspace +2 MISRA2012:D4.1 [Justified:Low] "model_M points to
       static memory which is guaranteed to be non-NULL" */
    model_M->Timing.sampleTimeTaskIDPtr = (&mdlTsMap[0]);
    model_M->Timing.sampleTimes = (&model_M->Timing.sampleTimesArray[0]);
    model_M->Timing.offsetTimes = (&model_M->Timing.offsetTimesArray[0]);

    /* task periods */
    model_M->Timing.sampleTimes[0] = (0.01);
    model_M->Timing.sampleTimes[1] = (0.1);

    /* task offsets */
    model_M->Timing.offsetTimes[0] = (0.0);
    model_M->Timing.offsetTimes[1] = (0.0);
  }

  rtmSetTPtr(model_M, &model_M->Timing.tArray[0]);

  {
    int_T *mdlSampleHits = model_M->Timing.sampleHitArray;
    mdlSampleHits[0] = 1;
    mdlSampleHits[1] = 1;
    model_M->Timing.sampleHits = (&mdlSampleHits[0]);
  }

  rtmSetTFinal(model_M, -1);
  model_M->Timing.stepSize0 = 0.01;
  model_M->Timing.stepSize1 = 0.1;

  /* External mode info */
  model_M->Sizes.checksums[0] = (3258999752U);
  model_M->Sizes.checksums[1] = (1357404177U);
  model_M->Sizes.checksums[2] = (3769183431U);
  model_M->Sizes.checksums[3] = (4252768710U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[1];
    model_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(model_M->extModeInfo,
      &model_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(model_M->extModeInfo, model_M->Sizes.checksums);
    rteiSetTPtr(model_M->extModeInfo, rtmGetTPtr(model_M));
  }

  model_M->solverInfoPtr = (&model_M->solverInfo);
  model_M->Timing.stepSize = (0.01);
  rtsiSetFixedStepSize(&model_M->solverInfo, 0.01);
  rtsiSetSolverMode(&model_M->solverInfo, SOLVER_MODE_SINGLETASKING);

  /* block I/O */
  model_M->blockIO = ((void *) &model_B);
  (void) memset(((void *) &model_B), 0,
                sizeof(B_model_T));

  /* parameters */
  model_M->defaultParam = ((real_T *)&model_P);

  /* states (dwork) */
  model_M->dwork = ((void *) &model_DW);
  (void) memset((void *)&model_DW, 0,
                sizeof(DW_model_T));

  /* data type transition information */
  {
    static DataTypeTransInfo dtInfo;
    (void) memset((char_T *) &dtInfo, 0,
                  sizeof(dtInfo));
    model_M->SpecialInfo.mappingInfo = (&dtInfo);
    dtInfo.numDataTypes = 23;
    dtInfo.dataTypeSizes = &rtDataTypeSizes[0];
    dtInfo.dataTypeNames = &rtDataTypeNames[0];

    /* Block I/O transition table */
    dtInfo.BTransTable = &rtBTransTable;

    /* Parameters transition table */
    dtInfo.PTransTable = &rtPTransTable;
  }

  /* Initialize Sizes */
  model_M->Sizes.numContStates = (0);  /* Number of continuous states */
  model_M->Sizes.numY = (0);           /* Number of model outputs */
  model_M->Sizes.numU = (0);           /* Number of model inputs */
  model_M->Sizes.sysDirFeedThru = (0); /* The model is not direct feedthrough */
  model_M->Sizes.numSampTimes = (2);   /* Number of sample times */
  model_M->Sizes.numBlocks = (4);      /* Number of blocks */
  model_M->Sizes.numBlockIO = (1);     /* Number of block outputs */
  model_M->Sizes.numBlockPrms = (7);   /* Sum of parameter "widths" */
  return model_M;
}

/*========================================================================*
 * End of Classic call interface                                          *
 *========================================================================*/
