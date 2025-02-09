// REQUIRES: aarch64-registered-target || arm-registered-target

// NOTE: Assertions have been autogenerated by utils/update_cc_test_checks.py
// RUN: %clang_cc1 -triple thumbv8.1m.main-none-none-eabi -target-feature +mve.fp -mfloat-abi hard -fallow-half-arguments-and-returns -O0 -disable-O0-optnone -S -emit-llvm -o - %s | opt -S -mem2reg -sroa -early-cse | FileCheck %s
// RUN: %clang_cc1 -triple thumbv8.1m.main-none-none-eabi -target-feature +mve.fp -mfloat-abi hard -fallow-half-arguments-and-returns -O0 -disable-O0-optnone -DPOLYMORPHIC -S -emit-llvm -o - %s | opt -S -mem2reg -sroa -early-cse | FileCheck %s

#include <arm_mve.h>

// CHECK-LABEL: @test_vctp16q(
// CHECK-NEXT:  entry:
// CHECK-NEXT:    [[TMP0:%.*]] = call <8 x i1> @llvm.arm.mve.vctp16(i32 [[A:%.*]])
// CHECK-NEXT:    [[TMP1:%.*]] = call i32 @llvm.arm.mve.pred.v2i.v8i1(<8 x i1> [[TMP0]])
// CHECK-NEXT:    [[TMP2:%.*]] = trunc i32 [[TMP1]] to i16
// CHECK-NEXT:    ret i16 [[TMP2]]
//
mve_pred16_t test_vctp16q(uint32_t a)
{
    return vctp16q(a);
}

// CHECK-LABEL: @test_vctp16q_m(
// CHECK-NEXT:  entry:
// CHECK-NEXT:    [[TMP0:%.*]] = zext i16 [[P:%.*]] to i32
// CHECK-NEXT:    [[TMP1:%.*]] = call <8 x i1> @llvm.arm.mve.pred.i2v.v8i1(i32 [[TMP0]])
// CHECK-NEXT:    [[TMP2:%.*]] = call <8 x i1> @llvm.arm.mve.vctp16(i32 [[A:%.*]])
// CHECK-NEXT:    [[TMP3:%.*]] = and <8 x i1> [[TMP1]], [[TMP2]]
// CHECK-NEXT:    [[TMP4:%.*]] = call i32 @llvm.arm.mve.pred.v2i.v8i1(<8 x i1> [[TMP3]])
// CHECK-NEXT:    [[TMP5:%.*]] = trunc i32 [[TMP4]] to i16
// CHECK-NEXT:    ret i16 [[TMP5]]
//
mve_pred16_t test_vctp16q_m(uint32_t a, mve_pred16_t p)
{
    return vctp16q_m(a, p);
}

// CHECK-LABEL: @test_vctp32q(
// CHECK-NEXT:  entry:
// CHECK-NEXT:    [[TMP0:%.*]] = call <4 x i1> @llvm.arm.mve.vctp32(i32 [[A:%.*]])
// CHECK-NEXT:    [[TMP1:%.*]] = call i32 @llvm.arm.mve.pred.v2i.v4i1(<4 x i1> [[TMP0]])
// CHECK-NEXT:    [[TMP2:%.*]] = trunc i32 [[TMP1]] to i16
// CHECK-NEXT:    ret i16 [[TMP2]]
//
mve_pred16_t test_vctp32q(uint32_t a)
{
    return vctp32q(a);
}

// CHECK-LABEL: @test_vctp32q_m(
// CHECK-NEXT:  entry:
// CHECK-NEXT:    [[TMP0:%.*]] = zext i16 [[P:%.*]] to i32
// CHECK-NEXT:    [[TMP1:%.*]] = call <4 x i1> @llvm.arm.mve.pred.i2v.v4i1(i32 [[TMP0]])
// CHECK-NEXT:    [[TMP2:%.*]] = call <4 x i1> @llvm.arm.mve.vctp32(i32 [[A:%.*]])
// CHECK-NEXT:    [[TMP3:%.*]] = and <4 x i1> [[TMP1]], [[TMP2]]
// CHECK-NEXT:    [[TMP4:%.*]] = call i32 @llvm.arm.mve.pred.v2i.v4i1(<4 x i1> [[TMP3]])
// CHECK-NEXT:    [[TMP5:%.*]] = trunc i32 [[TMP4]] to i16
// CHECK-NEXT:    ret i16 [[TMP5]]
//
mve_pred16_t test_vctp32q_m(uint32_t a, mve_pred16_t p)
{
    return vctp32q_m(a, p);
}

