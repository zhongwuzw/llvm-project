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
#define SVE_ACLE_FUNC(A1, A2_UNUSED, A3, A4_UNUSED) A1##A3
#else
#define SVE_ACLE_FUNC(A1, A2, A3, A4) A1##A2##A3##A4
#endif

svint64_t test_svldnt1uw_gather_u64base_s64(svbool_t pg, svuint64_t bases) {
  // CHECK-LABEL: test_svldnt1uw_gather_u64base_s64
  // CHECK: [[PG:%.*]] = call <vscale x 2 x i1> @llvm.aarch64.sve.convert.from.svbool.nxv2i1(<vscale x 16 x i1> %pg)
  // CHECK: [[LOAD:%.*]] = call <vscale x 2 x i32> @llvm.aarch64.sve.ldnt1.gather.scalar.offset.nxv2i32.nxv2i64(<vscale x 2 x i1> [[PG]], <vscale x 2 x i64> %bases, i64 0)
  // CHECK: [[ZEXT:%.*]] = zext <vscale x 2 x i32> [[LOAD]] to <vscale x 2 x i64>
  // CHECK: ret <vscale x 2 x i64> [[ZEXT]]
  // overload-warning@+2 {{implicit declaration of function 'svldnt1uw_gather_s64'}}
  // expected-warning@+1 {{implicit declaration of function 'svldnt1uw_gather_u64base_s64'}}
  return SVE_ACLE_FUNC(svldnt1uw_gather, _u64base, _s64, )(pg, bases);
}

svuint64_t test_svldnt1uw_gather_u64base_u64(svbool_t pg, svuint64_t bases) {
  // CHECK-LABEL: test_svldnt1uw_gather_u64base_u64
  // CHECK: [[PG:%.*]] = call <vscale x 2 x i1> @llvm.aarch64.sve.convert.from.svbool.nxv2i1(<vscale x 16 x i1> %pg)
  // CHECK: [[LOAD:%.*]] = call <vscale x 2 x i32> @llvm.aarch64.sve.ldnt1.gather.scalar.offset.nxv2i32.nxv2i64(<vscale x 2 x i1> [[PG]], <vscale x 2 x i64> %bases, i64 0)
  // CHECK: [[ZEXT:%.*]] = zext <vscale x 2 x i32> [[LOAD]] to <vscale x 2 x i64>
  // CHECK: ret <vscale x 2 x i64> [[ZEXT]]
  // overload-warning@+2 {{implicit declaration of function 'svldnt1uw_gather_u64'}}
  // expected-warning@+1 {{implicit declaration of function 'svldnt1uw_gather_u64base_u64'}}
  return SVE_ACLE_FUNC(svldnt1uw_gather, _u64base, _u64, )(pg, bases);
}

svint64_t test_svldnt1uw_gather_s64offset_s64(svbool_t pg, const uint32_t *base, svint64_t offsets) {
  // CHECK-LABEL: test_svldnt1uw_gather_s64offset_s64
  // CHECK: [[PG:%.*]] = call <vscale x 2 x i1> @llvm.aarch64.sve.convert.from.svbool.nxv2i1(<vscale x 16 x i1> %pg)
  // CHECK: [[LOAD:%.*]] = call <vscale x 2 x i32> @llvm.aarch64.sve.ldnt1.gather.nxv2i32(<vscale x 2 x i1> [[PG]], i32* %base, <vscale x 2 x i64> %offsets)
  // CHECK: [[ZEXT:%.*]] = zext <vscale x 2 x i32> [[LOAD]] to <vscale x 2 x i64>
  // CHECK: ret <vscale x 2 x i64> [[ZEXT]]
  // overload-warning@+2 {{implicit declaration of function 'svldnt1uw_gather_offset_s64'}}
  // expected-warning@+1 {{implicit declaration of function 'svldnt1uw_gather_s64offset_s64'}}
  return SVE_ACLE_FUNC(svldnt1uw_gather_, s64, offset_s64, )(pg, base, offsets);
}

