/*
 * part_n.h
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

#ifndef RTW_HEADER_part_n_h_
#define RTW_HEADER_part_n_h_
#ifndef part_n_COMMON_INCLUDES_
#define part_n_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "simstruc.h"
#include "fixedpoint.h"
#include "dt_info.h"
#include "ext_work.h"
#include "sldrtdef.h"
#endif                                 /* part_n_COMMON_INCLUDES_ */

#include "part_n_types.h"
#include "rtGetInf.h"
#include <stddef.h>
#include <string.h>
#include "rt_defines.h"
#include "rt_nonfinite.h"
#include "zero_crossing_types.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetBlockIO
#define rtmGetBlockIO(rtm)             ((rtm)->blockIO)
#endif

#ifndef rtmSetBlockIO
#define rtmSetBlockIO(rtm, val)        ((rtm)->blockIO = (val))
#endif

#ifndef rtmGetChecksums
#define rtmGetChecksums(rtm)           ((rtm)->Sizes.checksums)
#endif

#ifndef rtmSetChecksums
#define rtmSetChecksums(rtm, val)      ((rtm)->Sizes.checksums = (val))
#endif

#ifndef rtmGetConstBlockIO
#define rtmGetConstBlockIO(rtm)        ((rtm)->constBlockIO)
#endif

#ifndef rtmSetConstBlockIO
#define rtmSetConstBlockIO(rtm, val)   ((rtm)->constBlockIO = (val))
#endif

#ifndef rtmGetContStateDisabled
#define rtmGetContStateDisabled(rtm)   ((rtm)->contStateDisabled)
#endif

#ifndef rtmSetContStateDisabled
#define rtmSetContStateDisabled(rtm, val) ((rtm)->contStateDisabled = (val))
#endif

#ifndef rtmGetContStates
#define rtmGetContStates(rtm)          ((rtm)->contStates)
#endif

#ifndef rtmSetContStates
#define rtmSetContStates(rtm, val)     ((rtm)->contStates = (val))
#endif

#ifndef rtmGetContTimeOutputInconsistentWithStateAtMajorStepFlag
#define rtmGetContTimeOutputInconsistentWithStateAtMajorStepFlag(rtm) ((rtm)->CTOutputIncnstWithState)
#endif

#ifndef rtmSetContTimeOutputInconsistentWithStateAtMajorStepFlag
#define rtmSetContTimeOutputInconsistentWithStateAtMajorStepFlag(rtm, val) ((rtm)->CTOutputIncnstWithState = (val))
#endif

#ifndef rtmGetCtrlRateMdlRefTiming
#define rtmGetCtrlRateMdlRefTiming(rtm) ()
#endif

#ifndef rtmSetCtrlRateMdlRefTiming
#define rtmSetCtrlRateMdlRefTiming(rtm, val) ()
#endif

#ifndef rtmGetCtrlRateMdlRefTimingPtr
#define rtmGetCtrlRateMdlRefTimingPtr(rtm) ()
#endif

#ifndef rtmSetCtrlRateMdlRefTimingPtr
#define rtmSetCtrlRateMdlRefTimingPtr(rtm, val) ()
#endif

#ifndef rtmGetCtrlRateNumTicksToNextHit
#define rtmGetCtrlRateNumTicksToNextHit(rtm) ()
#endif

#ifndef rtmSetCtrlRateNumTicksToNextHit
#define rtmSetCtrlRateNumTicksToNextHit(rtm, val) ()
#endif

#ifndef rtmGetDataMapInfo
#define rtmGetDataMapInfo(rtm)         ()
#endif

#ifndef rtmSetDataMapInfo
#define rtmSetDataMapInfo(rtm, val)    ()
#endif

#ifndef rtmGetDefaultParam
#define rtmGetDefaultParam(rtm)        ((rtm)->defaultParam)
#endif

#ifndef rtmSetDefaultParam
#define rtmSetDefaultParam(rtm, val)   ((rtm)->defaultParam = (val))
#endif

#ifndef rtmGetDerivCacheNeedsReset
#define rtmGetDerivCacheNeedsReset(rtm) ((rtm)->derivCacheNeedsReset)
#endif

#ifndef rtmSetDerivCacheNeedsReset
#define rtmSetDerivCacheNeedsReset(rtm, val) ((rtm)->derivCacheNeedsReset = (val))
#endif

#ifndef rtmGetDirectFeedThrough
#define rtmGetDirectFeedThrough(rtm)   ((rtm)->Sizes.sysDirFeedThru)
#endif

#ifndef rtmSetDirectFeedThrough
#define rtmSetDirectFeedThrough(rtm, val) ((rtm)->Sizes.sysDirFeedThru = (val))
#endif

#ifndef rtmGetErrorStatusFlag
#define rtmGetErrorStatusFlag(rtm)     ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatusFlag
#define rtmSetErrorStatusFlag(rtm, val) ((rtm)->errorStatus = (val))
#endif

#ifndef rtmGetFinalTime
#define rtmGetFinalTime(rtm)           ((rtm)->Timing.tFinal)
#endif

#ifndef rtmSetFinalTime
#define rtmSetFinalTime(rtm, val)      ((rtm)->Timing.tFinal = (val))
#endif

#ifndef rtmGetFirstInitCondFlag
#define rtmGetFirstInitCondFlag(rtm)   ()
#endif

#ifndef rtmSetFirstInitCondFlag
#define rtmSetFirstInitCondFlag(rtm, val) ()
#endif

#ifndef rtmGetIntgData
#define rtmGetIntgData(rtm)            ((rtm)->intgData)
#endif

#ifndef rtmSetIntgData
#define rtmSetIntgData(rtm, val)       ((rtm)->intgData = (val))
#endif

#ifndef rtmGetMdlRefGlobalRuntimeEventIndices
#define rtmGetMdlRefGlobalRuntimeEventIndices(rtm) ()
#endif

#ifndef rtmSetMdlRefGlobalRuntimeEventIndices
#define rtmSetMdlRefGlobalRuntimeEventIndices(rtm, val) ()
#endif

#ifndef rtmGetMdlRefGlobalTID
#define rtmGetMdlRefGlobalTID(rtm)     ()
#endif

#ifndef rtmSetMdlRefGlobalTID
#define rtmSetMdlRefGlobalTID(rtm, val) ()
#endif

#ifndef rtmGetMdlRefGlobalTimerIndices
#define rtmGetMdlRefGlobalTimerIndices(rtm) ()
#endif

#ifndef rtmSetMdlRefGlobalTimerIndices
#define rtmSetMdlRefGlobalTimerIndices(rtm, val) ()
#endif

#ifndef rtmGetMdlRefTriggerTID
#define rtmGetMdlRefTriggerTID(rtm)    ()
#endif

#ifndef rtmSetMdlRefTriggerTID
#define rtmSetMdlRefTriggerTID(rtm, val) ()
#endif

#ifndef rtmGetModelMappingInfo
#define rtmGetModelMappingInfo(rtm)    ((rtm)->SpecialInfo.mappingInfo)
#endif

#ifndef rtmSetModelMappingInfo
#define rtmSetModelMappingInfo(rtm, val) ((rtm)->SpecialInfo.mappingInfo = (val))
#endif

