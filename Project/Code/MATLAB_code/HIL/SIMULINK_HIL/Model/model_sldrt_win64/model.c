/*
 * model.c
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
#include "rtwtypes.h"
#include <string.h>
#include <emmintrin.h>
#include <math.h>
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
  { "Standard_Devices/Serial_Port", 4U, 8, SLDRTBoardOptions0 },
};

/* Block signals (default storage) */
B_model_T model_B;

/* Block states (default storage) */
DW_model_T model_DW;

/* Real-time model */
static RT_MODEL_model_T model_M_;
RT_MODEL_model_T *const model_M = &model_M_;

/* Forward declaration for local functions */
static void model_genrand_uint32_vector(uint32_T mt[625], uint32_T u[2]);
static real_T model_genrandu(uint32_T mt[625]);
static real_T model_eml_rand_mt19937ar(uint32_T state[625]);
static void model_randn(real_T r[40]);
static void model_sum(const real_T x[40], real_T y[20]);
static void model_sqrt(real_T x[20]);
static void model_power(const real_T a[2], real_T y[2]);
static int32_T model_combineVectorElements(const boolean_T x[20]);
static void model_repmat(const real_T a_data[], const int32_T a_size[2], real_T
  b_data[], int32_T b_size[2]);
static void model_binary_expand_op(real_T in1[40], const int8_T in2_data[],
  const int8_T in3_data[], const int32_T in3_size[2], const real_T in4[20]);

/* Function for MATLAB Function: '<Root>/MATLAB Function1' */
static void model_genrand_uint32_vector(uint32_T mt[625], uint32_T u[2])
{
  int32_T j;
  int32_T kk;
  for (j = 0; j < 2; j++) {
    uint32_T mti;
    uint32_T y;
    mti = mt[624] + 1U;
    if (mt[624] + 1U >= 625U) {
      for (kk = 0; kk < 227; kk++) {
        mti = (mt[kk + 1] & 2147483647U) | (mt[kk] & 2147483648U);
        if ((mti & 1U) == 0U) {
          mti >>= 1U;
        } else {
          mti = mti >> 1U ^ 2567483615U;
        }

        mt[kk] = mt[kk + 397] ^ mti;
      }

      for (kk = 0; kk < 396; kk++) {
        mti = (mt[kk + 227] & 2147483648U) | (mt[kk + 228] & 2147483647U);
        if ((mti & 1U) == 0U) {
          mti >>= 1U;
        } else {
          mti = mti >> 1U ^ 2567483615U;
        }

        mt[kk + 227] = mt[kk] ^ mti;
      }

      mti = (mt[623] & 2147483648U) | (mt[0] & 2147483647U);
      if ((mti & 1U) == 0U) {
        mti >>= 1U;
      } else {
        mti = mti >> 1U ^ 2567483615U;
      }

      mt[623] = mt[396] ^ mti;
      mti = 1U;
    }

    y = mt[(int32_T)mti - 1];
    mt[624] = mti;
    y ^= y >> 11U;
    y ^= y << 7U & 2636928640U;
    y ^= y << 15U & 4022730752U;
    u[j] = y >> 18U ^ y;
  }
}

/* Function for MATLAB Function: '<Root>/MATLAB Function1' */
static real_T model_genrandu(uint32_T mt[625])
{
  real_T r;
  uint32_T u[2];

  /* ========================= COPYRIGHT NOTICE ============================ */
  /*  This is a uniform (0,1) pseudorandom number generator based on:        */
  /*                                                                         */
  /*  A C-program for MT19937, with initialization improved 2002/1/26.       */
  /*  Coded by Takuji Nishimura and Makoto Matsumoto.                        */
  /*                                                                         */
  /*  Copyright (C) 1997 - 2002, Makoto Matsumoto and Takuji Nishimura,      */
  /*  All rights reserved.                                                   */
  /*                                                                         */
  /*  Redistribution and use in source and binary forms, with or without     */
  /*  modification, are permitted provided that the following conditions     */
  /*  are met:                                                               */
  /*                                                                         */
  /*    1. Redistributions of source code must retain the above copyright    */
  /*       notice, this list of conditions and the following disclaimer.     */
  /*                                                                         */
  /*    2. Redistributions in binary form must reproduce the above copyright */
  /*       notice, this list of conditions and the following disclaimer      */
  /*       in the documentation and/or other materials provided with the     */
  /*       distribution.                                                     */
  /*                                                                         */
  /*    3. The names of its contributors may not be used to endorse or       */
  /*       promote products derived from this software without specific      */
  /*       prior written permission.                                         */
  /*                                                                         */
  /*  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS    */
  /*  "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT      */
  /*  LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR  */
  /*  A PARTICULAR PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL THE COPYRIGHT  */
  /*  OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,  */
  /*  SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT       */
  /*  LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  */
  /*  DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  */
  /*  THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT    */
  /*  (INCLUDING  NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE */
  /*  OF THIS  SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  */
  /*                                                                         */
  /* =============================   END   ================================= */
  int32_T exitg1;
  do {
    exitg1 = 0;
    model_genrand_uint32_vector(mt, u);
    r = ((real_T)(u[0] >> 5U) * 6.7108864E+7 + (real_T)(u[1] >> 6U)) *
      1.1102230246251565E-16;
    if (r == 0.0) {
      boolean_T b_isvalid;
      if ((mt[624] >= 1U) && (mt[624] < 625U)) {
        int32_T k;
        boolean_T exitg2;
        b_isvalid = false;
        k = 1;
        exitg2 = false;
        while ((!exitg2) && (k < 625)) {
          if (mt[k - 1] == 0U) {
            k++;
          } else {
            b_isvalid = true;
            exitg2 = true;
          }
        }
      } else {
        b_isvalid = false;
      }

      if (!b_isvalid) {
        mt[0] = 5489U;
        mt[624] = 624U;
      }
    } else {
      exitg1 = 1;
    }
  } while (exitg1 == 0);

  return r;
}

