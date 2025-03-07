// REQUIRES: aarch64-registered-target || arm-registered-target

// NOTE: Assertions have been autogenerated by utils/update_cc_test_checks.py
// RUN: %clang_cc1 -triple thumbv8.1m.main-none-none-eabi -target-feature +mve.fp -mfloat-abi hard -fallow-half-arguments-and-returns -O0 -disable-O0-optnone -S -emit-llvm -o - %s | opt -S -mem2reg | FileCheck %s
// RUN: %clang_cc1 -triple thumbv8.1m.main-none-none-eabi -target-feature +mve.fp -mfloat-abi hard -fallow-half-arguments-and-returns -O0 -disable-O0-optnone -DPOLYMORPHIC -S -emit-llvm -o - %s | opt -S -mem2reg | FileCheck %s

#include <arm_mve.h>

// CHECK-LABEL: @test_vhcaddq_rot90_s8(
// CHECK-NEXT:  entry:
// CHECK-NEXT:    [[TMP0:%.*]] = call <16 x i8> @llvm.arm.mve.vcaddq.v16i8(i32 0, i32 0, <16 x i8> [[A:%.*]], <16 x i8> [[B:%.*]])
// CHECK-NEXT:    ret <16 x i8> [[TMP0]]
//
int8x16_t test_vhcaddq_rot90_s8(int8x16_t a, int8x16_t b)
{
#ifdef POLYMORPHIC
    return vhcaddq_rot90(a, b);
#else
    return vhcaddq_rot90_s8(a, b);
#endif
}

// CHECK-LABEL: @test_vhcaddq_rot90_s16(
// CHECK-NEXT:  entry:
// CHECK-NEXT:    [[TMP0:%.*]] = call <8 x i16> @llvm.arm.mve.vcaddq.v8i16(i32 0, i32 0, <8 x i16> [[A:%.*]], <8 x i16> [[B:%.*]])
// CHECK-NEXT:    ret <8 x i16> [[TMP0]]
//
int16x8_t test_vhcaddq_rot90_s16(int16x8_t a, int16x8_t b)
{
#ifdef POLYMORPHIC
    return vhcaddq_rot90(a, b);
#else
    return vhcaddq_rot90_s16(a, b);
#endif
}

// CHECK-LABEL: @test_vhcaddq_rot90_s32(
// CHECK-NEXT:  entry:
// CHECK-NEXT:    [[TMP0:%.*]] = call <4 x i32> @llvm.arm.mve.vcaddq.v4i32(i32 0, i32 0, <4 x i32> [[A:%.*]], <4 x i32> [[B:%.*]])
// CHECK-NEXT:    ret <4 x i32> [[TMP0]]
//
int32x4_t test_vhcaddq_rot90_s32(int32x4_t a, int32x4_t b)
{
#ifdef POLYMORPHIC
    return vhcaddq_rot90(a, b);
#else
    return vhcaddq_rot90_s32(a, b);
#endif
}

// CHECK-LABEL: @test_vhcaddq_rot270_s8(
// CHECK-NEXT:  entry:
// CHECK-NEXT:    [[TMP0:%.*]] = call <16 x i8> @llvm.arm.mve.vcaddq.v16i8(i32 0, i32 1, <16 x i8> [[A:%.*]], <16 x i8> [[B:%.*]])
// CHECK-NEXT:    ret <16 x i8> [[TMP0]]
//
int8x16_t test_vhcaddq_rot270_s8(int8x16_t a, int8x16_t b)
{
#ifdef POLYMORPHIC
    return vhcaddq_rot270(a, b);
#else
    return vhcaddq_rot270_s8(a, b);
#endif
}

// CHECK-LABEL: @test_vhcaddq_rot270_s16(
// CHECK-NEXT:  entry:
// CHECK-NEXT:    [[TMP0:%.*]] = call <8 x i16> @llvm.arm.mve.vcaddq.v8i16(i32 0, i32 1, <8 x i16> [[A:%.*]], <8 x i16> [[B:%.*]])
// CHECK-NEXT:    ret <8 x i16> [[TMP0]]
//
int16x8_t test_vhcaddq_rot270_s16(int16x8_t a, int16x8_t b)
{
#ifdef POLYMORPHIC
    return vhcaddq_rot270(a, b);
#else
    return vhcaddq_rot270_s16(a, b);
#endif
}

// CHECK-LABEL: @test_vhcaddq_rot270_s32(
// CHECK-NEXT:  entry:
// CHECK-NEXT:    [[TMP0:%.*]] = call <4 x i32> @llvm.arm.mve.vcaddq.v4i32(i32 0, i32 1, <4 x i32> [[A:%.*]], <4 x i32> [[B:%.*]])
// CHECK-NEXT:    ret <4 x i32> [[TMP0]]
//
int32x4_t test_vhcaddq_rot270_s32(int32x4_t a, int32x4_t b)
{
#ifdef POLYMORPHIC
    return vhcaddq_rot270(a, b);
#else
    return vhcaddq_rot270_s32(a, b);
#endif
}