#ifndef rtmGetModelName
#define rtmGetModelName(rtm)           ((rtm)->modelName)
#endif

#ifndef rtmSetModelName
#define rtmSetModelName(rtm, val)      ((rtm)->modelName = (val))
#endif

#ifndef rtmGetNonInlinedSFcns
#define rtmGetNonInlinedSFcns(rtm)     ()
#endif

#ifndef rtmSetNonInlinedSFcns
#define rtmSetNonInlinedSFcns(rtm, val) ()
#endif

#ifndef rtmGetNumBlockIO
#define rtmGetNumBlockIO(rtm)          ((rtm)->Sizes.numBlockIO)
#endif

#ifndef rtmSetNumBlockIO
#define rtmSetNumBlockIO(rtm, val)     ((rtm)->Sizes.numBlockIO = (val))
#endif

#ifndef rtmGetNumBlockParams
#define rtmGetNumBlockParams(rtm)      ((rtm)->Sizes.numBlockPrms)
#endif

#ifndef rtmSetNumBlockParams
#define rtmSetNumBlockParams(rtm, val) ((rtm)->Sizes.numBlockPrms = (val))
#endif

#ifndef rtmGetNumBlocks
#define rtmGetNumBlocks(rtm)           ((rtm)->Sizes.numBlocks)
#endif

#ifndef rtmSetNumBlocks
#define rtmSetNumBlocks(rtm, val)      ((rtm)->Sizes.numBlocks = (val))
#endif

#ifndef rtmGetNumContStates
#define rtmGetNumContStates(rtm)       ((rtm)->Sizes.numContStates)
#endif

#ifndef rtmSetNumContStates
#define rtmSetNumContStates(rtm, val)  ((rtm)->Sizes.numContStates = (val))
#endif

#ifndef rtmGetNumDWork
#define rtmGetNumDWork(rtm)            ((rtm)->Sizes.numDwork)
#endif

#ifndef rtmSetNumDWork
#define rtmSetNumDWork(rtm, val)       ((rtm)->Sizes.numDwork = (val))
#endif

#ifndef rtmGetNumInputPorts
#define rtmGetNumInputPorts(rtm)       ((rtm)->Sizes.numIports)
#endif

#ifndef rtmSetNumInputPorts
#define rtmSetNumInputPorts(rtm, val)  ((rtm)->Sizes.numIports = (val))
#endif

#ifndef rtmGetNumNonSampledZCs
#define rtmGetNumNonSampledZCs(rtm)    ((rtm)->Sizes.numNonSampZCs)
#endif

#ifndef rtmSetNumNonSampledZCs
#define rtmSetNumNonSampledZCs(rtm, val) ((rtm)->Sizes.numNonSampZCs = (val))
#endif

#ifndef rtmGetNumOutputPorts
#define rtmGetNumOutputPorts(rtm)      ((rtm)->Sizes.numOports)
#endif

#ifndef rtmSetNumOutputPorts
#define rtmSetNumOutputPorts(rtm, val) ((rtm)->Sizes.numOports = (val))
#endif

#ifndef rtmGetNumPeriodicContStates
#define rtmGetNumPeriodicContStates(rtm) ((rtm)->Sizes.numPeriodicContStates)
#endif

#ifndef rtmSetNumPeriodicContStates
#define rtmSetNumPeriodicContStates(rtm, val) ((rtm)->Sizes.numPeriodicContStates = (val))
#endif

#ifndef rtmGetNumSFcnParams
#define rtmGetNumSFcnParams(rtm)       ((rtm)->Sizes.numSFcnPrms)
#endif

#ifndef rtmSetNumSFcnParams
#define rtmSetNumSFcnParams(rtm, val)  ((rtm)->Sizes.numSFcnPrms = (val))
#endif

#ifndef rtmGetNumSFunctions
#define rtmGetNumSFunctions(rtm)       ((rtm)->Sizes.numSFcns)
#endif

#ifndef rtmSetNumSFunctions
#define rtmSetNumSFunctions(rtm, val)  ((rtm)->Sizes.numSFcns = (val))
#endif

#ifndef rtmGetNumSampleTimes
#define rtmGetNumSampleTimes(rtm)      ((rtm)->Sizes.numSampTimes)
#endif

#ifndef rtmSetNumSampleTimes
#define rtmSetNumSampleTimes(rtm, val) ((rtm)->Sizes.numSampTimes = (val))
#endif

#ifndef rtmGetNumU
#define rtmGetNumU(rtm)                ((rtm)->Sizes.numU)
#endif

#ifndef rtmSetNumU
#define rtmSetNumU(rtm, val)           ((rtm)->Sizes.numU = (val))
#endif

#ifndef rtmGetNumY
#define rtmGetNumY(rtm)                ((rtm)->Sizes.numY)
#endif

#ifndef rtmSetNumY
#define rtmSetNumY(rtm, val)           ((rtm)->Sizes.numY = (val))
#endif

#ifndef rtmGetOdeF
#define rtmGetOdeF(rtm)                ((rtm)->odeF)
#endif

#ifndef rtmSetOdeF
#define rtmSetOdeF(rtm, val)           ((rtm)->odeF = (val))
#endif

#ifndef rtmGetOdeY
#define rtmGetOdeY(rtm)                ((rtm)->odeY)
#endif

#ifndef rtmSetOdeY
#define rtmSetOdeY(rtm, val)           ((rtm)->odeY = (val))
#endif

#ifndef rtmGetOffsetTimeArray
#define rtmGetOffsetTimeArray(rtm)     ((rtm)->Timing.offsetTimesArray)
#endif

#ifndef rtmSetOffsetTimeArray
#define rtmSetOffsetTimeArray(rtm, val) ((rtm)->Timing.offsetTimesArray = (val))
#endif

#ifndef rtmGetOffsetTimePtr
#define rtmGetOffsetTimePtr(rtm)       ((rtm)->Timing.offsetTimes)
#endif

#ifndef rtmSetOffsetTimePtr
#define rtmSetOffsetTimePtr(rtm, val)  ((rtm)->Timing.offsetTimes = (val))
#endif

#ifndef rtmGetOptions
#define rtmGetOptions(rtm)             ((rtm)->Sizes.options)
#endif

#ifndef rtmSetOptions
#define rtmSetOptions(rtm, val)        ((rtm)->Sizes.options = (val))
#endif

#ifndef rtmGetParamIsMalloced
#define rtmGetParamIsMalloced(rtm)     ()
#endif

#ifndef rtmSetParamIsMalloced
#define rtmSetParamIsMalloced(rtm, val) ()
#endif

#ifndef rtmGetPath
#define rtmGetPath(rtm)                ((rtm)->path)
#endif

#ifndef rtmSetPath
#define rtmSetPath(rtm, val)           ((rtm)->path = (val))
#endif

#ifndef rtmGetPerTaskSampleHits
#define rtmGetPerTaskSampleHits(rtm)   ()
#endif

#ifndef rtmSetPerTaskSampleHits
#define rtmSetPerTaskSampleHits(rtm, val) ()
#endif

#ifndef rtmGetPerTaskSampleHitsArray
#define rtmGetPerTaskSampleHitsArray(rtm) ((rtm)->Timing.perTaskSampleHitsArray)
#endif