// CHECK-LABEL: @test_vctp64q(
// CHECK-NEXT:  entry:
// CHECK-NEXT:    [[TMP0:%.*]] = call <4 x i1> @llvm.arm.mve.vctp64(i32 [[A:%.*]])
// CHECK-NEXT:    [[TMP1:%.*]] = call i32 @llvm.arm.mve.pred.v2i.v4i1(<4 x i1> [[TMP0]])
// CHECK-NEXT:    [[TMP2:%.*]] = trunc i32 [[TMP1]] to i16
// CHECK-NEXT:    ret i16 [[TMP2]]
//
mve_pred16_t test_vctp64q(uint32_t a)
{
    return vctp64q(a);
}

// CHECK-LABEL: @test_vctp64q_m(
// CHECK-NEXT:  entry:
// CHECK-NEXT:    [[TMP0:%.*]] = zext i16 [[P:%.*]] to i32
// CHECK-NEXT:    [[TMP1:%.*]] = call <4 x i1> @llvm.arm.mve.pred.i2v.v4i1(i32 [[TMP0]])
// CHECK-NEXT:    [[TMP2:%.*]] = call <4 x i1> @llvm.arm.mve.vctp64(i32 [[A:%.*]])
// CHECK-NEXT:    [[TMP3:%.*]] = and <4 x i1> [[TMP1]], [[TMP2]]
// CHECK-NEXT:    [[TMP4:%.*]] = call i32 @llvm.arm.mve.pred.v2i.v4i1(<4 x i1> [[TMP3]])
// CHECK-NEXT:    [[TMP5:%.*]] = trunc i32 [[TMP4]] to i16
// CHECK-NEXT:    ret i16 [[TMP5]]
//
mve_pred16_t test_vctp64q_m(uint32_t a, mve_pred16_t p)
{
    return vctp64q_m(a, p);
}

// CHECK-LABEL: @test_vctp8q(
// CHECK-NEXT:  entry:
// CHECK-NEXT:    [[TMP0:%.*]] = call <16 x i1> @llvm.arm.mve.vctp8(i32 [[A:%.*]])
// CHECK-NEXT:    [[TMP1:%.*]] = call i32 @llvm.arm.mve.pred.v2i.v16i1(<16 x i1> [[TMP0]])
// CHECK-NEXT:    [[TMP2:%.*]] = trunc i32 [[TMP1]] to i16
// CHECK-NEXT:    ret i16 [[TMP2]]
//
mve_pred16_t test_vctp8q(uint32_t a)
{
    return vctp8q(a);
}

// CHECK-LABEL: @test_vctp8q_m(
// CHECK-NEXT:  entry:
// CHECK-NEXT:    [[TMP0:%.*]] = zext i16 [[P:%.*]] to i32
// CHECK-NEXT:    [[TMP1:%.*]] = call <16 x i1> @llvm.arm.mve.pred.i2v.v16i1(i32 [[TMP0]])
// CHECK-NEXT:    [[TMP2:%.*]] = call <16 x i1> @llvm.arm.mve.vctp8(i32 [[A:%.*]])
// CHECK-NEXT:    [[TMP3:%.*]] = and <16 x i1> [[TMP1]], [[TMP2]]
// CHECK-NEXT:    [[TMP4:%.*]] = call i32 @llvm.arm.mve.pred.v2i.v16i1(<16 x i1> [[TMP3]])
// CHECK-NEXT:    [[TMP5:%.*]] = trunc i32 [[TMP4]] to i16
// CHECK-NEXT:    ret i16 [[TMP5]]
//
mve_pred16_t test_vctp8q_m(uint32_t a, mve_pred16_t p)
{
    return vctp8q_m(a, p);
}

// CHECK-LABEL: @test_vpnot(
// CHECK-NEXT:  entry:
// CHECK-NEXT:    [[TMP0:%.*]] = xor i16 [[A:%.*]], -1
// CHECK-NEXT:    ret i16 [[TMP0]]
//
mve_pred16_t test_vpnot(mve_pred16_t a)
{
    return vpnot(a);
}

// CHECK-LABEL: @test_vpselq_f16(
// CHECK-NEXT:  entry:
// CHECK-NEXT:    [[TMP0:%.*]] = zext i16 [[P:%.*]] to i32
// CHECK-NEXT:    [[TMP1:%.*]] = call <8 x i1> @llvm.arm.mve.pred.i2v.v8i1(i32 [[TMP0]])
// CHECK-NEXT:    [[TMP2:%.*]] = select <8 x i1> [[TMP1]], <8 x half> [[A:%.*]], <8 x half> [[B:%.*]]
// CHECK-NEXT:    ret <8 x half> [[TMP2]]
//
float16x8_t test_vpselq_f16(float16x8_t a, float16x8_t b, mve_pred16_t p)
{
#ifdef POLYMORPHIC
    return vpselq(a, b, p);
#else /* POLYMORPHIC */
    return vpselq_f16(a, b, p);
#endif /* POLYMORPHIC */
}