svuint64_t test_svldnt1uw_gather_s64offset_u64(svbool_t pg, const uint32_t *base, svint64_t offsets) {
  // CHECK-LABEL: test_svldnt1uw_gather_s64offset_u64
  // CHECK: [[PG:%.*]] = call <vscale x 2 x i1> @llvm.aarch64.sve.convert.from.svbool.nxv2i1(<vscale x 16 x i1> %pg)
  // CHECK: [[LOAD:%.*]] = call <vscale x 2 x i32> @llvm.aarch64.sve.ldnt1.gather.nxv2i32(<vscale x 2 x i1> [[PG]], i32* %base, <vscale x 2 x i64> %offsets)
  // CHECK: [[ZEXT:%.*]] = zext <vscale x 2 x i32> [[LOAD]] to <vscale x 2 x i64>
  // CHECK: ret <vscale x 2 x i64> [[ZEXT]]
  // overload-warning@+2 {{implicit declaration of function 'svldnt1uw_gather_offset_u64'}}
  // expected-warning@+1 {{implicit declaration of function 'svldnt1uw_gather_s64offset_u64'}}
  return SVE_ACLE_FUNC(svldnt1uw_gather_, s64, offset_u64, )(pg, base, offsets);
}

svint64_t test_svldnt1uw_gather_u64offset_s64(svbool_t pg, const uint32_t *base, svuint64_t offsets) {
  // CHECK-LABEL: test_svldnt1uw_gather_u64offset_s64
  // CHECK: [[PG:%.*]] = call <vscale x 2 x i1> @llvm.aarch64.sve.convert.from.svbool.nxv2i1(<vscale x 16 x i1> %pg)
  // CHECK: [[LOAD:%.*]] = call <vscale x 2 x i32> @llvm.aarch64.sve.ldnt1.gather.nxv2i32(<vscale x 2 x i1> [[PG]], i32* %base, <vscale x 2 x i64> %offsets)
  // CHECK: [[ZEXT:%.*]] = zext <vscale x 2 x i32> [[LOAD]] to <vscale x 2 x i64>
  // CHECK: ret <vscale x 2 x i64> [[ZEXT]]
  // overload-warning@+2 {{implicit declaration of function 'svldnt1uw_gather_offset_s64'}}
  // expected-warning@+1 {{implicit declaration of function 'svldnt1uw_gather_u64offset_s64'}}
  return SVE_ACLE_FUNC(svldnt1uw_gather_, u64, offset_s64, )(pg, base, offsets);
}

svuint64_t test_svldnt1uw_gather_u64offset_u64(svbool_t pg, const uint32_t *base, svuint64_t offsets) {
  // CHECK-LABEL: test_svldnt1uw_gather_u64offset_u64
  // CHECK: [[PG:%.*]] = call <vscale x 2 x i1> @llvm.aarch64.sve.convert.from.svbool.nxv2i1(<vscale x 16 x i1> %pg)
  // CHECK: [[LOAD:%.*]] = call <vscale x 2 x i32> @llvm.aarch64.sve.ldnt1.gather.nxv2i32(<vscale x 2 x i1> [[PG]], i32* %base, <vscale x 2 x i64> %offsets)
  // CHECK: [[ZEXT:%.*]] = zext <vscale x 2 x i32> [[LOAD]] to <vscale x 2 x i64>
  // CHECK: ret <vscale x 2 x i64> [[ZEXT]]
  // overload-warning@+2 {{implicit declaration of function 'svldnt1uw_gather_offset_u64'}}
  // expected-warning@+1 {{implicit declaration of function 'svldnt1uw_gather_u64offset_u64'}}
  return SVE_ACLE_FUNC(svldnt1uw_gather_, u64, offset_u64, )(pg, base, offsets);
}

svint64_t test_svldnt1uw_gather_u64base_offset_s64(svbool_t pg, svuint64_t bases, int64_t offset) {
  // CHECK-LABEL: test_svldnt1uw_gather_u64base_offset_s64
  // CHECK: [[PG:%.*]] = call <vscale x 2 x i1> @llvm.aarch64.sve.convert.from.svbool.nxv2i1(<vscale x 16 x i1> %pg)
  // CHECK: [[LOAD:%.*]] = call <vscale x 2 x i32> @llvm.aarch64.sve.ldnt1.gather.scalar.offset.nxv2i32.nxv2i64(<vscale x 2 x i1> [[PG]], <vscale x 2 x i64> %bases, i64 %offset)
  // CHECK: [[ZEXT:%.*]] = zext <vscale x 2 x i32> [[LOAD]] to <vscale x 2 x i64>
  // CHECK: ret <vscale x 2 x i64> [[ZEXT]]
  // overload-warning@+2 {{implicit declaration of function 'svldnt1uw_gather_offset_s64'}}
  // expected-warning@+1 {{implicit declaration of function 'svldnt1uw_gather_u64base_offset_s64'}}
  return SVE_ACLE_FUNC(svldnt1uw_gather, _u64base, _offset_s64, )(pg, bases, offset);
}