#ifndef rtmSetPerTaskSampleHitsArray
#define rtmSetPerTaskSampleHitsArray(rtm, val) ((rtm)->Timing.perTaskSampleHitsArray = (val))
#endif

#ifndef rtmGetPerTaskSampleHitsPtr
#define rtmGetPerTaskSampleHitsPtr(rtm) ((rtm)->Timing.perTaskSampleHits)
#endif

#ifndef rtmSetPerTaskSampleHitsPtr
#define rtmSetPerTaskSampleHitsPtr(rtm, val) ((rtm)->Timing.perTaskSampleHits = (val))
#endif

#ifndef rtmGetPeriodicContStateIndices
#define rtmGetPeriodicContStateIndices(rtm) ((rtm)->periodicContStateIndices)
#endif

#ifndef rtmSetPeriodicContStateIndices
#define rtmSetPeriodicContStateIndices(rtm, val) ((rtm)->periodicContStateIndices = (val))
#endif

#ifndef rtmGetPeriodicContStateRanges
#define rtmGetPeriodicContStateRanges(rtm) ((rtm)->periodicContStateRanges)
#endif

#ifndef rtmSetPeriodicContStateRanges
#define rtmSetPeriodicContStateRanges(rtm, val) ((rtm)->periodicContStateRanges = (val))
#endif

#ifndef rtmGetPrevZCSigState
#define rtmGetPrevZCSigState(rtm)      ((rtm)->prevZCSigState)
#endif

#ifndef rtmSetPrevZCSigState
#define rtmSetPrevZCSigState(rtm, val) ((rtm)->prevZCSigState = (val))
#endif

#ifndef rtmGetRTWExtModeInfo
#define rtmGetRTWExtModeInfo(rtm)      ((rtm)->extModeInfo)
#endif

#ifndef rtmSetRTWExtModeInfo
#define rtmSetRTWExtModeInfo(rtm, val) ((rtm)->extModeInfo = (val))
#endif

#ifndef rtmGetRTWGeneratedSFcn
#define rtmGetRTWGeneratedSFcn(rtm)    ((rtm)->Sizes.rtwGenSfcn)
#endif

#ifndef rtmSetRTWGeneratedSFcn
#define rtmSetRTWGeneratedSFcn(rtm, val) ((rtm)->Sizes.rtwGenSfcn = (val))
#endif

#ifndef rtmGetRTWLogInfo
#define rtmGetRTWLogInfo(rtm)          ()
#endif

#ifndef rtmSetRTWLogInfo
#define rtmSetRTWLogInfo(rtm, val)     ()
#endif

#ifndef rtmGetRTWRTModelMethodsInfo
#define rtmGetRTWRTModelMethodsInfo(rtm) ()
#endif

#ifndef rtmSetRTWRTModelMethodsInfo
#define rtmSetRTWRTModelMethodsInfo(rtm, val) ()
#endif

#ifndef rtmGetRTWSfcnInfo
#define rtmGetRTWSfcnInfo(rtm)         ((rtm)->sfcnInfo)
#endif

#ifndef rtmSetRTWSfcnInfo
#define rtmSetRTWSfcnInfo(rtm, val)    ((rtm)->sfcnInfo = (val))
#endif

#ifndef rtmGetRTWSolverInfo
#define rtmGetRTWSolverInfo(rtm)       ((rtm)->solverInfo)
#endif

#ifndef rtmSetRTWSolverInfo
#define rtmSetRTWSolverInfo(rtm, val)  ((rtm)->solverInfo = (val))
#endif

#ifndef rtmGetRTWSolverInfoPtr
#define rtmGetRTWSolverInfoPtr(rtm)    ((rtm)->solverInfoPtr)
#endif

#ifndef rtmSetRTWSolverInfoPtr
#define rtmSetRTWSolverInfoPtr(rtm, val) ((rtm)->solverInfoPtr = (val))
#endif

#ifndef rtmGetReservedForXPC
#define rtmGetReservedForXPC(rtm)      ((rtm)->SpecialInfo.xpcData)
#endif

#ifndef rtmSetReservedForXPC
#define rtmSetReservedForXPC(rtm, val) ((rtm)->SpecialInfo.xpcData = (val))
#endif

#ifndef rtmGetRootDWork
#define rtmGetRootDWork(rtm)           ((rtm)->dwork)
#endif

#ifndef rtmSetRootDWork
#define rtmSetRootDWork(rtm, val)      ((rtm)->dwork = (val))
#endif

#ifndef rtmGetSFunctions
#define rtmGetSFunctions(rtm)          ((rtm)->childSfunctions)
#endif

#ifndef rtmSetSFunctions
#define rtmSetSFunctions(rtm, val)     ((rtm)->childSfunctions = (val))
#endif

#ifndef rtmGetSampleHitArray
#define rtmGetSampleHitArray(rtm)      ((rtm)->Timing.sampleHitArray)
#endif

#ifndef rtmSetSampleHitArray
#define rtmSetSampleHitArray(rtm, val) ((rtm)->Timing.sampleHitArray = (val))
#endif

#ifndef rtmGetSampleHitPtr
#define rtmGetSampleHitPtr(rtm)        ((rtm)->Timing.sampleHits)
#endif

#ifndef rtmSetSampleHitPtr
#define rtmSetSampleHitPtr(rtm, val)   ((rtm)->Timing.sampleHits = (val))
#endif

#ifndef rtmGetSampleTimeArray
#define rtmGetSampleTimeArray(rtm)     ((rtm)->Timing.sampleTimesArray)
#endif

#ifndef rtmSetSampleTimeArray
#define rtmSetSampleTimeArray(rtm, val) ((rtm)->Timing.sampleTimesArray = (val))
#endif

#ifndef rtmGetSampleTimePtr
#define rtmGetSampleTimePtr(rtm)       ((rtm)->Timing.sampleTimes)
#endif

#ifndef rtmSetSampleTimePtr
#define rtmSetSampleTimePtr(rtm, val)  ((rtm)->Timing.sampleTimes = (val))
#endif

#ifndef rtmGetSampleTimeTaskIDArray
#define rtmGetSampleTimeTaskIDArray(rtm) ((rtm)->Timing.sampleTimeTaskIDArray)
#endif

#ifndef rtmSetSampleTimeTaskIDArray
#define rtmSetSampleTimeTaskIDArray(rtm, val) ((rtm)->Timing.sampleTimeTaskIDArray = (val))
#endif

#ifndef rtmGetSampleTimeTaskIDPtr
#define rtmGetSampleTimeTaskIDPtr(rtm) ((rtm)->Timing.sampleTimeTaskIDPtr)
#endif

#ifndef rtmSetSampleTimeTaskIDPtr
#define rtmSetSampleTimeTaskIDPtr(rtm, val) ((rtm)->Timing.sampleTimeTaskIDPtr = (val))
#endif

#ifndef rtmGetSelf
#define rtmGetSelf(rtm)                ()
#endif

#ifndef rtmSetSelf
#define rtmSetSelf(rtm, val)           ()
#endif

#ifndef rtmGetSimMode
#define rtmGetSimMode(rtm)             ((rtm)->simMode)
#endif