// CHECK-LABEL: @test_vpselq_f32(
// CHECK-NEXT:  entry:
// CHECK-NEXT:    [[TMP0:%.*]] = zext i16 [[P:%.*]] to i32
// CHECK-NEXT:    [[TMP1:%.*]] = call <4 x i1> @llvm.arm.mve.pred.i2v.v4i1(i32 [[TMP0]])
// CHECK-NEXT:    [[TMP2:%.*]] = select <4 x i1> [[TMP1]], <4 x float> [[A:%.*]], <4 x float> [[B:%.*]]
// CHECK-NEXT:    ret <4 x float> [[TMP2]]
//
float32x4_t test_vpselq_f32(float32x4_t a, float32x4_t b, mve_pred16_t p)
{
#ifdef POLYMORPHIC
    return vpselq(a, b, p);
#else /* POLYMORPHIC */
    return vpselq_f32(a, b, p);
#endif /* POLYMORPHIC */
}

// CHECK-LABEL: @test_vpselq_s16(
// CHECK-NEXT:  entry:
// CHECK-NEXT:    [[TMP0:%.*]] = zext i16 [[P:%.*]] to i32
// CHECK-NEXT:    [[TMP1:%.*]] = call <8 x i1> @llvm.arm.mve.pred.i2v.v8i1(i32 [[TMP0]])
// CHECK-NEXT:    [[TMP2:%.*]] = select <8 x i1> [[TMP1]], <8 x i16> [[A:%.*]], <8 x i16> [[B:%.*]]
// CHECK-NEXT:    ret <8 x i16> [[TMP2]]
//
int16x8_t test_vpselq_s16(int16x8_t a, int16x8_t b, mve_pred16_t p)
{
#ifdef POLYMORPHIC
    return vpselq(a, b, p);
#else /* POLYMORPHIC */
    return vpselq_s16(a, b, p);
#endif /* POLYMORPHIC */
}

// CHECK-LABEL: @test_vpselq_s32(
// CHECK-NEXT:  entry:
// CHECK-NEXT:    [[TMP0:%.*]] = zext i16 [[P:%.*]] to i32
// CHECK-NEXT:    [[TMP1:%.*]] = call <4 x i1> @llvm.arm.mve.pred.i2v.v4i1(i32 [[TMP0]])
// CHECK-NEXT:    [[TMP2:%.*]] = select <4 x i1> [[TMP1]], <4 x i32> [[A:%.*]], <4 x i32> [[B:%.*]]
// CHECK-NEXT:    ret <4 x i32> [[TMP2]]
//
int32x4_t test_vpselq_s32(int32x4_t a, int32x4_t b, mve_pred16_t p)
{
#ifdef POLYMORPHIC
    return vpselq(a, b, p);
#else /* POLYMORPHIC */
    return vpselq_s32(a, b, p);
#endif /* POLYMORPHIC */
}

// CHECK-LABEL: @test_vpselq_s64(
// CHECK-NEXT:  entry:
// CHECK-NEXT:    [[TMP0:%.*]] = zext i16 [[P:%.*]] to i32
// CHECK-NEXT:    [[TMP1:%.*]] = call <4 x i1> @llvm.arm.mve.pred.i2v.v4i1(i32 [[TMP0]])
// CHECK-NEXT:    [[TMP2:%.*]] = bitcast <2 x i64> [[A:%.*]] to <4 x i32>
// CHECK-NEXT:    [[TMP3:%.*]] = bitcast <2 x i64> [[B:%.*]] to <4 x i32>
// CHECK-NEXT:    [[TMP4:%.*]] = select <4 x i1> [[TMP1]], <4 x i32> [[TMP2]], <4 x i32> [[TMP3]]
// CHECK-NEXT:    [[TMP5:%.*]] = bitcast <4 x i32> [[TMP4]] to <2 x i64>
// CHECK-NEXT:    ret <2 x i64> [[TMP5]]
//
int64x2_t test_vpselq_s64(int64x2_t a, int64x2_t b, mve_pred16_t p)
{
#ifdef POLYMORPHIC
    return vpselq(a, b, p);
#else /* POLYMORPHIC */
    return vpselq_s64(a, b, p);
#endif /* POLYMORPHIC */
}

