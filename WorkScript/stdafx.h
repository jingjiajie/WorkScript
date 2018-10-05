#pragma once
#include <iostream>
#include <sstream>
#include <string>
#include <type_traits>
#include <sstream>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>
#include <vector>

#include <stdio.h>
#include <wchar.h>
#include <string.h>
#include <locale.h>
#include <time.h>
#include <math.h>
#include <limits.h>

#include <boost/locale.hpp>

#include <llvm/IR/LLVMContext.h>
#include <llvm/IR/IRBuilder.h>
#include <llvm/IR/Verifier.h>
#include <llvm/IR/Module.h>
#include <llvm/IR/Function.h>
#include <llvm/ExecutionEngine/ExecutionEngine.h>
#include <llvm/ExecutionEngine/MCJIT.h>
#include <llvm/ExecutionEngine/Interpreter.h>
#include <llvm/Object/ObjectFile.h>
#include <llvm/Support/TargetSelect.h>