#ifndef rtmSetSimMode
#define rtmSetSimMode(rtm, val)        ((rtm)->simMode = (val))
#endif

#ifndef rtmGetSimTimeStep
#define rtmGetSimTimeStep(rtm)         ((rtm)->Timing.simTimeStep)
#endif

#ifndef rtmSetSimTimeStep
#define rtmSetSimTimeStep(rtm, val)    ((rtm)->Timing.simTimeStep = (val))
#endif

#ifndef rtmGetStartTime
#define rtmGetStartTime(rtm)           ((rtm)->Timing.tStart)
#endif

#ifndef rtmSetStartTime
#define rtmSetStartTime(rtm, val)      ((rtm)->Timing.tStart = (val))
#endif

#ifndef rtmGetStepSize
#define rtmGetStepSize(rtm)            ((rtm)->Timing.stepSize)
#endif

#ifndef rtmSetStepSize
#define rtmSetStepSize(rtm, val)       ((rtm)->Timing.stepSize = (val))
#endif

#ifndef rtmGetStopRequestedFlag
#define rtmGetStopRequestedFlag(rtm)   ((rtm)->Timing.stopRequestedFlag)
#endif

#ifndef rtmSetStopRequestedFlag
#define rtmSetStopRequestedFlag(rtm, val) ((rtm)->Timing.stopRequestedFlag = (val))
#endif

#ifndef rtmGetTaskCounters
#define rtmGetTaskCounters(rtm)        ()
#endif

#ifndef rtmSetTaskCounters
#define rtmSetTaskCounters(rtm, val)   ()
#endif

#ifndef rtmGetTaskTimeArray
#define rtmGetTaskTimeArray(rtm)       ((rtm)->Timing.tArray)
#endif

#ifndef rtmSetTaskTimeArray
#define rtmSetTaskTimeArray(rtm, val)  ((rtm)->Timing.tArray = (val))
#endif

#ifndef rtmGetTimePtr
#define rtmGetTimePtr(rtm)             ((rtm)->Timing.t)
#endif

#ifndef rtmSetTimePtr
#define rtmSetTimePtr(rtm, val)        ((rtm)->Timing.t = (val))
#endif

#ifndef rtmGetTimingData
#define rtmGetTimingData(rtm)          ((rtm)->Timing.timingData)
#endif

#ifndef rtmSetTimingData
#define rtmSetTimingData(rtm, val)     ((rtm)->Timing.timingData = (val))
#endif

#ifndef rtmGetU
#define rtmGetU(rtm)                   ((rtm)->inputs)
#endif

#ifndef rtmSetU
#define rtmSetU(rtm, val)              ((rtm)->inputs = (val))
#endif

#ifndef rtmGetVarNextHitTimesListPtr
#define rtmGetVarNextHitTimesListPtr(rtm) ((rtm)->Timing.varNextHitTimesList)
#endif

#ifndef rtmSetVarNextHitTimesListPtr
#define rtmSetVarNextHitTimesListPtr(rtm, val) ((rtm)->Timing.varNextHitTimesList = (val))
#endif

#ifndef rtmGetY
#define rtmGetY(rtm)                   ((rtm)->outputs)
#endif

#ifndef rtmSetY
#define rtmSetY(rtm, val)              ((rtm)->outputs = (val))
#endif

#ifndef rtmGetZCCacheNeedsReset
#define rtmGetZCCacheNeedsReset(rtm)   ((rtm)->zCCacheNeedsReset)
#endif

#ifndef rtmSetZCCacheNeedsReset
#define rtmSetZCCacheNeedsReset(rtm, val) ((rtm)->zCCacheNeedsReset = (val))
#endif

#ifndef rtmGetZCSignalValues
#define rtmGetZCSignalValues(rtm)      ((rtm)->zcSignalValues)
#endif

#ifndef rtmSetZCSignalValues
#define rtmSetZCSignalValues(rtm, val) ((rtm)->zcSignalValues = (val))
#endif

#ifndef rtmGet_TimeOfLastOutput
#define rtmGet_TimeOfLastOutput(rtm)   ((rtm)->Timing.timeOfLastOutput)
#endif

#ifndef rtmSet_TimeOfLastOutput
#define rtmSet_TimeOfLastOutput(rtm, val) ((rtm)->Timing.timeOfLastOutput = (val))
#endif

#ifndef rtmGetdX
#define rtmGetdX(rtm)                  ((rtm)->derivs)
#endif

#ifndef rtmSetdX
#define rtmSetdX(rtm, val)             ((rtm)->derivs = (val))
#endif

#ifndef rtmGettimingBridge
#define rtmGettimingBridge(rtm)        ()
#endif

#ifndef rtmSettimingBridge
#define rtmSettimingBridge(rtm, val)   ()
#endif

#ifndef rtmGetChecksumVal
#define rtmGetChecksumVal(rtm, idx)    ((rtm)->Sizes.checksums[idx])
#endif

#ifndef rtmSetChecksumVal
#define rtmSetChecksumVal(rtm, idx, val) ((rtm)->Sizes.checksums[idx] = (val))
#endif

#ifndef rtmGetDWork
#define rtmGetDWork(rtm, idx)          ((rtm)->dwork[idx])
#endif

#ifndef rtmSetDWork
#define rtmSetDWork(rtm, idx, val)     ((rtm)->dwork[idx] = (val))
#endif

#ifndef rtmGetOffsetTime
#define rtmGetOffsetTime(rtm, idx)     ((rtm)->Timing.offsetTimes[idx])
#endif

#ifndef rtmSetOffsetTime
#define rtmSetOffsetTime(rtm, idx, val) ((rtm)->Timing.offsetTimes[idx] = (val))
#endif

#ifndef rtmGetSFunction
#define rtmGetSFunction(rtm, idx)      ((rtm)->childSfunctions[idx])
#endif

#ifndef rtmSetSFunction
#define rtmSetSFunction(rtm, idx, val) ((rtm)->childSfunctions[idx] = (val))
#endif

#ifndef rtmGetSampleTime
#define rtmGetSampleTime(rtm, idx)     ((rtm)->Timing.sampleTimes[idx])
#endif

#ifndef rtmSetSampleTime
#define rtmSetSampleTime(rtm, idx, val) ((rtm)->Timing.sampleTimes[idx] = (val))
#endif

#ifndef rtmGetSampleTimeTaskID
#define rtmGetSampleTimeTaskID(rtm, idx) ((rtm)->Timing.sampleTimeTaskIDPtr[idx])
#endif

#ifndef rtmSetSampleTimeTaskID
#define rtmSetSampleTimeTaskID(rtm, idx, val) ((rtm)->Timing.sampleTimeTaskIDPtr[idx] = (val))
#endif

#ifndef rtmGetVarNextHitTimeList
#define rtmGetVarNextHitTimeList(rtm, idx) ((rtm)->Timing.varNextHitTimesList[idx])
#endif

#ifndef rtmSetVarNextHitTimeList
#define rtmSetVarNextHitTimeList(rtm, idx, val) ((rtm)->Timing.varNextHitTimesList[idx] = (val))
#endif

#ifndef rtmIsContinuousTask
#define rtmIsContinuousTask(rtm, tid)  ((tid) == 0)
#endif

