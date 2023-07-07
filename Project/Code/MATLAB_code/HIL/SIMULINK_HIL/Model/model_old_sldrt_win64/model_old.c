/*
 * model_old.c
 *
 * Code generation for model "model_old".
 *
 * Model version              : 1.2
 * Simulink Coder version : 9.7 (R2022a) 13-Nov-2021
 * C source code generated on : Sat Jul  8 03:13:49 2023
 *
 * Target selection: sldrt.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Intel->x86-64 (Linux 64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "model_old.h"
#include "rtwtypes.h"
#include "rt_nonfinite.h"
#include "model_old_dt.h"

/* options for Simulink Desktop Real-Time board 0 */
static double SLDRTBoardOptions0[] = {
  115200.0,
  8.0,
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
  0.005, 0.0,
};

/* list of Simulink Desktop Real-Time boards */
const int SLDRTBoardCount = 1;
SLDRTBOARD SLDRTBoards[1] = {
  { "Standard_Devices/Serial_Port", 4U, 8, SLDRTBoardOptions0 },
};

/* Block signals (default storage) */
B_model_old_T model_old_B;

/* Block states (default storage) */
DW_model_old_T model_old_DW;

/* Real-time model */
static RT_MODEL_model_old_T model_old_M_;
RT_MODEL_model_old_T *const model_old_M = &model_old_M_;

/* Model output function */
void model_old_output(void)
{
  int32_T i;
  uint32_T tmp;
  for (i = 0; i < 6; i++) {
    real_T rtb_data;

    /* MATLAB Function: '<Root>/MATLAB Function' incorporates:
     *  Constant: '<Root>/Constant1'
     */
    model_old_DW.iteration++;
    rtb_data = model_old_P.Constant1_Value[(int32_T)model_old_DW.iteration - 1];
    if (model_old_DW.iteration >= 1000.0) {
      model_old_DW.iteration = 0.0;
    }

    /* End of MATLAB Function: '<Root>/MATLAB Function' */

    /* DataTypeConversion: '<Root>/Data Type Conversion1' */
    model_old_B.DataTypeConversion1[i] = (real32_T)rtb_data;
  }

  /* S-Function (sldrtpo): '<Root>/Packet Output' incorporates:
   *  Constant: '<Root>/Constant4'
   *  Constant: '<Root>/Constant5'
   */
  /* S-Function Block: <Root>/Packet Output */

  /* no code required */

  /* S-Function (any2byte_svd): '<Root>/Byte Pack' */

  /* Pack: <Root>/Byte Pack */
  {
    uint32_T MW_outputPortOffset = 0;
    uint32_T MW_inputPortWidth = 0;
    uint32_T MW_remainder1 = 0;

    /* Packed output data type - uint8_T */
    /* Packing the values of Input 1 */
    /* Input data type - real32_T, size - 6 */
    {
      MW_inputPortWidth = 6 * sizeof(real32_T);
      memcpy((uint8_T*)((uint8_T*)&model_old_B.BytePack[0] + MW_outputPortOffset),
             (uint8_T*)&model_old_B.DataTypeConversion1[0], MW_inputPortWidth);
    }
  }

  /* Sum: '<Root>/Sum of Elements' */
  tmp = 0U;
  for (i = 0; i < 24; i++) {
    /* Sum: '<Root>/Sum of Elements' incorporates:
     *  DataTypeConversion: '<Root>/Data Type Conversion2'
     */
    tmp += model_old_B.BytePack[i];
  }

  /* Sum: '<Root>/Sum of Elements' */
  model_old_B.SumofElements = tmp;

  /* S-Function (any2byte_svd): '<Root>/Byte Pack1' */

  /* Pack: <Root>/Byte Pack1 */
  {
    uint32_T MW_outputPortOffset = 0;
    uint32_T MW_inputPortWidth = 0;
    uint32_T MW_remainder1 = 0;

    /* Packed output data type - uint8_T */
    /* Packing the values of Input 1 */
    /* Input data type - uint32_T, size - 1 */
    {
      MW_inputPortWidth = 1 * sizeof(uint32_T);
      memcpy((uint8_T*)((uint8_T*)&model_old_B.BytePack1[0] +
                        MW_outputPortOffset), (uint8_T*)
             &model_old_B.SumofElements, MW_inputPortWidth);
    }
  }

  /* S-Function (sldrtpi): '<Root>/Packet Input' */
  /* S-Function Block: <Root>/Packet Input */
  {
    uint8_T indata[4U];
    int status = RTBIO_DriverIO(0, STREAMINPUT, IOREAD, 4U,
      &model_old_P.PacketInput_PacketID, (double*) indata, NULL);
    if (status & 0x1) {
      RTWin_ANYTYPEPTR indp;
      indp.p_uint8_T = indata;
      model_old_B.PacketInput[0] = *indp.p_uint8_T++;
      model_old_B.PacketInput[1] = *indp.p_uint8_T++;
      model_old_B.PacketInput[2] = *indp.p_uint8_T++;
      model_old_B.PacketInput[3] = *indp.p_uint8_T++;
    }
  }

  /* S-Function (byte2any_svd): '<Root>/Byte Unpack' */

  /* Unpack: <Root>/Byte Unpack */
  {
    uint32_T MW_inputPortOffset = 0;
    uint32_T MW_outputPortWidth = 0;
    uint32_T MW_remainder2 = 0;

    /* Packed input data type - uint8_T */
    /* Unpacking the values to output 1 */
    /* Output data type - real32_T, size - 1 */
    {
      MW_outputPortWidth = 1 * sizeof(real32_T);
      memcpy((uint8_T*)&model_old_B.ByteUnpack, (uint8_T*)
             &model_old_B.PacketInput[0] + MW_inputPortOffset,
             MW_outputPortWidth);
    }
  }
}

