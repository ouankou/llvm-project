// RUN: %clang_cc1 -triple x86_64-unknown-linux-gnu -fopenmp \
// RUN:   -debug-info-kind=limited -disable-llvm-passes -emit-llvm -o - %s \
// RUN:   | FileCheck %s

// CHECK: !llvm.loop ![[LOOP:[0-9]+]]
// CHECK-DAG: ![[LOOP]] = distinct !{![[LOOP]], ![[BEGIN:[0-9]+]], ![[END:[0-9]+]]
// CHECK-DAG: ![[BEGIN]] = !DILocation(line: 101, column: 3,
// CHECK-DAG: ![[END]] = !DILocation(line: 103, column: 3,

void foo(int *a, int n) {
#line 100
#pragma omp parallel for
  for (int i = 0; i < n; ++i) {
    a[i]++;
  }
}