/* Function for MATLAB Function: '<Root>/MATLAB Function1' */
static real_T model_eml_rand_mt19937ar(uint32_T state[625])
{
  real_T r;
  uint32_T u32[2];
  static const real_T b[257] = { 0.0, 0.215241895984875, 0.286174591792068,
    0.335737519214422, 0.375121332878378, 0.408389134611989, 0.43751840220787,
    0.46363433679088, 0.487443966139235, 0.50942332960209, 0.529909720661557,
    0.549151702327164, 0.567338257053817, 0.584616766106378, 0.601104617755991,
    0.61689699000775, 0.63207223638606, 0.646695714894993, 0.660822574244419,
    0.674499822837293, 0.687767892795788, 0.700661841106814, 0.713212285190975,
    0.725446140909999, 0.737387211434295, 0.749056662017815, 0.760473406430107,
    0.771654424224568, 0.782615023307232, 0.793369058840623, 0.80392911698997,
    0.814306670135215, 0.824512208752291, 0.834555354086381, 0.844444954909153,
    0.854189171008163, 0.863795545553308, 0.87327106808886, 0.882622229585165,
    0.891855070732941, 0.900975224461221, 0.909987953496718, 0.91889818364959,
    0.927710533401999, 0.936429340286575, 0.945058684468165, 0.953602409881086,
    0.96206414322304, 0.970447311064224, 0.978755155294224, 0.986990747099062,
    0.99515699963509, 1.00325667954467, 1.01129241744, 1.01926671746548,
    1.02718196603564, 1.03504043983344, 1.04284431314415, 1.05059566459093,
    1.05829648333067, 1.06594867476212, 1.07355406579244, 1.0811144097034,
    1.08863139065398, 1.09610662785202, 1.10354167942464, 1.11093804601357,
    1.11829717411934, 1.12562045921553, 1.13290924865253, 1.14016484436815,
    1.14738850542085, 1.15458145035993, 1.16174485944561, 1.16887987673083,
    1.17598761201545, 1.18306914268269, 1.19012551542669, 1.19715774787944,
    1.20416683014438, 1.2111537262437, 1.21811937548548, 1.22506469375653,
    1.23199057474614, 1.23889789110569, 1.24578749554863, 1.2526602218949,
    1.25951688606371, 1.26635828701823, 1.27318520766536, 1.27999841571382,
    1.28679866449324, 1.29358669373695, 1.30036323033084, 1.30712898903073,
    1.31388467315022, 1.32063097522106, 1.32736857762793, 1.33409815321936,
    1.3408203658964, 1.34753587118059, 1.35424531676263, 1.36094934303328,
    1.36764858359748, 1.37434366577317, 1.38103521107586, 1.38772383568998,
    1.39441015092814, 1.40109476367925, 1.4077782768464, 1.41446128977547,
    1.42114439867531, 1.42782819703026, 1.43451327600589, 1.44120022484872,
    1.44788963128058, 1.45458208188841, 1.46127816251028, 1.46797845861808,
    1.47468355569786, 1.48139403962819, 1.48811049705745, 1.49483351578049,
    1.50156368511546, 1.50830159628131, 1.51504784277671, 1.521803020761,
    1.52856772943771, 1.53534257144151, 1.542128153229, 1.54892508547417,
    1.55573398346918, 1.56255546753104, 1.56939016341512, 1.57623870273591,
    1.58310172339603, 1.58997987002419, 1.59687379442279, 1.60378415602609,
    1.61071162236983, 1.61765686957301, 1.62462058283303, 1.63160345693487,
    1.63860619677555, 1.64562951790478, 1.65267414708306, 1.65974082285818,
    1.66683029616166, 1.67394333092612, 1.68108070472517, 1.68824320943719,
    1.69543165193456, 1.70264685479992, 1.7098896570713, 1.71716091501782,
    1.72446150294804, 1.73179231405296, 1.73915426128591, 1.74654827828172,
    1.75397532031767, 1.76143636531891, 1.76893241491127, 1.77646449552452,
    1.78403365954944, 1.79164098655216, 1.79928758454972, 1.80697459135082,
    1.81470317596628, 1.82247454009388, 1.83028991968276, 1.83815058658281,
    1.84605785028518, 1.8540130597602, 1.86201760539967, 1.87007292107127,
    1.878180486293, 1.88634182853678, 1.8945585256707, 1.90283220855043,
    1.91116456377125, 1.91955733659319, 1.92801233405266, 1.93653142827569,
    1.94511656000868, 1.95376974238465, 1.96249306494436, 1.97128869793366,
    1.98015889690048, 1.98910600761744, 1.99813247135842, 2.00724083056053,
    2.0164337349062, 2.02571394786385, 2.03508435372962, 2.04454796521753,
    2.05410793165065, 2.06376754781173, 2.07353026351874, 2.0833996939983,
    2.09337963113879, 2.10347405571488, 2.11368715068665, 2.12402331568952,
    2.13448718284602, 2.14508363404789, 2.15581781987674, 2.16669518035431,
    2.17772146774029, 2.18890277162636, 2.20024554661128, 2.21175664288416,
    2.22344334009251, 2.23531338492992, 2.24737503294739, 2.25963709517379,
    2.27210899022838, 2.28480080272449, 2.29772334890286, 2.31088825060137,
    2.32430801887113, 2.33799614879653, 2.35196722737914, 2.36623705671729,
    2.38082279517208, 2.39574311978193, 2.41101841390112, 2.42667098493715,
    2.44272531820036, 2.4592083743347, 2.47614993967052, 2.49358304127105,
    2.51154444162669, 2.53007523215985, 2.54922155032478, 2.56903545268184,
    2.58957598670829, 2.61091051848882, 2.63311639363158, 2.65628303757674,
    2.68051464328574, 2.70593365612306, 2.73268535904401, 2.76094400527999,
    2.79092117400193, 2.82287739682644, 2.85713873087322, 2.89412105361341,
    2.93436686720889, 2.97860327988184, 3.02783779176959, 3.08352613200214,
    3.147889289518, 3.2245750520478, 3.32024473383983, 3.44927829856143,
    3.65415288536101, 3.91075795952492 };

  static const real_T c[257] = { 1.0, 0.977101701267673, 0.959879091800108,
    0.9451989534423, 0.932060075959231, 0.919991505039348, 0.908726440052131,
    0.898095921898344, 0.887984660755834, 0.878309655808918, 0.869008688036857,
    0.860033621196332, 0.851346258458678, 0.842915653112205, 0.834716292986884,
    0.826726833946222, 0.818929191603703, 0.811307874312656, 0.803849483170964,
    0.796542330422959, 0.789376143566025, 0.782341832654803, 0.775431304981187,
    0.768637315798486, 0.761953346836795, 0.755373506507096, 0.748892447219157,
    0.742505296340151, 0.736207598126863, 0.729995264561476, 0.72386453346863,
    0.717811932630722, 0.711834248878248, 0.705928501332754, 0.700091918136512,
    0.694321916126117, 0.688616083004672, 0.682972161644995, 0.677388036218774,
    0.671861719897082, 0.66639134390875, 0.660975147776663, 0.655611470579697,
    0.650298743110817, 0.645035480820822, 0.639820277453057, 0.634651799287624,
    0.629528779924837, 0.624450015547027, 0.619414360605834, 0.614420723888914,
    0.609468064925773, 0.604555390697468, 0.599681752619125, 0.594846243767987,
    0.590047996332826, 0.585286179263371, 0.580559996100791, 0.575868682972354,
    0.571211506735253, 0.566587763256165, 0.561996775814525, 0.557437893618766,
    0.552910490425833, 0.548413963255266, 0.543947731190026, 0.539511234256952,
    0.535103932380458, 0.530725304403662, 0.526374847171684, 0.522052074672322,
    0.517756517229756, 0.513487720747327, 0.509245245995748, 0.505028667943468,
    0.500837575126149, 0.49667156905249, 0.492530263643869, 0.488413284705458,
    0.484320269426683, 0.480250865909047, 0.476204732719506, 0.47218153846773,
    0.468180961405694, 0.464202689048174, 0.460246417812843, 0.456311852678716,
    0.452398706861849, 0.448506701507203, 0.444635565395739, 0.440785034665804,
    0.436954852547985, 0.433144769112652, 0.429354541029442, 0.425583931338022,
    0.421832709229496, 0.418100649837848, 0.414387534040891, 0.410693148270188,
    0.407017284329473, 0.403359739221114, 0.399720314980197, 0.396098818515832,
    0.392495061459315, 0.388908860018789, 0.385340034840077, 0.381788410873393,
    0.378253817245619, 0.374736087137891, 0.371235057668239, 0.367750569779032,
    0.364282468129004, 0.360830600989648, 0.357394820145781, 0.353974980800077,
    0.350570941481406, 0.347182563956794, 0.343809713146851, 0.340452257044522,
    0.337110066637006, 0.333783015830718, 0.330470981379163, 0.327173842813601,
    0.323891482376391, 0.320623784956905, 0.317370638029914, 0.314131931596337,
    0.310907558126286, 0.307697412504292, 0.30450139197665, 0.301319396100803,
    0.298151326696685, 0.294997087799962, 0.291856585617095, 0.288729728482183,
    0.285616426815502, 0.282516593083708, 0.279430141761638, 0.276356989295668,
    0.273297054068577, 0.270250256365875, 0.267216518343561, 0.264195763997261,
    0.261187919132721, 0.258192911337619, 0.255210669954662, 0.252241126055942,
    0.249284212418529, 0.246339863501264, 0.24340801542275, 0.240488605940501,
    0.237581574431238, 0.23468686187233, 0.231804410824339, 0.228934165414681,
    0.226076071322381, 0.223230075763918, 0.220396127480152, 0.217574176724331,
    0.214764175251174, 0.211966076307031, 0.209179834621125, 0.206405406397881,
    0.203642749310335, 0.200891822494657, 0.198152586545776, 0.195425003514135,
    0.192709036903589, 0.190004651670465, 0.187311814223801, 0.1846304924268,
    0.181960655599523, 0.179302274522848, 0.176655321443735, 0.174019770081839,
    0.171395595637506, 0.168782774801212, 0.166181285764482, 0.163591108232366,
    0.161012223437511, 0.158444614155925, 0.15588826472448, 0.153343161060263,
    0.150809290681846, 0.148286642732575, 0.145775208005994, 0.143274978973514,
    0.140785949814445, 0.138308116448551, 0.135841476571254, 0.133386029691669,
    0.130941777173644, 0.12850872228, 0.126086870220186, 0.123676228201597,
    0.12127680548479, 0.11888861344291, 0.116511665625611, 0.114145977827839,
    0.111791568163838, 0.109448457146812, 0.107116667774684, 0.104796225622487,
    0.102487158941935, 0.10018949876881, 0.0979032790388625, 0.095628536713009,
    0.093365311912691, 0.0911136480663738, 0.0888735920682759,
    0.0866451944505581, 0.0844285095703535, 0.082223595813203,
    0.0800305158146631, 0.0778493367020961, 0.0756801303589272,
    0.0735229737139814, 0.0713779490588905, 0.0692451443970068,
    0.0671246538277886, 0.065016577971243, 0.0629210244377582, 0.06083810834954,
    0.0587679529209339, 0.0567106901062031, 0.0546664613248891,
    0.0526354182767924, 0.0506177238609479, 0.0486135532158687,
    0.0466230949019305, 0.0446465522512946, 0.0426841449164746,
    0.0407361106559411, 0.0388027074045262, 0.0368842156885674,
    0.0349809414617162, 0.0330932194585786, 0.0312214171919203,
    0.0293659397581334, 0.0275272356696031, 0.0257058040085489,
    0.0239022033057959, 0.0221170627073089, 0.0203510962300445,
    0.0186051212757247, 0.0168800831525432, 0.0151770883079353,
    0.0134974506017399, 0.0118427578579079, 0.0102149714397015,
    0.00861658276939875, 0.00705087547137324, 0.00552240329925101,
    0.00403797259336304, 0.00260907274610216, 0.0012602859304986,
    0.000477467764609386 };

  int32_T exitg1;
  int32_T i;
  do {
    exitg1 = 0;
    model_genrand_uint32_vector(state, u32);
    i = (int32_T)((u32[1] >> 24U) + 1U);
    r = (((real_T)(u32[0] >> 3U) * 1.6777216E+7 + (real_T)((int32_T)u32[1] &
           16777215)) * 2.2204460492503131E-16 - 1.0) * b[i];
    if (fabs(r) <= b[i - 1]) {
      exitg1 = 1;
    } else if (i < 256) {
      real_T x;
      x = model_genrandu(state);
      if ((c[i - 1] - c[i]) * x + c[i] < exp(-0.5 * r * r)) {
        exitg1 = 1;
      }
    } else {
      real_T c_u;
      real_T x;
      do {
        x = model_genrandu(state);
        x = log(x) * 0.273661237329758;
        c_u = model_genrandu(state);
      } while (!(-2.0 * log(c_u) > x * x));

      if (r < 0.0) {
        r = x - 3.65415288536101;
      } else {
        r = 3.65415288536101 - x;
      }

      exitg1 = 1;
    }
  } while (exitg1 == 0);

  return r;
}