#ifndef rtmGetErrorStatus
#define rtmGetErrorStatus(rtm)         ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
#define rtmSetErrorStatus(rtm, val)    ((rtm)->errorStatus = (val))
#endif

#ifndef rtmIsMajorTimeStep
#define rtmIsMajorTimeStep(rtm)        (((rtm)->Timing.simTimeStep) == MAJOR_TIME_STEP)
#endif

#ifndef rtmIsMinorTimeStep
#define rtmIsMinorTimeStep(rtm)        (((rtm)->Timing.simTimeStep) == MINOR_TIME_STEP)
#endif

#ifndef rtmIsSampleHit
#define rtmIsSampleHit(rtm, sti, tid)  ((rtmIsMajorTimeStep((rtm)) && (rtm)->Timing.sampleHits[(rtm)->Timing.sampleTimeTaskIDPtr[sti]]))
#endif

#ifndef rtmGetStopRequested
#define rtmGetStopRequested(rtm)       ((rtm)->Timing.stopRequestedFlag)
#endif

#ifndef rtmSetStopRequested
#define rtmSetStopRequested(rtm, val)  ((rtm)->Timing.stopRequestedFlag = (val))
#endif

#ifndef rtmGetStopRequestedPtr
#define rtmGetStopRequestedPtr(rtm)    (&((rtm)->Timing.stopRequestedFlag))
#endif

#ifndef rtmGetT
#define rtmGetT(rtm)                   (rtmGetTPtr((rtm))[0])
#endif

#ifndef rtmSetT
#define rtmSetT(rtm, val)                                        /* Do Nothing */
#endif

#ifndef rtmGetTFinal
#define rtmGetTFinal(rtm)              ((rtm)->Timing.tFinal)
#endif

#ifndef rtmSetTFinal
#define rtmSetTFinal(rtm, val)         ((rtm)->Timing.tFinal = (val))
#endif

#ifndef rtmGetTPtr
#define rtmGetTPtr(rtm)                ((rtm)->Timing.t)
#endif

#ifndef rtmSetTPtr
#define rtmSetTPtr(rtm, val)           ((rtm)->Timing.t = (val))
#endif

#ifndef rtmGetTStart
#define rtmGetTStart(rtm)              ((rtm)->Timing.tStart)
#endif

#ifndef rtmSetTStart
#define rtmSetTStart(rtm, val)         ((rtm)->Timing.tStart = (val))
#endif

#ifndef rtmGetTaskTime
#define rtmGetTaskTime(rtm, sti)       (rtmGetTPtr((rtm))[(rtm)->Timing.sampleTimeTaskIDPtr[sti]])
#endif

#ifndef rtmSetTaskTime
#define rtmSetTaskTime(rtm, sti, val)  (rtmGetTPtr((rtm))[sti] = (val))
#endif

#ifndef rtmGetTimeOfLastOutput
#define rtmGetTimeOfLastOutput(rtm)    ((rtm)->Timing.timeOfLastOutput)
#endif

#ifdef rtmGetRTWSolverInfo
#undef rtmGetRTWSolverInfo
#endif

#define rtmGetRTWSolverInfo(rtm)       &((rtm)->solverInfo)

/* Definition for use in the target main file */
#define part_n_rtModel                 RT_MODEL_part_n_T

/* Block signals (default storage) */
typedef struct {
  real_T Square[3];                    /* '<S3>/Square' */
  real_T Memory;                       /* '<S19>/Memory' */
  real_T Reset;                        /* '<S19>/Reset' */
  real_T Delay;                        /* '<S17>/Delay' */
  real_T Delay_f;                      /* '<S18>/Delay' */
  real_T Delay1;                       /* '<S11>/Delay1' */
  real_T R_m;                          /* '<S12>/Sqrt' */
  real_T Delay_k;                      /* '<S11>/Delay' */
  real_T d_sigma;                      /* '<S13>/Transfer Fcn' */
  real_T R_m_o;                        /* '<S13>/Sqrt' */
  real_T d_epsilon;                    /* '<S13>/Transfer Fcn2' */
  real_T Saturation[2];                /* '<S2>/Saturation' */
  real_T d_state[3];                   /* '<S4>/Integrator' */
  real_T d_state_j[3];                 /* '<S5>/Integrator' */
  real_T dd_state[3];                  /* '<S5>/MATLAB Function' */
  real_T dot_attitude[2];              /* '<S5>/MATLAB Function' */
  real_T dd_state_o[3];                /* '<S4>/MATLAB Function' */
  real_T dot_attitude_j[2];            /* '<S4>/MATLAB Function' */
  real_T d_sigma_e;                    /* '<S2>/MATLAB Function' */
  real_T d_epsilon_n;                  /* '<S2>/MATLAB Function' */
  real_T epsilon_t;                    /* '<S2>/MATLAB Function' */
  real_T sigma_t;                      /* '<S2>/MATLAB Function' */
  boolean_T AND;                       /* '<S3>/AND' */
} B_part_n_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  real_T Delay_DSTATE;                 /* '<S17>/Delay' */
  real_T Delay_DSTATE_f;               /* '<S18>/Delay' */
  real_T Delay1_DSTATE;                /* '<S11>/Delay1' */
  real_T Delay_DSTATE_j;               /* '<S11>/Delay' */
  real_T Memory_PreviousInput;         /* '<S19>/Memory' */
} DW_part_n_T;

/* Continuous states (default storage) */
typedef struct {
  real_T Integrator1_CSTATE[3];        /* '<S4>/Integrator1' */
  real_T Integrator1_CSTATE_k[3];      /* '<S5>/Integrator1' */
  real_T TransferFcn_CSTATE;           /* '<S12>/Transfer Fcn' */
  real_T TransferFcn4_CSTATE;          /* '<S12>/Transfer Fcn4' */
  real_T TransferFcn2_CSTATE;          /* '<S12>/Transfer Fcn2' */
  real_T TransferFcn_CSTATE_a;         /* '<S9>/Transfer Fcn' */
  real_T TransferFcn_CSTATE_l;         /* '<S10>/Transfer Fcn' */
  real_T TransferFcn_CSTATE_b;         /* '<S13>/Transfer Fcn' */
  real_T TransferFcn1_CSTATE;          /* '<S13>/Transfer Fcn1' */
  real_T TransferFcn4_CSTATE_p;        /* '<S13>/Transfer Fcn4' */
  real_T TransferFcn2_CSTATE_a;        /* '<S13>/Transfer Fcn2' */
  real_T TransferFcn3_CSTATE;          /* '<S13>/Transfer Fcn3' */
  real_T Integrator_CSTATE[3];         /* '<S4>/Integrator' */
  real_T Integrator2_CSTATE[2];        /* '<S4>/Integrator2' */
  real_T TransferFcn_CSTATE_c[2];      /* '<S22>/Transfer Fcn' */
  real_T TransferFcn1_CSTATE_n[2];     /* '<S22>/Transfer Fcn1' */
  real_T Integrator_CSTATE_b[3];       /* '<S5>/Integrator' */
  real_T Integrator2_CSTATE_j[2];      /* '<S5>/Integrator2' */
} X_part_n_T;