// CHECK-LABEL: @test_vpselq_s8(
// CHECK-NEXT:  entry:
// CHECK-NEXT:    [[TMP0:%.*]] = zext i16 [[P:%.*]] to i32
// CHECK-NEXT:    [[TMP1:%.*]] = call <16 x i1> @llvm.arm.mve.pred.i2v.v16i1(i32 [[TMP0]])
// CHECK-NEXT:    [[TMP2:%.*]] = select <16 x i1> [[TMP1]], <16 x i8> [[A:%.*]], <16 x i8> [[B:%.*]]
// CHECK-NEXT:    ret <16 x i8> [[TMP2]]
//
int8x16_t test_vpselq_s8(int8x16_t a, int8x16_t b, mve_pred16_t p)
{
#ifdef POLYMORPHIC
    return vpselq(a, b, p);
#else /* POLYMORPHIC */
    return vpselq_s8(a, b, p);
#endif /* POLYMORPHIC */
}

// CHECK-LABEL: @test_vpselq_u16(
// CHECK-NEXT:  entry:
// CHECK-NEXT:    [[TMP0:%.*]] = zext i16 [[P:%.*]] to i32
// CHECK-NEXT:    [[TMP1:%.*]] = call <8 x i1> @llvm.arm.mve.pred.i2v.v8i1(i32 [[TMP0]])
// CHECK-NEXT:    [[TMP2:%.*]] = select <8 x i1> [[TMP1]], <8 x i16> [[A:%.*]], <8 x i16> [[B:%.*]]
// CHECK-NEXT:    ret <8 x i16> [[TMP2]]
//
uint16x8_t test_vpselq_u16(uint16x8_t a, uint16x8_t b, mve_pred16_t p)
{
#ifdef POLYMORPHIC
    return vpselq(a, b, p);
#else /* POLYMORPHIC */
    return vpselq_u16(a, b, p);
#endif /* POLYMORPHIC */
}

// CHECK-LABEL: @test_vpselq_u32(
// CHECK-NEXT:  entry:
// CHECK-NEXT:    [[TMP0:%.*]] = zext i16 [[P:%.*]] to i32
// CHECK-NEXT:    [[TMP1:%.*]] = call <4 x i1> @llvm.arm.mve.pred.i2v.v4i1(i32 [[TMP0]])
// CHECK-NEXT:    [[TMP2:%.*]] = select <4 x i1> [[TMP1]], <4 x i32> [[A:%.*]], <4 x i32> [[B:%.*]]
// CHECK-NEXT:    ret <4 x i32> [[TMP2]]
//
uint32x4_t test_vpselq_u32(uint32x4_t a, uint32x4_t b, mve_pred16_t p)
{
#ifdef POLYMORPHIC
    return vpselq(a, b, p);
#else /* POLYMORPHIC */
    return vpselq_u32(a, b, p);
#endif /* POLYMORPHIC */
}

// CHECK-LABEL: @test_vpselq_u64(
// CHECK-NEXT:  entry:
// CHECK-NEXT:    [[TMP0:%.*]] = zext i16 [[P:%.*]] to i32
// CHECK-NEXT:    [[TMP1:%.*]] = call <4 x i1> @llvm.arm.mve.pred.i2v.v4i1(i32 [[TMP0]])
// CHECK-NEXT:    [[TMP2:%.*]] = bitcast <2 x i64> [[A:%.*]] to <4 x i32>
// CHECK-NEXT:    [[TMP3:%.*]] = bitcast <2 x i64> [[B:%.*]] to <4 x i32>
// CHECK-NEXT:    [[TMP4:%.*]] = select <4 x i1> [[TMP1]], <4 x i32> [[TMP2]], <4 x i32> [[TMP3]]
// CHECK-NEXT:    [[TMP5:%.*]] = bitcast <4 x i32> [[TMP4]] to <2 x i64>
// CHECK-NEXT:    ret <2 x i64> [[TMP5]]
//
uint64x2_t test_vpselq_u64(uint64x2_t a, uint64x2_t b, mve_pred16_t p)
{
#ifdef POLYMORPHIC
    return vpselq(a, b, p);
#else /* POLYMORPHIC */
    return vpselq_u64(a, b, p);
#endif /* POLYMORPHIC */
}

// CHECK-LABEL: @test_vpselq_u8(
// CHECK-NEXT:  entry:
// CHECK-NEXT:    [[TMP0:%.*]] = zext i16 [[P:%.*]] to i32
// CHECK-NEXT:    [[TMP1:%.*]] = call <16 x i1> @llvm.arm.mve.pred.i2v.v16i1(i32 [[TMP0]])
// CHECK-NEXT:    [[TMP2:%.*]] = select <16 x i1> [[TMP1]], <16 x i8> [[A:%.*]], <16 x i8> [[B:%.*]]
// CHECK-NEXT:    ret <16 x i8> [[TMP2]]
//
uint8x16_t test_vpselq_u8(uint8x16_t a, uint8x16_t b, mve_pred16_t p)
{
#ifdef POLYMORPHIC
    return vpselq(a, b, p);
#else /* POLYMORPHIC */
    return vpselq_u8(a, b, p);
#endif /* POLYMORPHIC */
}