/* Function for MATLAB Function: '<Root>/MATLAB Function1' */
static void model_randn(real_T r[40])
{
  int32_T k;
  for (k = 0; k < 40; k++) {
    r[k] = model_eml_rand_mt19937ar(model_DW.state);
  }
}

/* Function for MATLAB Function: '<Root>/MATLAB Function1' */
static void model_sum(const real_T x[40], real_T y[20])
{
  int32_T xi;
  for (xi = 0; xi < 20; xi++) {
    int32_T xpageoffset;
    xpageoffset = xi << 1;
    y[xi] = x[xpageoffset + 1] + x[xpageoffset];
  }
}

/* Function for MATLAB Function: '<Root>/MATLAB Function1' */
static void model_sqrt(real_T x[20])
{
  int32_T k;
  for (k = 0; k <= 18; k += 2) {
    __m128d tmp;
    tmp = _mm_loadu_pd(&x[k]);
    _mm_storeu_pd(&x[k], _mm_sqrt_pd(tmp));
  }
}

/* Function for MATLAB Function: '<Root>/MATLAB Function1' */
static void model_power(const real_T a[2], real_T y[2])
{
  y[0] = a[0] * a[0];
  y[1] = a[1] * a[1];
}

/* Function for MATLAB Function: '<Root>/MATLAB Function1' */
static int32_T model_combineVectorElements(const boolean_T x[20])
{
  int32_T k;
  int32_T y;
  y = x[0];
  for (k = 0; k < 19; k++) {
    y += x[k + 1];
  }

  return y;
}

/* Function for MATLAB Function: '<Root>/MATLAB Function1' */
static void model_repmat(const real_T a_data[], const int32_T a_size[2], real_T
  b_data[], int32_T b_size[2])
{
  int32_T jcol;
  b_size[0] = 2;
  b_size[1] = (int8_T)a_size[1];
  for (jcol = 0; jcol < a_size[1]; jcol++) {
    real_T b_data_tmp;
    int32_T ibmat;
    ibmat = jcol << 1;
    b_data_tmp = a_data[jcol];
    b_data[ibmat] = b_data_tmp;
    b_data[ibmat + 1] = b_data_tmp;
  }
}

static void model_binary_expand_op(real_T in1[40], const int8_T in2_data[],
  const int8_T in3_data[], const int32_T in3_size[2], const real_T in4[20])
{
  real_T tmp_data[40];
  real_T tmp_data_0[40];
  real_T in4_data[20];
  int32_T in4_size[2];
  int32_T tmp_size[2];
  int32_T aux_0_1;
  int32_T aux_1_1;
  int32_T in4_data_tmp;
  int32_T in4_data_tmp_0;
  int32_T loop_ub;
  int32_T stride_0_1;
  int32_T stride_1_1;
  int32_T tmp;

  /* MATLAB Function: '<Root>/MATLAB Function1' */
  in4_size[0] = 1;
  in4_size[1] = in3_size[1];
  loop_ub = in3_size[1];
  for (in4_data_tmp = 0; in4_data_tmp < loop_ub; in4_data_tmp++) {
    in4_data[in4_data_tmp] = in4[in3_data[in4_data_tmp] - 1];
  }

  model_repmat(in4_data, in4_size, tmp_data, tmp_size);
  in4_data_tmp_0 = tmp_size[1] == 1 ? in3_size[1] : tmp_size[1];
  stride_0_1 = (in3_size[1] != 1);
  stride_1_1 = (tmp_size[1] != 1);
  aux_0_1 = 0;
  aux_1_1 = 0;
  loop_ub = tmp_size[1] == 1 ? in3_size[1] : tmp_size[1];
  for (in4_data_tmp = 0; in4_data_tmp < loop_ub; in4_data_tmp++) {
    tmp = (in3_data[aux_0_1] - 1) << 1;
    tmp_data_0[in4_data_tmp << 1] = in1[tmp] * 7.0 / tmp_data[aux_1_1 << 1];
    tmp_data_0[1 + (in4_data_tmp << 1)] = in1[tmp + 1] * 7.0 / tmp_data[(aux_1_1
      << 1) + 1];
    aux_1_1 += stride_1_1;
    aux_0_1 += stride_0_1;
  }

  for (in4_data_tmp = 0; in4_data_tmp < in4_data_tmp_0; in4_data_tmp++) {
    tmp = (in2_data[in4_data_tmp] - 1) << 1;
    in1[tmp] = tmp_data_0[in4_data_tmp << 1];
    in1[tmp + 1] = tmp_data_0[(in4_data_tmp << 1) + 1];
  }

  /* End of MATLAB Function: '<Root>/MATLAB Function1' */
}

