// REQUIRES: aarch64-registered-target || arm-registered-target

// NOTE: Assertions have been autogenerated by utils/update_cc_test_checks.py
// RUN: %clang_cc1 -triple thumbv8.1m.main-none-none-eabi -target-feature +mve -mfloat-abi hard -fallow-half-arguments-and-returns -O0 -disable-O0-optnone -S -emit-llvm -o - %s | opt -S -mem2reg | FileCheck %s
// RUN: %clang_cc1 -triple thumbv8.1m.main-none-none-eabi -target-feature +mve -mfloat-abi hard -fallow-half-arguments-and-returns -O0 -disable-O0-optnone -DPOLYMORPHIC -S -emit-llvm -o - %s | opt -S -mem2reg | FileCheck %s

#include <arm_mve.h>

// CHECK-LABEL: @test_vmovlbq_s8(
// CHECK-NEXT:  entry:
// CHECK-NEXT:    [[TMP0:%.*]] = shufflevector <16 x i8> [[A:%.*]], <16 x i8> poison, <8 x i32> <i32 0, i32 2, i32 4, i32 6, i32 8, i32 10, i32 12, i32 14>
// CHECK-NEXT:    [[TMP1:%.*]] = sext <8 x i8> [[TMP0]] to <8 x i16>
// CHECK-NEXT:    ret <8 x i16> [[TMP1]]
//
int16x8_t test_vmovlbq_s8(int8x16_t a)
{
#ifdef POLYMORPHIC
    return vmovlbq(a);
#else /* POLYMORPHIC */
    return vmovlbq_s8(a);
#endif /* POLYMORPHIC */
}

// CHECK-LABEL: @test_vmovlbq_s16(
// CHECK-NEXT:  entry:
// CHECK-NEXT:    [[TMP0:%.*]] = shufflevector <8 x i16> [[A:%.*]], <8 x i16> poison, <4 x i32> <i32 0, i32 2, i32 4, i32 6>
// CHECK-NEXT:    [[TMP1:%.*]] = sext <4 x i16> [[TMP0]] to <4 x i32>
// CHECK-NEXT:    ret <4 x i32> [[TMP1]]
//
int32x4_t test_vmovlbq_s16(int16x8_t a)
{
#ifdef POLYMORPHIC
    return vmovlbq(a);
#else /* POLYMORPHIC */
    return vmovlbq_s16(a);
#endif /* POLYMORPHIC */
}

// CHECK-LABEL: @test_vmovlbq_u8(
// CHECK-NEXT:  entry:
// CHECK-NEXT:    [[TMP0:%.*]] = shufflevector <16 x i8> [[A:%.*]], <16 x i8> poison, <8 x i32> <i32 0, i32 2, i32 4, i32 6, i32 8, i32 10, i32 12, i32 14>
// CHECK-NEXT:    [[TMP1:%.*]] = zext <8 x i8> [[TMP0]] to <8 x i16>
// CHECK-NEXT:    ret <8 x i16> [[TMP1]]
//
uint16x8_t test_vmovlbq_u8(uint8x16_t a)
{
#ifdef POLYMORPHIC
    return vmovlbq(a);
#else /* POLYMORPHIC */
    return vmovlbq_u8(a);
#endif /* POLYMORPHIC */
}

// CHECK-LABEL: @test_vmovlbq_u16(
// CHECK-NEXT:  entry:
// CHECK-NEXT:    [[TMP0:%.*]] = shufflevector <8 x i16> [[A:%.*]], <8 x i16> poison, <4 x i32> <i32 0, i32 2, i32 4, i32 6>
// CHECK-NEXT:    [[TMP1:%.*]] = zext <4 x i16> [[TMP0]] to <4 x i32>
// CHECK-NEXT:    ret <4 x i32> [[TMP1]]
//
uint32x4_t test_vmovlbq_u16(uint16x8_t a)
{
#ifdef POLYMORPHIC
    return vmovlbq(a);
#else /* POLYMORPHIC */
    return vmovlbq_u16(a);
#endif /* POLYMORPHIC */
}