/* State derivatives (default storage) */
typedef struct {
  real_T Integrator1_CSTATE[3];        /* '<S4>/Integrator1' */
  real_T Integrator1_CSTATE_k[3];      /* '<S5>/Integrator1' */
  real_T TransferFcn_CSTATE;           /* '<S12>/Transfer Fcn' */
  real_T TransferFcn4_CSTATE;          /* '<S12>/Transfer Fcn4' */
  real_T TransferFcn2_CSTATE;          /* '<S12>/Transfer Fcn2' */
  real_T TransferFcn_CSTATE_a;         /* '<S9>/Transfer Fcn' */
  real_T TransferFcn_CSTATE_l;         /* '<S10>/Transfer Fcn' */
  real_T TransferFcn_CSTATE_b;         /* '<S13>/Transfer Fcn' */
  real_T TransferFcn1_CSTATE;          /* '<S13>/Transfer Fcn1' */
  real_T TransferFcn4_CSTATE_p;        /* '<S13>/Transfer Fcn4' */
  real_T TransferFcn2_CSTATE_a;        /* '<S13>/Transfer Fcn2' */
  real_T TransferFcn3_CSTATE;          /* '<S13>/Transfer Fcn3' */
  real_T Integrator_CSTATE[3];         /* '<S4>/Integrator' */
  real_T Integrator2_CSTATE[2];        /* '<S4>/Integrator2' */
  real_T TransferFcn_CSTATE_c[2];      /* '<S22>/Transfer Fcn' */
  real_T TransferFcn1_CSTATE_n[2];     /* '<S22>/Transfer Fcn1' */
  real_T Integrator_CSTATE_b[3];       /* '<S5>/Integrator' */
  real_T Integrator2_CSTATE_j[2];      /* '<S5>/Integrator2' */
} XDot_part_n_T;

/* State disabled  */
typedef struct {
  boolean_T Integrator1_CSTATE[3];     /* '<S4>/Integrator1' */
  boolean_T Integrator1_CSTATE_k[3];   /* '<S5>/Integrator1' */
  boolean_T TransferFcn_CSTATE;        /* '<S12>/Transfer Fcn' */
  boolean_T TransferFcn4_CSTATE;       /* '<S12>/Transfer Fcn4' */
  boolean_T TransferFcn2_CSTATE;       /* '<S12>/Transfer Fcn2' */
  boolean_T TransferFcn_CSTATE_a;      /* '<S9>/Transfer Fcn' */
  boolean_T TransferFcn_CSTATE_l;      /* '<S10>/Transfer Fcn' */
  boolean_T TransferFcn_CSTATE_b;      /* '<S13>/Transfer Fcn' */
  boolean_T TransferFcn1_CSTATE;       /* '<S13>/Transfer Fcn1' */
  boolean_T TransferFcn4_CSTATE_p;     /* '<S13>/Transfer Fcn4' */
  boolean_T TransferFcn2_CSTATE_a;     /* '<S13>/Transfer Fcn2' */
  boolean_T TransferFcn3_CSTATE;       /* '<S13>/Transfer Fcn3' */
  boolean_T Integrator_CSTATE[3];      /* '<S4>/Integrator' */
  boolean_T Integrator2_CSTATE[2];     /* '<S4>/Integrator2' */
  boolean_T TransferFcn_CSTATE_c[2];   /* '<S22>/Transfer Fcn' */
  boolean_T TransferFcn1_CSTATE_n[2];  /* '<S22>/Transfer Fcn1' */
  boolean_T Integrator_CSTATE_b[3];    /* '<S5>/Integrator' */
  boolean_T Integrator2_CSTATE_j[2];   /* '<S5>/Integrator2' */
} XDis_part_n_T;

#ifndef ODE4_INTG
#define ODE4_INTG

/* ODE4 Integration Data */
typedef struct {
  real_T *y;                           /* output */
  real_T *f[4];                        /* derivatives */
} ODE4_IntgData;

#endif

/* Backward compatible GRT Identifiers */
#define rtB                            part_n_B
#define BlockIO                        B_part_n_T
#define rtX                            part_n_X
#define ContinuousStates               X_part_n_T
#define rtXdot                         part_n_XDot
#define StateDerivatives               XDot_part_n_T
#define tXdis                          part_n_XDis
#define StateDisabled                  XDis_part_n_T
#define rtP                            part_n_P
#define Parameters                     P_part_n_T
#define rtDWork                        part_n_DW
#define D_Work                         DW_part_n_T

