global calculateCircleArea
calculateCircleArea:
section .data
    .pi            dq  3.14
section .text

push    rbp
mov     rbp, rsp
mov     [rbp-8], rdi
mov     rax, [rbp-8]
mov     edx, [rax+8]
mov     rax, [rbp-8]
mov     eax, [rax+8]
imul    eax, edx
cvtsi2sd xmm1, eax
movsd   xmm0, [.pi]
mulsd   xmm0, xmm1
pop     rbp
retn

global calculateLength
calculateLength:
endbr64
push    rbp
mov     rbp, rsp
sub     rsp, 10h
mov     [rbp-4], edi
mov     [rbp-8], esi
mov     [rbp-0Ch], edx
mov     [rbp-10h], ecx
mov     eax, [rbp-4]
sub     eax, [rbp-0Ch]
mov     edx, eax
mov     eax, [rbp-4]
sub     eax, [rbp-0Ch]
imul    edx, eax
mov     eax, [rbp-8]
sub     eax, [rbp-10h]
mov     ecx, eax
mov     eax, [rbp-8]
sub     eax, [rbp-10h]
imul    eax, ecx
add     eax, edx
mov     edi, eax      
cvtsi2sd xmm1, edi  
sqrtsd  xmm0, xmm1
leave
retn

global calculateRectangleArea
calculateRectangleArea:
push    rbp
mov     rbp, rsp
movsd   [rbp-8], xmm0
movsd   [rbp-10h], xmm1
movsd   xmm0, [rbp-8]
mulsd   xmm0, [rbp-10h]
pop     rbp
retn

global calculateTriangleArea
calculateTriangleArea:
section .data
    .two            dq  2.0
section .text
push    rbp
mov     rbp, rsp
sub     rsp, 30h
movsd   [rbp-18h], xmm0
movsd   [rbp-20h], xmm1
movsd   [rbp-28h], xmm2
movsd   xmm0, [rbp-18h]
addsd   xmm0, [rbp-20h]
addsd   xmm0, [rbp-28h]
movsd   xmm1, [.two]
divsd   xmm0, xmm1
movsd   [rbp-8], xmm0
movsd   xmm0, [rbp-8]
subsd   xmm0, [rbp-18h]
movapd  xmm1, xmm0
mulsd   xmm1, [rbp-8]
movsd   xmm0, [rbp-8]
subsd   xmm0, [rbp-20h]
mulsd   xmm1, xmm0
movsd   xmm0, [rbp-8]
subsd   xmm0, [rbp-28h]
mulsd   xmm0, xmm1      ; x
sqrtsd  xmm0, xmm0
leave
retn

global SortInner
SortInner:
push    rbp
mov     rbp, rsp
mov     [rbp-8], rdi
mov     [rbp-0Ch], esi
mov     [rbp-10h], edx
mov     rcx, [rbp-8]
mov     eax, [rbp-0Ch]
movsxd  rdx, eax
mov     rax, rdx
add     rax, rax
add     rax, rdx
shl     rax, 4
add     rax, rcx
add     rax, 10h
movsd   xmm0, [rax]
mov     rcx, [rbp-8]
mov     eax, [rbp-10h]
movsxd  rdx, eax
mov     rax, rdx
add     rax, rax
add     rax, rdx
shl     rax, 4
add     rax, rcx
add     rax, 10h
movsd   xmm1, [rax]
comisd  xmm0, xmm1
setnbe  al
pop     rbp
retn