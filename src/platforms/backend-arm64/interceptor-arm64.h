/**
 *    Copyright 2017 jmpews
 *
 *    Licensed under the Apache License, Version 2.0 (the "License");
 *    you may not use this file except in compliance with the License.
 *    You may obtain a copy of the License at
 *
 *        http://www.apache.org/licenses/LICENSE-2.0
 *
 *    Unless required by applicable law or agreed to in writing, software
 *    distributed under the License is distributed on an "AS IS" BASIS,
 *    WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *    See the License for the specific language governing permissions and
 *    limitations under the License.
 */

#ifndef platforms_backend_arm64_intercetor_arm64
#define platforms_backend_arm64_intercetor_arm64

#include "hookzz.h"
#include "zkit.h"

#include "platforms/arch-arm64/reader-arm64.h"
#include "platforms/arch-arm64/relocator-arm64.h"
#include "platforms/arch-arm64/writer-arm64.h"

#include "memory.h"
#include "interceptor.h"

#define CTX_SAVE_STACK_OFFSET (8 + 30 * 8 + 8 * 16)

typedef struct _InterceptorBackend {
    ExecuteMemoryManager *emm;
    ARM64Relocator arm64_relocator;
    ARM64AssemblyrWriter arm64_writer;
    ARM64AssemblyReader arm64_reader;

    zz_ptr_t enter_bridge;
    zz_ptr_t insn_leave_bridge;
    zz_ptr_t leave_bridge;
    zz_ptr_t dynamic_binary_instrumentation_bridge;
} InterceptorBackend;

typedef struct _ARM64HookFuntionEntryBackend {
    bool is_thumb;
    zz_size_t redirect_code_size;
} ARM64HookEntryBackend;

#endif