/* Model output function */
void model_output(void)
{
  __m128d tmp_1;
  __m128d tmp_3;
  real_T rtb_TmpSignalConversionAtSFunctionInport1[80];
  real_T p_rel[40];
  real_T v_rel[40];
  real_T vel_command[40];
  real_T vel_fric[40];
  real_T vel_obs[40];
  real_T vel_rep[40];
  real_T vel_wall[40];
  real_T y[40];
  real_T dist[20];
  real_T v_rel_norm[20];
  real_T tmp_0[2];
  real_T v_wall_virtual[2];
  real_T x[2];
  real_T v_wall_max;
  int32_T f_data[20];
  int32_T i;
  int32_T p_rel_tmp;
  int32_T v_wall_virtual_tmp;
  int32_T v_wall_virtual_tmp_0;
  int32_T vel_wall_tmp;
  uint32_T tmp;
  int8_T c_data[20];
  int8_T d_data[20];
  int8_T e_data[20];
  int8_T neig_list_data[20];
  int8_T neig_list_data_0[20];
  int8_T unit[4];
  boolean_T b_data[20];
  static const int8_T spheres[9] = { 0, 0, 5, 50, 10, 10, -50, 20, 2 };

  int32_T c_size[2];
  int32_T dist_size[2];
  int32_T tmp_size[2];

  /* S-Function (sldrtpo): '<S2>/Packet Output' incorporates:
   *  Constant: '<S2>/Constant4'
   *  Constant: '<S2>/Constant5'
   */
  /* S-Function Block: <S2>/Packet Output */

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

      {
        int_T i1;
        uint8_T *y0 = &model_B.PacketInput[0];
        for (i1=0; i1 < 8; i1++) {
          y0[i1] = *indp.p_uint8_T++;
        }
      }
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
    /* Output data type - real32_T, size - 2 */
    {
      MW_outputPortWidth = 2 * sizeof(real32_T);
      memcpy((uint8_T*)&model_B.ByteUnpack[0], (uint8_T*)&model_B.PacketInput[0]
             + MW_inputPortOffset, MW_outputPortWidth);
    }
  }

  /* MATLAB Function: '<Root>/MATLAB Function1' */
  if (!model_DW.velocity_not_empty) {
    model_DW.velocity_not_empty = true;
    model_randn(model_DW.position);
    for (v_wall_virtual_tmp = 0; v_wall_virtual_tmp <= 38; v_wall_virtual_tmp +=
         2) {
      tmp_3 = _mm_loadu_pd(&model_DW.position[v_wall_virtual_tmp]);
      _mm_storeu_pd(&model_DW.position[v_wall_virtual_tmp], _mm_sub_pd
                    (_mm_mul_pd(tmp_3, _mm_set1_pd(20.0)), _mm_set1_pd(10.0)));
    }
  }

  memset(&vel_rep[0], 0, 40U * sizeof(real_T));
  memset(&vel_fric[0], 0, 40U * sizeof(real_T));
  memset(&vel_wall[0], 0, 40U * sizeof(real_T));
  memset(&vel_obs[0], 0, 40U * sizeof(real_T));
  memset(&vel_command[0], 0, 40U * sizeof(real_T));
  unit[1] = 0;
  unit[2] = 0;
  unit[0] = 1;
  unit[3] = 1;
  for (v_wall_virtual_tmp = 0; v_wall_virtual_tmp < 20; v_wall_virtual_tmp++) {
    real_T tmp_5;
    real_T v_wall_max_0;
    real_T v_wall_max_tmp;
    real_T vel_ab;
    int32_T d_size_idx_1;
    int32_T f_size_idx_1;
    for (v_wall_virtual_tmp_0 = 0; v_wall_virtual_tmp_0 < 20;
         v_wall_virtual_tmp_0++) {
      i = v_wall_virtual_tmp_0 << 1;
      p_rel_tmp = v_wall_virtual_tmp << 1;
      p_rel[i] = model_DW.position[i] - model_DW.position[p_rel_tmp];
      p_rel[i + 1] = model_DW.position[i + 1] - model_DW.position[p_rel_tmp + 1];
    }

    for (i = 0; i <= 38; i += 2) {
      tmp_3 = _mm_loadu_pd(&p_rel[i]);
      _mm_storeu_pd(&y[i], _mm_mul_pd(tmp_3, tmp_3));
    }

    model_sum(y, dist);
    model_sqrt(dist);
    i = 0;
    for (v_wall_virtual_tmp_0 = 0; v_wall_virtual_tmp_0 < 20;
         v_wall_virtual_tmp_0++) {
      if (dist[v_wall_virtual_tmp_0] != 0.0) {
        i++;
      }
    }

    d_size_idx_1 = i;
    i = 0;
    for (v_wall_virtual_tmp_0 = 0; v_wall_virtual_tmp_0 < 20;
         v_wall_virtual_tmp_0++) {
      if (dist[v_wall_virtual_tmp_0] != 0.0) {
        d_data[i] = (int8_T)(v_wall_virtual_tmp_0 + 1);
        i++;
      }
    }

    p_rel_tmp = (d_size_idx_1 / 16) << 4;
    vel_wall_tmp = p_rel_tmp - 16;
    for (v_wall_virtual_tmp_0 = 0; v_wall_virtual_tmp_0 <= vel_wall_tmp;
         v_wall_virtual_tmp_0 += 16) {
      __m128i tmp_2;
      __m128i tmp_4;
      tmp_2 = _mm_loadu_si128((const __m128i *)&d_data[v_wall_virtual_tmp_0]);
      tmp_4 = _mm_set1_epi8(1);
      _mm_storeu_si128((__m128i *)&neig_list_data[v_wall_virtual_tmp_0],
                       _mm_add_epi8(_mm_sub_epi8(tmp_2, tmp_4), tmp_4));
    }

    if (p_rel_tmp <= d_size_idx_1 - 1) {
      memcpy(&neig_list_data[p_rel_tmp], &d_data[p_rel_tmp], (d_size_idx_1 -
              p_rel_tmp) * sizeof(int8_T));
    }

    for (v_wall_virtual_tmp_0 = 0; v_wall_virtual_tmp_0 < d_size_idx_1;
         v_wall_virtual_tmp_0++) {
      b_data[v_wall_virtual_tmp_0] = (dist[neig_list_data[v_wall_virtual_tmp_0]
        - 1] < 20.0);
    }

    v_wall_virtual_tmp_0 = 0;
    for (vel_wall_tmp = 0; vel_wall_tmp < d_size_idx_1; vel_wall_tmp++) {
      if (b_data[vel_wall_tmp]) {
        v_wall_virtual_tmp_0++;
      }
    }

    f_size_idx_1 = v_wall_virtual_tmp_0;
    v_wall_virtual_tmp_0 = 0;
    for (vel_wall_tmp = 0; vel_wall_tmp < d_size_idx_1; vel_wall_tmp++) {
      if (b_data[vel_wall_tmp]) {
        f_data[v_wall_virtual_tmp_0] = vel_wall_tmp + 1;
        v_wall_virtual_tmp_0++;
      }
    }

    for (v_wall_virtual_tmp_0 = 0; v_wall_virtual_tmp_0 < f_size_idx_1;
         v_wall_virtual_tmp_0++) {
      neig_list_data_0[v_wall_virtual_tmp_0] =
        neig_list_data[f_data[v_wall_virtual_tmp_0] - 1];
    }

    if (f_size_idx_1 - 1 >= 0) {
      memcpy(&neig_list_data[0], &neig_list_data_0[0], f_size_idx_1 * sizeof
             (int8_T));
    }

    if (f_size_idx_1 != 0) {
      for (v_wall_virtual_tmp_0 = 0; v_wall_virtual_tmp_0 < 20;
           v_wall_virtual_tmp_0++) {
        i = v_wall_virtual_tmp_0 << 1;
        p_rel_tmp = v_wall_virtual_tmp << 1;
        v_rel[i] = model_DW.velocity[i] - model_DW.velocity[p_rel_tmp];
        v_rel[i + 1] = model_DW.velocity[i + 1] - model_DW.velocity[p_rel_tmp +
          1];
      }

      for (i = 0; i <= 38; i += 2) {
        tmp_3 = _mm_loadu_pd(&v_rel[i]);
        _mm_storeu_pd(&y[i], _mm_mul_pd(tmp_3, tmp_3));
      }

      model_sum(y, v_rel_norm);
      model_sqrt(v_rel_norm);
      for (v_wall_virtual_tmp_0 = 0; v_wall_virtual_tmp_0 < 20;
           v_wall_virtual_tmp_0++) {
        v_wall_max = dist[v_wall_virtual_tmp_0];
        i = v_wall_virtual_tmp_0 << 1;
        y[i] = -p_rel[i] / v_wall_max;
        y[i + 1] = -p_rel[i + 1] / v_wall_max;
      }

      memcpy(&p_rel[0], &y[0], 40U * sizeof(real_T));
      for (v_wall_virtual_tmp_0 = 0; v_wall_virtual_tmp_0 < 20;
           v_wall_virtual_tmp_0++) {
        v_wall_max = v_rel_norm[v_wall_virtual_tmp_0];
        i = v_wall_virtual_tmp_0 << 1;
        y[i] = -v_rel[i] / v_wall_max;
        y[i + 1] = -v_rel[i + 1] / v_wall_max;
      }

      memcpy(&v_rel[0], &y[0], 40U * sizeof(real_T));
      for (i = 0; i < f_size_idx_1; i++) {
        v_wall_virtual_tmp_0 = neig_list_data[i] - 1;
        v_wall_max_tmp = dist[v_wall_virtual_tmp_0];
        if (v_wall_max_tmp < 20.0) {
          vel_ab = (20.0 - v_wall_max_tmp) * 0.3;
          p_rel_tmp = v_wall_virtual_tmp << 1;
          vel_wall_tmp = (neig_list_data[i] - 1) << 1;
          vel_rep[p_rel_tmp] += p_rel[vel_wall_tmp] * vel_ab;
          p_rel_tmp = (v_wall_virtual_tmp << 1) + 1;
          vel_rep[p_rel_tmp] += p_rel[vel_wall_tmp + 1] * vel_ab;
        } else {
          vel_ab = (v_wall_max_tmp - 20.0) * 0.3;
          p_rel_tmp = v_wall_virtual_tmp << 1;
          vel_wall_tmp = v_wall_virtual_tmp_0 << 1;
          vel_rep[p_rel_tmp] += -p_rel[vel_wall_tmp] * vel_ab;
          p_rel_tmp = (v_wall_virtual_tmp << 1) + 1;
          vel_rep[p_rel_tmp] += -p_rel[vel_wall_tmp + 1] * vel_ab;
        }

        if (v_wall_max_tmp - 85.3 < 0.0) {
          vel_ab = 0.0;
        } else {
          vel_ab = (dist[v_wall_virtual_tmp_0] - 85.3) * 3.2;
          if ((vel_ab > 0.0) && (vel_ab < 1.3)) {
          } else {
            vel_ab = sqrt((dist[v_wall_virtual_tmp_0] - 85.3) * 8.32 - 1.69);
          }
        }

        if (vel_ab < 0.63) {
          vel_ab = 0.63;
        }

        v_wall_max_tmp = v_rel_norm[v_wall_virtual_tmp_0];
        if (v_wall_max_tmp > vel_ab) {
          vel_ab = (v_wall_max_tmp - vel_ab) * 0.05;
          v_wall_virtual_tmp_0 = v_wall_virtual_tmp << 1;
          p_rel_tmp = (neig_list_data[i] - 1) << 1;
          vel_fric[v_wall_virtual_tmp_0] += v_rel[p_rel_tmp] * vel_ab;
          v_wall_virtual_tmp_0 = (v_wall_virtual_tmp << 1) + 1;
          vel_fric[v_wall_virtual_tmp_0] += v_rel[p_rel_tmp + 1] * vel_ab;
        }
      }
    }

    for (i = 0; i < 2; i++) {
      p_rel_tmp = v_wall_virtual_tmp << 1;
      vel_wall_tmp = p_rel_tmp + i;
      v_wall_max = fabs(model_DW.position[vel_wall_tmp] - -100.0);
      v_wall_virtual_tmp_0 = i << 1;
      v_wall_virtual[0] = (real_T)unit[v_wall_virtual_tmp_0] * 1.6;
      v_wall_virtual[1] = (real_T)unit[v_wall_virtual_tmp_0 + 1] * 1.6;
      v_wall_max_tmp = model_DW.velocity[p_rel_tmp];
      tmp_0[0] = v_wall_max_tmp - v_wall_virtual[0];
      v_wall_virtual_tmp_0 = (v_wall_virtual_tmp << 1) + 1;
      v_wall_max_0 = model_DW.velocity[v_wall_virtual_tmp_0];
      tmp_0[1] = v_wall_max_0 - v_wall_virtual[1];
      model_power(tmp_0, x);
      vel_ab = sqrt(x[0] + x[1]);
      if (v_wall_max - 0.1 < 0.0) {
        v_wall_max = 0.0;
      } else {
        tmp_5 = (v_wall_max - 0.1) * 0.55;
        if ((tmp_5 > 0.0) && (tmp_5 < 5.49090909090909)) {
          v_wall_max = (v_wall_max - 0.1) * 0.55;
        } else {
          v_wall_max = sqrt((v_wall_max - 0.1) * 6.04 - 30.150082644628096);
        }
      }

      if (v_wall_max < 0.0) {
        v_wall_max = 0.0;
      }

      if (vel_ab > v_wall_max) {
        v_wall_max = vel_ab - v_wall_max;
        vel_wall[p_rel_tmp] += (v_wall_virtual[0] - v_wall_max_tmp) * v_wall_max
          / vel_ab;
        vel_wall[v_wall_virtual_tmp_0] += (v_wall_virtual[1] - v_wall_max_0) *
          v_wall_max / vel_ab;
      }

      v_wall_max = fabs(model_DW.position[vel_wall_tmp] - 100.0);
      vel_wall_tmp = i << 1;
      tmp_0[0] = v_wall_max_tmp - (-((real_T)unit[vel_wall_tmp] * 1.6));
      tmp_0[1] = v_wall_max_0 - (-((real_T)unit[vel_wall_tmp + 1] * 1.6));
      model_power(tmp_0, x);
      vel_ab = sqrt(x[0] + x[1]);
      if (v_wall_max - 0.1 < 0.0) {
        v_wall_max = 0.0;
      } else {
        tmp_5 = (v_wall_max - 0.1) * 0.55;
        if ((tmp_5 > 0.0) && (tmp_5 < 5.49090909090909)) {
          v_wall_max = (v_wall_max - 0.1) * 0.55;
        } else {
          v_wall_max = sqrt((v_wall_max - 0.1) * 6.04 - 30.150082644628096);
        }
      }

      if (v_wall_max < 0.0) {
        v_wall_max = 0.0;
      }

      if (vel_ab > v_wall_max) {
        v_wall_max = vel_ab - v_wall_max;
        vel_wall[p_rel_tmp] += (-((real_T)unit[vel_wall_tmp] * 1.6) -
          v_wall_max_tmp) * v_wall_max / vel_ab;
        vel_wall[v_wall_virtual_tmp_0] += (-((real_T)unit[vel_wall_tmp + 1] *
          1.6) - v_wall_max_0) * v_wall_max / vel_ab;
      }
    }

    for (i = 0; i < 3; i++) {
      real_T v_wall_virtual_0;
      v_wall_virtual_tmp_0 = v_wall_virtual_tmp << 1;
      v_wall_virtual[0] = model_DW.position[v_wall_virtual_tmp_0] - (real_T)
        spheres[3 * i];
      p_rel_tmp = (v_wall_virtual_tmp << 1) + 1;
      v_wall_virtual[1] = model_DW.position[p_rel_tmp] - (real_T)spheres[3 * i +
        1];
      model_power(v_wall_virtual, x);
      v_wall_max_tmp = spheres[3 * i + 2];
      v_wall_max = sqrt(x[0] + x[1]) - v_wall_max_tmp;
      v_wall_max_0 = v_wall_max_tmp + v_wall_max;
      v_wall_virtual_0 = v_wall_virtual[0] / v_wall_max_0 * 1.6;
      v_wall_max_tmp = model_DW.velocity[v_wall_virtual_tmp_0];
      tmp_0[0] = v_wall_max_tmp - v_wall_virtual_0;
      v_wall_virtual[0] = v_wall_virtual_0;
      v_wall_virtual_0 = v_wall_virtual[1] / v_wall_max_0 * 1.6;
      v_wall_max_0 = model_DW.velocity[p_rel_tmp];
      tmp_0[1] = v_wall_max_0 - v_wall_virtual_0;
      model_power(tmp_0, x);
      vel_ab = sqrt(x[0] + x[1]);
      if (v_wall_max - 0.1 < 0.0) {
        v_wall_max = 0.0;
      } else {
        tmp_5 = (v_wall_max - 0.1) * 0.55;
        if ((tmp_5 > 0.0) && (tmp_5 < 5.49090909090909)) {
          v_wall_max = (v_wall_max - 0.1) * 0.55;
        } else {
          v_wall_max = sqrt((v_wall_max - 0.1) * 6.04 - 30.150082644628096);
        }
      }

      if (v_wall_max < 0.0) {
        v_wall_max = 0.0;
      }

      if (vel_ab > v_wall_max) {
        v_wall_max = vel_ab - v_wall_max;
        vel_obs[v_wall_virtual_tmp_0] += (v_wall_virtual[0] - v_wall_max_tmp) *
          v_wall_max / vel_ab;
        vel_obs[p_rel_tmp] += (v_wall_virtual_0 - v_wall_max_0) * v_wall_max /
          vel_ab;
      }
    }

    v_wall_virtual_tmp_0 = v_wall_virtual_tmp << 1;
    vel_command[v_wall_virtual_tmp_0] = ((vel_rep[v_wall_virtual_tmp_0] +
      vel_fric[v_wall_virtual_tmp_0]) + vel_obs[v_wall_virtual_tmp_0]) +
      vel_wall[v_wall_virtual_tmp_0];
    i = (v_wall_virtual_tmp << 1) + 1;
    vel_command[i] = ((vel_rep[i] + vel_fric[i]) + vel_obs[i]) + vel_wall[i];
    model_power(&model_DW.velocity[v_wall_virtual_tmp_0], x);
    vel_ab = sqrt(x[0] + x[1]);
    if (vel_ab > 0.0) {
      vel_command[v_wall_virtual_tmp_0] +=
        model_DW.velocity[v_wall_virtual_tmp_0] * 16.0 / vel_ab;
      vel_command[i] += model_DW.velocity[i] * 16.0 / vel_ab;
    }
  }

  model_randn(vel_rep);
  for (v_wall_virtual_tmp = 0; v_wall_virtual_tmp <= 38; v_wall_virtual_tmp += 2)
  {
    /* MATLAB Function: '<Root>/MATLAB Function1' */
    tmp_3 = _mm_loadu_pd(&vel_rep[v_wall_virtual_tmp]);
    tmp_1 = _mm_loadu_pd(&vel_command[v_wall_virtual_tmp]);
    tmp_3 = _mm_add_pd(_mm_mul_pd(_mm_set1_pd(0.0), tmp_3), tmp_1);
    _mm_storeu_pd(&y[v_wall_virtual_tmp], _mm_mul_pd(tmp_3, tmp_3));
    _mm_storeu_pd(&vel_command[v_wall_virtual_tmp], tmp_3);
  }

  /* MATLAB Function: '<Root>/MATLAB Function1' */
  model_sum(y, dist);
  model_sqrt(dist);
  for (v_wall_virtual_tmp = 0; v_wall_virtual_tmp < 20; v_wall_virtual_tmp++) {
    b_data[v_wall_virtual_tmp] = (dist[v_wall_virtual_tmp] > 7.0);
  }

  if (model_combineVectorElements(b_data) > 0) {
    v_wall_virtual_tmp = 0;
    for (i = 0; i < 20; i++) {
      if (dist[i] > 7.0) {
        v_wall_virtual_tmp++;
      }
    }

    c_size[0] = 1;
    c_size[1] = v_wall_virtual_tmp;
    v_wall_virtual_tmp = 0;
    for (i = 0; i < 20; i++) {
      if (dist[i] > 7.0) {
        c_data[v_wall_virtual_tmp] = (int8_T)(i + 1);
        v_wall_virtual_tmp++;
      }
    }

    v_wall_virtual_tmp = 0;
    for (i = 0; i < 20; i++) {
      if (dist[i] > 7.0) {
        e_data[v_wall_virtual_tmp] = (int8_T)(i + 1);
        v_wall_virtual_tmp++;
      }
    }

    dist_size[0] = 1;
    dist_size[1] = c_size[1];
    i = c_size[1];
    for (v_wall_virtual_tmp = 0; v_wall_virtual_tmp < i; v_wall_virtual_tmp++) {
      v_rel_norm[v_wall_virtual_tmp] = dist[c_data[v_wall_virtual_tmp] - 1];
    }

    model_repmat(v_rel_norm, dist_size, vel_rep, tmp_size);
    if (c_size[1] == tmp_size[1]) {
      dist_size[0] = 1;
      dist_size[1] = c_size[1];
      i = c_size[1];
      for (v_wall_virtual_tmp = 0; v_wall_virtual_tmp < i; v_wall_virtual_tmp++)
      {
        v_rel_norm[v_wall_virtual_tmp] = dist[c_data[v_wall_virtual_tmp] - 1];
      }

      model_repmat(v_rel_norm, dist_size, vel_rep, tmp_size);
      p_rel_tmp = c_size[1];
      i = c_size[1];
      for (v_wall_virtual_tmp = 0; v_wall_virtual_tmp < i; v_wall_virtual_tmp++)
      {
        v_wall_virtual_tmp_0 = (c_data[v_wall_virtual_tmp] - 1) << 1;
        vel_wall_tmp = v_wall_virtual_tmp << 1;
        vel_fric[vel_wall_tmp] = vel_command[v_wall_virtual_tmp_0] * 7.0 /
          vel_rep[vel_wall_tmp];
        vel_wall_tmp = (v_wall_virtual_tmp << 1) + 1;
        vel_fric[vel_wall_tmp] = vel_command[v_wall_virtual_tmp_0 + 1] * 7.0 /
          vel_rep[vel_wall_tmp];
      }

      for (v_wall_virtual_tmp = 0; v_wall_virtual_tmp < p_rel_tmp;
           v_wall_virtual_tmp++) {
        v_wall_virtual_tmp_0 = (e_data[v_wall_virtual_tmp] - 1) << 1;
        vel_command[v_wall_virtual_tmp_0] = vel_fric[v_wall_virtual_tmp << 1];
        vel_command[v_wall_virtual_tmp_0 + 1] = vel_fric[(v_wall_virtual_tmp <<
          1) + 1];
      }
    } else {
      model_binary_expand_op(vel_command, e_data, c_data, c_size, dist);
    }
  }

  memcpy(&model_DW.velocity[0], &vel_command[0], 40U * sizeof(real_T));
  model_DW.velocity[0] = model_B.ByteUnpack[0];
  model_DW.velocity[1] = model_B.ByteUnpack[1];
  for (i = 0; i <= 38; i += 2) {
    /* MATLAB Function: '<Root>/MATLAB Function1' */
    tmp_3 = _mm_loadu_pd(&model_DW.velocity[i]);
    tmp_1 = _mm_loadu_pd(&model_DW.position[i]);
    _mm_storeu_pd(&model_DW.position[i], _mm_add_pd(_mm_mul_pd(tmp_3,
      _mm_set1_pd(0.01)), tmp_1));
    tmp_3 = _mm_loadu_pd(&model_DW.position[i]);
    _mm_storeu_pd(&model_B.position_out[i], tmp_3);

    /* SignalConversion generated from: '<S3>/ SFunction ' incorporates:
     *  MATLAB Function: '<Root>/MATLAB Function1'
     *  MATLAB Function: '<S2>/MATLAB Function'
     */
    tmp_3 = _mm_loadu_pd(&model_B.position_out[i]);
    _mm_storeu_pd(&rtb_TmpSignalConversionAtSFunctionInport1[i], tmp_3);

    /* MATLAB Function: '<Root>/MATLAB Function1' */
    tmp_3 = _mm_loadu_pd(&vel_command[i]);

    /* SignalConversion generated from: '<S3>/ SFunction ' incorporates:
     *  MATLAB Function: '<Root>/MATLAB Function1'
     *  MATLAB Function: '<S2>/MATLAB Function'
     */
    _mm_storeu_pd(&rtb_TmpSignalConversionAtSFunctionInport1[i + 40], tmp_3);
  }

  for (i = 0; i < 6; i++) {
    /* MATLAB Function: '<S2>/MATLAB Function' incorporates:
     *  SignalConversion generated from: '<S3>/ SFunction '
     */
    model_DW.iteration++;
    v_wall_max = rtb_TmpSignalConversionAtSFunctionInport1[(int32_T)
      model_DW.iteration - 1];
    if (model_DW.iteration >= 80.0) {
      model_DW.iteration = 0.0;
    }

    /* DataTypeConversion: '<S2>/Data Type Conversion1' */
    model_B.DataTypeConversion1[i] = (real32_T)v_wall_max;
  }

  /* S-Function (any2byte_svd): '<S2>/Byte Pack' */

  /* Pack: <S2>/Byte Pack */
  {
    uint32_T MW_outputPortOffset = 0;
    uint32_T MW_inputPortWidth = 0;
    uint32_T MW_remainder1 = 0;

    /* Packed output data type - uint8_T */
    /* Packing the values of Input 1 */
    /* Input data type - real32_T, size - 6 */
    {
      MW_inputPortWidth = 6 * sizeof(real32_T);
      memcpy((uint8_T*)((uint8_T*)&model_B.BytePack[0] + MW_outputPortOffset),
             (uint8_T*)&model_B.DataTypeConversion1[0], MW_inputPortWidth);
    }
  }

  /* Sum: '<S2>/Sum of Elements' */
  tmp = 0U;
  for (i = 0; i < 24; i++) {
    /* Sum: '<S2>/Sum of Elements' incorporates:
     *  DataTypeConversion: '<S2>/Data Type Conversion2'
     */
    tmp += model_B.BytePack[i];
  }

  /* Sum: '<S2>/Sum of Elements' */
  model_B.SumofElements = tmp;

  /* S-Function (any2byte_svd): '<S2>/Byte Pack1' */

  /* Pack: <S2>/Byte Pack1 */
  {
    uint32_T MW_outputPortOffset = 0;
    uint32_T MW_inputPortWidth = 0;
    uint32_T MW_remainder1 = 0;

    /* Packed output data type - uint8_T */
    /* Packing the values of Input 1 */
    /* Input data type - uint32_T, size - 1 */
    {
      MW_inputPortWidth = 1 * sizeof(uint32_T);
      memcpy((uint8_T*)((uint8_T*)&model_B.BytePack1[0] + MW_outputPortOffset),
             (uint8_T*)&model_B.SumofElements, MW_inputPortWidth);
    }
  }
}