// CHECK-LABEL: @test_vmovltq_s8(
// CHECK-NEXT:  entry:
// CHECK-NEXT:    [[TMP0:%.*]] = shufflevector <16 x i8> [[A:%.*]], <16 x i8> poison, <8 x i32> <i32 1, i32 3, i32 5, i32 7, i32 9, i32 11, i32 13, i32 15>
// CHECK-NEXT:    [[TMP1:%.*]] = sext <8 x i8> [[TMP0]] to <8 x i16>
// CHECK-NEXT:    ret <8 x i16> [[TMP1]]
//
int16x8_t test_vmovltq_s8(int8x16_t a)
{
#ifdef POLYMORPHIC
    return vmovltq(a);
#else /* POLYMORPHIC */
    return vmovltq_s8(a);
#endif /* POLYMORPHIC */
}

// CHECK-LABEL: @test_vmovltq_s16(
// CHECK-NEXT:  entry:
// CHECK-NEXT:    [[TMP0:%.*]] = shufflevector <8 x i16> [[A:%.*]], <8 x i16> poison, <4 x i32> <i32 1, i32 3, i32 5, i32 7>
// CHECK-NEXT:    [[TMP1:%.*]] = sext <4 x i16> [[TMP0]] to <4 x i32>
// CHECK-NEXT:    ret <4 x i32> [[TMP1]]
//
int32x4_t test_vmovltq_s16(int16x8_t a)
{
#ifdef POLYMORPHIC
    return vmovltq(a);
#else /* POLYMORPHIC */
    return vmovltq_s16(a);
#endif /* POLYMORPHIC */
}

// CHECK-LABEL: @test_vmovltq_u8(
// CHECK-NEXT:  entry:
// CHECK-NEXT:    [[TMP0:%.*]] = shufflevector <16 x i8> [[A:%.*]], <16 x i8> poison, <8 x i32> <i32 1, i32 3, i32 5, i32 7, i32 9, i32 11, i32 13, i32 15>
// CHECK-NEXT:    [[TMP1:%.*]] = zext <8 x i8> [[TMP0]] to <8 x i16>
// CHECK-NEXT:    ret <8 x i16> [[TMP1]]
//
uint16x8_t test_vmovltq_u8(uint8x16_t a)
{
#ifdef POLYMORPHIC
    return vmovltq(a);
#else /* POLYMORPHIC */
    return vmovltq_u8(a);
#endif /* POLYMORPHIC */
}

// CHECK-LABEL: @test_vmovltq_u16(
// CHECK-NEXT:  entry:
// CHECK-NEXT:    [[TMP0:%.*]] = shufflevector <8 x i16> [[A:%.*]], <8 x i16> poison, <4 x i32> <i32 1, i32 3, i32 5, i32 7>
// CHECK-NEXT:    [[TMP1:%.*]] = zext <4 x i16> [[TMP0]] to <4 x i32>
// CHECK-NEXT:    ret <4 x i32> [[TMP1]]
//
uint32x4_t test_vmovltq_u16(uint16x8_t a)
{
#ifdef POLYMORPHIC
    return vmovltq(a);
#else /* POLYMORPHIC */
    return vmovltq_u16(a);
#endif /* POLYMORPHIC */
}

// CHECK-LABEL: @test_vmovlbq_m_s8(
// CHECK-NEXT:  entry:
// CHECK-NEXT:    [[TMP0:%.*]] = zext i16 [[P:%.*]] to i32
// CHECK-NEXT:    [[TMP1:%.*]] = call <8 x i1> @llvm.arm.mve.pred.i2v.v8i1(i32 [[TMP0]])
// CHECK-NEXT:    [[TMP2:%.*]] = call <8 x i16> @llvm.arm.mve.vmovl.predicated.v8i16.v16i8.v8i1(<16 x i8> [[A:%.*]], i32 0, i32 0, <8 x i1> [[TMP1]], <8 x i16> [[INACTIVE:%.*]])
// CHECK-NEXT:    ret <8 x i16> [[TMP2]]
//
int16x8_t test_vmovlbq_m_s8(int16x8_t inactive, int8x16_t a, mve_pred16_t p)
{
#ifdef POLYMORPHIC
    return vmovlbq_m(inactive, a, p);
#else /* POLYMORPHIC */
    return vmovlbq_m_s8(inactive, a, p);
#endif /* POLYMORPHIC */
}

