; ModuleID = 'main'
source_filename = "main"

define i1 @main() {
entry:
  br label %branch

not_matched:                                      ; No predecessors!
  ret i1 undef

branch:                                           ; preds = %entry
  %0 = alloca i64
  store i64 100, i64* %0
  %1 = alloca i64
  store i64 200, i64* %1
  %2 = load i64, i64* %0
  %3 = icmp eq i64 %2, 100
  %4 = sext i1 %3 to i64
  store i64 %4, i64* %1
  ret i1 %3
}
