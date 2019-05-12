; ModuleID = 'main'
source_filename = "main"

%"@ref" = type { i8*, i8* }

define i32 @main() {
entry:
  br label %branch

not_matched:                                      ; No predecessors!
  ret i32 undef

branch:                                           ; preds = %entry
  %0 = alloca i32
  store i32 0, i32* %0
  %1 = call i32 @_Z1fi(i32* %0)
  ret i32 %1
}

define i32 @_Z1fi(i32* %"@0") {
entry:
  br label %branch

not_matched:                                      ; No predecessors!
  ret i32 undef

branch:                                           ; preds = %entry
  %0 = load i32, i32* %"@0"
  %1 = alloca i32
  store i32 %0, i32* %1
  %2 = alloca %"@ref"
  %target = insertvalue %"@ref"* %2, i32* %1, 0
  %3 = alloca %"@ref"
  store %"@ref"* %2, %"@ref"* %3
  %4 = call i32 @"_Z2f1i4@ref"(%"@ref"* %3)
  ret i32 %4
}

define i32 @"_Z2f1i4@ref"(%"@ref"* %"@0") {
entry:
  br label %branch

not_matched:                                      ; No predecessors!
  ret i32 undef

branch:                                           ; preds = %entry
  %0 = load %"@ref", %"@ref"* %"@0"
  %target = extractvalue %"@ref" %0, 0
  %1 = bitcast i8* %target to i32*
  %2 = load i32, i32* %1
  %3 = alloca i32
  store i32 %2, i32* %3
  %4 = load i32, i32* %3
  ret i32 %4
}