/* Parameters (default storage) */
struct P_part_n_T_ {
  real_T attitude_m0[2];               /* Variable: attitude_m0
                                        * Referenced by: '<S4>/Integrator2'
                                        */
  real_T attitude_t0[2];               /* Variable: attitude_t0
                                        * Referenced by: '<S5>/Integrator2'
                                        */
  real_T d_state_m[3];                 /* Variable: d_state_m
                                        * Referenced by: '<S4>/Integrator'
                                        */
  real_T d_state_t[3];                 /* Variable: d_state_t
                                        * Referenced by: '<S5>/Integrator'
                                        */
  real_T k_epsilon_lead_angle;         /* Variable: k_epsilon_lead_angle
                                        * Referenced by: '<S10>/Gain1'
                                        */
  real_T k_sigma_lead_angle;           /* Variable: k_sigma_lead_angle
                                        * Referenced by: '<S9>/Gain'
                                        */
  real_T state_m0[3];                  /* Variable: state_m0
                                        * Referenced by: '<S4>/Integrator1'
                                        */
  real_T state_t0[3];                  /* Variable: state_t0
                                        * Referenced by: '<S5>/Integrator1'
                                        */
  real_T MinMaxRunningResettable_vinit;
                                /* Mask Parameter: MinMaxRunningResettable_vinit
                                 * Referenced by:
                                 *   '<S19>/Initial Condition'
                                 *   '<S19>/Memory'
                                 */
  real_T Constant_Value;               /* Expression: 0
                                        * Referenced by: '<S3>/Constant'
                                        */
  real_T Constant3_Value;              /* Expression: 0
                                        * Referenced by: '<S17>/Constant3'
                                        */
  real_T Delay_InitialCondition;       /* Expression: inf
                                        * Referenced by: '<S17>/Delay'
                                        */
  real_T Constant4_Value;              /* Expression: 1
                                        * Referenced by: '<S17>/Constant4'
                                        */
  real_T Switch_Threshold;             /* Expression: 0
                                        * Referenced by: '<S17>/Switch'
                                        */
  real_T Constant3_Value_i;            /* Expression: 0
                                        * Referenced by: '<S18>/Constant3'
                                        */
  real_T Delay_InitialCondition_k;     /* Expression: inf
                                        * Referenced by: '<S18>/Delay'
                                        */
  real_T Constant4_Value_c;            /* Expression: 1
                                        * Referenced by: '<S18>/Constant4'
                                        */
  real_T Switch_Threshold_i;           /* Expression: 0
                                        * Referenced by: '<S18>/Switch'
                                        */
  real_T Constant7_Value;              /* Expression: 1
                                        * Referenced by: '<S1>/Constant7'
                                        */
  real_T Constant8_Value[3];           /* Expression: [0; 0; -10]
                                        * Referenced by: '<S1>/Constant8'
                                        */
  real_T Constant9_Value;              /* Expression: 0
                                        * Referenced by: '<S1>/Constant9'
                                        */
  real_T Delay1_InitialCondition;      /* Expression: 0.0
                                        * Referenced by: '<S11>/Delay1'
                                        */
  real_T TransferFcn_A;                /* Computed Parameter: TransferFcn_A
                                        * Referenced by: '<S12>/Transfer Fcn'
                                        */
  real_T TransferFcn_C;                /* Computed Parameter: TransferFcn_C
                                        * Referenced by: '<S12>/Transfer Fcn'
                                        */
  real_T TransferFcn_D;                /* Computed Parameter: TransferFcn_D
                                        * Referenced by: '<S12>/Transfer Fcn'
                                        */
  real_T TransferFcn4_A;               /* Computed Parameter: TransferFcn4_A
                                        * Referenced by: '<S12>/Transfer Fcn4'
                                        */
  real_T TransferFcn4_C;               /* Computed Parameter: TransferFcn4_C
                                        * Referenced by: '<S12>/Transfer Fcn4'
                                        */
  real_T TransferFcn4_D;               /* Computed Parameter: TransferFcn4_D
                                        * Referenced by: '<S12>/Transfer Fcn4'
                                        */
  real_T Delay_InitialCondition_i;     /* Expression: 0.0
                                        * Referenced by: '<S11>/Delay'
                                        */
  real_T TransferFcn2_A;               /* Computed Parameter: TransferFcn2_A
                                        * Referenced by: '<S12>/Transfer Fcn2'
                                        */
  real_T TransferFcn2_C;               /* Computed Parameter: TransferFcn2_C
                                        * Referenced by: '<S12>/Transfer Fcn2'
                                        */
  real_T TransferFcn2_D;               /* Computed Parameter: TransferFcn2_D
                                        * Referenced by: '<S12>/Transfer Fcn2'
                                        */
  real_T TransferFcn_A_a;              /* Computed Parameter: TransferFcn_A_a
                                        * Referenced by: '<S9>/Transfer Fcn'
                                        */
  real_T TransferFcn_C_i;              /* Computed Parameter: TransferFcn_C_i
                                        * Referenced by: '<S9>/Transfer Fcn'
                                        */
  real_T TransferFcn_D_j;              /* Computed Parameter: TransferFcn_D_j
                                        * Referenced by: '<S9>/Transfer Fcn'
                                        */
  real_T TransferFcn_A_j;              /* Computed Parameter: TransferFcn_A_j
                                        * Referenced by: '<S10>/Transfer Fcn'
                                        */
  real_T TransferFcn_C_o;              /* Computed Parameter: TransferFcn_C_o
                                        * Referenced by: '<S10>/Transfer Fcn'
                                        */
  real_T TransferFcn_D_c;              /* Computed Parameter: TransferFcn_D_c
                                        * Referenced by: '<S10>/Transfer Fcn'
                                        */
  real_T TransferFcn_A_jp;             /* Computed Parameter: TransferFcn_A_jp
                                        * Referenced by: '<S13>/Transfer Fcn'
                                        */
  real_T TransferFcn_C_m;              /* Computed Parameter: TransferFcn_C_m
                                        * Referenced by: '<S13>/Transfer Fcn'
                                        */
  real_T TransferFcn_D_f;              /* Computed Parameter: TransferFcn_D_f
                                        * Referenced by: '<S13>/Transfer Fcn'
                                        */
  real_T TransferFcn1_A;               /* Computed Parameter: TransferFcn1_A
                                        * Referenced by: '<S13>/Transfer Fcn1'
                                        */
  real_T TransferFcn1_C;               /* Computed Parameter: TransferFcn1_C
                                        * Referenced by: '<S13>/Transfer Fcn1'
                                        */
  real_T TransferFcn1_D;               /* Computed Parameter: TransferFcn1_D
                                        * Referenced by: '<S13>/Transfer Fcn1'
                                        */
  real_T TransferFcn4_A_p;             /* Computed Parameter: TransferFcn4_A_p
                                        * Referenced by: '<S13>/Transfer Fcn4'
                                        */
  real_T TransferFcn4_C_a;             /* Computed Parameter: TransferFcn4_C_a
                                        * Referenced by: '<S13>/Transfer Fcn4'
                                        */
  real_T TransferFcn4_D_g;             /* Computed Parameter: TransferFcn4_D_g
                                        * Referenced by: '<S13>/Transfer Fcn4'
                                        */
  real_T TransferFcn2_A_a;             /* Computed Parameter: TransferFcn2_A_a
                                        * Referenced by: '<S13>/Transfer Fcn2'
                                        */
  real_T TransferFcn2_C_b;             /* Computed Parameter: TransferFcn2_C_b
                                        * Referenced by: '<S13>/Transfer Fcn2'
                                        */
  real_T TransferFcn2_D_p;             /* Computed Parameter: TransferFcn2_D_p
                                        * Referenced by: '<S13>/Transfer Fcn2'
                                        */
  real_T TransferFcn3_A;               /* Computed Parameter: TransferFcn3_A
                                        * Referenced by: '<S13>/Transfer Fcn3'
                                        */
  real_T TransferFcn3_C;               /* Computed Parameter: TransferFcn3_C
                                        * Referenced by: '<S13>/Transfer Fcn3'
                                        */
  real_T TransferFcn3_D;               /* Computed Parameter: TransferFcn3_D
                                        * Referenced by: '<S13>/Transfer Fcn3'
                                        */
  real_T Constant_Value_p;             /* Expression: 0
                                        * Referenced by: '<S13>/Constant'
                                        */
  real_T Switch_Threshold_g;           /* Expression: 0.2
                                        * Referenced by: '<S13>/Switch'
                                        */
  real_T Saturation_UpperSat;          /* Expression: 5*9.81
                                        * Referenced by: '<S2>/Saturation'
                                        */
  real_T Saturation_LowerSat;          /* Expression: -5*9.81
                                        * Referenced by: '<S2>/Saturation'
                                        */
  real_T Step_Time;                    /* Expression: 3
                                        * Referenced by: '<S6>/Step'
                                        */
  real_T Step_Y0;                      /* Expression: 0
                                        * Referenced by: '<S6>/Step'
                                        */
  real_T Step_YFinal;                  /* Expression: -1
                                        * Referenced by: '<S6>/Step'
                                        */
  real_T Step1_Time;                   /* Expression: 0
                                        * Referenced by: '<S6>/Step1'
                                        */
  real_T Step1_Y0;                     /* Expression: 0
                                        * Referenced by: '<S6>/Step1'
                                        */
  real_T Step1_YFinal;                 /* Expression: 1
                                        * Referenced by: '<S6>/Step1'
                                        */
  real_T Gain_Gain;                    /* Expression: 300
                                        * Referenced by: '<S6>/Gain'
                                        */
  real_T Constant1_Value;              /* Expression: 1.5e-4
                                        * Referenced by: '<S6>/Constant1'
                                        */
  real_T TransferFcn_A_l[2];           /* Computed Parameter: TransferFcn_A_l
                                        * Referenced by: '<S22>/Transfer Fcn'
                                        */
  real_T TransferFcn_C_c[2];           /* Computed Parameter: TransferFcn_C_c
                                        * Referenced by: '<S22>/Transfer Fcn'
                                        */
  real_T TransferFcn1_A_o[2];          /* Computed Parameter: TransferFcn1_A_o
                                        * Referenced by: '<S22>/Transfer Fcn1'
                                        */
  real_T TransferFcn1_C_e[2];          /* Computed Parameter: TransferFcn1_C_e
                                        * Referenced by: '<S22>/Transfer Fcn1'
                                        */
};

