// REQUIRES: aarch64-registered-target || arm-registered-target

// RUN: %clang_cc1 -triple aarch64-none-linux-gnu -target-feature +sve2 -fallow-half-arguments-and-returns -S -O1 -Werror -Wall -emit-llvm -o - %s | FileCheck %s
// RUN: %clang_cc1 -triple aarch64-none-linux-gnu -target-feature +sve2 -fallow-half-arguments-and-returns -S -O1 -Werror -Wall -emit-llvm -o - -x c++ %s | FileCheck %s
// RUN: %clang_cc1 -DSVE_OVERLOADED_FORMS -triple aarch64-none-linux-gnu -target-feature +sve2 -fallow-half-arguments-and-returns -S -O1 -Werror -Wall -emit-llvm -o - %s | FileCheck %s
// RUN: %clang_cc1 -DSVE_OVERLOADED_FORMS -triple aarch64-none-linux-gnu -target-feature +sve2 -fallow-half-arguments-and-returns -S -O1 -Werror -Wall -emit-llvm -o - -x c++ %s | FileCheck %s
// RUN: %clang_cc1 -triple aarch64-none-linux-gnu -target-feature +sve -fallow-half-arguments-and-returns -fsyntax-only -verify -verify-ignore-unexpected=error %s
// RUN: %clang_cc1 -DSVE_OVERLOADED_FORMS -triple aarch64-none-linux-gnu -target-feature +sve -fallow-half-arguments-and-returns -fsyntax-only -verify=overload -verify-ignore-unexpected=error %s

#include <arm_sve.h>

#ifdef SVE_OVERLOADED_FORMS
// A simple used,unused... macro, long enough to represent any SVE builtin.
#define SVE_ACLE_FUNC(A1,A2_UNUSED,A3,A4_UNUSED) A1##A3
#else
#define SVE_ACLE_FUNC(A1,A2,A3,A4) A1##A2##A3##A4
#endif

svuint8_t test_svqrshrunb_n_s16(svint16_t op1)
{
  // CHECK-LABEL: test_svqrshrunb_n_s16
  // CHECK: %[[INTRINSIC:.*]] = call <vscale x 16 x i8> @llvm.aarch64.sve.sqrshrunb.nxv8i16(<vscale x 8 x i16> %op1, i32 1)
  // CHECK: ret <vscale x 16 x i8> %[[INTRINSIC]]
  // overload-warning@+2 {{implicit declaration of function 'svqrshrunb'}}
  // expected-warning@+1 {{implicit declaration of function 'svqrshrunb_n_s16'}}
  return SVE_ACLE_FUNC(svqrshrunb,_n_s16,,)(op1, 1);
}

svuint8_t test_svqrshrunb_n_s16_1(svint16_t op1)
{
  // CHECK-LABEL: test_svqrshrunb_n_s16_1
  // CHECK: %[[INTRINSIC:.*]] = call <vscale x 16 x i8> @llvm.aarch64.sve.sqrshrunb.nxv8i16(<vscale x 8 x i16> %op1, i32 8)
  // CHECK: ret <vscale x 16 x i8> %[[INTRINSIC]]
  // overload-warning@+2 {{implicit declaration of function 'svqrshrunb'}}
  // expected-warning@+1 {{implicit declaration of function 'svqrshrunb_n_s16'}}
  return SVE_ACLE_FUNC(svqrshrunb,_n_s16,,)(op1, 8);
}

svuint16_t test_svqrshrunb_n_s32(svint32_t op1)
{
  // CHECK-LABEL: test_svqrshrunb_n_s32
  // CHECK: %[[INTRINSIC:.*]] = call <vscale x 8 x i16> @llvm.aarch64.sve.sqrshrunb.nxv4i32(<vscale x 4 x i32> %op1, i32 1)
  // CHECK: ret <vscale x 8 x i16> %[[INTRINSIC]]
  // overload-warning@+2 {{implicit declaration of function 'svqrshrunb'}}
  // expected-warning@+1 {{implicit declaration of function 'svqrshrunb_n_s32'}}
  return SVE_ACLE_FUNC(svqrshrunb,_n_s32,,)(op1, 1);
}

svuint16_t test_svqrshrunb_n_s32_1(svint32_t op1)
{
  // CHECK-LABEL: test_svqrshrunb_n_s32_1
  // CHECK: %[[INTRINSIC:.*]] = call <vscale x 8 x i16> @llvm.aarch64.sve.sqrshrunb.nxv4i32(<vscale x 4 x i32> %op1, i32 16)
  // CHECK: ret <vscale x 8 x i16> %[[INTRINSIC]]
  // overload-warning@+2 {{implicit declaration of function 'svqrshrunb'}}
  // expected-warning@+1 {{implicit declaration of function 'svqrshrunb_n_s32'}}
  return SVE_ACLE_FUNC(svqrshrunb,_n_s32,,)(op1, 16);
}

svuint32_t test_svqrshrunb_n_s64(svint64_t op1)
{
  // CHECK-LABEL: test_svqrshrunb_n_s64
  // CHECK: %[[INTRINSIC:.*]] = call <vscale x 4 x i32> @llvm.aarch64.sve.sqrshrunb.nxv2i64(<vscale x 2 x i64> %op1, i32 1)
  // CHECK: ret <vscale x 4 x i32> %[[INTRINSIC]]
  // overload-warning@+2 {{implicit declaration of function 'svqrshrunb'}}
  // expected-warning@+1 {{implicit declaration of function 'svqrshrunb_n_s64'}}
  return SVE_ACLE_FUNC(svqrshrunb,_n_s64,,)(op1, 1);
}

svuint32_t test_svqrshrunb_n_s64_1(svint64_t op1)
{
  // CHECK-LABEL: test_svqrshrunb_n_s64_1
  // CHECK: %[[INTRINSIC:.*]] = call <vscale x 4 x i32> @llvm.aarch64.sve.sqrshrunb.nxv2i64(<vscale x 2 x i64> %op1, i32 32)
  // CHECK: ret <vscale x 4 x i32> %[[INTRINSIC]]
  // overload-warning@+2 {{implicit declaration of function 'svqrshrunb'}}
  // expected-warning@+1 {{implicit declaration of function 'svqrshrunb_n_s64'}}
  return SVE_ACLE_FUNC(svqrshrunb,_n_s64,,)(op1, 32);
}
