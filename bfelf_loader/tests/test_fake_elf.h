//
// Bareflank Hypervisor
// Copyright (C) 2015 Assured Information Security, Inc.
//
// This library is free software; you can redistribute it and/or
// modify it under the terms of the GNU Lesser General Public
// License as published by the Free Software Foundation; either
// version 2.1 of the License, or (at your option) any later version.
//
// This library is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
// Lesser General Public License for more details.
//
// You should have received a copy of the GNU Lesser General Public
// License along with this library; if not, write to the Free Software
// Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA

#ifndef TEST_FAKE_ELF_H
#define TEST_FAKE_ELF_H

#include <memory>
#include <bfelf_loader.h>

std::pair<std::unique_ptr<char[]>, uint64_t>
get_fake_elf();

#pragma pack(push, 1)

#ifdef __cplusplus
extern "C" {
#endif

struct test_phdrtab {
    bfelf_phdr re_segment;
    bfelf_phdr rw_segment;
    bfelf_phdr dyn_segment;
    bfelf_phdr stack_segment;
    bfelf_phdr relro_segment;
};

struct test_hash {
    bfelf64_word nbucket;
    bfelf64_word nchain;
    bfelf64_word index1;
    bfelf64_word index2;
    bfelf64_word hash1;
    bfelf64_word hash2;
};

struct test_dynsym {
    bfelf_sym syms[2];
};

struct test_dynstr {
    char str1[10];
    char str2[10];
    char str3[10];
    char str4[10];
};

struct test_relatab {
    struct bfelf_rela relas[2];
};

struct test_eh_frame {
    const char *reserved[10];
};

struct test_init_array {
    const char *reserved[10];
};

struct test_fini_array {
    const char *reserved[10];
};

struct test_dynamic {
    struct bfelf_dyn needed1;
    struct bfelf_dyn needed2;
    struct bfelf_dyn pltgot;
    struct bfelf_dyn strtab;
    struct bfelf_dyn symtab;
    struct bfelf_dyn rela;
    struct bfelf_dyn relasz;
    struct bfelf_dyn relaent;
    struct bfelf_dyn strsz;
    struct bfelf_dyn init;
    struct bfelf_dyn fini;
    struct bfelf_dyn init_array;
    struct bfelf_dyn fini_array;
    struct bfelf_dyn init_arraysz;
    struct bfelf_dyn fini_arraysz;
    struct bfelf_dyn flags_1;
    struct bfelf_dyn last;
};

struct test_shdrtab {
    bfelf_shdr hash;
    bfelf_shdr dynsym;
    bfelf_shdr dynstr;
    bfelf_shdr relatab;
    bfelf_shdr eh_frame;
    bfelf_shdr init_array;
    bfelf_shdr fini_array;
    bfelf_shdr dynamic;
    bfelf_shdr ctors;
    bfelf_shdr dtors;
};

struct bfelf_test {
    bfelf_ehdr header;
    test_phdrtab phdrtab;

    test_dynsym dynsym;
    test_dynstr dynstr;
    test_hash hash;
    test_relatab relatab;
    test_eh_frame eh_frame;
    test_init_array init_array;
    test_fini_array fini_array;
    test_dynamic dynamic;

    test_shdrtab shdrtab;
};

#ifdef __cplusplus
}
#endif

#pragma pack(pop)

#endif