svuint64_t test_svldnt1uw_gather_u64base_offset_u64(svbool_t pg, svuint64_t bases, int64_t offset) {
  // CHECK-LABEL: test_svldnt1uw_gather_u64base_offset_u64
  // CHECK: [[PG:%.*]] = call <vscale x 2 x i1> @llvm.aarch64.sve.convert.from.svbool.nxv2i1(<vscale x 16 x i1> %pg)
  // CHECK: [[LOAD:%.*]] = call <vscale x 2 x i32> @llvm.aarch64.sve.ldnt1.gather.scalar.offset.nxv2i32.nxv2i64(<vscale x 2 x i1> [[PG]], <vscale x 2 x i64> %bases, i64 %offset)
  // CHECK: [[ZEXT:%.*]] = zext <vscale x 2 x i32> [[LOAD]] to <vscale x 2 x i64>
  // CHECK: ret <vscale x 2 x i64> [[ZEXT]]
  // overload-warning@+2 {{implicit declaration of function 'svldnt1uw_gather_offset_u64'}}
  // expected-warning@+1 {{implicit declaration of function 'svldnt1uw_gather_u64base_offset_u64'}}
  return SVE_ACLE_FUNC(svldnt1uw_gather, _u64base, _offset_u64, )(pg, bases, offset);
}

svint64_t test_svldnt1uw_gather_s64index_s64(svbool_t pg, const uint32_t *base, svint64_t indices) {
  // CHECK-LABEL: test_svldnt1uw_gather_s64index_s64
  // CHECK: [[PG:%.*]] = call <vscale x 2 x i1> @llvm.aarch64.sve.convert.from.svbool.nxv2i1(<vscale x 16 x i1> %pg)
  // CHECK: [[LOAD:%.*]] = call <vscale x 2 x i32> @llvm.aarch64.sve.ldnt1.gather.index.nxv2i32(<vscale x 2 x i1> [[PG]], i32* %base, <vscale x 2 x i64> %indices)
  // CHECK: [[ZEXT:%.*]] = zext <vscale x 2 x i32> [[LOAD]] to <vscale x 2 x i64>
  // CHECK: ret <vscale x 2 x i64> [[ZEXT]]
  // overload-warning@+2 {{implicit declaration of function 'svldnt1uw_gather_index_s64'}}
  // expected-warning@+1 {{implicit declaration of function 'svldnt1uw_gather_s64index_s64'}}
  return SVE_ACLE_FUNC(svldnt1uw_gather_, s64, index_s64, )(pg, base, indices);
}

svuint64_t test_svldnt1uw_gather_s64index_u64(svbool_t pg, const uint32_t *base, svint64_t indices) {
  // CHECK-LABEL: test_svldnt1uw_gather_s64index_u64
  // CHECK: [[PG:%.*]] = call <vscale x 2 x i1> @llvm.aarch64.sve.convert.from.svbool.nxv2i1(<vscale x 16 x i1> %pg)
  // CHECK: [[LOAD:%.*]] = call <vscale x 2 x i32> @llvm.aarch64.sve.ldnt1.gather.index.nxv2i32(<vscale x 2 x i1> [[PG]], i32* %base, <vscale x 2 x i64> %indices)
  // CHECK: [[ZEXT:%.*]] = zext <vscale x 2 x i32> [[LOAD]] to <vscale x 2 x i64>
  // CHECK: ret <vscale x 2 x i64> [[ZEXT]]
  // overload-warning@+2 {{implicit declaration of function 'svldnt1uw_gather_index_u64'}}
  // expected-warning@+1 {{implicit declaration of function 'svldnt1uw_gather_s64index_u64'}}
  return SVE_ACLE_FUNC(svldnt1uw_gather_, s64, index_u64, )(pg, base, indices);
}

svint64_t test_svldnt1uw_gather_u64index_s64(svbool_t pg, const uint32_t *base, svuint64_t indices) {
  // CHECK-LABEL: test_svldnt1uw_gather_u64index_s64
  // CHECK: [[PG:%.*]] = call <vscale x 2 x i1> @llvm.aarch64.sve.convert.from.svbool.nxv2i1(<vscale x 16 x i1> %pg)
  // CHECK: [[LOAD:%.*]] = call <vscale x 2 x i32> @llvm.aarch64.sve.ldnt1.gather.index.nxv2i32(<vscale x 2 x i1> [[PG]], i32* %base, <vscale x 2 x i64> %indices)
  // CHECK: [[ZEXT:%.*]] = zext <vscale x 2 x i32> [[LOAD]] to <vscale x 2 x i64>
  // CHECK: ret <vscale x 2 x i64> [[ZEXT]]
  // overload-warning@+2 {{implicit declaration of function 'svldnt1uw_gather_index_s64'}}
  // expected-warning@+1 {{implicit declaration of function 'svldnt1uw_gather_u64index_s64'}}
  return SVE_ACLE_FUNC(svldnt1uw_gather_, u64, index_s64, )(pg, base, indices);
}

