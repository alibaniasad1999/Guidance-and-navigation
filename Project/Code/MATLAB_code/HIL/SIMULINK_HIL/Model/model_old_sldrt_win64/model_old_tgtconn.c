/*
 * model_old_tgtconn.c
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

#include "rtwtypes.h"
#define EXTERN_C
#include <stddef.h>
#include "ToAsyncQueueTgtAppSvc/ToAsyncQueueTgtAppSvcCIntrf.h"

EXTERN_C void TgtConnBackgroundTask()
{
}

EXTERN_C const char *TgtConnInit(int_T argc, char_T *argv[])
{
  const char *result = (NULL);         /* assume success */
  if (startToAsyncQueueTgtAppSvc()) {
    result = "Could not start ToAsyncQueue app service";
    return(result);
  }

  return(result);
}

EXTERN_C void TgtConnTerm()
{
  terminateToAsyncQueueTgtAppSvc();
}

EXTERN_C void TgtConnPreStep(int_T tid)
{
}

EXTERN_C void TgtConnPostStep(int_T tid)
{
}

/* EOF: model_old_tgtconn.c */