/* Model update function */
void model_update(void)
{
  /* Update for S-Function (sldrtpo): '<S2>/Packet Output' incorporates:
   *  Constant: '<S2>/Constant4'
   *  Constant: '<S2>/Constant5'
   */

  /* S-Function Block: <S2>/Packet Output */
  {
    uint8_T outdata[32U];
    RTWin_ANYTYPEPTR outdp;
    outdp.p_uint8_T = outdata;

    {
      uint8_T pktout = model_P.Constant4_Value;
      *outdp.p_uint8_T++ = pktout;
    }

    {
      uint8_T pktout = model_P.Constant4_Value;
      *outdp.p_uint8_T++ = pktout;
    }

    {
      int_T i1;
      const uint8_T *u0 = &model_B.BytePack[0];
      for (i1=0; i1 < 24; i1++) {
        {
          uint8_T pktout = u0[i1];
          *outdp.p_uint8_T++ = pktout;
        }
      }

      {
        uint8_T pktout = model_B.BytePack1[0];
        *outdp.p_uint8_T++ = pktout;
      }

      {
        uint8_T pktout = model_B.BytePack1[1];
        *outdp.p_uint8_T++ = pktout;
      }

      {
        uint8_T pktout = model_B.BytePack1[2];
        *outdp.p_uint8_T++ = pktout;
      }

      {
        uint8_T pktout = model_B.BytePack1[3];
        *outdp.p_uint8_T++ = pktout;
      }

      {
        uint8_T pktout = model_P.Constant5_Value;
        *outdp.p_uint8_T++ = pktout;
      }

      {
        uint8_T pktout = model_P.Constant5_Value;
        *outdp.p_uint8_T++ = pktout;
      }
    }

    RTBIO_DriverIO(0, STREAMOUTPUT, IOWRITE, 32U, &model_P.PacketOutput_PacketID,
                   (double*) outdata, NULL);
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
}

/* Model initialize function */
void model_initialize(void)
{
  /* Start for S-Function (sldrtpo): '<S2>/Packet Output' incorporates:
   *  Constant: '<S2>/Constant4'
   *  Constant: '<S2>/Constant5'
   */

  /* S-Function Block: <S2>/Packet Output */
  /* no initial value should be set */
  {
    int32_T i;
    static const uint32_T tmp[625] = { 5489U, 1301868182U, 2938499221U,
      2950281878U, 1875628136U, 751856242U, 944701696U, 2243192071U, 694061057U,
      219885934U, 2066767472U, 3182869408U, 485472502U, 2336857883U, 1071588843U,
      3418470598U, 951210697U, 3693558366U, 2923482051U, 1793174584U,
      2982310801U, 1586906132U, 1951078751U, 1808158765U, 1733897588U,
      431328322U, 4202539044U, 530658942U, 1714810322U, 3025256284U, 3342585396U,
      1937033938U, 2640572511U, 1654299090U, 3692403553U, 4233871309U,
      3497650794U, 862629010U, 2943236032U, 2426458545U, 1603307207U,
      1133453895U, 3099196360U, 2208657629U, 2747653927U, 931059398U, 761573964U,
      3157853227U, 785880413U, 730313442U, 124945756U, 2937117055U, 3295982469U,
      1724353043U, 3021675344U, 3884886417U, 4010150098U, 4056961966U,
      699635835U, 2681338818U, 1339167484U, 720757518U, 2800161476U, 2376097373U,
      1532957371U, 3902664099U, 1238982754U, 3725394514U, 3449176889U,
      3570962471U, 4287636090U, 4087307012U, 3603343627U, 202242161U,
      2995682783U, 1620962684U, 3704723357U, 371613603U, 2814834333U,
      2111005706U, 624778151U, 2094172212U, 4284947003U, 1211977835U, 991917094U,
      1570449747U, 2962370480U, 1259410321U, 170182696U, 146300961U, 2836829791U,
      619452428U, 2723670296U, 1881399711U, 1161269684U, 1675188680U,
      4132175277U, 780088327U, 3409462821U, 1036518241U, 1834958505U,
      3048448173U, 161811569U, 618488316U, 44795092U, 3918322701U, 1924681712U,
      3239478144U, 383254043U, 4042306580U, 2146983041U, 3992780527U,
      3518029708U, 3545545436U, 3901231469U, 1896136409U, 2028528556U,
      2339662006U, 501326714U, 2060962201U, 2502746480U, 561575027U, 581893337U,
      3393774360U, 1778912547U, 3626131687U, 2175155826U, 319853231U, 986875531U,
      819755096U, 2915734330U, 2688355739U, 3482074849U, 2736559U, 2296975761U,
      1029741190U, 2876812646U, 690154749U, 579200347U, 4027461746U, 1285330465U,
      2701024045U, 4117700889U, 759495121U, 3332270341U, 2313004527U,
      2277067795U, 4131855432U, 2722057515U, 1264804546U, 3848622725U,
      2211267957U, 4100593547U, 959123777U, 2130745407U, 3194437393U, 486673947U,
      1377371204U, 17472727U, 352317554U, 3955548058U, 159652094U, 1232063192U,
      3835177280U, 49423123U, 3083993636U, 733092U, 2120519771U, 2573409834U,
      1112952433U, 3239502554U, 761045320U, 1087580692U, 2540165110U, 641058802U,
      1792435497U, 2261799288U, 1579184083U, 627146892U, 2165744623U,
      2200142389U, 2167590760U, 2381418376U, 1793358889U, 3081659520U,
      1663384067U, 2009658756U, 2689600308U, 739136266U, 2304581039U,
      3529067263U, 591360555U, 525209271U, 3131882996U, 294230224U, 2076220115U,
      3113580446U, 1245621585U, 1386885462U, 3203270426U, 123512128U, 12350217U,
      354956375U, 4282398238U, 3356876605U, 3888857667U, 157639694U, 2616064085U,
      1563068963U, 2762125883U, 4045394511U, 4180452559U, 3294769488U,
      1684529556U, 1002945951U, 3181438866U, 22506664U, 691783457U, 2685221343U,
      171579916U, 3878728600U, 2475806724U, 2030324028U, 3331164912U,
      1708711359U, 1970023127U, 2859691344U, 2588476477U, 2748146879U,
      136111222U, 2967685492U, 909517429U, 2835297809U, 3206906216U, 3186870716U,
      341264097U, 2542035121U, 3353277068U, 548223577U, 3170936588U, 1678403446U,
      297435620U, 2337555430U, 466603495U, 1132321815U, 1208589219U, 696392160U,
      894244439U, 2562678859U, 470224582U, 3306867480U, 201364898U, 2075966438U,
      1767227936U, 2929737987U, 3674877796U, 2654196643U, 3692734598U,
      3528895099U, 2796780123U, 3048728353U, 842329300U, 191554730U, 2922459673U,
      3489020079U, 3979110629U, 1022523848U, 2202932467U, 3583655201U,
      3565113719U, 587085778U, 4176046313U, 3013713762U, 950944241U, 396426791U,
      3784844662U, 3477431613U, 3594592395U, 2782043838U, 3392093507U,
      3106564952U, 2829419931U, 1358665591U, 2206918825U, 3170783123U, 31522386U,
      2988194168U, 1782249537U, 1105080928U, 843500134U, 1225290080U,
      1521001832U, 3605886097U, 2802786495U, 2728923319U, 3996284304U,
      903417639U, 1171249804U, 1020374987U, 2824535874U, 423621996U, 1988534473U,
      2493544470U, 1008604435U, 1756003503U, 1488867287U, 1386808992U,
      732088248U, 1780630732U, 2482101014U, 976561178U, 1543448953U, 2602866064U,
      2021139923U, 1952599828U, 2360242564U, 2117959962U, 2753061860U,
      2388623612U, 4138193781U, 2962920654U, 2284970429U, 766920861U,
      3457264692U, 2879611383U, 815055854U, 2332929068U, 1254853997U,
      3740375268U, 3799380844U, 4091048725U, 2006331129U, 1982546212U,
      686850534U, 1907447564U, 2682801776U, 2780821066U, 998290361U, 1342433871U,
      4195430425U, 607905174U, 3902331779U, 2454067926U, 1708133115U,
      1170874362U, 2008609376U, 3260320415U, 2211196135U, 433538229U,
      2728786374U, 2189520818U, 262554063U, 1182318347U, 3710237267U,
      1221022450U, 715966018U, 2417068910U, 2591870721U, 2870691989U,
      3418190842U, 4238214053U, 1540704231U, 1575580968U, 2095917976U,
      4078310857U, 2313532447U, 2110690783U, 4056346629U, 4061784526U,
      1123218514U, 551538993U, 597148360U, 4120175196U, 3581618160U, 3181170517U,
      422862282U, 3227524138U, 1713114790U, 662317149U, 1230418732U, 928171837U,
      1324564878U, 1928816105U, 1786535431U, 2878099422U, 3290185549U,
      539474248U, 1657512683U, 552370646U, 1671741683U, 3655312128U, 1552739510U,
      2605208763U, 1441755014U, 181878989U, 3124053868U, 1447103986U,
      3183906156U, 1728556020U, 3502241336U, 3055466967U, 1013272474U,
      818402132U, 1715099063U, 2900113506U, 397254517U, 4194863039U, 1009068739U,
      232864647U, 2540223708U, 2608288560U, 2415367765U, 478404847U, 3455100648U,
      3182600021U, 2115988978U, 434269567U, 4117179324U, 3461774077U, 887256537U,
      3545801025U, 286388911U, 3451742129U, 1981164769U, 786667016U, 3310123729U,
      3097811076U, 2224235657U, 2959658883U, 3370969234U, 2514770915U,
      3345656436U, 2677010851U, 2206236470U, 271648054U, 2342188545U,
      4292848611U, 3646533909U, 3754009956U, 3803931226U, 4160647125U,
      1477814055U, 4043852216U, 1876372354U, 3133294443U, 3871104810U,
      3177020907U, 2074304428U, 3479393793U, 759562891U, 164128153U, 1839069216U,
      2114162633U, 3989947309U, 3611054956U, 1333547922U, 835429831U, 494987340U,
      171987910U, 1252001001U, 370809172U, 3508925425U, 2535703112U, 1276855041U,
      1922855120U, 835673414U, 3030664304U, 613287117U, 171219893U, 3423096126U,
      3376881639U, 2287770315U, 1658692645U, 1262815245U, 3957234326U,
      1168096164U, 2968737525U, 2655813712U, 2132313144U, 3976047964U,
      326516571U, 353088456U, 3679188938U, 3205649712U, 2654036126U, 1249024881U,
      880166166U, 691800469U, 2229503665U, 1673458056U, 4032208375U, 1851778863U,
      2563757330U, 376742205U, 1794655231U, 340247333U, 1505873033U, 396524441U,
      879666767U, 3335579166U, 3260764261U, 3335999539U, 506221798U, 4214658741U,
      975887814U, 2080536343U, 3360539560U, 571586418U, 138896374U, 4234352651U,
      2737620262U, 3928362291U, 1516365296U, 38056726U, 3599462320U, 3585007266U,
      3850961033U, 471667319U, 1536883193U, 2310166751U, 1861637689U,
      2530999841U, 4139843801U, 2710569485U, 827578615U, 2012334720U,
      2907369459U, 3029312804U, 2820112398U, 1965028045U, 35518606U, 2478379033U,
      643747771U, 1924139484U, 4123405127U, 3811735531U, 3429660832U,
      3285177704U, 1948416081U, 1311525291U, 1183517742U, 1739192232U,
      3979815115U, 2567840007U, 4116821529U, 213304419U, 4125718577U,
      1473064925U, 2442436592U, 1893310111U, 4195361916U, 3747569474U,
      828465101U, 2991227658U, 750582866U, 1205170309U, 1409813056U, 678418130U,
      1171531016U, 3821236156U, 354504587U, 4202874632U, 3882511497U,
      1893248677U, 1903078632U, 26340130U, 2069166240U, 3657122492U, 3725758099U,
      831344905U, 811453383U, 3447711422U, 2434543565U, 4166886888U, 3358210805U,
      4142984013U, 2988152326U, 3527824853U, 982082992U, 2809155763U, 190157081U,
      3340214818U, 2365432395U, 2548636180U, 2894533366U, 3474657421U,
      2372634704U, 2845748389U, 43024175U, 2774226648U, 1987702864U, 3186502468U,
      453610222U, 4204736567U, 1392892630U, 2471323686U, 2470534280U,
      3541393095U, 4269885866U, 3909911300U, 759132955U, 1482612480U, 667715263U,
      1795580598U, 2337923983U, 3390586366U, 581426223U, 1515718634U, 476374295U,
      705213300U, 363062054U, 2084697697U, 2407503428U, 2292957699U, 2426213835U,
      2199989172U, 1987356470U, 4026755612U, 2147252133U, 270400031U,
      1367820199U, 2369854699U, 2844269403U, 79981964U, 624U };

    /* SystemInitialize for MATLAB Function: '<Root>/MATLAB Function1' */
    memcpy(&model_DW.state[0], &tmp[0], 625U * sizeof(uint32_T));
    model_DW.velocity_not_empty = false;
    for (i = 0; i < 40; i++) {
      model_DW.velocity[i] = 1.0;
    }

    /* End of SystemInitialize for MATLAB Function: '<Root>/MATLAB Function1' */

    /* SystemInitialize for MATLAB Function: '<S2>/MATLAB Function' */
    model_DW.iteration = 0.0;
  }
}

/* Model terminate function */
void model_terminate(void)
{
  /* Terminate for S-Function (sldrtpo): '<S2>/Packet Output' incorporates:
   *  Constant: '<S2>/Constant4'
   *  Constant: '<S2>/Constant5'
   */

  /* S-Function Block: <S2>/Packet Output */
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

    /* polyspace +2 MISRA2012:D4.1 [Justified:Low] "model_M points to
       static memory which is guaranteed to be non-NULL" */
    model_M->Timing.sampleTimeTaskIDPtr = (&mdlTsMap[0]);
    model_M->Timing.sampleTimes = (&model_M->Timing.sampleTimesArray[0]);
    model_M->Timing.offsetTimes = (&model_M->Timing.offsetTimesArray[0]);

    /* task periods */
    model_M->Timing.sampleTimes[0] = (0.01);

    /* task offsets */
    model_M->Timing.offsetTimes[0] = (0.0);
  }

  rtmSetTPtr(model_M, &model_M->Timing.tArray[0]);

  {
    int_T *mdlSampleHits = model_M->Timing.sampleHitArray;
    mdlSampleHits[0] = 1;
    model_M->Timing.sampleHits = (&mdlSampleHits[0]);
  }

  rtmSetTFinal(model_M, 25.0);
  model_M->Timing.stepSize0 = 0.01;

  /* External mode info */
  model_M->Sizes.checksums[0] = (2709160817U);
  model_M->Sizes.checksums[1] = (1289811529U);
  model_M->Sizes.checksums[2] = (3407644614U);
  model_M->Sizes.checksums[3] = (1956649037U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[3];
    model_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    systemRan[1] = &rtAlwaysEnabled;
    systemRan[2] = &rtAlwaysEnabled;
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
    dtInfo.numDataTypes = 22;
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
  model_M->Sizes.numSampTimes = (1);   /* Number of sample times */
  model_M->Sizes.numBlocks = (16);     /* Number of blocks */
  model_M->Sizes.numBlockIO = (8);     /* Number of block outputs */
  model_M->Sizes.numBlockPrms = (8);   /* Sum of parameter "widths" */
  return model_M;
}

/*========================================================================*
 * End of Classic call interface                                          *
 *========================================================================*/