/* Model update function */
void model_old_update(void)
{
  /* Update for S-Function (sldrtpo): '<Root>/Packet Output' incorporates:
   *  Constant: '<Root>/Constant4'
   *  Constant: '<Root>/Constant5'
   */

  /* S-Function Block: <Root>/Packet Output */
  {
    uint8_T outdata[32U];
    RTWin_ANYTYPEPTR outdp;
    outdp.p_uint8_T = outdata;

    {
      uint8_T pktout = model_old_P.Constant4_Value;
      *outdp.p_uint8_T++ = pktout;
    }

    {
      uint8_T pktout = model_old_P.Constant4_Value;
      *outdp.p_uint8_T++ = pktout;
    }

    {
      int_T i1;
      const uint8_T *u0 = &model_old_B.BytePack[0];
      for (i1=0; i1 < 24; i1++) {
        {
          uint8_T pktout = u0[i1];
          *outdp.p_uint8_T++ = pktout;
        }
      }

      {
        uint8_T pktout = model_old_B.BytePack1[0];
        *outdp.p_uint8_T++ = pktout;
      }

      {
        uint8_T pktout = model_old_B.BytePack1[1];
        *outdp.p_uint8_T++ = pktout;
      }

      {
        uint8_T pktout = model_old_B.BytePack1[2];
        *outdp.p_uint8_T++ = pktout;
      }

      {
        uint8_T pktout = model_old_B.BytePack1[3];
        *outdp.p_uint8_T++ = pktout;
      }

      {
        uint8_T pktout = model_old_P.Constant5_Value;
        *outdp.p_uint8_T++ = pktout;
      }

      {
        uint8_T pktout = model_old_P.Constant5_Value;
        *outdp.p_uint8_T++ = pktout;
      }
    }

    RTBIO_DriverIO(0, STREAMOUTPUT, IOWRITE, 32U,
                   &model_old_P.PacketOutput_PacketID, (double*) outdata, NULL);
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
  if (!(++model_old_M->Timing.clockTick0)) {
    ++model_old_M->Timing.clockTickH0;
  }

  model_old_M->Timing.t[0] = model_old_M->Timing.clockTick0 *
    model_old_M->Timing.stepSize0 + model_old_M->Timing.clockTickH0 *
    model_old_M->Timing.stepSize0 * 4294967296.0;
}

/* Model initialize function */
void model_old_initialize(void)
{
  /* Start for S-Function (sldrtpo): '<Root>/Packet Output' incorporates:
   *  Constant: '<Root>/Constant4'
   *  Constant: '<Root>/Constant5'
   */

  /* S-Function Block: <Root>/Packet Output */
  /* no initial value should be set */

  /* SystemInitialize for MATLAB Function: '<Root>/MATLAB Function' */
  model_old_DW.iteration = 0.0;
}

/* Model terminate function */
void model_old_terminate(void)
{
  /* Terminate for S-Function (sldrtpo): '<Root>/Packet Output' incorporates:
   *  Constant: '<Root>/Constant4'
   *  Constant: '<Root>/Constant5'
   */

  /* S-Function Block: <Root>/Packet Output */
  /* no initial value should be set */
}

/*========================================================================*
 * Start of Classic call interface                                        *
 *========================================================================*/
void MdlOutputs(int_T tid)
{
  model_old_output();
  UNUSED_PARAMETER(tid);
}

void MdlUpdate(int_T tid)
{
  model_old_update();
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
  model_old_initialize();
}

void MdlTerminate(void)
{
  model_old_terminate();
}

/* Registration function */
RT_MODEL_model_old_T *model_old(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize real-time model */
  (void) memset((void *)model_old_M, 0,
                sizeof(RT_MODEL_model_old_T));

  /* Initialize timing info */
  {
    int_T *mdlTsMap = model_old_M->Timing.sampleTimeTaskIDArray;
    mdlTsMap[0] = 0;

    /* polyspace +2 MISRA2012:D4.1 [Justified:Low] "model_old_M points to
       static memory which is guaranteed to be non-NULL" */
    model_old_M->Timing.sampleTimeTaskIDPtr = (&mdlTsMap[0]);
    model_old_M->Timing.sampleTimes = (&model_old_M->Timing.sampleTimesArray[0]);
    model_old_M->Timing.offsetTimes = (&model_old_M->Timing.offsetTimesArray[0]);

    /* task periods */
    model_old_M->Timing.sampleTimes[0] = (0.005);

    /* task offsets */
    model_old_M->Timing.offsetTimes[0] = (0.0);
  }

  rtmSetTPtr(model_old_M, &model_old_M->Timing.tArray[0]);

  {
    int_T *mdlSampleHits = model_old_M->Timing.sampleHitArray;
    mdlSampleHits[0] = 1;
    model_old_M->Timing.sampleHits = (&mdlSampleHits[0]);
  }

  rtmSetTFinal(model_old_M, -1);
  model_old_M->Timing.stepSize0 = 0.005;

  /* External mode info */
  model_old_M->Sizes.checksums[0] = (3092865588U);
  model_old_M->Sizes.checksums[1] = (622340237U);
  model_old_M->Sizes.checksums[2] = (654314713U);
  model_old_M->Sizes.checksums[3] = (7298682U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[2];
    model_old_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    systemRan[1] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(model_old_M->extModeInfo,
      &model_old_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(model_old_M->extModeInfo, model_old_M->Sizes.checksums);
    rteiSetTPtr(model_old_M->extModeInfo, rtmGetTPtr(model_old_M));
  }

  model_old_M->solverInfoPtr = (&model_old_M->solverInfo);
  model_old_M->Timing.stepSize = (0.005);
  rtsiSetFixedStepSize(&model_old_M->solverInfo, 0.005);
  rtsiSetSolverMode(&model_old_M->solverInfo, SOLVER_MODE_SINGLETASKING);

  /* block I/O */
  model_old_M->blockIO = ((void *) &model_old_B);
  (void) memset(((void *) &model_old_B), 0,
                sizeof(B_model_old_T));

  /* parameters */
  model_old_M->defaultParam = ((real_T *)&model_old_P);

  /* states (dwork) */
  model_old_M->dwork = ((void *) &model_old_DW);
  (void) memset((void *)&model_old_DW, 0,
                sizeof(DW_model_old_T));

  /* data type transition information */
  {
    static DataTypeTransInfo dtInfo;
    (void) memset((char_T *) &dtInfo, 0,
                  sizeof(dtInfo));
    model_old_M->SpecialInfo.mappingInfo = (&dtInfo);
    dtInfo.numDataTypes = 22;
    dtInfo.dataTypeSizes = &rtDataTypeSizes[0];
    dtInfo.dataTypeNames = &rtDataTypeNames[0];

    /* Block I/O transition table */
    dtInfo.BTransTable = &rtBTransTable;

    /* Parameters transition table */
    dtInfo.PTransTable = &rtPTransTable;
  }

  /* Initialize Sizes */
  model_old_M->Sizes.numContStates = (0);/* Number of continuous states */
  model_old_M->Sizes.numY = (0);       /* Number of model outputs */
  model_old_M->Sizes.numU = (0);       /* Number of model inputs */
  model_old_M->Sizes.sysDirFeedThru = (0);/* The model is not direct feedthrough */
  model_old_M->Sizes.numSampTimes = (1);/* Number of sample times */
  model_old_M->Sizes.numBlocks = (15); /* Number of blocks */
  model_old_M->Sizes.numBlockIO = (6); /* Number of block outputs */
  model_old_M->Sizes.numBlockPrms = (1008);/* Sum of parameter "widths" */
  return model_old_M;
}

/*========================================================================*
 * End of Classic call interface                                          *
 *========================================================================*/