// CHECK-LABEL: @test_vmovlbq_m_s16(
// CHECK-NEXT:  entry:
// CHECK-NEXT:    [[TMP0:%.*]] = zext i16 [[P:%.*]] to i32
// CHECK-NEXT:    [[TMP1:%.*]] = call <4 x i1> @llvm.arm.mve.pred.i2v.v4i1(i32 [[TMP0]])
// CHECK-NEXT:    [[TMP2:%.*]] = call <4 x i32> @llvm.arm.mve.vmovl.predicated.v4i32.v8i16.v4i1(<8 x i16> [[A:%.*]], i32 0, i32 0, <4 x i1> [[TMP1]], <4 x i32> [[INACTIVE:%.*]])
// CHECK-NEXT:    ret <4 x i32> [[TMP2]]
//
int32x4_t test_vmovlbq_m_s16(int32x4_t inactive, int16x8_t a, mve_pred16_t p)
{
#ifdef POLYMORPHIC
    return vmovlbq_m(inactive, a, p);
#else /* POLYMORPHIC */
    return vmovlbq_m_s16(inactive, a, p);
#endif /* POLYMORPHIC */
}

// CHECK-LABEL: @test_vmovlbq_m_u8(
// CHECK-NEXT:  entry:
// CHECK-NEXT:    [[TMP0:%.*]] = zext i16 [[P:%.*]] to i32
// CHECK-NEXT:    [[TMP1:%.*]] = call <8 x i1> @llvm.arm.mve.pred.i2v.v8i1(i32 [[TMP0]])
// CHECK-NEXT:    [[TMP2:%.*]] = call <8 x i16> @llvm.arm.mve.vmovl.predicated.v8i16.v16i8.v8i1(<16 x i8> [[A:%.*]], i32 1, i32 0, <8 x i1> [[TMP1]], <8 x i16> [[INACTIVE:%.*]])
// CHECK-NEXT:    ret <8 x i16> [[TMP2]]
//
uint16x8_t test_vmovlbq_m_u8(uint16x8_t inactive, uint8x16_t a, mve_pred16_t p)
{
#ifdef POLYMORPHIC
    return vmovlbq_m(inactive, a, p);
#else /* POLYMORPHIC */
    return vmovlbq_m_u8(inactive, a, p);
#endif /* POLYMORPHIC */
}

// CHECK-LABEL: @test_vmovlbq_m_u16(
// CHECK-NEXT:  entry:
// CHECK-NEXT:    [[TMP0:%.*]] = zext i16 [[P:%.*]] to i32
// CHECK-NEXT:    [[TMP1:%.*]] = call <4 x i1> @llvm.arm.mve.pred.i2v.v4i1(i32 [[TMP0]])
// CHECK-NEXT:    [[TMP2:%.*]] = call <4 x i32> @llvm.arm.mve.vmovl.predicated.v4i32.v8i16.v4i1(<8 x i16> [[A:%.*]], i32 1, i32 0, <4 x i1> [[TMP1]], <4 x i32> [[INACTIVE:%.*]])
// CHECK-NEXT:    ret <4 x i32> [[TMP2]]
//
uint32x4_t test_vmovlbq_m_u16(uint32x4_t inactive, uint16x8_t a, mve_pred16_t p)
{
#ifdef POLYMORPHIC
    return vmovlbq_m(inactive, a, p);
#else /* POLYMORPHIC */
    return vmovlbq_m_u16(inactive, a, p);
#endif /* POLYMORPHIC */
}

// CHECK-LABEL: @test_vmovltq_m_s8(
// CHECK-NEXT:  entry:
// CHECK-NEXT:    [[TMP0:%.*]] = zext i16 [[P:%.*]] to i32
// CHECK-NEXT:    [[TMP1:%.*]] = call <8 x i1> @llvm.arm.mve.pred.i2v.v8i1(i32 [[TMP0]])
// CHECK-NEXT:    [[TMP2:%.*]] = call <8 x i16> @llvm.arm.mve.vmovl.predicated.v8i16.v16i8.v8i1(<16 x i8> [[A:%.*]], i32 0, i32 1, <8 x i1> [[TMP1]], <8 x i16> [[INACTIVE:%.*]])
// CHECK-NEXT:    ret <8 x i16> [[TMP2]]
//
int16x8_t test_vmovltq_m_s8(int16x8_t inactive, int8x16_t a, mve_pred16_t p)
{
#ifdef POLYMORPHIC
    return vmovltq_m(inactive, a, p);
#else /* POLYMORPHIC */
    return vmovltq_m_s8(inactive, a, p);
#endif /* POLYMORPHIC */
}

