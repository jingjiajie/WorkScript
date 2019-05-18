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
  %2 = alloca i32
  store i32 0, i32* %2
  %3 = call i32 @_Z1fi(i32* %2)
  ret i32 %3
}

define i32 @_Z1fi(i32* %"@0") {
entry:
  br label %branch

not_matched:                                      ; No predecessors!
  ret i32 undef

branch:                                           ; preds = %entry
  %0 = alloca %"@ref"
  %target = getelementptr inbounds %"@ref", %"@ref"* %0, i32 0, i32 0
  %1 = bitcast i32* %"@0" to i8*
  store i8* %1, i8** %target
  %2 = call i32 @"_Z2f1i4@ref"(%"@ref"* %0)
  %3 = call i32 @"_Z2f1i4@ref"(%"@ref"* %0)
  ret i32 %3
}

define i32 @"_Z2f1i4@ref"(%"@ref"* %"@0") {
entry:
  br label %branch

not_matched:                                      ; No predecessors!
  ret i32 undef

branch:                                           ; preds = %entry
  %target = getelementptr inbounds %"@ref", %"@ref"* %"@0", i32 0, i32 0
  %0 = load i8*, i8** %target
  %1 = bitcast i8* %0 to i32*
  %2 = load i32, i32* %1
  ret i32 %2
}