// CHECK-LABEL: @test_vhcaddq_rot90_x_s8(
// CHECK-NEXT:  entry:
// CHECK-NEXT:    [[TMP0:%.*]] = zext i16 [[P:%.*]] to i32
// CHECK-NEXT:    [[TMP1:%.*]] = call <16 x i1> @llvm.arm.mve.pred.i2v.v16i1(i32 [[TMP0]])
// CHECK-NEXT:    [[TMP2:%.*]] = call <16 x i8> @llvm.arm.mve.vcaddq.predicated.v16i8.v16i1(i32 0, i32 0, <16 x i8> undef, <16 x i8> [[A:%.*]], <16 x i8> [[B:%.*]], <16 x i1> [[TMP1]])
// CHECK-NEXT:    ret <16 x i8> [[TMP2]]
//
int8x16_t test_vhcaddq_rot90_x_s8(int8x16_t a, int8x16_t b, mve_pred16_t p)
{
#ifdef POLYMORPHIC
    return vhcaddq_rot90_x(a, b, p);
#else
    return vhcaddq_rot90_x_s8(a, b, p);
#endif
}

// CHECK-LABEL: @test_vhcaddq_rot90_x_s16(
// CHECK-NEXT:  entry:
// CHECK-NEXT:    [[TMP0:%.*]] = zext i16 [[P:%.*]] to i32
// CHECK-NEXT:    [[TMP1:%.*]] = call <8 x i1> @llvm.arm.mve.pred.i2v.v8i1(i32 [[TMP0]])
// CHECK-NEXT:    [[TMP2:%.*]] = call <8 x i16> @llvm.arm.mve.vcaddq.predicated.v8i16.v8i1(i32 0, i32 0, <8 x i16> undef, <8 x i16> [[A:%.*]], <8 x i16> [[B:%.*]], <8 x i1> [[TMP1]])
// CHECK-NEXT:    ret <8 x i16> [[TMP2]]
//
int16x8_t test_vhcaddq_rot90_x_s16(int16x8_t a, int16x8_t b, mve_pred16_t p)
{
#ifdef POLYMORPHIC
    return vhcaddq_rot90_x(a, b, p);
#else
    return vhcaddq_rot90_x_s16(a, b, p);
#endif
}

// CHECK-LABEL: @test_vhcaddq_rot90_x_s32(
// CHECK-NEXT:  entry:
// CHECK-NEXT:    [[TMP0:%.*]] = zext i16 [[P:%.*]] to i32
// CHECK-NEXT:    [[TMP1:%.*]] = call <4 x i1> @llvm.arm.mve.pred.i2v.v4i1(i32 [[TMP0]])
// CHECK-NEXT:    [[TMP2:%.*]] = call <4 x i32> @llvm.arm.mve.vcaddq.predicated.v4i32.v4i1(i32 0, i32 0, <4 x i32> undef, <4 x i32> [[A:%.*]], <4 x i32> [[B:%.*]], <4 x i1> [[TMP1]])
// CHECK-NEXT:    ret <4 x i32> [[TMP2]]
//
int32x4_t test_vhcaddq_rot90_x_s32(int32x4_t a, int32x4_t b, mve_pred16_t p)
{
#ifdef POLYMORPHIC
    return vhcaddq_rot90_x(a, b, p);
#else
    return vhcaddq_rot90_x_s32(a, b, p);
#endif
}

// CHECK-LABEL: @test_vhcaddq_rot270_x_s8(
// CHECK-NEXT:  entry:
// CHECK-NEXT:    [[TMP0:%.*]] = zext i16 [[P:%.*]] to i32
// CHECK-NEXT:    [[TMP1:%.*]] = call <16 x i1> @llvm.arm.mve.pred.i2v.v16i1(i32 [[TMP0]])
// CHECK-NEXT:    [[TMP2:%.*]] = call <16 x i8> @llvm.arm.mve.vcaddq.predicated.v16i8.v16i1(i32 0, i32 1, <16 x i8> undef, <16 x i8> [[A:%.*]], <16 x i8> [[B:%.*]], <16 x i1> [[TMP1]])
// CHECK-NEXT:    ret <16 x i8> [[TMP2]]
//
int8x16_t test_vhcaddq_rot270_x_s8(int8x16_t a, int8x16_t b, mve_pred16_t p)
{
#ifdef POLYMORPHIC
    return vhcaddq_rot270_x(a, b, p);
#else
    return vhcaddq_rot270_x_s8(a, b, p);
#endif
}