// CHECK-LABEL: @test_vmovltq_m_s16(
// CHECK-NEXT:  entry:
// CHECK-NEXT:    [[TMP0:%.*]] = zext i16 [[P:%.*]] to i32
// CHECK-NEXT:    [[TMP1:%.*]] = call <4 x i1> @llvm.arm.mve.pred.i2v.v4i1(i32 [[TMP0]])
// CHECK-NEXT:    [[TMP2:%.*]] = call <4 x i32> @llvm.arm.mve.vmovl.predicated.v4i32.v8i16.v4i1(<8 x i16> [[A:%.*]], i32 0, i32 1, <4 x i1> [[TMP1]], <4 x i32> [[INACTIVE:%.*]])
// CHECK-NEXT:    ret <4 x i32> [[TMP2]]
//
int32x4_t test_vmovltq_m_s16(int32x4_t inactive, int16x8_t a, mve_pred16_t p)
{
#ifdef POLYMORPHIC
    return vmovltq_m(inactive, a, p);
#else /* POLYMORPHIC */
    return vmovltq_m_s16(inactive, a, p);
#endif /* POLYMORPHIC */
}

// CHECK-LABEL: @test_vmovltq_m_u8(
// CHECK-NEXT:  entry:
// CHECK-NEXT:    [[TMP0:%.*]] = zext i16 [[P:%.*]] to i32
// CHECK-NEXT:    [[TMP1:%.*]] = call <8 x i1> @llvm.arm.mve.pred.i2v.v8i1(i32 [[TMP0]])
// CHECK-NEXT:    [[TMP2:%.*]] = call <8 x i16> @llvm.arm.mve.vmovl.predicated.v8i16.v16i8.v8i1(<16 x i8> [[A:%.*]], i32 1, i32 1, <8 x i1> [[TMP1]], <8 x i16> [[INACTIVE:%.*]])
// CHECK-NEXT:    ret <8 x i16> [[TMP2]]
//
uint16x8_t test_vmovltq_m_u8(uint16x8_t inactive, uint8x16_t a, mve_pred16_t p)
{
#ifdef POLYMORPHIC
    return vmovltq_m(inactive, a, p);
#else /* POLYMORPHIC */
    return vmovltq_m_u8(inactive, a, p);
#endif /* POLYMORPHIC */
}

// CHECK-LABEL: @test_vmovltq_m_u16(
// CHECK-NEXT:  entry:
// CHECK-NEXT:    [[TMP0:%.*]] = zext i16 [[P:%.*]] to i32
// CHECK-NEXT:    [[TMP1:%.*]] = call <4 x i1> @llvm.arm.mve.pred.i2v.v4i1(i32 [[TMP0]])
// CHECK-NEXT:    [[TMP2:%.*]] = call <4 x i32> @llvm.arm.mve.vmovl.predicated.v4i32.v8i16.v4i1(<8 x i16> [[A:%.*]], i32 1, i32 1, <4 x i1> [[TMP1]], <4 x i32> [[INACTIVE:%.*]])
// CHECK-NEXT:    ret <4 x i32> [[TMP2]]
//
uint32x4_t test_vmovltq_m_u16(uint32x4_t inactive, uint16x8_t a, mve_pred16_t p)
{
#ifdef POLYMORPHIC
    return vmovltq_m(inactive, a, p);
#else /* POLYMORPHIC */
    return vmovltq_m_u16(inactive, a, p);
#endif /* POLYMORPHIC */
}