svuint64_t test_svldnt1uw_gather_u64index_u64(svbool_t pg, const uint32_t *base, svuint64_t indices) {
  // CHECK-LABEL: test_svldnt1uw_gather_u64index_u64
  // CHECK: [[PG:%.*]] = call <vscale x 2 x i1> @llvm.aarch64.sve.convert.from.svbool.nxv2i1(<vscale x 16 x i1> %pg)
  // CHECK: [[LOAD:%.*]] = call <vscale x 2 x i32> @llvm.aarch64.sve.ldnt1.gather.index.nxv2i32(<vscale x 2 x i1> [[PG]], i32* %base, <vscale x 2 x i64> %indices)
  // CHECK: [[ZEXT:%.*]] = zext <vscale x 2 x i32> [[LOAD]] to <vscale x 2 x i64>
  // CHECK: ret <vscale x 2 x i64> [[ZEXT]]
  // overload-warning@+2 {{implicit declaration of function 'svldnt1uw_gather_index_u64'}}
  // expected-warning@+1 {{implicit declaration of function 'svldnt1uw_gather_u64index_u64'}}
  return SVE_ACLE_FUNC(svldnt1uw_gather_, u64, index_u64, )(pg, base, indices);
}

svint64_t test_svldnt1uw_gather_u64base_index_s64(svbool_t pg, svuint64_t bases, int64_t index) {
  // CHECK-LABEL: test_svldnt1uw_gather_u64base_index_s64
  // CHECK-DAG: [[PG:%.*]] = call <vscale x 2 x i1> @llvm.aarch64.sve.convert.from.svbool.nxv2i1(<vscale x 16 x i1> %pg)
  // CHECK-DAG: [[SHL:%.*]] = shl i64 %index, 2
  // CHECK: [[LOAD:%.*]] = call <vscale x 2 x i32> @llvm.aarch64.sve.ldnt1.gather.scalar.offset.nxv2i32.nxv2i64(<vscale x 2 x i1> [[PG]], <vscale x 2 x i64> %bases, i64 [[SHL]])
  // CHECK: [[ZEXT:%.*]] = zext <vscale x 2 x i32> [[LOAD]] to <vscale x 2 x i64>
  // CHECK: ret <vscale x 2 x i64> [[ZEXT]]
  // overload-warning@+2 {{implicit declaration of function 'svldnt1uw_gather_index_s64'}}
  // expected-warning@+1 {{implicit declaration of function 'svldnt1uw_gather_u64base_index_s64'}}
  return SVE_ACLE_FUNC(svldnt1uw_gather, _u64base, _index_s64, )(pg, bases, index);
}

svuint64_t test_svldnt1uw_gather_u64base_index_u64(svbool_t pg, svuint64_t bases, int64_t index) {
  // CHECK-LABEL: test_svldnt1uw_gather_u64base_index_u64
  // CHECK-DAG: [[PG:%.*]] = call <vscale x 2 x i1> @llvm.aarch64.sve.convert.from.svbool.nxv2i1(<vscale x 16 x i1> %pg)
  // CHECK-DAG: [[SHL:%.*]] = shl i64 %index, 2
  // CHECK: [[LOAD:%.*]] = call <vscale x 2 x i32> @llvm.aarch64.sve.ldnt1.gather.scalar.offset.nxv2i32.nxv2i64(<vscale x 2 x i1> [[PG]], <vscale x 2 x i64> %bases, i64 [[SHL]])
  // CHECK: [[ZEXT:%.*]] = zext <vscale x 2 x i32> [[LOAD]] to <vscale x 2 x i64>
  // CHECK: ret <vscale x 2 x i64> [[ZEXT]]
  // overload-warning@+2 {{implicit declaration of function 'svldnt1uw_gather_index_u64'}}
  // expected-warning@+1 {{implicit declaration of function 'svldnt1uw_gather_u64base_index_u64'}}
  return SVE_ACLE_FUNC(svldnt1uw_gather, _u64base, _index_u64, )(pg, bases, index);
}