// CHECK-LABEL: @test_vhcaddq_rot270_x_s16(
// CHECK-NEXT:  entry:
// CHECK-NEXT:    [[TMP0:%.*]] = zext i16 [[P:%.*]] to i32
// CHECK-NEXT:    [[TMP1:%.*]] = call <8 x i1> @llvm.arm.mve.pred.i2v.v8i1(i32 [[TMP0]])
// CHECK-NEXT:    [[TMP2:%.*]] = call <8 x i16> @llvm.arm.mve.vcaddq.predicated.v8i16.v8i1(i32 0, i32 1, <8 x i16> undef, <8 x i16> [[A:%.*]], <8 x i16> [[B:%.*]], <8 x i1> [[TMP1]])
// CHECK-NEXT:    ret <8 x i16> [[TMP2]]
//
int16x8_t test_vhcaddq_rot270_x_s16(int16x8_t a, int16x8_t b, mve_pred16_t p)
{
#ifdef POLYMORPHIC
    return vhcaddq_rot270_x(a, b, p);
#else
    return vhcaddq_rot270_x_s16(a, b, p);
#endif
}

// CHECK-LABEL: @test_vhcaddq_rot270_x_s32(
// CHECK-NEXT:  entry:
// CHECK-NEXT:    [[TMP0:%.*]] = zext i16 [[P:%.*]] to i32
// CHECK-NEXT:    [[TMP1:%.*]] = call <4 x i1> @llvm.arm.mve.pred.i2v.v4i1(i32 [[TMP0]])
// CHECK-NEXT:    [[TMP2:%.*]] = call <4 x i32> @llvm.arm.mve.vcaddq.predicated.v4i32.v4i1(i32 0, i32 1, <4 x i32> undef, <4 x i32> [[A:%.*]], <4 x i32> [[B:%.*]], <4 x i1> [[TMP1]])
// CHECK-NEXT:    ret <4 x i32> [[TMP2]]
//
int32x4_t test_vhcaddq_rot270_x_s32(int32x4_t a, int32x4_t b, mve_pred16_t p)
{
#ifdef POLYMORPHIC
    return vhcaddq_rot270_x(a, b, p);
#else
    return vhcaddq_rot270_x_s32(a, b, p);
#endif
}

// CHECK-LABEL: @test_vhcaddq_rot90_m_s8(
// CHECK-NEXT:  entry:
// CHECK-NEXT:    [[TMP0:%.*]] = zext i16 [[P:%.*]] to i32
// CHECK-NEXT:    [[TMP1:%.*]] = call <16 x i1> @llvm.arm.mve.pred.i2v.v16i1(i32 [[TMP0]])
// CHECK-NEXT:    [[TMP2:%.*]] = call <16 x i8> @llvm.arm.mve.vcaddq.predicated.v16i8.v16i1(i32 0, i32 0, <16 x i8> [[INACTIVE:%.*]], <16 x i8> [[A:%.*]], <16 x i8> [[B:%.*]], <16 x i1> [[TMP1]])
// CHECK-NEXT:    ret <16 x i8> [[TMP2]]
//
int8x16_t test_vhcaddq_rot90_m_s8(int8x16_t inactive, int8x16_t a, int8x16_t b, mve_pred16_t p)
{
#ifdef POLYMORPHIC
    return vhcaddq_rot90_m(inactive, a, b, p);
#else
    return vhcaddq_rot90_m_s8(inactive, a, b, p);
#endif
}

// CHECK-LABEL: @test_vhcaddq_rot90_m_s16(
// CHECK-NEXT:  entry:
// CHECK-NEXT:    [[TMP0:%.*]] = zext i16 [[P:%.*]] to i32
// CHECK-NEXT:    [[TMP1:%.*]] = call <8 x i1> @llvm.arm.mve.pred.i2v.v8i1(i32 [[TMP0]])
// CHECK-NEXT:    [[TMP2:%.*]] = call <8 x i16> @llvm.arm.mve.vcaddq.predicated.v8i16.v8i1(i32 0, i32 0, <8 x i16> [[INACTIVE:%.*]], <8 x i16> [[A:%.*]], <8 x i16> [[B:%.*]], <8 x i1> [[TMP1]])
// CHECK-NEXT:    ret <8 x i16> [[TMP2]]
//
int16x8_t test_vhcaddq_rot90_m_s16(int16x8_t inactive, int16x8_t a, int16x8_t b, mve_pred16_t p)
{
#ifdef POLYMORPHIC
    return vhcaddq_rot90_m(inactive, a, b, p);
#else
    return vhcaddq_rot90_m_s16(inactive, a, b, p);
#endif
}