// CHECK-LABEL: @test_vmovlbq_x_s8(
// CHECK-NEXT:  entry:
// CHECK-NEXT:    [[TMP0:%.*]] = zext i16 [[P:%.*]] to i32
// CHECK-NEXT:    [[TMP1:%.*]] = call <8 x i1> @llvm.arm.mve.pred.i2v.v8i1(i32 [[TMP0]])
// CHECK-NEXT:    [[TMP2:%.*]] = call <8 x i16> @llvm.arm.mve.vmovl.predicated.v8i16.v16i8.v8i1(<16 x i8> [[A:%.*]], i32 0, i32 0, <8 x i1> [[TMP1]], <8 x i16> undef)
// CHECK-NEXT:    ret <8 x i16> [[TMP2]]
//
int16x8_t test_vmovlbq_x_s8(int8x16_t a, mve_pred16_t p)
{
#ifdef POLYMORPHIC
    return vmovlbq_x(a, p);
#else /* POLYMORPHIC */
    return vmovlbq_x_s8(a, p);
#endif /* POLYMORPHIC */
}

// CHECK-LABEL: @test_vmovlbq_x_s16(
// CHECK-NEXT:  entry:
// CHECK-NEXT:    [[TMP0:%.*]] = zext i16 [[P:%.*]] to i32
// CHECK-NEXT:    [[TMP1:%.*]] = call <4 x i1> @llvm.arm.mve.pred.i2v.v4i1(i32 [[TMP0]])
// CHECK-NEXT:    [[TMP2:%.*]] = call <4 x i32> @llvm.arm.mve.vmovl.predicated.v4i32.v8i16.v4i1(<8 x i16> [[A:%.*]], i32 0, i32 0, <4 x i1> [[TMP1]], <4 x i32> undef)
// CHECK-NEXT:    ret <4 x i32> [[TMP2]]
//
int32x4_t test_vmovlbq_x_s16(int16x8_t a, mve_pred16_t p)
{
#ifdef POLYMORPHIC
    return vmovlbq_x(a, p);
#else /* POLYMORPHIC */
    return vmovlbq_x_s16(a, p);
#endif /* POLYMORPHIC */
}

// CHECK-LABEL: @test_vmovlbq_x_u8(
// CHECK-NEXT:  entry:
// CHECK-NEXT:    [[TMP0:%.*]] = zext i16 [[P:%.*]] to i32
// CHECK-NEXT:    [[TMP1:%.*]] = call <8 x i1> @llvm.arm.mve.pred.i2v.v8i1(i32 [[TMP0]])
// CHECK-NEXT:    [[TMP2:%.*]] = call <8 x i16> @llvm.arm.mve.vmovl.predicated.v8i16.v16i8.v8i1(<16 x i8> [[A:%.*]], i32 1, i32 0, <8 x i1> [[TMP1]], <8 x i16> undef)
// CHECK-NEXT:    ret <8 x i16> [[TMP2]]
//
uint16x8_t test_vmovlbq_x_u8(uint8x16_t a, mve_pred16_t p)
{
#ifdef POLYMORPHIC
    return vmovlbq_x(a, p);
#else /* POLYMORPHIC */
    return vmovlbq_x_u8(a, p);
#endif /* POLYMORPHIC */
}

// CHECK-LABEL: @test_vmovlbq_x_u16(
// CHECK-NEXT:  entry:
// CHECK-NEXT:    [[TMP0:%.*]] = zext i16 [[P:%.*]] to i32
// CHECK-NEXT:    [[TMP1:%.*]] = call <4 x i1> @llvm.arm.mve.pred.i2v.v4i1(i32 [[TMP0]])
// CHECK-NEXT:    [[TMP2:%.*]] = call <4 x i32> @llvm.arm.mve.vmovl.predicated.v4i32.v8i16.v4i1(<8 x i16> [[A:%.*]], i32 1, i32 0, <4 x i1> [[TMP1]], <4 x i32> undef)
// CHECK-NEXT:    ret <4 x i32> [[TMP2]]
//
uint32x4_t test_vmovlbq_x_u16(uint16x8_t a, mve_pred16_t p)
{
#ifdef POLYMORPHIC
    return vmovlbq_x(a, p);
#else /* POLYMORPHIC */
    return vmovlbq_x_u16(a, p);
#endif /* POLYMORPHIC */
}

