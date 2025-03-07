// This file is part of the FidelityFX SDK.
//
// Copyright (C) 2024 Advanced Micro Devices, Inc.
// 
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files(the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and /or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions :
//
// The above copyright notice and this permission notice shall be included in
// all copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
// THE SOFTWARE.
#if 0
;
; Input signature:
;
; Name                 Index   Mask Register SysValue  Format   Used
; -------------------- ----- ------ -------- -------- ------- ------
; SV_Position              0   xyzw        0      POS   float   x   
;
;
; Output signature:
;
; Name                 Index   Mask Register SysValue  Format   Used
; -------------------- ----- ------ -------- -------- ------- ------
; SV_Target                0   xyzw        0   TARGET   float   xyzw
;
; shader hash: 19decc2ff08fd3cbd2edcf26536e91df
;
; Pipeline Runtime Information: 
;
; Pixel Shader
; DepthOutput=0
; SampleFrequency=0
;
;
; Input signature:
;
; Name                 Index             InterpMode DynIdx
; -------------------- ----- ---------------------- ------
; SV_Position              0          noperspective       
;
; Output signature:
;
; Name                 Index             InterpMode DynIdx
; -------------------- ----- ---------------------- ------
; SV_Target                0                              
;
; Buffer Definitions:
;
; cbuffer input
; {
;
;   struct input
;   {
;
;       uint frameIndex;                              ; Offset:    0
;   
;   } input;                                          ; Offset:    0 Size:     4
;
; }
;
;
; Resource Bindings:
;
; Name                                 Type  Format         Dim      ID      HLSL Bind  Count
; ------------------------------ ---------- ------- ----------- ------- -------------- ------
; input                             cbuffer      NA          NA     CB0            cb0     1
;
;
; ViewId state:
;
; Number of inputs: 4, outputs: 4
; Outputs dependent on ViewId: {  }
; Inputs contributing to computation of Outputs:
;   output 0 depends on inputs: { 0 }
;   output 1 depends on inputs: { 0 }
;   output 2 depends on inputs: { 0 }
;   output 3 depends on inputs: { 0 }
;
target datalayout = "e-m:e-p:32:32-i1:32-i8:32-i16:32-i32:32-i64:64-f16:32-f32:32-f64:64-n8:16:32:64"
target triple = "dxil-ms-dx"

%dx.types.Handle = type { i8* }
%dx.types.CBufRet.i32 = type { i32, i32, i32, i32 }
%input = type { i32 }

define void @mainPS() {
  %1 = call %dx.types.Handle @dx.op.createHandle(i32 57, i8 2, i32 0, i32 0, i1 false)  ; CreateHandle(resourceClass,rangeId,index,nonUniformIndex)
  %2 = call float @dx.op.loadInput.f32(i32 4, i32 0, i32 0, i8 0, i32 undef)  ; LoadInput(inputSigId,rowIndex,colIndex,gsVertexAxis)
  %3 = call %dx.types.CBufRet.i32 @dx.op.cbufferLoadLegacy.i32(i32 59, %dx.types.Handle %1, i32 0)  ; CBufferLoadLegacy(handle,regIndex)
  %4 = extractvalue %dx.types.CBufRet.i32 %3, 0
  %5 = and i32 %4, 1
  %6 = uitofp i32 %5 to float
  %7 = xor i32 %5, 1
  %8 = uitofp i32 %7 to float
  %9 = fcmp fast olt float %2, 1.600000e+01
  br i1 %9, label %13, label %10

; <label>:10                                      ; preds = %0
  %11 = fcmp fast olt float %2, 3.200000e+01
  br i1 %11, label %12, label %13

; <label>:12                                      ; preds = %10
  br label %13

; <label>:13                                      ; preds = %12, %10, %0
  %14 = phi float [ %6, %12 ], [ 0.000000e+00, %10 ], [ %8, %0 ]
  %15 = phi float [ %6, %12 ], [ 0.000000e+00, %10 ], [ %6, %0 ]
  %16 = phi float [ 1.000000e+00, %12 ], [ 0.000000e+00, %10 ], [ 1.000000e+00, %0 ]
  call void @dx.op.storeOutput.f32(i32 5, i32 0, i32 0, i8 0, float %14)  ; StoreOutput(outputSigId,rowIndex,colIndex,value)
  call void @dx.op.storeOutput.f32(i32 5, i32 0, i32 0, i8 1, float %15)  ; StoreOutput(outputSigId,rowIndex,colIndex,value)
  call void @dx.op.storeOutput.f32(i32 5, i32 0, i32 0, i8 2, float %14)  ; StoreOutput(outputSigId,rowIndex,colIndex,value)
  call void @dx.op.storeOutput.f32(i32 5, i32 0, i32 0, i8 3, float %16)  ; StoreOutput(outputSigId,rowIndex,colIndex,value)
  ret void
}

; Function Attrs: nounwind readnone
declare float @dx.op.loadInput.f32(i32, i32, i32, i8, i32) #0

; Function Attrs: nounwind
declare void @dx.op.storeOutput.f32(i32, i32, i32, i8, float) #1

; Function Attrs: nounwind readonly
declare %dx.types.CBufRet.i32 @dx.op.cbufferLoadLegacy.i32(i32, %dx.types.Handle, i32) #2

; Function Attrs: nounwind readonly
declare %dx.types.Handle @dx.op.createHandle(i32, i8, i32, i32, i1) #2

attributes #0 = { nounwind readnone }
attributes #1 = { nounwind }
attributes #2 = { nounwind readonly }

!llvm.ident = !{!0}
!dx.version = !{!1}
!dx.valver = !{!2}
!dx.shaderModel = !{!3}
!dx.resources = !{!4}
!dx.viewIdState = !{!7}
!dx.entryPoints = !{!8}

!0 = !{!"dxcoob 1.8.2403.37 (11e1318c3)"}
!1 = !{i32 1, i32 0}
!2 = !{i32 1, i32 8}
!3 = !{!"ps", i32 6, i32 0}
!4 = !{null, null, !5, null}
!5 = !{!6}
!6 = !{i32 0, %input* undef, !"", i32 0, i32 0, i32 1, i32 4, null}
!7 = !{[6 x i32] [i32 4, i32 4, i32 15, i32 0, i32 0, i32 0]}
!8 = !{void ()* @mainPS, !"mainPS", !9, !4, null}
!9 = !{!10, !14, null}
!10 = !{!11}
!11 = !{i32 0, !"SV_Position", i8 9, i8 3, !12, i8 4, i32 1, i8 4, i32 0, i8 0, !13}
!12 = !{i32 0}
!13 = !{i32 3, i32 1}
!14 = !{!15}
!15 = !{i32 0, !"SV_Target", i8 9, i8 16, !12, i8 0, i32 1, i8 4, i32 0, i8 0, !16}
!16 = !{i32 3, i32 15}

#endif

const unsigned char g_mainPS[] = {
  0x44, 0x58, 0x42, 0x43, 0x10, 0x23, 0xe0, 0x08, 0x38, 0xca, 0xf2, 0xb2,
  0xda, 0xb6, 0xc5, 0xdb, 0x01, 0x58, 0x48, 0x43, 0x01, 0x00, 0x00, 0x00,
  0x6c, 0x0d, 0x00, 0x00, 0x07, 0x00, 0x00, 0x00, 0x3c, 0x00, 0x00, 0x00,
  0x4c, 0x00, 0x00, 0x00, 0x88, 0x00, 0x00, 0x00, 0xc4, 0x00, 0x00, 0x00,
  0x6c, 0x01, 0x00, 0x00, 0x4c, 0x07, 0x00, 0x00, 0x68, 0x07, 0x00, 0x00,
  0x53, 0x46, 0x49, 0x30, 0x08, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x49, 0x53, 0x47, 0x31, 0x34, 0x00, 0x00, 0x00,
  0x01, 0x00, 0x00, 0x00, 0x08, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x28, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00,
  0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0f, 0x01, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x53, 0x56, 0x5f, 0x50, 0x6f, 0x73, 0x69, 0x74,
  0x69, 0x6f, 0x6e, 0x00, 0x4f, 0x53, 0x47, 0x31, 0x34, 0x00, 0x00, 0x00,
  0x01, 0x00, 0x00, 0x00, 0x08, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x28, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x40, 0x00, 0x00, 0x00,
  0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0f, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x53, 0x56, 0x5f, 0x54, 0x61, 0x72, 0x67, 0x65,
  0x74, 0x00, 0x00, 0x00, 0x50, 0x53, 0x56, 0x30, 0xa0, 0x00, 0x00, 0x00,
  0x34, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0xff, 0xff, 0xff, 0xff, 0x00, 0x00, 0x00, 0x00, 0x01, 0x01, 0x00, 0x01,
  0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00,
  0x18, 0x00, 0x00, 0x00, 0x02, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0d, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x08, 0x00, 0x00, 0x00, 0x00, 0x6d, 0x61, 0x69,
  0x6e, 0x50, 0x53, 0x00, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x10, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x01, 0x00, 0x44, 0x03, 0x03, 0x04, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x44, 0x10, 0x03, 0x00, 0x00, 0x00,
  0x0f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x53, 0x54, 0x41, 0x54, 0xd8, 0x05, 0x00, 0x00,
  0x60, 0x00, 0x00, 0x00, 0x76, 0x01, 0x00, 0x00, 0x44, 0x58, 0x49, 0x4c,
  0x00, 0x01, 0x00, 0x00, 0x10, 0x00, 0x00, 0x00, 0xc0, 0x05, 0x00, 0x00,
  0x42, 0x43, 0xc0, 0xde, 0x21, 0x0c, 0x00, 0x00, 0x6d, 0x01, 0x00, 0x00,
  0x0b, 0x82, 0x20, 0x00, 0x02, 0x00, 0x00, 0x00, 0x13, 0x00, 0x00, 0x00,
  0x07, 0x81, 0x23, 0x91, 0x41, 0xc8, 0x04, 0x49, 0x06, 0x10, 0x32, 0x39,
  0x92, 0x01, 0x84, 0x0c, 0x25, 0x05, 0x08, 0x19, 0x1e, 0x04, 0x8b, 0x62,
  0x80, 0x14, 0x45, 0x02, 0x42, 0x92, 0x0b, 0x42, 0xa4, 0x10, 0x32, 0x14,
  0x38, 0x08, 0x18, 0x4b, 0x0a, 0x32, 0x52, 0x88, 0x48, 0x90, 0x14, 0x20,
  0x43, 0x46, 0x88, 0xa5, 0x00, 0x19, 0x32, 0x42, 0xe4, 0x48, 0x0e, 0x90,
  0x91, 0x22, 0xc4, 0x50, 0x41, 0x51, 0x81, 0x8c, 0xe1, 0x83, 0xe5, 0x8a,
  0x04, 0x29, 0x46, 0x06, 0x51, 0x18, 0x00, 0x00, 0x08, 0x00, 0x00, 0x00,
  0x1b, 0x8c, 0xe0, 0xff, 0xff, 0xff, 0xff, 0x07, 0x40, 0x02, 0xa8, 0x0d,
  0x84, 0xf0, 0xff, 0xff, 0xff, 0xff, 0x03, 0x20, 0x6d, 0x30, 0x86, 0xff,
  0xff, 0xff, 0xff, 0x1f, 0x00, 0x09, 0xa8, 0x00, 0x49, 0x18, 0x00, 0x00,
  0x03, 0x00, 0x00, 0x00, 0x13, 0x82, 0x60, 0x42, 0x20, 0x4c, 0x08, 0x06,
  0x00, 0x00, 0x00, 0x00, 0x89, 0x20, 0x00, 0x00, 0x1e, 0x00, 0x00, 0x00,
  0x32, 0x22, 0x48, 0x09, 0x20, 0x64, 0x85, 0x04, 0x93, 0x22, 0xa4, 0x84,
  0x04, 0x93, 0x22, 0xe3, 0x84, 0xa1, 0x90, 0x14, 0x12, 0x4c, 0x8a, 0x8c,
  0x0b, 0x84, 0xa4, 0x4c, 0x10, 0x58, 0x23, 0x00, 0x25, 0x00, 0x14, 0x66,
  0x00, 0xe6, 0x08, 0xc0, 0x60, 0x8e, 0x00, 0x29, 0xc6, 0x20, 0x84, 0x14,
  0x42, 0xa6, 0x18, 0x80, 0x10, 0x52, 0x06, 0xa1, 0xa3, 0x86, 0xcb, 0x9f,
  0xb0, 0x87, 0x90, 0x7c, 0x6e, 0xa3, 0x8a, 0x95, 0x98, 0x7c, 0xe4, 0xb6,
  0x11, 0x41, 0x08, 0x21, 0x54, 0xee, 0x19, 0x2e, 0x7f, 0xc2, 0x1e, 0x42,
  0xf2, 0x43, 0xa0, 0x19, 0x16, 0x02, 0x05, 0xab, 0x10, 0x8a, 0x30, 0x42,
  0x6d, 0x8e, 0x20, 0x28, 0x06, 0x23, 0x85, 0x90, 0x47, 0x70, 0x20, 0xe0,
  0x0a, 0xa4, 0x79, 0xa8, 0x09, 0x05, 0x84, 0x66, 0x1a, 0x10, 0x00, 0x00,
  0x13, 0x14, 0x72, 0xc0, 0x87, 0x74, 0x60, 0x87, 0x36, 0x68, 0x87, 0x79,
  0x68, 0x03, 0x72, 0xc0, 0x87, 0x0d, 0xaf, 0x50, 0x0e, 0x6d, 0xd0, 0x0e,
  0x7a, 0x50, 0x0e, 0x6d, 0x00, 0x0f, 0x7a, 0x30, 0x07, 0x72, 0xa0, 0x07,
  0x73, 0x20, 0x07, 0x6d, 0x90, 0x0e, 0x71, 0xa0, 0x07, 0x73, 0x20, 0x07,
  0x6d, 0x90, 0x0e, 0x78, 0xa0, 0x07, 0x73, 0x20, 0x07, 0x6d, 0x90, 0x0e,
  0x71, 0x60, 0x07, 0x7a, 0x30, 0x07, 0x72, 0xd0, 0x06, 0xe9, 0x30, 0x07,
  0x72, 0xa0, 0x07, 0x73, 0x20, 0x07, 0x6d, 0x90, 0x0e, 0x76, 0x40, 0x07,
  0x7a, 0x60, 0x07, 0x74, 0xd0, 0x06, 0xe6, 0x10, 0x07, 0x76, 0xa0, 0x07,
  0x73, 0x20, 0x07, 0x6d, 0x60, 0x0e, 0x73, 0x20, 0x07, 0x7a, 0x30, 0x07,
  0x72, 0xd0, 0x06, 0xe6, 0x60, 0x07, 0x74, 0xa0, 0x07, 0x76, 0x40, 0x07,
  0x6d, 0xe0, 0x0e, 0x78, 0xa0, 0x07, 0x71, 0x60, 0x07, 0x7a, 0x30, 0x07,
  0x72, 0xa0, 0x07, 0x76, 0x40, 0x07, 0x43, 0x9e, 0x00, 0x08, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x86, 0x3c, 0x06, 0x10, 0x00,
  0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0c, 0x79, 0x10, 0x20,
  0x00, 0x04, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x18, 0xf2, 0x34,
  0x40, 0x00, 0x0c, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x30, 0xe4,
  0x81, 0x80, 0x00, 0x18, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x20,
  0x0b, 0x04, 0x00, 0x00, 0x0e, 0x00, 0x00, 0x00, 0x32, 0x1e, 0x98, 0x14,
  0x19, 0x11, 0x4c, 0x90, 0x8c, 0x09, 0x26, 0x47, 0xc6, 0x04, 0x43, 0x22,
  0x25, 0x30, 0x02, 0x50, 0x0c, 0x85, 0x50, 0x06, 0xe5, 0x50, 0x0a, 0xe5,
  0x51, 0x04, 0xa5, 0x42, 0xa5, 0x24, 0xca, 0xa0, 0x10, 0x46, 0x00, 0x0a,
  0x84, 0xe6, 0x0c, 0x00, 0xd1, 0x19, 0x00, 0xaa, 0x63, 0x19, 0x04, 0xf1,
  0x00, 0x00, 0x00, 0x00, 0x79, 0x18, 0x00, 0x00, 0x79, 0x00, 0x00, 0x00,
  0x1a, 0x03, 0x4c, 0x90, 0x46, 0x02, 0x13, 0x44, 0x8f, 0x0c, 0x6f, 0xec,
  0xed, 0x4d, 0x0c, 0x24, 0xc6, 0x05, 0xc7, 0x45, 0x86, 0x06, 0x66, 0xc6,
  0x65, 0xe6, 0x06, 0x04, 0x25, 0x26, 0xa6, 0x2c, 0x66, 0x26, 0x06, 0x67,
  0x6c, 0x26, 0x65, 0x43, 0x10, 0x4c, 0x10, 0x88, 0x62, 0x82, 0x40, 0x18,
  0x1b, 0x84, 0x81, 0xd8, 0x20, 0x10, 0x04, 0x05, 0xb8, 0xb9, 0x09, 0x02,
  0x71, 0x6c, 0x18, 0x0e, 0x84, 0x98, 0x20, 0x50, 0x15, 0x8b, 0x34, 0x37,
  0xb8, 0x3a, 0xba, 0x09, 0x02, 0x81, 0x6c, 0x40, 0x08, 0x65, 0x21, 0x88,
  0x81, 0x01, 0x36, 0x04, 0xcd, 0x06, 0x02, 0x00, 0x1c, 0x60, 0x82, 0x30,
  0x51, 0x54, 0xcc, 0xe4, 0xc2, 0xda, 0xca, 0x92, 0xdc, 0xc8, 0xca, 0xf0,
  0x26, 0x08, 0x44, 0x32, 0x41, 0x20, 0x94, 0x09, 0x02, 0xb1, 0x6c, 0x30,
  0x90, 0x48, 0x22, 0x26, 0x6a, 0x83, 0xc0, 0x54, 0x1b, 0x06, 0x02, 0xb2,
  0x26, 0x08, 0x02, 0xb0, 0x01, 0xd8, 0x30, 0x10, 0x59, 0xb6, 0x21, 0xd0,
  0x36, 0x0c, 0x03, 0xb6, 0x4d, 0x10, 0x2a, 0x6b, 0x43, 0xd0, 0xd1, 0x68,
  0x0b, 0x4b, 0x73, 0x83, 0x9a, 0xe2, 0x32, 0x65, 0xf5, 0x05, 0xf5, 0x36,
  0x97, 0x46, 0x97, 0xf6, 0xe6, 0x36, 0x41, 0x28, 0x9e, 0x09, 0x42, 0x01,
  0x6d, 0x08, 0x88, 0x09, 0x42, 0x11, 0x4d, 0x10, 0x0a, 0x69, 0x83, 0x20,
  0x0d, 0x1b, 0x16, 0x02, 0x0c, 0xc2, 0x40, 0x0c, 0xc6, 0x80, 0x0c, 0x06,
  0x32, 0x20, 0xca, 0xc0, 0x0c, 0x36, 0x04, 0x67, 0xc0, 0x64, 0xca, 0xea,
  0x8b, 0x2a, 0x4c, 0xee, 0xac, 0x8c, 0x6e, 0x82, 0x50, 0x4c, 0x13, 0x04,
  0x82, 0xd9, 0x20, 0x48, 0x6b, 0xb0, 0x61, 0x21, 0xd2, 0x20, 0x0c, 0xd4,
  0x60, 0x0c, 0xca, 0x60, 0x20, 0x03, 0xa2, 0x0c, 0xd8, 0x60, 0x43, 0xd0,
  0x06, 0x1b, 0x06, 0x34, 0x70, 0x03, 0x60, 0x43, 0x81, 0x7d, 0x6f, 0xf0,
  0x00, 0x44, 0xc4, 0xe4, 0xc2, 0xdc, 0xc6, 0xd0, 0xca, 0xe6, 0x26, 0x08,
  0x44, 0x43, 0xc3, 0x8c, 0xed, 0x2d, 0x8c, 0x6e, 0x8e, 0x45, 0x9a, 0xdb,
  0x1c, 0xdd, 0xdc, 0x04, 0x81, 0x70, 0x68, 0xcc, 0xa5, 0x9d, 0x7d, 0xb1,
  0x91, 0xd1, 0x98, 0x4b, 0x3b, 0xfb, 0x9a, 0xa3, 0x63, 0x51, 0x97, 0xe6,
  0x46, 0x37, 0xb7, 0x81, 0x89, 0x03, 0x39, 0x98, 0x03, 0x86, 0x0e, 0xea,
  0xc0, 0x0e, 0x86, 0x3b, 0x60, 0xf0, 0x40, 0x0e, 0xaa, 0xb0, 0xb1, 0xd9,
  0xb5, 0xb9, 0xa4, 0x91, 0x95, 0xb9, 0xd1, 0x4d, 0x09, 0x82, 0x2a, 0x64,
  0x78, 0x2e, 0x76, 0x65, 0x72, 0x73, 0x69, 0x6f, 0x6e, 0x53, 0x02, 0xa2,
  0x09, 0x19, 0x9e, 0x8b, 0x5d, 0x18, 0x9b, 0x5d, 0x99, 0xdc, 0x94, 0xa0,
  0xa8, 0x43, 0x86, 0xe7, 0x32, 0x87, 0x16, 0x46, 0x56, 0x26, 0xd7, 0xf4,
  0x46, 0x56, 0xc6, 0x36, 0x25, 0x40, 0xca, 0x90, 0xe1, 0xb9, 0xc8, 0x95,
  0xcd, 0xbd, 0xd5, 0xc9, 0x8d, 0x95, 0xcd, 0x4d, 0x09, 0x9c, 0x4a, 0x64,
  0x78, 0x2e, 0x74, 0x79, 0x70, 0x65, 0x41, 0x6e, 0x6e, 0x6f, 0x74, 0x61,
  0x74, 0x69, 0x6f, 0x6e, 0x73, 0x53, 0x04, 0x6b, 0xab, 0x43, 0x86, 0xe7,
  0x62, 0x97, 0x56, 0x76, 0x97, 0x44, 0x36, 0x45, 0x17, 0x46, 0x57, 0x36,
  0x25, 0xe8, 0xea, 0x90, 0xe1, 0xb9, 0x94, 0xb9, 0xd1, 0xc9, 0xe5, 0x41,
  0xbd, 0xa5, 0xb9, 0xd1, 0xcd, 0x4d, 0x09, 0xde, 0xa0, 0x0b, 0x19, 0x9e,
  0xcb, 0xd8, 0x5b, 0x9d, 0x1b, 0x5d, 0x99, 0xdc, 0xdc, 0x94, 0x00, 0x0f,
  0x00, 0x00, 0x00, 0x00, 0x79, 0x18, 0x00, 0x00, 0x51, 0x00, 0x00, 0x00,
  0x33, 0x08, 0x80, 0x1c, 0xc4, 0xe1, 0x1c, 0x66, 0x14, 0x01, 0x3d, 0x88,
  0x43, 0x38, 0x84, 0xc3, 0x8c, 0x42, 0x80, 0x07, 0x79, 0x78, 0x07, 0x73,
  0x98, 0x71, 0x0c, 0xe6, 0x00, 0x0f, 0xed, 0x10, 0x0e, 0xf4, 0x80, 0x0e,
  0x33, 0x0c, 0x42, 0x1e, 0xc2, 0xc1, 0x1d, 0xce, 0xa1, 0x1c, 0x66, 0x30,
  0x05, 0x3d, 0x88, 0x43, 0x38, 0x84, 0x83, 0x1b, 0xcc, 0x03, 0x3d, 0xc8,
  0x43, 0x3d, 0x8c, 0x03, 0x3d, 0xcc, 0x78, 0x8c, 0x74, 0x70, 0x07, 0x7b,
  0x08, 0x07, 0x79, 0x48, 0x87, 0x70, 0x70, 0x07, 0x7a, 0x70, 0x03, 0x76,
  0x78, 0x87, 0x70, 0x20, 0x87, 0x19, 0xcc, 0x11, 0x0e, 0xec, 0x90, 0x0e,
  0xe1, 0x30, 0x0f, 0x6e, 0x30, 0x0f, 0xe3, 0xf0, 0x0e, 0xf0, 0x50, 0x0e,
  0x33, 0x10, 0xc4, 0x1d, 0xde, 0x21, 0x1c, 0xd8, 0x21, 0x1d, 0xc2, 0x61,
  0x1e, 0x66, 0x30, 0x89, 0x3b, 0xbc, 0x83, 0x3b, 0xd0, 0x43, 0x39, 0xb4,
  0x03, 0x3c, 0xbc, 0x83, 0x3c, 0x84, 0x03, 0x3b, 0xcc, 0xf0, 0x14, 0x76,
  0x60, 0x07, 0x7b, 0x68, 0x07, 0x37, 0x68, 0x87, 0x72, 0x68, 0x07, 0x37,
  0x80, 0x87, 0x70, 0x90, 0x87, 0x70, 0x60, 0x07, 0x76, 0x28, 0x07, 0x76,
  0xf8, 0x05, 0x76, 0x78, 0x87, 0x77, 0x80, 0x87, 0x5f, 0x08, 0x87, 0x71,
  0x18, 0x87, 0x72, 0x98, 0x87, 0x79, 0x98, 0x81, 0x2c, 0xee, 0xf0, 0x0e,
  0xee, 0xe0, 0x0e, 0xf5, 0xc0, 0x0e, 0xec, 0x30, 0x03, 0x62, 0xc8, 0xa1,
  0x1c, 0xe4, 0xa1, 0x1c, 0xcc, 0xa1, 0x1c, 0xe4, 0xa1, 0x1c, 0xdc, 0x61,
  0x1c, 0xca, 0x21, 0x1c, 0xc4, 0x81, 0x1d, 0xca, 0x61, 0x06, 0xd6, 0x90,
  0x43, 0x39, 0xc8, 0x43, 0x39, 0x98, 0x43, 0x39, 0xc8, 0x43, 0x39, 0xb8,
  0xc3, 0x38, 0x94, 0x43, 0x38, 0x88, 0x03, 0x3b, 0x94, 0xc3, 0x2f, 0xbc,
  0x83, 0x3c, 0xfc, 0x82, 0x3b, 0xd4, 0x03, 0x3b, 0xb0, 0xc3, 0x0c, 0xc4,
  0x21, 0x07, 0x7c, 0x70, 0x03, 0x7a, 0x28, 0x87, 0x76, 0x80, 0x87, 0x19,
  0xd1, 0x43, 0x0e, 0xf8, 0xe0, 0x06, 0xe4, 0x20, 0x0e, 0xe7, 0xe0, 0x06,
  0xf6, 0x10, 0x0e, 0xf2, 0xc0, 0x0e, 0xe1, 0x90, 0x0f, 0xef, 0x50, 0x0f,
  0xf4, 0x30, 0x83, 0x81, 0xc8, 0x01, 0x1f, 0xdc, 0x40, 0x1c, 0xe4, 0xa1,
  0x1c, 0xc2, 0x61, 0x1d, 0xdc, 0x40, 0x1c, 0xe4, 0x01, 0x00, 0x00, 0x00,
  0x71, 0x20, 0x00, 0x00, 0x14, 0x00, 0x00, 0x00, 0x36, 0xb0, 0x0d, 0x97,
  0xef, 0x3c, 0xbe, 0x10, 0x50, 0x45, 0x41, 0x44, 0xa5, 0x03, 0x0c, 0x25,
  0x61, 0x00, 0x02, 0xe6, 0x23, 0xb7, 0x6d, 0x04, 0xd2, 0x70, 0xf9, 0xce,
  0xe3, 0x0b, 0x11, 0x01, 0x4c, 0x44, 0x08, 0x34, 0xc3, 0x42, 0x58, 0xc0,
  0x34, 0x5c, 0xbe, 0xf3, 0xf8, 0x8b, 0x03, 0x0c, 0x62, 0xf3, 0x50, 0x93,
  0x5f, 0xdc, 0xb6, 0x09, 0x54, 0xc3, 0xe5, 0x3b, 0x8f, 0x2f, 0x4d, 0x4e,
  0x44, 0xa0, 0xd4, 0xf4, 0x50, 0x93, 0x5f, 0xdc, 0xb6, 0x01, 0x18, 0x0c,
  0x80, 0x34, 0x29, 0x0b, 0x00, 0x00, 0x00, 0x00, 0x48, 0x41, 0x53, 0x48,
  0x14, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x19, 0xde, 0xcc, 0x2f,
  0xf0, 0x8f, 0xd3, 0xcb, 0xd2, 0xed, 0xcf, 0x26, 0x53, 0x6e, 0x91, 0xdf,
  0x44, 0x58, 0x49, 0x4c, 0xfc, 0x05, 0x00, 0x00, 0x60, 0x00, 0x00, 0x00,
  0x7f, 0x01, 0x00, 0x00, 0x44, 0x58, 0x49, 0x4c, 0x00, 0x01, 0x00, 0x00,
  0x10, 0x00, 0x00, 0x00, 0xe4, 0x05, 0x00, 0x00, 0x42, 0x43, 0xc0, 0xde,
  0x21, 0x0c, 0x00, 0x00, 0x76, 0x01, 0x00, 0x00, 0x0b, 0x82, 0x20, 0x00,
  0x02, 0x00, 0x00, 0x00, 0x13, 0x00, 0x00, 0x00, 0x07, 0x81, 0x23, 0x91,
  0x41, 0xc8, 0x04, 0x49, 0x06, 0x10, 0x32, 0x39, 0x92, 0x01, 0x84, 0x0c,
  0x25, 0x05, 0x08, 0x19, 0x1e, 0x04, 0x8b, 0x62, 0x80, 0x14, 0x45, 0x02,
  0x42, 0x92, 0x0b, 0x42, 0xa4, 0x10, 0x32, 0x14, 0x38, 0x08, 0x18, 0x4b,
  0x0a, 0x32, 0x52, 0x88, 0x48, 0x90, 0x14, 0x20, 0x43, 0x46, 0x88, 0xa5,
  0x00, 0x19, 0x32, 0x42, 0xe4, 0x48, 0x0e, 0x90, 0x91, 0x22, 0xc4, 0x50,
  0x41, 0x51, 0x81, 0x8c, 0xe1, 0x83, 0xe5, 0x8a, 0x04, 0x29, 0x46, 0x06,
  0x51, 0x18, 0x00, 0x00, 0x08, 0x00, 0x00, 0x00, 0x1b, 0x8c, 0xe0, 0xff,
  0xff, 0xff, 0xff, 0x07, 0x40, 0x02, 0xa8, 0x0d, 0x84, 0xf0, 0xff, 0xff,
  0xff, 0xff, 0x03, 0x20, 0x6d, 0x30, 0x86, 0xff, 0xff, 0xff, 0xff, 0x1f,
  0x00, 0x09, 0xa8, 0x00, 0x49, 0x18, 0x00, 0x00, 0x03, 0x00, 0x00, 0x00,
  0x13, 0x82, 0x60, 0x42, 0x20, 0x4c, 0x08, 0x06, 0x00, 0x00, 0x00, 0x00,
  0x89, 0x20, 0x00, 0x00, 0x1f, 0x00, 0x00, 0x00, 0x32, 0x22, 0x48, 0x09,
  0x20, 0x64, 0x85, 0x04, 0x93, 0x22, 0xa4, 0x84, 0x04, 0x93, 0x22, 0xe3,
  0x84, 0xa1, 0x90, 0x14, 0x12, 0x4c, 0x8a, 0x8c, 0x0b, 0x84, 0xa4, 0x4c,
  0x10, 0x5c, 0x23, 0x00, 0x25, 0x00, 0x14, 0x66, 0x00, 0xe6, 0x08, 0xc0,
  0x60, 0x8e, 0x00, 0x29, 0xc6, 0x20, 0x84, 0x14, 0x42, 0xa6, 0x18, 0x80,
  0x10, 0x52, 0x06, 0xa1, 0xa3, 0x86, 0xcb, 0x9f, 0xb0, 0x87, 0x90, 0x7c,
  0x6e, 0xa3, 0x8a, 0x95, 0x98, 0x7c, 0xe4, 0xb6, 0x11, 0x41, 0x08, 0x21,
  0x54, 0xee, 0x19, 0x2e, 0x7f, 0xc2, 0x1e, 0x42, 0xf2, 0x43, 0xa0, 0x19,
  0x16, 0x02, 0x05, 0xab, 0x10, 0x8a, 0x30, 0x42, 0x6d, 0x8e, 0x20, 0x28,
  0x06, 0x23, 0x85, 0x90, 0x47, 0x70, 0x20, 0xe0, 0x0a, 0xa4, 0x79, 0xa8,
  0x09, 0x05, 0x84, 0x66, 0x1a, 0x90, 0x29, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x13, 0x14, 0x72, 0xc0, 0x87, 0x74, 0x60, 0x87, 0x36, 0x68, 0x87, 0x79,
  0x68, 0x03, 0x72, 0xc0, 0x87, 0x0d, 0xaf, 0x50, 0x0e, 0x6d, 0xd0, 0x0e,
  0x7a, 0x50, 0x0e, 0x6d, 0x00, 0x0f, 0x7a, 0x30, 0x07, 0x72, 0xa0, 0x07,
  0x73, 0x20, 0x07, 0x6d, 0x90, 0x0e, 0x71, 0xa0, 0x07, 0x73, 0x20, 0x07,
  0x6d, 0x90, 0x0e, 0x78, 0xa0, 0x07, 0x73, 0x20, 0x07, 0x6d, 0x90, 0x0e,
  0x71, 0x60, 0x07, 0x7a, 0x30, 0x07, 0x72, 0xd0, 0x06, 0xe9, 0x30, 0x07,
  0x72, 0xa0, 0x07, 0x73, 0x20, 0x07, 0x6d, 0x90, 0x0e, 0x76, 0x40, 0x07,
  0x7a, 0x60, 0x07, 0x74, 0xd0, 0x06, 0xe6, 0x10, 0x07, 0x76, 0xa0, 0x07,
  0x73, 0x20, 0x07, 0x6d, 0x60, 0x0e, 0x73, 0x20, 0x07, 0x7a, 0x30, 0x07,
  0x72, 0xd0, 0x06, 0xe6, 0x60, 0x07, 0x74, 0xa0, 0x07, 0x76, 0x40, 0x07,
  0x6d, 0xe0, 0x0e, 0x78, 0xa0, 0x07, 0x71, 0x60, 0x07, 0x7a, 0x30, 0x07,
  0x72, 0xa0, 0x07, 0x76, 0x40, 0x07, 0x43, 0x9e, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x86, 0x3c, 0x06, 0x10, 0x00,
  0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0c, 0x79, 0x10, 0x20,
  0x00, 0x04, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x18, 0xf2, 0x34,
  0x40, 0x00, 0x0c, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x30, 0xe4,
  0x81, 0x80, 0x00, 0x18, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x20,
  0x0b, 0x04, 0x00, 0x00, 0x0c, 0x00, 0x00, 0x00, 0x32, 0x1e, 0x98, 0x14,
  0x19, 0x11, 0x4c, 0x90, 0x8c, 0x09, 0x26, 0x47, 0xc6, 0x04, 0x43, 0x22,
  0x25, 0x30, 0x02, 0x50, 0x10, 0xc5, 0x50, 0x08, 0x65, 0x50, 0x1e, 0x54,
  0x4a, 0xa2, 0x0c, 0x0a, 0x61, 0x04, 0xa0, 0x40, 0x88, 0xce, 0x00, 0x50,
  0x1d, 0xcb, 0x20, 0x88, 0x07, 0x00, 0x00, 0x00, 0x79, 0x18, 0x00, 0x00,
  0x4f, 0x00, 0x00, 0x00, 0x1a, 0x03, 0x4c, 0x90, 0x46, 0x02, 0x13, 0x44,
  0x8f, 0x0c, 0x6f, 0xec, 0xed, 0x4d, 0x0c, 0x24, 0xc6, 0x05, 0xc7, 0x45,
  0x86, 0x06, 0x66, 0xc6, 0x65, 0xe6, 0x06, 0x04, 0x25, 0x26, 0xa6, 0x2c,
  0x66, 0x26, 0x06, 0x67, 0x6c, 0x26, 0x65, 0x43, 0x10, 0x4c, 0x10, 0x88,
  0x62, 0x82, 0x40, 0x18, 0x1b, 0x84, 0x81, 0x98, 0x20, 0x10, 0xc7, 0x06,
  0x61, 0x30, 0x28, 0xc0, 0xcd, 0x4d, 0x10, 0x08, 0x64, 0xc3, 0x80, 0x24,
  0xc4, 0x04, 0x81, 0x8a, 0x08, 0x4c, 0x10, 0x88, 0x64, 0x03, 0x42, 0x2c,
  0x0c, 0x41, 0x0c, 0x0d, 0xb0, 0x21, 0x70, 0x36, 0x10, 0x00, 0xf0, 0x00,
  0x13, 0x84, 0x4a, 0xda, 0x10, 0x44, 0x13, 0x04, 0x01, 0xa0, 0xd1, 0x16,
  0x96, 0xe6, 0x06, 0x35, 0xc5, 0x65, 0xca, 0xea, 0x0b, 0xea, 0x6d, 0x2e,
  0x8d, 0x2e, 0xed, 0xcd, 0x6d, 0x82, 0x50, 0x30, 0x13, 0x84, 0xa2, 0xd9,
  0x10, 0x10, 0x13, 0x84, 0xc2, 0x99, 0x20, 0x14, 0xcf, 0x04, 0x81, 0x50,
  0x36, 0x08, 0xdb, 0xb0, 0x61, 0x21, 0x2a, 0xeb, 0xc2, 0xb2, 0x21, 0x23,
  0x34, 0x6e, 0x43, 0xd0, 0x31, 0x99, 0xb2, 0xfa, 0xa2, 0x0a, 0x93, 0x3b,
  0x2b, 0xa3, 0x9b, 0x20, 0x14, 0xd0, 0x04, 0x81, 0x58, 0x36, 0x08, 0x5b,
  0x18, 0x6c, 0x58, 0x88, 0xcf, 0x02, 0x03, 0x4c, 0x1b, 0x32, 0x42, 0x13,
  0x83, 0x0d, 0xc1, 0x18, 0x6c, 0x18, 0x3c, 0x32, 0x00, 0x36, 0x14, 0x13,
  0x55, 0x06, 0x10, 0x50, 0x85, 0x8d, 0xcd, 0xae, 0xcd, 0x25, 0x8d, 0xac,
  0xcc, 0x8d, 0x6e, 0x4a, 0x10, 0x54, 0x21, 0xc3, 0x73, 0xb1, 0x2b, 0x93,
  0x9b, 0x4b, 0x7b, 0x73, 0x9b, 0x12, 0x10, 0x4d, 0xc8, 0xf0, 0x5c, 0xec,
  0xc2, 0xd8, 0xec, 0xca, 0xe4, 0xa6, 0x04, 0x46, 0x1d, 0x32, 0x3c, 0x97,
  0x39, 0xb4, 0x30, 0xb2, 0x32, 0xb9, 0xa6, 0x37, 0xb2, 0x32, 0xb6, 0x29,
  0x41, 0x52, 0x86, 0x0c, 0xcf, 0x45, 0xae, 0x6c, 0xee, 0xad, 0x4e, 0x6e,
  0xac, 0x6c, 0x6e, 0x4a, 0xf0, 0xd4, 0x21, 0xc3, 0x73, 0xb1, 0x4b, 0x2b,
  0xbb, 0x4b, 0x22, 0x9b, 0xa2, 0x0b, 0xa3, 0x2b, 0x9b, 0x12, 0x44, 0x75,
  0xc8, 0xf0, 0x5c, 0xca, 0xdc, 0xe8, 0xe4, 0xf2, 0xa0, 0xde, 0xd2, 0xdc,
  0xe8, 0xe6, 0xa6, 0x04, 0x65, 0x00, 0x00, 0x00, 0x79, 0x18, 0x00, 0x00,
  0x51, 0x00, 0x00, 0x00, 0x33, 0x08, 0x80, 0x1c, 0xc4, 0xe1, 0x1c, 0x66,
  0x14, 0x01, 0x3d, 0x88, 0x43, 0x38, 0x84, 0xc3, 0x8c, 0x42, 0x80, 0x07,
  0x79, 0x78, 0x07, 0x73, 0x98, 0x71, 0x0c, 0xe6, 0x00, 0x0f, 0xed, 0x10,
  0x0e, 0xf4, 0x80, 0x0e, 0x33, 0x0c, 0x42, 0x1e, 0xc2, 0xc1, 0x1d, 0xce,
  0xa1, 0x1c, 0x66, 0x30, 0x05, 0x3d, 0x88, 0x43, 0x38, 0x84, 0x83, 0x1b,
  0xcc, 0x03, 0x3d, 0xc8, 0x43, 0x3d, 0x8c, 0x03, 0x3d, 0xcc, 0x78, 0x8c,
  0x74, 0x70, 0x07, 0x7b, 0x08, 0x07, 0x79, 0x48, 0x87, 0x70, 0x70, 0x07,
  0x7a, 0x70, 0x03, 0x76, 0x78, 0x87, 0x70, 0x20, 0x87, 0x19, 0xcc, 0x11,
  0x0e, 0xec, 0x90, 0x0e, 0xe1, 0x30, 0x0f, 0x6e, 0x30, 0x0f, 0xe3, 0xf0,
  0x0e, 0xf0, 0x50, 0x0e, 0x33, 0x10, 0xc4, 0x1d, 0xde, 0x21, 0x1c, 0xd8,
  0x21, 0x1d, 0xc2, 0x61, 0x1e, 0x66, 0x30, 0x89, 0x3b, 0xbc, 0x83, 0x3b,
  0xd0, 0x43, 0x39, 0xb4, 0x03, 0x3c, 0xbc, 0x83, 0x3c, 0x84, 0x03, 0x3b,
  0xcc, 0xf0, 0x14, 0x76, 0x60, 0x07, 0x7b, 0x68, 0x07, 0x37, 0x68, 0x87,
  0x72, 0x68, 0x07, 0x37, 0x80, 0x87, 0x70, 0x90, 0x87, 0x70, 0x60, 0x07,
  0x76, 0x28, 0x07, 0x76, 0xf8, 0x05, 0x76, 0x78, 0x87, 0x77, 0x80, 0x87,
  0x5f, 0x08, 0x87, 0x71, 0x18, 0x87, 0x72, 0x98, 0x87, 0x79, 0x98, 0x81,
  0x2c, 0xee, 0xf0, 0x0e, 0xee, 0xe0, 0x0e, 0xf5, 0xc0, 0x0e, 0xec, 0x30,
  0x03, 0x62, 0xc8, 0xa1, 0x1c, 0xe4, 0xa1, 0x1c, 0xcc, 0xa1, 0x1c, 0xe4,
  0xa1, 0x1c, 0xdc, 0x61, 0x1c, 0xca, 0x21, 0x1c, 0xc4, 0x81, 0x1d, 0xca,
  0x61, 0x06, 0xd6, 0x90, 0x43, 0x39, 0xc8, 0x43, 0x39, 0x98, 0x43, 0x39,
  0xc8, 0x43, 0x39, 0xb8, 0xc3, 0x38, 0x94, 0x43, 0x38, 0x88, 0x03, 0x3b,
  0x94, 0xc3, 0x2f, 0xbc, 0x83, 0x3c, 0xfc, 0x82, 0x3b, 0xd4, 0x03, 0x3b,
  0xb0, 0xc3, 0x0c, 0xc4, 0x21, 0x07, 0x7c, 0x70, 0x03, 0x7a, 0x28, 0x87,
  0x76, 0x80, 0x87, 0x19, 0xd1, 0x43, 0x0e, 0xf8, 0xe0, 0x06, 0xe4, 0x20,
  0x0e, 0xe7, 0xe0, 0x06, 0xf6, 0x10, 0x0e, 0xf2, 0xc0, 0x0e, 0xe1, 0x90,
  0x0f, 0xef, 0x50, 0x0f, 0xf4, 0x30, 0x83, 0x81, 0xc8, 0x01, 0x1f, 0xdc,
  0x40, 0x1c, 0xe4, 0xa1, 0x1c, 0xc2, 0x61, 0x1d, 0xdc, 0x40, 0x1c, 0xe4,
  0x01, 0x00, 0x00, 0x00, 0x71, 0x20, 0x00, 0x00, 0x14, 0x00, 0x00, 0x00,
  0x36, 0xb0, 0x0d, 0x97, 0xef, 0x3c, 0xbe, 0x10, 0x50, 0x45, 0x41, 0x44,
  0xa5, 0x03, 0x0c, 0x25, 0x61, 0x00, 0x02, 0xe6, 0x23, 0xb7, 0x6d, 0x04,
  0xd2, 0x70, 0xf9, 0xce, 0xe3, 0x0b, 0x11, 0x01, 0x4c, 0x44, 0x08, 0x34,
  0xc3, 0x42, 0x58, 0xc0, 0x34, 0x5c, 0xbe, 0xf3, 0xf8, 0x8b, 0x03, 0x0c,
  0x62, 0xf3, 0x50, 0x93, 0x5f, 0xdc, 0xb6, 0x09, 0x54, 0xc3, 0xe5, 0x3b,
  0x8f, 0x2f, 0x4d, 0x4e, 0x44, 0xa0, 0xd4, 0xf4, 0x50, 0x93, 0x5f, 0xdc,
  0xb6, 0x01, 0x18, 0x0c, 0x80, 0x34, 0x29, 0x0b, 0x61, 0x20, 0x00, 0x00,
  0x32, 0x00, 0x00, 0x00, 0x13, 0x04, 0x44, 0x2c, 0x10, 0x00, 0x00, 0x00,
  0x0a, 0x00, 0x00, 0x00, 0xf4, 0x46, 0x00, 0xa8, 0x94, 0x40, 0x11, 0x10,
  0x29, 0xbb, 0x52, 0x28, 0xb9, 0x19, 0x00, 0x1a, 0x63, 0x04, 0x20, 0x08,
  0x82, 0x60, 0x18, 0x8c, 0x11, 0x80, 0x20, 0x08, 0xe2, 0x60, 0x30, 0x46,
  0x00, 0x82, 0x20, 0x88, 0x7f, 0x23, 0x00, 0x00, 0x23, 0x06, 0x09, 0x00,
  0x82, 0x60, 0x00, 0x69, 0x46, 0x82, 0x61, 0xcb, 0x88, 0x41, 0x02, 0x80,
  0x20, 0x18, 0x18, 0x9e, 0x95, 0x65, 0x90, 0x31, 0x62, 0x70, 0x00, 0x20,
  0x08, 0x06, 0x4d, 0xa7, 0x08, 0xda, 0x68, 0x42, 0x00, 0x54, 0xd0, 0xe9,
  0x05, 0xa3, 0x4a, 0xf8, 0xf8, 0x82, 0x51, 0xc3, 0x11, 0xc7, 0x42, 0x7c,
  0xb3, 0x0c, 0x43, 0x10, 0x0c, 0x47, 0x20, 0x0d, 0xf1, 0xcd, 0x32, 0x08,
  0x43, 0x30, 0x4b, 0x30, 0x0c, 0x74, 0x0c, 0x8a, 0x60, 0x05, 0x06, 0x30,
  0xd0, 0x31, 0x30, 0x02, 0x16, 0x30, 0xc0, 0x40, 0xc7, 0xc0, 0x09, 0x5a,
  0xc0, 0x01, 0x23, 0x06, 0x09, 0x00, 0x82, 0x60, 0x80, 0xa4, 0x01, 0x55,
  0x06, 0x65, 0xc0, 0x0d, 0x23, 0x06, 0x09, 0x00, 0x82, 0x60, 0x80, 0xa4,
  0x01, 0x55, 0x06, 0x65, 0x70, 0x09, 0x23, 0x06, 0x09, 0x00, 0x82, 0x60,
  0x80, 0xa4, 0x01, 0x55, 0x06, 0x65, 0x60, 0x0d, 0x23, 0x06, 0x09, 0x00,
  0x82, 0x60, 0x80, 0xa4, 0x01, 0x55, 0x06, 0x65, 0xe0, 0x05, 0x08, 0x00,
  0x00, 0x00, 0x00, 0x00
};