// CHECK-LABEL: @test_vhcaddq_rot90_m_s32(
// CHECK-NEXT:  entry:
// CHECK-NEXT:    [[TMP0:%.*]] = zext i16 [[P:%.*]] to i32
// CHECK-NEXT:    [[TMP1:%.*]] = call <4 x i1> @llvm.arm.mve.pred.i2v.v4i1(i32 [[TMP0]])
// CHECK-NEXT:    [[TMP2:%.*]] = call <4 x i32> @llvm.arm.mve.vcaddq.predicated.v4i32.v4i1(i32 0, i32 0, <4 x i32> [[INACTIVE:%.*]], <4 x i32> [[A:%.*]], <4 x i32> [[B:%.*]], <4 x i1> [[TMP1]])
// CHECK-NEXT:    ret <4 x i32> [[TMP2]]
//
int32x4_t test_vhcaddq_rot90_m_s32(int32x4_t inactive, int32x4_t a, int32x4_t b, mve_pred16_t p)
{
#ifdef POLYMORPHIC
    return vhcaddq_rot90_m(inactive, a, b, p);
#else
    return vhcaddq_rot90_m_s32(inactive, a, b, p);
#endif
}

// CHECK-LABEL: @test_vhcaddq_rot270_m_s8(
// CHECK-NEXT:  entry:
// CHECK-NEXT:    [[TMP0:%.*]] = zext i16 [[P:%.*]] to i32
// CHECK-NEXT:    [[TMP1:%.*]] = call <16 x i1> @llvm.arm.mve.pred.i2v.v16i1(i32 [[TMP0]])
// CHECK-NEXT:    [[TMP2:%.*]] = call <16 x i8> @llvm.arm.mve.vcaddq.predicated.v16i8.v16i1(i32 0, i32 1, <16 x i8> [[INACTIVE:%.*]], <16 x i8> [[A:%.*]], <16 x i8> [[B:%.*]], <16 x i1> [[TMP1]])
// CHECK-NEXT:    ret <16 x i8> [[TMP2]]
//
int8x16_t test_vhcaddq_rot270_m_s8(int8x16_t inactive, int8x16_t a, int8x16_t b, mve_pred16_t p)
{
#ifdef POLYMORPHIC
    return vhcaddq_rot270_m(inactive, a, b, p);
#else
    return vhcaddq_rot270_m_s8(inactive, a, b, p);
#endif
}

// CHECK-LABEL: @test_vhcaddq_rot270_m_s16(
// CHECK-NEXT:  entry:
// CHECK-NEXT:    [[TMP0:%.*]] = zext i16 [[P:%.*]] to i32
// CHECK-NEXT:    [[TMP1:%.*]] = call <8 x i1> @llvm.arm.mve.pred.i2v.v8i1(i32 [[TMP0]])
// CHECK-NEXT:    [[TMP2:%.*]] = call <8 x i16> @llvm.arm.mve.vcaddq.predicated.v8i16.v8i1(i32 0, i32 1, <8 x i16> [[INACTIVE:%.*]], <8 x i16> [[A:%.*]], <8 x i16> [[B:%.*]], <8 x i1> [[TMP1]])
// CHECK-NEXT:    ret <8 x i16> [[TMP2]]
//
int16x8_t test_vhcaddq_rot270_m_s16(int16x8_t inactive, int16x8_t a, int16x8_t b, mve_pred16_t p)
{
#ifdef POLYMORPHIC
    return vhcaddq_rot270_m(inactive, a, b, p);
#else
    return vhcaddq_rot270_m_s16(inactive, a, b, p);
#endif
}

// CHECK-LABEL: @test_vhcaddq_rot270_m_s32(
// CHECK-NEXT:  entry:
// CHECK-NEXT:    [[TMP0:%.*]] = zext i16 [[P:%.*]] to i32
// CHECK-NEXT:    [[TMP1:%.*]] = call <4 x i1> @llvm.arm.mve.pred.i2v.v4i1(i32 [[TMP0]])
// CHECK-NEXT:    [[TMP2:%.*]] = call <4 x i32> @llvm.arm.mve.vcaddq.predicated.v4i32.v4i1(i32 0, i32 1, <4 x i32> [[INACTIVE:%.*]], <4 x i32> [[A:%.*]], <4 x i32> [[B:%.*]], <4 x i1> [[TMP1]])
// CHECK-NEXT:    ret <4 x i32> [[TMP2]]
//
int32x4_t test_vhcaddq_rot270_m_s32(int32x4_t inactive, int32x4_t a, int32x4_t b, mve_pred16_t p)
{
#ifdef POLYMORPHIC
    return vhcaddq_rot270_m(inactive, a, b, p);
#else
    return vhcaddq_rot270_m_s32(inactive, a, b, p);
#endif
}