// CHECK-LABEL: @test_vmovltq_x_s8(
// CHECK-NEXT:  entry:
// CHECK-NEXT:    [[TMP0:%.*]] = zext i16 [[P:%.*]] to i32
// CHECK-NEXT:    [[TMP1:%.*]] = call <8 x i1> @llvm.arm.mve.pred.i2v.v8i1(i32 [[TMP0]])
// CHECK-NEXT:    [[TMP2:%.*]] = call <8 x i16> @llvm.arm.mve.vmovl.predicated.v8i16.v16i8.v8i1(<16 x i8> [[A:%.*]], i32 0, i32 1, <8 x i1> [[TMP1]], <8 x i16> undef)
// CHECK-NEXT:    ret <8 x i16> [[TMP2]]
//
int16x8_t test_vmovltq_x_s8(int8x16_t a, mve_pred16_t p)
{
#ifdef POLYMORPHIC
    return vmovltq_x(a, p);
#else /* POLYMORPHIC */
    return vmovltq_x_s8(a, p);
#endif /* POLYMORPHIC */
}

// CHECK-LABEL: @test_vmovltq_x_s16(
// CHECK-NEXT:  entry:
// CHECK-NEXT:    [[TMP0:%.*]] = zext i16 [[P:%.*]] to i32
// CHECK-NEXT:    [[TMP1:%.*]] = call <4 x i1> @llvm.arm.mve.pred.i2v.v4i1(i32 [[TMP0]])
// CHECK-NEXT:    [[TMP2:%.*]] = call <4 x i32> @llvm.arm.mve.vmovl.predicated.v4i32.v8i16.v4i1(<8 x i16> [[A:%.*]], i32 0, i32 1, <4 x i1> [[TMP1]], <4 x i32> undef)
// CHECK-NEXT:    ret <4 x i32> [[TMP2]]
//
int32x4_t test_vmovltq_x_s16(int16x8_t a, mve_pred16_t p)
{
#ifdef POLYMORPHIC
    return vmovltq_x(a, p);
#else /* POLYMORPHIC */
    return vmovltq_x_s16(a, p);
#endif /* POLYMORPHIC */
}

// CHECK-LABEL: @test_vmovltq_x_u8(
// CHECK-NEXT:  entry:
// CHECK-NEXT:    [[TMP0:%.*]] = zext i16 [[P:%.*]] to i32
// CHECK-NEXT:    [[TMP1:%.*]] = call <8 x i1> @llvm.arm.mve.pred.i2v.v8i1(i32 [[TMP0]])
// CHECK-NEXT:    [[TMP2:%.*]] = call <8 x i16> @llvm.arm.mve.vmovl.predicated.v8i16.v16i8.v8i1(<16 x i8> [[A:%.*]], i32 1, i32 1, <8 x i1> [[TMP1]], <8 x i16> undef)
// CHECK-NEXT:    ret <8 x i16> [[TMP2]]
//
uint16x8_t test_vmovltq_x_u8(uint8x16_t a, mve_pred16_t p)
{
#ifdef POLYMORPHIC
    return vmovltq_x(a, p);
#else /* POLYMORPHIC */
    return vmovltq_x_u8(a, p);
#endif /* POLYMORPHIC */
}

// CHECK-LABEL: @test_vmovltq_x_u16(
// CHECK-NEXT:  entry:
// CHECK-NEXT:    [[TMP0:%.*]] = zext i16 [[P:%.*]] to i32
// CHECK-NEXT:    [[TMP1:%.*]] = call <4 x i1> @llvm.arm.mve.pred.i2v.v4i1(i32 [[TMP0]])
// CHECK-NEXT:    [[TMP2:%.*]] = call <4 x i32> @llvm.arm.mve.vmovl.predicated.v4i32.v8i16.v4i1(<8 x i16> [[A:%.*]], i32 1, i32 1, <4 x i1> [[TMP1]], <4 x i32> undef)
// CHECK-NEXT:    ret <4 x i32> [[TMP2]]
//
uint32x4_t test_vmovltq_x_u16(uint16x8_t a, mve_pred16_t p)
{
#ifdef POLYMORPHIC
    return vmovltq_x(a, p);
#else /* POLYMORPHIC */
    return vmovltq_x_u16(a, p);
#endif /* POLYMORPHIC */
}