/* Real-time Model Data Structure */
struct tag_RTM_part_n_T {
  const char_T *path;
  const char_T *modelName;
  struct SimStruct_tag * *childSfunctions;
  const char_T *errorStatus;
  SS_SimMode simMode;
  RTWExtModeInfo *extModeInfo;
  RTWSolverInfo solverInfo;
  RTWSolverInfo *solverInfoPtr;
  void *sfcnInfo;
  void *blockIO;
  const void *constBlockIO;
  void *defaultParam;
  ZCSigState *prevZCSigState;
  real_T *contStates;
  int_T *periodicContStateIndices;
  real_T *periodicContStateRanges;
  real_T *derivs;
  void *zcSignalValues;
  void *inputs;
  void *outputs;
  boolean_T *contStateDisabled;
  boolean_T zCCacheNeedsReset;
  boolean_T derivCacheNeedsReset;
  boolean_T CTOutputIncnstWithState;
  real_T odeY[30];
  real_T odeF[4][30];
  ODE4_IntgData intgData;
  void *dwork;

  /*
   * Sizes:
   * The following substructure contains sizes information
   * for many of the model attributes such as inputs, outputs,
   * dwork, sample times, etc.
   */
  struct {
    uint32_T checksums[4];
    uint32_T options;
    int_T numContStates;
    int_T numPeriodicContStates;
    int_T numU;
    int_T numY;
    int_T numSampTimes;
    int_T numBlocks;
    int_T numBlockIO;
    int_T numBlockPrms;
    int_T numDwork;
    int_T numSFcnPrms;
    int_T numSFcns;
    int_T numIports;
    int_T numOports;
    int_T numNonSampZCs;
    int_T sysDirFeedThru;
    int_T rtwGenSfcn;
  } Sizes;

  /*
   * SpecialInfo:
   * The following substructure contains special information
   * related to other components that are dependent on RTW.
   */
  struct {
    const void *mappingInfo;
    void *xpcData;
  } SpecialInfo;

  /*
   * Timing:
   * The following substructure contains information regarding
   * the timing information for the model.
   */
  struct {
    time_T stepSize;
    uint32_T clockTick0;
    uint32_T clockTickH0;
    time_T stepSize0;
    uint32_T clockTick1;
    uint32_T clockTickH1;
    time_T stepSize1;
    time_T tStart;
    time_T tFinal;
    time_T timeOfLastOutput;
    void *timingData;
    real_T *varNextHitTimesList;
    SimTimeStep simTimeStep;
    boolean_T stopRequestedFlag;
    time_T *sampleTimes;
    time_T *offsetTimes;
    int_T *sampleTimeTaskIDPtr;
    int_T *sampleHits;
    int_T *perTaskSampleHits;
    time_T *t;
    time_T sampleTimesArray[2];
    time_T offsetTimesArray[2];
    int_T sampleTimeTaskIDArray[2];
    int_T sampleHitArray[2];
    int_T perTaskSampleHitsArray[4];
    time_T tArray[2];
  } Timing;
};

/* Block parameters (default storage) */
extern P_part_n_T part_n_P;

/* Block signals (default storage) */
extern B_part_n_T part_n_B;

/* Continuous states (default storage) */
extern X_part_n_T part_n_X;

/* Block states (default storage) */
extern DW_part_n_T part_n_DW;

/* Model entry point functions */
extern void part_n_initialize(void);
extern void part_n_output(void);
extern void part_n_update(void);
extern void part_n_terminate(void);

/*====================*
 * External functions *
 *====================*/
extern part_n_rtModel *part_n(void);
extern void MdlInitializeSizes(void);
extern void MdlInitializeSampleTimes(void);
extern void MdlInitialize(void);
extern void MdlStart(void);
extern void MdlOutputs(int_T tid);
extern void MdlUpdate(int_T tid);
extern void MdlTerminate(void);

/* Real-time Model object */
extern RT_MODEL_part_n_T *const part_n_M;

/*-
 * The generated code includes comments that allow you to trace directly
 * back to the appropriate location in the model.  The basic format
 * is <system>/block_name, where system is the system number (uniquely
 * assigned by Simulink) and block_name is the name of the block.
 *
 * Use the MATLAB hilite_system command to trace the generated code back
 * to the model.  For example,
 *
 * hilite_system('<S3>')    - opens system 3
 * hilite_system('<S3>/Kp') - opens and selects block Kp which resides in S3
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'part_n'
 * '<S1>'   : 'part_n/scenario III'
 * '<S2>'   : 'part_n/scenario III/Lead Anggle2'
 * '<S3>'   : 'part_n/scenario III/Miss Distance3'
 * '<S4>'   : 'part_n/scenario III/Missile 3'
 * '<S5>'   : 'part_n/scenario III/Target3'
 * '<S6>'   : 'part_n/scenario III/acceleration3'
 * '<S7>'   : 'part_n/scenario III/Lead Anggle2/MATLAB Function'
 * '<S8>'   : 'part_n/scenario III/Lead Anggle2/MATLAB Function1'
 * '<S9>'   : 'part_n/scenario III/Lead Anggle2/Subsystem'
 * '<S10>'  : 'part_n/scenario III/Lead Anggle2/Subsystem1'
 * '<S11>'  : 'part_n/scenario III/Lead Anggle2/Subsystem4'
 * '<S12>'  : 'part_n/scenario III/Lead Anggle2/Subsystem4/Subsystem2'
 * '<S13>'  : 'part_n/scenario III/Lead Anggle2/Subsystem4/Subsystem3'
 * '<S14>'  : 'part_n/scenario III/Lead Anggle2/Subsystem4/Subsystem2/MATLAB Function'
 * '<S15>'  : 'part_n/scenario III/Lead Anggle2/Subsystem4/Subsystem3/MATLAB Function'
 * '<S16>'  : 'part_n/scenario III/Miss Distance3/MinMax Running Resettable'
 * '<S17>'  : 'part_n/scenario III/Miss Distance3/nearing check'
 * '<S18>'  : 'part_n/scenario III/Miss Distance3/nearing check y'
 * '<S19>'  : 'part_n/scenario III/Miss Distance3/MinMax Running Resettable/Subsystem'
 * '<S20>'  : 'part_n/scenario III/Missile 3/MATLAB Function'
 * '<S21>'  : 'part_n/scenario III/Missile 3/Transformation Matrix'
 * '<S22>'  : 'part_n/scenario III/Missile 3/a model'
 * '<S23>'  : 'part_n/scenario III/Target3/MATLAB Function'
 * '<S24>'  : 'part_n/scenario III/Target3/Transformation Matrix'
 */
#endif                                 /* RTW_HEADER_part_n_h_ */
